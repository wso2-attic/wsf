<?php
/*
 * Copyright (c) 2005-2008 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Finds the operation DomNode.
 * @param DomDocument $sig_model_dom 
 * @param string $operation_name name of the param to be invoked
 * @param string $endpoint_address service endpoint address
 * @return DomNode operation DomNode of the Sig model
 */
function wsf_find_operation(DomDocument $sig_model_dom, $operation_name, $service_name, $port_name, $is_multiple)
{
    require_once('wsf_wsdl_consts.php');
    require_once('wsf_wsdl_util.php');

    if ($is_multiple == FALSE){
        $operation = NULL;
        $services_node = $sig_model_dom->firstChild;
        $services_childs_list = $services_node->childNodes;

        foreach($services_childs_list as $child){
            if($child->tagName == WSF_SERVICE) {
                if($service_name == NULL){
                    /* pick by port if the service name is not given*/
                    if($port_name == NULL){
                        /* now just get the first service and port*/
                        $service_node = $child;
                        break;
                    }
                    /* now pick by the port name */
                    if($child->attributes->getNamedItem("endpoint")){
                        $derived_port_name = $child->attributes->getNamedItem("endpoint")->value;
                    }
                    if($derived_port_name == $port_name){
                        $service_node = $child;
                        break;
                    }
                }
                $child_service_name = NULL;
                if($child->attributes->getNamedItem(WSF_NAME))
                {
                    $child_service_name = $child->attributes->getNamedItem(WSF_NAME)->value;
                }
                if($service_name == $child_service_name)
                {
                    /* pick by port if the service name is found*/
                    if($port_name == NULL){
                        /* now just get the first service and port*/
                        $service_node = $child;
                        break;
                    }
                    /* now pick by the port name */
                    if($child->attributes->getNamedItem("endpoint")){
                        $derived_port_name = $child->attributes->getNamedItem("endpoint")->value;
                    }
                    if($derived_port_name == $port_name){
                        $service_node = $child;
                        break;
                    }
                }
            }
        }
        if(!$service_node){
            error_log("service node not found");
            return NULL;
        }

        
        $service_child_list = $service_node->childNodes;
        /* search the operations element of the sig */
        foreach($service_child_list as $service_child){
            if($service_child->tagName == WSF_OPERATIONS){
                $operations_node = $service_child;
                break;
            }
        }
        
        /* search the operation element of sig */
        if($operations_node){
            foreach($operations_node->childNodes as $operations_child){
                if($operations_child->nodeType == XML_ELEMENT_NODE && $operations_child->tagName == WSF_OPERATION){
                    $operation_node = $operations_child->attributes;
                    if($operation_node->getNamedItem(WSF_NAME) && $operation_node->getNamedItem(WSF_NAME)->value == $operation_name){
                        $operation = $operations_child;
                        return $operation;
                    }
                }
            }
        }
    }
    else{
        $operation = NULL;
        $services_node = $sig_model_dom->firstChild;
        $services_childs_list = $services_node->childNodes;

        foreach($services_childs_list as $child){
            if($child->tagName == WSF_SERVICE && $child->attributes->getNamedItem(WSF_ADDRESS) &&
                    $child->attributes->getNamedItem(WSF_ADDRESS)->value == $endpoint_address){
                $service_node = $child;
                if(!$service_node)
                    return NULL;
                $service_child_list = $service_node->childNodes;
                /* search the operations element of the sig */
                foreach($service_child_list as $service_child){
                    if($service_child->tagName == WSF_OPERATIONS){
                        $operations_node = $service_child;
                        if($operations_node){
                            foreach($operations_node->childNodes as $operations_child){
                                if($operations_child->tagName == WSF_OPERATION){
                                    $operation_node = $operations_child->attributes;
                                    if($operation_node->getNamedItem(WSF_NAME) && 
                                            $operation_node->getNamedItem(WSF_NAME)->value == $operation_name){
                                        $operation = $operations_child;
                                        return $operation;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return $operation;
    }
}


/**
 * Return response parameters as a DOM node.
 * @param DomNode $signature_node Node points to the signature element in sigmodel  
 * @return DomNode Cloned DomNode
 */
function wsf_get_response_parameters(DomNode $signature_node)
{
    $signature_child_list = $signature_node->childNodes;
    foreach($signature_child_list as $signature_child){
        if($signature_child->tagName == WSF_RETURNS){
            $clone_return_node = $signature_child->cloneNode(TRUE);
            return $clone_return_node;
        }
    }
}


/**
 * Creates the payload to be passed to C level.
 * @param DomNode $signature_node 
 * @param Bool $is_doc true if doc-lit or false if rpc style
 * @param string $operation_name Name of the operation to be invoked
 * @param int $arg_count No of arguments in the function
 * @param array $argument array of arguments of the function to be invoked
 * @param array $class_map array of class mappings for complex types 
 * @param DomNode $schema_node schema for the given WSDL
 */

function wsf_create_payload(DomNode $signature_node, $is_doc, $operation_name, $arg_count, $arguments, array $class_map = NULL)
{
    $tmp_param_struct = array();
    $is_wrapper = FALSE;
   
    if($signature_node){
        $params_node = $signature_node->firstChild;
        if($params_node && $params_node->localName == WSF_PARAMS){
            if($params_node->hasAttributes()){
                /* Wrapper element of the request operation */
                $params_attr = $params_node->attributes;
                $ele_name = NULL;
                if($params_attr->getNamedItem(WSF_WRAPPER_ELEMENT)){
                    $ele_name = $params_attr->getNamedItem(WSF_WRAPPER_ELEMENT)->value;
                }
                $ele_ns = NULL;
                if($params_attr->getNamedItem(WSF_WRAPPER_ELEMENT_NS)){
                    $ele_ns = $params_attr->getNamedItem(WSF_WRAPPER_ELEMENT_NS)->value;
                }
                $child_array =  array();
                $child_array[WSF_NS] = $ele_ns;
                $child_array[WSF_HAS_SIG_CHILDS] = TRUE;
                $is_wrapper = TRUE;
                            
                $param_child_list = $params_node->childNodes;
                foreach($param_child_list as $param_child){
                    $param_attr = $param_child->attributes;
                    $ele_ns = NULL;
                    $param_name = $param_attr->getNamedItem(WSF_NAME)->value;
                    $param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
                    $child_array[$param_name] = wsf_create_temp_struct($param_child, $ele_ns); 
                }
            }
            else{
                /* No wrapper element in the request */
                $child_array =  array();
                $ele_ns = NULL;
                $param_child_list = $params_node->childNodes;
                foreach($param_child_list as $param_child){
                    $param_attr = $param_child->attributes;
                    $param_name = $param_attr->getNamedItem(WSF_NAME)->value;
                    $param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
                    $child_array[$param_name] = wsf_create_temp_struct($param_child, $ele_ns);
                    $ele_name = $param_name;
                }
            }
        }
        if ($is_wrapper == TRUE)
            $tmp_param_struct[$ele_name] = $child_array;
        else
            $tmp_param_struct = $child_array;
    }


    /* no wrapper elements most probably getter functions */
    if(count($tmp_param_struct) == 0)
        return NULL;
 
    if($is_doc == TRUE){
        $payload_dom = new DOMDocument('1.0', 'iso-8859-1');
        $element = $payload_dom->createElementNS($tmp_param_struct[$ele_name][WSF_NS], "ns1:".$ele_name);
        if(is_object($arguments[0])){
            /* this is class map support */
            $new_obj = $arguments[0];
            $parameter_structure = $tmp_param_struct[$ele_name];
            $namespace_map = array($tmp_param_struct[$ele_name][WSF_NS] => "ns1");

            wsf_create_payload_for_class_map($payload_dom, $parameter_structure, $element, $element, $new_obj,
                                                                        $namespace_map);
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);

            return $payload_dom->saveXML($clone_node);
        }
        else {
            /* array type implementation */
            $parameter_structure = $tmp_param_struct[$ele_name];
            $namespace_map = array($tmp_param_struct[$ele_name][WSF_NS] => "ns1");

            wsf_create_payload_for_array($payload_dom, $parameter_structure, $element, $element, $arguments[0],
                                                                       $namespace_map);
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);

            return $payload_dom->saveXML($clone_node);
        }
    }else{
        $payload_dom = new DOMDocument('1.0', 'iso-8859-1');
        $element = $payload_dom->createElementNS($tmp_param_struct[$ele_name][WSF_NS], "ns1:".$ele_name);
        $element->setAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
        $element->setAttribute("xmlns:xsd", "http://www.w3.org/2001/XMLSchema");


        if(is_object($arguments[0])){
            $new_obj = $arguments[0];
            $parameter_structure = $tmp_param_struct[$ele_name];
            $namespace_map = array($tmp_param_struct[$ele_name][WSF_NS] => "ns1");
            //wsf_create_rpc_payload_for_class_map($payload_dom, $parameter_structure, $element, $element, $new_obj,
            //                                                          $namespace_map);a
            // currently we handle both rpc and doc lit sameway
            wsf_create_payload_for_class_map($payload_dom, $parameter_structure, $element, $element, $new_obj,
                                                                        $namespace_map);
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);
            return $payload_dom->saveXML($clone_node);
        }
        else {
            /* array type implementation */
            $parameter_structure = $tmp_param_struct[$ele_name];
            $namespace_map = array($tmp_param_struct[$ele_name][WSF_NS] => "ns1");

            //wsf_create_rpc_payload_for_array($payload_dom, $parameter_structure, $element, $element, $arguments[0],
            //                                                           $namespace_map);
            wsf_create_payload_for_array($payload_dom, $parameter_structure, $element, $element, $arguments[0],
                                                                       $namespace_map);

            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);
            return $payload_dom->saveXML($clone_node);
        }
    }
}

?>

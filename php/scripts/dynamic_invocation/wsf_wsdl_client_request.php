<?php
/*
 * Copyright 2005,2006 WSO2, Inc. http://wso2.com
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
function wsf_find_operation(DomDocument $sig_model_dom, $operation_name, $endpoint_address, $is_multiple)
{
    require_once('wsf_wsdl_consts.php');
    require_once('wsf_wsdl_util.php');

    if ($is_multiple == FALSE){
        $operation = NULL;
        $services_node = $sig_model_dom->firstChild;
        $services_childs_list = $services_node->childNodes;
        
        foreach($services_childs_list as $child){
            if($child->tagName == WSF_SERVICE && $child->attributes->getNamedItem(WSF_ADDRESS)->value == $endpoint_address){
                $service_node = $child;
                break;
            }
        }
        
        if(!$service_node)
            return NULL;
        
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
                    if($operation_node->getNamedItem(WSF_NAME)->value == $operation_name){
                        $operation = $operations_child;
                        break;
                    }
                }
            }
        }
        
        return $operation;
    }
    else{
        $operation = NULL;
        $services_node = $sig_model_dom->firstChild;
        $services_childs_list = $services_node->childNodes;

        foreach($services_childs_list as $child){
            if($child->tagName == WSF_SERVICE && $child->attributes->getNamedItem(WSF_ADDRESS)->value == $endpoint_address){
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
                                    if($operation_node->getNamedItem(WSF_NAME)->value == $operation_name){
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
    
    if(($is_doc == TRUE)  && $signature_node){
        $params_node = $signature_node->firstChild;
        if($params_node && $params_node->localName == WSF_PARAMS){
            if($params_node->hasAttributes()){
                /* Wrapper element of the request operation */
                $params_attr = $params_node->attributes;
                $ele_name = $params_attr->getNamedItem(WSF_WRAPPER_ELEMENT)->value;
                $ele_ns = $params_attr->getNamedItem(WSF_WRAPPER_ELEMENT_NS)->value;
                $child_array =  array();
                $child_array[WSF_NS] = $ele_ns;
                $is_wrapper = TRUE;
                            
                $param_child_list = $params_node->childNodes;
                foreach($param_child_list as $param_child){
                    $param_attr = $param_child->attributes;
                    $param_name = $param_attr->getNamedItem(WSF_NAME)->value;
                    $param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
                    $child_array[$param_name] = wsf_create_temp_struct($param_child); 
                }
            }
            else{
                /* No wrapper element in the request */
                $child_array =  array();
                $param_child_list = $params_node->childNodes;
                foreach($param_child_list as $param_child){
                    $param_attr = $param_child->attributes;
                    $param_name = $param_attr->getNamedItem(WSF_NAME)->value;
                    $param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
                    $child_array[$param_name] = wsf_create_temp_struct($param_child);
                    $ele_name = $param_name;
                }
            }
        }
        if ($is_wrapper == TRUE)
            $tmp_param_struct[$ele_name] = $child_array;
        else
            $tmp_param_struct = $child_array;
    }
    $payload_dom = new DOMDocument('1.0', 'iso-8859-1');
    $element = $payload_dom->createElementNS($tmp_param_struct[$ele_name][WSF_NS], $ele_name);
    if(is_object($arguments[0])){
        /* this is class map support */
        $new_obj = $arguments[0];
        $parameter_structure = $tmp_param_struct[$ele_name];
        wsf_create_payload_for_class_map($payload_dom, $parameter_structure, $element, $new_obj);
        $payload_dom->appendChild($element);
        $payload_node = $payload_dom->firstChild;
        $clone_node = $payload_node->cloneNode(TRUE);
        return $payload_dom->saveXML($clone_node);
    }
    else {
        /* array type implementation */
        $parameter_structure = $tmp_param_struct[$ele_name];
        wsf_create_payload_for_array($payload_dom, $parameter_structure, $element, $arguments[0]);
        $payload_dom->appendChild($element);
        $payload_node = $payload_dom->firstChild;
        $clone_node = $payload_node->cloneNode(TRUE);
        return $payload_dom->saveXML($clone_node);
    }

}

/**
 * Recursive function to create temperaly structure
 * @param DomNode $types_node schema node of the WSDL
 * @param string $param_type Type of the parameter
 */


function wsf_create_temp_struct(DomNode $param_child)
{
    $rec_array = array();
    $param_nil = NULL;
    $param_min = NULL;
    $param_max = NULL;

    $param_attr = $param_child->attributes;
    if($param_attr->getNamedItem(WSF_WSDL_SIMPLE))
        $wrap_type = $param_attr->getNamedItem(WSF_WSDL_SIMPLE)->value;
    if($param_attr->getNamedItem(WSF_TARGETNAMESPACE))
        $param_ns = $param_attr->getNamedItem(WSF_TARGETNAMESPACE)->value;
    if($param_attr->getNamedItem(WSF_TYPE))
        $param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
    if($param_attr->getNamedItem(WSF_TYPE_NAMESPACE))
        $param_type_ns = $param_attr->getNamedItem(WSF_TYPE_NAMESPACE)->value;
    if($param_attr->getNamedItem('minOccurs'))
        $param_min = $param_attr->getNamedItem('minOccurs')->value;
    if($param_attr->getNamedItem('maxOccurs'))
        $param_max = $param_attr->getNamedItem('maxOccurs')->value;
    if($param_attr->getNamedItem('nillable'))
        $param_nil = $param_attr->getNamedItem('nillable')->value;

    if($wrap_type == 'yes'){
        $rec_array[WSF_NS] = $param_ns;
        $rec_array[WSF_TYPE] = $param_type;
        if($param_min)
            $rec_array['minOccurs'] = $param_min; 
        if($param_max != 1)
            $rec_array['maxOccurs'] = $param_max; 
        if($param_nil)
            $rec_array['nillable'] = $param_nil; 
    }
    else{
        
        /* for some WSDL sig model gives simple type no even there are
         * xsd types in the parameter. So this check is needed */
        
        if (is_xsd_type($param_type)){
            $rec_array[WSF_NS] = $param_ns;
            $rec_array[WSF_TYPE] = $param_type;
            if($param_min)
                $rec_array['minOccurs'] = $param_min; 
            if($param_max != 1)
                $rec_array['maxOccurs'] = $param_max; 
            if($param_nil)
                $rec_array['nillable'] = $param_nil; 
        }
        else{
            $rec_array[WSF_NS] = $param_ns;
            $rec_array['class_map_name'] = $param_type;
            if($param_min)
                $rec_array['minOccurs'] = $param_min; 
            if($param_max != 1)
                $rec_array['maxOccurs'] = $param_max; 
            if($param_nil)
            $rec_array['nillable'] = $param_nil; 
            
            $param_child_list_level2 = $param_child->childNodes;
            foreach($param_child_list_level2 as $param_child_level2){
                $param_child_level2_attr = $param_child_level2->attributes;
            $param_level2_name = $param_child_level2_attr->getNamedItem(WSF_NAME)->value;
            $rec_array[$param_level2_name] = wsf_create_temp_struct($param_child_level2);
            }
        }
    }

    return $rec_array;
    
}

/**
 * Recursive function to create payload 
 * @param DomDocument $payload_dom 
 * @param array $value_array Array that include payload details
 * @param DomNode $element 
 * @param mixed $new_obj call_map object
 */


function wsf_create_payload_for_class_map(DomDocument $payload_dom, $parameter_struct, DomNode $root_ele, $classmap_obj, $prev_class_obj = NULL)
{
    static $i = 2;
    foreach($parameter_struct as $val => $value){
        if(is_array($value)){
            if($value[WSF_NS]){
                if (isset($value[WSF_TYPE]) && $value[WSF_TYPE] && $classmap_obj){
                    if($classmap_obj->$val)
                        $obj_value = $classmap_obj->$val;
                    else
                        $obj_value = $prev_class_obj->$val;
                    $element_2 = $payload_dom->createElementNS($value[WSF_NS], "ns".$i.":".$val, $obj_value);
                }
                else {
                    if(isset($value['nillable'])){
                        if(isset($value['maxOccurs'])){
                        }
                        else{
                            $element_2 = $payload_dom->createElementNS($value['ns'], "ns".$i.":".$val);
                            $prev_class_obj = $classmap_obj;
                            $new_obj = $classmap_obj->$val;
                            $i++;
                            wsf_create_payload_for_class_map($payload_dom, $value, $element_2, $new_obj, $prev_class_obj);
             
                        }
                    }
                    else{
                        if(!isset($value['class_map_name'])){
                            $element_2 = $payload_dom->createElementNS($value['ns'], "ns".$i.":".$val);
                            $prev_class_obj = $classmap_obj;
                            $new_obj = $classmap_obj->$val;
                            $i++;
                            wsf_create_payload_for_class_map($payload_dom, $value, $element_2, $new_obj, $prev_class_obj);
                        }
                    }
                }
            }
            $root_ele->appendChild($element_2);
        }
    }
}

function wsf_create_payload_for_array(DomDocument $payload_dom, $parameter_struct, DomNode $root_ele, $argument_array)
{
    static $i = 2;
    foreach($parameter_struct as $key => $value){
        if(is_array($value)){
            if($value[WSF_NS]){
                if (isset($value[WSF_TYPE]) && $value[WSF_TYPE]){
                    foreach($argument_array as $arg_key => $arg_val){
                        if($key == $arg_key){
                            /* type conversion is needed */
                            $element_2 = $payload_dom->createElementNS($value[WSF_NS], "ns".$i.":".$key, $arg_val);
                            $root_ele->appendChild($element_2);
                            $i++;
                        }
                    }
                }
                else {
                    foreach($argument_array as $arg_key => $arg_val){
                        if($key == $arg_key){
                            $element_2 = $payload_dom->createElementNS($value[WSF_NS], "ns".$i.":".$key);
                            wsf_create_payload_for_array($payload_dom, $value, $element_2, $arg_val);
                            $root_ele->appendChild($element_2);
                            $i++;
                        }
                    }
             
                }
            }
        }else if($key == WSF_TYPE && is_xsd_type($value)){
            /* TODO multiple values */
            if($value == 'boolean' && !$argument_array[0])
                $element_2 = $payload_dom->createTextNode(0);
            else
                $element_2 = $payload_dom->createTextNode($argument_array[0]);
            $root_ele->appendChild($element_2);
        }
    }

}



?>




















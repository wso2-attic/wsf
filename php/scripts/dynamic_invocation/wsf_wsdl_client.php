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


/**
 * Processes and validate response message and assign values to class map.
 * @param DomDocument $envelope_dom response envelope
 * @param DomDocument $signature_dom response parameter string
 * @param array $response_parameters array of response parameters
 * @return mixed an object, an array or a simple type in line with the 
 * expected format of the response
 */
function wsf_client_response_and_validate(DomDocument $envelope_dom, DomDocument $signature_dom, $response_parameters)
{
    require_once('wsf_wsdl_consts.php');
    require_once('wsf_wsdl_util.php');

    $tmp_param_struct = array();

    $envelope_node = $envelope_dom->documentElement;
    $returns_node = $signature_dom->documentElement;

    $ele_ns = NULL;
    $is_wrapper = FALSE;

    if($returns_node){
        if($returns_node->localName == WSF_RETURNS){
            if($returns_node->hasAttributes()){
                /* Wrapper element of the request operation */
                $params_attr = $returns_node->attributes;
                $ele_name = $params_attr->getNamedItem(WSF_WRAPPER_ELEMENT)->value;
                $ele_ns = $params_attr->getNamedItem(WSF_WRAPPER_ELEMENT_NS)->value;
                $child_array =  array();
                $child_array[WSF_NS] = $ele_ns;
                $is_wrapper = TRUE;
                            
                $param_child_list = $returns_node->childNodes;
                foreach($param_child_list as $param_child){
                    $param_attr = $param_child->attributes;
                    $param_name = $param_attr->getNamedItem(WSF_NAME)->value;
                    $param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
                    $child_array[$param_name] = wsf_create_temp_struct($param_child, $ele_ns); 
                }
            }
            else{
                /* No wrapper element in the request */
                $child_array =  array();
                $param_child_list = $returns_node->childNodes;
                foreach($param_child_list as $param_child){
                    $param_attr = $param_child->attributes;
                    $param_name = $param_attr->getNamedItem(WSF_NAME)->value;
                    $param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
                    $child_array[$param_name] = wsf_create_temp_struct($param_child, $ele_ns);
                    $ele_name = $param_name;
                }
            }
        }
    }

    if ($is_wrapper == TRUE)
        $tmp_param_struct = $child_array;
    else
        $tmp_param_struct = $child_array[$ele_name];



    /** get SOAP body DOM tree to compare with Sig model */
	foreach($envelope_node->childNodes as $env_child_node){
		if($env_child_node->localName == 'Body'){
			$soap_body_node = $env_child_node->firstChild;
			break;
		}
	}

	if(!$soap_body_node){
		error_log("soap_body not found", 0);
	}

    $class_map = NULL;
    if(isset($response_parameters[WSF_CLASSMAP]))
        $class_map = $response_parameters[WSF_CLASSMAP];

    $op_param_values = array();
    if($class_map !== NULL)
    {
        $op_param_values = wsf_parse_payload_for_class_map($soap_body_node, $tmp_param_struct, $ele_name, $class_map);
    }
    else
    {
        $op_param_values = wsf_parse_payload_for_array($soap_body_node, $tmp_param_struct);
    }

    return $op_param_values;
}

?>

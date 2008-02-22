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


function wsf_serivce_invoke_function($operation_node, $function_name, $class_name, $class_args, $envelope_node, $class_map)
{
    require_once("wsf_wsdl_util.php");
	if($operation_node){
		foreach($operation_node->childNodes as $style){
			if($style->tagName == WSF_SIGNATURE){
				$signature_node = $style;
                break;
			}
		}
	}

    $is_doc = TRUE; //currently we only support doc-lit style parsing..
    $is_wrapper = FALSE;

    if($signature_node){
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
    }

    if ($is_wrapper == TRUE)
        $tmp_param_struct = $child_array;
    else
        $tmp_param_struct = $child_array[$ele_name];
    

	foreach($envelope_node->childNodes as $env_child_node){
		if($env_child_node->localName == 'Body'){
			$soap_body_node = $env_child_node->firstChild;
			break;
		}
	}

	if(!$soap_body_node){
		error_log("soap_body not found", 0);
	}

    $op_param_values = array();
    if($class_map != NULL && !empty($class_map))
    {
        $op_param_values = wsf_parse_payload_for_service_class_map($soap_body_node, $tmp_param_struct, $ele_name, $class_map);
    }
    else
    {
        $op_param_values = wsf_parse_payload_for_array($soap_body_node, $tmp_param_struct);
    }

    

    
    $arg_array = $op_param_values; 
    if($class_name != NULL)
    {
        // First call the constructor
        $class = new ReflectionClass($class_name);
        $class_inst = $class->newInstanceArgs($class_args);
        
        // Then the user method
        $method = $class->getMethod($function_name);
        $response_value = $method->invokeArgs($class_inst, $arg_array);
    }
    else
    {
        $response_value = call_user_func_array($function_name, $arg_array);
    }
    $response_payload_string = wsf_wsdl_create_response_payload($response_value, $signature_node);

	return $response_payload_string;
}

function wsf_wsdl_create_response_payload($return_val, $signature_node)
{
    require_once("wsf_wsdl_util.php");

    $is_doc = TRUE;
	$is_wrapper = FALSE;
	$tmp_param_struct = array();

	$res_payload_dom = new DOMDocument('1.0', 'iso-8859-1');
	 
	foreach ($signature_node->childNodes as $signature_child_node){
		if($signature_child_node->localName == WSF_RETURNS){
			$returns_node = $signature_child_node;
            break;
		}
	}

	if(!$returns_node)
	    error_log("Returns node not found", 0);

	if($returns_node->hasAttributes()){
		$ele_name = $returns_node->attributes->getNamedItem(WSF_WRAPPER_ELEMENT)->value;
		$ele_ns = $returns_node->attributes->getNamedItem(WSF_WRAPPER_ELEMENT_NS)->value;
		$body_array = array();
		$body_array[WSF_NS] = $ele_ns;
        $body_array[WSF_HAS_SIG_CHILDS] = TRUE;
		$is_wrapper = TRUE;
	}
    else
    {
        $ele_ns = NULL;
        $ele_name = NULL;
    }


	$param_child_list = $returns_node->childNodes;
	foreach($param_child_list as $param_child){
		$param_attr = $param_child->attributes;
		$param_name = $param_attr->getNamedItem(WSF_NAME)->value;
		$param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
		$body_array[$param_name] = wsf_create_temp_struct($param_child, $ele_ns);
        if($ele_name === NULL) /* that is when the wrapper element is not exist */
        {
            $ele_name= $param_name;        
        }
	}

	if($is_wrapper == TRUE)
	    $tmp_param_struct[$ele_name] = $body_array;
	else
	    $tmp_param_struct = $body_array;

    $arguments = $return_val;


    /* no wrapper elements most probably getter functions */
    if(count($tmp_param_struct) == 0)
        return NULL;

 
    if($is_doc == TRUE){
        $ele_ns = $tmp_param_struct[$ele_name][WSF_NS];
        $payload_dom = new DOMDocument('1.0', 'iso-8859-1');
        $element = $payload_dom->createElementNS($ele_ns, "ns1:".$ele_name);
        if(is_object($arguments)){
            /* this is class map support */
            $new_obj = $arguments;
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

            wsf_create_payload_for_array($payload_dom, $parameter_structure, $element, $element, $arguments,
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


        if(is_object($arguments)){
            $new_obj = $arguments;
            $parameter_structure = $tmp_param_struct[$ele_name];
            $namespace_map = array($tmp_param_struct[$ele_name][WSF_NS] => "ns1");
            wsf_create_rpc_payload_for_class_map($payload_dom, $parameter_structure, $element, $element, $new_obj,
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
            wsf_create_rpc_payload_for_array($payload_dom, $parameter_structure, $element, $element, $arguments[0],
                                                                       $namespace_map);
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);
            return $payload_dom->saveXML($clone_node);
        }
    }
}


?>

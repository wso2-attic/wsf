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


function wsf_serivce_invoke_function($operation_node, $function_name, $class_name, $class_args, $envelope_node, $classmap) {
    require_once('wsf_wsdl_consts.php');
    require_once('wsf_wsdl_util.php');
    require_once('wsf_wsdl_deserialization.php');

	if($operation_node) {
		foreach($operation_node->childNodes as $style) {
			if($style->tagName == WSF_SIGNATURE) {
				$sig_node = $style;
                break;
			}
		}
	}

    $is_doc = TRUE; //currently we only support doc-lit style parsing..
    $is_wrapper = FALSE;
    $params_node = NULL;
    $is_direct_list = FALSE;

    if($sig_node) {
        $params_node = $sig_node->firstChild;
        if($params_node && $params_node->localName == WSF_PARAMS) {
            if($params_node->hasAttributes()) {
                /* Wrapper element of the request operation */
                $sig_attrs = $params_node->attributes;

                if($sig_attrs->getNamedItem(WSF_WRAPPER_ELEMENT)) {
                    $ele_name = $sig_attrs->getNamedItem(WSF_WRAPPER_ELEMENT)->value;
                }
                if($sig_attrs->getNamedItem(WSF_WRAPPER_ELEMENT_NS)) {
                    $ele_ns = $sig_attrs->getNamedItem(WSF_WRAPPER_ELEMENT_NS)->value;
                }

                $is_wrapper = TRUE;
            }
            else{
                /* No wrapper element in the request */
                $ele_ns = NULL;
                $ele_name = NULL;

                /* check for the only param target-namespace */
                $only_param = $params_node->firstChild;
                $sig_attrs = $only_param->attributes;
                
                if($sig_attrs->getNamedItem(WSF_TARGETNAMESPACE)) {
                    $ele_ns = $sig_attrs->getNamedItem(WSF_TARGETNAMESPACE)->value;
                }
                if($sig_attrs->getNamedItem(WSF_NAME)) {
                    $ele_name = $sig_attrs->getNamedItem(WSF_NAME)->value;
                }
                if($sig_attrs->getNamedItem(WSF_LIST)) {
                    $is_direct_list = $sig_attrs->getNamedItem(WSF_LIST)->value;
                }
            }
        }
    }

	foreach($envelope_node->childNodes as $env_child_node) {
		if($env_child_node->localName == WSF_SOAP_BODY) {
			$soap_body_node = $env_child_node->firstChild;
			break;
		}
	}

	if(!$soap_body_node) {
		error_log("soap_body not found", 0);
	}

    $op_param_values = array();
    if($classmap != NULL && !empty($classmap)) {
        ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "starting to parse payload as a classmap");
        $op_param_values = wsf_parse_payload_for_class_map($soap_body_node, $params_node, $ele_name, $classmap);
    }
    else
    {
        ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "starting to parse payload as an array");
        $op_param_values = wsf_parse_payload_for_array($soap_body_node, $params_node);
    }

    
    $arg_array = $op_param_values; 
    if($class_name != NULL) {
        // First call the constructor
        $class = new ReflectionClass($class_name);

        if($class) {
            if($class_args && is_array($class_args)) {
                $class_inst = $class->newInstanceArgs($class_args);
            }
            else {
                $class_inst = $class->newInstanceArgs(array());
            }
            
            // Then the user method
            $method = $class->getMethod($function_name);
            if(($classmap != NULL && !empty($classmap)) || $is_direct_list) {
                // for direct lists we follow same api as classmap
                $response_value = $method->invoke($class_inst, $arg_array);
            }
            else {
                $response_value = $method->invokeArgs($class_inst, $arg_array);
            }
        }
        else {
        ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, "class : $class_name doesn't exists");
        }
    }
    else
    {
        if(($classmap != NULL && !empty($classmap)) || $is_direct_list) {
            // for direct lists we follow same api as classmap
            $response_value = call_user_func($function_name, $arg_array);
        }
        else {
            $response_value = call_user_func_array($function_name, $arg_array);
        }
    }
    
    $response_payload_string = wsf_wsdl_create_response_payload($response_value, $sig_node);

	return $response_payload_string;
}

function wsf_wsdl_create_response_payload($return_val, $sig_node) {
    require_once('wsf_wsdl_consts.php');
    require_once('wsf_wsdl_util.php');
    require_once('wsf_wsdl_serialization.php');

    $is_doc = TRUE;
	$is_wrapper = FALSE;

    // starting prefix index of the xml to be built
    $prefix_i = 2;

	$res_payload_dom = new DOMDocument('1.0', 'iso-8859-1');
	 
	foreach ($sig_node->childNodes as $signature_child_node) {
		if($signature_child_node->localName == WSF_RETURNS) {
			$returns_node = $signature_child_node;
            break;
		}
	}

	if(!$returns_node) {
	    error_log("Returns node not found", 0);
        return NULL;
    }

	if($returns_node->hasAttributes()) {
        $ele_name = NULL;
        $ele_ns = NULL;

        if($returns_node->attributes->getNamedItem(WSF_WRAPPER_ELEMENT)) {
		    $ele_name = $returns_node->attributes->getNamedItem(WSF_WRAPPER_ELEMENT)->value;
        }
        if($returns_node->attributes->getNamedItem(WSF_WRAPPER_ELEMENT_NS)) {
		    $ele_ns = $returns_node->attributes->getNamedItem(WSF_WRAPPER_ELEMENT_NS)->value;
        }
		
        $is_wrapper = TRUE;

	}
    else
    {
        /* No wrapper element in the request */
        $ele_ns = NULL;
        $ele_name = NULL;

        /* check for the only param target-namespace */
        $only_param = $returns_node->firstChild;
        $sig_attrs = $only_param->attributes;
        
        if($sig_attrs->getNamedItem(WSF_TARGETNAMESPACE)) {
            $ele_ns = $sig_attrs->getNamedItem(WSF_TARGETNAMESPACE)->value;
        }

        if($sig_attrs->getNamedItem(WSF_NAME)) {
            $ele_name = $sig_attrs->getNamedItem(WSF_NAME)->value;
        }
    }

    $arguments = $return_val;


    /* no wrapper elements most probably getter functions */
    if($returns_node == NULL) {
        return NULL;
    }

 
    if($is_doc == TRUE) {
        $payload_dom = new DOMDocument('1.0', 'iso-8859-1');
        $element = $payload_dom->createElementNS($ele_ns, WSF_STARTING_NS_PREFIX.":".$ele_name);
        if(is_object($arguments)) {
            /* this is class map support */
            $new_obj = $arguments;
            $namespace_map = array($ele_ns => WSF_STARTING_NS_PREFIX);
            wsf_create_payload_for_class_map($payload_dom, $returns_node, $element, $element, $new_obj,
                                                                     $prefix_i, $namespace_map);
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);

            return $payload_dom->saveXML($clone_node);
        }
        else {
            /* array type implementation */
            $namespace_map = array($ele_ns => WSF_STARTING_NS_PREFIX);

            wsf_create_payload_for_array($payload_dom, $returns_node, $element, $element, $arguments,
                                                                     $prefix_i, $namespace_map);
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);
            return $payload_dom->saveXML($clone_node);
        }
    }else {
        $payload_dom = new DOMDocument('1.0', 'iso-8859-1');
        $element = $payload_dom->createElementNS($ele_ns, WSF_STARTING_NS_PREFIX.":".$ele_name);
        $element->setAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
        $element->setAttribute("xmlns:xsd", "http://www.w3.org/2001/XMLSchema");


        if(is_object($arguments)) {
            $new_obj = $arguments;
            $namespace_map = array($ele_ns => WSF_STARTING_NS_PREFIX);
            wsf_create_rpc_payload_for_class_map($payload_dom, $returns_node, $element, $element, $new_obj,
                                                                     $prefix_i, $namespace_map);
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);
            return $payload_dom->saveXML($clone_node);
        }
        else {
            /* array type implementation */
            $namespace_map = array($ele_ns => WSF_STARTING_NS_PREFIX);
            wsf_create_rpc_payload_for_array($payload_dom, $returns_node, $element, $element, $arguments[0],
                                                                     $prefix_i, $namespace_map);
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);
            return $payload_dom->saveXML($clone_node);
        }
    }
}


?>

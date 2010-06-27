<?php
/*
 * Copyright (c) 2005-2010 WSO2, Inc. http://wso2.com
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
 * service invoke function
 */
function wsf_serivce_invoke_function($operation_node, $function_name, $class_name,
    $class_args, $soap_body_node, $header_node, $classmap, $mtom_on,
                $cid2cont_type, $cid2attachments) {

    require_once('wsf_wsdl_consts.php');
    require_once('wsf_wsdl_util.php');
    require_once('wsf_wsdl_deserialization.php');

    $sig_node = NULL;
    $binding_details_node = NULL;
	if($operation_node) {
		foreach($operation_node->childNodes as $operation_child) {
			if($operation_child->tagName == WSF_SIGNATURE) {
				$sig_node = $operation_child;
			}
            if($operation_child->tagName == WSF_BINDINDG_DETAILS) {
                $binding_details_node = $operation_child;
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

	if(!$soap_body_node) {
        ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "soap_body not found");
	}

    // parsing input headers
    $header_params = array();
    $output_headers = array();
    if($header_node) {
        $header_first_child = $header_node->firstChild;
        $output_index = 0;

        if($binding_details_node) {
            $binding_details_childs = $binding_details_node->childNodes;

            foreach($binding_details_childs as $binding_details_child) {
                if($binding_details_child->nodeType == XML_ELEMENT_NODE &&
                    $binding_details_child->nodeName == WSF_SOAPHEADER &&
                    $binding_details_child->attributes->getNamedItem(WSF_HEADER_FOR_ATTRIBUTE)) {

                    if($binding_details_child->attributes->getNamedItem(WSF_HEADER_FOR_ATTRIBUTE)->value == WSF_WSDL_INPUT) {

                        //so this is the next input element..
                        $sig_attrs = $binding_details_child->attributes;

                        if($sig_attrs->getNamedItem(WSF_TYPE)) {
                            $ele_name = $sig_attrs->getNamedItem(WSF_TYPE)->value;
                        }
                        if($sig_attrs->getNamedItem(WSF_TYPE_NAMESPACE)) {
                            $ele_ns = $sig_attrs->getNamedItem(WSF_TYPE_NAMESPACE)->value;
                        }

                        // for the starting sig we have to go for the header node name we want

                        //go to the next header
                        if($header_first_child) {
                            $header_child = $header_first_child;
                            while($header_child  && ($header_child->nodeType == XML_TEXT_NODE ||
                                    !($header_child->localName == $ele_name && $header_child->namespaceURI == $ele_ns))) {
                                $header_child = $header_child->nextSibling;
                            }
                        }

                        if($header_child) {
                            $header_sig = $binding_details_child->firstChild;
                            if($classmap != NULL && !empty($classmap)) {
                                ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "starting to parse header $ele_name as a classmap");
                                $new_param = wsf_parse_payload_for_class_map($header_child, $header_sig, $ele_name, $classmap,
                                                                               $cid2cont_type, $cid2attachments);
                                ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "parsed_pram ".print_r($new_param, TRUE)." as a classmap");
                            }
                            else
                            {
                                ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "starting to parse header $ele_name as an array");
                                $new_param = wsf_parse_payload_for_array($header_child, $header_sig,
                                                                               $cid2cont_type, $cid2attachments);
                            }
                            $header_params[] = $new_param;
                        }
                        else {
                            //if header child doesn't exist better check whether it is an requeired header
                            if($sig_attrs && $sig_attrs->getNamedItem(WSF_REQUIRED) && $sig_attrs->getNamedItem(WSF_REQUIRED)->value == "true") {
                                //throwing faults saying it is required
                                throw new WSFault("Sender", "Requried header {$ele_name}|{$ele_ns} missing");
                            }
                        }

                    }
                    else if($binding_details_child->attributes->getNamedItem(WSF_HEADER_FOR_ATTRIBUTE)->value == WSF_WSDL_OUTPUT){
                        $output_headers[$output_index] = array(); //to retrive later
                        $header_params[] = &$output_headers[$output_index]; //to feed to the user operation
                        
                        $output_index ++;
                    }
                }
            }
        }
    }

    //parsing the pyalod
    $op_param_values = array();
    if($classmap != NULL && !empty($classmap)) {
        if($soap_body_node)
        {
            ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "starting to parse payload as a classmap");
            $op_param_values = wsf_parse_payload_for_class_map($soap_body_node, $params_node, $ele_name, $classmap,
                                                           $cid2cont_type, $cid2attachments);
        }
        $arg_array = array_merge(array($op_param_values), $header_params); 
    }
    else
    {
        if($soap_body_node)
        {
            ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "starting to parse payload as an array");
            $op_param_values = wsf_parse_payload_for_array($soap_body_node, $params_node,
                                                           $cid2cont_type, $cid2attachments);
            if(!is_array($op_param_values) || $is_direct_list) {
                // this can happens when returning simple types
                $op_param_values = array($op_param_values);
            }
        }
        $arg_array = array_merge($op_param_values, $header_params); 
    }

    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, print_r($arg_array, TRUE));
	

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
				
                $response_value = $method->invokeArgs($class_inst, $arg_array);
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
			$response_value = call_user_func_array($function_name, $arg_array);
        }
		else {
            $response_value = call_user_func_array($function_name, $arg_array);
        }
    }

    $attachment_map = array();

    $response_payload_string = wsf_wsdl_create_response_payload($response_value, $sig_node, $mtom_on,
                                    $attachment_map, $classmap);
    $output_header_string =
            wsf_wsdl_create_response_headers($binding_details_node, $output_headers, $mtom_on,
                                    $attachment_map, $classmap);


	return array(WSF_RESPONSE_PAYLOAD => $response_payload_string, 
                WSF_OUTPUT_HEADERS => $output_header_string,
                WSF_ATTACHMENT_MAP => $attachment_map);
}

/**
 * Generate the response headers
 */
function wsf_wsdl_create_response_headers($binding_details_node, $arguments, $mtom_on, $attachment_map, $classmap) {

    $output_headers = array();
    $argument_index = 0;
    if($binding_details_node) {
        $binding_details_childs = $binding_details_node->childNodes;

        foreach($binding_details_childs as $binding_details_child) {
            if($binding_details_child->nodeType == XML_ELEMENT_NODE &&
                $binding_details_child->nodeName == WSF_SOAPHEADER &&
                $binding_details_child->attributes->getNamedItem(WSF_HEADER_FOR_ATTRIBUTE) &&
                $binding_details_child->attributes->getNamedItem(WSF_HEADER_FOR_ATTRIBUTE)->value == WSF_WSDL_OUTPUT) {
                //so this is the next input element..

                $header_name = "";
                $header_ns = "";
                if($binding_details_child->attributes->getNamedItem(WSF_TYPE)) {
                    $header_name = $binding_details_child->attributes->getNamedItem(WSF_TYPE)->value;
                }
                if($binding_details_child->attributes->getNamedItem(WSF_TYPE_NAMESPACE)) {
                    $header_ns = $binding_details_child->attributes->getNamedItem(WSF_TYPE_NAMESPACE)->value;
                }

                $header_dom = new DOMDocument('1.0', 'iso-8859-1');
                $element = $header_dom->createElementNS($header_ns, WSF_STARTING_NS_PREFIX.":".$header_name);

                if(array_key_exists($argument_index, $arguments)) {

                    $namespace_map = array($header_ns => WSF_STARTING_NS_PREFIX);
                    $argument = $arguments[$argument_index];

                    $header_sig = $binding_details_child->firstChild;

                    if($argument && is_array($argument)){
                        wsf_create_payload_for_array($header_dom, $header_sig, $element, $element, $arguments,
                                                  $prefix_i, $namespace_map, $mtom_on, $attachment_map);
                    }
                    else if($argument && is_object($argument)) {

                        wsf_create_payload_for_class_map($header_dom, $header_sig, $element, $element, $argument, $classmap,
                                                  $prefix_i, $namespace_map, $mtom_on, $attachment_map);
                    }
                    else if($argument) {
                        // this can be tiny little simple type
                        $text_node = new DOMText($argument);
                        $element->appendChild($text_node);
                    }

                    $header_dom->appendChild($element);
                    $header_node = $header_dom->firstChild;
                    $clone_node = $header_node->cloneNode(TRUE);
                    $header_str = $header_dom->saveXML($clone_node);

                    $output_headers[] = $header_str;

                }
                else {
                    break;
                }

                $argument_index ++;
            }
        }
    }
    return $output_headers;
}

/**
 * Generate the payload
 */
function wsf_wsdl_create_response_payload($return_val, $sig_node, $mtom_on, &$attachment_map, $classmap) {
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
            wsf_create_payload_for_class_map($payload_dom, $returns_node, $element, $element, $new_obj, $classmap,
                                             $prefix_i, $namespace_map, $mtom_on, $attachment_map);
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);

            return $payload_dom->saveXML($clone_node);
        }
        else {
            /* array type implementation */
            $namespace_map = array($ele_ns => WSF_STARTING_NS_PREFIX);

            wsf_create_payload_for_array($payload_dom, $returns_node, $element, $element, $arguments,
                                               $prefix_i, $namespace_map, $mtom_on, $attachment_map);
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
            wsf_create_payload_for_class_map($payload_dom, $returns_node, $element, $element, $new_obj, $classmap,
                                             $prefix_i, $namespace_map, $mtom_on, $attachment_map);
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);
            return $payload_dom->saveXML($clone_node);
        }
        else {
            /* array type implementation */
            $namespace_map = array($ele_ns => WSF_STARTING_NS_PREFIX);
            wsf_create_payload_for_array($payload_dom, $returns_node, $element, $element, $arguments,
                                               $prefix_i, $namespace_map, $mtom_on, $attachment_map);
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);
            return $payload_dom->saveXML($clone_node);
        }
    }
}


?>

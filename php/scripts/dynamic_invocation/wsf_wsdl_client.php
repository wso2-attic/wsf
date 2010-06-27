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
 * Return response parameters as a DOM node.
 * @param DomNode $sig_node Node points to the signature element in sigmodel  
 * @return DomNode Cloned DomNode
 */
function wsf_get_response_parameters(DomNode $sig_node)
{
    $signature_child_list = $sig_node->childNodes;
    foreach($signature_child_list as $signature_child) {
        if($signature_child->tagName == WSF_RETURNS) {
            $clone_return_node = $signature_child->cloneNode(TRUE);
            return $clone_return_node;
        }
    }
}


/**
 * Creates the payload to be passed to C level.
 * @param DomNode $sig_node the sig node of the operation
 * @param Bool $is_doc true if doc-lit or false if rpc style
 * @param string $operation_name Name of the operation to be invoked
 * @param int $arg_count No of arguments in the function
 * @param array $argument array of arguments of the function to be invoked
 * @param array $classmap array of class mappings for complex types 
 * @param DomNode $schema_node schema for the given WSDL
 */
function wsf_create_payload(DomNode $sig_node, $is_doc, $operation_name,
            $arg_count, $arguments, array $classmap = NULL, $mtom_on, &$attachment_map)
{
    require_once('wsf_wsdl_consts.php');
    require_once('wsf_wsdl_util.php');
    require_once('wsf_wsdl_serialization.php');

    // if the sig is an immediate simple type then
    // it is expected to have is_wrapper = TRUE
    $is_wrapper = FALSE;
    $params_node = NULL;

    // starting prefix index to build the xml
    $prefix_i = 2;
   
    if($sig_node) {
        $params_node = $sig_node->firstChild;
        if($params_node && $params_node->localName == WSF_PARAMS) {
            if($params_node->hasAttributes()) {
                /* Wrapper element of the request operation */
                $sig_attrs = $params_node->attributes;
                $ele_name = NULL;
                $ele_ns = NULL;
                if($sig_attrs->getNamedItem(WSF_WRAPPER_ELEMENT)) {
                    $ele_name = $sig_attrs->getNamedItem(WSF_WRAPPER_ELEMENT)->value;
                }
                if($sig_attrs->getNamedItem(WSF_WRAPPER_ELEMENT_NS)) {
                    $ele_ns = $sig_attrs->getNamedItem(WSF_WRAPPER_ELEMENT_NS)->value;
                }
                $is_wrapper = TRUE;
                            
            }
            else {
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
            }
        }
    }

    if($params_node == NULL) {
        return NULL;
    }
                                
    
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "element name: $ele_name");

    // the returning payload..
    $payload_str = NULL;

    /*if(array_key_exists(0, $arguments) && $arguments[0] === NULL) {
        $payload_str = NULL;
    }*/ 
    if(
        ($ele_name == NULL || $ele_name == "#any")) {
        $payload_str = NULL;
    }
    else if($is_doc == TRUE) {

        $payload_dom = new DOMDocument('1.0', 'iso-8859-1');
        $element = $payload_dom->createElementNS($ele_ns, WSF_STARTING_NS_PREFIX.":".$ele_name);
        if(!array_key_exists(0, $arguments)) {
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);


            $payload_str = $payload_dom->saveXML($clone_node);
        }
        else if(is_object($arguments[0])) {

            /* this is class map support */
            $new_obj = $arguments[0];
            $namespace_map = array($ele_ns => WSF_STARTING_NS_PREFIX);
            wsf_create_payload_for_class_map($payload_dom, $params_node, $element, $element, $new_obj, $classmap,
                                                  $prefix_i, $namespace_map, $mtom_on, $attachment_map);
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);

            $payload_str = $payload_dom->saveXML($clone_node);
        }
        else {
            /* array type implementation */
            $namespace_map = array($ele_ns => WSF_STARTING_NS_PREFIX);

            wsf_create_payload_for_array($payload_dom, $params_node, $element, $element, $arguments[0],
                                                   $prefix_i, $namespace_map, $mtom_on, $attachment_map);
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);

            $payload_str = $payload_dom->saveXML($clone_node);
        }
    }
    else {
        $payload_dom = new DOMDocument('1.0', 'iso-8859-1');
        $element = $payload_dom->createElementNS($ele_ns, WSF_STARTING_NS_PREFIX.":".$ele_name);
        $element->setAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
        $element->setAttribute("xmlns:xsd", "http://www.w3.org/2001/XMLSchema");


        if(is_object($arguments[0])) {
            $new_obj = $arguments[0];
            
            $namespace_map = array($ele_ns => WSF_STARTING_NS_PREFIX);
            // currently we handle both rpc and doc lit sameway
            wsf_create_payload_for_class_map($payload_dom, $params_node, $element, $element, $new_obj, $classmap,
                                                           $prefix_i, $namespace_map, $mtom_on, $attachment_map);
            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);
            $payload_str = $payload_dom->saveXML($clone_node);
        }
        else {
            /* array type implementation */
            
            $namespace_map = array($ele_ns => WSF_STARTING_NS_PREFIX);

            wsf_create_payload_for_array($payload_dom, $params_node, $element, $element, $arguments[0],
                                                           $prefix_i, $namespace_map, $mtom_on, $attachment_map);

            $payload_dom->appendChild($element);
            $payload_node = $payload_dom->firstChild;
            $clone_node = $payload_node->cloneNode(TRUE);
            $payload_str = $payload_dom->saveXML($clone_node);
        }
    }
    
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "test: ".$payload_str);

    $binding_details_node = NULL;
    $binding_details_node = $sig_node->nextSibling;

    while(($binding_details_node && $binding_details_node->nodeType == XML_ELEMENT_NODE) &&
            $binding_details_node->nodeName != WSF_BINDINDG_DETAILS) {
        $binding_details_node = $binding_details_node->nextSibling;
    }

    $input_headers = array();

    $argument_index = 1;
    if($binding_details_node) {
        $binding_details_childs = $binding_details_node->childNodes;

        foreach($binding_details_childs as $binding_details_child) {
            if($binding_details_child->nodeType == XML_ELEMENT_NODE && 
                $binding_details_child->nodeName == WSF_SOAPHEADER &&
                $binding_details_child->attributes->getNamedItem(WSF_HEADER_FOR_ATTRIBUTE) &&
                $binding_details_child->attributes->getNamedItem(WSF_HEADER_FOR_ATTRIBUTE)->value == WSF_WSDL_INPUT) {
                
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

                    $input_headers[] = $header_str;

                }
                else {
                    break;
                }

                $argument_index ++;
            }
        }
    }

    return array(WSF_REQUEST_PAYLOAD => $payload_str,
                WSF_INPUT_HEADERS => $input_headers);
}


/**
 * Processes and validate response message and assign values to class map.
 * @param DomDocument $payload_dom response payload
 * @param DomDocument $header_dom response header, can be NULL
 * @param DomDocument $operation_sig_dom operation sig model
 * @param array $response_parameters array of response parameters
 * @return mixed an object, an array or a simple type in line with the 
 * expected format of the response
 */
function wsf_client_response_and_validate(DomDocument $payload_dom, 
        $header_dom,
        DomDocument $operation_sig_dom,
        $response_parameters,
        $mtom_on = FALSE)
{
    require_once('wsf_wsdl_consts.php');
    require_once('wsf_wsdl_util.php');
    require_once('wsf_wsdl_deserialization.php');

    $payload_node = $payload_dom->documentElement;
    $operation_sig_node = $operation_sig_dom->documentElement;
    $binding_details_node = NULL;

    $sig_method = NULL;
    //extracting out the sig_method from the operation sig node
    if($operation_sig_node) {
        foreach($operation_sig_node->childNodes as $operation_sig_child) {
            if($operation_sig_child->tagName == WSF_SIGNATURE) {
                $sig_method = $operation_sig_child;
            }
            if($operation_sig_child->tagName == WSF_BINDINDG_DETAILS) {
                $binding_details_node = $operation_sig_child;
            }
        }
    }

    $ele_ns = NULL;
    $is_wrapper = FALSE;

    if($sig_method) {
        $returns_node = $sig_method->firstChild;
        while($returns_node && $returns_node->localName != WSF_RETURNS) {
            $returns_node = $returns_node->nextSibling;
        }
        if($returns_node) {
            if($returns_node->hasAttributes()) {
                /* Wrapper element of the request operation */
                $sig_attrs = $returns_node->attributes;
                $ele_name = NULL;
                $ele_ns = NULL;
                if($sig_attrs->getNamedItem(WSF_WRAPPER_ELEMENT)) {
                    $ele_name = $sig_attrs->getNamedItem(WSF_WRAPPER_ELEMENT)->value;
                }
                if($sig_attrs->getNamedItem(WSF_WRAPPER_ELEMENT_NS)) {
                    $ele_ns = $sig_attrs->getNamedItem(WSF_WRAPPER_ELEMENT_NS)->value;
                }
                $is_wrapper = TRUE;
            }
            else {
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
        }
    }

    /** get SOAP body DOM tree to compare with Sig model */

    if(!$payload_node) {
        error_log("soap_body not found", 0);
    }

    $classmap = NULL;
    $cid2cont_type = array();
    $cid2attachments = array();

    if(array_key_exists(WSF_CLASSMAP, $response_parameters)) {
        $classmap = $response_parameters[WSF_CLASSMAP];
    }
    if(array_key_exists("attachments", $response_parameters)) {
        $cid2attachments = $response_parameters["attachments"];
    }
    if(array_key_exists("cid2contentType", $response_parameters)) {
        $cid2cont_type = $response_parameters["cid2contentType"];
    }

    $op_param_values = array();
    if($classmap !== NULL) {
        $op_param_values = wsf_parse_payload_for_class_map($payload_node, $returns_node,
                                $ele_name, $classmap, $cid2cont_type, $cid2attachments);
    }
    else {
        $op_param_values = wsf_parse_payload_for_array($payload_node, $returns_node,
                                $cid2cont_type, $cid2attachments);
    }

    $header_node = NULL;
    if($header_dom) {
        $header_node = $header_dom->documentElement;
    }

    $header_params = array();
    if($header_node) {
        $header_first_child = $header_node->firstChild;
        $output_index = 0;

        if($binding_details_node) {
            $binding_details_childs = $binding_details_node->childNodes;

            foreach($binding_details_childs as $binding_details_child) {
                if($binding_details_child->nodeType == XML_ELEMENT_NODE &&
                    $binding_details_child->nodeName == WSF_SOAPHEADER &&
                    $binding_details_child->attributes->getNamedItem(WSF_HEADER_FOR_ATTRIBUTE)) {

                    if($binding_details_child->attributes->getNamedItem(WSF_HEADER_FOR_ATTRIBUTE)->value == WSF_WSDL_OUTPUT) {

                        //so this is the next input element..
                        $sig_attrs = $binding_details_child->attributes;

                        if($sig_attrs->getNamedItem(WSF_TYPE)) {
                            $ele_name = $sig_attrs->getNamedItem(WSF_TYPE)->value;
                        }
                        if($sig_attrs->getNamedItem(WSF_TYPE_NAMESPACE)) {
                            $ele_ns = $sig_attrs->getNamedItem(WSF_TYPE_NAMESPACE)->value;
                        }

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
                            }
                            else
                            {
                                ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "starting to parse header $ele_name as an array");
                                $new_param = wsf_parse_payload_for_array($header_child, $header_sig,
                                                                               $cid2cont_type, $cid2attachments);
                            }
                            $header_params[] = $new_param;
                        }
                    }
                }
            }
        }
    }

    return array(WSF_RESPONSE_PAYLOAD_PARAM => $op_param_values,
                WSF_RESPONSE_HEADER_PARAM => $header_params);
}

?>

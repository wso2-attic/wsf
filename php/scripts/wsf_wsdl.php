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
 * This function is called from call_user_function in C level.
 * Once this function is called, it will fill in the WSDL information, 
 * such as payload, service endpoint, SOAP version, policies etc,
 * into an array and return that array.
 * @param array $user_parameters the details of WSDL endpoint, service address
 * and class map
 * @param array $function_parameters details of the invoked function
 * @return array $return_value array of details to be passed to C level
 */
function wsf_process_wsdl($user_parameters, $function_parameters)
{
    require_once('dynamic_invocation/wsf_wsdl_consts.php');
    require_once('dynamic_invocation/wsf_wsdl_util.php');
    require_once('dynamic_invocation/wsf_wsdl_client.php');
    
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "wsf_process_wsdl called");

    global $is_wsdl_11;
    global $wsdl_11_dom;

    $return_value = array();
    $policy_array = array();
    $binding_array = array();

    $is_doc_lit = FALSE;
    $is_rpc_enc = FALSE;
    $use_mtom = TRUE; //default to on

    $wsdl_dom = new DomDocument();
    $sig_model_dom  = new DOMDocument();

    /* retrieving the user parameters */
    $service = NULL;
    $port = NULL;
    if(array_key_exists(WSF_SERVICE_NAME, $user_parameters)) {
        $service = $user_parameters[WSF_SERVICE_NAME];
    }
    if(array_key_exists(WSF_PORT_NAME, $user_parameters)) {
        $port = $user_parameters[WSF_PORT_NAME];
    }
    if(array_key_exists(WSF_USE_MTOM, $user_parameters)) {
        $use_mtom = $user_parameters[WSF_USE_MTOM];
    }

    $wsdl_location = $user_parameters[WSF_WSDL];

    /* wsf endpoint is an optional parameter */
    if(isset($user_parameters[WSF_ENDPOINT])) {
        $endpoint_address = $user_parameters[WSF_ENDPOINT];
    }
    else {
        $endpoint_address = NULL;
    }
  
    /* class map is an optional parameter */
    if (isset($user_parameters[WSF_CLASSMAP])) {
        $class_map = $user_parameters[WSF_CLASSMAP];
    }
    else {
        $class_map = NULL;
    }


    /* extracting the information on function parameters */
    $operation_name = $function_parameters[WSF_INVOKE_FUNCTION];
    $arg_count = $function_parameters[WSF_ARG_COUNT];
    $arguments = $function_parameters[WSF_ARG_ARRAY];

    $sig_model_dom->preserveWhiteSpace = FALSE;
    $wsdl_dom->preserveWhiteSpace = FALSE;
       
    if(!$wsdl_location) {
        ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, "WSDL location uri is not found");
        return "WSDL locaiton uri is not found";
    }
    $is_multiple_interfaces = FALSE;

    // Load WSDL as DOM
    $wsdl_dom = new DOMDocument();
    if(!$wsdl_dom->load($wsdl_location)) {
        ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, "WSDL {$wsdl_location}could not be loaded");
        return "WSDL {$wsdl_location} could not be loaded.";
    }
   

    $wsdl_dom->preserveWhiteSpace = FALSE;
    /* changing code for processing mutiple port types in wsdl 1.1 */
    $is_multiple_interfaces = wsf_is_mutiple_port_types($wsdl_dom);

    if ($is_multiple_interfaces == FALSE) {
        $wsdl_dom = wsf_get_wsdl_dom($wsdl_dom, $wsdl_location);
        
        if(!$wsdl_dom) {
            ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, "Error creating WSDL Dom Document,".
                    "Please check whether the wsdl is an valid XML");
            return "Error creating WSDL Dom Document".
                    "Please check whether the wsdl is an valid XML";
        }
        
        $sig_model_dom = wsf_get_sig_model_dom($wsdl_dom);
    }
    else {
        $wsdl_dom = wsf_get_wsdl_dom($wsdl_dom, $wsdl_location);
        $sig_model_dom = wsf_process_multiple_interfaces($wsdl_dom);
    }
    
    if(!$sig_model_dom) {
        ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, "Error creating intermediate sig model");
        return "Error creating intermediate model";
    }

    /* endpoint_address is used for just to parse back to the c code: */
    if(!$endpoint_address) {
        $endpoint_address = wsf_get_endpoint_address($sig_model_dom);
    }
    else{
        $multiple_ep = TRUE;
        $multiple_ep = wsf_is_multiple_endpoints($sig_model_dom);
        if(!$multiple_ep) {
            $endpoint_address = wsf_get_endpoint_address($sig_model_dom);
        }
    }
    
    /* for retrieve binding we have to go to the old WSDL */
    if ($is_wsdl_11 &&  $wsdl_11_dom != NULL) {
        $binding_node = wsf_get_binding($wsdl_11_dom, $service, $port, TRUE);
        if(!$binding_node) {
            ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, "binding node not found");
            return  NULL;
        }
        $policy_array = wsf_get_all_policies($wsdl_11_dom, $binding_node, $operation_name, $is_wsdl_11);
        $is_rpc_enc =  wsf_is_rpc_enc_wsdl($wsdl_11_dom, $binding_node, $operation_name);
        /* rpc literal not supported */
    }
    else{
        $binding_node = wsf_get_binding($wsdl_dom, $service, $port);
        if(!$binding_node) {
            ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, "binding node not found");
            return  NULL;
        }
        $policy_array = wsf_get_all_policies($wsdl_dom, $binding_node, $operation_name);
    }

    $operation = wsf_find_operation($sig_model_dom, $operation_name, $service, $port, $is_multiple_interfaces);

    if(!$operation) {
        ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, "operation node not found");
        return;
    }

    $binding_array = wsf_get_binding_details($operation);

    //extracting out the sig_method from the operation sig node
    if($operation) {
        foreach($operation->childNodes as $style) {
            if($style->tagName == WSF_SIGNATURE) {
                $sig_method = $style;
                if($style->attributes->getNamedItem(WSF_METHOD)->value == WSF_INFERENCE)
                    $is_doc_lit = TRUE;
                else if ($style->attributes->getNamedItem(WSF_METHOD)->value == WSF_RPC)
                    $is_doc_lit = FALSE;
            }
        }
    }

    $attachment_map = array();
    $return_info = NULL;
    if($sig_method && !$is_rpc_enc) {
        $return_info = wsf_create_payload($sig_method, $is_doc_lit, $operation_name,
                    $arg_count, $arguments, $class_map, $use_mtom, $attachment_map);
    }
    else {
        $return_info = wsf_create_payload($sig_method, FALSE, $operation_name,
                $arg_count, $arguments, $class_map, $use_mtom, $attachment_map);
    }

    $payload = $return_info[WSF_REQUEST_PAYLOAD];
    $headers = $return_info[WSF_INPUT_HEADERS];

    $sig_model_string = $sig_model_dom->saveXML($operation);

    if($is_wsdl_11 == TRUE && $wsdl_11_dom) {
        $wsdl_dom = $wsdl_11_dom;
    }

    if(is_array($attachment_map) && count($attachment_map) == 0) {
        $attachment_map = NULL;
    }

    $wsdl_dom_string = $wsdl_dom->saveXML();
    $return_value = array(WSF_ENDPOINT_URI=> $endpoint_address,
                          WSF_BINDING_DETAILS=> $binding_array,
                          WSF_REQUEST_PAYLOAD=> $payload,
                          WSF_INPUT_HEADERS=> $headers,
                          WSF_POLICY_NODE=> $policy_array,
                          WSF_RESPONSE_SIG_MODEL => $sig_model_string,
                          WSF_WSDL_DOM => $wsdl_dom_string,
                          WSF_ATTACHMENT_MAP => $attachment_map);
    return $return_value;
}


/**
 * Processes and validate response message and assign values to class map.
 * @param string $response_payload_string response envelope
 * @param string $response_sig_model_string response parameter string
 * @param array $response_parameters array of response parameters
 * @return mixed an object, an array or a simple type in line with the 
 * expected format of the response
 */
function wsf_process_response($response_payload_string, 
                    $response_header_string,
                    $response_sig_model_string,
                    $response_parameters,
                    $wsdldom_string)
{
    require_once('dynamic_invocation/wsf_wsdl_consts.php');
    require_once('dynamic_invocation/wsf_wsdl_util.php');
    require_once('dynamic_invocation/wsf_wsdl_client.php');
    
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "wsf_process_resonse is called");

    $payload_dom = new DomDocument(); 
    $sig_model_dom = new DomDocument();
    $wsdl_dom = new DomDocument();

    $header_dom = NULL;
    
    $payload_dom->preserveWhiteSpace = FALSE;
    $sig_model_dom->preserveWhiteSpace = FALSE;
    $wsdl_dom->preserveWhiteSpace = FALSE;

    $payload_dom->loadXML($response_payload_string);
    $sig_model_dom->loadXML($response_sig_model_string);
    $wsdl_dom->loadXML($wsdldom_string);

    if($response_header_string && !empty($response_header_string)) {
        $header_dom = new DomDocument();
        $header_dom->preserveWhiteSpace = FALSE;
        $header_dom->loadXML($response_header_string);
    }
    
    $response_class = wsf_client_response_and_validate($payload_dom, $header_dom,
                                    $sig_model_dom, $response_parameters);
    
    return $response_class;
}

function wsf_process_wsdl_for_service($parameters, $operation_array)
{
    require_once('dynamic_invocation/wsf_wsdl_consts.php');
    require_once('dynamic_invocation/wsf_wsdl_util.php');
    require_once('dynamic_invocation/wsf_wsdl_service.php');

    global $is_wsdl_11;
    global $wsdl_11_dom;
    
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "wsf_process_wsdl_for_service called");
    
    $wsdl_dom = new DomDocument();
    $sig_model_dom  = new DOMDocument();
    $sig_model_dom->preserveWhiteSpace = FALSE;
    $wsdl_dom->preserveWhiteSpace = FALSE;
    
    $service_name = NULL;
    $port_name = NULL;

    if(array_key_exists(WSF_WSDL, $parameters)) { 
        $wsdl_location = $parameters[WSF_WSDL];
    }
    if(array_key_exists(WSF_SERVICE_NAME, $parameters)) {
        $service_name = $parameters[WSF_SERVICE_NAME];
    }
    if(array_key_exists(WSF_PORT_NAME, $parameters)) {
        $port_name = $parameters[WSF_PORT_NAME];
    }
    
    $sig_model_dom->preserveWhiteSpace = FALSE;
    $wsdl_dom->preserveWhiteSpace = FALSE;

    if(!$wsdl_location) {
        ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, "wsdl is not found");
        return "WSDL is not found";
    }
    $is_multiple_interfaces = FALSE;

    // Load WSDL as DOM
    $wsdl_dom = new DOMDocument();
    if(!$wsdl_dom->load($wsdl_location)) {
        ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, "WSDL {$wsdl_location} could not be loaded.");
        return "WSDL {$wsdl_location} could not be loaded.";
    }

    /* changing code for processing mutiple port types in wsdl 1.1 */
    $is_multiple_interfaces = wsf_is_mutiple_port_types($wsdl_dom);
    
    if ($is_multiple_interfaces == FALSE) {
        $wsdl_dom = wsf_get_wsdl_dom($wsdl_dom, $wsdl_location);
        
        if(!$wsdl_dom) {
            ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, "error creating WSDL Dom Document.");
            return "error creating WSDL Dom Document";
        }
        
        $sig_model_dom = wsf_get_sig_model_dom($wsdl_dom);
    }
    else {
        $wsdl_dom = wsf_get_wsdl_dom($wsdl_dom, $wsdl_location);
        $sig_model_dom = wsf_process_multiple_interfaces($wsdl_dom);
    }

    if(!$sig_model_dom) {
        ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, "error creating intermediate model.");
        return "error creating intermediate model";
    }
    
    $sig_model_string = $sig_model_dom->saveXML();
    
    /* creating policy array */
    $policy_array = array();
    /* this will no longer need for the service */
    $endpoint_address = wsf_get_endpoint_address($sig_model_dom);
    
    if ($is_wsdl_11 == TRUE && $wsdl_11_dom != NULL) {
        $binding_node = wsf_get_binding($wsdl_11_dom, $service_name, $port_name, TRUE);
        if(!$binding_node)
            return  NULL;
        foreach($operation_array as $value) {
            $policy_array[$value] = wsf_get_all_policies($wsdl_11_dom, $binding_node, $value, TRUE);
         } 
                
    }
    else{
        $binding_node = wsf_get_binding($wsdl_dom, $service_name, $port_name);
        if(!$binding_node)
            return  NULL;
        foreach($operation_array as $value) {
            $policy_array[$value] = wsf_get_all_policies($wsdl_dom, $binding_node, $value);
        }
    }
    
    $return_array = array();
    $return_array[WSF_SIG_MODEL_STRING] = $sig_model_string;
    $return_array[WSF_POLICIES] = $policy_array;
    
    return $return_array;
}

function wsf_wsdl_process_in_msg($parameters)
{
    require_once('dynamic_invocation/wsf_wsdl_consts.php');
    require_once('dynamic_invocation/wsf_wsdl_util.php');
    require_once('dynamic_invocation/wsf_wsdl_service.php');

    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "wsf_wsdl_process_in_msg is called");

    $payload_dom = new DomDocument();
    $sig_model_dom = new DomDocument();

    $payload_dom->preserveWhiteSpace = FALSE;
    $sig_model_dom->preserveWhiteSpace = FALSE;

    $service_name = NULL;
    $port_name = NULL;
    $is_multiple_interfaces = FALSE;
    
    $sig_model_string = NULL;
    $payload_string = NULL;
    $operation_name = NULL;
    $function_name = NULL;
    $class_name = NULL;
    $class_map = NULL;
    $class_args = NULL;
    $header_string = NULL;

    // this is about the respnse message
    $mtom_on = TRUE;

    $cid2cont_type = array();
    $cid2attachments = array();

    if(array_key_exists(WSF_SERVICE_NAME, $parameters)) {
        $service_name = $parameters[WSF_SERVICE_NAME];
    }
    if(array_key_exists(WSF_PORT_NAME, $parameters)) {
        $port_name = $parameters[WSF_PORT_NAME];
    }
  
    if(array_key_exists(WSF_SIG_MODEL_STRING, $parameters)) {
        $sig_model_string = $parameters[WSF_SIG_MODEL_STRING];
    }
    if(array_key_exists(WSF_PAYLOAD_STRING, $parameters)) {
        $payload_string = $parameters[WSF_PAYLOAD_STRING];
    }
    if(array_key_exists(WSF_OPERATION_NAME, $parameters)) {
        $operation_name = $parameters[WSF_OPERATION_NAME];
    }
    if(array_key_exists(WSF_FUNCTION_NAME, $parameters)) {
        $function_name = $parameters[WSF_FUNCTION_NAME];
    }
    if(array_key_exists(WSF_CLASS_NAME, $parameters)) {
        $class_name = $parameters[WSF_CLASS_NAME];
    }
    if(array_key_exists(WSF_CLASSMAP, $parameters)) {
        $class_map = $parameters[WSF_CLASSMAP];
    }
    if(array_key_exists(WSF_CLASS_ARGS, $parameters)) {
        $class_args = $parameters[WSF_CLASS_ARGS];
    }

    if(array_key_exists(WSF_ATTACHMENTS, $parameters)) {
        $cid2attachments = $parameters[WSF_ATTACHMENTS];
    }
    if(array_key_exists(WSF_CID2CONTENT_TYPE, $parameters)) {
        $cid2cont_type = $parameters[WSF_CID2CONTENT_TYPE];
    }
    if(array_key_exists(WSF_USE_MTOM, $parameters)) {
        $mtom_on = $parameters[WSF_USE_MTOM];
    }

    $header_element = NULL;
    if(array_key_exists(WSF_HEADER_STRING, $parameters)) {
        $header_string = $parameters[WSF_HEADER_STRING];
    
        if($header_string && !empty($header_string)) {
            $header_dom = new DomDocument(); 
            $header_dom->preserveWhiteSpace = FALSE;

            $header_dom->loadXML($header_string);
            $header_element = $header_dom->documentElement;
        }
    }

    $payload_dom->loadXML($payload_string);
    $sig_model_dom->loadXML($sig_model_string);

    $endpoint_address = wsf_get_endpoint_address($sig_model_dom);

    $operation_node = wsf_find_operation($sig_model_dom, $operation_name,
            $service_name, $port_name, $is_multiple_interfaces);

    if(!$operation_node) {
        ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, "$operation_name operaiton not found");
        throw new WSFault("Sender","$operation_name operation not found");
    }

    $payload_element = $payload_dom->documentElement;

    $return_payload_info = wsf_serivce_invoke_function($operation_node, $function_name,
                $class_name, $class_args, $payload_element, $header_element, $class_map,
                $mtom_on, $cid2cont_type, $cid2attachments);

    return $return_payload_info;
}

function wsf_wsdl_check() {
    return 1;
}

?>

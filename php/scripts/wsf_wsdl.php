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
    require_once('dynamic_invocation/wsf_wsdl_client_request.php');
    require_once('dynamic_invocation/wsf_wsdl_client_response.php');

    global $is_wsdl_11;
    global $wsdl_11_dom;

    $return_value = array();
    $policy_array = array();
    $binding_array = array();

    $is_doc_lit = FALSE;
    $is_rpc_enc = FALSE; 

    $wsdl_dom = new DomDocument();
    $sig_model_dom  = new DOMDocument();

    /* retrieving the user parameters */
    $service_name = NULL;
    $port_name = NULL;
    if(array_key_exists(WSF_SERVICE_NAME, $user_parameters)){
        $service = $user_parameters[WSF_SERVICE_NAME];
    }
    if(array_key_exists(WSF_PORT_NAME, $user_parameters)){
        $port = $user_parameters[WSF_PORT_NAME];
    }

    $wsdl_location = $user_parameters[WSF_WSDL];

    /* wsf endpoint is an optional parameter */
    if(isset($user_parameters[WSF_ENDPOINT]))
        $endpoint_address = $user_parameters[WSF_ENDPOINT];
    else
        $endpoint_address = NULL;
  
    /* class map is an optional parameter */
    if (isset($user_parameters[WSF_CLASSMAP]))
        $class_map = $user_parameters[WSF_CLASSMAP];
    else
        $class_map = NULL;


    /* extracting the information on function parameters */
    $operation_name = $function_parameters[WSF_INVOKE_FUNCTION];
    $arg_count = $function_parameters[WSF_ARG_COUNT];
    $arguments = $function_parameters[WSF_ARG_ARRAY];

    $sig_model_dom->preserveWhiteSpace = false;
    $wsdl_dom->preserveWhiteSpace = false;
       
    if(!$wsdl_location){
        error_log("WSDL location uri is not found");
        return "WSDL locaiton uri is not found";
    }
    $is_multiple_interfaces = FALSE;

    // Load WSDL as DOM
    $wsdl_dom = new DOMDocument();
    if(!$wsdl_dom->load($wsdl_location)) {
        error_log("WSDL {$wsdl_location}could not be loaded");
        return "WSDL {$wsdl_location} could not be loaded.";
    }
   

    $wsdl_dom->preserveWhiteSpace = false;
    /* changing code for processing mutiple port types in wsdl 1.1 */
    $is_multiple_interfaces = wsf_is_mutiple_port_types($wsdl_dom);

    if ($is_multiple_interfaces == FALSE) {
        $wsdl_dom = wsf_get_wsdl_dom($wsdl_dom);
        
        if(!$wsdl_dom) {
            error_log("Error creating WSDL Dom Document,".
                    "Please check whether the wsdl is an valid XML");
            return "Error creating WSDL Dom Document".
                    "Please check whether the wsdl is an valid XML";
        }
        
        $sig_model_dom = wsf_get_sig_model_dom($wsdl_dom);
    }
    else {
        $wsdl_dom = wsf_get_wsdl_dom($wsdl_dom);
        $sig_model_dom = wsf_process_multiple_interfaces($wsdl_dom);
    }
    
    if(!$sig_model_dom) {
        error_log("Error creating intermediate model");
        return "Error creating intermediate model";
    }

    /* endpoint_address is used for just to parse back to c code: */
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
    if ($is_wsdl_11 &&  $wsdl_11_dom != NULL){
        $binding_node = wsf_get_binding($wsdl_11_dom, $service, $port, TRUE);
        if(!$binding_node){
            error_log("binding node not found");
            return  NULL;
        }
        $policy_array = wsf_get_all_policies($wsdl_11_dom, $binding_node, $operation_name, $is_wsdl_11);
        $is_rpc_enc =  wsf_is_rpc_enc_wsdl($wsdl_11_dom, $binding_node, $operation_name);
        /* rpc literal not supported */
    }
    else{
        $binding_node = wsf_get_binding($wsdl_dom, $service, $port);
        if(!$binding_node){
            error_log("binding node not found");
            return  NULL;
        }
        $policy_array = wsf_get_all_policies($wsdl_dom, $binding_node, $operation_name);
    }

    $operation = wsf_find_operation($sig_model_dom, $operation_name, $service, $port, $is_multiple_interfaces);

    if(!$operation){
        error_log("operation node not found");
        return;
    }

    $binding_array = wsf_get_binding_details($operation);

    if($operation){
        foreach($operation->childNodes as $style){
            if($style->tagName == WSF_SIGNATURE){
                $sig_method = $style;
                if($style->attributes->getNamedItem(WSF_METHOD)->value == WSF_INFERENCE)
                    $is_doc_lit = TRUE;
                else if ($style->attributes->getNamedItem(WSF_METHOD)->value == WSF_RPC)
                    $is_doc_lit = FALSE;
            }
        }
    }

    if($sig_method && !$is_rpc_enc)
        $payload = wsf_create_payload($sig_method, $is_doc_lit, $operation_name, $arg_count, $arguments, $class_map);
    else
        $payload = wsf_create_payload($sig_method, FALSE, $operation_name, $arg_count, $arguments, $class_map);

    if($sig_method)
        $return_node = wsf_get_response_parameters($sig_method);
    $return_sig_model_string = $sig_model_dom->saveXML($return_node);

    if ($is_wsdl_11 == TRUE && $wsdl_11_dom)
        $wsdl_dom = $wsdl_11_dom;

    $wsdl_dom_string = $wsdl_dom->saveXML();
    $return_value = array(WSF_ENDPOINT_URI=> $endpoint_address,
                          WSF_BINDING_DETAILS=> $binding_array,
                          WSF_REQUEST_PAYLOAD=> $payload,
                          WSF_POLICY_NODE=> $policy_array,
                          WSF_RESPONSE_SIG_MODEL => $return_sig_model_string,
                          WSF_WSDL_DOM => $wsdl_dom_string);
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
function wsf_process_response($response_payload_string, $response_sig_model_string, $response_parameters, $wsdldom_string)
{
    require_once('dynamic_invocation/wsf_wsdl_consts.php');
    require_once('dynamic_invocation/wsf_wsdl_client_response.php');

    $envelope_dom = new DomDocument(); 
    $sig_model_dom = new DomDocument();
    $wsdl_dom = new DomDocument();
    
    $envelope_dom->preserveWhiteSpace = false;
    $sig_model_dom->preserveWhiteSpace = false;
    $wsdl_dom->preserveWhiteSpace = false;

    $envelope_dom->loadXML($response_payload_string);
    $sig_model_dom->loadXML($response_sig_model_string);
    $wsdl_dom->loadXML($wsdldom_string);
    
    $response_class = wsf_client_response_and_validate($envelope_dom, $sig_model_dom, $response_parameters);
    return $response_class;
}

function wsf_process_wsdl_for_service($parameters, $operation_array)
{
    require_once('dynamic_invocation/wsf_wsdl_consts.php');
    require_once('dynamic_invocation/wsf_wsdl_util.php');
    require_once('dynamic_invocation/wsf_wsdl_service.php');

    global $is_wsdl_11;
    global $wsdl_11_dom;
    
    $wsdl_dom = new DomDocument();
    $sig_model_dom  = new DOMDocument();
    $sig_model_dom->preserveWhiteSpace = false;
    $wsdl_dom->preserveWhiteSpace = false;
    
    $wsdl_location = $parameters[WSF_WSDL];
    if(array_key_exists(WSF_SERVICE_NAME, $parameters)){
        $service_name = $parameters[WSF_SERVICE_NAME];
    }
    if(array_key_exists(WSF_PORT_NAME, $parameters)){
        $port_name = $parameters[WSF_PORT_NAME];
    }
    
    $sig_model_dom->preserveWhiteSpace = false;
    $wsdl_dom->preserveWhiteSpace = false;

    if(!$wsdl_location){
        return "WSDL is not found";
    }
    $is_multiple_interfaces = FALSE;

    // Load WSDL as DOM
    $wsdl_dom = new DOMDocument();
    if(!$wsdl_dom->load($wsdl_location)){
        return "WSDL {$wsdl_location} could not be loaded.";
    }

    /* changing code for processing mutiple port types in wsdl 1.1 */
    $is_multiple_interfaces = wsf_is_mutiple_port_types($wsdl_dom);
    
    if ($is_multiple_interfaces == FALSE){
        $wsdl_dom = wsf_get_wsdl_dom($wsdl_dom);
        
        if(!$wsdl_dom){
            return "error creating WSDL Dom Document";
        }
        
        $sig_model_dom = wsf_get_sig_model_dom($wsdl_dom);
    }
    else {
        $wsdl_dom = wsf_get_wsdl_dom($wsdl_dom);
        $sig_model_dom = wsf_process_multiple_interfaces($wsdl_dom);
    }

    if(!$sig_model_dom){
        return "error creating intermediate model";
    }
    
    $sig_model_string = $sig_model_dom->saveXML();
    
    /* creating policy array */
    $policy_array = array();
    /* this will no longer need for the service */
    $endpoint_address = wsf_get_endpoint_address($sig_model_dom);
    
    if ($is_wsdl_11 == TRUE && $wsdl_11_dom != NULL){
        $binding_node = wsf_get_binding($wsdl_11_dom, $service, $port, TRUE);
        if(!$binding_node)
            return  NULL;
        foreach($operation_array as $value){
            $policy_array[$value] = wsf_get_all_policies($wsdl_11_dom, $binding_node, $value, TRUE);
         } 
                
    }
    else{
        $binding_node = wsf_get_binding($wsdl_dom, $endpoint_address);
        if(!$binding_node)
            return  NULL;
        foreach($operation_array as $value){
            $policy_array[$value] = wsf_get_all_policies($wsdl_dom, $binding_node, $value);
        }
    }
    
    $return_array = array();
    $return_array["sig_model_string"] = $sig_model_string;
    $return_array["policies"] = $policy_array;
    
    return $return_array;
}

function wsf_wsdl_process_in_msg($parameters)
{
    require_once('dynamic_invocation/wsf_wsdl_consts.php');
    require_once('dynamic_invocation/wsf_wsdl_util.php');
    require_once('dynamic_invocation/wsf_wsdl_client_request.php');
    require_once('dynamic_invocation/wsf_wsdl_service.php');

    $payload_dom = new DomDocument();
    $sig_model_dom = new DomDocument();


    $payload_dom->preserveWhiteSpace = false;
    $sig_model_dom->preserveWhiteSpace = false;

    $service_name = NULL;
    $port_name = NULL;
    $is_multiple_interfaces = FALSE;

    if(array_key_exists(WSF_SERVICE_NAME, $parameters)){
        $service_name = $parameters[WSF_SERVICE_NAME];
    }
    if(array_key_exists(WSF_PORT_NAME, $parameters)){
        $port_name = $parameters[WSF_PORT_NAME];
    }
   
    $sig_model_string = $parameters["sig_model_string"];
    $payload_string = $parameters["payload_string"];
    $operation_name = $parameters["operation_name"];
    $function_name = $parameters["function_name"];
    $class_name = $parameters["class_name"];
    $class_map = $parameters["classmap"];
    $class_args = $parameters["class_args"];

    
    
    $payload_dom->loadXML($payload_string);
    $sig_model_dom->loadXML($sig_model_string);

    $endpoint_address = wsf_get_endpoint_address($sig_model_dom);

    $operation_node = wsf_find_operation($sig_model_dom, $operation_name, $service_name, $port_name, $is_multiple_interfaces);

    if(!$operation_node){
        return "operation not found";
    }
    

    $return_payload_string = wsf_serivce_invoke_function($operation_node, $function_name, $class_name, $class_args, $payload_dom->firstChild, $class_map);

    return $return_payload_string;
}

function wsf_wsdl_check(){
    return 1;
}

?>

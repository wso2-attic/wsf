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

define("WSF_WSDL", "wsdl");
define("WSF_ENDPOINT", "endpoint");
define("WSF_INVOKE_FUNCTION", "invoke_function");
define("WSF_ARG_COUNT", "arg_count");
define("WSF_ARG_ARRAY", "arg_array");
define("WSF_SIGNATURE", "signature");
define("WSF_METHOD", "method");
define("WSF_INFERENCE", "inference");
define("WSF_RPC", "rpc");
define("WSF_ENDPOINT_URI", "endpoint_uri");
define("WSF_BINDING_DETAILS", "binding_details");
define("WSF_REQUEST_PAYLOAD", "request_payload");
define("WSF_POLICY_NODE", "policy_node");

define("WSF_DEFINITION", "definitions");
define("WSF_DESCRIPTION", "description");
define("WSF_OPERATIONS", "operations");
define("WSF_OPERATION" , "operation");
define("WSF_ADDRESS", "address");
define("WSF_NAME" , "name");
define("WSF_TYPE", "type");
define("WSF_ID", "Id");
define("WSF_SERVICE", "service");
define("WSF_BINDING", "binding");
define("WSF_POLICY_REFERENCE", "PolicyReference");
define("WSF_POLICY", "Policy");
define("WSF_REF", "ref");
define("WSF_URI", "URI");
define("WSF_PARAMS", "params");
define("WSF_PARAM" , "param");
define("WSF_WRAPPER_ELEMENT", "wrapper-element");
define("WSF_WRAPPER_ELEMENT_NS", "wrapper-element-ns");
define("WSF_TARGETNAMESPACE", "targetNamespace");
define("WSF_BINDINDG_DETAILS", "binding-details");
define("WSF_WSAWAACTION", "wsawaction");
define("WSF_SOAPACTION", "soapaction");
define("WSF_WSA", "wsa");
define("WSF_SOAP", "soap");
define("WSF_SOAP11", "SOAP11");
define("WSF_SOAP12", "SOAP12");
define("WSF_SOAP_VERSION", "soap_version");
define("WSF_RETURNS", "returns");
define("WSF_RESPONSE_SIG_MODEL", "response_sig_model");
define("WSF_ENVELOPE", "envelope");
define("WSF_BODY", "body");
define("WSF_RETURNS", "returns");
define("WSF_TYPE_NAMESPACE", "type-namespace");
define("WSF_CLASSMAP", "classmap");
define("WSF_NS", "ns");
define("WSF_TYPE_NS", "type_ns");
define("WSF_TNS", "tns");
define("WSF_PORT", "port");
define("WSF_LOCATION", "location");
define("WSF_XSLT_LOCATION", "xslt_location");

define("WSF_WSDL2_NAMESPACE", "http://www.w3.org/ns/wsdl");
define("WSF_WSDL_NAMESPACE", "http://schemas.xmlsoap.org/wsdl/");
define("WSF_POLICY_REFERENCE_NAMESPACE_URI", "http://schemas.xmlsoap.org/ws/2004/09/policy");
define("WSF_POLICY_NAMESPACE_URI", "http://www.w3.org/ns/ws-policy");
define("WSF_POLICY_ID_NAMESPACE_URI", "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd");

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
    global $is_wsdl_11;
    global $wsdl_11_dom;

    $return_value = array();
    $policy_array = array();
    $binding_array = array();

    $is_doc_lit = FALSE;

    $wsdl_dom = new DomDocument();
    $sig_model_dom  = new DOMDocument();

    $wsdl_location = $user_parameters[WSF_WSDL];
    if(isset($user_parameters[WSF_ENDPOINT]))
        $endpoint_address = $user_parameters[WSF_ENDPOINT];
    else
        $endpoint_address = NULL;
    $class_map = $user_parameters[WSF_CLASSMAP];
    $xslt_location = $user_parameters[WSF_XSLT_LOCATION];

    $operation_name = $function_parameters[WSF_INVOKE_FUNCTION];
    $arg_count = $function_parameters[WSF_ARG_COUNT];
    $arguments = $function_parameters[WSF_ARG_ARRAY];

    $sig_model_dom->preserveWhiteSpace = false;
    $wsdl_dom->preserveWhiteSpace = false;
    
    if(!$wsdl_location)
        return "WSDL is not found";
    
    $wsdl_dom = wsf_get_wsdl_dom($wsdl_location, $xslt_location);
    
    if(!$wsdl_dom)
        return "error creating WSDL Dom Document";
    
    $sig_model_dom = wsf_get_sig_model_dom($wsdl_dom, $xslt_location);
    
    if(!$sig_model_dom)
        return "error creating intermediate model";

    if(!$endpoint_address)
        $endpoint_address = wsf_get_endpoint_address($sig_model_dom);

    if ($is_wsdl_11 == TRUE && $wsdl_11_dom ){
        $binding_node = wsf_get_binding($wsdl_11_dom, $endpoint_address, $is_wsdl_11);
        if(!$binding_node)
            return  NULL;
        $policy_array = wsf_get_all_policies($wsdl_11_dom, $binding_node, $operation_name, $is_wsdl_11);
        
    }
    else{
        $binding_node = wsf_get_binding($wsdl_dom, $endpoint_address);
        if(!$binding_node)
            return  NULL;
        $policy_array = wsf_get_all_policies($wsdl_dom, $binding_node, $operation_name);
    }
        
    
    $operation = wsf_find_operation($sig_model_dom, $operation_name, $endpoint_address);

    if(!$operation){
        echo "\noperation not found";
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
 
    if($sig_method)
        $payload = wsf_create_payload($sig_method, $is_doc_lit, $operation_name, $arg_count, $arguments, $class_map);

    if($sig_method)
        $return_node = wsf_get_response_parameters($sig_method);
    
    $return_sig_model_string = $sig_model_dom->saveXML($return_node);

    $return_value = array(WSF_ENDPOINT_URI=> $endpoint_address,
                          WSF_BINDING_DETAILS=> $binding_array,
                          WSF_REQUEST_PAYLOAD=> $payload,
                          WSF_POLICY_NODE=> $policy_array,
                          WSF_RESPONSE_SIG_MODEL => $return_sig_model_string);
    
    
    return $return_value;
}

/**
 * Create WSDL DomDocument from given WSDL location.
 * If given WSDL is WSDL1.1 then it would be coverted to a WSDL2.0
 * @param string $wsdl_location 
 * @return DomDocument $wsdl_dom DomDocument of WSDL2.0 
 */
function wsf_get_wsdl_dom($wsdl_location, $xslt_location){
    
    $wsdl_dom = new DOMDocument();
    $xslt_wsdl_20_dom = new DOMDocument();
    $xslt_11_to_20_dom = new DOMDocument();
    $xslt_11_to_20_dom->preserveWhiteSpace = false;
    $wsdl_dom->preserveWhiteSpace = false;
    $xslt = new XSLTProcessor();
    global $wsdl_11_dom, $is_wsdl_11;
   
    if($wsdl_dom->load($wsdl_location)){
        if($wsdl_dom->firstChild->localName == WSF_DEFINITION){ 
            /* first element local name is definitions, so this is a 
               version 1.1 WSDL */
            if(!($xslt_wsdl_20_dom->load($xslt_location."/wsdl11to20.xsl10.xsl")))
                return "WSDL 1.1 to 2.0 converting stylesheet not found";
            $xslt->importStyleSheet($xslt_wsdl_20_dom);
            $xslt_11_to_20_dom->loadXML($xslt->transformToXML($wsdl_dom));
            $is_wsdl_11 = TRUE;
            $wsdl_11_dom = $wsdl_dom;
            return $xslt_11_to_20_dom;
        }
        else if ($wsdl_dom->firstChild->localName == WSF_DESCRIPTION) {
            /* first element local name is description, so this is a 
               version 2.0 WSDL */
            return $wsdl_dom;
        }
        else
            return NULL;
    }
    else
        return NULL;
}


/**
 * Creates the Sig model DomDocument from WSDL2.0 DomDocument.
 * @param DomDocument $wsdl_dom WSDL2.0 DomDocument
 * @return DomDocument Sig model DomDocument
 */

function wsf_get_sig_model_dom(DomDocument $wsdl_dom, $xslt_location)
{
    $xslt_dom  = new DOMDocument();
    $xsl = new XSLTProcessor();

    if($xslt_dom->load($xslt_location."/wsdl2sig.xslt")){
        $xsl->importStyleSheet($xslt_dom);
        return $xsl->transformToDoc($wsdl_dom);
    }
    else
        return NULL;
}

/**
 * Returns the endpoint address from Sig model DOM.
 * @param $DomDocument $sig_model_dom Sig model DomDocument 
 * @return string endpoint address value
 */

function wsf_get_endpoint_address(DomDocument $sig_model_dom)
{
    $services_node = $sig_model_dom->firstChild;
    $service_node = $services_node->firstChild;
    $service_attr = $service_node->attributes;
    return $service_attr->getNamedItem(WSF_ADDRESS)->value;
}


/**
 * Finds the operation DomNode.
 * @param DomDocument $sig_model_dom 
 * @param string $operation_name name of the param to be invoked
 * @param string $endpoint_address service endpoint address
 * @return DomNode operation DomNode of the Sig model
 */
function wsf_find_operation(DomDocument $sig_model_dom, $operation_name, $endpoint_address)
{
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
            if($operations_child->tagName == WSF_OPERATION){
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

/**
 * Creates the payload to be passed to C level.
 * @param DomNode $signature_node 
 * @param Bool $is_doc true if doc-lit or false if rpc style
 * @param string $operation_name Name of the operation to be invoked
 * @param int $arg_count No of arguments in the function
 * @param array $argument array of arguments of the function to be invoked
 * @param array $class_map array of class mappings for complex types 
 */
function wsf_create_payload(DomNode $signature_node, $is_doc, $operation_name, $arg_count, $arguments, array $class_map = NULL)
{
    $np1= "ns0";
    $np2= "ns";
    
    if(($is_doc == TRUE)  && $signature_node){
        if($signature_node->firstChild->tagName == WSF_PARAMS){
            if($signature_node->firstChild->hasAttributes()){
                $params_attr = $signature_node->firstChild->attributes;
                $ele_name = $params_attr->getNamedItem(WSF_WRAPPER_ELEMENT)->value;
                if($ele_name == $operation_name){
                    $ns0 = $params_attr->getNamedItem(WSF_WRAPPER_ELEMENT_NS)->value;
                    
                    /* TODO: how about qualified and unqualified schemas? */
                    
                    /* start creating payload */
                    $root1 = "<".$np1.":".$ele_name." xmlns:".$np1."=\"".$ns0."\">";
                    /* one element or wrapper elements? */
                    $params = $signature_node->firstChild;
                    if(!($params->hasChildNodes())){
                        if ($arg_count == 0){
                            $return_node = $root1. "</".$np1.":".$ele_name.">";
                            return $return_node;
                        }
                        else if ($class_map){
                            $return_node = $root1. "</".$np1.":".$ele_name.">";
                            return $return_node;
                        }
                        else
                            return "Invalid Arguments to function";
                    }
                    else{
                        /* more wrapper elements --- there may be a class map 
                           or it is an array of arrays type */
                        if(is_object($arguments[0])){
                            /* this is a class map */
                            $no_of_elements = $params->childNodes->length;
                            $new_obj = $arguments[0];
                            $ref_obj = new ReflectionObject($new_obj);
                            $prop_array = $ref_obj->getProperties();
                            
                            $param = $params->firstChild;
                            $rest_payload = "";
                            for($i = 0; $i < $no_of_elements; $i++){
                                $param_attr = $param->attributes;
                                $name = $param_attr->getNamedItem(WSF_NAME)->value;
                                $type = $param_attr->getNamedItem(WSF_TYPE)->value;
                                $ns2 = $param_attr->getNamedItem(WSF_TARGETNAMESPACE)->value;
                                
                                $test = $ref_obj->message;
                                
                                if($ns0 == $ns2){
                                    $ns2 = $ns0;
                                    $np2 = $np1;
                                }
                                else
                                    $np2 = $np2.$i;
  
                                if(!$ns2)
                                    $tmp_value = "<".$name." xmlns:ns".($i+1)."=\"".$ns0."\">".$new_obj->$name."</".$name.">";
                                else
                                    $tmp_value = "<ns".($i+1).":".$name." xmlns:ns".($i+1)."=\"".$ns2."\">".$new_obj->$name."</ns".($i+1).":".$name.">";

                                $rest_payload = $rest_payload.$tmp_value;

                                $param = $param->nextSibling;

                            }

                            return  $root1.$rest_payload. "</".$np1.":".$ele_name.">";
                            
                        }
                        else if(!$params->childNodes->length == $arg_count){
                            return "Invalid Function Parameters";
                        }
                        else{
                            /* it is an array of array */ 
                            $no_of_elements = $params->childNodes->length;
                            $param = $params->firstChild;
                            $rest_payload = "";
                            for($i = 0; $i < $no_of_elements; $i++){
                                $param_attr = $param->attributes;
                                $name = $param_attr->getNamedItem(WSF_NAME)->value;
                                $type = $param_attr->getNamedItem(WSF_TYPE)->value;
                                $ns2 = $param_attr->getNamedItem(WSF_TARGETNAMESPACE)->value;
                                
                                if($ns0 == $ns2){
                                    $ns2 = $ns0;
                                    $np2 = $np1;
                                }
                                else
                                    $np2 = $np2.$i;
                                
                                /* TODO: may be when it is  unqualified schema?? */
                                if(!$ns2)
                                    $tmp_value = "<".$name." xmlns:ns".($i+1)."=\"".$ns0."\">".$arguments[$i]."</".$name.">";
                                else
                                    $tmp_value = "<ns".($i+1).":".$name." xmlns:ns".($i+1)."=\"".$ns2."\">".$arguments[$i]."</ns".($i+1).":".$name.">";
                                
                                $rest_payload = $rest_payload.$tmp_value;
                                
                                $param = $param->nextSibling;
                                
                            }
                            
                            return  $root1.$rest_payload. "</".$np1.":".$ele_name.">"; 
                        }
                        
                    }
                }
            }
            
            else{
                
                /* when no wrapper elements and only one element 
                   it is simple type */
                $params = $signature_node->firstChild;
                $param = $params->firstChild;
                /* if there are more elements there should be a loop */
                if($param->hasAttributes()){
                    $param_attr = $param->attributes;
                    $name = $param_attr->getNamedItem(WSF_NAME)->value;
                    $type = $param_attr->getNamedItem(WSF_TYPE)->value;
                    $ns1 = $param_attr->getNamedItem("targetNamespace")->value;
                    if($ns1)
                        $return_val = "<ns0:".$name." xmlns:ns0=\"".$ns1."\">".$arguments[0]."</ns0:".$name.">";
                    else
                        $return_val = "<".$name.">".$arguments[0]."</".$name.">";
                    return $return_val;
                }                    
            }
          }
    }
}

/**
 * Returns the binding node corresponding to the given endpoint address.
 * @param DomDocument $wsdl_dom WSDL2.0 DomDocument
 * @param string $endpoint_address 
 * @param Bool $$is_wsdl_11 true is WSDL version 1.1, else false 
 * @return DomNode binding DomNode
 */
function wsf_get_binding(DomDocument $wsdl_dom, $endpoint_address, $is_wsdl_11 = FALSE)
{
    if($is_wsdl_11 == FALSE){
         $root_node = $wsdl_dom->firstChild;
         $root_child_list = $root_node->childNodes;
         
         
         foreach($root_child_list as $childs){
             if($childs->localName == WSF_SERVICE && $childs->namespaceURI == WSF_WSDL2_NAMESPACE){
                 $service_node = $childs;
                 break;
             }
         }
         
         if(!$service_node){
             echo "serivice node not found";
             return;
         }
         
         $service_child_list = $service_node->childNodes;
         foreach($service_child_list as $service_childs){
             if($service_childs->localName == WSF_ENDPOINT && $service_childs->namespaceURI == WSF_WSDL2_NAMESPACE){
                 if($service_childs->attributes->getNamedItem(WSF_ADDRESS)->value == $endpoint_address){
                     $binding_name = $service_childs->attributes->getNamedItem(WSF_BINDING)->value;
                     break;
                 }
             }
         }
         
         if(!$binding_name){
             echo "binding_name not found";
             return;
         }
         
         foreach($root_child_list as $childs){
             if($childs->localName == WSF_BINDING && $childs->namespaceURI == WSF_WSDL2_NAMESPACE){
                 $binding_name_mod = strstr($binding_name, ":");
                 if($childs->attributes->getNamedItem(WSF_NAME)->value == substr($binding_name_mod, 1))
                     return $childs;
             }
         }
         
         return NULL;
    }
    else{
        $root_node = $wsdl_dom->firstChild;
        $root_child_list = $root_node->childNodes;
        
        
        foreach($root_child_list as $childs){
            if($childs->localName == WSF_SERVICE && $childs->namespaceURI == WSF_WSDL_NAMESPACE){
                $service_node = $childs;
                break;
            }
        }
        
        if(!$service_node){
             echo "service node not found";
             return;
        }
        
        $service_child_list = $service_node->childNodes;
        foreach($service_child_list as $service_childs){
            if($service_childs->localName == WSF_PORT && $service_childs->namespaceURI == WSF_WSDL_NAMESPACE){
                foreach($service_childs->childNodes as $port_child){
                    if($port_child->localName == WSF_ADDRESS && $port_child->attributes->getNamedItem(WSF_LOCATION)->value == $endpoint_address){
                        $binding_name = $port_child->parentNode->attributes->getNamedItem(WSF_BINDING)->value;
                        break;
                    }
                }
                
            }
            
        }
        
        if(!$binding_name){
            echo "binding_name not found";
             return;
        }
        
        foreach($root_child_list as $childs){
            if($childs->localName == WSF_BINDING && $childs->namespaceURI == WSF_WSDL_NAMESPACE){
                $binding_name_mod = strstr($binding_name, ":");
                if($childs->attributes->getNamedItem(WSF_NAME)->value == substr($binding_name_mod, 1))
                    return $childs;
            }
        }
        
         return NULL;
    }
}

/**
 * Returns the array of policies associated with the given operation and binding.
 * @param DomDocument $wsdl_dom WSDl2.0 DomDocument 
 * @param DomNode $binding_node 
 * @param string $operation_name Name of the operation
 * @param Bool $$is_wsdl_11 true is WSDL version 1.1, else false 
 * @return array of policies
 */
function wsf_get_all_policies(DomDocument $wsdl_dom, DomNode $binding_node, $operation_name, $is_wsdl_11 = FALSE)
{
    $policy_array = array();
    if(!$binding_node)
        return NULL;

    $binding_child_list = $binding_node->childNodes;
    foreach($binding_child_list as $binding_child){
        if($binding_child->localName == WSF_POLICY_REFERENCE){
            $binding_attr = $binding_child->attributes;
            $policy_uri =  $binding_attr->getNamedItem(WSF_URI)->value;
            $binding_policy = get_policy_node($wsdl_dom, $policy_uri);
            $policy_array["operation_policy"] = $binding_policy;
        }

        if($binding_child->localName == WSF_POLICY){
            $binding_policy_child = $binding_child->firstChild;
            $binding_attr = $binding_policy_child->attributes;
            $policy_uri =  $binding_attr->getNamedItem(WSF_URI)->value;
            $binding_policy = get_policy_node($wsdl_dom, $policy_uri);
            $policy_array["operation_policy"] = $binding_policy;
        }
        
        if($binding_child->localName == WSF_OPERATION && $is_wsdl_11 = FALSE){
            $operation_attr = $binding_child->attributes;
            $operation_ref = $operation_attr->getNamedItem(WSF_REF)->value;
            if(substr(strstr($operation_ref, ":"), 1) == $operation_name && $binding_child->hasChildNodes()){
                var_dump($binding_child->firstChild);
                foreach($binding_child->childNodes as $input_output){
                    if($input_output->firstChild->localName == WSF_POLICY_REFERENCE){  /* there may be several chidren */
                        $input_output_attr = $input_output->firstChild->attributes;
                        $msg_policy_uri =  $input_output_attr->getNamedItem(WSF_URI)->value;
                        $msg_policy = get_policy_node($wsdl_dom, $msg_policy_uri);
                        $key = $input_output->localName."_policy";
                        $policy_array[$key] = $msg_policy;
                    }
                }
            }
        }

        if($binding_child->localName == WSF_OPERATION && $is_wsdl_11 = TRUE){
            $operation_attr = $binding_child->attributes;
            $op_name = $operation_attr->getNamedItem(WSF_NAME)->value;
            if($op_name == $operation_name && $binding_child->hasChildNodes()){
                foreach($binding_child->childNodes as $input_output){
                    if($input_output->firstChild->localName == WSF_POLICY_REFERENCE){  /* there may be several children */
                        $input_output_attr = $input_output->firstChild->attributes;
                        $msg_policy_uri =  $input_output_attr->getNamedItem(WSF_URI)->value;
                        $msg_policy = get_policy_node($wsdl_dom, $msg_policy_uri);
                        $key = $input_output->localName."_policy";
                        $policy_array[$key] = $msg_policy;
                    }
                }
            }
        }
    }
    return $policy_array;
}
    
/**
 * Returns policy node corresponding to given policy URI.
 * @param DomDocument $wsdl_dom WSDL2.0 DomDocument 
 * @param string $policy_uri policy location defined in WSDL
 * @return string policy xml string 
 */

function get_policy_node(DomDocument $wsdl_dom, $policy_uri)
{
    $root_node = $wsdl_dom->firstChild;
    $root_child_list = $root_node->childNodes;
    foreach($root_child_list as $child){
        if($child->localName == WSF_POLICY){
            $policy_attr = $child->attributes;
            $policy_in_same_wsdl  = strpos($policy_uri, '#');
            if($policy_in_same_wsdl === 0){
                if($policy_attr->getNamedItemNS(WSF_POLICY_ID_NAMESPACE_URI, WSF_ID)->value == substr($policy_uri, 1)){
                    $policy_node = $child;
                    break;
                }
            } else {/* TODO- get policy from another WSDL */
                printf("Policy is not found in the given WSDL");
                return;
            }
        }
    }


    if($policy_node){
        $clone_policy_node = $policy_node->cloneNode(TRUE);
        return $wsdl_dom->saveXML($clone_policy_node);
    } else
        return NULL;
    
}


/**
 * Returns the binding details as SOAP action, WSA action, etc.
 * @param DomNode $operation_node
 * @return array binding-details array 
 */
function wsf_get_binding_details(DomNode $operation_node)
{
    $binding_array = array();
    $soap_version = 2;

    $operation_child_list = $operation_node->childNodes;
    foreach($operation_child_list as $operation_child){
        if($operation_child->localName == WSF_BINDINDG_DETAILS && $operation_child->hasAttributes()){
            $wsa_action = $operation_child->attributes->getNamedItem(WSF_WSAWAACTION)->value;
            $soap_action = $operation_child->attributes->getNamedItem(WSF_SOAPACTION)->value;
            if($wsa_action)
                $binding_array[WSF_WSA] = $wsa_action;
            if($soap_action)
                $binding_array[WSF_SOAP] = $soap_action;
        }
    }

    
    $operations_node = $operation_node->parentNode;
    if ($operations_node)
        $service_node = $operations_node->parentNode;
    if ($service_node){
        $soap_type = $service_node->attributes->getNamedItem(WSF_TYPE)->value;
        if($soap_type == WSF_SOAP11)
            $soap_version = 1;
        else if($soap_type == WSF_SOAP12)
            $soap_version = 2;
        else
            $soap_version = 2;
        $binding_array[WSF_SOAP_VERSION] = $soap_version;
    }
        
    
    return $binding_array;
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
 * Processes and validate response message and assign values to class map.
 * @param string $response_payload_string response envelope
 * @param string $response_sig_model_string response parameter string
 * @param array $response_parameters array of response parameters
 * @return mixed an object, an array or a simple type in line with the 
 * expected format of the response
 */
function wsf_process_response($response_payload_string, $response_sig_model_string, $response_parameters)
{
    $envelope_dom = new DomDocument(); 
    $sig_model_dom = new DomDocument();
    
    $has_return = FALSE;
    $is_wrapper = FALSE;

    $created_sig_array = array();

    $envelope_dom->preserveWhiteSpace = false;
    $sig_model_dom->preserveWhiteSpace = false;

    $envelope_dom->loadXML($response_payload_string);
    $sig_model_dom->loadXML($response_sig_model_string);
    
    
    /** get SOAP body DOM tree to compare with Sig model */
    $env_node = $envelope_dom->firstChild; 
    $env_child_list = $env_node->childNodes;
    foreach($env_child_list as $env_child){
        if (strtolower($env_child->localName) == WSF_BODY){
            $clone_body_node = $env_child->firstChild->cloneNode(TRUE);
            $response_node = $clone_body_node; 
        }
    }
    
    $returns_node = $sig_model_dom->firstChild; 
    if ($returns_node && $returns_node->tagName == WSF_RETURNS){
        if($returns_node->hasAttributes()){
            $ret_value_name = $returns_node->attributes->getNamedItem(WSF_WRAPPER_ELEMENT)->value;
            $ret_value_namespace = $returns_node->attributes->getNamedItem(WSF_WRAPPER_ELEMENT_NS)->value;
            $body_array = array();
            $body_array[WSF_NS] = $ret_value_namespace;
            $is_wrapper = TRUE;
        }
    }

    if(isset($response_parameters[WSF_CLASSMAP]))
        $class_map = $response_parameters[WSF_CLASSMAP];
   
    if ($class_map)
        $class = new ReflectionClass($class_map[$ret_value_name]);
     
        
    
    $param_child_list = $returns_node->childNodes;
    foreach($param_child_list as $param_child){
        if($param_child->tagName == WSF_PARAM && $param_child->hasAttributes()){
            /**TODO - complex types??? */

            if(!$param_child->hasChildNodes()){
                /* For simple types */
                $param_attribute_name = $param_child->attributes->getNamedItem(WSF_NAME)->value;
                $param_attribute_type = $param_child->attributes->getNamedItem(WSF_TYPE)->value;
                $param_attribute_type_ns = $param_child->attributes->getNamedItem(WSF_TYPE_NAMESPACE)->value;
                $param_attribute_target_ns = $param_child->attributes->getNamedItem(WSF_TARGETNAMESPACE)->value;
                /* TODO min occurs, max occrs and nillable should be handled */
                $body_child_array = array();
                $body_child_array[WSF_TYPE] = $param_attribute_type;
                $body_child_array[WSF_TYPE_NS] = $param_attribute_type_ns;
                $body_child_array[WSF_TNS] = $param_attribute_target_ns;
                $body_array[$param_attribute_name] = $body_child_array;
              
                if($class){
                    $property = $class->getProperty($param_attribute_name);
                    if (class_exists($class_map[$ret_value_name]))
                        $response_class = new $class_map[$ret_value_name];
                   
                }
            }
            
        }
    }

    if($is_wrapper == TRUE)
        $created_sig_array[$ret_value_name] = $body_array;
    else
        $created_sig_array = $body_array;
  
    if(!isset($created_sig_array[$response_node->localName])){
        echo "return operation not found";
        return;
    }
    
    if ($is_wrapper == FALSE && $response_node->firstChild->nodeType == XML_TEXT_NODE ){
        return $response_node->firstChild->wholeText;        
    }

    $response_child_list = $response_node->childNodes;
    if($response_child_list){
        foreach($response_child_list as $child){
            foreach($created_sig_array[$response_node->localName] as $key => $val){
                if($key == $child->localName){
                    if ($child->hasChildNodes() && $child->firstChild->nodeType != XML_TEXT_NODE){
                        // TODO - this is where recursive logic is needed after complex within 
                        // complex is supported
                        if($val[WSF_TYPE] == "anyType" && $child->firstChild->nodeType == XML_ELEMENT_NODE){
                            if($property && $response_class){
                                $property->setValue($response_class, $child->firstChild->tagName);
                                return $response_class;
                            }
                        }
                    }
                    else if($child->firstChild->nodeType == XML_TEXT_NODE) {
                        /* it is a simple type */
                        if($property && $response_class){
                            $property->setValue($response_class, $child->firstChild->wholeText); 
                            return $response_class;
                        }
                        else
                            return $child->firstChild->wholeText;
                    }
                }
            }
        }
    }
    else{
        if (count($created_sig_array[$response_node->tagName]) == 1){
            return; /* response has empty playload */
        }
    }
}

?>

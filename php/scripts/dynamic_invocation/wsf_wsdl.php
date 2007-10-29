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
    require_once('wsf_wsdl_consts.php');

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
   
    if (isset($user_parameters[WSF_CLASSMAP]))
        $class_map = $user_parameters[WSF_CLASSMAP];
    else
        $class_map = NULL;

    $xslt_location = $user_parameters[WSF_XSLT_LOCATION];

    $operation_name = $function_parameters[WSF_INVOKE_FUNCTION];
    $arg_count = $function_parameters[WSF_ARG_COUNT];
    $arguments = $function_parameters[WSF_ARG_ARRAY];

    $sig_model_dom->preserveWhiteSpace = false;
    $wsdl_dom->preserveWhiteSpace = false;
       
    if(!$wsdl_location)
        return "WSDL is not found";
    $is_multiple_interfaces = FALSE;

    // Load WSDL as DOM
    $wsdl_dom = new DOMDocument();
    if(!$wsdl_dom->load($wsdl_location))
        return "WSDL could not be loaded.";
   
    $wsdl_dom->preserveWhiteSpace = false;
/* changing code for processing mutiple port types in wsdl 1.1 */
    $is_multiple_interfaces = wsf_is_mutiple_port_types($wsdl_dom);

    if ($is_multiple_interfaces == FALSE){
        $wsdl_dom = wsf_get_wsdl_dom($wsdl_dom, $xslt_location);
        
        if(!$wsdl_dom)
            return "error creating WSDL Dom Document";
        
        $sig_model_dom = wsf_get_sig_model_dom($wsdl_dom, $xslt_location);
        $schema_node = wsf_get_schema_node($wsdl_dom); 

    }
    else {
        $wsdl_dom = wsf_get_wsdl_dom($wsdl_dom, $xslt_location);
//        $sig_model_dom = wsf_get_sig_model_dom($wsdl_dom, $xslt_location);/* this function is called inside wsf_process_multiple_interfaces .so no needed */
        $schema_node = wsf_get_schema_node($wsdl_11_dom, $wsdl_dom); 

        $sig_model_dom = wsf_process_multiple_interfaces($wsdl_dom, $sig_model_dom, $xslt_location);
    }

/*     if ($is_wsdl_11 == TRUE && $wsdl_11_dom ) */
/*         $schema_node = wsf_get_schema_node($wsdl_11_dom); */
    if ($is_wsdl_11 == FALSE && !$wsdl_11_dom )
         $schema_node = wsf_get_schema_node($wsdl_dom); 

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
    $operation = wsf_find_operation($sig_model_dom, $operation_name, $endpoint_address, $is_multiple_interfaces);

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
        $payload = wsf_create_payload($sig_method, $is_doc_lit, $operation_name, $arg_count, $arguments, $class_map, $schema_node);
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

function wsf_is_mutiple_port_types($wsdl_dom)
{
    if($wsdl_dom){
        $child_list = $wsdl_dom->childNodes;
        foreach($child_list as $child){
            if ($child->localName == WSF_DESCRIPTION)
                return FALSE;
            else if ($child->localName == WSF_DEFINITION){
                $wsdl_11_child_list = $child->childNodes;
                $i = 0;
                foreach($wsdl_11_child_list as $wsdl_11_child){
                    if ($wsdl_11_child->localName == 'portType')
                        $i++;
                }
                if($i > 1)
                    return TRUE;
                return FALSE; 
            }
        }
    }
}

function wsf_process_multiple_interfaces($wsdl_dom, $sig_model_dom, $xslt_location)
{

    $wsdl_2_0_child_list = $wsdl_dom->firstChild->childNodes;
    $interface_array = array();
    $i = 1 ;
  
    foreach($wsdl_2_0_child_list as $interface_child){
        if($interface_child->localName == 'interface'){
            $interface_array[$i] = $interface_child->attributes->getNamedItem('name')->value;
            $i++;    
        }
    }
    $sig_service_array = array();
    $no_of_interfaces = count($interface_array);
  

    $wsdl_dom2 = new DomDocument();
    $wsdl_dom2->preserveWhiteSpace = false;
    $wsdl_dom2->loadXML($wsdl_dom->saveXML());

    $wsdl_2_0_child_list2 = $wsdl_dom2->firstChild->childNodes;
    
  for($j = 1 ; $j <= $no_of_interfaces; $j++){
      $wsdl_2_0_child_list1 = $wsdl_dom2->firstChild->childNodes;
        foreach($wsdl_2_0_child_list1 as $service_child){
            if($service_child->localName == 'service'){
                $old_attr = $service_child->getAttribute('interface');
                $service_child->removeAttribute($old_attr);
                $service_child->setAttribute('interface', "tns:".$interface_array[$j]);
            }
        }
      
        $tmp_sig_model = wsf_get_sig_model_dom($wsdl_dom2, $xslt_location);
      
      
        $services_node = $tmp_sig_model->firstChild;
        $service_child_list = $services_node->childNodes;
        foreach($service_child_list as $service_child){
            if($service_child->localName == 'service' && $service_child->hasAttributes()){
                $service_endpoint = $service_child->attributes->getNamedItem('endpoint')->value;
                $operations_child_list = $service_child->childNodes;
                
                foreach($operations_child_list as $operations_child){
                    if($operations_child->localName == 'operations'){
                        $operations_name = $operations_child->attributes->getNamedItem('name')->value;
                        if(strstr($service_endpoint, $operations_name)){
                            $sig_service_array[strstr($service_endpoint, $operations_name)] = $service_child;
                        }
                    }
                }
            }
        }
    }
  $created_sig_dom = new DOMDocument('1.0', 'iso-8859-1');
  $element = $created_sig_dom->createElement('services');
  $created_sig_dom->appendChild($element);
  foreach($sig_service_array as $value){
      wsf_schema_appendNode($element, $value, $created_sig_dom);
  }
  
    return $created_sig_dom;
    
}

/**
 * Create WSDL DomDocument from given WSDL location.
 * If given WSDL is WSDL1.1 then it would be coverted to a WSDL2.0
 * @param string $wsdl_location 
 * @return DomDocument $wsdl_dom DomDocument of WSDL2.0 
 */
function wsf_get_wsdl_dom($wsdl_dom, $xslt_location)
{
    require_once('wsf_wsdl_consts.php');
   
    $xslt_wsdl_20_dom = new DOMDocument();
    $xslt_11_to_20_dom = new DOMDocument();
    $xslt_11_to_20_dom->preserveWhiteSpace = false;
    $xslt = new XSLTProcessor();
    global $wsdl_11_dom, $is_wsdl_11;
   
    if($wsdl_dom){
        $child_list = $wsdl_dom->childNodes;
        foreach($child_list as $child){
            if($child->localName == WSF_DEFINITION){ 
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
            else if ($child->localName == WSF_DESCRIPTION) {
            /* first element local name is description, so this is a 
               version 2.0 WSDL */
                return $wsdl_dom;
            }
            else{
                echo "Not a valid WSDL";
                return NULL;
            }
        }
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
    require_once('wsf_wsdl_consts.php');

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
    require_once('wsf_wsdl_consts.php');

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
function wsf_find_operation(DomDocument $sig_model_dom, $operation_name, $endpoint_address, $is_multiple)
{
    require_once('wsf_wsdl_consts.php');

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
 * Creates the payload to be passed to C level.
 * @param DomNode $signature_node 
 * @param Bool $is_doc true if doc-lit or false if rpc style
 * @param string $operation_name Name of the operation to be invoked
 * @param int $arg_count No of arguments in the function
 * @param array $argument array of arguments of the function to be invoked
 * @param array $class_map array of class mappings for complex types 
 * @param DomNode $schema_node schema for the given WSDL
 */
function wsf_create_payload(DomNode $signature_node, $is_doc, $operation_name, $arg_count, $arguments, array $class_map = NULL, $schema_node)
{
    require_once('wsf_wsdl_consts.php');
    

    $np1= "ns0";
    $np2= "ns";
    if(!$class_map){    
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
    else{
        $temp_param_struct = array();

        if(($is_doc == TRUE)  && $signature_node){;
            if($signature_node->firstChild->tagName == WSF_PARAMS){ /* TODO - what if it is not a wrapper element */
                if($signature_node->firstChild->hasAttributes()){
                    $params_attr = $signature_node->firstChild->attributes;
                    $ele_name = $params_attr->getNamedItem(WSF_WRAPPER_ELEMENT)->value;
                    /** this is wrapper element */
                    $child_array = array();
                    $ele_ns = $params_attr->getNamedItem(WSF_WRAPPER_ELEMENT_NS)->value;
                    $child_array[WSF_NS] = $ele_ns;
                        // }
                }
            }
        }
        if($signature_node->firstChild->hasChildNodes()){
            $param_child_list = $signature_node->firstChild->childNodes;
            foreach($param_child_list as $param_node){
                $is_xsd = FALSE;
                $wrap_type = $param_node->attributes->getNamedItem('simple')->value;
                $param_name = $param_node->attributes->getNamedItem(WSF_NAME)->value;
                $param_type = $param_node->attributes->getNamedItem(WSF_TYPE)->value;
                $is_xsd = is_xsd_type($param_type);
                if($wrap_type == "no" && $is_xsd == FALSE){// get from WSDL DOM
                    $rec_array = array();
                    $param_ns = $param_node->attributes->getNamedItem('targetNamespace')->value;
                    //    $param_type = $param_node->attributes->getNamedItem(WSF_TYPE)->value;
                    $child_array[$param_name] = create_recursive_struct($schema_node, $param_type, $param_ns);
                } 
                else{
                    $simple_array = array();
                    $param_ns = $param_node->attributes->getNamedItem('targetNamespace')->value;
                    /** min occurs max occurs */
                    $simple_array[WSF_TYPE] = $param_type;
                    $simple_array[WSF_NS] = $param_ns;
                    $child_array[$param_name]= $simple_array;
                }
            }
        }
        $temp_param_struct[$ele_name] = $child_array;
        $payload_dom = new DOMDocument('1.0', 'iso-8859-1');
        $element = $payload_dom->createElementNS($temp_param_struct[$ele_name][WSF_NS], "ns1:".$ele_name);
        
        $value_array = $temp_param_struct[$ele_name];
        if(is_object($arguments[0])){
            $new_obj = $arguments[0];
            recursive_payload($payload_dom, $value_array, $element, $new_obj);
        }
        
        $payload_dom->appendChild($element);
        $payload_node = $payload_dom->firstChild;
        $clone_node = $payload_node->cloneNode(TRUE);
        return $payload_dom->saveXML($clone_node);
    } 
}

/**
 * Recursive function to create payload 
 * @param DomDocument $payload_dom 
 * @param array $value_array Array that include payload details
 * @param DomNode $element 
 * @param mixed $new_obj call_map object
 */

function recursive_payload(DomDocument $payload_dom, $value_array, DomNode $element, $new_obj, $prev_obj = NULL)
{
    require_once('wsf_wsdl_consts.php');
    static $i = 2;
    foreach($value_array as $val => $value){
        if($val != WSF_NS && is_array($value)){
            // type of complex type
            if($value[WSF_NS]){
                if (isset($value[WSF_TYPE]) && $value[WSF_TYPE]){
                    if($new_obj->$val)
                        $obj_value = $new_obj->$val;
                    else
                        $obj_value = $prev_obj->$val;
                    $element_2 = $payload_dom->createElementNS($value[WSF_NS], "ns".$i.":".$val, $obj_value);
                }
                else{ 
                    $element_2 = $payload_dom->createElementNS($value['ns'], "ns".$i.":".$val);
                    $prev_obj = $new_obj;// this is a ugly hack
                    $new_obj = $new_obj->$val;
                    $i++;
                    recursive_payload($payload_dom, $value, $element_2, $new_obj, $prev_obj);
                }
            }
            else {
                $element_2 = $payload_dom->createElement($val, $new_obj->$val);
            }
            $element->appendChild($element_2);
        }
    }
}

/**
 * Recursive function to create temperaly structure
 * @param DomNode $types_node schema node of the WSDL
 * @param string $param_type Type of the parameter
 */

function create_recursive_struct(DomNode $types_node, $param_type, $prev_ns)
{
    require_once('wsf_wsdl_consts.php');
    
    $rec_array = array();
    $schema_list = $types_node->childNodes;
    foreach($schema_list as $schema){
        $ns = $schema->attributes->getNamedItem(WSF_TARGETNAMESPACE)->value;
        $complexType_list = $schema->childNodes;
        foreach($complexType_list as $complexType){
            if($complexType->localName == WSF_WSDL_COMPLEX_TYPE && $complexType->attributes->getNamedItem(WSF_NAME)->value == $param_type){
                $rec_array[WSF_NS] = $prev_ns;
                $prev_ns = $ns;
                $sequence_node = $complexType->firstChild;
                if($sequence_node->localName == "sequence" && $sequence_node->hasChildNodes()){// for now handling only sequence elements all? choice?
                    $element_list = $sequence_node->childNodes;
                    foreach($element_list as $element){
                        if($element->localName == "element" && $element->hasAttributes()){
                            $ele_type = $element->attributes->getNamedItem(WSF_TYPE)->value;
                            $ele_name = $element->attributes->getNamedItem(WSF_NAME)->value;
                            if(substr($ele_type, 0, 3) == "xs:" || substr($ele_type, 0, 4) == "xsd:"){
                                $simple_array = array();
                                $param_type = substr(strstr($ele_type, ':'), 1);
                                /** min occurs max occurs and nillable */
                                $simple_array[WSF_TYPE] = $param_type;
                                $simple_array[WSF_NS] = $ns;
                                $rec_array[$ele_name]= $simple_array;

                            }
                            else{
                                $rec_array[$ele_name] = create_recursive_struct($types_node, substr(strstr($ele_type, ':'),1), $prev_ns);
                            }
                        }
                    }
                }
                else if ($sequence_node->localName == "complexContent"){
                    $complexContent_node = $sequence_node->firstChild;// it is complex content
                    $complexContent_base_type = $complexContent_node->attributes->getNamedItem('base')->value;
                    $rec_array['complexContent'] = create_recursive_struct($types_node, substr(strstr($complexContent_base_type, ':'), 1), $prev_ns);
                    if($complexContent_node->firstChild->localName == "sequence" && $complexContent_node->firstChild->hasChildNodes()){
                        $element_list = $complexContent_node->firstChild->childNodes;
                        foreach($element_list as $element){
                            if($element->localName == "element" && $element->hasAttributes()){
                                $ele_type = $element->attributes->getNamedItem(WSF_TYPE)->value;
                                $ele_name = $element->attributes->getNamedItem(WSF_NAME)->value;
                                if(substr($ele_type, 0, 3) == "xs:" || substr($ele_type, 0, 4) == "xsd:"){
                                    $simple_array = array();
                                    $param_type = substr(strstr($ele_type, ':'), 1);
                                    /** min occurs max occurs and
                                     //nillable */
                                    $simple_array[WSF_TYPE] = $param_type;
                                    $simple_array[WSF_NS] = $ns;
                                    $rec_array[$ele_name]= $simple_array;

                                }
                                else{
                                    $rec_array[$ele_name] = create_recursive_struct($types_node, substr(strstr($ele_type, ':'),1), $prev_ns);
                                }
                            }
                        }
                    }
                                        
                }
                
            }
            else if ($complexType->localName == "simpleType" && $complexType->attributes->getNamedItem(WSF_NAME)->value == $param_type) {
                    $restriction_node = $complexType->firstChild;
                    if($restriction_node->localName == "restriction"){
                        $rec_array[WSF_TYPE] = $restriction_node->attributes->getNamedItem('base')->value;
                        $rec_array[WSF_NS] = $prev_ns;
                        $rec_array['simpleType'] = 1;
                    }
            }
        }
    }
    
    return $rec_array;
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
    require_once('wsf_wsdl_consts.php');

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
    require_once('wsf_wsdl_consts.php');

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
                    if($input_output->firstChild && $input_output->firstChild->localName == WSF_POLICY_REFERENCE){  /* there may be several children */
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
    require_once('wsf_wsdl_consts.php');

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
    require_once('wsf_wsdl_consts.php');

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
    require_once('wsf_wsdl_consts.php');

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
function wsf_process_response($response_payload_string, $response_sig_model_string, $response_parameters, $wsdldom_string)
{
    require_once('wsf_wsdl_consts.php');

    $envelope_dom = new DomDocument(); 
    $sig_model_dom = new DomDocument();
    $wsdl_dom = new DomDocument();
    
    $has_return = FALSE;
    $is_wrapper = FALSE;

    $created_sig_array = array();

    $envelope_dom->preserveWhiteSpace = false;
    $sig_model_dom->preserveWhiteSpace = false;
    $wsdl_dom->preserveWhiteSpace = false;

    $envelope_dom->loadXML($response_payload_string);
    $sig_model_dom->loadXML($response_sig_model_string);
    $wsdl_dom->loadXML($wsdldom_string);
    
    /** get SOAP body DOM tree to compare with Sig model */
    $env_node = $envelope_dom->firstChild; 
    $env_child_list = $env_node->childNodes;
    foreach($env_child_list as $env_child){
        if (strtolower($env_child->localName) == WSF_BODY){
            if(!$env_child->hasChildNodes())
                return;
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
                $param_attribute_simple = $param_child->attributes->getNamedItem(WSF_WSDL_SIMPLE)->value;

                if($param_attribute_simple == "no"){
                    $body_child_array = array();
                    $body_child_array[WSF_TYPE] = $param_attribute_type;
                    $body_child_array[WSF_TYPE_NS] = $param_attribute_type_ns;
                    $body_child_array[WSF_TNS] = $param_attribute_target_ns;

                    $schema_node = wsf_get_schema_node($wsdl_dom);
                    $recursive_array = create_recursive_response_struct($schema_node, $param_attribute_type);
                    $complex_array = array();
                    $complex_array[WSF_NS] = $param_attribute_target_ns;
                    $complex_array[$param_attribute_type] = $recursive_array;
                    $body_array[$param_attribute_name] = $complex_array;    
                }
                else{
                    $body_child_array = array();
                    $body_child_array[WSF_TYPE] = $param_attribute_type;
                    $body_child_array[WSF_TYPE_NS] = $param_attribute_type_ns;
                    $body_child_array[WSF_TNS] = $param_attribute_target_ns;
                    $body_array[$param_attribute_name] = $body_child_array;
                    
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
    if(isset($response_parameters[WSF_CLASSMAP]))
        $class_map = $response_parameters[WSF_CLASSMAP];
   
    $response_class = new $class_map[$response_node->localName];
    $ref_class = new ReflectionClass($response_class);
    if($response_child_list){
        foreach($response_child_list as $child){
            foreach($created_sig_array[$response_node->localName] as $key => $val){
                if($key == $child->localName){
                    $ret_val =   wsf_set_values($val, $class_map, $child, NULL);
                    if($ref_class)
                        $ref_property = $ref_class->getProperty($key);
                    if($ref_property)
                        $ref_property->setValue($response_class, $ret_val);
                }
            }
            
        }

        return $response_class;
    }
    else{
        if (count($created_sig_array[$response_node->tagName]) == 1){
            return; /* response has empty playload */
        }
    }
}

/**
 * Returns schema node 
 * @param DomDocument $wsdl_dom WSDL2.0 DomDocument
 * @return DomNode $schema_node Cloned schema node
 */
function wsf_get_schema_node(&$wsdl_dom, &$wsdl_dom2 = NULL)
{
    require_once('wsf_wsdl_consts.php');

    
    static $schema_node = NULL;
    
    if ($schema_node != NULL)
        return $schema_node; // Asume it is a single WSDL
   
    $root_node = $wsdl_dom->firstChild;
    $root_child_list = $root_node->childNodes;
    foreach($root_child_list as $childs){
        /* this is for inline schema */
        $tmp_node = $childs;
        $schema_node = $tmp_node->cloneNode(TRUE);
        /* end inline schema */
        
        if($childs->localName == WSF_TYPES){
            $schema_list = $childs->childNodes;
            // to find import schemas
            foreach($schema_list as $schema_child){
                $schema = array();
                $i = 0;
                $import_child_list = $schema_child->childNodes;
                foreach($import_child_list as $import_child){
                    if($import_child->localName == "import" && $import_child->attributes->getNamedItem('schemaLocation')){
                        $schema["schema".$i]= $import_child->attributes->getNamedItem('schemaLocation')->value;
                        $i++;
                    }
                }
            }

            if($schema){
                $schema_dom = new DomDocument();
                $schema_dom->preserveWhiteSpace = false;
                foreach($schema as $key => $val){
                    $schema_dom->load($val);
                    $import_schema_child_list = $schema_dom->childNodes;
                    foreach($import_schema_child_list as $import_schema_child){
                        if($import_schema_child->localName == 'schema'){
                            $tmp_import_schema_node = $import_schema_child;
                            $cloned_import_schema_node = $tmp_import_schema_node->cloneNode(TRUE);
                            wsf_schema_appendNode($schema_node, $tmp_import_schema_node, $wsdl_dom);
                        }
                    }
                }
            }
            $wsdl_2_0_child_list2 = $wsdl_dom->firstChild->childNodes;
            foreach($wsdl_2_0_child_list2 as $types_child){
                if($types_child->localName == 'types'){
                    $types_child_list = $types_child->childNodes;
                    foreach($types_child_list as $schema_child){
                        if($schema_child->localName == 'schema'){
                            $schema_child_list = $schema_child->childNodes;
                                for ($i = $schema_child_list->length; $i >= 0; $i--) {
                                    $import_child = $schema_child_list->item($i);
                                        if($import_child && $import_child->localName == 'import' && $import_child->attributes->getNamedItem('schemaLocation')){
                                            $schema_child->removeChild($import_child);
                                    }
                                }
                            }
                        }
                    }
                }
            
          if($wsdl_dom2){
                $wsdl_2_0_child_list = $wsdl_dom2->firstChild->childNodes;
                foreach($wsdl_2_0_child_list as $types_child){
                    if($types_child->localName == 'types'){
                        $types_child_list = $types_child->childNodes;
                        foreach($types_child_list as $schema_child){
                            if($schema_child->localName == 'schema'){
                                $types_child->removeChild($schema_child);
                                foreach($schema_node->childNodes as $schema3_child)
                                    wsf_schema_appendNode($types_child, $schema3_child, $wsdl_dom2);
                                
                            }
                        }

                    }
                }
          }

            if($wsdl_dom2){
                $wsdl_2_0_child_list = $wsdl_dom2->firstChild->childNodes;
                foreach($wsdl_2_0_child_list as $types_child){
                    if($types_child->localName == 'types'){
                        $types_child_list = $types_child->childNodes;
                        foreach($types_child_list as $schema_child){
                            if($schema_child->localName == 'schema'){
                                $schema_child_list = $schema_child->childNodes;
                                for ($i = $schema_child_list->length; $i >= 0; $i--) {
                                    //foreach($schema_child_list as $import_child){
                                    $import_child = $schema_child_list->item($i);
                                    if($import_child->localName == 'import' && $import_child->attributes->getNamedItem('schemaLocation')){
                                        $schema_child->removeChild($import_child);
                                        
                                }
                                }
                            }
                        }
                    }
                }
            }
            return $schema_node;
        }
    }

}


/**
 * Recursive function to create schema from import schema
 * @param DomNode $parent parent dom node 
 * @param DomNode $child dom node of import schema
 * @param DomDocument $doc DomDocument of parent DomNode
 */

function wsf_schema_appendNode( $parent, $child, $doc )
{
    if( $child == NULL)
    {
        return;
    }
    $newChild = NULL;
    if( $child-> nodeType == XML_TEXT_NODE )
    {
        $newChild = $doc-> createTextNode($child->nodeValue);
        //echo $newChild->nodeValue."\n";
    }
    else if( $child-> nodeType == XML_ELEMENT_NODE)
    {
        $childTag = $child->tagName;
        
        $newChild = $doc-> createElementNS($child->namespaceURI, $childTag);

        foreach( $child->attributes as $attribute)
            {
                $newChild->setAttribute($attribute->name, $attribute->value);
            }

        foreach ( $child->childNodes as $childsChild)
            {
                wsf_schema_appendNode( $newChild, $childsChild, $doc);
            }
    }
    if( $newChild != NULL)
    {
        $parent-> appendChild( $newChild);
    }
}



/**
 * Recursive function to create response temperary structure
 * @param DomNode $types_node schema node of the WSDL
 * @param string $param_type Type of the parameter
 */

function create_recursive_response_struct(DomNode $types_node, $param_type)
{
    
    require_once('wsf_wsdl_consts.php');
    $rec_array = array();
    $schema_list = $types_node->childNodes;
    foreach($schema_list as $schema){
        $ns = $schema->attributes->getNamedItem(WSF_TARGETNAMESPACE)->value;
        $complexType_list = $schema->childNodes;
        foreach($complexType_list as $complexType){
            if($complexType->localName == WSF_WSDL_COMPLEX_TYPE && $complexType->attributes->getNamedItem(WSF_NAME)->value == $param_type){
                $sequence_node = $complexType->firstChild;
                if($sequence_node->localName != "restriction"){
                    $rec_array['class'] = 1;
                    $rec_array[WSF_NS] = $ns;
                }
                $sequence_node = $complexType->firstChild;
                if($sequence_node->localName == "sequence" && $sequence_node->hasChildNodes()){// for now handling only sequence elements all? choice?
                    $element_list = $sequence_node->childNodes;
                    foreach($element_list as $element){
                        if($element->localName == "element" && $element->hasAttributes()){
                            $ele_type = $element->attributes->getNamedItem(WSF_TYPE)->value;
                            $ele_name = $element->attributes->getNamedItem(WSF_NAME)->value;
                            if(substr($ele_type, 0, 3) == "xs:" || substr($ele_type, 0, 4) == "xsd:"){
                                $simple_array = array();
                                $param_type = substr(strstr($ele_type, ':'), 1);
                                /** min occurs max occurs and nillable */
                                $simple_array[WSF_TYPE] = $param_type;
                                $simple_array[WSF_NS] = $ns;
                                $rec_array[$ele_name]= $simple_array;

                            }
                            else{
/*                                 to determine whether it is simple type */
                                $temp_arry = create_recursive_response_struct($types_node, substr(strstr($ele_type, ':'),1));
                                 if($temp_arry['simpleType'])
                                     $rec_array[$ele_name] = $temp_arry;
                                 else{
                                     $rec_array[substr(strstr($ele_type, ':'),1)] = $temp_arry;
                                 }
                            }
                        }
                    }
                }
                else if ($sequence_node->localName == "complexContent"){
                    $complexContent_node = $sequence_node->firstChild;
                    $complexContent_base_type = $complexContent_node->attributes->getNamedItem('base')->value;
                    $rec_array[substr(strstr($complexContent_base_type, ':'), 1)] = create_recursive_response_struct($types_node, substr(strstr($complexContent_base_type, ':'), 1));
                    //begin
                    if($complexContent_node->firstChild->localName == "sequence" && $complexContent_node->firstChild->hasChildNodes()){
                        $element_list = $complexContent_node->firstChild->childNodes;
                        foreach($element_list as $element){
                            if($element->localName == "element" && $element->hasAttributes()){
                                $ele_type = $element->attributes->getNamedItem(WSF_TYPE)->value;
                                $ele_name = $element->attributes->getNamedItem(WSF_NAME)->value;
                                if(substr($ele_type, 0, 3) == "xs:" || substr($ele_type, 0, 4) == "xsd:"){
                                    $simple_array = array();
                                    $param_type = substr(strstr($ele_type, ':'), 1);
                                    /** min occurs max occurs and
                                     //nillable */
                                    $simple_array[WSF_TYPE] = $param_type;
                                    $simple_array[WSF_NS] = $ns;
                                    $rec_array[$ele_name]= $simple_array;

                                }
                                else{
                                    $rec_array[$ele_name] = create_recursive_response_struct($types_node, substr(strstr($ele_type, ':'),1));
                                }
                            }
                        }
                    }
                    else {
                        /* TODO - restriction base */
                      }
                }
            }
            else if ($complexType->localName == "simpleType" && $complexType->attributes->getNamedItem(WSF_NAME)->value == $param_type) {
                $restriction_node = $complexType->firstChild;
                if($restriction_node->localName == "restriction"){
                    $rec_array[WSF_TYPE] = $restriction_node->attributes->getNamedItem('base')->value;
                    $rec_array[WSF_NS] = $ns;
                    $rec_array['simpleType'] = 1;
                }

                
            }
        }
    }
    return $rec_array;
}

function wsf_set_values($val, $class_map, &$child, $prev_class)
{
    $class1 = NULL;
    if(is_array($val) && !isset($val[WSF_TYPE])){
        foreach($val as $key2 => $val2){
            if(is_array($val2) && !isset($val2[WSF_TYPE])){
                $val1 = $val2;
                foreach($val1 as $key3 => $val3){
                    if($val3 == 1){
                        $class_name = $key2;
                        $class1 = new $class_map[$class_name];
                        $class_name = $class_map[$class_name];
                        if($prev_class){
                            $refle_class = new ReflectionClass($prev_class);
                            if($refle_class && $refle_class->hasProperty($child->localName))
                                $refle_property = $refle_class->getProperty($child->localName);
                            if($refle_property)
                                $refle_property->setValue($prev_class, $class1);
                        }
                        $child = $child->firstChild;
                        wsf_set_values($val2, $class_map, $child, $class1);
                        break;
                    }
                }
            }
            else{
                $var_name = NULL;
                if($key2 != WSF_NS && $key2 != 'class'){
                    $var_name = $key2;
                }
                if ($var_name != NULL){
                    if ($var_name == $child->localName){
                        $ref_class = new ReflectionClass($prev_class);
                        if($ref_class && $ref_class->hasProperty($var_name))
                            $property = $ref_class->getProperty($var_name);
                        if($property){
                            if($child->firstChild->nodeType == XML_TEXT_NODE){
                                $property->setValue($prev_class, $child->firstChild->wholeText);
                            }
                        }
                        if($child->nextSibling == NULL){
                            $child = $child->parentNode->nextSibling;
                        }
                        else
                            $child = $child->nextSibling;
                        
                    }else if($val2['simpleType'] == 1){
                        if($child->nextSibling == NULL){
                            $child = $child->parentNode->nextSibling;
                        }
                        else
                            $child = $child->nextSibling;
                    }
                    else{                        
/*                         echo "\n".$var_name."=>:".$child->localName."\n"; */
                    }
                }
            }
        }
    }
    if($class1)
        return $class1;
    else
        return NULL;
}

function is_xsd_type($param_type)
{
    
    $xsd_array = array("string", "boolean", "double", "boolean", "double", 
                          "float", "int", "integer", "byte", "decimal", 
                          "base64Binary", "hexBinary", "any", "QName", "dateTime", 
                          "date", "time", "unsignedLong", "unsignedInt", "unsignedShort",
                          "unsignedByte" , "positiveInteger", "negativeInteger", "nonNegativeInteger",
                          "nonPositiveInteger", "gYearMonth", "gMonthDay", "gYear", "gMonth", 
                          "gDay", "duration", "Name", "NCName", "NMTOKEN", "NOTATION", "NMTOKENS", "ENTITY",
                          "ENTITIES", "IDREF", "IDREFS", "anyURI", "language", "ID", "normalizedString", "token");

    return in_array($param_type, $xsd_array);
}



?>




















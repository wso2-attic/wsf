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
 * Processes and validate response message and assign values to class map.
 * @param string $response_payload_string response envelope
 * @param string $response_sig_model_string response parameter string
 * @param array $response_parameters array of response parameters
 * @return mixed an object, an array or a simple type in line with the 
 * expected format of the response
 */
function wsf_client_response_and_validate(DomDocument $envelope_dom, DomDocument $sig_model_dom, $response_parameters)
{
    require_once('wsf_wsdl_consts.php');

    $has_return = FALSE;
    $is_wrapper = FALSE;
    $tmp_param_struct = array();
    $class_map = NULL;
    
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
        $param_attr = $param_child->attributes;
        $param_name = $param_attr->getNamedItem(WSF_NAME)->value;
        $param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
        $body_array[$param_name] = wsf_create_response_struct($param_child);

    }
    
    
    if($is_wrapper == TRUE)
        $tmp_param_struct[$ret_value_name] = $body_array;
    else
        $tmp_param_struct = $body_array;
  
    if(!isset($tmp_param_struct[$response_node->localName])){
        echo "return operation not found";
        return;
    }
    
    if ($is_wrapper == FALSE && $response_node->firstChild->nodeType == XML_TEXT_NODE ){
        return $response_node->firstChild->wholeText;        
    }
    
    $response_child_list = $response_node->childNodes;
    if(isset($response_parameters[WSF_CLASSMAP]))
        $class_map = $response_parameters[WSF_CLASSMAP];

    if($class_map){
        $response_class = new $class_map[$response_node->localName];
        $ref_class = new ReflectionClass($response_class);
        if($response_child_list){
            foreach($response_child_list as $child){
                foreach($tmp_param_struct[$response_node->localName] as $key => $val){
                    if($key == $child->localName){
                        $ret_val = wsf_set_values_to_class_obj($val, $class_map, $child, NULL);
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
            if (count($tmp_param_struct[$response_node->tagName]) == 1){
                return; /* response has empty playload */
            }
        }
    }
    else{
        $return_array = array();
        if($response_child_list){
            foreach($response_child_list as $child){
                foreach($tmp_param_struct[$response_node->localName] as $key => $val){
                    if($key == $child->localName){
                        $return_array[$response_node->localName] = wsf_set_values_to_array($val, $child->firstChild);
                    }
                }
            }
            return $return_array;
        }
    }
}

function wsf_create_response_struct(DomNode $param_child)
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
        $is_xsd = is_xsd_type($param_type);
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
    
    return $rec_array;
    
}





/**
 * Recursive function to create response temperary structure
 * @param DomNode $types_node schema node of the WSDL
 * @param string $param_type Type of the parameter
 */


function wsf_set_values_to_class_obj($val, $class_map, &$child, $prev_user_obj)
{
    $user_level_obj = NULL;

    
    if(is_array($val) && !isset($val[WSF_TYPE])){
        foreach($val as $key2 => $val2){                    
            if(is_array($val2)){
                if(isset($val['class_map_name'])){
                    if($class_map[$val['class_map_name']]){
                        if(!$user_level_obj)
                            $user_level_obj = new $class_map[$val['class_map_name']];
                        
                        if($child->firstChild != NULL && $child->firstChild->nodeType == XML_ELEMENT_NODE)
                            $child = $child->firstChild;
                        $refle_class = new ReflectionClass($user_level_obj);

                        if(!isset($val2[WSF_TYPE])){
                            if($prev_user_obj){
                                if($refle_class && $refle_class->hasProperty($child->parentNode->localName))
                                    $refle_property = $refle_class->getProperty($child->parentNode->localName);

                                $result_obj = wsf_set_values_to_class_obj($val2, $class_map, $child, $prev_user_obj);
                                if($refle_property)
                                    $refle_property->setValue($prev_user_obj, $result_obj);
                                
                            }
                            else{
                                if($refle_class && $refle_class->hasProperty($child->localName))
                                    $refle_property = $refle_class->getProperty($child->localName);

                                $prev_user_obj = $user_level_obj;
                                $result_obj = wsf_set_values_to_class_obj($val2, $class_map, $child, $prev_user_obj);
                                if($refle_property)
                                    $refle_property->setValue($user_level_obj, $result_obj);
                                
                            }
                        }
                        else{
                           if($refle_class && $refle_class->hasProperty($child->localName))
                                $property = $refle_class->getProperty($child->localName);
                            if($property){
                                if($child->firstChild->nodeType == XML_TEXT_NODE){
                                    $property->setValue($user_level_obj, $child->firstChild->wholeText);
                                }
                            }
                            if($child->nextSibling != NULL)
                                $child = $child->nextSibling;
                            else{
                                $child = $child->parentNode->nextSibling;
                            }
                        }
                    }
                }
            }
            else if($key2 != WSF_NS && $key2 != 'class_map_name' && $key2 != 'nillable'){
                //echo "one here ".$key2."==>".$child->localName."\n";
            }
            
        }
    }
    else{
        
    }

    if($user_level_obj)
        return $user_level_obj;
    else
        return NULL;

}

function wsf_set_values_to_array($response_struct, $child)
{
    $data_array = array();
    if(is_array($response_struct) && !isset($response_struct[WSF_TYPE])){
        foreach($response_struct as $key => $value){
            if(is_array($value) && !isset($value[WSF_TYPE])){
                if($key == $child->localName)
                    $data_array [$key] = wsf_set_values_to_array($value, $child->firstChild);
                $child = $child->nextSibling;
            }
            else if(is_array($value) && isset($value[WSF_TYPE])){
                if ($key == $child->localName){
                    if($child->firstChild->nodeType == XML_TEXT_NODE){
                        $converted_value =  wsf_wsdl_util_convert_value($value[WSF_TYPE], $child->firstChild->wholeText);
                        $data_array [$key] = $converted_value;
                    }
                    else
                        $data_array [$key] = $child->firstChild;//any type may be an xml
                    $child = $child->nextSibling;
                }
            }
        }
    }
    return $data_array;

}



?>




















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
 * Recursive function to create payload 
 * @param DomDocument $payload_dom 
 * @param array $sig_data_struct $sig_model as an array
 *      example of parameter_struct..
 *
 *      Array
 *      (
 *          [has_childs] => 
 *          [ns] => http://wso2.org/dyn/codegen/demo
 *          [type_rep] => int //either one of type_rep or childs exists
 *          [minOccurs] => 
 *          [maxOccurs] => 
 *          [childs] => Array ()
 *      )
 *      or
 *     Array
 *     (
 *         [ns] => http://wso2.org/dyn/codegen/demo
 *         [has_childs] => 1
 *         [childs] => Array
 *             (
 *                 [demo1] => Array
 *                     (
 *                         [has_childs] => 
 *                         [ns] => http://wso2.org/dyn/codegen/demo
 *                         [type_rep] => int
 *                     )
 * 
 *                 [demo2] => Array
 *                     (
 *                         [has_childs] => 
 *                         [ns] => http://wso2.org/dyn/codegen/demo
 *                         [type_rep] => string
 *                     )
 * 
 *             )
 * 
 *      )
 *
 * @param DomNode $parent_ele - The parent node to add the content 
 * @param DomNode $root_ele - The top most of parent
 * @param mixed $class_obj - class object to pass
 * @param $namespace_map - Just make sure the unique namespace is used. Newly added
    (passed by reference)
 */


function wsf_create_payload_for_class_map(DomDocument $payload_dom,
                                            array $sig_data_struct, 
                                            DomNode $parent_ele, 
                                            DomNode $root_ele, 
                                            $class_obj, 
                                            array &$namespace_map = array()) {
    static $i = 2;


    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, print_r($sig_data_struct, TRUE));

    // This is not expected in the class map mode to have params with no childs
    // So mark it as an unknown schema
    if($sig_data_struct[WSF_HAS_SIG_CHILDS] !== TRUE) {
        // Just take the first namespace in the map to create the xml elements in 
        // the unknown structure..
        $values = array_values($namespace_map);
        $prefix = $values[0];
        wsf_create_payload_for_unknown_class_map($payload_dom, $parent_ele, $class_obj, $prefix);
        return;
    }

    $user_arguments = array();
    // filling user class information to the array..
    
    if(array_key_exists(WSF_SIG_CHILDS, $sig_data_struct) && is_array($sig_data_struct[WSF_SIG_CHILDS])) {
        foreach($sig_data_struct[WSF_SIG_CHILDS] as $param_key => $param_value) {
            if($class_obj->$param_key !== NULL) {
                $user_arguments[$param_key] = $class_obj->$param_key;
            }
        }
    }
    
    wsf_build_content_model($sig_data_struct, $user_arguments, $parent_ele, $payload_dom, $root_ele, $namespace_map);
}

/** create payload for arrays
 * @param $payload_dom - DomDocument for the payload building
 * @param $sig_data_struct - Map of parameters extracted from sig model
 *      example of parameter_struct..
 *
 *      Array
 *      (
 *          [has_childs] => 
 *          [ns] => http://wso2.org/dyn/codegen/demo
 *          [type_rep] => int //either one of type_rep or childs exists
 *          [minOccurs] => 
 *          [maxOccurs] => 
 *          [childs] => Array ()
 *      )
 *
 * @param $parent_ele - The parent node to add the content
 * @param $root_ele - The always parent. Just to add all the namespace declaration here..
 * @param $user_arguments - The user given arguments
 * @param $namespace_map - Just make sure the unique namespace is used. Newly added
    (passed by reference)
 */
function wsf_create_payload_for_array(DomDocument $payload_dom,
                                     array $sig_data_struct,
                                     DomNode $parent_ele,
                                     DomNode $root_ele,
                                     $user_arguments,
                                     array &$namespace_map = array()) {
    static $i = 2;

    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, print_r($sig_data_struct, TRUE));

    if($sig_data_struct[WSF_HAS_SIG_CHILDS] !== TRUE) {
        $values = array_values($namespace_map);
        $prefix = $values[0];
        if(is_array($user_arguments)) {
            wsf_create_payload_for_unknown_array($payload_dom, $parent_ele, $user_arguments, $prefix);
        }
    }


    wsf_build_content_model($sig_data_struct, $user_arguments, $parent_ele, $payload_dom,  $root_ele, $namespace_map);

    // this situation meets only for non-wrapped mode as doclit-bare wsdls
    if(array_key_exists(WSF_TYPE_REP, $sig_data_struct)) {
        $param_value = $sig_data_struct[WSF_TYPE_REP];
        if(is_xsd_type($param_value)) {
            /* TODO multiple values */
            if($user_arguments == NULL || !is_array($user_arguments)) {
                $serialized_value = wsf_wsdl_util_serialize_php_value($param_value, $user_arguments);
                $element_2 = $payload_dom->createTextNode($serialized_value);
                $parent_ele->appendChild($element_2);

            }
            else if(is_array($user_arguments)) {
                error_log("Array is specified when non-array is expected\n");
            }
        }
    }
}

/** create payload for unknown class maps 
 * @param $payload_dom - DomDocument for the payload building
 * @param $parent_ele - The parent node to add the content
 * @param $user_arguments - The user given argument array 
 * @param $class_obj - object with user data..
 * @param $ns_prefix
 */
function wsf_create_payload_for_unknown_class_map(DomDocument $payload_dom,
                                     DomNode $parent_ele,
                                     $class_obj,
                                     $ns_prefix) {
    $reflex_obj = new ReflectionObject($class_obj);
    $reflex_properties = $reflex_obj->getProperties();


    foreach($reflex_properties as $reflex_property) {
        $key = $reflex_property->getName();
        $value = $reflex_property->getValue($class_obj);

        if($ns_prefix != NULL && !empty($ns_prefix)) {
            $node_name = $ns_prefix.":".$key;
        }
        else
        {
            $node_name = $key;
        }
        if(is_object($value)) {
            $current_node = $payload_dom->createElement($node_name);
            wsf_create_payload_for_unknown_class_map($payload_dom, $current_node, $value, $ns_prefix);
            $parent_ele->appendChild($current_node);
        }
        else if(wsf_is_map($value)) {
            $current_node = $payload_dom->createElement($node_name);
            wsf_create_payload_for_unknown_array($payload_dom, $current_node, $value, $ns_prefix);
            $parent_ele->appendChild($current_node);
        }
        else if(is_array($value)) {
            foreach($value as $child_value) {
                if(is_object($child_value)) {
                    $current_node = $payload_dom->createElement($node_name);
                    wsf_create_payload_for_unknown_class_map($payload_dom, $current_node, $child_value, $ns_prefix);
                    $parent_ele->appendChild($current_node);
                }
                else if(wsf_is_map($child_value)) {
                    $current_node = $payload_dom->createElement($node_name);
                    wsf_create_payload_for_unknown_array($payload_dom, $current_node, $child_value, $ns_prefix);
                    $parent_ele->appendChild($current_node);
                }
                else if(is_array($child_value)) {
                    error_log("Invalid array (inside an array) supplied around ".print_r($child_value, TRUE)." \n");
                }
                else
                {
                    $current_node = $payload_dom->createElement($node_name, $child_value);
                    $parent_ele->appendChild($current_node);
                }
            }
        }
        else
        {
            $current_node = $payload_dom->createElement($node_name, $value);
            $parent_ele->appendChild($current_node);
        }
    }
}



/** create payload for arrays
 * @param $payload_dom - DomDocument for the payload building
 * @param $parent_ele - The parent node to add the content
 * @param $user_arguments - The user given argument array 
 * @param $ns_prefix
 */
function wsf_create_payload_for_unknown_array(DomDocument $payload_dom,
                                     DomNode $parent_ele,
                                     $user_arguments,
                                     $ns_prefix) {
    foreach($user_arguments as $key=> $value) {
        if($ns_prefix != NULL && !empty($ns_prefix)) {
            $node_name = $ns_prefix.":".$key;
        }
        else
        {
            $node_name = $key;
        }
        if(is_object($value)) {
            $current_node = $payload_dom->createElement($node_name);
            wsf_create_payload_for_unknown_class_map($payload_dom, $current_node, $value, $ns_prefix);
            $parent_ele->appendChild($current_node);
        }
        else if(wsf_is_map($value)) {
            $current_node = $payload_dom->createElement($node_name);
            wsf_create_payload_for_unknown_array($payload_dom, $current_node, $value, $ns_prefix);
            $parent_ele->appendChild($current_node);
        }
        else if(is_array($value)) {
            foreach($value as $child_value) {
                if(is_object($child_value)) {
                    $current_node = $payload_dom->createElement($node_name);
                    wsf_create_payload_for_unknown_class_map($payload_dom, $current_node, $child_value, $ns_prefix);
                    $parent_ele->appendChild($current_node);
                }
                else if(wsf_is_map($child_value)) {
                    $current_node = $payload_dom->createElement($node_name);
                    wsf_create_payload_for_unknown_array($payload_dom, $current_node, $child_value, $ns_prefix);
                    $parent_ele->appendChild($current_node);
                }
                else if(is_array($child_value)) {
                    error_log("Invalid array (inside an array) supplied around ".print_r($child_value, TRUE)." \n");
                }
                else
                {
                    $current_node = $payload_dom->createElement($node_name, $child_value);
                    $parent_ele->appendChild($current_node);
                }
            }
        }
        else
        {
            $current_node = $payload_dom->createElement($node_name, $value);
            $parent_ele->appendChild($current_node);
        }
    }
}

/** 
 * Do serialization over simple schema types
 * @param param_key string, the element name
 * @param param_value array, the schema information corrosponding to the key element
 *                     consists of following information for an example
 *                         [has_childs] => 
 *                         [ns] => http://wso2.org/dyn/codegen/demo
 *                         [type_rep] => int
 * @param $user_val the user value given to the type
 * @param $parant_ele just root element of the element
 * @param $payload_dom  payload dom document
 * @param $root_ele root element of the document, in order to add namespace 
 * @param namespace_map, array, map to the namespace to prefix
 */
function wsf_serialize_simple_types($param_key, $param_value, $user_val, $parent_ele, $payload_dom, $root_ele, &$namespace_map) {

   /* type conversion is needed */
   if(!array_key_exists(WSF_NS, $param_value) || empty($param_value[WSF_NS]) || $param_value[WSF_NS] == "NULL") {
       $param_value[WSF_NS] = NULL;
   }

   if(!isset($param_value[WSF_NS]) || $param_value[WSF_NS] == NULL) {
       $node_name = $param_key;
   }
   else{
       if(array_key_exists($param_value[WSF_NS], $namespace_map) && $namespace_map[$param_value[WSF_NS]] != NULL) {
           $prefix = $namespace_map[$param_value[WSF_NS]];
       }
       else{
           $prefix = "ns".$i;
           $i ++;
           $root_ele->setAttribute("xmlns:".$prefix, $param_value[WSF_NS]);
           $namespace_map[$param_value[WSF_NS]] = $prefix;
       }
       $node_name = $prefix.":".$param_key;
   }

   if(array_key_exists("maxOccurs", $param_value) && ($param_value["maxOccurs"] == "unbounded" || $param_value["maxOccurs"] > 1) && is_array($user_val)) {
       foreach($user_val as $user_val_item) {
           $serialized_value = wsf_wsdl_util_serialize_php_value($param_value[WSF_TYPE_REP], $user_val_item);
           $element_2 = $payload_dom->createElement($node_name, $serialized_value);
           $parent_ele->appendChild($element_2);
       }
   }
   else if(!is_array($user_val)) {
       /* in a case this is not an array */
       $serialized_value = wsf_wsdl_util_serialize_php_value($param_value[WSF_TYPE_REP], $user_val);
       $element_2 = $payload_dom->createElement($node_name, $serialized_value);
       $parent_ele->appendChild($element_2);
   }
   else{
       error_log("Array is given for ". $param_key ." which should be a non array. \n");
   }
}

/** 
 * Do serialization over complex schema types
 * @param param_key string, the element name
 * @param param_value array, the schema information corrosponding to the key element
 *                     consists of following information for an example
 *                        [ns] => http://wso2.org/dyn/codegen/demo
 *                        [has_childs] => 1
 *                        [childs] => Array
 *                            (
 *                                [demo1] => Array
 *                                    (
 *                                        [has_childs] => 
 *                                        [ns] => http://wso2.org/dyn/codegen/demo
 *                                        [type_rep] => int
 *                                    )
 *                   
 *                                [demo2] => Array
 *                                    (
 *                                        [has_childs] => 
 *                                        [ns] => http://wso2.org/dyn/codegen/demo
 *                                        [type_rep] => string
 *                                    )
 *                   
 *                            )
 * @param $user_val the user value given to the type
 * @param $parant_ele just root element of the element
 * @param $payload_dom  payload dom document
 * @param $root_ele root element of the document, in order to add namespace 
 * @param namespace_map, array, map to the namespace to prefix
 */
function wsf_serialize_complex_types($param_key, $param_value, $user_val, $parent_ele, $payload_dom, $root_ele, &$namespace_map) {

   if(!array_key_exists(WSF_NS, $param_value) || empty($param_value[WSF_NS]) || $param_value[WSF_NS] == "NULL") {
       $param_value[WSF_NS] = NULL;
   }

   if($param_value[WSF_NS] == NULL) {
       $node_name = $param_key;
   }
   else {
       if(array_key_exists(WSF_NS, $param_value) && array_key_exists($param_value[WSF_NS], $namespace_map) && 
               $namespace_map[$param_value[WSF_NS]] != NULL) {
           $prefix = $namespace_map[$param_value[WSF_NS]];
       }
       else{
           $prefix = "ns".$i;
           $i ++;
           $root_ele->setAttribute("xmlns:".$prefix, $param_value[WSF_NS]);
           $namespace_map[$param_value[WSF_NS]] = $prefix;
       }
       $node_name = $prefix.":".$param_key;
   }

   if(array_key_exists("maxOccurs", $param_value) && ($param_value["maxOccurs"] == "unbounded" || $param_value["maxOccurs"] > 1) && is_array($user_val)) {
       foreach($user_val as $user_val_item) {
           $element_2 = $payload_dom->createElement($node_name);
           if(is_object($user_val_item)) {
               if($param_value[WSF_HAS_SIG_CHILDS] === TRUE && array_key_exists(WSF_SIG_CHILDS, $param_value)) {
                   wsf_create_payload_for_class_map($payload_dom, $param_value[WSF_SIG_CHILDS], $element_2, $root_ele, $user_val_item, $namespace_map);
               }
               else
               {
                   wsf_create_payload_for_unknown_class_map($payload_dom, $element_2, $user_val_item, $prefix);
               }
           }
           else
           {
               if($param_value[WSF_HAS_SIG_CHILDS] === TRUE && array_key_exists(WSF_SIG_CHILDS, $param_value)) {
                   wsf_create_payload_for_array($payload_dom, $param_value[WSF_SIG_CHILDS], $element_2, $root_ele, $user_val_item, $namespace_map);
               }
               else
               {
                   wsf_create_payload_for_unknown_array($payload_dom, $element_2, $user_val_item, $prefix);
               }
           }
           $parent_ele->appendChild($element_2);
       }
   }
   else{
       /* in a case this is not an array */
       $element_2 = $payload_dom->createElement($node_name);
       if(is_object($user_val)) {
           if($param_value[WSF_HAS_SIG_CHILDS] === TRUE && array_key_exists(WSF_SIG_CHILDS, $param_value)) {
               wsf_create_payload_for_class_map($payload_dom, $param_value[WSF_SIG_CHILDS], $element_2, $root_ele, $user_val, $namespace_map);
           }
           else
           {
               wsf_create_payload_for_unknown_class_map($payload_dom, $element_2, $user_val, $prefix);
           }
       }
       else
       {
           if($param_value[WSF_HAS_SIG_CHILDS] === TRUE && array_key_exists(WSF_SIG_CHILDS, $param_value)) {
               wsf_create_payload_for_array($payload_dom, $param_value[WSF_SIG_CHILDS], $element_2, $root_ele, $user_val, $namespace_map);
           }
           else
           {
               wsf_create_payload_for_unknown_array($payload_dom, $element_2, $user_val, $prefix);
           }
       }
       $parent_ele->appendChild($element_2);
   }
}

/**
 * build the content model correctly
 * @param $sig_data_struct sig data struct
 * @param $user_arguments, user arguments as an array
 * @param $parent_ele the immediate parent element
 * @param $payload_dom the dom document of the building xml
 * @param $root_ele the root element of the dom
 */
function wsf_build_content_model(array $sig_data_struct, $user_arguments, $parent_ele, $payload_dom, $root_ele, $namespace_map) {

    $content_model = $sig_data_struct[WSF_CONTENT_MODEL];
    $just_found_once = FALSE;

    if(array_key_exists(WSF_SIG_CHILDS, $sig_data_struct) && is_array($sig_data_struct[WSF_SIG_CHILDS])) {
        foreach($sig_data_struct[WSF_SIG_CHILDS] as $param_key => $param_value) {
           // the childs should be set as an array
            if(is_array($param_value)) {
                // users are not expected to provide it in exact sequence..
                foreach($user_arguments as $arg_key => $user_val) {
                    if($param_key == $arg_key) {
                        if (isset($param_value[WSF_TYPE_REP]) && $param_value[WSF_TYPE_REP]) {
                            wsf_serialize_simple_types($param_key, $param_value, $user_val, $parent_ele, $payload_dom, $root_ele, $namespace_map);
                        }
                        else {
                            wsf_serialize_complex_types($param_key, $param_value, $user_val, $parent_ele, $payload_dom, $root_ele, $namespace_map);
                        }
                        if($user_val !== NULL) {
                            $just_found_once = TRUE;
                        }
                        break;
                    }
                }
                if($just_found_once && $content_model == "choice"){
                    break;
                }
            }
        }
    }
}



//-------------------------------------------------------------------------------------------
//currently we don't have diffent serialization for rpc-style in contrast with doc-lit

?>

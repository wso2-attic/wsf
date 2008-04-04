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
 * @param array $parameter_struct $sig_model as an array
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
 *  )
 *
 * @param DomNode $parent_ele - The parent node to add the content 
 * @param DomNode $root_ele - The top most of parent
 * @param mixed $class_obj - class object to pass
 * @param $namespace_map - Just make sure the unique namespace is used. Newly added
    (passed by reference)
 */


function wsf_create_payload_for_class_map(DomDocument $payload_dom,
                                            array $parameter_struct, 
                                            DomNode $parent_ele, 
                                            DomNode $root_ele, 
                                            $class_obj, 
                                            array &$namespace_map = array()) {
    static $i = 2;

    // This is not expected in the class map mode to have params with no childs
    // So mark it as an unknown schema
    if($parameter_struct[WSF_HAS_SIG_CHILDS] !== TRUE) {
        // Just take the first namespace in the map to create the xml elements in 
        // the unknown structure..
        $values = array_values($namespace_map);
        $prefix = $values[0];
        wsf_create_payload_for_unknown_class_map($payload_dom, $parent_ele, $class_obj, $prefix);
        return;
    }

    if(array_key_exists(WSF_SIG_CHILDS, $parameter_struct) && is_array($parameter_struct[WSF_SIG_CHILDS])) {
        foreach($parameter_struct[WSF_SIG_CHILDS] as $key => $value) {
            // the childs should be set as an array
            if(is_array($value)) {
                // no worries if the mapped class name is anyType
                if(array_key_exists(WSF_CLASS_MAP_NAME, $value) && $value[WSF_CLASS_MAP_NAME] == "anyType") {
                      $values = array_values($namespace_map);
                      $prefix = $values[0];
                      wsf_create_payload_for_unknown_class_map($payload_dom, $parent_ele, $class_obj, $prefix);
                      continue;
                }
                if (isset($value[WSF_TYPE_REP]) && $value[WSF_TYPE_REP]) {
                    if($class_obj->$key !== NULL) {
                        $arg_val = $class_obj->$key;
                        /* type conversion is needed */
                        if(!array_key_exists(WSF_NS, $value) || empty($value[WSF_NS]) || $value[WSF_NS] == "NULL") {
                            $value[WSF_NS] = NULL;
                        }

                        if(!isset($value[WSF_NS]) || $value[WSF_NS] == NULL) {
                            $node_name = $key;
                        }
                        else{
                            if(array_key_exists($value[WSF_NS], $namespace_map) && $namespace_map[$value[WSF_NS]] != NULL) {
                                $prefix = $namespace_map[$value[WSF_NS]];
                            }
                            else{
                                $prefix = "ns".$i;
                                $i ++;
                                $root_ele->setAttribute("xmlns:".$prefix, $value[WSF_NS]);
                                $namespace_map[$value[WSF_NS]] = $prefix;
                            }
                            $node_name = $prefix.":".$key;
                        }

                        if(array_key_exists("maxOccurs", $value) && ($value["maxOccurs"] == "unbounded" || $value["maxOccurs"] > 1) && is_array($arg_val)) {
                            foreach($arg_val as $arg_val_item) {
                                $serialized_value = wsf_wsdl_util_serialize_php_value($value[WSF_TYPE_REP], $arg_val_item);
                                $element_2 = $payload_dom->createElement($node_name, $serialized_value);
                                $parent_ele->appendChild($element_2);
                            }
                        }
                        else if(!is_array($arg_val)) {
                            /* in a case this is not an array */
                            $serialized_value = wsf_wsdl_util_serialize_php_value($value[WSF_TYPE_REP], $arg_val);
                            $element_2 = $payload_dom->createElement($node_name, $serialized_value);
                            $parent_ele->appendChild($element_2);
                        }
                        else{
                            error_log("Array is given for ". $key ." which should be a non array. \n");
                        }
                    }
                }
                else {
                    if($class_obj->$key) {
                        $arg_val = $class_obj->$key;
                        /* type conversion is needed */
                        if(!array_key_exists(WSF_NS, $value) || empty($value[WSF_NS]) || $value[WSF_NS] == "NULL") {
                            $value[WSF_NS] = NULL;
                        }

                        if($value[WSF_NS] == NULL) {
                            $node_name = $key;
                        }
                        else{
                            if(array_key_exists(WSF_NS, $value) && array_key_exists($value[WSF_NS], $namespace_map) && 
                                    $namespace_map[$value[WSF_NS]] != NULL) {
                                $prefix = $namespace_map[$value[WSF_NS]];
                            }
                            else{
                                $prefix = "ns".$i;
                                $i ++;
                                $root_ele->setAttribute("xmlns:".$prefix, $value[WSF_NS]);
                                $namespace_map[$value[WSF_NS]] = $prefix;
                            }
                            $node_name = $prefix.":".$key;
                        }

                        if(array_key_exists("maxOccurs", $value) && ($value["maxOccurs"] == "unbounded" || $value["maxOccurs"] > 1) && is_array($arg_val)) {
                            foreach($arg_val as $arg_val_item) {
                                $element_2 = $payload_dom->createElement($node_name);
                                if(is_object($arg_val_item)) {
                                    if($value[WSF_HAS_SIG_CHILDS] === TRUE) {
                                        wsf_create_payload_for_class_map($payload_dom, $value, $element_2, $root_ele, $arg_val_item, $namespace_map);
                                    }
                                    else
                                    {
                                        wsf_create_payload_for_unknown_class_map($payload_dom, $element_2, $arg_val_item, $prefix);
                                    }
                                }
                                else
                                {
                                    if($value[WSF_HAS_SIG_CHILDS] === TRUE) {
                                        wsf_create_payload_for_array($payload_dom, $value, $element_2, $root_ele, $arg_val_item, $namespace_map);
                                    }
                                    else
                                    {
                                        wsf_create_payload_for_unknown_array($payload_dom, $element_2, $arg_val_item, $prefix);
                                    }
                                }
                                $parent_ele->appendChild($element_2);
                            }
                        }
                        else{
                            /* in a case this is not an array */
                            $element_2 = $payload_dom->createElement($node_name);
                            if(is_object($arg_val)) {
                                if($value[WSF_HAS_SIG_CHILDS] === TRUE) {
                                    wsf_create_payload_for_class_map($payload_dom, $value, $element_2, $root_ele, $arg_val, $namespace_map);
                                }
                                else
                                {
                                    wsf_create_payload_for_unknown_class_map($payload_dom, $element_2, $arg_val, $prefix);
                                }
                            }
                            else
                            {
                                if($value[WSF_HAS_SIG_CHILDS] === TRUE) {
                                    wsf_create_payload_for_array($payload_dom, $value, $element_2, $root_ele, $arg_val, $namespace_map);
                                }
                                else
                                {
                                    wsf_create_payload_for_unknown_array($payload_dom, $element_2, $arg_val, $prefix);
                                }
                            }
                            $parent_ele->appendChild($element_2);
                        }
                    }
                }
            }
        }
    }
}

/** create payload for arrays
 * @param $payload_dom - DomDocument for the payload building
 * @param $parameter_struct - Map of parameters extracted from sig model
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
                                     array $parameter_struct,
                                     DomNode $parent_ele,
                                     DomNode $root_ele,
                                     $user_arguments,
                                     array &$namespace_map = array()) {
    static $i = 2;

    $unknown_schema_found = FALSE;

    if($parameter_struct[WSF_HAS_SIG_CHILDS] !== TRUE) {
        $values = array_values($namespace_map);
        $prefix = $values[0];
        if(is_array($user_arguments)) {
            wsf_create_payload_for_unknown_array($payload_dom, $parent_ele, $user_arguments, $prefix);
        }
        $unknown_schema_found = TRUE;
    }


    if(array_key_exists(WSF_SIG_CHILDS, $parameter_struct) && is_array($parameter_struct[WSF_SIG_CHILDS])) {
        foreach($parameter_struct[WSF_SIG_CHILDS] as $key => $value) {
            // the childs should be set as an array
            if(is_array($value)) {
                if($unknown_schema_found) {
                    continue;
                }
                if(isset($value[WSF_CLASS_MAP_NAME]) && ($value[WSF_CLASS_MAP_NAME] == "anyType")) {
                      $values = array_values($namespace_map);
                      $prefix = $values[0];
                      if(is_array($user_arguments)) {
                          wsf_create_payload_for_unknown_array($payload_dom, $parent_ele, $user_arguments, $prefix);
                      }
                      continue;
                }
                if (isset($value[WSF_TYPE_REP]) && $value[WSF_TYPE_REP]) {
                    foreach($user_arguments as $arg_key => $arg_val) {
                        if($key == $arg_key) {
                            /* type conversion is needed */
                            if($value[WSF_NS] == "NULL") {
                                $value[WSF_NS] = NULL;
                            }

                            if($value[WSF_NS] == NULL) {
                                $node_name = $key;
                            }
                            else{
                                if($namespace_map[$value[WSF_NS]] != NULL) {
                                    $prefix = $namespace_map[$value[WSF_NS]];
                                }
                                else{
                                    $prefix = "ns".$i;
                                    $i ++;
                                    $root_ele->setAttribute("xmlns:".$prefix, $value[WSF_NS]);
                                    $namespace_map[$value[WSF_NS]] = $prefix;
                                }
                                $node_name = $prefix.":".$key;
                            }

                            if(array_key_exists("maxOccurs", $value) && ($value["maxOccurs"] == "unbounded" || $value["maxOccurs"] > 1) && is_array($arg_val)) {
                                foreach($arg_val as $arg_val_item) {
                                    $serialized_value = wsf_wsdl_util_serialize_php_value($value[WSF_TYPE_REP], $arg_val_item);
                                    $element_2 = $payload_dom->createElement($node_name, $serialized_value);
                                    $parent_ele->appendChild($element_2);
                                }
                            }
                            else if(!is_array($arg_val)) {
                                /* in a case this is not an array */
                                $serialized_value = wsf_wsdl_util_serialize_php_value($value[WSF_TYPE_REP], $arg_val);
                                $element_2 = $payload_dom->createElement($node_name, $serialized_value);
                                $parent_ele->appendChild($element_2);
                            }
                            else{
                                error_log("Array is given for ". $key ." which should be a non array. \n");
                            }
                        }
                    }
                }
                else {
                    foreach($user_arguments as $arg_key => $arg_val) {
                        if($key == $arg_key) {
                            /* type conversion is needed */
                            if($value[WSF_NS] == "NULL") {
                                $value[WSF_NS] = NULL;
                            }

                            if($value[WSF_NS] == NULL) {
                                $node_name = $key;
                            }
                            else{
                                if($namespace_map[$value[WSF_NS]] != NULL) {
                                    $prefix = $namespace_map[$value[WSF_NS]];
                                }
                                else{
                                    $prefix = "ns".$i;
                                    $i ++;
                                    $root_ele->setAttribute("xmlns:".$prefix, $value[WSF_NS]);
                                    $namespace_map[$value[WSF_NS]] = $prefix;
                                }
                                $node_name = $prefix.":".$key;
                            }

                            if(array_key_exists("maxOccurs", $value) && ($value["maxOccurs"] == "unbounded" || $value["maxOccurs"] > 1) && is_array($arg_val)) {
                                foreach($arg_val as $arg_val_item) {
                                    $element_2 = $payload_dom->createElement($node_name);
                                    if(is_object($arg_val_item)) {
                                        if($value[WSF_HAS_SIG_CHILDS] === TRUE) {
                                            wsf_create_payload_for_class_map($payload_dom, $value, $element_2, $root_ele, $arg_val_item, $namespace_map);
                                        }
                                        else
                                        {
                                            wsf_create_payload_for_unknown_class_map($payload_dom, $element_2, $arg_val_item, $prefix);
                                        }
                                    }
                                    else
                                    {
                                        if($value[WSF_HAS_SIG_CHILDS] === TRUE) {
                                            wsf_create_payload_for_array($payload_dom, $value, $element_2, $root_ele, $arg_val_item, $namespace_map);
                                        }
                                        else
                                        {
                                            wsf_create_payload_for_unknown_array($payload_dom, $element_2, $arg_val_item, $prefix);
                                        }
                                    }
                                    $parent_ele->appendChild($element_2);
                                }
                            }
                            else{
                                /* in a case this is not an array */
                                #$element_2 = $payload_dom->createElementNS($value[WSF_NS], $node_name);
                                $element_2 = $payload_dom->createElement($node_name);
                                if(is_object($arg_val)) {
                                    if($value[WSF_HAS_SIG_CHILDS] === TRUE) {
                                        wsf_create_payload_for_class_map($payload_dom, $value, $element_2, $root_ele, $arg_val, $namespace_map);
                                    }
                                    else
                                    {
                                        wsf_create_payload_for_unknown_class_map($payload_dom, $element_2, $arg_val, $prefix);
                                    }
                                }
                                else
                                {
                                    if($value[WSF_HAS_SIG_CHILDS] === TRUE) {
                                        wsf_create_payload_for_array($payload_dom, $value, $element_2, $root_ele, $arg_val, $namespace_map);
                                    }
                                    else
                                    {
                                        wsf_create_payload_for_unknown_array($payload_dom, $element_2, $arg_val, $prefix);
                                    }
                                }
                                $parent_ele->appendChild($element_2);
                            }
                        }
                    }
                }
            }
        }
    }

    // this situation meets only for non-wrapped mode as doclit-bare wsdls
    if(array_key_exists(WSF_TYPE_REP, $parameter_struct)) {
        $value = $parameter_struct[WSF_TYPE_REP];
        if(is_xsd_type($value)) {
            /* TODO multiple values */
            if($user_arguments == NULL || !is_array($user_arguments)) {
                $serialized_value = wsf_wsdl_util_serialize_php_value($value, $user_arguments);
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


//-------------------------------------------------------------------------------------------
//currently we don't have diffent serialization for rpc-style in contrast with doc-lit

/**
 * Recursive function to create payload 
 * @param DomDocument $payload_dom 
 * @param array $parameter_struct $sig_model as an array
 * @param DomNode $parent_ele - The parent node to add the content 
 * @param DomNode $root_ele - The top most of parent
 * @param mixed $class_obj - class object to pass
 * @param $namespace_map - Just make sure the unique namespace is used. Newly added
    (passed by reference)
 */


function wsf_create_rpc_payload_for_class_map(DomDocument $payload_dom,
                                            array $parameter_struct, 
                                            DomNode $parent_ele, 
                                            DomNode $root_ele, 
                                            $class_obj, 
                                            array &$namespace_map = array()) {
    static $i = 2;

    foreach($parameter_struct as $key => $value) {
        if(is_array($value)) {
            if($value[WSF_CLASS_MAP_NAME] == "anyType") {
                  $values = array_values($namespace_map);
                  $prefix = $values[0];
                  {
                        wsf_create_payload_for_unknown_class_map($payload_dom, $parent_ele, $class_obj, $prefix);
                  }
                  continue;
            }
                if (isset($value[WSF_TYPE_REP]) && $value[WSF_TYPE_REP]) {
                    if($class_obj->$key !== NULL) {
                        $arg_val = $class_obj->$key;
                        /* type conversion is needed */
                        if($value[WSF_NS] == "NULL") {
                            $value[WSF_NS] = NULL;
                        }

                        if($value[WSF_NS] == NULL) {
                            $node_name = $key;
                        }
                        else{
                            if($namespace_map[$value[WSF_NS]] != NULL) {
                                $prefix = $namespace_map[$value[WSF_NS]];
                            }
                            else{
                                $prefix = "ns".$i;
                                $i ++;
                                $root_ele->setAttribute("xmlns:".$prefix, $value[WSF_NS]);
                                $namespace_map[$value[WSF_NS]] = $prefix;
                            }
                            $node_name = $prefix.":".$key;
                        }

                        if(array_key_exists("maxOccurs", $value) && ($value["maxOccurs"] == "unbounded" || $value["maxOccurs"] > 1) && is_array($arg_val)) {
                            foreach($arg_val as $arg_val_item) {
                                $element_2 = $payload_dom->createElement($node_name, $arg_val_item);
                                $element_2->setAttribute("xsi:type", "xsd:".$value[WSF_TYPE_REP]);
                                $parent_ele->appendChild($element_2);
                            }
                        }
                        else{
                            /* in a case this is not an array */
                            $element_2 = $payload_dom->createElement($node_name, $arg_val);
                            $element_2->setAttribute("xsi:type", "xsd:".$value[WSF_TYPE_REP]);
                            $parent_ele->appendChild($element_2);
                        }
                    }
                }
                else {
                    if($class_obj->$key) {
                        $arg_val = $class_obj->$key;
                        /* type conversion is needed */
                        if($value[WSF_NS] == "NULL") {
                            $value[WSF_NS] = NULL;
                        }

                        if($value[WSF_NS] == NULL) {
                            $node_name = $key;
                        }
                        else{
                            if($namespace_map[$value[WSF_NS]] != NULL) {
                                $prefix = $namespace_map[$value[WSF_NS]];
                            }
                            else{
                                $prefix = "ns".$i;
                                $i ++;
                                $root_ele->setAttribute("xmlns:".$prefix, $value[WSF_NS]);
                                $namespace_map[$value[WSF_NS]] = $prefix;
                            }
                            $node_name = $prefix.":".$key;
                        }

                        if(array_key_exists("maxOccurs", $value) && ($value["maxOccurs"] == "unbounded" || $value["maxOccurs"] > 1) && is_array($arg_val)) {
                            foreach($arg_val as $arg_val_item) {
                                $element_2 = $payload_dom->createElement($node_name);
                                if(is_object($arg_val_item)) {
                                    wsf_create_rpc_payload_for_class_map($payload_dom, $value, $element_2, $root_ele, $arg_val_item, $namespace_map);
                                }
                                else
                                {
                                    wsf_create_rpc_payload_for_array($payload_dom, $value, $element_2, $root_ele, $arg_val_item, $namespace_map);
                                }
                                $parent_ele->appendChild($element_2);
                            }
                        }
                        else{
                            /* in a case this is not an array */
                            $element_2 = $payload_dom->createElement($node_name);
                            if(is_object($arg_val)) {
                                wsf_create_rpc_payload_for_class_map($payload_dom, $value, $element_2, $root_ele, $arg_val, $namespace_map);
                            }
                            else
                            {
                                wsf_create_rpc_payload_for_array($payload_dom, $value, $element_2, $root_ele, $arg_val, $namespace_map);
                            }
                            $parent_ele->appendChild($element_2);
                        }
                    }
                }
        }else if($key == WSF_TYPE_REP && is_xsd_type($value)) {
            /* TODO multiple values */
            if(!$user_arguments[0])
                $element_2 = $payload_dom->createTextNode(0);
            else
                $element_2 = $payload_dom->createTextNode($user_arguments[0]);
            $root_ele->appendChild($element_2);
        }
    }
}

/** create payload for arrays
 * @param $payload_dom - DomDocument for the payload building
 * @param $parameter_struct - Map of parameters extracted from sig model
 * @param $parent_ele - The parent node to add the content
 * @param $root_ele - The always parent. Just to add all the namespace declaration here..
 * @param $user_arguments - The user given argument array 
 * @param $namespace_map - Just make sure the unique namespace is used. Newly added
    (passed by reference)
 */
function wsf_create_rpc_payload_for_array(DomDocument $payload_dom,
                                     array $parameter_struct,
                                     DomNode $parent_ele,
                                     DomNode $root_ele,
                                     array $user_arguments,
                                     array &$namespace_map = array()) {
    static $i = 2;

    foreach($parameter_struct as $key => $value) {
        if(is_array($value)) {
            if($value[WSF_CLASS_MAP_NAME] == "anyType") {
                  $values = array_values($namespace_map);
                  $prefix = $values[0];
                  if(is_array($user_arguments)) {
                      wsf_create_payload_for_unknown_array($payload_dom, $parent_ele, $user_arguments, $prefix);
                  }
                  continue;
            }
            if (isset($value[WSF_TYPE_REP]) && $value[WSF_TYPE_REP]) {
                foreach($user_arguments as $arg_key => $arg_val) {
                    if($key == $arg_key) {
                        /* type conversion is needed */
                        if($value[WSF_NS] == "NULL") {
                            $value[WSF_NS] = NULL;
                        }

                        if($value[WSF_NS] == NULL) {
                            $node_name = $key;
                        }
                        else{
                            if($namespace_map[$value[WSF_NS]] != NULL) {
                                $prefix = $namespace_map[$value[WSF_NS]];
                            }
                            else{
                                $prefix = "ns".$i;
                                $i ++;
                                $root_ele->setAttribute("xmlns:".$prefix, $value[WSF_NS]);
                                $namespace_map[$value[WSF_NS]] = $prefix;
                            }
                            $node_name = $prefix.":".$key;
                        }

                        if(array_key_exists("maxOccurs", $value) && ($value["maxOccurs"] == "unbounded" || $value["maxOccurs"] > 1) && is_array($arg_val)) {
                            foreach($arg_val as $arg_val_item) {
                                $element_2 = $payload_dom->createElement($node_name, $arg_val_item);
                                $element_2->setAttribute("xsi:type", "xsd:".$value[WSF_TYPE_REP]);
                                $parent_ele->appendChild($element_2);
                            }
                        }
                        else{
                            /* in a case this is not an array */
                            $element_2 = $payload_dom->createElement($node_name, $arg_val);
                            $element_2->setAttribute("xsi:type", "xsd:".$value[WSF_TYPE_REP]);
                            $parent_ele->appendChild($element_2);
                        }
                    }
                }
            }
            else {
                foreach($user_arguments as $arg_key => $arg_val) {
                    if($key == $arg_key) {
                        /* type conversion is needed */
                        if($value[WSF_NS] == "NULL") {
                            $value[WSF_NS] = NULL;
                        }

                        if($value[WSF_NS] == NULL) {
                            $node_name = $key;
                        }
                        else{
                            if($namespace_map[$value[WSF_NS]] != NULL) {
                                $prefix = $namespace_map[$value[WSF_NS]];
                            }
                            else{
                                $prefix = "ns".$i;
                                $i ++;
                                $root_ele->setAttribute("xmlns:".$prefix, $value[WSF_NS]);
                                $namespace_map[$value[WSF_NS]] = $prefix;
                            }
                            $node_name = $prefix.":".$key;
                        }

                        if(array_key_exists("maxOccurs", $value) && ($value["maxOccurs"] == "unbounded" || $value["maxOccurs"] > 1) && is_array($arg_val)) {
                            foreach($arg_val as $arg_val_item) {
                                $element_2 = $payload_dom->createElement($node_name);
                                if(is_object($arg_val_item)) {
                                    wsf_create_rpc_payload_for_array($payload_dom, $value, $element_2, $root_ele, $arg_val_item, $namespace_map);
                                }
                                else
                                {
                                    wsf_create_rpc_payload_for_class_map($payload_dom, $value, $element_2, $root_ele, $arg_val_item, $namespace_map);
                                }
                                $parent_ele->appendChild($element_2);
                            }
                        }
                        else{
                            /* in a case this is not an array */
                            #$element_2 = $payload_dom->createElementNS($value[WSF_NS], $node_name);
                            $element_2 = $payload_dom->createElement($node_name);
                            wsf_create_rpc_payload_for_array($payload_dom, $value, $element_2, $root_ele, $arg_val, $namespace_map);
                            $parent_ele->appendChild($element_2);
                        }
                    }
                }
            }
        }else if($key == WSF_TYPE_REP && is_xsd_type($value)) {
            /* TODO multiple values */
            if(!$user_arguments[0])
                $element_2 = $payload_dom->createTextNode(0);
            else
                $element_2 = $payload_dom->createTextNode($user_arguments[0]);
            $root_ele->appendChild($element_2);
        }
    }
}
?>

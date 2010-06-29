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
 * Recursive function to create payload 
 * @param DomDocument $payload_dom 
 * @param array $sig_model as a DomNode
 *      example of sig..
 *
 *      <params wrapper-element="myDemo"
 *             wrapper-element-ns="http://wso2.org/dyn/codegen/demo"
 *             simple="no" contentModel="all">
 *          <param token="#in"
 *               targetNamespace="http://wso2.org/dyn/codegen/demo"
 *               minOccurs="1" maxOccurs="1" name="demo1" type="int"
 *               type-namespace="http://www.w3.org/2001/XMLSchema" 
 *               type-prefix="xs" simple="yes"/>
 *          <param token="#in" 
 *               targetNamespace="http://wso2.org/dyn/codegen/demo"
 *               minOccurs="1" maxOccurs="1" name="demo2" type="string"
 *               type-namespace="http://www.w3.org/2001/XMLSchema" 
 *               type-prx="xs" simple="yes"/>
 *      </params>
 *
 *
 * @param DomNode $parent_node - The parent node to add the content 
 * @param DomNode $root_node - The top most of parent
 * @param mixed $user_obj - class object to pass
 * @param array $classmap, the classmap user entered
 * @param $prefix_i - next available prefix index 
 * @param $namespace_map - Just make sure the unique namespace is used.
    Newly added (passed by reference)
 */
function wsf_create_payload_for_class_map(DomDocument $payload_dom,
                                            DomNode $sig_node, 
                                            DomNode $parent_node, 
                                            DomNode $root_node, 
                                            $user_obj,
                                            $classmap,
                                            &$prefix_i, 
                                            array &$namespace_map,
                                            $mtom_on,
                                            &$attachment_map) {

    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "Loading in to creating payload from classmap");

    if(wsf_set_nil_element($user_obj, $parent_node, $root_node, $prefix_i, $namespace_map)) {
        return TRUE;
    }

    // This is not expected in the class map mode to have params with no childs
    // So mark it as an unknown schema

    // here we always expect structures with childs unless it is simple content model
    if(!($sig_node->attributes->getNamedItem(WSF_CONTENT_MODEL) &&
                $sig_node->attributes->getNamedItem(WSF_CONTENT_MODEL)->value == WSF_SIMPLE_CONTENT) && 
                !$sig_node->hasChildNodes()) {
        
        // Just take the first namespace in the map to create the xml elements in 
        // the unknown structure..
        $values = array_values($namespace_map);
        $prefix = $values[0];
        wsf_create_payload_for_unknown_class_map($payload_dom, $parent_node, $user_obj, $prefix);
        return;
    }


    if($sig_node->hasAttributes()) {
        // filling user class information to the array..

        $changed_sig_node = wsf_infer_sig_node_from_user_obj($sig_node, $parent_node, $root_node,
                    $user_obj, $classmap, $prefix_i, $namespace_map);

        $user_arguments = wsf_convert_classobj_to_array($changed_sig_node, $user_obj);

        wsf_build_content_model($changed_sig_node, $user_arguments, $parent_node, $payload_dom,
                $root_node, $classmap, $prefix_i, $namespace_map, $mtom_on, $attachment_map);
    }
    else {
        // this situation meets only for non-wrapped mode as doclit-bare wsdls
        // and for the simpleContent extension in the classmap
        $the_only_node = $sig_node->firstChild;


        //  handle simple content extension seperatly
        if($the_only_node->attributes->getNamedItem(WSF_CONTENT_MODEL) &&
                $the_only_node->attributes->getNamedItem(WSF_CONTENT_MODEL)->value == WSF_SIMPLE_CONTENT) {

            // filling user class information to the array..
            $user_arguments = wsf_convert_classobj_to_array($the_only_node, $user_obj);

            wsf_build_content_model($the_only_node, $user_arguments, $parent_node,
                $payload_dom, $root_node, $classmap, $prefix_i, $namespace_map, $mtom_on, $attachement_map);
        }
    }
}


/** create payload for arrays
 * @param $payload_dom - DomDocument for the payload building
 * @param $sig_node - sig model
 * @param $parent_node - The parent node to add the content
 * @param $root_node - The always parent. Just to add all the namespace declaration here..
 * @param $user_arguments - The user given arguments
 * @param $prefix_i - next available prefix index 
 * @param $namespace_map - Just make sure the unique namespace is used. Newly added
    (passed by reference)
 */
function wsf_create_payload_for_array(DomDocument $payload_dom,
                                     DOMNode $sig_node,
                                     DomNode $parent_node,
                                     DomNode $root_node,
                                     $user_arguments,
                                     &$prefix_i, 
                                     array &$namespace_map,
                                     $mtom_on,
                                     &$attachement_map) {

    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "Loading in to creating payload from arrays");

    if(wsf_set_nil_element($user_arguments, $parent_node, $root_node, $prefix_i, $namespace_map)) {
        return TRUE;
    }

    // here we always expect structures with childs
    if(!$sig_node->hasChildNodes()) {
        
        // Just take the first namespace in the map to create the xml elements in 
        // the unknown structure..
        $values = array_values($namespace_map);
        $prefix = $values[0];
        wsf_create_payload_for_unknown_class_map($payload_dom, $parent_node, $user_obj, $prefix);
        return;
    }


    $classmap = NULL;
    if($sig_node->hasAttributes()) {
        if(!is_array($user_arguments)) {
            ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, $payload_dom->localName. 
                " can not be empty, note: just set to NULL to make it as NULL");
            wsf_set_nil_element(NULL, $parent_node, $root_node, $prefix_i, $namespace_map);
            return;
        }
        wsf_build_content_model($sig_node, $user_arguments, $parent_node,
            $payload_dom,  $root_node, $classmap, $prefix_i, $namespace_map, $mtom_on, $attachement_map);
    }
    else {
        // this situation meets only for non-wrapped mode as doclit-bare wsdls
        $the_only_node = $sig_node->firstChild;

        //  handle simple content extension seperatly
        if($the_only_node->attributes->getNamedItem(WSF_CONTENT_MODEL) &&
                $the_only_node->attributes->getNamedItem(WSF_CONTENT_MODEL)->value == WSF_SIMPLE_CONTENT) {
            wsf_build_content_model($the_only_node, $user_arguments, $parent_node,
                    $payload_dom, $root_node, $classmap, $prefix_i, $namespace_map, $mtom_on, $attachement_map);
        }
        else {
            $is_simple = FALSE;
            if($the_only_node->attributes->getNamedItem(WSF_WSDL_SIMPLE) &&
                    $the_only_node->attributes->getNamedItem(WSF_WSDL_SIMPLE)->value == "yes") {
                $is_simple = TRUE;
            }
            $param_type = NULL;
            if($the_only_node->attributes->getNamedItem(WSF_TYPE)) {
                $param_type = $the_only_node->attributes->getNamedItem(WSF_TYPE)->value;
            }
            if($is_simple) {

                $is_list = FALSE;
                if($the_only_node->attributes->getNamedItem(WSF_LIST) &&
                    $the_only_node->attributes->getNamedItem(WSF_LIST)->value == "yes") {
                     $is_list = TRUE;
                }

                if($user_arguments === NULL || !is_array($user_arguments) || $is_list) {

                    $serialized_value = wsf_wsdl_serialize_php_value($param_type,
                        $user_arguments, $the_only_node, $parent_node, 
                        $parent_node, $prefix_i, $namespace_map, $root_node);
                    $text_node = $payload_dom->createTextNode($serialized_value);
                    $parent_node->appendChild($text_node);

                }
                else if(is_array($user_arguments)) {
                    ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, "Array is specified when non-array is expected for the root node\n");
                }
                wsf_set_nil_element($user_arguments, $parent_node, $root_node, $prefix_i, $namespace_map);
            }
        }
    }
}

/** create payload for unknown class maps 
 * @param $payload_dom - DomDocument for the payload building
 * @param $parent_node - The parent node to add the content
 * @param $user_arguments - The user given argument array 
 * @param $user_obj - object with user data..
 * @param $ns_prefix
 */
function wsf_create_payload_for_unknown_class_map(DomDocument $payload_dom,
                                     DomNode $parent_node,
                                     $user_obj,
                                     $ns_prefix) {

    $reflex_obj = new ReflectionObject($user_obj);
    $reflex_properties = $reflex_obj->getProperties();


    foreach($reflex_properties as $reflex_property) {
        $key = $reflex_property->getName();
        $value = $reflex_property->getValue($user_obj);

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
            $parent_node->appendChild($current_node);
        }
        else if(wsf_is_map($value)) {
            $current_node = $payload_dom->createElement($node_name);
            wsf_create_payload_for_unknown_array($payload_dom, $current_node, $value, $ns_prefix);
            $parent_node->appendChild($current_node);
        }
        else if(is_array($value)) {
            foreach($value as $child_value) {
                if(is_object($child_value)) {
                    $current_node = $payload_dom->createElement($node_name);
                    wsf_create_payload_for_unknown_class_map($payload_dom, $current_node, $child_value, $ns_prefix);
                    $parent_node->appendChild($current_node);
                }
                else if(wsf_is_map($child_value)) {
                    $current_node = $payload_dom->createElement($node_name);
                    wsf_create_payload_for_unknown_array($payload_dom, $current_node, $child_value, $ns_prefix);
                    $parent_node->appendChild($current_node);
                }
                else if(is_array($child_value)) {
                    error_log("Invalid array (inside an array) supplied around ".print_r($child_value, TRUE)." \n");
                }
                else
                {
                    $current_node = $payload_dom->createElement($node_name, $child_value);
                    $parent_node->appendChild($current_node);
                }
            }
        }
        else
        {
            $current_node = $payload_dom->createElement($node_name, $value);
            $parent_node->appendChild($current_node);
        }
    }
}



/** create payload for arrays
 * @param $payload_dom - DomDocument for the payload building
 * @param $parent_node - The parent node to add the content
 * @param $user_arguments - The user given argument array 
 * @param $ns_prefix
 */
function wsf_create_payload_for_unknown_array(DomDocument $payload_dom,
                                     DomNode $parent_node,
                                     $user_arguments,
                                     $ns_prefix) {
    if(is_array($user_arguments)) {
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
                $parent_node->appendChild($current_node);
            }
            else if(wsf_is_map($value)) {
                $current_node = $payload_dom->createElement($node_name);
                wsf_create_payload_for_unknown_array($payload_dom, $current_node, $value, $ns_prefix);
                $parent_node->appendChild($current_node);
            }
            else if(is_array($value)) {
                foreach($value as $child_value) {
                    if(is_object($child_value)) {
                        $current_node = $payload_dom->createElement($node_name);
                        wsf_create_payload_for_unknown_class_map($payload_dom, $current_node, $child_value, $ns_prefix);
                        $parent_node->appendChild($current_node);
                    }
                    else if(wsf_is_map($child_value)) {
                        $current_node = $payload_dom->createElement($node_name);
                        wsf_create_payload_for_unknown_array($payload_dom, $current_node, $child_value, $ns_prefix);
                        $parent_node->appendChild($current_node);
                    }
                    else if(is_array($child_value)) {
                        error_log("Invalid array (inside an array) supplied around ".print_r($child_value, TRUE)." \n");
                    }
                    else
                    {
                        $current_node = $payload_dom->createElement($node_name, $child_value);
                        $parent_node->appendChild($current_node);
                    }
                }
            }
            else
            {
                $current_node = $payload_dom->createElement($node_name, $value);
                $parent_node->appendChild($current_node);
            }
        }
    }
    else {
        // just return the current value;
        $ele = $payload_dom->createTextNode($user_arguments);
        $parent_node->appendChild($ele);
    }
}

/** 
 * Do serialization over simple schema types, attributes are too handled here
 * @param $sig_param_node sig model for the param
 * @param $user_val the user value given to the type
 * @param $parant_ele just root element of the element
 * @param $payload_dom  payload dom document
 * @param $root_node root element of the document, in order to add namespace 
 * @param $classmap array of classemap
 * @param $prefix_i - next available prefix index 
 * @param $namespace_map, array, map to the namespace to prefix
 * @param $user_val_encoded, encoded value of the user val, hm! use only for base64
 */
function wsf_serialize_simple_types(DomNode $sig_param_node, $user_val,
                    $parent_node, $payload_dom, $root_node, $classmap, &$prefix_i,
                    &$namespace_map, $mtom_on, &$attachment_map, $user_val_encoded = NULL, $content_type = NULL) {

    $target_namespace = NULL;
    $min_occurs = 1;
    $max_occurs = 1;
    $sig_param_attris = $sig_param_node->attributes;
    $param_type = NULL;
    $param_name = NULL;
    $is_attribute = FALSE;
    $is_list = FALSE;
    $content_model = NULL;
    $nillable = FALSE;


    if($sig_param_attris->getNamedItem(WSF_NAME)) {
        $param_name = 
            $sig_param_attris->getNamedItem(WSF_NAME)->value;
    }

    if($sig_param_attris->getNamedItem(WSF_TARGETNAMESPACE)) {
         $target_namespace = 
            $sig_param_attris->getNamedItem(WSF_TARGETNAMESPACE)->value;
    }

    if($sig_param_attris->getNamedItem(WSF_MIN_OCCURS)) {
         $min_occurs = 
            $sig_param_attris->getNamedItem(WSF_MIN_OCCURS)->value;
    }

    if($sig_param_attris->getNamedItem(WSF_MAX_OCCURS)) {
         $max_occurs = 
            $sig_param_attris->getNamedItem(WSF_MAX_OCCURS)->value;
    }

    if($sig_param_attris->getNamedItem(WSF_XSD_NILLABLE)) {
         $nillable = 
            $sig_param_attris->getNamedItem(WSF_XSD_NILLABLE)->value;
    }
    
    if($sig_param_attris->getNamedItem(WSF_TYPE)) {
         $param_type = 
            $sig_param_attris->getNamedItem(WSF_TYPE)->value;
    }
    else if($sig_param_attris->getNamedItem(WSF_EXTENSION)) {
         $param_type = 
            $sig_param_attris->getNamedItem(WSF_EXTENSION)->value;
    }

    if($sig_param_attris->getNamedItem(WSF_ATTRIBUTE) &&
        $sig_param_attris->getNamedItem(WSF_ATTRIBUTE)->value == "yes") {
         $is_attribute = TRUE;
    }
 
    if($sig_param_attris->getNamedItem(WSF_CONTENT_MODEL)) {
        $content_model = $sig_param_attris->getNamedItem(WSF_CONTENT_MODEL)->value;
    }


    if($sig_param_attris->getNamedItem(WSF_LIST) &&
        $sig_param_attris->getNamedItem(WSF_LIST)->value == "yes") {
         $is_list = TRUE;
    }
    
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, $param_name);

    if($target_namespace === NULL) {
        $qualified_name = $param_name;
    }
    else {
        if(array_key_exists($target_namespace, $namespace_map)
                     && $namespace_map[$target_namespace] != NULL) {
            $prefix = $namespace_map[$target_namespace];
        }
        else{
            $prefix = "ns".$prefix_i;
            $prefix_i ++;
            $root_node->setAttribute("xmlns:".$prefix, $target_namespace);
            $namespace_map[$target_namespace] = $prefix;
        }
        $qualified_name = $prefix.":".$param_name;
    }

    if($is_attribute) {
        $attri_name = $qualified_name;
       
        if(!is_array($user_val) && !is_object($user_val) ||
            ($user_val_encoded && !is_array($user_val_encoded) && !is_object($user_val_encoded))) {
    
            $serialized_value = wsf_wsdl_serialize_php_value(
                                $param_type, $user_val, $sig_param_node,
                                NULL, $prefix_i, $namespace_map, $root_node);

            $parent_node->setAttribute($attri_name, $serialized_value);
        }
        else {
            ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR,
                        "attribute found -  ".
                        $param_name ." which have given an array.");
        }
    }
    else {
        $node_name = $qualified_name;

        if($max_occurs > 1 || $max_occurs == "unbounded") {
            if($user_val && is_array($user_val)) {
                foreach($user_val as $user_val_item) {
                    if($content_model == WSF_SIMPLE_CONTENT) {
                        $ele = $payload_dom->createElement($node_name);
                        $parent_node->appendChild($ele);
                        if(is_object($user_val_item)) {
                            wsf_create_payload_for_class_map($payload_dom, $sig_param_node,
                                $ele, $root_node, $user_val_item, $classmap,
                                $prefix_i, $namespace_map, $mtom_on, $attachment_map);
                        }
                        else {
                            wsf_create_payload_for_array($payload_dom, $sig_param_node,
                                $ele, $root_node, $user_val_item, $prefix_i, $namespace_map, $mtom_on, $attachment_map);
                        }
                    }
                    else {
                        /* type conversion is needed */
                        
                        $ele = $payload_dom->createElement($node_name);
                        $parent_node->appendChild($ele);
                        wsf_serialize_type_info($param_type, $user_val_item,
                                    $sig_param_node, $payload_dom, $root_node,
                                    $ele, $namespace_map, $mtom_on, $attachment_map, NULL, $content_type);
                    }
                }
            }
            else if($user_val_encoded && is_array($user_val_encoded)) {
                foreach($user_val_encoded as $user_val_encoded_item) {
                    if($content_model == WSF_SIMPLE_CONTENT) {
                        // this is never to happen
                    }
                    else {
                        /* type conversion is needed */
                        $ele = $payload_dom->createElement($node_name);
                        $parent_node->appendChild($ele);
                        wsf_serialize_type_info($param_type, NULL,
                                    $sig_param_node, $payload_dom, $root_node, 
                                    $ele, $namespace_map, $mtom_on, $attachment_map, $user_val_encoded_item, $content_type);
                    }
                }
            }
            else if($user_val || $user_val_encoded) {
                if($content_model == WSF_SIMPLE_CONTENT) {
                    //this never happen if $user_val exists
                    $ele = $payload_dom->createElement($node_name);
                    $parent_node->appendChild($ele);
                    if(is_object($user_val)) {
                        wsf_create_payload_for_class_map($payload_dom, $sig_param_node,
                            $ele, $root_node, $user_val, $classmap,
                            $prefix_i, $namespace_map, $mtom_on, $attachment_map);
                    }
                    else {
                        wsf_create_payload_for_array($payload_dom, $sig_param_node,
                            $ele, $root_node, $user_val, $prefix_i, $namespace_map, $mtom_on, $attachment_map);
                    }
                }
                else {
                    /* in a case this is not an array */
                    $ele = $payload_dom->createElement($node_name);
                    $parent_node->appendChild($ele);
                    wsf_serialize_type_info($param_type, $user_val, $sig_param_node, $payload_dom, $root_node,
                                $ele, $namespace_map, $mtom_on, $attachment_map, $user_val_encoded, $content_type);
                }
            }
        }
        else {
            if(!($user_val && is_array($user_val)) ||
                    !($user_val_encoded && is_array($user_val_encoded)) ||
                    $content_model == WSF_SIMPLE_CONTENT) {
                /* in a case this is not an array */
                if($content_model == WSF_SIMPLE_CONTENT) {
                    $ele = $payload_dom->createElement($node_name);
                    $parent_node->appendChild($ele);
                    if(is_object($user_val)) {
                      //  echo wsf_test_serialize_node($sig_param_node) ."<val>".print_r($user_val, true)."</val>" ;
                        wsf_create_payload_for_class_map($payload_dom, $sig_param_node,
                         $ele, $root_node, $user_val, $classmap,
                         $prefix_i, $namespace_map, $mtom_on, $attachment_map);
                    }
                    else {
                        wsf_create_payload_for_array($payload_dom, $sig_param_node,
                         $ele, $root_node, $user_val, $prefix_i, $namespace_map, $mtom_on, $attachment_map);
                    }
                }
                else {
                    $ele = $payload_dom->createElement($node_name);
                    $parent_node->appendChild($ele);
                    wsf_serialize_type_info($param_type, $user_val, $sig_param_node, $payload_dom, $root_node,
                                $ele, $namespace_map, $mtom_on, $attachment_map, $user_val_encoded, $content_type);

                }
            }
            else {
                error_log("Array is given for ". $param_name ." which should be a non array. \n");
                ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR,
                    "Array is given for ". $param_name ." which should be a non array.");
            }
        }
    }
}

/** 
 * Do serialization over complex schema types
 * @param $sig_param_node sig model for the param
 * @param $user_val the user value given to the type
 * @param $parant_ele just root element of the element
 * @param $payload_dom  payload dom document
 * @param $classmap (array) users classmap
 * @param $root_node root element of the document, in order to add namespace 
 * @param $prefix_i - next available prefix index 
 * @param namespace_map, array, map to the namespace to prefix
 */
function wsf_serialize_complex_types(DomNode $sig_param_node, $user_val,
                                $parent_node, $payload_dom, $root_node, $classmap,
                                &$prefix_i, &$namespace_map, $mtom_on, &$attachment_map) {

    $target_namespace = NULL;
    $min_occurs = 1;
    $max_occurs = 1;
    $sig_param_attris = $sig_param_node->attributes;
    $param_type = NULL;
    $param_name = NULL;

    if($sig_param_attris->getNamedItem(WSF_NAME)) {
        $param_name = 
            $sig_param_attris->getNamedItem(WSF_NAME)->value;
    }

    if($sig_param_attris->getNamedItem(WSF_TARGETNAMESPACE)) {
        $target_namespace = 
            $sig_param_attris->getNamedItem(WSF_TARGETNAMESPACE)->value;
    }

    if($sig_param_attris->getNamedItem(WSF_MIN_OCCURS)) {
        $min_occurs = 
            $sig_param_attris->getNamedItem(WSF_MIN_OCCURS)->value;
    }

    if($sig_param_attris->getNamedItem(WSF_MAX_OCCURS)) {

        $max_occurs = 
            $sig_param_attris->getNamedItem(WSF_MAX_OCCURS)->value;
    }
    
    if($sig_param_attris->getNamedItem(WSF_TYPE)) {
        $param_type = 
            $sig_param_attris->getNamedItem(WSF_TYPE)->value;
    }
    
    if($target_namespace == NULL) {
        $node_name = $param_name;
    }
    else {
        if(array_key_exists($target_namespace, $namespace_map)
                     && $namespace_map[$target_namespace] != NULL) {
            $prefix = $namespace_map[$target_namespace];
        }
        else{
            $prefix = "ns".$prefix_i;
            $prefix_i ++;
            $root_node->setAttribute("xmlns:".$prefix, $target_namespace);
            $namespace_map[$target_namespace] = $prefix;
        }
        $node_name = $prefix.":".$param_name;
    }


    if($max_occurs > 1 || $max_occurs == "unbounded") {
        if($user_val === NULL) {
            wsf_set_nil_element(NULL, $parent_node, $root_node, $prefix_i, $namespace_map);
        }
        else if(is_array($user_val)) {
            foreach($user_val as $user_val_item) {
                /* type conversion is needed */
                if($user_val_item === NULL) {
                    wsf_set_nil_element(NULL, $parent_node, $root_node, $prefix_i, $namespace_map);
                    continue;
                }
                $param_node = $payload_dom->createElement($node_name);
                if(is_object($user_val_item)) {
                    if($sig_param_node->hasChildNodes()) {
                        wsf_create_payload_for_class_map($payload_dom, 
                                    $sig_param_node, $param_node, $root_node,
                                    $user_val_item, $classmap, $prefix_i,
                                    $namespace_map, $mtom_on, $attachment_map);
                    }
                    else
                    {
                        wsf_create_payload_for_unknown_class_map($payload_dom,
                                    $param_node, $user_val_item, $prefix);
                    }
                }
                else
                {
                    if($sig_param_node->hasChildNodes()) {
                        wsf_create_payload_for_array($payload_dom,
                                    $sig_param_node, $param_node, $root_node,
                                    $user_val_item, $prefix_i, $namespace_map, $mtom_on, $attachment_map);
                    }
                    else
                    {
                        wsf_create_payload_for_unknown_array($payload_dom,
                                    $param_node, $user_val_item, $prefix);
                    }
                }
                $parent_node->appendChild($param_node);
            }
        }
        else {
            /* in a case this is not an array */

            $param_node = $payload_dom->createElement($node_name);
            if(is_object($user_val)) {
                if($sig_param_node->hasChildNodes()) {
                    wsf_create_payload_for_class_map($payload_dom, 
                                $sig_param_node, $param_node, $root_node,
                                $user_val, $classmap, $prefix_i,
                                $namespace_map, $mtom_on, $attachment_map);
                }
                else
                {
                    wsf_create_payload_for_unknown_class_map($payload_dom,
                                $param_node, $user_val, $prefix);
                }
            }
            else
            {
                if($sig_param_node->hasChildNodes()) {
                    wsf_create_payload_for_array($payload_dom,
                                $sig_param_node, $param_node, $root_node,
                                $user_val, $prefix_i, $namespace_map, $mtom_on, $attachment_map);
                }
                else
                {
                    wsf_create_payload_for_unknown_array($payload_dom,
                                $param_node, $user_val, $prefix);
                }
            }
            $parent_node->appendChild($param_node);
        }
    }
    else {
        /* in a case this is not an array */

        $param_node = $payload_dom->createElement($node_name);
        if(is_object($user_val)) {
            if($sig_param_node->hasChildNodes()) {
                wsf_create_payload_for_class_map($payload_dom, 
                            $sig_param_node, $param_node, $root_node,
                            $user_val, $classmap, $prefix_i,
                            $namespace_map, $mtom_on, $attachment_map);
            }
            else
            {
                wsf_create_payload_for_unknown_class_map($payload_dom,
                            $param_node, $user_val, $prefix);
            }
        }
        else
        {
            if($sig_param_node->hasChildNodes()) {
                wsf_create_payload_for_array($payload_dom,
                            $sig_param_node, $param_node, $root_node,
                            $user_val, $prefix_i, $namespace_map, $mtom_on, $attachment_map);
            }
            else
            {
                wsf_create_payload_for_unknown_array($payload_dom,
                            $param_node, $user_val, $prefix);
            }
        }
        $parent_node->appendChild($param_node);
    }
}

/**
 * build the content model correctly
 * @param $sig_node sig model to be processed..
 * @param $user_arguments, user arguments as an array
 * @param $parent_node the immediate parent element
 * @param $payload_dom the dom document of the building xml
 * @param $prefix_i - next available prefix index 
 * @param $root_node the root element of the dom
 */
function wsf_build_content_model(DomNode $sig_node, array $user_arguments,
            DomNode $parent_node, DomNode $payload_dom, $root_node, $classmap, &$prefix_i,
            &$namespace_map, $mtom_on, &$attachment_map) {

    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "building the content model");

    $content_model = WSF_WSDL_SEQUENCE;
    if($sig_node->attributes->getNamedItem(WSF_CONTENT_MODEL)) {
        $content_model = $sig_node->attributes->getNamedItem(WSF_CONTENT_MODEL)->value;
    }

    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, print_r($user_arguments, TRUE));
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, $content_model);
    // simple content extension should be treated differently
    if($content_model == WSF_SIMPLE_CONTENT) {
       
        $param_type = "";
        if($sig_node->attributes->getNamedItem(WSF_EXTENSION)) {
            $param_type = $sig_node->attributes->getNamedItem(WSF_EXTENSION)->value;
        }

        $is_list = FALSE;
        if($sig_node->attributes->getNamedItem(WSF_LIST) &&
            $sig_node->attributes->getNamedItem(WSF_LIST)->value == "yes") {
             $is_list = TRUE;
        }
        $user_val = NULL;
        $user_val_encoded = NULL;
        /* type conversion is needed */
        if(array_key_exists(WSF_SIMPLE_CONTENT_VALUE, $user_arguments)) {
            $user_val = $user_arguments[WSF_SIMPLE_CONTENT_VALUE];
        }
        if($param_type == WSF_XSD_BASE64) {
            if(array_key_exists(WSF_SIMPLE_CONTENT_VALUE. WSF_POSTFIX_BASE64, $user_arguments)) {
                $user_val_encoded = $user_arguments[WSF_SIMPLE_CONTENT_VALUE. WSF_POSTFIX_BASE64];
            }
        }
        if($user_val_encoded === NULL  && $user_val === NULL) {
            wsf_set_nil_element(NULL, $parent_node, $root_node, $prefix_i, $namespace_map);
        }
        $content_type = NULL;
        if(array_key_exists(WSF_CONTENT_TYPE, $user_arguments)) {
            $content_type = $user_arguments[WSF_CONTENT_TYPE];
        }
        wsf_serialize_type_info($param_type, $user_val, $sig_node, $payload_dom, $root_node,
                    $parent_node, $namespace_map, $mtom_on, $attachment_map, $user_val_encoded, $content_type);
    }

    $just_found_once = FALSE;

    $sig_param_nodes = $sig_node->childNodes;
    foreach($sig_param_nodes as $sig_param_node) {
        if($sig_param_node->nodeName == WSF_PARAM) {
            if($sig_param_node->attributes->getNamedItem(WSF_NAME))
	    $param_name = $sig_param_node->attributes->getNamedItem(WSF_NAME)->value;

            // users are not expected to provide it in exact sequence..
            // for both all and sequences we build the xml same order as in the schema
            // for choice we pick the first non-null value in the group, when it is in the order defined in the schema
            foreach($user_arguments as $user_key => $user_val) {
                if($param_name == $user_key) {
                    if($user_val === NULL) {
                        if($sig_param_node->attributes->getNamedItem(WSF_MIN_OCCURS) &&
                                $sig_param_node->attributes->getNamedItem(WSF_MIN_OCCURS)->value == 0) {
                            ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, 
                                "minOccurs=0 element $user_key is nil");
                            break; //will not render the min occured 0 nil elements
                        }
                        else if($content_model == WSF_WSDL_SEQUENCE &&
                                $sig_param_node->attributes->getNamedItem(WSF_XSD_NILLABLE) &&
                                $sig_param_node->attributes->getNamedItem(WSF_XSD_NILLABLE)->value == "true") {
                            // this too ok, somehow we would render an nill element here,
                            // we are not handling it here concerning the array elements
                            ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, 
                                "nillable element $user_key is nil");
                        }
                        else {
                            // not allow to be NIL section
                            ws_log_write(__FILE__, __LINE__, WSF_LOG_ERROR, 
                                "non nillable and minOccurs!=0 element $user_key is nil");
                            // right now we dont throw excpetion here..
                            //TODO: exit as validation fails
                            break;
                        }
                            
                    }
                    if (($sig_param_node->attributes->getNamedItem(WSF_WSDL_SIMPLE) &&
                            $sig_param_node->attributes->getNamedItem(WSF_WSDL_SIMPLE)->value == "yes") ||
                            ($sig_param_node->attributes->getNamedItem(WSF_TYPE) &&
                             $sig_param_node->attributes->getNamedItem(WSF_TYPE)->value == "anyType")) {
                        $user_val_encoded = NULL;
                        $param_type = NULL;

                        if($sig_param_node->attributes->getNamedItem(WSF_TYPE)) {
                            $param_type = 
                                $sig_param_node->attributes->getNamedItem(WSF_TYPE)->value;
                        }

                        if($param_type == WSF_XSD_BASE64) {
                            if(array_key_exists($user_key. WSF_POSTFIX_BASE64, $user_arguments)) {
                                $user_val_encoded = $user_arguments[$user_key. WSF_POSTFIX_BASE64];
                            }
                        }
                        ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, 
                                "calling serialize simple types");
                        // default simple type
                        wsf_serialize_simple_types($sig_param_node,
                                    $user_val, $parent_node, $payload_dom, 
                                    $root_node, $classmap, $prefix_i, $namespace_map,
                                    $mtom_on, $attachment_map, $user_val_encoded);
                    }
                    else {
                        ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, 
                                "calling serialize complex types");
                        wsf_serialize_complex_types($sig_param_node, 
                                        $user_val, $parent_node, $payload_dom,
                                        $root_node, $classmap, $prefix_i, 
                                        $namespace_map, $mtom_on, $attachment_map);
                    }
                    if($user_val !== NULL) {
                        $just_found_once = TRUE;
                    }
                    break;
                }

            }
            if($just_found_once && $content_model == "choice") {
                break;
            }
        }
        else if($sig_param_node->nodeName == WSF_INNER_CONTENT) {
            wsf_build_content_model($sig_param_node, $user_arguments, $parent_node,
                    $payload_dom, $root_node, $classmap, $prefix_i,
                    $namespace_map, $mtom_on, $attachment_map);
        }
        else if($sig_param_node->nodeName == WSF_INHERITED_CONTENT) {
            wsf_build_content_model($sig_param_node, $user_arguments, $parent_node,
                    $payload_dom, $root_node, $classmap, $prefix_i,
                    $namespace_map, $mtom_on, $attachment_map);
        }
    }
}

/**
 * convert user object to user arguments array, right now just for one level
 * @param $sig_node DomNode sig model
 * @param $user_obj
 * @return resulting argument array
 */
function wsf_convert_classobj_to_array($sig_node, $user_obj) {

    $user_arguments = array();
    $sig_param_nodes = $sig_node->childNodes;
    $sig_param_attrs = $sig_node->attributes;
    if(!is_object($user_obj) && !is_array($user_obj)) {
        return $user_obj;
    }

    /* for the simple content type we expect the "VALUE" attribute */
    if($sig_param_attrs->getNamedItem(WSF_CONTENT_MODEL) &&
            $sig_param_attrs->getNamedItem(WSF_CONTENT_MODEL)->value == WSF_SIMPLE_CONTENT) {
        $extension_type = "";
        if($sig_param_attrs->getNamedItem(WSF_EXTENSION)) {
            $extension_type = $sig_param_attrs->getNamedItem(WSF_EXTENSION)->value;
        }

        $simple_content_value_const = WSF_SIMPLE_CONTENT_VALUE;
        $reflex_object = new ReflectionObject($user_obj);
        
        //treat specially for the base64, to give two apis one for base64, one without base64..
        if($extension_type == WSF_XSD_BASE64) {
            $simple_content_value_encoded = WSF_SIMPLE_CONTENT_VALUE.WSF_POSTFIX_BASE64;

            if($reflex_object->hasProperty($simple_content_value_encoded) && $user_obj->$simple_content_value_encoded !== NULL) {
                $user_arguments[$simple_content_value_encoded] = $user_obj->$simple_content_value_encoded;
            }

            if($reflex_object->hasProperty($simple_content_value_const) && $user_obj->$simple_content_value_const !== NULL) {
                $user_arguments[$simple_content_value_const] = $user_obj->$simple_content_value_const;
            }
        }
        else {
            if($reflex_object->hasProperty($simple_content_value_const) && $user_obj->$simple_content_value_const !== NULL) {
                $user_arguments[$simple_content_value_const] = $user_obj->$simple_content_value_const;
            }
        }
    }
        

    foreach($sig_param_nodes as $sig_param_node) {
        if($sig_param_node->nodeName == WSF_PARAM && is_object($user_obj)) {
            $param_attrs = $sig_param_node->attributes;
            $param_name = "";
            $param_type = "";
            if($param_attrs->getNamedItem(WSF_NAME)) {
                $param_name = $param_attrs->getNamedItem(WSF_NAME)->value;
            }
            if($param_attrs->getNamedItem(WSF_TYPE)) {
                $param_type = $param_attrs->getNamedItem(WSF_TYPE)->value;
            }

            $reflex_object = new ReflectionObject($user_obj);

            if($param_type == WSF_XSD_BASE64) {
                $param_name_encoded = $param_name.WSF_POSTFIX_BASE64;
                if($reflex_object->hasProperty($param_name_encoded)) {
                    $user_arguments[$param_name_encoded] = $user_obj->$param_name_encoded;
                }
                if($reflex_object->hasProperty($param_name)) {
                    $user_arguments[$param_name] = $user_obj->$param_name;
                }
            }
            else {
                if($reflex_object->hasProperty($param_name)) {
                    $user_arguments[$param_name] = $user_obj->$param_name;
                }
            }

        }
        else if($sig_param_node->nodeName == WSF_INNER_CONTENT) {
            $tmp_array = wsf_convert_classobj_to_array($sig_param_node, $user_obj);
            $user_arguments = array_merge($user_arguments, $tmp_array);
        }
        else if($sig_param_node->nodeName == WSF_INHERITED_CONTENT) {
            $tmp_array = wsf_convert_classobj_to_array($sig_param_node, $user_obj);
            $user_arguments = array_merge($user_arguments, $tmp_array);
        }
    }
    return $user_arguments;
}

/**
 * serialize the php value to the string value to put in the xml
 * @param $xsd_type, xsd type the value hold
 * @param $data_value, the data_value with php type
 * @param $is_list, whether the given map is a list
 * @param $parent_node, for put xsi:type in a case of a need..
 * @return string serialized to string
 */
function wsf_wsdl_serialize_php_value($xsd_type, $data_value, 
            $sig_param_node, $parent_node, &$prefix_i, &$namespace_map, $root_node) {

    $is_list = FALSE;
    $is_union = FALSE;
    $sig_param_attris = $sig_param_node->attributes;
    if($sig_param_attris->getNamedItem(WSF_LIST) &&
        $sig_param_attris->getNamedItem(WSF_LIST)->value == "yes") {
         $is_list = TRUE;
    }
   
    //currently union are not handled correctly
    if($sig_param_attris->getNamedItem(WSF_UNION) &&
        $sig_param_attris->getNamedItem(WSF_UNION)->value == "yes") {
         $is_union = TRUE;
    }

    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "serializing ".$data_value);
    // handle the list
    if($is_list && is_array($data_value)) {
        $tmp_data_values = $data_value;

        $new_data_value = array();
        foreach($tmp_data_values as $tmp_data_value) {
            //this can't be anytype, since we can't put xsi:type in parent node there..
            $new_data_value[] = wsf_convert_php_type_to_string($xsd_type, $tmp_data_value);
        }

        $serialized_value = implode(" ", $new_data_value);
    }
    else {
        $serialized_value = wsf_convert_php_type_to_string($xsd_type, $data_value);
        ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "xsd type info ".$xsd_type);
        if($xsd_type == "anyType") {

            if(array_key_exists(WSF_XSI_NAMESPACE, $namespace_map)) {
                $xsi_prefix = $namespace_map[WSF_XSI_NAMESPACE];
            }
            else {
                $xsi_prefix = "xsi";
                $root_node->setAttribute("xmlns:".$xsi_prefix, WSF_XSI_NAMESPACE);
                $namespace_map[WSF_XSI_NAMESPACE] = $xsi_prefix;
            }
            if(array_key_exists(WSF_XSD_NAMESPACE, $namespace_map)) {
                $xsd_prefix = $namespace_map[WSF_XSD_NAMESPACE];
            }
            else {
                $xsd_prefix = "xsd";
                $root_node->setAttribute("xmlns:".$xsd_prefix, WSF_XSD_NAMESPACE);
                $namespace_map[WSF_XSD_NAMESPACE] = $xsd_prefix;
            }

            $attribute_name = $xsi_prefix.":"."type";
            $php_type = $xsd_prefix.":".gettype($data_value);
            $attribute_value = $php_type;

            $parent_node->setAttribute($attribute_name, $attribute_value);
                
        }
    }


    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "serialized ".$serialized_value);
    return $serialized_value;
}

/**
 * serialize the php value to the string value to put in the xml
 * @param $xsd_type, xsd type the value hold
 * @param $data_value, the data_value with php type
 * @return string serialized to string
 */
function wsf_convert_php_type_to_string($xsd_type, $data_value) {
	
	$serialized_value = $data_value;
	if($serialized_value === NULL) {
		return "";
	}
	
	// we treat dateTime value differently
	if($xsd_type == "dateTime" || $xsd_type == "date" || $xsd_type == "time") {
		
		if(gettype($data_value) == "integer") {
			if($xsd_type == "dateTime") {
				$serialized_value = date("Y-m-d", $data_value)."T".date("H:i:s", $data_value)."Z";
			}
			else if($xsd_type == "date") {
				$serialized_value = date("Y-m-d", $data_value);
			}
			else if($xsd_type == "time") {
					$serialized_value = date("H:i:s", $data_value)."Z";
				}
		}
		else {
			// hope the other type is the string as it is
			$serialized_value = (string)$data_value;
		}
	}
	else {
		$xsd_php_mapping_table = wsf_wsdl_util_xsd_to_php_type_map();
		
		if(array_key_exists($xsd_type, $xsd_php_mapping_table)) {
			//retrieve the php type
			$type = $xsd_php_mapping_table[$xsd_type];
			
			if($type == "boolean") {
				if($data_value == FALSE) {
					$serialized_value = "false";
				}
				else
				{
					$serialized_value = "true";
				}
			}
		}
	}
    return $serialized_value."";
}

/**
 * infer the correct type and serialize, specially for mtom binding
 * @param $param_type parameter type
 * @param $user_val user value (default set)
 * @param $sig_node corrosponding sig node
 * @param $payload_dom payload DOM
 * @param $parent_node parent node the dom tree should be set to
 * @param $user_val_encoded (alternative var for base64 types)
 * @param $content_type content type
 * @param $attachment_map map of href => attachment contnet
 */
function wsf_serialize_type_info($param_type, $user_val, $sig_node, $payload_dom, $root_node,
                        $parent_node,
                        &$namespace_map,
                        $mtom_on, &$attachment_map,
                        $user_val_encoded = NULL,
                        $content_type = NULL) {

    /* handle the mtom scenario different to other cases */
    if($param_type == WSF_XSD_BASE64) {
        if($mtom_on) {
            // if the mtom on, use the encoded one..

            if(!$user_val) {
                if($user_val_encoded) {
                    $user_val = base64_decode($user_val_encoded);
                }
            }

            if($user_val) {
                // just attach the $user_val to the array
                // and prepare the dom structure

                // set the xmlmime namespace
                $xml_mime_ns_prefix = WSF_MIME_NAMESPACE_PREFIX;
                if(array_key_exists(WSF_MIME_NAMESPACE_URI, $namespace_map)) {
                    //nothing to do special
                    $xml_mime_ns_prefix = $namespace_map[WSF_MIME_NAMESPACE_URI];
                }
                else {
                    $xml_mime_ns_prefix = WSF_MIME_NAMESPACE_PREFIX;
                    $namespace_map[WSF_MIME_NAMESPACE_URI] = WSF_MIME_NAMESPACE_PREFIX;
                
                    if($content_type == NULL){
                        $root_node->setAttribute("xmlns:".WSF_MIME_NAMESPACE_PREFIX,
                                WSF_MIME_NAMESPACE_URI);
                    }
                }

                if($content_type == NULL) {
                    $content_type = WSF_DEFAULT_CONTENT_TYPE;
                    // set the content type ..we only set this only,
                    // if the contentType is not available from the schema itself
                    $parent_node->setAttribute($xml_mime_ns_prefix. ":". WSF_CONTENT_TYPE,
                                $content_type);
                }

                $mtom_include_node = $payload_dom->createElementNS(WSF_XOP_NAMESPACE_URI,
                            WSF_XOP_NAMESPACE_PREFIX.":". WSF_MTOM_INCLUDE_TAG);

                $href_id = NULL;
                do {
                    $rnd = rand();
                    $href_id = "id".$rnd;
                }
                while(array_key_exists($href_id, $attachment_map));

                // put the attachment to the the map
                $attachment_map[$href_id] = $user_val;
                
                $mtom_include_node->setAttribute(WSF_HREF, WSF_HREF_PREFIX.$href_id);

                $parent_node->appendChild($mtom_include_node);
            }
        }
        else {
            // if the mtom off use the non-encoded variable
            if(!$user_val_encoded) {
                if($user_val) {
                    $user_val_encoded = base64_encode($user_val);
                }
            }

            if($user_val_encoded) {
                if(!wsf_set_nil_element($user_val_encoded, $parent_node, $root_node, $prefix_i, $namespace_map)) {
                    $serialized_value = wsf_wsdl_serialize_php_value(
                        $param_type, $user_val_encoded, 
                        $sig_node, $parent_node, $prefix_i, $namespace_map, $root_node);
                    $ele = $payload_dom->createTextNode($serialized_value);
                    $parent_node->appendChild($ele);
                }
            }
        }
    }
    else {
        
        ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "setting the value after a null check");

        if(!wsf_set_nil_element($user_val, $parent_node, $root_node, $prefix_i, $namespace_map)) {
            $serialized_value = wsf_wsdl_serialize_php_value(
                 $param_type, $user_val, $sig_node,
                 $parent_node, $prefix_i, $namespace_map, $root_node);
            $ele = $payload_dom->createTextNode($serialized_value);
            $parent_node->appendChild($ele);
        }
    }
}

/**
 * Extract the sig node looking at the user object type
 * @param array $sig_model as a DomNode
 * @param DomNode $parent_node - The parent node to add the content 
 * @param DomNode $root_node - The top most of parent
 * @param mixed $user_obj - class object to pass
 * @param $prefix_i - next available prefix index 
 * @param $namespace_map - Just make sure the unique namespace is used.
    Newly added (passed by reference)
 */


function wsf_infer_sig_node_from_user_obj($sig_node, $parent_node, $root_node, 
            $user_obj, $classmap, &$prefix_i, array &$namespace_map) {

    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "Calling infer sig mode from user obj");

    // first loop the through sig child whther there is is inheriting-types in there
    $inheriting_type_sigs = array();
    $inheriting_type_namespaces = array();

    $sig_child_nodes = $sig_node->childNodes;
    foreach($sig_child_nodes as $sig_child_node) {
        
        if($sig_child_node->localName == WSF_INHERITING_TYPE) {

            $sig_child_attris = $sig_child_node->attributes;
            $type_name = $type_ns = "";
            if($sig_child_attris->getNamedItem(WSF_XSI_TYPE)) {
                 $type_name = $sig_child_attris->getNamedItem(WSF_XSI_TYPE)->value;
            }
            if($sig_child_attris->getNamedItem(WSF_XSI_TYPE_NS)) {
                 $type_ns = $sig_child_attris->getNamedItem(WSF_XSI_TYPE_NS)->value;
            }

            ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "type name $type_name ; $type_ns ");
            $inheriting_type_sigs[$type_name] = $sig_child_node;
            $inheriting_type_namespaces[$type_name] = $type_ns;
        }
    }
    
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, print_r($inheriting_type_namespaces, TRUE));

    // if not inheriting types just let the sig_node to be the sig node
    if(count($inheriting_type_sigs) == 0) {
        return $sig_node;
    }
      
    $reflex_obj = new ReflectionObject($user_obj);
    if(!$reflex_obj) {
        return $sig_node;
    }

    $class_name = $reflex_obj->getName();
    
    // find the type name
    $type_name = $class_name;

    // if the classmap is present we need to check the type name from the map
    if($classmap && is_array($classmap)) {
        foreach($classmap as $type_name_key => $class_name_value ) {
            if($class_name_value == $class_name) {
                $type_name = $type_name_key;
                break;
            }
        }
    }

    // so we found the type, check with the collected inherited_types
    $the_sig_node = NULL;
    $the_type_name = NULL;
    $the_type_namespace = NULL;
    if(array_key_exists($type_name, $inheriting_type_sigs)) {
        $the_type_name = $type_name;
        $the_type_namespace = $inheriting_type_namespaces[$type_name];
        $the_sig_node = $inheriting_type_sigs[$type_name];
    }
    else {
        // not in inherited map, so should be the same sig,
        return $sig_node;
    }

    //now retrieve the namespace or declare it if it is not present
    $the_type_ns_prefix = NULL;
    if(array_key_exists($the_type_namespace, $namespace_map)) {
        $the_type_ns_prefix = $namespace_map[$the_type_namespace];
    }
    else {
        $the_type_ns_prefix = "ns".$prefix_i;
        $prefix_i ++;
        $root_node->setAttribute("xmlns:".$the_type_ns_prefix, $the_type_namespace);
        $namespace_map[$the_type_namespace] = $the_type_ns_prefix;
    }

    $xsi_namespace_prefix = NULL;
    if(array_key_exists(WSF_XSI_NAMESPACE, $namespace_map)) {
        $xsi_namespace_prefix = $namespace_map[WSF_XSI_NAMESPACE];
    }
    else {
        $xsi_namespace_prefix = "xsi";
        $root_node->setAttribute("xmlns:".$xsi_namespace_prefix, WSF_XSI_NAMESPACE);
        $namespace_map[WSF_XSI_NAMESPACE] = $xsi_namespace_prefix;
    }
    
    $attribute_name = $xsi_namespace_prefix.":"."type";
    $attribute_value = $the_type_ns_prefix.":".$the_type_name;

    $parent_node->setAttribute($attribute_name, $attribute_value);

    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, wsf_test_serialize_node($the_sig_node));
    return $the_sig_node;
}

function wsf_set_nil_element($value, $parent_node, $root_node, &$prefix_i, array &$namespace_map) {
    if($value !== NULL) {
        ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, $parent_node->localName. " is not nil\n value is: ".print_r($value, TRUE));
        return FALSE;
    }
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, $parent_node->localName. " is nil\n");
    if(array_key_exists(WSF_XSI_NAMESPACE, $namespace_map)) {
        $prefix = $namespace_map[WSF_XSI_NAMESPACE];
    }
    else {
        $prefix = "xsi";
        $root_node->setAttribute("xmlns:".$prefix, WSF_XSI_NAMESPACE);
        $namespace_map[WSF_XSI_NAMESPACE] = $prefix;
    }

    $attribute_name = $prefix.":"."nil";
    $attribute_value = "1";

    $parent_node->setAttribute($attribute_name, $attribute_value);

    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, $parent_node->localName. " is nil");
    return TRUE;
}

//-------------------------------------------------------------------------------------------
//currently we don't have diffent serialization for rpc-style in contrast with doc-lit

?>

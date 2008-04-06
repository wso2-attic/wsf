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
 * parse payload and return an array of paramerters
 * @param $payload 
 * @param $sig_data_struct
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
 * @return the parse tree
 */
function wsf_parse_payload_for_array(DomNode $payload, array $sig_data_struct) {

    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "Loading in to parsing array");
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, print_r($sig_data_struct, TRUE));
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, wsf_test_serialize_node($payload));

    while($payload != NULL && $payload->nodeType != XML_ELEMENT_NODE) {
        $payload = $payload->nextSibling;
    }


    // this situation meets only for non-wrapped mode as doclit-bare wsdls
    if(array_key_exists(WSF_TYPE_REP, $sig_data_struct)) {
        $param_value = $sig_data_struct[WSF_TYPE_REP];
        if(is_xsd_type($param_value)) {
            if ($payload != NULL) {
                if($payload->firstChild) {
                    $original_value = $payload->firstChild->nodeValue;
                }
                else {
                    $original_value = "";
                }
                $converted_value = wsf_wsdl_util_convert_value($param_value, $original_value);

                return $converted_value;
            }
        }
    }

    //all the other situations..    
    $parse_tree = array();

    if($payload != NULL) {
        /* go for the childs */
        $current_child = $payload->firstChild;
        while($current_child != NULL && $current_child->nodeType != XML_ELEMENT_NODE) {
            $current_child = $current_child->nextSibling;
        }
        if($current_child == NULL) {
            return $parse_tree; //just the empty array
        }
    }

    $parse_tree = wsf_infer_content_model($current_child, $sig_data_struct, FALSE);

    return $parse_tree;
}


/**
 * parse payload and return an object hierarchy
 * @param $payload 
 * @param $sig_data_struct
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
 * @param $element_name element name under which the parsing happen
 * @return the parsed result objects
 */
function wsf_parse_payload_for_class_map(DomNode $payload, array $sig_data_struct, $element_name, $class_map) {

    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "Loading in to parsing classmap");
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, print_r($sig_data_struct, TRUE));
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, wsf_test_serialize_node($payload));

    while($payload != NULL && $payload->nodeType != XML_ELEMENT_NODE) {
        $payload = $payload->nextSibling;
    }

    // this situation meets only for non-wrapped mode as doclit-bare wsdls
    if(array_key_exists(WSF_TYPE_REP, $sig_data_struct)) {
        $param_value = $sig_data_struct[WSF_TYPE_REP];
        if(is_xsd_type($param_value)) {
            if ($payload != NULL) {
                if($payload->firstChild) {
                    $original_value = $payload->firstChild->nodeValue;
                }
                else {
                    $original_value = "";
                }
                $converted_value = wsf_wsdl_util_convert_value($param_value, $original_value);

                return $converted_value;
            }
        }
    }

    // for all the other situation gotta create the object..
    if(is_array($class_map) && array_key_exists($element_name, $class_map)) {
        $class_name = $class_map[$element_name];
    }
    if(!isset($class_name) || $class_name == NULL) {
        $class_name = $element_name;
    }
    

    try
    {
        $ref_class = new ReflectionClass($class_name);
        if ($ref_class->isInstantiable()) {
            $object = $ref_class->newInstance();

        }
    } catch(Exception $e) {
        $object = new WSFUnknownSchemaConstruct();
    }

    if($object == NULL) {
        return NULL;
    }

    // for a NULL payload return the empty object
    if($payload == NULL) {
        return $object;
    }

    $current_child = $payload->firstChild;
    while($current_child != NULL && $current_child->nodeType != XML_ELEMENT_NODE) {
        $current_child = $current_child->nextSibling;
    }
    if($current_child == NULL) {
        /* it still can be a text node */
        $current_child = $payload->firstChild;
        if($current_child != NULL && $current_child->nodeType == XML_TEXT_NODE) {
            return $current_child->nodeValue;
        }
        /* otherwise it is a NULL */
        return NULL;
    }

    // all the above part of the story we were handling non-wrap types like in doclit-bare

    $parse_tree = wsf_infer_content_model($current_child, $sig_data_struct, TRUE);

    foreach($parse_tree as $parsed_key => $parsed_value) {
        $object->$parsed_key = $parsed_value;
    }
    return $object;
}


/**
 * wsf_parse_payload_for_unknown_array
 * @param $current_node node to parse
 * @returns array of parsed data
 */
function wsf_parse_payload_for_unknown_array(DomNode $current_node) {
    $param_child = array();

    while($current_node != NULL && $current_node->nodeType != XML_ELEMENT_NODE) {
        $current_node = $current_node->nextSibling;
    }

    foreach($current_node->childNodes as $child) {
        if($child->nodeType == XML_TEXT_NODE) {
            $node_value = $child->nodeValue;
            return $node_value;
        }


        $name = $child->tagName;
        $needle = strpos($name, ':');

        if($needle !== FALSE) {
            $name = substr($name, $needle + 1);
        }

        if($child->nodeType ==  XML_ELEMENT_NODE) {
            $node_value = wsf_parse_payload_for_unknown_array($child);
        }
        else
        {
            $node_value = NULL;
        }

        if($node_value !== NULL) {
            if($param_child[$name] === NULL) {
                $param_child[$name] = $node_value;
            }
            else
            {
                if(is_array($param_child[$name]) && !wsf_is_map($param_child[$name])) {
                    $i = count($param_child[$name]);
                    $param_child[$name][$i] = $node_value;
                }
                else
                {
                    $tmp = $param_child[$name];
                    $param_child[$name] = array($tmp, $node_value);
                }
            }
        }
    }

    return $param_child;
}

/**
 * wsf_parse_payload_for_unknown_class_map
 * @param $current_node node to parse
 * @returns array of parsed data
 */
function wsf_parse_payload_for_unknown_class_map(DomNode $current_node, $element_name, $class_map) {
    $class_name = NULL;
    if(is_array($class_map) && array_key_exists($element_name, $class_map)) {
        $class_name = $class_map[$element_name];
    }
    if(!isset($class_name) || $class_name == NULL) {
        $class_name = $element_name;
    }
   
    try
    {
        $ref_class = new ReflectionClass($class_name);
        if ($ref_class->isInstantiable()) {
            $object = $ref_class->newInstance();

        }
    } catch(Exception $e) {
        $object = new WSFUnknownSchemaConstruct();
    }

    if($object == NULL) {
        return NULL;
    }

    while($current_node != NULL && $current_node->nodeType != XML_ELEMENT_NODE) {
        $current_node = $current_node->nextSibling;
    }

    foreach($current_node->childNodes as $child) {
        if($child->nodeType == XML_TEXT_NODE) {
            $node_value = $child->nodeValue;
            return $node_value;
        }


        $name = $child->tagName;
        $needle = strpos($name, ':');

        if($needle !== FALSE) {
            $name = substr($name, $needle + 1);
        }

        if($child->nodeType ==  XML_ELEMENT_NODE) {
            $node_value = wsf_parse_payload_for_unknown_class_map($child, $name, $class_map);
        }
        else
        {
            $node_value = NULL;
        }

        if($node_value !== NULL) {
            if($object->$name === NULL) {
                $object->$name = $node_value;
            }
            else
            {
                if(is_array($object->$name) && !wsf_is_map($object->$name)) {
                    $i = count($object->$name);
                    $tmp = $object->$name;
                    $tmp[$i] = $node_value;
                    $object->$name = $tmp;
                }
                else
                {
                    $tmp = $object->$name;
                    $object->$name = array($tmp, $node_value);
                }
            }
        }
    }

    return $object;
}

/** 
 * Do deserialization over simple schema types and move to the next element
 * @param param_key string, the element name
 * @param param_value array, the schema information corrosponding to the key element
 *                     consists of following information for an example
 *                         [has_childs] => 
 *                         [ns] => http://wso2.org/dyn/codegen/demo
 *                         [type_rep] => int
 * @param $current_child is the relevent xml node to parse
 * @return the result simple type value.
 */

function deserialize_simple_types($param_key, $param_value, &$current_child) {

    $ret_val = NULL;

    if(array_key_exists("maxOccurs", $param_value) && ($param_value["maxOccurs"] == "unbounded" || $param_value["maxOccurs"] > 1)) {
        $i = 0;
        $tmp_array = array();
        while($current_child !== NULL && $current_child->localName == $param_key) {
            if($current_child->firstChild) {
                $converted_value =  wsf_wsdl_util_convert_value($param_value[WSF_TYPE_REP], $current_child->firstChild->wholeText);
            }
            else{
                if(!isset($param_value["nillable"])) {
                    error_log("Non nillable element". $param_key ."is nil. \n");
                }
                $converted_value = "";
            }
            $tmp_array[$i++] = $converted_value;
            $current_child = $current_child->nextSibling;
            while($current_child != NULL && $current_child->nodeType != XML_ELEMENT_NODE) {
                $current_child = $current_child->nextSibling;
            }
        }
        $ret_val = $tmp_array;
        $object->$param_key = $tmp_array;
    }
    else
    {
        if($current_child->firstChild) {
            $converted_value =  wsf_wsdl_util_convert_value($param_value[WSF_TYPE_REP], $current_child->firstChild->wholeText);
        }
        else
        {
            if(!isset($param_value["nillable"])) {
                error_log("Non nillable element". $param_key ."is nil. \n");
            }
            $converted_value = "";
        }
        $object->$param_key = $converted_value;
        $ret_val = $converted_value;
        $current_child = $current_child->nextSibling;
        while($current_child != NULL && $current_child->nodeType != XML_ELEMENT_NODE) {
            $current_child = $current_child->nextSibling;
        }
    }
    return $ret_val;
}

/** 
 * Do deserialization over complex schema types and move to the next element
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
 *
 * @param $current_child is the relevent xml node to parse
 * @return the result complex type value.
 */


function deserialize_complex_types($param_key, $param_value, &$current_child, $is_classmap = TRUE) {

   $class_map_name = $param_value[WSF_CLASSMAP_NAME];
   ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, print_r($param_value, TRUE));
    $ret_val = NULL;
    if(array_key_exists("maxOccurs", $param_value) && ($param_value["maxOccurs"] == "unbounded" || $param_value["maxOccurs"] > 1)) {
        $i = 0;
        $tmp_array = array();
        while($current_child !== NULL && $current_child->localName == $param_key) {
            if($current_child->firstChild) {
                if($param_value[WSF_HAS_SIG_CHILDS] === TRUE && array_key_exists(WSF_SIG_CHILDS, $param_value)) {
                    if($is_classmap) {
                        $converted_value = wsf_parse_payload_for_class_map($current_child, $param_value, $class_map_name, $class_map);
                    }
                    else { 
                        $converted_value = wsf_parse_payload_for_array($current_child, $param_value);
                    }

                }
                else
                {
                    if($is_classmap) {
                        $converted_value = wsf_parse_payload_for_unknown_class_map($current_child, $class_map_name, $class_map);
                    }
                    else {
                        $converted_value = wsf_parse_payload_for_unknown_array($current_child);
                    }
                }
            }
            else
            {
                if(!isset($param_value["nillable"])) {
                    error_log("Non nillable element". $param_key ."is nil. \n");
                }
                $converted_value = "";
            }
            $tmp_array[$i++] = $converted_value;
            $current_child = $current_child->nextSibling;
            while($current_child != NULL && $current_child->nodeType != XML_ELEMENT_NODE) {
                $current_child = $current_child->nextSibling;
            }
        }
        $ret_val = $tmp_array;
    }
    else
    {
        if($current_child->firstChild) {
            if($param_value[WSF_HAS_SIG_CHILDS] === TRUE && array_key_exists(WSF_SIG_CHILDS, $param_value)) {
                if($is_classmap) {
                    $converted_value = wsf_parse_payload_for_class_map($current_child, $param_value, $class_map_name, $class_map);
                }
                else { 
                    $converted_value = wsf_parse_payload_for_array($current_child, $param_value);
                }
            }
            else
            {
                if($is_classmap) {
                    $converted_value = wsf_parse_payload_for_unknown_class_map($current_child, $class_map_name, $class_map);
                }
                else{
                    $converted_value = wsf_parse_payload_for_unknown_array($current_child);
                }
            }
        }
        else
        {
            if(!isset($param_value["nillable"])) {
                error_log("Non nillable element". $param_key ."is nil. \n");
            }
            $converted_value = "";
        }
        $ret_val = $converted_value;
        $current_child = $current_child->nextSibling;
        while($current_child != NULL && $current_child->nodeType != XML_ELEMENT_NODE) {
            $current_child = $current_child->nextSibling;
        }
    }
    return $ret_val;
}

/**
 * handle content model in parsing
 * @param $current_child, starting child element to handle...
 * @param $sig_data_struct, the same old parameter struct..
 * @param $is_classmap whether it is for classmap or not..
 */
function wsf_infer_content_model(DomNode $current_child, array $sig_data_struct, $is_classmap) {
    $parse_tree = array();
    $content_model = $sig_data_struct[WSF_CONTENT_MODEL];
    $first_child = $current_child;
    if(array_key_exists(WSF_SIG_CHILDS, $sig_data_struct) && is_array($sig_data_struct[WSF_SIG_CHILDS])) {
        foreach($sig_data_struct[WSF_SIG_CHILDS] as $param_key => $param_value) {
            // the childs should be set as an array
            if(is_array($param_value)) {
                if(isset($param_value[WSF_CLASSMAP_NAME]) && ($param_value[WSF_CLASSMAP_NAME] == "anyType")) {
                    $tag_name = $current_child->localName;
                    if($param_key == $tag_name) {
                        $converted_value = wsf_parse_payload_for_unknown_array($current_child);
                        $parse_tree[$param_key] = $converted_value;
                        continue;
                    }
                }
               
                if($content_model == "sequence") {
                    if($param_key == $current_child->localName) {
                        if(isset($param_value[WSF_TYPE_REP]) && $param_value[WSF_TYPE_REP]) {
                            // this moves the current_child pointer to the next child..
                            $parse_tree[$param_key] = deserialize_simple_types($param_key, $param_value, $current_child);
                        }
                        else {
                            $parse_tree[$param_key] = deserialize_complex_types($param_key, $param_value, $current_child, $is_classmap);
                        }
                    }
                    else
                    {
                        if(!array_key_exists("minOccurs", $param_value) || $param_value["minOccurs"] == 0) {
                            // if array_key doesn't exist that mean minOccurs = 1;
                            error_log("minOccurs != 0 element ". $param_key ." doesn't exist in the sequence.\n");
                            if($current_child->localName != NULL){
                                error_log($current_child->localName. " is found in place of ". $param_key ."\n");
                            }
                        }
                    }
                }
                else if($content_model == "all") {
                    $found = FALSE;
                    $current_child = $first_child;
                    while($current_child !== NULL) {
                        if($current_child->nodeType == XML_TEXT_NODE) {
                            continue;
                        }

                        if($param_key == $current_child->localName) {
                            if(isset($param_value[WSF_TYPE_REP]) && $param_value[WSF_TYPE_REP]) {
                                // this moves the current_child pointer to the next child..
                                $parse_tree[$param_key] = deserialize_simple_types($param_key, $param_value, $current_child);
                            }
                            else {
                                $parse_tree[$param_key] = deserialize_complex_types($param_key, $param_value, $current_child, $is_classmap);
                            }
                            $found = TRUE;
                            break; //found and no need to investigate more..
                        }

                        $current_child = $current_child->nextSibling;
                    }
                    if(!$found) {
                        
                        if(!array_key_exists("minOccurs", $param_value) || $param_value["minOccurs"] != 0) {
                            // if array_key doesn't exist that mean minOccurs = 1;
                            error_log("minOccurs != 0 element ". $param_key ." doesn't exist.\n");
                        }  
                    }
                }
                else if($content_model == "choice") {
                    if($param_key == $current_child->localName) {
                        if(isset($param_value[WSF_TYPE_REP]) && $param_value[WSF_TYPE_REP]) {
                            // this moves the current_child pointer to the next child..
                            $parse_tree[$param_key] = deserialize_simple_types($param_key, $param_value, $current_child);
                        }
                        else {
                            $parse_tree[$param_key] = deserialize_complex_types($param_key, $param_value, $current_child, $is_classmap);
                        }

                        //finally found what they were asking for, no need to continue any further..
                        break;
                    }
                }
            }
        }
    }
    return $parse_tree;
}

//-----------------------------------------------------------------------------


?>

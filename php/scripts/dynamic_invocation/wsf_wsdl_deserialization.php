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
 * @param $parameter_struct
 * @return
 */
function wsf_parse_payload_for_array(DomNode $payload, array $parameter_struct)
{
    $parse_tree = array();

    $is_just_text = FALSE;
    
    /* for now, we only support complex type sequences */
    //$child_nodes = $payload->childNodes;

    $original_payload = $payload;
    while($payload != NULL && $payload->nodeType != XML_ELEMENT_NODE)
    {
        $payload = $payload->nextSibling;
    }
    if($payload == NULL) {
        $is_just_text = TRUE;
    }


    if($payload != NULL)
    {
        /* go for the childs */
        $current_child = $payload->firstChild;
        while($current_child != NULL && $current_child->nodeType != XML_ELEMENT_NODE)
        {
            $current_child = $current_child->nextSibling;
        }
        if($current_child == NULL)
        {
            $is_just_text = TRUE;
        }
    }

    foreach($parameter_struct as $key => $value)
    {   
        if(is_array($value))
        {
            if($is_just_text)
            {
                continue;
            }
            if(isset($value["class_map_name"]) && ($value["class_map_name"] == "anyType"))
            {
                $tag_name = $current_child->localName;
                if($key == $tag_name)
                {
                  $converted_value = wsf_parse_payload_for_unknown_array($current_child);
                  $parse_tree[$key] = $converted_value;
                  continue;
                }
            }
            if(isset($value[WSF_TYPE_REP]) && $value[WSF_TYPE_REP]){
                if($key == $current_child->localName) {
                    if(array_key_exists("maxOccurs", $value) && ($value["maxOccurs"] == "unbounded" || $value["maxOccurs"] > 1)){
                        $i = 0;
                        $parse_tree[$key] = array();
                        while($current_child !== NULL && $current_child->localName == $key)
                        {
                            if($current_child->firstChild)
                            {
                                $converted_value =  wsf_wsdl_util_convert_value($value[WSF_TYPE_REP], $current_child->firstChild->wholeText);
                            }
                            else
                            {
                                if(!isset($value["nillable"]))
                                {
                                    error_log("Non nillable element". $key ."is nil. \n");
                                }
                                $converted_value = "";
                            }
                            $parse_tree[$key][$i++] = $converted_value;
                            $current_child = $current_child->nextSibling;
                            while($current_child != NULL && $current_child->nodeType != XML_ELEMENT_NODE)
                            {
                                $current_child = $current_child->nextSibling;
                            }
                        }
                    }
                    else
                    {
                        if($current_child->firstChild)
                        {
                            $converted_value =  wsf_wsdl_util_convert_value($value[WSF_TYPE_REP], $current_child->firstChild->wholeText);
                        }
                        else
                        {
                            if(!isset($value["nillable"]))
                            {
                                error_log("Non nillable element". $key ."is nil. \n");
                            }
                            $converted_value = "";
                        }
                        $parse_tree[$key] = $converted_value;
                        $current_child = $current_child->nextSibling;
                    }
                }
                else
                {
                    if($value["minOccurs"] && $value["minOccurs"] == 0){
                        // so this if fine
                    }
                    else{
                       error_log("minOccurs!=0 element ". $key ." doesn't exist.\n");
                    }
                }
            }
            else
            {
                if($key == $current_child->localName) {
                    if(array_key_exists("maxOccurs", $value) && ($value["maxOccurs"] == "unbounded" || $value["maxOccurs"] > 1)){
                        $i = 0;
                        $parse_tree[$key] = array();
                        while($current_child !== NULL && $current_child->localName == $key)
                        {
                            if($current_child->firstChild)
                            {
                                if($value[WSF_HAS_SIG_CHILDS] === TRUE)
                                {
                                    $converted_value = wsf_parse_payload_for_array($current_child, $value);
                                }
                                else
                                {
                                    $converted_value = wsf_parse_payload_for_unknown_array($current_child);
                                }
                            }
                            else
                            {
                                if(!isset($value["nillable"]))
                                {
                                    error_log("Non nillable element". $key ."is nil. \n");
                                }
                                $converted_value = "";
                            }
                            $parse_tree[$key][$i++] = $converted_value;
                            $current_child = $current_child->nextSibling;
                        }
                    }
                    else
                    {
                        if($current_child->firstChild)
                        {
                            if($value[WSF_HAS_SIG_CHILDS] === TRUE)
                            {
                                $converted_value = wsf_parse_payload_for_array($current_child, $value);
                            }
                            else
                            {
                                $converted_value = wsf_parse_payload_for_unknown_array($current_child);
                            }
                        }
                        else
                        {
                            if(!isset($value["nillable"]))
                            {
                                error_log("Non nillable element". $key ."is nil. \n");
                            }
                            $converted_value = "";
                        }
                        $parse_tree[$key] = $converted_value;
                        $current_child = $current_child->nextSibling;
                    }
                }
                else
                {
                    if($value["minOccurs"] && $value["minOccurs"] == 0){
                        // so this if fine
                    }
                    else{
                       error_log("minOccurs!=0 element ". $key ." doesn't exist.\n");
                    }
                }
            }
        }else if($key == WSF_TYPE_REP && is_xsd_type($value)){
            if ($payload != NULL && $payload->nodeType != XML_TEXT_NODE)
            {
                $original_value = $payload->nodeValue;
                $converted_value = wsf_wsdl_util_convert_value($value, $original_value);

                return $converted_value;
            }
        }
    }

    return $parse_tree;
}


/**
 * parse payload and return an object hierarchy
 * @param $payload 
 * @param $parameter_struct
 * @return the parsed result objects
 */
function wsf_parse_payload_for_class_map(DomNode $payload, array $parameter_struct, $element_name, $class_map)
{
    $parse_tree = NULL;
    if(is_array($class_map) && array_key_exists($element_name, $class_map))
    {
        $class_name = $class_map[$element_name];
    }
    if(!isset($class_name) || $class_name == NULL)
    {
        $class_name = $element_name;
    }
    
    while($payload != NULL && $payload->nodeType != XML_ELEMENT_NODE)
    {
        $payload = $payload->nextSibling;
    }
    if($payload == NULL) {
        return NULL;
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

    if($object == NULL){
        return NULL;
    }

    /* for now, we only support complex type sequences */
    //$child_nodes = $payload->childNodes;
    $current_child = $payload->firstChild;
    while($current_child != NULL && $current_child->nodeType != XML_ELEMENT_NODE)
    {
        $current_child = $current_child->nextSibling;
    }
    if($current_child == NULL)
    {
        /* it still can be a text node */
        $current_child = $payload->firstChild;
        if($current_child != NULL && $current_child->nodeType == XML_TEXT_NODE)
        {
            return $current_child->nodeValue;
        }
        /* otherwise it is a NULL */
        return NULL;
    }

    foreach($parameter_struct as $key => $value)
    {
        if(is_array($value))
        {
            if(array_key_exists("class_map_name", $value) && $value["class_map_name"] == "anyType")
            {
                $tag_name = $current_child->localName;
                if($key == $tag_name)
                {
                  $converted_value = wsf_parse_payload_for_unknown_class_map($current_child, "anyType_for".$key, $class_map);
                  $parse_tree[$key] = $converted_value;
                  continue;
                }
            }
            if(isset($value[WSF_TYPE_REP]) && $value[WSF_TYPE_REP]){
                if($key == $current_child->localName) {
                    if(array_key_exists("maxOccurs", $value) && ($value["maxOccurs"] == "unbounded" || $value["maxOccurs"] > 1)){
                        $i = 0;
                        $tmp_array = array();
                        while($current_child !== NULL && $current_child->localName == $key)
                        {
                            if($current_child->firstChild)
                            {
                                $converted_value =  wsf_wsdl_util_convert_value($value[WSF_TYPE_REP], $current_child->firstChild->wholeText);
                            }
                            else
                            {
                                if(!isset($value["nillable"]))
                                {
                                    error_log("Non nillable element". $key ."is nil. \n");
                                }
                                $converted_value = "";
                            }
                            $tmp_array[$i++] = $converted_value;
                            $current_child = $current_child->nextSibling;
                        }
                        $object->$key = $tmp_array;
                    }
                    else
                    {
                        if($current_child->firstChild)
                        {
                            $converted_value =  wsf_wsdl_util_convert_value($value[WSF_TYPE_REP], $current_child->firstChild->wholeText);
                        }
                        else
                        {
                            if(!isset($value["nillable"]))
                            {
                                error_log("Non nillable element". $key ."is nil. \n");
                            }
                            $converted_value = "";
                        }
                        $object->$key = $converted_value;
                        $current_child = $current_child->nextSibling;
                        while($current_child != NULL && $current_child->nodeType != XML_ELEMENT_NODE)
                        {
                            $current_child = $current_child->nextSibling;
                        }
                    }
                }
                else
                {
                    if($value["minOccurs"] && $value["minOccurs"] == 0){
                        // so this if fine
                    }
                    else{
                       error_log(" minOccurs!=0 element". $key ." doesn't exist.\n");
                    }
                }
            }
            else
            {
                $class_map_name = $value["class_map_name"];

                if($key == $current_child->localName) {
                    if(array_key_exists("maxOccurs", $value) && ($value["maxOccurs"] == "unbounded" || $value["maxOccurs"] > 1)){
                        $i = 0;
                        $tmp_array = array();
                        while($current_child !== NULL && $current_child->localName == $key)
                        {
                            if($current_child->firstChild)
                            {
                                if($value[WSF_HAS_SIG_CHILDS] === TRUE)
                                {
                                    $converted_value = wsf_parse_payload_for_class_map($current_child, $value, $class_map_name, $class_map);
                                }
                                else
                                {
                                    $converted_value = wsf_parse_payload_for_unknown_class_map($current_child, $class_map_name, $class_map);
                                }
                            }
                            else
                            {
                                if(!isset($value["nillable"]))
                                {
                                    error_log("Non nillable element". $key ."is nil. \n");
                                }
                                $converted_value = "";
                            }
                            $tmp_array[$i++] = $converted_value;
                            $current_child = $current_child->nextSibling;
                        }
                        $object->$key = $tmp_array;
                    }
                    else
                    {
                        if($current_child->firstChild)
                        {
                            if($value[WSF_HAS_SIG_CHILDS] === TRUE)
                            {
                                $converted_value = wsf_parse_payload_for_class_map($current_child, $value, $class_map_name, $class_map);
                            }
                            else
                            {
                                $converted_value = wsf_parse_payload_for_unknown_class_map($current_child, $class_map_name, $class_map);
                            }
                        }
                        else
                        {
                            if(!isset($value["nillable"]))
                            {
                                error_log("Non nillable element". $key ."is nil. \n");
                            }
                            $converted_value = "";
                        }
                        $object->$key = $converted_value;
                        $current_child = $current_child->nextSibling;
                    }
                }
                else
                {
                    if($value["minOccurs"] && $value["minOccurs"] == 0){
                        // so this if fine
                    }
                    else{
                       error_log(" minOccurs!=0 element". $key ." doesn't exist.\n");
                    }
                }
            }
        }
    }

    return $object;
}

/**
 * parse payload and return an object of paramerters for used in serverside
 * @param $payload 
 * @param $parameter_struct
 * @return
 */
function wsf_parse_payload_for_service_class_map(DomNode $payload, array $parameter_struct, $element_name, $class_map)
{
    $parse_tree = array();
    
    /* for now, we only support complex type sequences */
    //$child_nodes = $payload->childNodes;
    $current_child = $payload->firstChild;
    foreach($parameter_struct as $key => $value)
    {   
        if(is_array($value))
        {
            if(isset($value[WSF_TYPE_REP]) && $value[WSF_TYPE_REP]){
                if($key == $current_child->localName) {
                    if(array_key_exists("maxOccurs", $value) && ($value["maxOccurs"] == "unbounded" || $value["maxOccurs"] > 1)){
                        $i = 0;
                        $parse_tree[$key] = array();
                        while($current_child->localName == $key)
                        {
                            if($current_child->firstChild)
                            {
                                $converted_value =  wsf_wsdl_util_convert_value($value[WSF_TYPE_REP], $current_child->firstChild->wholeText);
                            }
                            else
                            {
                                if(!isset($value["nillable"]))
                                {
                                    error_log("Non nillable element". $key ."is nil. \n");
                                }
                                $converted_value = "";
                            }
                            $parse_tree[$key][$i++] = $converted_value;
                            $current_child = $current_child->nextSibling;
                        }
                    }
                    else
                    {
                        if($current_child->firstChild)
                        {
                            $converted_value =  wsf_wsdl_util_convert_value($value[WSF_TYPE_REP], $current_child->firstChild->wholeText);
                        }
                        else
                        {
                            if(!isset($value["nillable"]))
                            {
                                error_log("Non nillable element". $key ."is nil. \n");
                            }
                            $converted_value = "";
                        }
                        $parse_tree[$key] = $converted_value;
                        $current_child = $current_child->nextSibling;
                    }
                }
                else
                {
                    if($value["minOccurs"] && $value["minOccurs"] == 0){
                        // so this if fine
                    }
                    else{
                       error_log(" minOccurs!=0 element". $key ." doesn't exist.\n");
                    }
                }
            }
            else
            {
                $class_map_name = $value["class_map_name"];

                if($key == $current_child->localName) {
                    if(array_key_exists("maxOccurs", $value) && ($value["maxOccurs"] == "unbounded" || $value["maxOccurs"] > 1)){
                        $i = 0;
                        $parse_tree[$key] = array();
                        while($current_child->localName == $key)
                        {
                            if($current_child->firstChild)
                            {
                                if($value[WSF_HAS_SIG_CHILDS] === TRUE)
                                {
                                    $converted_value = wsf_parse_payload_for_class_map($current_child, $value, $class_map_name, $class_map);
                                }
                                else
                                {
                                    $converted_value = wsf_parse_payload_for_unknown_class_map($current_child, $class_map_name, $class_map);
                                }
                            }
                            else
                            {
                                if(!isset($value["nillable"]))
                                {
                                    error_log("Non nillable element". $key ."is nil. \n");
                                }
                                $converted_value = "";
                            }
                            $parse_tree[$key][$i++] = $converted_value;
                            $current_child = $current_child->nextSibling;
                        }
                    }
                    else
                    {
                        if($current_child->firstChild)
                        {
                            if($value[WSF_HAS_SIG_CHILDS] === TRUE)
                            {
                                $converted_value = wsf_parse_payload_for_class_map($current_child, $value, $class_map_name, $class_map);
                            }
                            else
                            {
                                $converted_value = wsf_parse_payload_for_unknown_class_map($current_child, $class_map_name, $class_map);
                            }
                        }
                        else
                        {
                            if(!isset($value["nillable"]))
                            {
                                error_log("Non nillable element". $key ."is nil. \n");
                            }
                            $converted_value = "";
                        }
                        $parse_tree[$key] = $converted_value;
                        $current_child = $current_child->nextSibling;
                    }
                }
                else
                {
                    if($value["minOccurs"] && $value["minOccurs"] == 0){
                        // so this if fine
                    }
                    else{
                       error_log(" minOccurs!=0 element". $key ." doesn't exist.\n");
                    }
                }
            }
        }
    }

    return $parse_tree;
}

/**
 * wsf_parse_payload_for_unknown_array
 * @param $current_node node to parse
 * @returns array of parsed data
 */
function wsf_parse_payload_for_unknown_array($current_node)
{
    $param_child = array();

    foreach($current_node->childNodes as $child)
    {
        if($child->nodeType == XML_TEXT_NODE)
        {
            $node_value = $child->nodeValue;
            return $node_value;
        }


        $name = $child->tagName;
        $needle = strpos($name, ':');

        if($needle !== FALSE)
        {
            $name = substr($name, $needle + 1);
        }

        if($child->nodeType ==  XML_ELEMENT_NODE)
        {
            $node_value = wsf_parse_payload_for_unknown_array($child);
        }
        else
        {
            $node_value = NULL;
        }

        if($node_value !== NULL)
        {
            if($param_child[$name] === NULL)
            {
                $param_child[$name] = $node_value;
            }
            else
            {
                if(is_array($param_child[$name]) && !wsf_is_map($param_child[$name]))
                {
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
function wsf_parse_payload_for_unknown_class_map($current_node, $element_name, $class_map)
{
    $class_name = NULL;
    if(is_array($class_map) && array_key_exists($element_name, $class_map))
    {
        $class_name = $class_map[$element_name];
    }
    if(!isset($class_name) || $class_name == NULL)
    {
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

    if($object == NULL){
        return NULL;
    }


    foreach($current_node->childNodes as $child)
    {
        if($child->nodeType == XML_TEXT_NODE)
        {
            $node_value = $child->nodeValue;
            return $node_value;
        }


        $name = $child->tagName;
        $needle = strpos($name, ':');

        if($needle !== FALSE)
        {
            $name = substr($name, $needle + 1);
        }

        if($child->nodeType ==  XML_ELEMENT_NODE)
        {
            $node_value = wsf_parse_payload_for_unknown_class_map($child, $name, $class_map);
        }
        else
        {
            $node_value = NULL;
        }

        if($node_value !== NULL)
        {
            if($object->$name === NULL)
            {
                $object->$name = $node_value;
            }
            else
            {
                if(is_array($object->$name) && !wsf_is_map($object->$name))
                {
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


?>

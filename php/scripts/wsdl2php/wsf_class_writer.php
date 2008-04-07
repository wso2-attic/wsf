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

// array to keep track of classes that are already written 
$written_classes = array ();

// array to hold information on operations to help generate demo code 
$operations = array ();

$actions = NULL;

/**
 * Function to write sub classes.  
 * $nodes array of nodes corresponding to the classes to be written
 * returns code segment corresponding to sub classes as a string
 */
function wsf_write_sub_classes($nodes) {
    global $written_classes;
    $code = "";
    foreach ($nodes as $node) {
        if ($node) {

            if ($node->hasAttributes()) {
                // Wrapper element found
                $attrs = $node->attributes;
                $type_name = $attrs->getNamedItem(WSF_TYPE)->value;

                // array to hold child elements corresponding to sub classes
                $child_array = array ();

                // check if the class was already written 
                if ($written_classes[$type_name] == true)
                    continue;

                $code = $code . "class " . $type_name . " { \n";
                $written_classes[$type_name] = true;

                $child_array = array();
                $code .= wsf_write_content_model($node, $child_array);

                $code = $code . "}\n\n";
                // done writing the current class, now go and write the sub classes
                $code = $code . wsf_write_sub_classes($child_array);
            }
            // TODO: What about arrays?
        }
    }
    return $code;
}

function wsf_write_content_model($parent_node, &$child_array) {
    $code = "";
    $param_child_list = $parent_node->childNodes;
    if($parent_node->attributes) {
        $content_model = $parent_node->attributes->getNamedItem(WSF_CONTENT_MODEL)->value;
    }
    if($content_model == "choice") {
        //just start a comment
        $code .= "\n";
        $code .= "    // You may set only one from the following set\n";
        $code .= "    // ---------------Start Choice----------------\n";
    }
    foreach ($param_child_list as $param_child) {
        if($param_child->localName == WSF_PARAM) {
            $param_attr = $param_child->attributes;
            $param_name = $param_attr->getNamedItem(WSF_NAME)->value;
            $param_type = $param_attr->getNamedItem(WSF_TYPE)->value;

            if($param_child->getAttribute("simple") == "yes"){
                $code .= wsf_comment_on_simple_type($param_child, $ele_name, $param_type);
            }

            // check if the attribute is of array type
            $max_occurs = $param_attr->getNamedItem(WSF_MAX_OCCURS)->value;
            $array_type = "";
            if ($max_occurs != null && $max_occurs != "1")
                $array_type = "array of ";

            // write public members of the class 
            $code = $code . "    public $" . $param_name . "; // " . $array_type . $param_type . "\n";
            // if it is not s simple type, we have to keep track of it to write a corresponding class
            if ($param_attr->getNamedItem(WSF_WSDL_SIMPLE)->value == 'no')
                $child_array[] = $param_child;
        }
        else if($param_child->localName == WSF_INNER_CONTENT) {
            // in place of inner content recursively call the wsf_write_content_model
            $code .= wsf_write_content_model($param_child, $child_array);
        }
    }
    if($content_model == "choice") {
        //just start a comment
        $code .= "    // ----------------End Choice---------------\n\n";
    }
    return $code;
}

/**
 * Function to write classes. Does the WSDL to PHP conversion using a 'sig model'.  
 * $wsdl_location location of the WSDL
 * returns code segment corresponding to classes as a string
 */
function wsf_wsdl2php($wsdl_location) {

    require_once ('dynamic_invocation/wsf_wsdl_consts.php');
    require_once ('dynamic_invocation/wsf_wsdl_util.php');

    global $written_classes;
    global $operations;
    global $actions;

    $code = "";

    $wsdl_dom = new DomDocument();
    $sig_model_dom = new DOMDocument();

    $xslt_location = "./xslt/";

    $sig_model_dom->preserveWhiteSpace = false;
    $wsdl_dom->preserveWhiteSpace = false;

    if (!$wsdl_location) {
        echo "WSDL is not found";
        return NULL;
    }
    $is_multiple_interfaces = FALSE;

    // load WSDL as DOM
    if (!$wsdl_dom->load($wsdl_location)) {
        echo "WSDL could not be loaded.";
        return NULL;
    }

    $wsdl_dom->preserveWhiteSpace = false;

    // changing code for processing mutiple port types in wsdl 1.1 
    $is_multiple_interfaces = wsf_is_mutiple_port_types($wsdl_dom);

    if ($is_multiple_interfaces == FALSE) {
        $wsdl_dom = wsf_get_wsdl_dom($wsdl_dom, $xslt_location);
        if (!$wsdl_dom) {
            echo "Error creating WSDL DOM document";
            return NULL;
        }
        $sig_model_dom = wsf_get_sig_model_dom($wsdl_dom, $xslt_location);
    } else {
        $wsdl_dom = wsf_get_wsdl_dom($wsdl_dom, $xslt_location);
        $sig_model_dom = wsf_process_multiple_interfaces($wsdl_dom, $sig_model_dom, $xslt_location);
    }

    if (!$sig_model_dom) {
        echo "Error creating intermediate service operations signature model";
        return NULL;
    }


    // get the list of operations
    $op_nodes = $sig_model_dom->getElementsByTagName(WSF_OPERATION);

    // process each operation
    foreach ($op_nodes as $op_node) {

        // get operation name 
        $op_attr = $op_node->attributes;
        $op_name = $op_attr->getNamedItem(WSF_NAME)->value;

        if ($operations[$op_name] == NULL) { // it operation is already found in an earlier parse, should not re-set it
            $operations[$op_name] = array ();
            $operations[$op_name][WSF_CLIENT] = "";
            $operations[$op_name][WSF_SERVICE] = "";
        }

        // get the nodes describing operation characteristics 
        $op_child_list = $op_node->childNodes;
    
        foreach ($op_child_list as $op_child) {
            // process the signature node
            if ($op_child->localName == WSF_SIGNATURE) {
                // get the nodes representing operation parameters and return types within signature
                $param_list = $op_child->childNodes;
                foreach ($param_list as $param_node) {
                    if ($param_node) {
                        // look for params and returns nodes 
                        if ($param_node->localName == WSF_PARAMS || $param_node->localName == WSF_RETURNS) {
                            if ($param_node->hasAttributes()) {
                                // Wrapper element 
                                $params_attr = $param_node->attributes;

                                // get wrapper element name, this is going to be the class name
                                $ele_name = $params_attr->getNamedItem(WSF_WRAPPER_ELEMENT)->value;
            
                                // array to hold child elements corresponding to sub classes
                                $child_array = array ();

                                // check if the class is already written
                                if ($written_classes[$ele_name] == TRUE)
                                    continue;

                                // start writing class    
                                $code = $code . "class " . $ele_name . " { \n";
                                $written_classes[$ele_name] = TRUE;

                                // prepare the demo code that the user could use for testing client. 
                                // shows how to create the input and receive the response

                                if ($param_node->localName == WSF_PARAMS) {
                                    $operations[$op_name][WSF_CLIENT] = $operations[$op_name][WSF_CLIENT] . "    \$input = new $ele_name();\n    //TODO: fill in the class fields of \$input to match your business logic\n";
                                    $operations[$op_name][WSF_SERVICE] = $operations[$op_name][WSF_SERVICE] . "function " . $op_name . "(\$input) {\n    // TODO: fill in the business logic\n    // NOTE: \$input is of type $ele_name\n";
                                }
                                if ($param_node->localName == WSF_RETURNS) {
                                    $operations[$op_name][WSF_CLIENT] = $operations[$op_name][WSF_CLIENT] . "\n    // call the operation\n    \$response = \$proxy->" . $op_node->attributes->getNamedItem('name')->value . "(\$input);\n    //TODO: Implement business logic to consume \$response, which is of type $ele_name\n";
                                    $operations[$op_name][WSF_SERVICE] = $operations[$op_name][WSF_SERVICE] . "    // NOTE: should return an object of type $ele_name\n}\n\n";
                                }

                                $child_array = array();
                                $code .= wsf_write_content_model($param_node, $child_array);
                                
                                $code = $code . "}\n\n";
                                // done writing the current class, now go and write the sub classes
                                $code = $code . wsf_write_sub_classes($child_array);
                            } else {
                                // TODO: No wrapper element, there won't be any class generated for this 

                                $child_array = array ();
                                $param_child_list = $param_node->childNodes;

                                foreach ($param_child_list as $param_child) {
                                    $param_attr = $param_child->attributes;
                                    $ele_name = $param_attr->getNamedItem(WSF_NAME)->value;
                                    $param_type = $param_attr->getNamedItem(WSF_TYPE)->value;


                                    // prepare the demo code that the user could use for testing client. 
                                    // shows how to create the input and receive the response

                                    if ($param_node->localName == WSF_PARAMS) {
                                        $operations[$op_name][WSF_CLIENT] = $operations[$op_name][WSF_CLIENT] . "    //TODO: fill \$input with (data type: {$param_type}) data to match your business logic\n";
                                        if($param_child->getAttribute("simple") == "yes"){
                                            $simple_type_comment = wsf_comment_on_simple_type($param_child, "\$input", $param_type);
                                            $operations[$op_name][WSF_CLIENT] = $operations[$op_name][WSF_CLIENT] . $simple_type_comment."\n";
                                        }
                                        $operations[$op_name][WSF_SERVICE] = $operations[$op_name][WSF_SERVICE] . "function " . $op_name . "(\$input) {\n    // TODO: fill in the business logic\n    // NOTE: \$input is of type {$param_type}\n";
                                        if($param_child->getAttribute("simple") == "yes"){
                                            $simple_type_comment = wsf_comment_on_simple_type($param_child, "\$input", $param_type);
                                            $operations[$op_name][WSF_SERVICE] = $operations[$op_name][WSF_SERVICE] . $simple_type_comment."\n";
                                        }

                                    }
                                    if ($param_node->localName == WSF_RETURNS) {
                                        $operations[$op_name][WSF_CLIENT] = $operations[$op_name][WSF_CLIENT] . "\n    // call the operation\n    \$response = \$proxy->" . $op_node->attributes->getNamedItem('name')->value . "(\$input);\n    //TODO: Implement business logic to consume \$response, which is of type {$param_type}\n";
                                        $operations[$op_name][WSF_SERVICE] = $operations[$op_name][WSF_SERVICE] . "    // NOTE: should return an object of (type: {$param_type})\n}\n\n";
                                    }

                                }
                            }
                        }
                    }
                }
            }
            else if($op_child->localName == WSF_W2P_BINDING_DETAILS) {
                /* action is default to wsa waction */
                $action = $op_child->getAttribute('wsawaction'); 
                if($action == NULL)
                {
                    $action = $op_child->getAttribute('soapaction');
                }

                if($action != NULL)
                {
                    /* we feeding the actions to the global variable */
                    if($actions == NULL)
                    {
                        $actions = array();
                    }
                
                    $actions[$action] = $op_name;
                }
            }
        }
    }
    return $code;
}

function wsf_comment_on_simple_type($param_node, $param_name, $param_type)
{
    $comment = "";
    if($param_node->hasChildNodes()){
        $comment = "    //NOTE: ${param_name} should follow the following restrictions\n";
    }
    else{
        return "";
    }

    $i = 0;
    $restrictions = $param_node->childNodes;
    // first iterate through the enumerations
    foreach($restrictions as $restriction){
        if($restriction->nodeName == "enumeration"){
            if($i == 0){
                $comment .= "    /* You can have one of the following value\n";
                $i ++;
            }
            $value = $restriction->getAttribute("value");
            $comment .= "     * {$value}\n";
        }
    }

    if($i != 0){
        $comment .= "     */\n";
    }

    $min_value = -1;
    $min_inclusive = FALSE;
    $max_value = -1;
    $max_inclusive = FALSE;


    // first iterate through the max/minInclusives/Exclusives
    foreach($restrictions as $restriction){
        if($restriction->nodeName == "minInclusive"){
            $value =  $restriction->getAttribute("value");
            if($min_value == -1){
                $min_value = $value;
                $min_inclusive = TRUE;
            }
            else{
                $min_value = ($min_value -1> $value)?$value:$min_value;
                $min_inclusive = TRUE;
            }
        }
        else if($restriction->nodeName == "maxInclusive"){
            $value = $restriction->getAttribute("value");
            if($max_value == -1){
                $max_value = $value;
                $max_inclusive = TRUE;
            }
            else{
                $max_value = ($max_value +1< $value)?$value:$max_value;
                $max_inclusive = TRUE;
            }
        }
        if($restriction->nodeName == "minExclusive"){
            $value =  $restriction->getAttribute("value");
            if($min_value == -1){
                $min_value = $value;
                $min_inclusive = FALSE;
            }
            else{
                $min_value = ($min_value > $value)?$value:$min_value;
                $min_inclusive = FALSE;
            }
        }
        else if($restriction->nodeName == "maxExclusive"){
            $value = $restriction->getAttribute("value");
            if($max_value == -1){
                $max_value = $value;
                $max_inclusive = FALSE;
            }
            else{
                $max_value = ($max_value < $value)?$value:$max_value;
                $max_inclusive = FALSE;
            }
        }
    }

    if($min_value == -1 && $max_value == -1){
        // just skip it
    }
    else
    {
        //print out the max/min information
        $comment .= "    /* Your value should be \n";
        if($min_value != -1){
            $comment .= "       Greater than ";
            if($min_inclusive){
                $comment .= "or equal to ";
            }
            $comment .= $min_value."\n";
        }
        if($max_value != -1){
            $comment .= "       Less than ";
            if($max_inclusive){
                $comment .= "or equal to ";
            }
            $comment .= $max_value."\n";
        }
        $comment .= "     */\n";
    }
  
    $min_len = -1;
    $max_len = -1;

    // first iterate through the max/minInclusives/Exclusives
    foreach($restrictions as $restriction){
        if($restriction->nodeName == "minLength"){
            $len =  $restriction->getAttribute("value");
            if($min_len == -1){
                $min_len = $len;
            }
            else{
                $min_len = ($min_len > $len)?$len:$min_len;
            }
        }
        else if($restriction->nodeName == "maxLength"){
            $len = $restriction->getAttribute("value");
            if($max_len == -1){
                $max_len = $len;
            }
            else{
                $max_len = ($max_len < $len)?$len:$max_len;
            }
        }
    }

    if($min_len == -1 && $max_len == -1){
        // just skip it
    }
    else
    {
        //print out the max/min information
        $comment .= "    /* Your length of the value should be \n";
        if($min_len != -1){
            $comment .= "       Greater than ";
            $comment .= $min_len."\n";
        }
        if($max_len != -1){
            $comment .= "       Less than ";
            $comment .= $max_len."\n";
        }
        $comment .= "     */";
    }
  
    return $comment;
}
?>

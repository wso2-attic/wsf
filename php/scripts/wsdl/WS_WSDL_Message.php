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
 * This class generates message elements in WSDL
 */

class WS_WSDL_Message
{
    public $operations;
    private $fun_mapping;
    private $classmap;
    /*
     * The constructor of the WS_Message class
     * @param Array $operationsArray Array of operation in the service
     * @param Array $simpleTypeArray type mapping table 
     */

    function __construct($operationsArray, $ops_to_functions, $classmap)
    {
        $this->operations = $operationsArray;
        $this->fun_mapping = $ops_to_functions;
        $this->classmap = $classmap;
    }

    /**
     * Function that creates Message elements for WSDL1.1 in doc-lit style
     * @param DomDocument $svr_name DomDocument element of the wsdl  document
     * @param DomElement $svr_root service dom element
     * @param array $msg_ele_names_info 
        "op =>  Array
                (
                    [In] => Array
                        (
                            [matrix_add] => Array
                                (
                                    [type] => MatrixAdd
                                    [array] =>
                                    [object] => object
                                )
                        )
                    [Out] => Array
                        (
                            [matrix_add_response] => Array
                                (
                                    [type] => MatrixAddResponse
                                    [array] =>
                                    [object] => object
                                )
                        )
                )
     */


    public function createDocLitMessage(DomDocument $msg_doc, DomElement $msg_root, $msg_ele_names_info)
    {
        $attr_name_to_postfix_map = array(WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME => WS_WSDL_Const::WS_WSDL_OPERTION_INPUT_TAG,
                                         WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME => WS_WSDL_Const::WS_WSDL_OPERTION_OUTPUT_TAG);
        
        foreach($this->operations as $name => $op_params)
        {
            // in only flag
            $in_only = !array_key_exists(WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME, $msg_ele_names_info[$name]) ||
                        $msg_ele_names_info[$name][WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME] == NULL;

            if($in_only) {
                $mep_patterns = array(WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME);
            }
            else {
                $mep_patterns = array(WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME,
                          WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME);
            }
            foreach($mep_patterns as $type)
            {

                // message element flag
                $msg_ele = $msg_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                WS_WSDL_Const::WS_WSDL_MESSAGE_ATTR_NAME);
                foreach($this->fun_mapping as $key => $value) {
                    if($value == $name) {
                        $msg_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                          "$key".ucfirst($attr_name_to_postfix_map[$type]));
                    }
                }
                $part = $msg_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                  WS_WSDL_Const::WS_WSDL_PART_ATTR_NAME);
                $part->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                    WS_WSDL_Const::WS_WSDL_PARAMETERS_ATTR_NAME);

                if (ucfirst(WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME) == ucfirst($type))
                {
                    foreach($this->fun_mapping as $key => $value) {
                        if($value == $name) {
                            if($this->classmap) {
                                $part->setAttribute(WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME,
                                                $msg_ele_names_info[$name][WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME]);
                            }
                            else {
                                $part->setAttribute(WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME,
                                               WS_WSDL_Const::WS_WSDL_DEFAULT_SCHEMA_ATTR_NAME.":". $key);
                            }
                        }
                    }
                }
                if (ucfirst(WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME) == ucfirst($type))
                {
                    foreach($this->fun_mapping as $key => $value){
                        if($value == $name) {
                            if($this->classmap) {
                                $part->setAttribute(WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME,
                                               $msg_ele_names_info[$name][WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME]);
                            }
                            else {
                                $part->setAttribute(WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME,
                                                WS_WSDL_Const::WS_WSDL_DEFAULT_SCHEMA_ATTR_NAME.":".$key.WS_WSDL_Const::WS_WSDL_RESPONSE_ATTR_NAME);
                            }
                        }
                    }
                }

                $msg_ele->appendChild($part);

                $msg_root->appendChild($msg_ele);
            }
        }
    }

    /**
     * Function that creates Message elements for WSDL1.1 in rpc style
     * @param DomDocument $svr_name DomDocument element of the wsdl  document
     * @param DomElement $svr_root service dom element
     */

    public function createRPCMessage(DomDocument $msg_doc, DomElement $msg_root, $class_to_prefix, $msg_ele_names_info)
    {
        $attr_name_to_postfix_map = array(WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME => WS_WSDL_Const::WS_WSDL_OPERTION_INPUT_TAG,
                                         WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME => WS_WSDL_Const::WS_WSDL_OPERTION_OUTPUT_TAG);
        foreach($this->operations as $op_name => $op_params)
        {
            $in_only = !array_key_exists(WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME, $msg_ele_names_info[$op_name]) ||
                        $msg_ele_names_info[$op_name][WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME] == NULL;
            if($in_only) {
                $mep_patterns = array(WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME);
            }
            else {
                $mep_patterns = array(WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME,
                          WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME);
            }
            foreach($mep_patterns as $in_or_out) {
                $op_params3 = $op_params[$in_or_out];
                $el = $msg_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                WS_WSDL_Const::WS_WSDL_MESSAGE_ATTR_NAME);
                foreach($this->fun_mapping as $key => $value) {
                    if ($op_name == $value) {
                        $el->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                          "$key".ucfirst($attr_name_to_postfix_map[$in_or_out]));
                    }
                }
                if($in_or_out == WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME)
                {
                    foreach($op_params3 as $name3 => $op_params4)
                    {
                        $part = $msg_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_PART_ATTR_NAME);
                        foreach ($op_params4 as $name4 => $param5)
                        {
                            if ($name4 == WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME)
                                $part->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                                    $param5);
                            if ($name4 == WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME)
                            {
                                $xsd_type = $param5;
                                if($op_params4["object"] == "object")
                                {
                                    $prefix = $class_to_prefix[$xsd_type];
                                    $part->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME,
                                                    $prefix.":".$param5);
                                }
                                else
                                {
                                    $part->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME,
                                                    WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$param5);
                                }
                            } 
                            $el->appendChild($part);

                        }
                    }
                }
                if($in_or_out == WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME)
                {
                    foreach($op_params3 as $name3 => $op_params4)
                    {
                        $part = $msg_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_PART_ATTR_NAME);
                        foreach ($op_params4 as $name4 => $param5)
                        {
                            if ($name4 == WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME)
                                $part->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                                    $param5);
                            if ($name4 == WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME)
                            {
                                $xsd_type = $param5;
                                if($op_params4["object"] == "object")
                                {
                                    $prefix = $class_to_prefix[$xsd_type];
                                    $part->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME,
                                                    $prefix.":".$param5);
                                }
                                else
                                {
                                    $part->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME,
                                                    WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$param5);
                                }
                            }
                            $el->appendChild($part);
                        }
                    }
                }
                $msg_root->appendChild($el);

            }

        }



    }


}

?>

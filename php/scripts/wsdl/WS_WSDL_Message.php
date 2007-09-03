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
 * This class generates message elements in WSDL
 */

class WS_WSDL_Message
{
    public $operations;
    private $simpleTypes;
    private $fun_mapping;
    /*
     * The constructor of the WS_Message class
     * @param Array $operationsArray Array of operation in the service
     * @param Array $simpleTypeArray type mapping table 
     */

    function __construct($operationsArray, $simpleTypeArray, $ops_to_functions)
    {
        $this->operations = $operationsArray;
        $this->simpleTypes = $simpleTypeArray;
        $this->fun_mapping = $ops_to_functions;
    }

    /**
     * Function that creates Message elements for WSDL1.1 in doc-lit style
     * @param DomDocument $svr_name DomDocument element of the wsdl  document
     * @param DomElement $svr_root service dom element
     */


    public function createDocLitMessage(DomDocument $msg_doc, DomElement $msg_root)
    {
        foreach(array(WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME,
                      WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME) as $type)
        {

            foreach($this->operations as $name => $params)
            {
                $el = $msg_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                WS_WSDL_Const::WS_WSDL_MESSAGE_ATTR_NAME);
                foreach($this->fun_mapping as $key => $value){
                    if($value == $name)
                        $el->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                          "$key".ucfirst($type));
                }
                $part = $msg_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                  WS_WSDL_Const::WS_WSDL_PART_ATTR_NAME);
                $part->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                    WS_WSDL_Const::WS_WSDL_PARAMETERS_ATTR_NAME);

                if (ucfirst(WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME) == ucfirst($type))
                {
                    foreach($this->fun_mapping as $key => $value){
                        if($value == $name)
                            $part->setAttribute(WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME,
                                               WS_WSDL_COnst::WS_WSDL_DEFAULT_SCHEMA_ATTR_NAME.":". $key);
                    }
                }
                if (ucfirst(WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME) == ucfirst($type))
                {
                    foreach($this->fun_mapping as $key => $value){
                        if($value == $name)
                            $part->setAttribute(WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME,
                                                WS_WSDL_COnst::WS_WSDL_DEFAULT_SCHEMA_ATTR_NAME.":".$key.WS_WSDL_Const::WS_WSDL_RESPONSE_ATTR_NAME);
                    }
                }

                $el->appendChild($part);


                $msg_root->appendChild($el);
            }
        }
    }

    /**
     * Function that creates Message elements for WSDL1.1 in rpc style
     * @param DomDocument $svr_name DomDocument element of the wsdl  document
     * @param DomElement $svr_root service dom element
     */

    public function createRPCMessage(DomDocument $msg_doc, DomElement $msg_root)
    {

        foreach($this->operations as $name1 => $params)
        {
            foreach($params as $name2 => $params3)
            {
                $el = $msg_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                WS_WSDL_Const::WS_WSDL_MESSAGE_ATTR_NAME);
                foreach($this->fun_mapping as $key => $value){
                    if ($name1 == $value)
                        $el->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                          "$key".ucfirst($name2));
                }
                if ($name2 == WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME)
                {
                    foreach($params3 as $name3 => $params4)
                    {
                        $part = $msg_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_PART_ATTR_NAME);
                        foreach ($params4 as $name4 => $param5)
                        {
                            if ($name4 == WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME)
                                $part->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                                    $param5);
                            if ($name4 == WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME)
                                $part->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME,
                                                    WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$param5);
                            $el->appendChild($part);

                        }
                    }
                }
                if ($name2 == WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME)
                {
                    foreach($params3 as $name3 => $params4)
                    {
                        $part = $msg_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_PART_ATTR_NAME);
                        foreach ($params4 as $name4 => $param5)
                        {
                            if ($name4 == WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME)
                                $part->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                                    $param5);
                            if ($name4 == WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME)
                                $part->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME,
                                                    WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$param5);
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

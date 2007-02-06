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

class WS_WsdlMessage
{
    public $operations;
    private $simpleTypes;

    /*
     * The constructor of the WS_Message class
     * @param Array $operationsArray Array of operation in the service
     * @param Array $simpleTypeArray type mapping table 
     */

    function __construct($operationsArray, $simpleTypeArray)
    {
        $this->operations = $operationsArray;
        $this->simpleTypes = $simpleTypeArray;
    }

    /**
     * Function that creates Message elements for WSDL1.1 in doc-lit style
     * @param DomDocument $svr_name DomDocument element of the wsdl  document
     * @param DomElement $svr_root service dom element
     */


    public function createDocLitMessage(DomDocument $msg_doc, DomElement $msg_root)
    {
        foreach(array(WS_WsdlConst::WS_WSDL_INPUT_ATTR_NAME,
                      WS_WsdlConst::WS_WSDL_OUT_ATTR_NAME) as $type)
        {

            foreach($this->operations as $name => $params)
            {
                $el = $msg_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
                                                WS_WsdlConst::WS_WSDL_MESSAGE_ATTR_NAME);
                $el->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME,
                                  "$name".ucfirst($type));

                $part = $msg_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
                                                  WS_WsdlConst::WS_WSDL_PART_ATTR_NAME);
                $part->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME,
                                    WS_WsdlConst::WS_WSDL_PARAMETERS_ATTR_NAME);

                if (ucfirst(WS_WsdlConst::WS_WSDL_INPUT_ATTR_NAME) == ucfirst($type))
                {
                    $part->setAttribute(WS_WsdlConst::WS_WSDL_ELEMENT_ATTR_NAME,
                                        $name);
                }
                if (ucfirst(WS_WsdlConst::WS_WSDL_OUTPUT_ATTR_NAME) == ucfirst($type))
                {
                    $part->setAttribute(WS_WsdlConst::WS_WSDL_ELEMENT_ATTR_NAME,
                                        $name.WS_WSDL_REPONSE_ATTR_NAME);
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
                $el = $msg_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
                                                WS_WsdlConst::WS_WSDL_MESSAGE_ATTR_NAME);
                $el->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME,
                                  "$name1".ucfirst($name2));
                if ($name2 == WS_WsdlConst::WS_WSDL_INPUT_ATTR_NAME)
                {
                    foreach($params3 as $name3 => $params4)
                    {
                        $part = $msg_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
                                                          WS_WsdlConst::WS_WSDL_PART_ATTR_NAME);
                        foreach ($params4 as $name4 => $param5)
                        {
                            if ($name4 == WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME)
                                $part->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME,
                                                    $param5);
                            if ($name4 == WS_WsdlConst::WS_WSDL_TYPE_ATTR_NAME)
                                $part->setAttribute(WS_WsdlConst::WS_WSDL_TYPE_ATTR_NAME,
                                                    $param5);
                            $el->appendChild($part);

                        }
                    }
                }
                if ($name2 == WS_WsdlConst::WS_WSDL_OUTPUT_ATTR_NAME)
                {
                    foreach($params3 as $name3 => $params4)
                    {
                        $part = $msg_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
                                                          WS_WsdlConst::WS_WSDL_PART_ATTR_NAME);
                        foreach ($params4 as $name4 => $param5)
                        {
                            if ($name4 == WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME)
                                $part->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME,
                                                    $param5);
                            if ($name4 == WS_WsdlConst::WS_WSDL_TYPE_ATTR_NAME)
                                $part->setAttribute(WS_WsdlConst::WS_WSDL_TYPE_ATTR_NAME,
                                                    $param5);
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
?>
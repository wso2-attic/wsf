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
 * This class generates the port type element in WSDL1.1
 */

class WS_WSDL_Port
{

    private $service_name;
    private $operations;
    private $fun_mapping;
    /**
     * The constructor of the class
     * @param string $service Name of the service
     * @param Array $array1 Array of operations defined in the service
     */
    function __construct($service, $array1, $ops_to_functions)
    {
        $this->service_name = $service;
        $this->operations = $array1;
        $this->fun_mapping = $ops_to_functions;
    }

    /**
     * Function that creates portType elements for WSDL1.1
     * @param DomDocument $port_doc DomDocument element of the wsdl document
     * @param DomElement $port_root service dom element
     */

    public function createPortType(DomDocument $port_doc, DomElement $port_root)
    {
        $port_el = $port_doc->createElementNS( WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                               WS_WSDL_Const::WS_WSDL_PORTTYPE_ATTR_NAME);
        $port_el->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                               $this->service_name);
        foreach($this->operations as $name => $params)
        {
            $operation = $port_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                    WS_WSDL_Const::WS_WSDL_OPERATION_ATTR_NAME);
            foreach ($this->fun_mapping as $key => $value){
                if ($value == $name)
                    $operation->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $key);
            }
            foreach(array(WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME, WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME)
                    as $type)
            {
                $sel = $port_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                  $type);
                foreach($this->fun_mapping as $key => $value){
                    if ($value == $name)
                        $sel->setAttribute(WS_WSDL_Const::WS_WSDL_MESSAGE_ATTR_NAME,
                                           "$key".ucfirst($type));
                }
                $operation->appendChild($sel);
            }
            $port_el->appendChild($operation);
        }
        $port_root->appendChild($port_el);
    }

}




?>

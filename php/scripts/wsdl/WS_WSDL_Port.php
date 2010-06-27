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
 * This class generates the port type element in WSDL1.1
 */

class WS_WSDL_Port
{

    private $service_name;
    private $operations;
    private $fun_mapping;
    private $use_wsa;
    private $r_actions;

    /**
     * The constructor of the class
     * @param string $service Name of the service
     * @param Array $array1 Array of operations defined in the service
     */
    function __construct($service, $array1, $ops_to_functions, $use_wsa, $r_actions)
    {
        $this->service_name = $service;
        $this->operations = $array1;
        $this->fun_mapping = $ops_to_functions;

        $this->use_wsa = $use_wsa;
        $this->r_actions = $r_actions;
    }

    /**
     * Function that creates portType elements for WSDL1.1
     * @param DomDocument $port_doc DomDocument element of the wsdl document
     * @param DomElement $port_root service dom element
     */

    public function createPortType(DomDocument $port_doc, DomElement $port_root)
    {
       $attr_name_to_postfix_map = array(WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME => WS_WSDL_Const::WS_WSDL_OPERTION_INPUT_TAG,
                                         WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME => WS_WSDL_Const::WS_WSDL_OPERTION_OUTPUT_TAG);
        $port_el = $port_doc->createElementNS( WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                               WS_WSDL_Const::WS_WSDL_PORTTYPE_ATTR_NAME);
        $port_el->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                               $this->service_name."PortType");
        foreach($this->operations as $name => $params)
        {
            $operation = $port_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                    WS_WSDL_Const::WS_WSDL_OPERATION_ATTR_NAME);
            foreach ($this->fun_mapping as $key => $value){
                if ($value == $name) {
                    $operation->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $key);
                }
            }
            // be sensitive to the available directions
            $directions_arr = array();
            // we anyway have the input message
            $directions_arr []= WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME;
            if(array_key_exists("output", $params)) {
                $directions_arr []= WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME;
            }
            foreach($directions_arr as $type) {
                $sel = $port_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                  $type);
                foreach($this->fun_mapping as $key => $value){
                    if ($value == $name) {
                        $sel->setAttribute(WS_WSDL_Const::WS_WSDL_MESSAGE_ATTR_NAME,
                                           WS_WSDL_Const::WS_WSDL_TNS_ATTR_NAME.":"."$key".ucfirst($attr_name_to_postfix_map[$type]));

                        if($this->use_wsa) {
                            $action = NULL;
                            if($this->r_actions && is_array($this->r_actions) && 
                                array_key_exists($key, $this->r_actions)) {
                                
                                $action = $this->r_actions[$key];
                                $sel->setAttributeNS(WS_WSDL_Const::WS_WSDL_WSAW_NAMESPACE,
                                           WS_WSDL_Const::WS_WSDL_WSAW_PREFIX.":".WS_WSDL_CONST::WS_WSDL_ACTION,
                                           $action);
                            }
                        }
                    }
                }
                $operation->appendChild($sel);
            }
            $port_el->appendChild($operation);
        }
        $port_root->appendChild($port_el);
    }

}




?>

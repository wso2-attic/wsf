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

class WS_WSDL_Interface
{

    const WS_WSDL_INTERFACE_NAME_ATTR_NAME = 'name';
    const WS_WSDL_INTERFACE_TYPE_ATTR_NAME = 'type';
    const WS_WSDL_INTERFACE_OPERATION_ATTR_NAME = 'operation';
    const WS_WSDL_INTERFACE_STYLE_ATTR_NAME = 'style';
    const WS_WSDL_INTERFACE_INPUT_ATTR_NAME = 'input';
    const WS_WSDL_INTERFACE_OUTPUT_ATTR_NAME = 'output';

    const WS_WSDL2_INTERFACE_PROTOCAL_ATTR_NAME = "protocol";
    const WS_WSDL2_INTERFACE_INTERFACE_ATTR_NAME = "interface";
    const WS_WSDL2_INTERFACE_VERSION_ATTR_NAME = "version";
    const WS_WSDL2_INTERFACE_VERSION_ATTR_VAL = "1.2";
    const WS_WSDL2_INTERFACE_SOAP_ATTR_NAME = "soap";
    const WS_WSDL2_INTERFACE_PATTERN_ATTR_NAME = "pattern";
    const WS_WSDL2_INTERFACE_ELEMENT_ATTR_NAME = "element";

    private $svr_name;
    public  $operations;

    function __construct($service_name, $operations)
    {
        $this->svr_name = $service_name;
        $this->operations = $operations;
    }


    public function createInterface(DomDocument $interface_doc, DomElement $interface_root)
    {
        $interface_ele = $interface_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                         self::WS_WSDL2_INTERFACE_INTERFACE_ATTR_NAME);
        $interface_ele->setAttribute(self::WS_WSDL_INTERFACE_NAME_ATTR_NAME,
                                     $this->svr_name.ucfirst(self::WS_WSDL2_INTERFACE_INTERFACE_ATTR_NAME));

        foreach($this->operations as $name => $params)
        {
            $op = $interface_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                  self::WS_WSDL_INTERFACE_OPERATION_ATTR_NAME  );
            $op->setAttribute(self::WS_WSDL_INTERFACE_NAME_ATTR_NAME  , $name);
            $op->setAttribute(self::WS_WSDL2_INTERFACE_PATTERN_ATTR_NAME,
                              WS_WSDL_Const::WS_WSDL2_PATTERN_ATTR_VAL);


            foreach(array(self::WS_WSDL_INTERFACE_INPUT_ATTR_NAME  ,
                          self::WS_WSDL_INTERFACE_OUTPUT_ATTR_NAME  ) as $type)
            {
                $operation_ele = $interface_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE, $type);
                if($type == self::WS_WSDL_INTERFACE_INPUT_ATTR_NAME)
                    $operation_ele->setAttribute(self::WS_WSDL2_INTERFACE_PATTERN_ATTR_NAME,
                                                 $name);
                else
                    $operation_ele->setAttribute(self::WS_WSDL2_INTERFACE_PATTERN_ATTR_NAME,
                                                 $name."Response");
                $op->appendChild($operation_ele);
            }
            $interface_ele->appendChild($op);
        }
        $interface_root->appendChild($interface_ele);
    }


}

?>

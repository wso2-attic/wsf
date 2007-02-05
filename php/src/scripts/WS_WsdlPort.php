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

 class WS_WsdlPort
 {

     private $service_name;
     private $operations;
     function __construct($service, $array1)
     {
	 $this->service_name = $service;
	 $this->operations = $array1;
     }

     public function createPortType(DomDocument $port_doc, DomElement $port_root)
     {
	 $port_el = $port_doc->createElementNS( WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE, 
						WS_WsdlConst::WS_WSDL_PORTTYPE_ATTR_NAME);
	 $port_el->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME, $this->service_name);
	 foreach($this->operations as $name => $params)
	 {
	     $operation = $port_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
						     WS_WsdlConst::WS_WSDL_OPERATION_ATTR_NAME);
	     $operation->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME, $name);
	     foreach(array(WS_WsdlConst::WS_WSDL_INPUT_ATTR_NAME, WS_WsdlConst::WS_WSDL_OUTPUT_ATTR_NAME) as $type)
	     {
		 $sel = $port_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE, $type);
		 $sel->setAttribute(WS_WsdlConst::WS_WSDL_MESSAGE_ATTR_NAME, "$name".ucfirst($type));
		 $operation->appendChild($sel);
	     }
	     $port_el->appendChild($operation);
	 }
	 $port_root->appendChild($port_el);
     }
     
 }




?>
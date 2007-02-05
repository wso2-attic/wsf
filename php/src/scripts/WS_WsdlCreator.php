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

include 'WS_WsdlConsts.php';
include 'WS_WsdlOperations.php';
include 'WS_WsdlType.php';
include 'WS_WsdlMessage.php';
include 'WS_WsdlPort.php';
include 'WS_WsdlBinding.php';
include 'WS_WsdlService.php';
include 'WS_WsdlInterface.php';

     class WS_WsdlCreator
     {
	 public $namespace;
	 private $endpoint;
	 private $f_name;
	 private $service_name;
	 private $Binding_style;
	 private $wsdl_version;

	 function __construct($obj_name, $service, $endpoints, 
			      $binding_style,  $ns , $wsdl_ver)
	 {
	     if(!$ns)
	     {
		 $this->namespace = $endpoints;
	     }
	     else
		 $this->namespace = $ns;
	     
	     $this->endpoint = $endpoints;
	     $this->f_name = $obj_name;
	     $this->service_name = $service;
	     $this->Binding_style = $binding_style;
	     if($wsdl_ver == "wsdl1.1")
		 $this->wsdl_version = "wsdl1";
	     if($wsdl_ver == "wsdl2.0")
		 $this->wsdl_version = "wsdl2";
	 }
	 
	 private function buildWsdlDom()
	 {
	     $wsdl_dom = new DomDocument(WS_WsdlConst::WS_DOM_DOCUMENT_VERSION_NO,
					 WS_WsdlConst::WS_DOM_DOCUMENT_ENCODING);

	     $wsdl_root_ele = $wsdl_dom->createElementNS(WS_Wsdlconst::WS_SCHEMA_WSDL_NAMESPACE,
							 WS_WsdlConst::WS_WSDL_DEFINITION);

	     $wsdl_root_ele->setAttributeNS(WS_Wsdlconst::WS_WSDL_DEF_SCHEMA_URI, 
					    WS_Wsdlconst::WS_WSDL_DEF_XSD_QN,
					    WS_Wsdlconst::WS_SOAP_XML_SCHEMA_NAMESPACE);
	    
	     $wsdl_root_ele->setAttributeNS(WS_Wsdlconst::WS_WSDL_DEF_SCHEMA_URI,
					    WS_Wsdlconst::WS_WSDL_DEF_TNS_QN, 
					    $this->namespace);

	     $wsdl_root_ele->setAttributeNS(WS_Wsdlconst::WS_WSDL_DEF_SCHEMA_URI, 
					    WS_Wsdlconst::WS_WSDL_DEF_SOAP_ENV_QN,
					    WS_Wsdlconst::WS_SCHEMA_SOAP_NAMESPACE);
	     
	     $wsdl_root_ele->setAttributeNS(WS_Wsdlconst::WS_WSDL_DEF_SCHEMA_URI,
					    WS_Wsdlconst::WS_WSDL_DEF_WSDL_QN,
					    WS_Wsdlconst::WS_SCHEMA_WSDL_NAMESPACE);
	     
	     $wsdl_root_ele->setAttributeNS(WS_Wsdlconst::WS_WSDL_DEF_SCHEMA_URI,
					    WS_Wsdlconst::WS_WSDL_DEF_SOAP_ENC_QN,
					    WS_Wsdlconst::WS_SOAP_SCHEMA_ENCODING_NAMESPACE);
	     
	      $wsdl_root_ele->setAttribute(WS_Wsdlconst::WS_WSDL_DEF_TARGET_NS,
					   $this->namespace);


	      $oper_obj = new WS_WsdlOperations($this->f_name);
	      $createdTypeArry = $oper_obj->createdTypes;
	      $operationsArry = $oper_obj->operations;
	      $xsdArry = $oper_obj->xsdTypes;
		  
	        
	      if($this->Binding_style == "doc-lit")
	      {
		  $type_obj = new WS_WsdlType($this->namespace, $createdTypeArry, $xsdArry);
		  $type_obj->createDocLitType($wsdl_dom, $wsdl_root_ele);
		  $simple_array = $type_obj->simpleTypes;
		
		  $msg_obj = new WS_WsdlMessage($operationsArry, $simple_array);
		  $msg_obj->createDocLitMessage($wsdl_dom,$wsdl_root_ele);
	      }

	      if ($this->Binding_style == "rpc")
	      {
		  $type_obj = new WS_WsdlType($this->namespace, $createdTypeArry, $operationsArry);
		  $type_obj->createRPCType($wsdl_dom, $wsdl_root_ele);
		  $simple_array = $type_obj->simpleTypes;

		 
		  $msg_obj = new WS_WsdlMessage($operationsArry, $simple_array);
		  $msg_obj->createRPCMessage($wsdl_dom,$wsdl_root_ele);

	      }



	      $port_obj = new WS_WsdlPort($this->service_name, $operationsArry);
	      $port_obj->createPortType($wsdl_dom, $wsdl_root_ele);

	      if ($this->Binding_style == "doc-lit")
	      {
		  $bind_obj = new WS_WsdlBinding($this->service_name, $this->endpoint,  $operationsArry);
		  $bind_obj->createDocLitBinding($wsdl_dom, $wsdl_root_ele);
	      }
	      
	      if ($this->Binding_style == "rpc")
	      {
		$bind_obj = new WS_WsdlBinding($this->service_name, $this->endpoint,  $operationsArry);
		$bind_obj->createRPCBinding($wsdl_dom, $wsdl_root_ele);
	       
	      }
	      
	      $svr_obj = new WS_WsdlService($this->service_name, $this->endpoint);
	      $svr_obj->createService($wsdl_dom, $wsdl_root_ele);
	      
	      
	      
	      $wsdl_dom->appendChild($wsdl_root_ele);
	      return $wsdl_dom->saveXML();
	      
	 }

	 private function buildWsdl2Dom()
	 {
	     $wsdl_dom = new DomDocument(WS_WsdlConst::WS_DOM_DOCUMENT_VERSION_NO,
					 WS_WsdlConst::WS_DOM_DOCUMENT_ENCODING);
	     
	     $wsdl_root_ele = $wsdl_dom->createElementNS(WS_WsdlConst::WS_WSDL2_NAMESPACE,
							 WS_WsdlConst::WS_WSDL2_DESCRIPTION);
	     
	    

	     $wsdl_root_ele->setAttributeNS(WS_WsdlConst::WS_WSDL_DEF_SCHEMA_URI, 
					    WS_WsdlConst::WS_WSDL2_WSDLX_ATTR_NAME,
					    WS_WsdlConst::WS_WSDL2_WSDLX_ATTR_VAL);
	     
	     $wsdl_root_ele->setAttributeNS(WS_WsdlConst::WS_WSDL_DEF_SCHEMA_URI,
					    WS_WsdlConst::WS_WSDL_DEF_TNS_QN, 
					    $this->namespace);
	     
	     $wsdl_root_ele->setAttributeNS(WS_WsdlConst::WS_WSDL_DEF_SCHEMA_URI, 
					    WS_WsdlConst::WS_WSDL2_WSOAP_ATTR_NAME,
					    WS_WsdlConst::WS_WSDL2_WSOAP_ATTR_VAL);
	     
	     $wsdl_root_ele->setAttributeNS(WS_WsdlConst::WS_WSDL_DEF_SCHEMA_URI,
					    WS_WsdlConst::WS_WSDL2_WHTTP_ATTR_NAME,
					    WS_WsdlConst::WS_WSDL2_WHTTP_ATTR_VAL);
	     
	     $wsdl_root_ele->setAttributeNS(WS_WsdlConst::WS_WSDL_DEF_SCHEMA_URI,
					    WS_WsdlConst::WS_WSDL_DEF_SOAP_ENC_QN,
					    WS_WsdlConst::WS_WSDL2_SOAP_ATTR_VAL);
	     
	      $wsdl_root_ele->setAttribute(WS_WsdlConst::WS_WSDL_DEF_TARGET_NS,
					   $this->namespace);
	      

	      $wsdl_doc_ele = $wsdl_dom->createElement(WS_WsdlConst::WS_WSDL2_DOCUMENTATION);
	      $doc_txt = new DomText("A simple ".$this->service_name." service");
	      $wsdl_doc_ele->appendChild($doc_txt);
	      $wsdl_root_ele->appendChild($wsdl_doc_ele);


	      $oper_obj = new WS_WsdlOperations($this->f_name);
	      $createdTypeArry = $oper_obj->createdTypes;
	      $operationsArry = $oper_obj->operations;
	      $xsdArry = $oper_obj->xsdTypes;

	      
	      $type_obj = new WS_WsdlType($this->namespace, $createdTypeArry, $xsdArry);
	      $type_obj->createWsdl2Type($wsdl_dom, $wsdl_root_ele);

	      $interface_obj = new WS_WsdlInterface($this->service_name, $operationsArry);
	      $interface_obj->createInterface($wsdl_dom, $wsdl_root_ele);
		      
	      $bind_obj = new WS_WsdlBinding($this->service_name);
	      $bind_obj->createWsdl2Binding($wsdl_dom, $wsdl_root_ele);

	      $svr_obj = new WS_WsdlService($this->service_name, $this->endpoint);
	      $svr_obj->createWsdl2Service($wsdl_dom, $wsdl_root_ele);
	      
	      
	      $wsdl_dom->appendChild($wsdl_root_ele);
	      /*$wsdl_dom->save("/tmp/wsdl2.wsdl"); */
	      return $wsdl_dom->saveXML();
	      
	 }

	 public function WS_WsdlOut()
	     {
		 if ($this->wsdl_version == "wsdl1")
		     $tmp = $this->buildWsdlDom();
		 else
		     $tmp = $this->buildWsdl2Dom();
		 return $tmp;
	     }
	 
	 
	 
     }
?>

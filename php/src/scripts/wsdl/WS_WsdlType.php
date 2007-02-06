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


class WS_WsdlType
 {


     public $simpleTypes;
     public $cmplxTypes;
     public $schemaTypes;
     private $ns;

     private $createdTypes;
     function __construct($ns, $array1, $array2)
     {
	 $this->ns = $ns;
	 $this->simpleTypes = WS_WsdlConst::$defaultTypes;
	 $this->createdTypes = $array1;
	 $this->schemaTypes = $array2;
	 $this->createPHPTypes();
	
     }
     
     
     protected function findTypes($wsdlType)
     {
	 foreach(array_keys($this->createdTypes) as $wsdlType) 
	 {
	     if(!isset($this->simpleTypes[$wsdlType])) 
	     {
		 $this->buildComplexType($wsdlType);
	     }
	 }
	 
     }
     
     protected function buildComplexType($className) 
     {     
	 $class = new ReflectionClass($className);
	 $this->cmplxTypes[$className] = array();
	 $this->createdTypes[$className] = array(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME => $className,
						 WS_WsdlConst::WS_WSDL_NAMESPACE_ATTR_NAME => $this->ns);
	 
	 foreach($class->getProperties() as $prop) 
	 {
	     $doc = $prop->getDocComment();
	     if(preg_match('|@var\s+(?:object\s+)?(\w+)|', $doc, $match)) 
	     {
		 $wsdlType = $match[1];
		 $this->cmplxTypes[$className][] = array(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME => $prop->getName(),
							 WS_WsdlConst::WS_WSDL_TYPE_ATTR_NAME => $wsdlType);
		 if(!isset($this->createdTypes[$wsdlType])) 
		 {
		     $this->buildComplexType($wsdlType);
		 }
	     }
	 }
	 
     }	 
	 protected function createPHPTypes() 
         {
	     $this->cmplxTypes['mixed'] = array(
		 array(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME => 'varString',
		       'type' => 'string'),
		 array(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME => 'varInt',
		       'type' => 'int'),
		 array(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME => 'varFloat',
		       'type' => 'float'),
		 array(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME => 'varArray',
		       'type' => 'array'));
	     $this->simpleTypes['mixed'] = array(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME => 'mixed', 
						 WS_WsdlConst::WS_WSDL_NAMESPACE_ATTR_NAME => $this->ns);
	     $this->simpleTypes['array'] = array(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME => 'array',
						 WS_WsdlConst::WS_WSDL_NAMESPACE_ATTR_NAME => $this->ns);
	 }
	 
	
	 public function createDocLitType(DomDocument $type_doc, DomElement $type_root)
	 {
	         $types = $type_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
						     WS_WsdlConst::WS_WSDL_TYPES_ATTR_NAME);
		 $type_root->appendChild($types);
		 $el = $type_doc->createElementNS(WS_WsdlConst::WS_SOAP_XML_SCHEMA_NAMESPACE, 
						  WS_WsdlConst::WS_WSDL_SCHEMA_ATTR_NAME);

		 $el->setAttribute(WS_WsdlConst::WS_WSDL_ELEMENTFROMDEFAULT_ATTR_NAME,
				   WS_WsdlConst::WS_WSDL_QUALIFIED_ATTR_NAME);
		 $types->appendChild($el);
		 

		 foreach ($this->schemaTypes as $function_name => $params)
		 {
		     foreach ($params as $requestType => $params2)
		     {
			 $ct = $type_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
							  WS_WsdlConst::WS_WSDL_ELEMENT_ATTR_NAME);
			 if ($requestType == WS_WsdlConst::WS_WSDL_IN_ATTR_NAME)
			 {
			     $ct->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME, $function_name);
			     $el->appendChild($ct);
			     $comtype = $type_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
								   WS_WsdlConst::WS_WSDL_COMPLXTYPE_ATTR_NAME);
			     $ct->appendChild($comtype);
			     $seq = $type_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
							       WS_WsdlConst::WS_WSDL_SEQUENCE_ATTR_NAME);
			     
			     $comtype->appendChild($seq);
			     foreach ($params2 as $paramName => $xsType)
			     {
				 $ele = $type_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
							       WS_WsdlConst::WS_WSDL_ELEMENT_ATTR_NAME);
				 $ele->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME, $paramName);
				 $ele->setAttribute(WS_WsdlConst::WS_WSDL_TYPE_ATTR_NAME, WS_WsdlConst::WS_WSDL_XSD_ATTR_NAME.$xsType);
				 $seq->appendChild($ele);
			     }
			 }
			 if ($requestType == WS_WsdlConst::WS_WSDL_OUT_ATTR_NAME)
			 {
			     $ct->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME, 
					       $function_name.WS_WsdlConst::WS_WSDL_RESPONSE_ATTR_NAME);
                             $el->appendChild($ct);
                             $comtype = $type_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
                                                                   WS_WsdlConst::WS_WSDL_COMPLXTYPE_ATTR_NAME);
                             $ct->appendChild($comtype);
                             $seq = $type_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
                                                               WS_WsdlConst::WS_WSDL_SEQUENCE_ATTR_NAME);

                             $comtype->appendChild($seq);
                        
			     foreach ($params2 as $paramName => $xsType)
			     {
				 $ele = $type_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
							       WS_WsdlConst::WS_WSDL_ELEMENT_ATTR_NAME);
				 $ele->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME, $paramName);
				 $ele->setAttribute(WS_WsdlConst::WS_WSDL_TYPE_ATTR_NAME, WS_WsdlConst::WS_WSDL_XSD_ATTR_NAME.$xsType);
				 $seq->appendChild($ele);
			     }
			
			
			 }
		     }

		 }
		 
	 }


	 public function createRPCType(DomDocument $type_doc, DomElement $type_root)
	 {
	         $types = $type_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
						     WS_WsdlConst::WS_WSDL_TYPES_ATTR_NAME);
		 $type_root->appendChild($types);
		 $el = $type_doc->createElementNS(WS_WsdlConst::WS_SOAP_XML_SCHEMA_NAMESPACE, 
						  WS_WsdlConst::WS_WSDL_SCHEMA_ATTR_NAME);

		 $el->setAttribute(WS_WsdlConst::WS_WSDL_ELEMENTFROMDEFAULT_ATTR_NAME,
				   WS_WsdlConst::WS_WSDL_QUALIFIED_ATTR_NAME);
		 $types->appendChild($el);
		 


		 // $ct = $type_doc->createElementNS(WS_WsdlConst::WS_SOAP_XML_SCHEMA_NAMESPACE,
// 						  WS_WsdlConst::WS_WSDL_COMPLXTYPE_ATTR_NAME);
// 		 $el->appendChild($ct);
// 		 $ct->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME, 'array');
// 		 $cc = $type_doc->createElementNS(WS_WsdlConst::WS_SOAP_XML_SCHEMA_NAMESPACE, 
// 						  WS_WsdlConst::WS_WSDL_COMPLXCONTENT_ATTR_NAME);
// 		 $ct->appendChild($cc);
// 		 $restriction = $type_doc->createElementNS(WS_WsdlConst::WS_SOAP_XML_SCHEMA_NAMESPACE,
// 							   WS_WsdlConst::WS_WSDL_RESTRICTION_ATTR_NAME);
// 		 $cc->appendChild($restriction);
// 		 $restriction->setAttribute(WS_WsdlConst::WS_WSDL_BASE_ATTR_NAME,
// 					    WS_WsdlConst::WS_WSDL_SOAPENCARRAY_ATTR_NAME);
// 		 $attribute = $type_doc->createElementNS(WS_WsdlConst::WS_SOAP_XML_SCHEMA_NAMESPACE, 
// 							 WS_WsdlConst::WS_WSDL_ATTRIBUTE_ATTR_NAME);
// 		 $restriction->appendChild($attribute);
// 		 $attribute->setAttribute(WS_WsdlConst::WS_WSDL_REF_ATTR_NAME,
// 					  WS_WsdlConst::WS_WSDL_SOAPENCARRAYTYPE_ATTR_NAME);
// 		 $attribute->setAttributeNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE, 
// 					  WS_WsdlConst::WS_WSDL_ARRAYTYPE_ATTR_NAME,
// 					  "tns");
					   
		 

		 
		 foreach($this->cmplxTypes as $name => $data)
                 {
		     $ct = $type_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
						      WS_WsdlConst::WS_WSDL_COMPLXTYPE_ATTR_NAME);
		     $ct->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME, $name);
		     
		     $all = $type_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
						       WS_WsdlConst::WS_WSDL_ALL_ATTR_NAME);
		     
		     foreach($data as $prop)
		     {
			 $p = $type_doc->createElementNS(WS_WsdlConst::WS_SCHEMA_WSDL_NAMESPACE,
							 WS_WsdlConst::WS_WSDL_ELEMENT_ATTR_NAME);
			 $p->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME, 
					  $prop[WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME]);
			 $p->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME,
					  $prop[WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME]);
			 $prefix = $type_root->lookupPrefix($this->simpleTypes[$prop[WS_WsdlConst::WS_WSDL_TYPE_ATTR_NAME]][WS_WsdlConst::WS_WSDL_NAMESPACE_ATTR_NAME]);
			 $p->setAttribute(WS_WsdlConst::WS_WSDL_TYPE_ATTR_NAME, "$prefix:".$this->simpleTypes[$prop[WS_WsdlConst::WS_WSDL_TYPE_ATTR_NAME]][WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME]);
			 $all->appendChild($p);
		     }
		     $ct->appendChild($all);
		     $el->appendChild($ct);
		 }

		 
	 }



	 public function createWsdl2Type(DomDocument $type_doc, DomElement $type_root)
	 {
	         $types = $type_doc->createElementNS(WS_WsdlConst::WS_WSDL2_NAMESPACE,
						     WS_WsdlConst::WS_WSDL_TYPES_ATTR_NAME);
		 $type_root->appendChild($types);
		 $el = $type_doc->createElementNS(WS_WsdlConst::WS_SOAP_XML_SCHEMA_NAMESPACE, 
						  WS_WsdlConst::WS_WSDL_SCHEMA_ATTR_NAME);

		 $el->setAttribute(WS_WsdlConst::WS_WSDL_ELEMENTFROMDEFAULT_ATTR_NAME,
				   WS_WsdlConst::WS_WSDL_QUALIFIED_ATTR_NAME);
		 $types->appendChild($el);
		 

		 foreach ($this->schemaTypes as $function_name => $params)
		 {
		     foreach ($params as $requestType => $params2)
		     {
			 $ct = $type_doc->createElementNS(WS_WsdlConst::WS_WSDL2_NAMESPACE,
							  WS_WsdlConst::WS_WSDL_ELEMENT_ATTR_NAME);
			 if ($requestType == WS_WsdlConst::WS_WSDL_IN_ATTR_NAME)
			 {
			     $ct->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME, 
					       $function_name);
			     $el->appendChild($ct);
			     $comtype = $type_doc->createElementNS(WS_WsdlConst::WS_WSDL2_NAMESPACE,
								   WS_WsdlConst::WS_WSDL_COMPLXTYPE_ATTR_NAME);
			     $ct->appendChild($comtype);
			     $seq = $type_doc->createElementNS(WS_WsdlConst::WS_WSDL2_NAMESPACE,
							       WS_WsdlConst::WS_WSDL_SEQUENCE_ATTR_NAME);
			     
			     $comtype->appendChild($seq);
			     foreach ($params2 as $paramName => $xsType)
			     {
				 $ele = $type_doc->createElementNS(WS_WsdlConst::WS_WSDL2_NAMESPACE,
							       WS_WsdlConst::WS_WSDL_ELEMENT_ATTR_NAME);
				 $ele->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME, $paramName);
				 $ele->setAttribute(WS_WsdlConst::WS_WSDL_TYPE_ATTR_NAME, WS_WsdlConst::WS_WSDL_XSD_ATTR_NAME.$xsType);
				 $seq->appendChild($ele);
			     }
			 }
			 if ($requestType == WS_WsdlConst::WS_WSDL_OUT_ATTR_NAME)
			 {
			     $ct->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME, 
					       $function_name.WS_WsdlConst::WS_WSDL_RESPONSE_ATTR_NAME);
                             $el->appendChild($ct);
                             $comtype = $type_doc->createElementNS(WS_WsdlConst::WS_WSDL2_NAMESPACE,
                                                                   WS_WsdlConst::WS_WSDL_COMPLXTYPE_ATTR_NAME);
                             $ct->appendChild($comtype);
                             $seq = $type_doc->createElementNS(WS_WsdlConst::WS_WSDL2_NAMESPACE,
                                                               WS_WsdlConst::WS_WSDL_SEQUENCE_ATTR_NAME);

                             $comtype->appendChild($seq);
                        
			     foreach ($params2 as $paramName => $xsType)
			     {
				 $ele = $type_doc->createElementNS(WS_WsdlConst::WS_WSDL2_NAMESPACE,
							       WS_WsdlConst::WS_WSDL_ELEMENT_ATTR_NAME);
				 $ele->setAttribute(WS_WsdlConst::WS_WSDL_NAME_ATTR_NAME, $paramName);
				 $ele->setAttribute(WS_WsdlConst::WS_WSDL_TYPE_ATTR_NAME, WS_WsdlConst::WS_WSDL_XSD_ATTR_NAME.$xsType);
				 $seq->appendChild($ele);
			     }
			
			
			 }
		     }

		 }
		 
	 }







      }
     



?>
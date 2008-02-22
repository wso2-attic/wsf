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

/**
 * This class generates the schema in WSDL
 *
 */
class WS_WSDL_Type
{
    public $simpleTypes;
    public $cmplxTypes;
    public $schemaTypes;
    private $ns;
    private $createdTypes;
    private $fun_mapping;

    /**
     * Constructor of the class
     * @param string $ns namespace
     * @param Array $array1 Mapping table of types
     * @param Array $array2 xsd mapping table
     */
    function __construct($ns, $array1, $array2, $mapping_array)
    {
        $this->ns = $ns;
        $this->simpleTypes = WS_WSDL_Const::$defaultTypes;
        $this->createdTypes = $array1;
        $this->schemaTypes = $array2;
        $this->fun_mapping = $mapping_array;
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
        $this->createdTypes[$className] = array(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME => $className,
                                                WS_WSDL_Const::WS_WSDL_NAMESPACE_ATTR_NAME => $this->ns);

        foreach($class->getProperties() as $prop)
        {
            $doc = $prop->getDocComment();
            if(preg_match('|@var\s+(?:object\s+)?(\w+)|', $doc, $match))
            {
                $wsdlType = $match[1];
                $this->cmplxTypes[$className][] = array(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME => $prop->getName(),
                                                        WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME => $wsdlType);
                if(!isset($this->createdTypes[$wsdlType]))
                {
                    $this->buildComplexType($wsdlType);
                }
            }
        }

    }

    /**
     * Function that creates types elements(schema) for WSDL1.1 in
     * doc-lit style 
     * @param DomDocument $type_doc DomDocument element of the wsdl document
     * @param DomElement $type_root service dom element
     */

    public function createDocLitType(DomDocument $type_doc, DomElement $type_root)
    {
        $types = $type_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                            WS_WSDL_Const::WS_WSDL_TYPES_ATTR_NAME);
        $type_root->appendChild($types);
        $el = $type_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                         WS_WSDL_Const::WS_WSDL_SCHEMA_ATTR_NAME);

        $el->setAttribute(WS_WSDL_Const::WS_WSDL_ELEMENTFORMDEFAULT_ATTR_NAME, 
                           WS_WSDL_Const::WS_WSDL_QUALIFIED_ATTR_NAME);

        $el->setAttribute(WS_WSDL_Const::WS_WSDL_DEF_TARGET_NS,
                          $this->ns);

        $schema_root = $el;

        $types->appendChild($el);


        foreach ($this->schemaTypes as $function_name => $params)
        {
            foreach ($params as $requestType => $params2)
            {
                $ct = $type_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                 WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                if ($requestType == WS_WSDL_Const::WS_WSDL_IN_ATTR_NAME)
                {
                    foreach($this->fun_mapping as $key => $value)
                    {
                        if ($value == $function_name)
                            $ct->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $key);
                    }
                    $el->appendChild($ct);
                    $comtype = $type_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME);
                    $ct->appendChild($comtype);
                    $seq = $type_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                      WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME);

                    $comtype->appendChild($seq);
                    foreach ($params2 as $paramName => $paramValue)
                    {
                        $xsd_type =  $paramValue["type"];
                        $ele = $type_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                        $ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $paramName);
                        if($paramValue["array"] == "array")
                        {
                            $ele->setAttribute(WS_WSDL_Const::WS_WSDL_ATTR_MAX_OCCURS, WS_WSDL_Const::WS_WSDL_ATTR_VALUE_UNBOUNDED);
                        }
                        
                        if($paramValue["object"] == "object")
                        {
                            $object_return = $this->createSchemaType($type_doc, $types, $xsd_type);
                            
                            $object_prefix = $object_return["prefix"];
                            $object_namespace = $object_return["namespace"];

                            $schema_root->setAttribute("xmlns:".$object_prefix, $object_namespace);
                            $ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, $object_prefix.":".$xsd_type);
                        }
                        else
                        {
                            $ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$xsd_type);
                        }
                        

                        $seq->appendChild($ele);

                    }
                }
                if ($requestType == WS_WSDL_Const::WS_WSDL_OUT_ATTR_NAME)
                {
                    foreach($this->fun_mapping as $key => $value){
                        if ($value == $function_name)
                            $ct->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                              $key.WS_WSDL_Const::WS_WSDL_RESPONSE_ATTR_NAME);
                    }
                    $el->appendChild($ct);
                    $comtype = $type_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME);
                    $ct->appendChild($comtype);
                    $seq = $type_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                      WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME);

                    $comtype->appendChild($seq);

                    foreach ($params2 as $paramName => $paramValue)
                    {
                        $xsd_type =  $paramValue["type"];
                        $ele = $type_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                        $ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $paramName);
                        if($paramValue["array"] == "array")
                        {
                            $ele->setAttribute(WS_WSDL_Const::WS_WSDL_ATTR_MAX_OCCURS, WS_WSDL_Const::WS_WSDL_ATTR_VALUE_UNBOUNDED);
                        }
                        
                        if($paramValue["object"] == "object")
                        {
                            $object_return = $this->createSchemaType($type_doc, $types, $xsd_type);
                            
                            $object_prefix = $object_return["prefix"];
                            $object_namespace = $object_return["namespace"];

                            $schema_root->setAttribute("xmlns:".$object_prefix, $object_namespace);

                            $ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, $object_prefix.":".$xsd_type);
                        }
                        else
                        {
                            $ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$xsd_type);
                        }
                        
                        $seq->appendChild($ele);
                    }
                }
            }
        }
    }

    /**
     * Function that creates types elements(schema) for WSDL1.1 in  rpc style
     * @param DomDocument $type_doc DomDocument element of the wsdl document
     * @param DomElement $type_root service dom element
     */

    public function createRPCType(DomDocument $type_doc, DomElement $type_root)
    {
    
        $class_to_prefix = array();

        $types = $type_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                            WS_WSDL_Const::WS_WSDL_TYPES_ATTR_NAME);
        $type_root->appendChild($types);

        foreach ($this->schemaTypes as $function_name => $params)
        {
            foreach ($params as $requestType => $params2)
            {
                if ($requestType == WS_WSDL_Const::WS_WSDL_IN_ATTR_NAME)
                {
                    foreach ($params2 as $paramName => $paramValue)
                    {
                        $xsd_type =  $paramValue["type"];
                        
                        if($paramValue["object"] == "object")
                        {
                            $object_return = $this->createSchemaType($type_doc, $types, $xsd_type);
                            
                            $object_prefix = $object_return["prefix"];
                            $object_namespace = $object_return["namespace"];

                            $type_root->setAttribute("xmlns:".$object_prefix, $object_namespace);
                            $class_to_prefix[$xsd_type] = $object_prefix;
                        }
                    }
                }
                if ($requestType == WS_WSDL_Const::WS_WSDL_OUT_ATTR_NAME)
                {
                    foreach ($params2 as $paramName => $paramValue)
                    {
                        $xsd_type =  $paramValue["type"];
                       
                        if($paramValue["object"] == "object")
                        {
                            $object_return = $this->createSchemaType($type_doc, $types, $xsd_type);
                            
                            $object_prefix = $object_return["prefix"];
                            $object_namespace = $object_return["namespace"];

                            $type_root->setAttribute("xmlns:".$object_prefix, $object_namespace);
                            $class_to_prefix[$xsd_type] = $object_prefix;
                        }
                    }
                }
            }
        }
        return $class_to_prefix;
    }

    /**
     * Function that creates type elements(schema) for WSDL2.0
     * @param DomDocument $type-doc DomDocument element of the wsdl
     * document
     * @param DomElement $type_root service dom element
     */

    public function createWsdl2Type(DomDocument $type_doc, DomElement $type_root)
    {
        $types = $type_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                            WS_WSDL_Const::WS_WSDL_TYPES_ATTR_NAME);
        $type_root->appendChild($types);
        $el = $type_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                         WS_WSDL_Const::WS_WSDL_SCHEMA_ATTR_NAME);

        $el->setAttribute(WS_WSDL_Const::WS_WSDL_ELEMENTFROMDEFAULT_ATTR_NAME,
                          WS_WSDL_Const::WS_WSDL_QUALIFIED_ATTR_NAME);
        $types->appendChild($el);


        foreach ($this->schemaTypes as $function_name => $params)
        {
            foreach ($params as $requestType => $params2)
            {
                $ct = $type_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                 WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                if ($requestType == WS_WSDL_Const::WS_WSDL_IN_ATTR_NAME)
                {
                    $ct->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                      $function_name);
                    $el->appendChild($ct);
                    $comtype = $type_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME);
                    $ct->appendChild($comtype);
                    $seq = $type_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                      WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME);

                    $comtype->appendChild($seq);
                    foreach ($params2 as $paramName => $xsType)
                    {
                        $ele = $type_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                        $ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $paramName);
                        $ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$xsType);
                        $seq->appendChild($ele);
                    }
                }
                if ($requestType == WS_WSDL_Const::WS_WSDL_OUT_ATTR_NAME)
                {
                    $ct->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                      $function_name.WS_WSDL_Const::WS_WSDL_RESPONSE_ATTR_NAME);
                    $el->appendChild($ct);
                    $comtype = $type_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME);
                    $ct->appendChild($comtype);
                    $seq = $type_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                      WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME);

                    $comtype->appendChild($seq);

                    foreach ($params2 as $paramName => $xsType)
                    {
                        $ele = $type_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                        $ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $paramName);
                        $ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$xsType);
                        $seq->appendChild($ele);
                    }
                }
            }
        }
    }

    public function createSchemaType($type_doc, $type_root, $classname){
        
        require_once("WS_WSDL_Operations.php");
        
        static $i = 0;

        $class = new ReflectionClass($classname);

        if($class == NULL)
        {
           return;
        }

        $class_namespace = WS_WSDL_SCHEMA_TYPE_DEFAULT_NS;
        $class_comment = $class->getDocComment();

        if(preg_match_all('|@namespace\s+([^\s]+).*|', $class_comment, $matches, PREG_SET_ORDER))
        {
            $namespace = $matches[0][1];
        }

        $prefix = NULL;

        $schema_root = NULL;

        foreach($type_root->childNodes as $child)
        {
            if($child->nodeType == XML_ELEMENT_NODE)
            {
                $child_tns = $child->getAttribute("targetNamespace");
                if($child_tns == $namespace)
                {
                    $schema_root = $child;
                    
                    foreach($child->childNodes as $types)
                    {
                        if($types->nodeType == XML_ELEMENT_NODE)
                        {
                            $types_name = $types->getAttribute("name");
                            if($types_name == $classname)
                            {
                                /* no need to create additional, just use this one */
                                $prefix = "ns".$i;
                                $i ++;
                                return array("prefix"=> $prefix, "namespace" => $namespace);
                                
                            }
                        }
                    }
                    break;
                }
            }
        }

        if($schema_root == NULL)
        {
            $schema_root = $type_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                             WS_WSDL_Const::WS_WSDL_SCHEMA_ATTR_NAME);

            $schema_root->setAttribute(WS_WSDL_Const::WS_WSDL_ELEMENTFORMDEFAULT_ATTR_NAME, 
                               WS_WSDL_Const::WS_WSDL_QUALIFIED_ATTR_NAME);

            $schema_root->setAttribute(WS_WSDL_Const::WS_WSDL_DEF_TARGET_NS,
                              $namespace);


            $type_root->appendChild($schema_root);
        }

        $comtype = $type_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                      WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME);
        $comtype->setAttribute("name", $classname);
        $schema_root->appendChild($comtype);
        $seq = $type_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                  WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME);

        $comtype->appendChild($seq);



        if($namespace_array[$namespace] != NULL)
        {
            $prefix = $namespace_array[$namespace];
        }
        else
        {
            $prefix = "ns".$i;
            $namespace_array[$namespace] = $prefix;
            $i ++;
        }

        $properties = $class->getProperties();

        foreach($properties as $property)
        {
            if($property->isPublic())
            {
                $name = $property->getName();
                $property_comment = $property->getDocComment();

                $array = FALSE;
                $object = FALSE;
                $php_type = "string"; //default to string
                $xsd_type = "string";

                if(preg_match_all('|@property\s+(?:(array)\s+of\s+)?(?:(object)\s+)?(\w+)\s+(.*)|', $property_comment,
                                              $matches, PREG_SET_ORDER))
                {
                    $array = $matches[0][1];
                    $object = $matches[0][2];
                    $php_type = $matches[0][3];
                }
                /* xsd type is optional */
                if(preg_match_all('|xs:?(\w+).*|', $property_comment, $matches, PREG_SET_ORDER))
                {
                    $xsd_type = $matches[0][1];
                }

                if($xsd_type == NULL || WS_WSDL_Operations::$mappingTable[$xsd_type] != $php_type)
                {
                    $xsd_type = $php_type;
                }

                $ele = $type_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                  WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                $ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $name);
                if($array == "array")
                {
                    $ele->setAttribute(WS_WSDL_Const::WS_WSDL_ATTR_MAX_OCCURS, WS_WSDL_Const::WS_WSDL_ATTR_VALUE_UNBOUNDED);
                }
                if($object == "object")
                {
                    $object_return = $this->createSchemaType($type_doc, $type_root, $xsd_type);

                    $object_prefix = $object_return["prefix"];
                    $object_namespace = $object_return["namespace"];

                    $schema_root->setAttribute("xmlns:".$object_prefix, $object_namespace);

                    $ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, $object_prefix.":".$xsd_type);
                }
                else
                {
                    $ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$xsd_type);
                }
                $seq->appendChild($ele);
            }
        }
        return array("prefix"=> $prefix, "namespace" => $namespace);
    }
}

?>

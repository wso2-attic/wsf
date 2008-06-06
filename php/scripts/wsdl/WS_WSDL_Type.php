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
    public $cmplxTypes;
    public $schemaTypes;
    private $ns;
    private $createdTypes;
    private $fun_mapping;
    private $classmap;
    private $namespace_array;

    /**
     * Constructor of the class
     * @param string $ns namespace
     * @param Array $createTypes Mapping table of types
     * @param Array $schemaTypes xsd mapping table
     */
    function __construct($ns, $createTypes, $schemaTypes, $mapping_array, $classmap)
    {
        $this->ns = $ns.WS_WSDL_Const::WS_WSDL_DEF_ELEMENT_NS_POSTFIX;
        $this->createdTypes = $createTypes;
        $this->schemaTypes = $schemaTypes;
        $this->fun_mapping = $mapping_array;
        $this->classmap = $classmap;
        $this->namespace_array = array();
    }


    public function createDocLitTypeWithAnnotations(DomDocument $wsdl_doc,
                                DomElement $wsdl_root, $annotations)
    {
 
        $return_array = array();
        $types_ele = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                            WS_WSDL_Const::WS_WSDL_TYPES_ATTR_NAME);
        $wsdl_root->appendChild($types_ele);


        // this keeps the map between the global namespaces => prefix
        $public_ns_map = array();

        // this keeps the map between the namespace => schema element
        $public_schema_map = array();

        // this keeps the next index (x) so that nsx doesn't exist
        // in the public_ns_map
        $public_ns_index = 0;

        $xsd_types = $annotations[WS_WSDL_Const::WS_WSDL_TYPES_ATTR_NAME];
        foreach($annotations as $function_name => $param_value) {
            $return_array[$function_name] = array();
            if(array_key_exists(WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME, $param_value)) {
                $input_element = $param_value[WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME];

                $element_name = $input_element["name"];
                $element_namespace = $input_element["namespace"];
                $element_type = $input_element["type"];


                if($element_namespace) {
                    $created_namespace = $this->createNamespace($element_namespace, $wsdl_doc, $types_ele, $public_ns_map,
                                $public_schema_map, $public_ns_index);
                }
                else {
                    $created_namespace = $this->createNamespace($this->ns, $wsdl_doc, $types_ele, $public_ns_map,
                                $public_schema_map, $public_ns_index);
                }
                $schema = $created_namespace["schema"];

                //element
                $element_ele = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                    WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $element_name);
                
                $schema->appendChild($element_ele);

                $type_attribute = NULL;
                if(strstr($element_type, "xsd:") !== FALSE) {
                    $type_attribute_value = $element_type;
                }
                else {
                    //finding the type with the name..
                    $type_entry = NULL;
                    foreach($xsd_types as $xsd_type) {
                        if($xsd_type["name"] == $element_type) {
                            $type_entry = $xsd_type;
                            break;
                        }
                    }

                    $type_ns = $type_entry["namespace"];
                    if($type_ns == NULL) {
                        $type_ns = $this->ns;
                    }
                    
                    $created_type_namespace = $this->createNamespace($type_ns, $wsdl_doc, $types_ele, $public_ns_map,
                                    $public_schema_map, $public_ns_index);
                    $type_prefix = $created_type_namespace["prefix"];

                    $type_attribute_value = $type_prefix.":".$element_type;
                }
                if($type_attribute_value) {
                    $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, $type_attribute_value);
                }
                $element_name_prefix = $created_namespace["prefix"];
                $return_array[$function_name]["in"] = $element_name_prefix.":".$element_name;
            }
            if(array_key_exists(WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME, $param_value)) {
                $output_element = $param_value[WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME];

                $element_name = $output_element["name"];
                $element_namespace = $output_element["namespace"];
                $element_type = $output_element["type"];


                if($element_namespace) {
                    $created_namespace = $this->createNamespace($element_namespace, $wsdl_doc, $types_ele, $public_ns_map,
                                $public_schema_map, $public_ns_index);
                }
                else {
                    $created_namespace = $this->createNamespace($this->ns, $wsdl_doc, $types_ele, $public_ns_map,
                                $public_schema_map, $public_ns_index);
                }
                $schema = $created_namespace["schema"];

                //element
                $element_ele = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                    WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $element_name);

                $schema->appendChild($element_ele);

                $type_attribute = NULL;
                if(strstr($element_type, "xsd:") !== FALSE) {
                    $type_attribute_value = $element_type;
                }
                else {
                    //finding the type with the name..
                    $type_entry = NULL;
                    foreach($xsd_types as $xsd_type) {
                        if($xsd_type["name"] == $element_type) {
                            $type_entry = $xsd_type;
                            break;
                        }
                    }

                    $type_ns = $type_entry["namespace"];
                    if($type_ns == NULL) {
                        $type_ns = $this->ns;
                    }
                    
                    $created_type_namespace = $this->createNamespace($type_ns, $wsdl_doc, $types_ele, $public_ns_map,
                                    $public_schema_map, $public_ns_index);
                    $type_prefix = $created_type_namespace["prefix"];

                    $type_attribute_value = $type_prefix.":".$element_type;
                }
                if($type_attribute_value) {
                    $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, $type_attribute_value);
                }
                $element_name_prefix = $created_namespace["prefix"];
                $return_array[$function_name]["out"] = $element_name_prefix.":".$element_name;
            }
        }
        
        foreach($xsd_types as $xsd_type) {
            $type_name = $xsd_type["name"];
            $type_namespace = $xsd_type["namespace"];

            if($element_namespace) {
                $created_namespace = $this->createNamespace($type_namespace, $wsdl_doc, $types_ele, $public_ns_map,
                                $public_schema_map, $public_ns_index);
            }
            else {
                $created_namespace = $this->createNamespace($this->ns, $wsdl_doc, $types_ele, $public_ns_map,
                                $public_schema_map, $public_ns_index);
            }
            $type_schema = $created_namespace["schema"];


            //create the complex type element 
            $comtype = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                      WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME);
            $comtype->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $type_name);
            $type_schema->appendChild($comtype);
            
            if(is_array($xsd_type) && array_key_exists("sequence", $xsd_type)) {

                //create the sequnce element
                $seq = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                      WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME);
                $comtype->appendChild($seq);

                $type_sequence = $xsd_type["sequence"];
                if(is_array($type_sequence)) {
                    foreach($type_sequence as $element) {
                        $element_name = $element["name"];
                        $element_type = $element["type"];

                        //element
                        $element_ele = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                            WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                        $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $element_name);

                        if(array_key_exists("minOccurs", $element)) {
                            $element_min_occurs = $element["minOccurs"];
                            if($element_min_occurs !== NULL) {
                                $element_ele->setAttribute("minOccurs", $element_min_occurs);
                            }
                        }
                        if(array_key_exists("maxOccurs", $element)) {
                            $element_max_occurs = $element["maxOccurs"];
                            if($element_max_occurs !== NULL) {
                                $element_ele->setAttribute("maxOccurs", $element_max_occurs);
                            }
                        }

                        $seq->appendChild($element_ele);
                        
                        $type_attribute = NULL;
                        if(strstr($element_type, "xsd:") !== FALSE) {
                            $type_attribute_value = $element_type;
                        }
                        else {
                            //finding the type with the name..
                            $type_entry = NULL;
                            foreach($xsd_types as $xsd_type_inner) {
                                if($xsd_type_inner["name"] == $element_type) {
                                    $type_entry = $xsd_type_inner;
                                    break;
                                }
                            }
                      
                            $type_ns = $type_entry["namespace"];
                            if($type_ns == NULL) {
                                $type_ns = $this->ns;
                            }
                            
                            $created_type_namespace = $this->createNamespace($type_ns, $wsdl_doc, $types_ele, $public_ns_map,
                                            $public_schema_map, $public_ns_index);
                            $type_prefix = $created_type_namespace["prefix"];
                      
                            $type_attribute_value = $type_prefix.":".$element_type;
                        }
                        if($type_attribute_value) {
                            $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, $type_attribute_value);
                        }
                    }
                }
            }
        }
    }

    /**
     * this function creates a new namespace in the root node with a unique prefix
     * + create a schema element inside the types element in the wsdl
     */
    private function createNamespace($namespace, DomDocument $wsdl_doc, $types_ele, &$public_ns_map,
                            &$public_schema_map, &$public_ns_index) {

        if(array_key_exists($namespace, $public_ns_map)) {
            $prefix = $public_ns_map[$namespace];
            $schema_ele = $public_schema_map[$namespace];
        }
        else {
            //namespace doesn't exist
            //generate the next prefix
            $prefix = "ns".$public_ns_index; 
            $public_ns_index ++;
             
            $public_ns_map[$namespace] = $prefix;
           
            // set the schema element to root
            $root_ele = $wsdl_doc->documentElement;
            $root_ele->setAttribute("xmlns:".$prefix, $namespace);

            $schema_ele = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                             WS_WSDL_Const::WS_WSDL_SCHEMA_ATTR_NAME);
            
            $schema_ele->setAttribute(WS_WSDL_Const::WS_WSDL_ELEMENTFORMDEFAULT_ATTR_NAME, 
                               WS_WSDL_Const::WS_WSDL_QUALIFIED_ATTR_NAME);
            
            $schema_ele->setAttribute(WS_WSDL_Const::WS_WSDL_DEF_TARGET_NS,
                              $namespace);

            $types_ele->appendChild($schema_ele);

            //set the schema element
            $public_schema_map[$namespace] = $schema_ele;
        }
        return array("schema" => $schema_ele, "prefix" => $prefix);
    }

    /**
     * Function that creates types elements(schema) for WSDL1.1 in
     * doc-lit style 
     * @param DomDocument $wsdl_doc DomDocument element of the wsdl document
     * @param DomElement $wsdl_root service dom element
     */
    public function createDocLitType(DomDocument $wsdl_doc, DomElement $wsdl_root)
    {

        $return_array = array();
        $types_ele = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                            WS_WSDL_Const::WS_WSDL_TYPES_ATTR_NAME);
        $wsdl_root->appendChild($types_ele);
        $schema_ele = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                         WS_WSDL_Const::WS_WSDL_SCHEMA_ATTR_NAME);

        $schema_ele->setAttribute(WS_WSDL_Const::WS_WSDL_ELEMENTFORMDEFAULT_ATTR_NAME, 
                           WS_WSDL_Const::WS_WSDL_QUALIFIED_ATTR_NAME);

        $schema_ele->setAttribute(WS_WSDL_Const::WS_WSDL_DEF_TARGET_NS,
                          $this->ns);

        $schema_root = $schema_ele;

        $types_ele->appendChild($schema_ele);

        /* here the structure of the param is
                Array
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

        foreach ($this->schemaTypes as $function_name => $params)
        {
            $ret_array[$function_name] = array();
            if(array_key_exists(WS_WSDL_Const::WS_WSDL_IN_ATTR_NAME, $params)) {

                $params2 = $params[WS_WSDL_Const::WS_WSDL_IN_ATTR_NAME];
                if($this->classmap) {
                    foreach ($params2 as $paramName => $paramValue)
                    {
                        $xsd_type =  $paramValue["type"];
                        $element_ele = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                        $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $paramName);
                        if($paramValue["object"] == "object")
                        {
                            $object_return = $this->createSchemaType($wsdl_doc, $types_ele, $xsd_type);
                            
                            $object_prefix = $object_return["prefix"];
                            $object_namespace = $object_return["namespace"];

                            $schema_root->setAttribute("xmlns:".$object_prefix, $object_namespace);
                            $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, $object_prefix.":".$xsd_type);
                        }
                        else
                        {
                            $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$xsd_type);
                        }
                        $schema_ele->appendChild($element_ele);
                        $return_array[$function_name]["in"] = WS_WSDL_Const::WS_WSDL_DEFAULT_SCHEMA_ATTR_NAME.":".$paramName;
                    }
                }
                else {
                    $ct = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                             WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                    foreach($this->fun_mapping as $key => $value)
                    {
                        if ($value == $function_name)
                            $ct->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $key);
                    }
                    $schema_ele->appendChild($ct);
                    $comtype = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME);
                    $ct->appendChild($comtype);
                    $seq = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                      WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME);

                    $comtype->appendChild($seq);
                    foreach ($params2 as $paramName => $paramValue)
                    {
                        $xsd_type =  $paramValue["type"];
                        $element_ele = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                        $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $paramName);
                        if($paramValue["array"] == "array")
                        {
                            $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_ATTR_MAX_OCCURS, WS_WSDL_Const::WS_WSDL_ATTR_VALUE_UNBOUNDED);
                        }
                        
                        if($paramValue["object"] == "object")
                        {
                            $object_return = $this->createSchemaType($wsdl_doc, $types_ele, $xsd_type);
                            
                            $object_prefix = $object_return["prefix"];
                            $object_namespace = $object_return["namespace"];

                            $schema_root->setAttribute("xmlns:".$object_prefix, $object_namespace);
                            $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, $object_prefix.":".$xsd_type);
                        }
                        else
                        {
                            $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$xsd_type);
                        }
                        

                        $seq->appendChild($element_ele);

                    }
                }
            }
            else {
                //just create an empty schema type
                $ct = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                  WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                $ct->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $function_name);
                $schema_ele->appendChild($ct);

                $comtype = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                      WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME);
                $ct->appendChild($comtype);
                $seq = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                  WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME);
                $comtype->appendChild($seq);
            }

            if(array_key_exists(WS_WSDL_Const::WS_WSDL_OUT_ATTR_NAME, $params)) {

                $params2 = $params[WS_WSDL_Const::WS_WSDL_OUT_ATTR_NAME];
                if($this->classmap) {
                    foreach ($params2 as $paramName => $paramValue)
                    {
                        $xsd_type =  $paramValue["type"];
                        $element_ele = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                        $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $paramName);
                        
                        if($paramValue["object"] == "object")
                        {
                            $object_return = $this->createSchemaType($wsdl_doc, $types_ele, $xsd_type);
                            
                            $object_prefix = $object_return["prefix"];
                            $object_namespace = $object_return["namespace"];

                            $schema_root->setAttribute("xmlns:".$object_prefix, $object_namespace);

                            $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, $object_prefix.":".$xsd_type);
                        }
                        else
                        {
                            $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$xsd_type);
                        }
                        $schema_ele->appendChild($element_ele);
                        $return_array[$function_name]["out"] = WS_WSDL_Const::WS_WSDL_DEFAULT_SCHEMA_ATTR_NAME.":".$paramName;
                    }
                }
                else {
                    $ct = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                 WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                    foreach($this->fun_mapping as $key => $value){
                        if ($value == $function_name)
                            $ct->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                              $key.WS_WSDL_Const::WS_WSDL_RESPONSE_ATTR_NAME);
                    }
                    $schema_ele->appendChild($ct);
                    $comtype = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME);
                    $ct->appendChild($comtype);
                    $seq = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                      WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME);

                    $comtype->appendChild($seq);

                    foreach ($params2 as $paramName => $paramValue)
                    {
                        $xsd_type =  $paramValue["type"];
                        $element_ele = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                        $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $paramName);
                        if($paramValue["array"] == "array")
                        {
                            $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_ATTR_MAX_OCCURS, WS_WSDL_Const::WS_WSDL_ATTR_VALUE_UNBOUNDED);
                        }
                        
                        if($paramValue["object"] == "object")
                        {
                            $object_return = $this->createSchemaType($wsdl_doc, $types_ele, $xsd_type);
                            
                            $object_prefix = $object_return["prefix"];
                            $object_namespace = $object_return["namespace"];

                            $schema_root->setAttribute("xmlns:".$object_prefix, $object_namespace);

                            $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, $object_prefix.":".$xsd_type);
                        }
                        else
                        {
                            $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$xsd_type);
                        }
                        
                        $seq->appendChild($element_ele);
                    }
                }
            }
            else {
                //just create an empty schema type
                $ct = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                  WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                $ct->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $function_name."Response");
                $schema_ele->appendChild($ct);

                $comtype = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                      WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME);
                $ct->appendChild($comtype);
                $seq = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                  WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME);
                $comtype->appendChild($seq);
            }
        }
        return $return_array;
    }

    /**
     * Function that creates types elements(schema) for WSDL1.1 in  rpc style
     * @param DomDocument $wsdl_doc DomDocument element of the wsdl document
     * @param DomElement $wsdl_root service dom element
     */

    public function createRPCType(DomDocument $wsdl_doc, DomElement $wsdl_root)
    {
    
        $class_to_prefix = array();

        $types = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                            WS_WSDL_Const::WS_WSDL_TYPES_ATTR_NAME);
        $wsdl_root->appendChild($types);

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
                            $object_return = $this->createSchemaType($wsdl_doc, $types, $xsd_type);
                            
                            $object_prefix = $object_return["prefix"];
                            $object_namespace = $object_return["namespace"];

                            $wsdl_root->setAttribute("xmlns:".$object_prefix, $object_namespace);
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
                            $object_return = $this->createSchemaType($wsdl_doc, $types, $xsd_type);
                            
                            $object_prefix = $object_return["prefix"];
                            $object_namespace = $object_return["namespace"];

                            $wsdl_root->setAttribute("xmlns:".$object_prefix, $object_namespace);
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
     * @param DomElement $wsdl_root service dom element
     */

    public function createWsdl2Type(DomDocument $wsdl_doc, DomElement $wsdl_root)
    {
        $types = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                            WS_WSDL_Const::WS_WSDL_TYPES_ATTR_NAME);
        $wsdl_root->appendChild($types);
        $el = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                         WS_WSDL_Const::WS_WSDL_SCHEMA_ATTR_NAME);

        $el->setAttribute(WS_WSDL_Const::WS_WSDL_ELEMENTFROMDEFAULT_ATTR_NAME,
                          WS_WSDL_Const::WS_WSDL_QUALIFIED_ATTR_NAME);
        $types->appendChild($el);


        foreach ($this->schemaTypes as $function_name => $params)
        {
            foreach ($params as $requestType => $params2)
            {
                $ct = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                 WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                if ($requestType == WS_WSDL_Const::WS_WSDL_IN_ATTR_NAME)
                {
                    $ct->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                      $function_name);
                    $el->appendChild($ct);
                    $comtype = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME);
                    $ct->appendChild($comtype);
                    $seq = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                      WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME);

                    $comtype->appendChild($seq);
                    foreach ($params2 as $paramName => $xsType)
                    {
                        $element_ele = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                        $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $paramName);
                        $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$xsType);
                        $seq->appendChild($element_ele);
                    }
                }
                if ($requestType == WS_WSDL_Const::WS_WSDL_OUT_ATTR_NAME)
                {
                    $ct->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                      $function_name.WS_WSDL_Const::WS_WSDL_RESPONSE_ATTR_NAME);
                    $el->appendChild($ct);
                    $comtype = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME);
                    $ct->appendChild($comtype);
                    $seq = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                      WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME);

                    $comtype->appendChild($seq);

                    foreach ($params2 as $paramName => $xsType)
                    {
                        $element_ele = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                                          WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                        $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $paramName);
                        $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$xsType);
                        $seq->appendChild($element_ele);
                    }
                }
            }
        }
    }

    public function createSchemaType($wsdl_doc, $wsdl_root, $classname){
        
        require_once("WS_WSDL_Operations.php");
        
        static $i = 0;

        $class = new ReflectionClass($classname);

        if($class == NULL)
        {
           return;
        }

        $namespace = WS_WSDL_Const::WS_WSDL_SCHEMA_TYPE_DEFAULT_NS;
        $class_comment = $class->getDocComment();

        if(preg_match_all('|@namespace\s+([^\s]+).*|', $class_comment, $matches, PREG_SET_ORDER))
        {
            $namespace = $matches[0][1];
        }

        $prefix = NULL;

        $schema_root = NULL;

        foreach($wsdl_root->childNodes as $child)
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
            $schema_root = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                             WS_WSDL_Const::WS_WSDL_SCHEMA_ATTR_NAME);

            $schema_root->setAttribute(WS_WSDL_Const::WS_WSDL_ELEMENTFORMDEFAULT_ATTR_NAME, 
                               WS_WSDL_Const::WS_WSDL_QUALIFIED_ATTR_NAME);

            $schema_root->setAttribute(WS_WSDL_Const::WS_WSDL_DEF_TARGET_NS,
                              $namespace);


            $wsdl_root->appendChild($schema_root);
        }

        $comtype = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                      WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME);
        $comtype->setAttribute("name", $classname);
        $schema_root->appendChild($comtype);
        $seq = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                  WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME);

        $comtype->appendChild($seq);


        if(array_key_exists($namespace, $this->namespace_array) &&
                $this->namespace_array[$namespace] != NULL)
        {
            $prefix = $this->namespace_array[$namespace];
        }
        else
        {
            $prefix = "ns".$i;
            $this->namespace_array[$namespace] = $prefix;
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

                if(preg_match_all('|@var\s+(?:(array)\s+of\s+)?(?:(object)\s+)?(\w+)\s+(.*)|', $property_comment,
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

                $element_ele = $wsdl_doc->createElementNS(WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                                  WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME);
                $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $name);
                if($array == "array")
                {
                    $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_ATTR_MAX_OCCURS, WS_WSDL_Const::WS_WSDL_ATTR_VALUE_UNBOUNDED);
                }
                if($object == "object")
                {
                    $object_return = $this->createSchemaType($wsdl_doc, $wsdl_root, $xsd_type);

                    $object_prefix = $object_return["prefix"];
                    $object_namespace = $object_return["namespace"];

                    $schema_root->setAttribute("xmlns:".$object_prefix, $object_namespace);

                    $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, $object_prefix.":".$xsd_type);
                }
                else
                {
                    $element_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME.$xsd_type);
                }
                $seq->appendChild($element_ele);
            }
        }
        return array("prefix"=> $prefix, "namespace" => $namespace);
    }
}

?>

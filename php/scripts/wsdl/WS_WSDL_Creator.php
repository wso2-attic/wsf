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

require_once('WS_WSDL_Consts.php');
require_once('WS_WSDL_Operations.php');
require_once('WS_WSDL_Type.php');
require_once('WS_WSDL_Message.php');
require_once('WS_WSDL_Port.php');
require_once('WS_WSDL_Binding.php');
require_once('WS_WSDL_Service.php');
require_once('WS_WSDL_Interface.php');


/**
 * This class does create wsdl by calling the other WS_WSDL_* classes 
 * and returns a php string which include the wsdl 
 *
 */
class WS_WSDL_Creator
{
    public $namespace;
    private $endpoint;
    private $f_arry;
    private $class_arry;
    private $service_name;
    private $Binding_style;
    private $wsdl_version;
    public $ops_to_functions;
    private $classmap;
    private $annotations;

    /**
     * Constructor of the class
     * @param string $f_array array of functions 
     * @param string $class_array array of functions 
     * @param string $service name of the service
     * @param string $endpoint endpoint location of the service
     * @param string $binding_style binding style of the service
     * @param string $ns namespace
     * @param string $wsdl_ver wsdl_version(wsdl1.1 or wsdl2)
     */
    function __construct($f_arry, $class_arry, $service, $endpoints,
                         $binding_style,  $ns , $wsdl_ver,
                         $op_arry, $classmap, $annotations)
    {
        if(!$ns) {
            $this->namespace = $endpoints;
        }
        else {
            $this->namespace = $ns;
        }

        $this->endpoint = $endpoints;
        $this->f_arry = $f_arry;
        $this->class_arry = $class_arry;
        $this->service_name = $service;
        $this->Binding_style = $binding_style;
        if($wsdl_ver == "wsdl1.1") {
            $this->wsdl_version = "wsdl1";
        }
        if($wsdl_ver == "wsdl2.0") {
            $this->wsdl_version = "wsdl2";
        }
        $this->ops_to_functions = $op_arry;
        $this->classmap = $classmap;
        
        $this->annotations = $annotations;
    }

    /**
     * Creates the wsdl document for WSDL1.1
     */
    private function buildWsdlDom() {
        $wsdl_dom = new DomDocument(WS_WSDL_Const::WS_DOM_DOCUMENT_VERSION_NO,
                                    WS_WSDL_Const::WS_DOM_DOCUMENT_ENCODING);

        $wsdl_root_ele = $wsdl_dom->createElementNS(WS_WSDL_const::WS_SCHEMA_WSDL_NAMESPACE,
                                                    WS_WSDL_const::WS_WSDL_DEFINITION);
        $wsdl_dom->appendChild($wsdl_root_ele);

        $wsdl_root_ele->setAttributeNS(WS_WSDL_const::WS_WSDL_DEF_SCHEMA_URI,
                                       WS_WSDL_const::WS_WSDL_DEF_XSD_QN,
                                       WS_WSDL_const::WS_SOAP_XML_SCHEMA_NAMESPACE);

        $wsdl_root_ele->setAttributeNS(WS_WSDL_const::WS_WSDL_DEF_SCHEMA_URI,
                                       WS_WSDL_const::WS_WSDL_DEF_TNS_QN,
                                       $this->namespace);

        $wsdl_root_ele->setAttributeNS(WS_WSDL_const::WS_WSDL_DEF_SCHEMA_URI,
                                       WS_WSDL_const::WS_WSDL_DEF_ELEMENT_PREFIX,
                                       $this->namespace. WS_WSDL_Const::WS_WSDL_DEF_ELEMENT_NS_POSTFIX);

        $wsdl_root_ele->setAttributeNS(WS_WSDL_const::WS_WSDL_DEF_SCHEMA_URI,
                                       WS_WSDL_const::WS_WSDL_DEF_SOAP_ENV_QN,
                                       WS_WSDL_const::WS_SCHEMA_SOAP_NAMESPACE);

        $wsdl_root_ele->setAttributeNS(WS_WSDL_const::WS_WSDL_DEF_SCHEMA_URI,
                                       WS_WSDL_const::WS_WSDL_DEF_WSDL_QN,
                                       WS_WSDL_const::WS_SCHEMA_WSDL_NAMESPACE);

        $wsdl_root_ele->setAttributeNS(WS_WSDL_const::WS_WSDL_DEF_SCHEMA_URI,
                                       WS_WSDL_const::WS_WSDL_DEF_SOAP_ENC_QN,
                                       WS_WSDL_const::WS_SOAP_SCHEMA_ENCODING_NAMESPACE);

        $wsdl_root_ele->setAttributeNS(WS_WSDL_const::WS_WSDL_DEF_SCHEMA_URI,
                                       WS_WSDL_const::WS_WSDL_DEF_HTTP_QN,
                                       WS_WSDL_const::WS_WSDL_HTTP12_NAMESPACE);

        
        $wsdl_root_ele->setAttribute(WS_WSDL_const::WS_WSDL_DEF_TARGET_NS,
                                     $this->namespace);


        $oper_obj = new WS_WSDL_Operations($this->f_arry, $this->class_arry);

        $createdTypeArry = $oper_obj->createdTypes;
        $operationsArry = $oper_obj->operations;
        $xsdArry = $oper_obj->xsdTypes;


        if($this->Binding_style == "doclit") {

            $type_obj = new WS_WSDL_Type($this->namespace, $createdTypeArry,
                                     $xsdArry, $this->ops_to_functions, $this->classmap);
            if($this->annotations) {
                $ele_names_info = $type_obj->createDocLitTypeWithAnnotations($wsdl_dom, 
                                    $wsdl_root_ele, $this->annotations);
            }
            else {
                $ele_names_info = $type_obj->createDocLitType($wsdl_dom, $wsdl_root_ele);
            }

            $msg_obj = new WS_WSDL_Message($operationsArry, $this->ops_to_functions, $this->classmap);
            $msg_obj->createDocLitMessage($wsdl_dom,$wsdl_root_ele, $ele_names_info);
        }

        if ($this->Binding_style == "rpc") {
            $type_obj = new WS_WSDL_Type($this->namespace, $createdTypeArry, 
                                        $xsdArry, $this->ops_to_functions, $this->classmap);
            /* no types for the time being */
            $class_to_prefix = $type_obj->createRPCType($wsdl_dom, $wsdl_root_ele);

            $msg_obj = new WS_WSDL_Message($operationsArry, $this->ops_to_functions, $this->classmap);
            $msg_obj->createRPCMessage($wsdl_dom,$wsdl_root_ele, $class_to_prefix);

        }



        $port_obj = new WS_WSDL_Port($this->service_name, $operationsArry, $this->ops_to_functions);
        $port_obj->createPortType($wsdl_dom, $wsdl_root_ele);

        if ($this->Binding_style == "doclit") {
            $bind_obj = new WS_WSDL_Binding($this->service_name,
                                           $this->endpoint, $operationsArry, $this->ops_to_functions);
            $bind_obj->createDocLitBinding($wsdl_dom, $wsdl_root_ele);
        }

        if ($this->Binding_style == "rpc") {
            $bind_obj = new WS_WSDL_Binding($this->service_name, $this->endpoint,
                                           $operationsArry, $this->ops_to_functions);
            $bind_obj->createRPCBinding($wsdl_dom, $wsdl_root_ele);

        }

        $svr_obj = new WS_WSDL_Service($this->service_name, $this->endpoint);
        $svr_obj->createService($wsdl_dom, $wsdl_root_ele);



        return $wsdl_dom->saveXML();

    }

    /**
     * Creates wsdl for WSDL 2.0
     *
     */
    private function buildWsdl2Dom() {
        $wsdl_dom = new DomDocument(WS_WSDL_Const::WS_DOM_DOCUMENT_VERSION_NO,
                                    WS_WSDL_Const::WS_DOM_DOCUMENT_ENCODING);

        $wsdl_root_ele = $wsdl_dom->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                         WS_WSDL_Const::WS_WSDL2_DESCRIPTION);



        $wsdl_root_ele->setAttributeNS(WS_WSDL_Const::WS_WSDL_DEF_SCHEMA_URI,
                                       WS_WSDL_Const::WS_WSDL2_WSDLX_ATTR_NAME,
                                       WS_WSDL_Const::WS_WSDL2_WSDLX_ATTR_VAL);

        $wsdl_root_ele->setAttributeNS(WS_WSDL_Const::WS_WSDL_DEF_SCHEMA_URI,
                                       WS_WSDL_Const::WS_WSDL_DEF_TNS_QN,
                                       $this->namespace);

        $wsdl_root_ele->setAttributeNS(WS_WSDL_Const::WS_WSDL_DEF_SCHEMA_URI,
                                       WS_WSDL_Const::WS_WSDL2_WSOAP_ATTR_NAME,
                                       WS_WSDL_Const::WS_WSDL2_WSOAP_ATTR_VAL);

        $wsdl_root_ele->setAttributeNS(WS_WSDL_Const::WS_WSDL_DEF_SCHEMA_URI,
                                       WS_WSDL_Const::WS_WSDL2_WHTTP_ATTR_NAME,
                                       WS_WSDL_Const::WS_WSDL2_WHTTP_ATTR_VAL);

        $wsdl_root_ele->setAttributeNS(WS_WSDL_Const::WS_WSDL_DEF_SCHEMA_URI,
                                       WS_WSDL_Const::WS_WSDL_DEF_SOAP_ENC_QN,
                                       WS_WSDL_Const::WS_WSDL2_SOAP_ATTR_VAL);

        $wsdl_root_ele->setAttribute(WS_WSDL_Const::WS_WSDL_DEF_TARGET_NS,
                                     $this->namespace);


//        $wsdl_doc_ele = $wsdl_dom->createElement(WS_WSDL_Const::WS_WSDL2_DOCUMENTATION);
//        $doc_txt = new DomText("A simple ".$this->service_name." service");
//        $wsdl_doc_ele->appendChild($doc_txt);
//        $wsdl_root_ele->appendChild($wsdl_doc_ele);


        $oper_obj = new WS_WSDL_Operations($this->f_arry, $this->class_arry);
        $createdTypeArry = $oper_obj->createdTypes;
        $operationsArry = $oper_obj->operations;
        $xsdArry = $oper_obj->xsdTypes;


        $type_obj = new WS_WSDL_Type($this->namespace, $createdTypeArry,
                                    $xsdArry, $this->ops_to_functions, $this->classmap);
        $type_obj->createWsdl2Type($wsdl_dom, $wsdl_root_ele);

        $interface_obj = new WS_WSDL_Interface($this->service_name,
                                              $operationsArry);
        $interface_obj->createInterface($wsdl_dom, $wsdl_root_ele);

        $bind_obj = new WS_WSDL_Binding($this->service_name,
                                       $this->endpoint,NULL, $this->ops_to_functions);
        $bind_obj->createWsdl2Binding($wsdl_dom, $wsdl_root_ele);

        $svr_obj = new WS_WSDL_Service($this->service_name,
                                      $this->endpoint);
        $svr_obj->createWsdl2Service($wsdl_dom, $wsdl_root_ele);


        $wsdl_dom->appendChild($wsdl_root_ele);
        return $wsdl_dom->saveXML();

    }

    /**
     * Returns the string created from wsdl to c-level
     *
     */

    public function WS_WSDL_Out() {
        if ($this->wsdl_version == "wsdl1")
            $tmp = $this->buildWsdlDom();
        else
            $tmp = $this->buildWsdl2Dom();
        return $tmp;
    }



}
?>

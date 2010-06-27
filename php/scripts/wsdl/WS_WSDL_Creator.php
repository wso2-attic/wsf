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
    private $r_actions;
    private $use_wsa;

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
    function __construct($f_arry, $class_arry, $service, $endpoint,
                         $binding_style,  $ns , $wsdl_ver,
                         $op_arry, $classmap, $annotations, $r_actions, $use_wsa)
    {
        if(!$ns) {
            $this->namespace = $endpoints;
        }
        else {
            $this->namespace = $ns;
        }

        $this->endpoint = $endpoint;
        $this->f_arry = $f_arry;
        $this->class_arry = $class_arry;
        $this->service_name = $service;
        $this->Binding_style = $binding_style;
        $this->ops_to_functions = $op_arry;
        $this->classmap = $classmap;
        
        $this->annotations = $annotations;
        $this->r_actions = $r_actions;

        $this->use_wsa = $use_wsa;
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

        $wsdl_root_ele->setAttribute("xmlns:".WS_WSDL_Const::WS_WSDL_WSAW_PREFIX,
                            WS_WSDL_Const::WS_WSDL_WSAW_NAMESPACE);
        
        $wsdl_root_ele->setAttribute(WS_WSDL_const::WS_WSDL_DEF_TARGET_NS,
                                     $this->namespace);



        if(!$this->annotations) {
            // we infer doc comments only when annotations are not provided as an array
            $oper_obj = new WS_WSDL_Operations($this->f_arry, $this->class_arry);
            $schemaTypes = $oper_obj->getSchemaTypes();
            $operations = $oper_obj->operations;
        }


        if($this->Binding_style == WS_WSDL_Const::WSF_WSDL_DOCLIT) {

            $type_obj = new WS_WSDL_Type($this->namespace, $this->ops_to_functions, $this->classmap);

            if($this->annotations) {
                $ele_names_info = $type_obj->createDocLitTypeWithAnnotations($wsdl_dom, 
                                    $wsdl_root_ele, $this->annotations);
                $operations = $ele_names_info;
                $this->classmap = array(0); //should just go with the classmap behaviour
            }
            else {
                $ele_names_info = $type_obj->createDocLitType($wsdl_dom, $wsdl_root_ele, $schemaTypes);
            }

            $msg_obj = new WS_WSDL_Message($operations, $this->ops_to_functions, $this->classmap);
            $msg_obj->createDocLitMessage($wsdl_dom, $wsdl_root_ele, $ele_names_info);
        }

        if ($this->Binding_style == WS_WSDL_Const::WSF_WSDL_RPC) {
            $type_obj = new WS_WSDL_Type($this->namespace, $this->ops_to_functions, $this->classmap);

            // class to prefix will be filled from the following function call
            $class_to_prefix = array();
            /* no types for the time being */
            $ele_names_info = $type_obj->createRPCType($wsdl_dom, $wsdl_root_ele,
                                        $class_to_prefix, $schemaTypes);

            $msg_obj = new WS_WSDL_Message($operations, $this->ops_to_functions, $this->classmap);
            $msg_obj->createRPCMessage($wsdl_dom,$wsdl_root_ele, $class_to_prefix, $ele_names_info);

        }

        $port_obj = new WS_WSDL_Port($this->service_name, $ele_names_info, $this->ops_to_functions, 
                                            $this->use_wsa, $this->r_actions);
        $port_obj->createPortType($wsdl_dom, $wsdl_root_ele, $ele_names_info);

        if ($this->Binding_style == WS_WSDL_Const::WSF_WSDL_DOCLIT) {
            $bind_obj = new WS_WSDL_Binding($this->service_name,
                                           $this->endpoint, $ele_names_info,
                                           $this->ops_to_functions, $this->r_actions);
            $bind_obj->createDocLitBinding($wsdl_dom, $wsdl_root_ele, $ele_names_info);
        }

        if ($this->Binding_style == WS_WSDL_Const::WSF_WSDL_RPC) {
            $bind_obj = new WS_WSDL_Binding($this->service_name, $this->endpoint,
                                           $ele_names_info, $this->ops_to_functions,
                                           $this->r_actions);
            $bind_obj->createRPCBinding($wsdl_dom, $wsdl_root_ele);

        }

        $svr_obj = new WS_WSDL_Service($this->service_name, $this->endpoint);
        $svr_obj->createService($wsdl_dom, $wsdl_root_ele);



        return $wsdl_dom->saveXML();

    }

    /**
     * Returns the string created from wsdl to c-level
     *
     */
    public function WS_WSDL_Out() {
        return $this->buildWsdlDom();
    }



}
?>

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
 * This class is used to generate Binding elements in the WSDL
 */

class WS_WSDL_Binding
{


    const WS_WSDL2_BINDING_VERSION_ATTR_VAL = "1.2";

    private $svr_name;
    public  $operations;
    private $wsdl_location;
    private $fun_mapping;
    private $r_actions;
    private $port;

    /**
     * The constructor of the WS_WSDL_Binding class                    
     * @param string $service_name Name of the service                    
     * @param string $wsdl_ep endpoint location(address)of the service     
     * @param Array $operations Array of operations defined in the service
     */

    function __construct($service_name, $wsdl_ep, $operations = false, $ops_to_functions, $r_actions) {
        $this->svr_name = $service_name;
        $this->operations = $operations;
        $this->wsdl_location = $wsdl_ep;
        $this->fun_mapping = $ops_to_functions;
        $this->r_actions = $r_actions;
	$url = parse_url($this->wsdl_location);
        if(array_key_exists('port',$url))
	{
		$this->port = $url['port'];
	}else{
		$this->port=80;
 	}
}
    /**
     * Function for creating Binding element when the binding style in doc-lit
     * @param DomDocument $binding_doc DomDocument element of the wsdl document 
     * @param DomElement $binding_root root element of the document
     */
    public function createDocLitBinding(DomDocument $binding_doc,
                                        DomElement $binding_root) {
        $binding_ele = $binding_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                       WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME);
        $binding_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                   $this->svr_name."SOAPBinding");
        $binding_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME,
                                  WS_WSDL_Const::WS_WSDL_TNS_ATTR_NAME.":".$this->svr_name."PortType");

        $s_binding = $binding_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_SOAP_NAMESPACE,
                     WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME);
        $s_binding->setAttribute(WS_WSDL_Const::WS_WSDL_TRANSPORT_ATTR_NAME,
                                 WS_WSDL_Const::WS_SCHEMA_SOAP_HTTP_NAMESPACE);
        $s_binding->setAttribute(WS_WSDL_Const::WS_WSDL_STYLE_ATTR_NAME,
                                 WS_WSDL_Const::WS_WSDL_DOCUMENT_ATTR_NAME);
        $binding_ele->appendChild($s_binding);

        foreach($this->operations as $name => $params) {

            $op = $binding_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                WS_WSDL_Const::WS_WSDL_OPERATION_ATTR_NAME);
            foreach($this->fun_mapping as $key => $value) {
                if ($value == $name) {
                    $op->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $key);

                    
                    $action_value = NULL;
                    if($this->r_actions != NULL && array_key_exists($key, $this->r_actions)) {
                        $action_value = $this->r_actions[$key];
                    }
                    else {
		        if ($this->port == 80)
	                       $action_value = WS_WSDL_Const::WS_WSDL_HTTP_ATTR_NAME.$this->wsdl_location."/".$key;
                        elseif ($this->port == 443)
        	               $action_value = WS_WSDL_Const::WS_WSDL_HTTPS_ATTR_NAME.$this->wsdl_location."/".$key;
                        else
	                       $action_value = WS_WSDL_Const::WS_WSDL_HTTP_ATTR_NAME.$this->wsdl_location."/".$key;
                    }
                }
            }

            $action_ele = $binding_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_SOAP_NAMESPACE,
                                  WS_WSDL_Const::WS_WSDL_OPERATION_ATTR_NAME);
            
            if($action_value) {
                $action_ele->setAttribute(WS_WSDL_Const::WS_WSDL_SOAP_ACTION_ATTR_NAME,
                                        $action_value);
            }

            $action_ele->setAttribute(WS_WSDL_Const::WS_WSDL_STYLE_ATTR_NAME,
                                      WS_WSDL_Const::WS_WSDL_DOCUMENT_ATTR_NAME);
            $op->appendChild($action_ele);

            // be sensitive to the available directions
            $directions_arr = array();
            // we anyway have the input part
            $directions_arr []= WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME;
            if(array_key_exists("output", $params)) {
                $directions_arr []= WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME;
            }

            foreach($directions_arr as $type) {

                $sbinding_ele = $binding_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                $type);
                $s_body = $binding_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_SOAP_NAMESPACE,
                                                        WS_WSDL_Const::WS_WSDL_BODY_ATTR_NAME);
                $s_body->setAttribute(WS_WSDL_Const::WS_WSDL_USE_ATTR_NAME,
                                      WS_WSDL_Const::WS_WSDL_LITERAL_ATTR_NAME);
                $sbinding_ele->appendChild($s_body);
                $op->appendChild($sbinding_ele);
            }
            $binding_ele->appendChild($op);
        }
        $binding_root->appendChild($binding_ele);
    }


    /**
     * Function for creating Binding element when the binding style in rpc
     * @param DomDocument $binding_doc DomDocument element of the wsdl document 
     * @param DomElement $binding_root root element of the document
     */
    public function createRPCBinding(DomDocument $binding_doc,
                                     DomElement $binding_root) {
        $binding_ele = $binding_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                       WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME);
        $binding_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, 
                                   $this->svr_name."SOAPBinding");
        $binding_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME,
                                    WS_WSDL_Const::WS_WSDL_TNS_ATTR_NAME.":".$this->svr_name."PortType");

        $s_binding = $binding_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_SOAP_NAMESPACE,
                     WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME);
        $s_binding->setAttribute(WS_WSDL_Const::WS_WSDL_STYLE_ATTR_NAME,
                                 WS_WSDL_Const::WS_WSDL_RPC_ATTR_NAME);
        $s_binding->setAttribute(WS_WSDL_Const::WS_WSDL_TRANSPORT_ATTR_NAME,
                                 WS_WSDL_Const::WS_SCHEMA_SOAP_HTTP_NAMESPACE);
        $binding_ele->appendChild($s_binding);

        foreach($this->operations as $name => $params) {
            $op = $binding_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                                WS_WSDL_Const::WS_WSDL_OPERATION_ATTR_NAME);
            foreach($this->fun_mapping as $key => $value) {
                if ($value == $name) {
                    $op->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $key);

                    $action_value = NULL;
                    if($this->r_actions != NULL && array_key_exists($key, $this->r_actions)) {
                        $action_value = $this->r_actions[$key];
                    }
   	               else {
	      	        if ($this->port == 80)
                          $action_value = WS_WSDL_Const::WS_WSDL_HTTP_ATTR_NAME.$this->wsdl_location."/".$key;
                        elseif ($this->port == 443)
                          $action_value = WS_WSDL_Const::WS_WSDL_HTTPS_ATTR_NAME.$this->wsdl_location."/".$key;
                        else
                           $action_value = WS_WSDL_Const::WS_WSDL_HTTP_ATTR_NAME.$this->wsdl_location."/".$key;
                    }
                }
            }

            $action_ele = $binding_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_SOAP_NAMESPACE,
                                  WS_WSDL_Const::WS_WSDL_OPERATION_ATTR_NAME);
            
            if($action_value) {
                $action_ele->setAttribute(WS_WSDL_Const::WS_WSDL_SOAP_ACTION_ATTR_NAME,
                                        $action_value);
            }
            $op->appendChild($action_ele);


            foreach(array(WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME,
                          WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME) as $type) {
                $sbinding_ele = $binding_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                $type);
                $s_body = $binding_doc->createElementNS(WS_WSDL_Const::WS_SCHEMA_SOAP_NAMESPACE,
                                                        WS_WSDL_Const::WS_WSDL_BODY_ATTR_NAME);
                $s_body->setAttribute(WS_WSDL_Const::WS_WSDL_USE_ATTR_NAME,
                                      WS_WSDL_Const::WS_WSDL_ENCODED_ATTR_NAME);
                $s_body->setAttribute(WS_WSDL_Const::WS_WSDL_ENCOD_STYLE_ATTR_NAME,
                                      WS_WSDL_Const::WS_SOAP_SCHEMA_ENCODING_NAMESPACE);
                
                
                $s_body->setAttribute(WS_WSDL_Const::WS_WSDL_RPC_NAMESPACE,
                                      WS_WSDL_Const::WS_WSDL_RPC_NAMESPACE_VALUE);
                
                $sbinding_ele->appendChild($s_body);
                $op->appendChild($sbinding_ele);
            }
            $binding_ele->appendChild($op);
        }
        $binding_root->appendChild($binding_ele);
    }

    /**
     * Function for creating Binding element in WSDL2.0
     * @param DomDocument $binding_doc DomDocument element of the wsdl document 
     * @param DomElement $binding_root root element of the document
     */
    public function createWsdl2Binding(DomDocument $binding_doc, DomElement $binding_root) {
        $binding_ele = $binding_doc->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                       WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME);
        $binding_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                   $this->svr_name.strtoupper(WS_WSDL_Const::WS_WSDL_SOAP_ATTR_NAME).
                                   ucfirst(WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME));
        $binding_ele->setAttribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME,
                                   WS_WSDL_Const:: WS_WSDL2_WSOAP_ATTR_VAL);

        $binding_ele->setAttribute(WS_WSDL_Const::WS_WSDL_INTERFACE_ATTR_NAME,
                                   $this->svr_name.ucfirst(WS_WSDL_Const::WS_WSDL_INTERFACE_ATTR_NAME));
        $binding_ele->setAttribute(WS_WSDL_Const::WS_WSDL_VERSION_ATTR_NAME,
                                   self::WS_WSDL2_BINDING_VERSION_ATTR_VAL);
        $binding_ele->setAttribute(WS_WSDL_Const::WS_WSDL_PROTOCAL_ATTR_NAME,
                                   WS_WSDL_Const:: WS_WSDL2_BINDING_ATTR_VAL);

        $binding_root->appendChild($binding_ele);
    }




}

?>

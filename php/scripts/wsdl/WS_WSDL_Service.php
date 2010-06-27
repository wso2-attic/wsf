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
 * This class generates the service elements in the WSDL
 */

class WS_WSDL_Service
{

    private $S_name;
    private $endpoint;
    private $port;
    /*
     * The constructor of the WS_WSDL_Service class
     * @param string $ser_name Name of the service
     * @param string $ep endpoint location(address)of the service
     */
    function __construct($ser_name, $ep)
    {
        if($ser_name)
            $this->S_name = $ser_name;
        else
            $this->S_name = "ws_default_service";

        $this->endpoint = $ep;
        $url = parse_url($ep);
        if(array_key_exists('port',$url))
	{
		$this->port = $url['port'];
	}else{
		$this->port=80;
	}
	
    }

    /**
     * Function that creates service elements for WSDL1.1
     * @param DomDocument $svr_name DomDocument element of the wsdl document 
     * @param DomElement $svr_root service dom element 
     */
    public function createService(DomDocument $svr_dom, DomElement $svr_root)
    {
        $svr_ele = $svr_dom->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                             WS_WSDL_const::WS_WSDL_SERVICE_ATTR_NAME);
        $svr_ele->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $this->S_name);

        $svr_port = $svr_dom->createElementNS(WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                              WS_WSDL_Const::WS_WSDL_PORT_ATTR_NAME);
        $svr_port->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                $this->S_name."SOAPPort_Http");
        $svr_port->setAttribute(WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME,
                                WS_WSDL_Const::WS_WSDL_TNS_ATTR_NAME.":".$this->S_name."SOAPBinding");

        $svr_addr = $svr_dom->createElementNS(WS_WSDL_Const::WS_SCHEMA_SOAP_NAMESPACE,
                                              WS_WSDL_Const::WS_WSDL_ADDRESS_ATTR_NAME);

	if ($this->port == 80){
          $svr_addr->setAttribute(WS_WSDL_Const::WS_WSDL_LOCATION_ATTR_NAME,
                                  WS_WSDL_Const::WS_WSDL_HTTP_ATTR_NAME.
                                  $this->endpoint);
	}
        else if ($this->port == 443){
          $svr_addr->setAttribute(WS_WSDL_Const::WS_WSDL_LOCATION_ATTR_NAME,
                                  WS_WSDL_Const::WS_WSDL_HTTPS_ATTR_NAME.
                                  $this->endpoint);
	}
        else{
	        $svr_addr->setAttribute(WS_WSDL_Const::WS_WSDL_LOCATION_ATTR_NAME,
                                WS_WSDL_Const::WS_WSDL_HTTP_ATTR_NAME.
                                $this->endpoint);
	}

        $svr_port->appendChild($svr_addr);
        $svr_ele->appendChild($svr_port);
        $svr_root->appendChild($svr_ele);

    }

    /**
     * Function that creates service elements for WSDL2.0
     * @param DomDocument $svr_name DomDocument element of the wsdl document 
     * @param DomElement $svr_root service dom element 
     */

    public function createWsdl2Service(DomDocument $svr_dom,DomElement $svr_root)
    {
        $svr_ele = $svr_dom->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                             WS_WSDL_Const::WS_WSDL_SERVICE_ATTR_NAME);
        $svr_ele->setAttribute(WS_WSDL_Const::WS_WSDL_SERVICE_ATTR_NAME,
                               $this->S_name);
        $svr_ele->setAttribute(WS_WSDL_Const::WS_WSDL_INTERFACE_ATTR_NAME,
                               $this->S_name.ucfirst(WS_WSDL_Const::WS_WSDL_INTERFACE_ATTR_NAME));


        $svr_port = $svr_dom->createElementNS(WS_WSDL_Const::WS_WSDL2_NAMESPACE,
                                              WS_WSDL_Const::WS_WSDL_ENDPOINT_ATTR_NAME);
        $svr_port->setAttribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                                $this->S_name);
        $svr_port->setAttribute(WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME,
                                "tns".$this->S_name);

        $svr_port->setAttribute(WS_WSDL_Const::WS_WSDL_ADDRESS_ATTR_NAME,
                                $this->endpoint);

        $svr_ele->appendChild($svr_port);
        $svr_root->appendChild($svr_ele);

    }
}

?>

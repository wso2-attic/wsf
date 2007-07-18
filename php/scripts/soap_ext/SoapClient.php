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


/*if (class_exists('SoapClient')) {
    echo "SoapClient exists\n"; 
    return;
}*/

require_once 'SoapParam.php';
require_once 'SoapFault.php';

/**
 * SoapClient represents a Web service client. Has two modes of operation, WSDL
 * and non- WSDL modes. In WSDL mode, user can provide a WSDL that represents
 * the service interface to be consumed. Non-WSDL mode can be used when the user
 * do not have a WSDL to define the interface of the service to be consumed.
 */
class WSSoapClient
{
    
    /**
     * WSDL mode
     * @var mixed
     */
    private $_wsdl;
    
    /**
     * Options to be used by Web service client
     * @var array
     */
    private $_options;
    
    /**
     * WSClient object instance
     * @var WSClient
     */
    private $_client;
    
    /**
     * Options to be used by WSClient 
     * @var array
     */
    private $_clientOptions;
    
   /**
     * This constructor creates SoapClient objects in WSDL or non-WSDL mode.
     *
     * @param  string $wsdl URI of the WSDL file or NULL if working in non-WSDL mode.
     * @param  array $options associative array of options. In non-WSDL mode, 
     * this cannot be null An array of options. If working in WSDL mode, this
     * parameter is optional. If working in non-WSDL mode, you must set the
     * location and uri options. The style and use options only work in non-WSDL
     * mode. In WSDL mode, they come from the WSDL file. 
     * location - the URL to equest 
     * uri - target namespace of the SOAP service
     * style - SOAP style (SOAP_RPC | SOAP_DOCUMENT) 
     * use - SOAP use (SOAP_ENCODED | SOAP_LITERAL) 
     * soap_version - whether to use SOAP 1.1, or SOAP 1.2 (SOAP_1_2 | SOAP_1_1)
     * login, password - HTTP authentication proxy_host, proxy_port,
     * proxy_login, proxy_password - HTTP connection through a proxy server
     * local_cert, passphrase - HTTPS client certificate authentication
     * compression - use compression of HTTP SOAP requests and responses 
     * (SOAP_COMPRESSION_ACCEPT | SOAP_COMPRESSION_GZIP |
     * SOAP_COMPRESSION_DEFLATE) 
     * encoding  - internal character encoding. This option does not change the
     * encoding of SOAP requests (it is always utf- 8), but converts strings
     * into it.
     * classmap - used to map some WSDL types to PHP classes. This option must 
     * be an array with WSDL types as keys and names of PHP classes as values.
     * trace - enables use of the methods SoapClient->__getLastRequest, 
     * SoapClient->__getLastRequestHeaders, SoapClient->__getLastResponse and 
     * SoapClient->__getLastResponseHeaders
     * exceptions - whether soap errors throw exceptions of type SoapFault.
     * connection_timeout - defines a timeout in seconds for the connection to
     * the SOAP service. This option does not define a timeout for services with
     * slow responses. To limit the time to wait for calls to finish the
     * default_socket_timeout setting is available.
     * 
     * @return SoapClient
     * @throws Exception
     */

    /**
     * Options that we have not implemented yet 
     * use-since in WSF-C we can set namespaces in soap-envelop element
     *     can do if opclient is used instead of svc client
     *
     * style -since soap body in axis2 should cantains only one children
     * proxy_login, proxy_password - not yet implemented in axis2c
     * compression - do not support in our API
     * encoding - In WSF-PHP internal character encoding is always utf-8
     */
    
     public function __construct($wsdl, $options = array())
    {
        if (is_null($wsdl)) {
            if (is_null($options)) {
                $fault = new WSSoapFault('Client',
                    "SoapClient::__construct(): Invalid arguments. " .
                    "'location' and 'uri' options are required in nonWSDL mode.");
                throw $fault;
            } else if (is_null($options['uri']) || is_null($options['location'])) {
                $fault = new WSSoapFault('Client',
                    "SoapClient::__construct(): Invalid arguments. " .
                    "'location' and 'uri' options are required in nonWSDL mode.");
                throw $fault; 
            }
            
        } else {
            $options = NULL;
            /* $fault = new WSSoapFault('Client', */
/*                 "SoapClient::__construct(): Invalid arguments. " . */
/*                 "WSO2 WSF/PHP does not support WSDL mode yet."); */
/*             throw $fault; */
        }
        
        $this->_wsdl = $wsdl;
        $this->_options = $options;

        /* Non-wsdl mode options processing */
        if ( !is_null($this->_options)){
            if (!is_null($this->_options['location'])) {
                $this->_clientOptions['to'] = $this->_options['location'];
            }
            
            /* Default SOAP version used by SOAP extension is 1.1 */
            if (!is_null($this->_wsdl))
                $this->_clientOptions['useSOAP'] = '1.1';
            
            if (array_keys($this->_options, 'soap_version') && !is_null($this->_options['soap_version'])) {
                if ($this->_options['soap_version'] == SOAP_1_2)
                    $this->_clientOptions['useSOAP'] = '1.2';
                else if ($this->_options['soap_version'] == SOAP_1_1)
                    $this->_clientOptions['useSOAP'] = '1.1';
            }
            
            /* Proxy support */
            if (array_keys($this->_options, "proxy_host") && !is_null($this->_options['proxy_host'])){
                $this->_clientOptions['proxy_host'] = $this->_options['proxy_host'];
            }
            if ( array_keys($this->_options, "proxy_port") && !is_null($this->_options['proxy_port'])){
                $this->_clientOptions['proxy_port'] = $this->_options['proxy_port'];
            }
            
            /* SSL support- need to  test */
            if (array_keys($this->_options, "local_cert") && !is_null($this->_options['local_cert'])){
                $this->_clientOptions['clientCert'] = $this->_options['local_cert'];
            }
            if ( array_keys($this->_options, "passpharse") && !is_null($this->_options['passpharse'])){
                $this->_clientOptions['passphrase'] = $this->_options['passpharse'];
            }
        }
        /* wsdl-mode */
        if ($this->_wsdl){
            $this->_clientOptions['wsdl'] = $this->_wsdl;
        }
        
        $this->_client = new WSClient($this->_clientOptions);
    } 


    /**
     * Calls a SOAP function (deprecated). Use SoapClient->__soapCall() instead
     * of it.
     * WSO2 WSF/PHP does not support this method.
     * @param string function_name
     * @param array arguments
     * @param array options 
     * @param array input_headers 
     * @param array output_headers
     */
	public function __call($function_name, $arguments)
        {
            if ($function_name){
                $proxy = $this->_client->getProxy();
                $count = count($arguments);
                switch($count){
                    case 0:
                        $val = $proxy->$function_name();
                        break;
                    case 1:
                        $val = $proxy->$function_name($arguments[0]);
                        break;
                    case 2:
                        $val = $proxy->$function_name($arguments[0], $arguments[1]);
                        break;
                    case 3:
                        $val = $proxy->$function_name($arguments[0], $arguments[1], $arguments[2], $arguments[3]);
                        break;
                }
                return $val;
            }
            else
            {
		$fault = new WSSoapFault('Client',
                                         "SoapClient::__call(): deprecated method. " .
                                         "WSO2 WSF/PHP does not support this deprecated method.");
                throw $fault;
            }
        }
	/**
	 * Performs a SOAP request. This method can be overridden in subclasses to
	 * implement different transport layers, perform additional XML processing
	 * or other purpose.
     * 
     * @param string request XML SOAP request
     * @param string location URL to request
     * @param string action SOAP action
     * @param int version SOAP version
     * 
     * @return string XML SOAP response
     */
	public function __doRequest($request, $location, $action, $version)
	{

            if (!is_null($version)) 
                $this->_clientOptions['useSOAP'] = '1.2';

            if(!is_null($location))
                $this->_clientOptions['to'] = $location;
        
            $this->_client = new WSClient($this->_clientOptions);

            if(!is_null($request))
                $result = $this->_client->request($request);
            
            return $result;
            
	}   

	/**
     * Returns list of SOAP functions. Note: This function works only in WSDL
     * mode.
     * 
     * @return array of SOAP functions
	 */
	public function __getFunctions()
	{
            if (is_null($this->_wsdl)) {
                $fault = new WSSoapFault('Client',
                                         "SoapClient::__getFunctions(): only works. " .
                                         "in nonWSDL mode.");
                throw $fault;
            }
            else{
                $proxy = $this->_client->getProxy();
                $val = $proxy->getFunctions();
                return $val;
            }
	}
        
	/**
     * Returns last SOAP request. Note: This method works only if the SoapClient
     * object was created with the trace option.
     * 
     * @return string  last request
	 */
	public function __getLastRequest()
	{
        if (is_null($this->_options) || is_null($this->_options['trace']) || 
            $this->_options['trace'] == 0) {
            $fault = new WSSoapFault('Client',
                "SoapClient::__getLastRequest(): Invalid function call. " .
                "This method only works if trace option is set.");
            throw $fault; 
        }
        
        return $this->_client->getLastRequest();
	}

 
	/**
	 * Returns last SOAP request headers. It is the transport headers and not
	 * the SOAP header that this function returns
     * Note: This method works only if the SoapClient object was created with
     * the trace option
     * 
     * @return string last request headers 
	 */
	public function __getLastRequestHeaders()
	{
		if (is_null($this->_options) || is_null($this->_options['trace']) || 
            $this->_options['trace'] == 0) {
            $fault = new WSSoapFault('Client',
                "SoapClient::__getLastRequestHeaders(): Invalid function call. " .
                "This method only works if trace option is set.");
            throw $fault; 
        }   
	}

	/**
	 * Returns last SOAP response. Note: This method works only if the
	 * SoapClient object was created with the trace option.
     * 
     * @return string last response
	 */
	public function __getLastResponse()
	{
		if (is_null($this->_options) || is_null($this->_options['trace']) || 
            $this->_options['trace'] == 0) {
            $fault = new WSSoapFault('Client',
                "SoapClient::__getLastResponse(): Invalid function call. " .
                "This method only works if trace option is set.");
            throw $fault; 
        }
        
        return $this->_client->getLastResponse();
	}
	 

	/**
	 * Returns last SOAP response headers. Note: This method works only if the 
     * SoapClient object was created with the trace option. Again, it is the
     * transport headers and not the SOAP header that this function returns.
     * 
     * @return string last response headers 
	 */
	public function __getLastResponseHeaders()
	{
            if (is_null($this->_options) || is_null($this->_options['trace']) || 
                $this->_options['trace'] == 0) {
                $fault = new WSSoapFault('Client',
                                         "SoapClient::__getLastResponseHeaders(): Invalid function call. " .
                                         "This method only works if trace option is set.");
                throw $fault; 
            }
	}
        
	/**
	 * Returns list of SOAP types. This function works only in WSDL mode.
         * 
         * @return array list of SOAP types from WSDL
	 */
	public function __getTypes()
	{
            if (is_null($this->_wsdl)) {
                $fault = new WSSoapFault('Client',
                                         "SoapClient::__getTypes(): only works. " .
                                         "in WSDL mode.");
                throw $fault;
            }
            else {
                $proxy = $this->_client->getProxy();
                $val = $proxy->getTypes();
                return $val;
            }
	} 
        
        
	/**
         * Sets a cookie that will be sent with the SOAP request.
         * 
     * @param string name cookie name
     * @param string  value cookie value
     * 
     * @return void
	 */
	public function __setCookie ($name, $value = "")
	{
		
	}

	/**
     * Calls a SOAP function. This is a low level API function that is used to
     * make a SOAP call. Usually, in WSDL mode, you can simply call SOAP
     * functions as SoapClient methods. This method useful in non-WSDL mode when
     * soapaction is unknown, uri differs from the default or when sending
     * and/or receiving SOAP Headers.
     * On  error, a call to a SOAP function can cause PHP to throw exceptions or
     * return a SoapFault object if exceptions are disabled. To check if the
     * function call failed to catch the SoapFault exceptions, check the result
     * with is_soap_fault().
     * SOAP  functions may return one, or multiple values. If only one value is
     * returned by the SOAP function, the return value of __soapCall will be a
     * simple value (e.g. an integer, a string, etc). If multiple values are
     * returned, __soapCall will return an associative array of named output
     * parameters.
     * 
     * @param string function_name name of the function to be called
     * @param array arguments arguments for the function
     * @param array options options to be used when calling the service
     * @param mixed input_headers input SOAP headers
     * @param array  &output_headers output SOAP headers
     * 
     * @return mixed
     */
	public function __soapCall ($function_name, $arguments , $options = null, 
        $input_headers = null, $output_headers = null)
	{
            if ($function_name && $this->_wsdl){
                $proxy = $this->_client->getProxy();
                $count = count($arguments);
                switch($count){
                    case 0:
                        $val = $proxy->$function_name();
                        break;
                    case 1:
                        $val = $proxy->$function_name($arguments[0]);
                        break;
                    case 2:
                        $val = $proxy->$function_name($arguments[0], $arguments[1]);
                        break;
                    case 3:
                        $val = $proxy->$function_name($arguments[0], $arguments[1], $arguments[2], $arguments[3]);
                        break;
                }
                return $val;
            }
            else{
                $params = array();
                $count = count($arguments);
                for ($i = 0; $i < $count; $i++) {
                    if (is_a($arguments[$i], 'WSSoapParam')){
                        $params[] = '<'.$arguments[$i]->_name.'>'.$arguments[$i]->_data.
                            '</'.$arguments[$i]->_name.'>';
                    }
                    else{
                        if (array_keys($this->_options, "use")){
                            if ($this->_options['use'] == SOAP_ENCODED){
                                if(is_string($arguments[$i])){
                                    $params[] = '<param'.$i.' xsi:type="xsd:string">'.$arguments[$i].
                                    '</param'.$i.'>';
                                }
                                if(is_int($arguments[$i])){
                                    $params[] = '<param'.$i.' xsi:type= "xsd:int">'.$arguments[$i].
                                        '</param'.$i.'>';
                                }
                                if(is_bool($arguments[$i])){
                                    $params[] = '<param'.$i.' xsi:type="xsd:bool">'.$arguments[$i].
                                        '</param'.$i.'>';
                                }
                                if(is_object($arguments[$i])){
                                    $params[] = '<param'.$i.' xsi:type="xsd:object">'.$arguments[$i].
                                        '</param'.$i.'>';
                                }
                                if(is_array($arguments[$i])){
                                    $params[] = '<param'.$i.' xsi:type="xsd:array">'.$arguments[$i].
                                        '</param'.$i.'>';
                                }
                                
                            }
                            else if($this->_options['use'] == SOAP_LITERAL){
                                $params[] = '<param'.$i.'>'.$arguments[$i].
                                    '</param'.$i.'>';
                            }
                            
                            $payload = '<ns1:'.$function_name.' xmlns:ns1="'.$this->_options['uri'].'"  xmlns:xsd="http://www.w3.org/2001/XMLSchema"'.'
                                        xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">';
                            
                        }
                        else{
                            $params[] = '<param'.$i.'>'.$arguments[$i].
                                '</param'.$i.'>';
                            $payload = '<ns1:'.$function_name.' xmlns:ns1="'.$this->_options['uri'].'">';
                        }
                        
                    }
                    
                }
                
                $count = count($params);
                for ($i = 0; $i < $count; $i++) {
                    $payload = $payload.$params[$i];
                }
                
                $payload = $payload.'</ns1:'.$function_name.'>';
                try{
                    $result = $this->_client->request($payload);
                    if($result){
/*                         $doc = new DOMDocument(); */
/*                         $doc->loadXML($result->str); */
/*                         return $doc->firstChild->nodeValue; */
//                        var_dump($result->str);
                        return $result->str;
                    }
                }
                catch(Exception $e){
                    if ($e instanceof WSFault){
                        printf("Soap Fault: %s \n", $e->code);
                    }else{
                        printf("Message = %s \n", $e->getMessage());
                    }
                }
            }
        }
        
     /**
     * Sets the location option (the endpoint URL that will be touched by the
     * following SOAP requests). If new_location is not specified or null then
     * SoapClient will use endpoint from WSDL file.
     * 
     * @param string new_location new location to be used
     * @return string old value of location option
   	 */
   	public function __setLocation($new_location = null)
   	{
            if($this->_wsdl && $new_location){
                $proxy = $this->_client->getProxy();
                $old_location = $proxy->getLocation();
                $old_location = $old_location[0];
                $this->_clientOptions["wsdl"] = $this->_wsdl;
                $this->_clientOptions["to"] = $new_location;
                $this->_client = new WSClient($this->_clientOptions);
            }
            else{
                $old_location = $this->_clientOptions["to"];
                if($new_location){
                    $this->_clientOptions["to"] = $new_location;
                    $this->_client = new WSClient($this->_clientOptions);
                    
                }
            }
                echo $old_location."\n";
   		
   	}

	/**
     * Sets SOAP headers for subsequent calls (replaces any previous values).
     * If no value is specified, all of the headers are removed.
     * 
     * @param array soapHeaders SOAP headers to be set
     * @return void
	 */
	public function __setSoapHeaders($soapHeaders)
	{
		
	}

}

?>




















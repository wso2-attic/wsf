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


/*if (class_exists('SoapServer')) {
    echo "SoapServer exists\n"; 
    return;
}*/

require_once 'SoapFault.php';

function generic($inMessage) {
 
    $returnMessage = new WSMessage($inMessage->str);
 
    $doc = new DOMDocument();
    $doc->loadXML($inMessage->str);
    list($ns, $op) = split( ":", $doc->firstChild->tagName, 2);
    if (is_null($op)) {
        $op = $ns;
    }
        call_user_func($op, 'sam');
    return $returnMessage;
}



/**
 * SoapServer represents a Web service. Has two modes of operation, WSDL and
 * non-WSDL modes. In WSDL mode, user can provide a WSDL that represents the
 * service interface. Non-WSDL mode can be used when the user do not have a WSDL
 * to define the service interface.
 */
class WSSoapServer extends WSService
{
    /**
     * WSDL mode
     * @var mixed
     */
    private $_wsdl;
    
    /**
     * Options to be used by Web service
     * @var array
     */
    private $_options;
    
    /**
     * WSService object instance
     * @var WSService
     */
    private $_service;
    
    /**
     * Service operations 
     * @var array
     */
    private $_operations;

    /**
     * Service operation Parameters
     * @var array
     */
    private $_opParams;

    /**
     * SoapServer constructor.
     * 
     * @param mixed wsdl If you want the WSDL mode, you must set this to the URI
     * of a WSDL file. In the other case, you must set this to NULL and set the
     * uri option.
     * @param array options array of options to be used by the Web service.
     * uri - service namespace URI
     * soap_version - default SOAP version (SOAP_1_1  SOAP_1_2) 
     * encoding -internal character encoding 
     * actor - actor URI 
     * classmap - can be used to map some WSDL types to PHP classes. This option
     * must be an array with WSDL types as keys and names of PHP classes as
     * values.
     * @return SoapServer
     * @throws Exception
     */
    public function __construct($wsdl, $options = null) 
    {
        if (is_null($wsdl)) {
            if (is_null($options)) {
                $fault = new WSSoapFault('Server',
                    "SoapServer::__construct(): Invalid arguments. " .
                    "'uri' option is required in nonWSDL mode.");
                throw $fault; 
            } else if (is_null($options['uri'])) {
                $fault = new WSSoapFault('Server',
                    "SoapServer::__construct(): Invalid arguments. " .
                    "'uri' option is required in nonWSDL mode.");
                throw $fault;
            }
            
        } else {
            $fault = new WSSoapFault('Server',
                "SoapServer::__construct(): Invalid arguments. " .
                "WSO2 WSF/PHP does not support WSDL mode yet.");
            throw $fault;
        }
        
        $this->_wsdl = $wsdl;
        $this->_options = $options;
        /*
         * None of the options used by SoapServer are used by WSService.
         * uri - Axis2 does not have a concept of providing a URI for service
         * soap_version  - Axis2 decides the SOAP version to be used by
         * the service based on the SOAP version used by client request.
         * encoding - internal character encoding - not sure how to support
         * this as WSService does not have such a concept
         * actor - Axis2 does not have a concept of an actor URI on server
         * side
         * classmap - can be used to map some WSDL types to PHP classes.
         * This option must be an array with WSDL types as keys and names of PHP
         * classes as values. - to be supported later
         */
    }

    /**
     * Adds one or several functions those will handle SOAP requests
     * 
     * @param mixed functions -
     * To export one function, pass the function name into this parameter as a string.
     * To export several functions, pass an array of function names.
     * To export all the functions, pass a special constant SOAP_FUNCTIONS_ALL.
     * Note: functions must receive all input arguments in the same order as defined 
     * in the WSDL file (They should not receive any output parameters as arguments) 
     * and return one or more values. To return several values they must return an 
     * array with named output parameters.
     * @return void
     */
    public function addFunction($functions) 
    {
        if (is_string($functions)) {
            //$newfunc = create_function("\$m, \$fn = $functions", 
            //            'return new WSMessage("<result><text>".call_user_func($fn, \'sam\')."</result></text>");');
          
//  $this->_operations[$functions] = 'generic';

            $this->_operations[$functions] = $functions;
            $this->_opParams[$functions] = 'MIXED';
            
        }
        
        if (is_array($functions)) {
            $this->_operations = $functions;
            $i = sizeof($functions);
            foreach($functions as $i){
                $this->_opParams[$i] = 'MIXED';
            }
        }
        
        if ($functions === SOAP_FUNCTIONS_ALL) {
            $fault = new WSSoapFault('Server',
                "SoapServer::addFunction(): Invalid arguments. " .
                "WSO2 WSF/PHP does not support SOAP_FUNCTIONS_ALL yet.");
            throw $fault;
        } 
    }

    /**
     * Issue SoapServer fault indicating an error
     * 
     * @param string code fault code
     * @param string string fault string
     * @param string actor fault actor 
     * @param mixed details fault details
     * @param string name fault name
     * @return void
     */
    public function fault($code, $string, $actor = null, $details = null, 
        $name = null) 
    {

    }

    /**
     * Returns list of defined functions. This method returns the list of all
     * functions added by SoapServer->addFunction() or SoapServer->setClass()
     * 
     * @return array of functions
     */
    public function getFunctions() 
    {
        return $this->_operations;
    }

    /**
     * Handles a SOAP request. Processes a SOAP request, calls necessary
     * functions, and sends a response back.
     * 
     * @param string soap_request The SOAP request. If this argument is omitted,
     * the request is supposed to be in the $HTTP_RAW_POST_DATA PHP variable.
     * @return void
     */
    public function handle($soap_request = null) 
    {
        $this->_service = new WSService(array('operations' => $this->_operations, "opParams" => $this->_opParams));
        $this->_service->reply();
    }

    /**
     * Sets class which will handle SOAP requests. Exports all methods from
     * specified class. The object can be made persistent across request for a 
     * given PHP session with the SoapServer->setPersistence() method.
     * 
     * @param string class_name name of the exported class
     * @param mixed args these optional parameters will be passed to the default
     * class constructor during object creation
     * @return void
     */
    public function setClass($class_name, $args = null) 
    {

    }

    /**
     * Sets persistence mode of SoapServer. This function allows saving data
     * between requests in a PHP session. It works only with a server that
     * exports functions from a class with SoapServer->setClass().
     * 
     * @param int mode One of the SOAP_PERSISTENCE_XXX constants.
     * (SOAP_PERSISTENCE_SESSION | SOAP_PERSISTENCE_REQUEST)
     * Note: The persistence SOAP_PERSISTENCE_SESSION makes persistent only 
     * object of given class, but not the class static data. You may use 
     * $this->bar instead of self::$bar.
     * @return void
     */
    public function setPersistence($mode) 
    {

    }
}
?>















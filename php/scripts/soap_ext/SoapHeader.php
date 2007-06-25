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

/*if (class_exists('SoapHeader')) {
    echo "SoapHeader exists\n"; 
    return;
}*/

/**
 * SoapHeader is a special low-level class for passing or returning SOAP
 * headers. It's just a data holder and it does not have any special methods
 * except its constructor. It can be used in the SoapClient->__soapCall() method
 * to pass a SOAP header or in a SOAP header handler to return the header in a
 * SOAP response.
 */
class WSSoapHeader
{
    /**
     * Namespace of the SOAP header element
     * @var string
     */
    private $_namespace;

    /** 
     * Name of the SOAP header element
     * @var string
     */
    private $_name;

    /** 
     * SOAP header's content. It can be a PHP value or a SoapVar object
     * @var mixed
     */
    private $_data;

    /**  
     * Value of the mustUnderstand attribute of the SOAP header element
     * @var bool
     */
    private $_mustUnderstand;

    /**
     * Value of the actor attribute of the SOAP header element
     * @var mixed
     */
    private $_actor;

    /**
     * SoapHeader constructor.
     * 
     * @param string namespace namespace of the SOAP header element
     * @param string name name of the SOAP header element
     * @param mixed data SOAP header's content. It can be a PHP value or a 
     * SoapVar object
     * @param bool mustUnderstand value of the mustUnderstand attribute of the
     * SOAP header element
     * @param mixed actor value of the actor attribute of the SOAP header element 
     * @return SoapHeader
     */
    public function __construct($namespace, $name, $data = null, $mustUnderstand = false, $actor = null)
    {
        $this->_namespace = $namespace;
        $this->_name = $name;
        $this->_data = $data;
        $this->_mustUnderstand = $mustUnderstand;
        $this->_actor = $actor;
    }
}
?>

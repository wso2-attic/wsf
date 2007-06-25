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

/*if (class_exists('SoapVar')) {
    echo "SoapParam exists\n"; 
    return;
}*/

/**
 * SoapVar is a special low-level class for encoding parameters and returning
 * values in non-WSDL mode. It's just a data holder and does not have any
 * special methods except the constructor. It's useful when you want to set the
 * type property in SOAP request or response.
 */
class WSSoapVar
{
    /** 
     * Data to pass or return 
     * @var mixed 
     */
    private $_data;

    /** 
     * Encoding ID, one of the XSD_... constants
     * @var int 
     */
    private $_encoding;

    /**
     * Type name
     * @var string 
     */
    private $_type_name;

    /** 
     * Type namespace
     * @var string 
     */
    private $_type_namespace;

    /** 
     * XML node name
     * @var string 
     */
    private $_node_name;

    /** 
     * XML node namespace
     * @var string 
     */
    private $_node_namespace;

    /*
     * SoapVar constructor. 
     * 
     * @param mixed data data to pass or return
     * @param int encoding encoding ID, one of the XSD_... constants
     * @param string type_name type name
     * @param string type_namespace type namespace
     * @param string node_name XML node name
     * @param string node_namespace XML node namespace
     * @return SoapVar
     */
    public function __construct($data, $encoding, $type_name = null, $type_namespace = null, $node_name = null, $node_namespace = null)
    {
        $this->_data = $data;
        $this->_encoding = $encoding;
        $this->_type_name = $type_name;
        $this->_type_namespace = $type_namespace;
        $this->_node_name = $node_name;
        $this->_node_name = $node_namespace;
    }
}
?>

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

/*if (class_exists('SoapParam')) {
    echo "SoapParam exists\n"; 
    return;
}*/

/**
 * SoapParam is a special low-level class for naming parameters and 
 * returning values in non-WSDL mode. It's just a data holder and it does 
 * not have any special methods except its constructor.
 */
class WSSoapParam
{
    /** 
     * Data to pass or return 
     * @var mixed 
     */
    public $_data;

    /** 
     * Parameter name
     * @var string
     */
    public $_name;

    /**
     * SoapParam constructor.
     * 
     * @param mixed data data to pass or return. You can pass this parameter 
     * directly as PHP value, but in this case it will be named as paramN and 
     * the SOAP Service may not understand it.
     * @param string name parameter name 
     * @return SoapParam
     */
    public function __construct($data, $name)
    {
        $this->_data = $data;
        $this->_name = $name;
    }
}

?>

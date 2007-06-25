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

/*if (class_exists('SoapFault')) {
    echo "SoapFault exists\n"; 
    return;
}*/

/**
 * SoapFault can be used to represent a SOAP fault. This class is useful when
 * you would like to send SOAP fault responses from the PHP Web service.
 */
class WSSoapFault extends Exception
{
    /**
	 * Error code of the SoapFault
     * @var string 
     */
     private $_faultcode;
     
     /**
      * Error message of the SoapFault
      * @var string 
      */
     private $_faultstring;
     
     /**
      * String identifying the actor that caused the error
      *@var string 
      */
     private $_faultactor;
     
     /**
      * Fault detail
      * @var mixed
      */
     private $_detail;
     
     /**
      * Can be used to select the proper fault encoding from WSDL
      * @var  string
      */
     private $_faultname;
     
     /**
      * Can be used during SOAP header handling to report an error in the
      * response header
      * @var SoapHeader  
      */
     private $_headerfault;
      
    /**
     * SoapFault constructor.
     * 
     * @param string faultcode error code of the SoapFault
     * @param string faultstring error message of the SoapFault
     * @param string faultactor string identifying the actor that caused the
     * error
     * @param mixed detail fault detail
     * @param string faultname can be used to select the proper fault encoding
     * from WSDL
     * @param SoapHeader headerfault can be used during SOAP header handling to
     * report an error in the response header
     * @return SoapFault
     */
    public function __construct($faultcode, $faultstring, $faultactor = null, $detail = null, $faultname = null, $headerfault = null)
    {
        $this->_faultcode = $faultcode;
        $this->_faultstring = $faultstring;
        $this->_faultactor = $faultactor;
        $this->_detail = $detail;
        $this->_faultname = $faultname;
        $this->_headerfault = $headerfault;
    }

    /**
     * Returns a string representing the SOAP fault
     * @return string string representing SOAP fault.
     */
    public function __toString()
    {
        $fautstr = "SoapFault exception: [".$this->_faultcode."]".
            $this->_faultstring."\nStack trace:\n";
            
        // get stack trace and attach that to returned string            
        ob_start();
        debug_print_backtrace();
        $trace = ob_get_contents();
        ob_end_clean();
               
        return $fautstr.$trace;
    }
}
?>

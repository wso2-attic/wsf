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

require_once 'SoapParam.php';
require_once 'SoapVar.php';
require_once 'SoapFault.php';
require_once 'SoapHeader.php';
require_once 'SoapClient.php';
require_once 'SoapServer.php'; 
 
/**
 * The constants below are defined by this extension, and will only be available
 * when the extension has either been compiled into PHP or dynamically loaded at 
 * runtime.
 */ 

define("SOAP_1_1", "1");
define("SOAP_1_2", "2");

define("SOAP_PERSISTENCE_SESSION", "1");
define("SOAP_PERSISTENCE_REQUEST", "2");

define("SOAP_FUNCTIONS_ALL", "999");

define("SOAP_ENCODED", "1");
define("SOAP_LITERAL", "2");

define("SOAP_RPC", "1");
define("SOAP_DOCUMENT", "2");

define("SOAP_ACTOR_NEXT", "1");
define("SOAP_ACTOR_NONE", "2");
define("SOAP_ACTOR_UNLIMATERECEIVER", "3");


define("SOAP_COMPRESSION_ACCEPT", "0x20");
define("SOAP_COMPRESSION_GZIP", "0x00");
define("SOAP_COMPRESSION_DEFLATE", "0x10");

define("UNKNOWN_TYPE", "999998");

define("XSD_STRING", "101");

define("XSD_BOOLEAN", "102");

define("XSD_DECIMAL", "103");

define("XSD_FLOAT", "104");

define("XSD_DOUBLE", "105");

define("XSD_DURATION", "106");

define("XSD_DATETIME", "107");

define("XSD_TIME", "108");

define("XSD_DATE", "109");

define("XSD_GYEARMONTH", "110");

define("XSD_GYEAR", "111");

define("XSD_GMONTHDAY", "112");

define("XSD_GDAY", "113");

define("XSD_GMONTH", "114");

define("XSD_HEXBINARY", "115");

define("XSD_BASE64BINARY", "116");

define("XSD_ANYURI", "117");

define("XSD_ANYXML", "147");

define("XSD_QNAME", "118");

define("XSD_NOTATION", "119");

define("XSD_NORMALIZEDSTRING", "120");

define("XSD_TOKEN", "121");

define("XSD_LANGUAGE", "122");

define("XSD_NMTOKEN", "123");

define("XSD_NAME", "124");

define("XSD_NCNAME", "125");

define("XSD_ID", "126");

define("XSD_IDREF", "127");

define("XSD_IDREFS", "128");

define("XSD_ENTITY", "129");

define("XSD_ENTITIES", "130");

define("XSD_INTEGER", "131");

define("XSD_NONPOSITIVEINTEGER", "132");

define("XSD_NEGATIVEINTEGER", "133");

define("XSD_LONG", "134");

define("XSD_INT", "135");

define("XSD_SHORT", "136");

define("XSD_BYTE", "137");

define("XSD_NONNEGATIVEINTEGER", "138");

define("XSD_UNSIGNEDLONG", "139");

define("XSD_UNSIGNEDINT", "140");

define("XSD_UNSIGNEDSHORT", "141");

define("XSD_UNSIGNEDBYTE", "142");

define("XSD_POSITIVEINTEGER", "143");

define("XSD_NMTOKENS", "144");

define("XSD_ANYTYPE", "145");

define("XSD_UR_TYPE", "146");

define("SOAP_ENC_OBJECT", "301");

define("SOAP_ENC_ARRAY", "300");

define("XSD_1999_TIMEINSTANT", "401");

define("XSD_NAMESPACE", "http://www.w3.org/2001/XMLSchema");

define("XSD_1999_NAMESPACE", "http://www.w3.org/1999/XMLSchema"); 
 
?>

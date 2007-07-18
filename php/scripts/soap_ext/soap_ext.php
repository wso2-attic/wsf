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

define("WSSOAP_1_1", "1");
define("WSSOAP_1_2", "2");

define("WSSOAP_PERSISTENCE_SESSION", "1");
define("WSSOAP_PERSISTENCE_REQUEST", "2");

define("WSSOAP_FUNCTIONS_ALL", "999");

define("WSSOAP_ENCODED", "1");
define("WSSOAP_LITERAL", "2");

define("WSSOAP_RPC", "1");
define("WSSOAP_DOCUMENT", "2");

define("WSSOAP_ACTOR_NEXT", "1");
define("WSSOAP_ACTOR_NONE", "2");
define("WSSOAP_ACTOR_UNLIMATERECEIVER", "3");


define("WSSOAP_COMPRESSION_ACCEPT", "0x20");
define("WSSOAP_COMPRESSION_GZIP", "0x00");
define("WSSOAP_COMPRESSION_DEFLATE", "0x10");

define("WSUNKNOWN_TYPE", "999998");

define("WSXSD_STRING", "101");

define("WSXSD_BOOLEAN", "102");

define("WSXSD_DECIMAL", "103");

define("WSXSD_FLOAT", "104");

define("WSXSD_DOUBLE", "105");

define("WSXSD_DURATION", "106");

define("WSXSD_DATETIME", "107");

define("WSXSD_TIME", "108");

define("WSXSD_DATE", "109");

define("WSXSD_GYEARMONTH", "110");

define("WSXSD_GYEAR", "111");

define("WSXSD_GMONTHDAY", "112");

define("WSXSD_GDAY", "113");

define("WSXSD_GMONTH", "114");

define("WSXSD_HEXBINARY", "115");

define("WSXSD_BASE64BINARY", "116");

define("WSXSD_ANYURI", "117");

define("WSXSD_ANYXML", "147");

define("WSXSD_QNAME", "118");

define("WSXSD_NOTATION", "119");

define("WSXSD_NORMALIZEDSTRING", "120");

define("WSXSD_TOKEN", "121");

define("WSXSD_LANGUAGE", "122");

define("WSXSD_NMTOKEN", "123");

define("WSXSD_NAME", "124");

define("WSXSD_NCNAME", "125");

define("WSXSD_ID", "126");

define("WSXSD_IDREF", "127");

define("WSXSD_IDREFS", "128");

define("WSXSD_ENTITY", "129");

define("WSXSD_ENTITIES", "130");

define("WSXSD_INTEGER", "131");

define("WSXSD_NONPOSITIVEINTEGER", "132");

define("WSXSD_NEGATIVEINTEGER", "133");

define("WSXSD_LONG", "134");

define("WSXSD_INT", "135");

define("WSXSD_SHORT", "136");

define("WSXSD_BYTE", "137");

define("WSXSD_NONNEGATIVEINTEGER", "138");

define("WSXSD_UNSIGNEDLONG", "139");

define("WSXSD_UNSIGNEDINT", "140");

define("WSXSD_UNSIGNEDSHORT", "141");

define("WSXSD_UNSIGNEDBYTE", "142");

define("WSXSD_POSITIVEINTEGER", "143");

define("WSXSD_NMTOKENS", "144");

define("WSXSD_ANYTYPE", "145");

define("WSXSD_UR_TYPE", "146");

define("WSSOAP_ENC_OBJECT", "301");

define("WSSOAP_ENC_ARRAY", "300");

define("WSXSD_1999_TIMEINSTANT", "401");

define("WSXSD_NAMESPACE", "http://www.w3.org/2001/XMLSchema");

define("WSXSD_1999_NAMESPACE", "http://www.w3.org/1999/XMLSchema"); 
 
?>















--TEST--
Echo Binary Array As String Array-soap1.1-MTOM
--FILE--
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
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

$reqPayloadString = <<<XML
<EchoBinaryArrayAsStringArray xmlns="http://xmlsoap.org/Ping"><arrayOfArray xmlns:i="http://www.w3.org/2001/XMLSchema-instance" xmlns:x="http://www.w3.org/2001/XMLSchema"><base64Binary xmlns="http://schemas.microsoft.com/2003/10/Serialization/Arrays"><xop:Include href="cid:myid1" xmlns:xop="http://www.w3.org/2004/08/xop/include"/></base64Binary><base64Binary xmlns="http://schemas.microsoft.com/2003/10/Serialization/Arrays"><xop:Include href="cid:myid1" xmlns:xop="http://www.w3.org/2004/08/xop/include"/></base64Binary><base64Binary xmlns="http://schemas.microsoft.com/2003/10/Serialization/Arrays"><xop:Include href="cid:myid1" xmlns:xop="http://www.w3.org/2004/08/xop/include"/></base64Binary></arrayOfArray>
</EchoBinaryArrayAsStringArray>
XML;

try {
	$f = file_get_contents("string.txt");
    
	$reqMessage = new WSMessage($reqPayloadString, 
        array("to" => "http://131.107.72.15/MTOM_Service_Indigo/Soap11MtomUtf8.svc/MtomTest",
              "action" => "http://xmlsoap.org/EchoBinaryArrayAsStringArray",
              "attachments" => array("myid1" => $f)));
	
	$client = new WSClient(array("useMTOM" => TRUE,
                                     "useSOAP" => "1.1",
                                     "useWSA" => TRUE));
/*                                   "proxyHost" => "localhost",*/
/*                                   "proxyPort" => "9093"));*/

	$resMessage = $client->request($reqMessage);
	
         echo $resMessage->str;

} catch (Exception $e) {
	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>
--EXPECT--
<EchoBinaryArrayAsStringArrayResponse xmlns="http://xmlsoap.org/Ping"><EchoBinaryArrayAsStringArrayResult xmlns:a="http://schemas.microsoft.com/2003/10/Serialization/Arrays" xmlns:i="http://www.w3.org/2001/XMLSchema-instance"><a:string>H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! &#13;
</a:string><a:string>H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! &#13;
</a:string><a:string>H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! &#13;
</a:string></EchoBinaryArrayAsStringArrayResult></EchoBinaryArrayAsStringArrayResponse>
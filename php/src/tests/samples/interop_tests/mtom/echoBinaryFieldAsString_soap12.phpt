--TEST--
Echo Binary Field as String- MTOM
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
<EchoBinaryFieldAsString xmlns="http://xmlsoap.org/Ping" xmlns:s="http://schemas.xmlsoap.org/soap/envelope/"><s xmlns:i="http://www.w3.org/2001/XMLSchema-instance" xmlns:x="http://www.w3.org/2001/XMLSchema"><Array><xop:Include href="cid:myid1" xmlns:xop="http://www.w3.org/2004/08/xop/include"/></Array><Name> My Struct </Name></s></EchoBinaryFieldAsString>
XML;

try {
	$f = file_get_contents("short_string.txt");
    
	$reqMessage = new WSMessage($reqPayloadString, 
        array("to" => "http://131.107.72.15/MTOM_Service_Indigo/Soap12MtomUtf8.svc/MtomTest",
              "action" => "http://xmlsoap.org/Ping",
              "attachments" => array("myid1" => $f)));
	
	$client = new WSClient(array("useMTOM" => TRUE,
                                     "useSOAP" => "1.2",
                                     "useWSA" => TRUE));
/*                                   "proxyHost" => "localhost",*/
/*                                   "proxyPort" => "9093"));*/

	$resMessage = $client->request($reqMessage);
	
	echo $resMessage->str;

} catch (Exception $e) {
	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Code);
		printf("Soap Reason: %s\n", $e->Reason);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>
--EXPECT--
<EchoBinaryFieldAsStringResponse xmlns="http://xmlsoap.org/Ping"><EchoBinaryFieldAsStringResult>Hello World&#13;
</EchoBinaryFieldAsStringResult></EchoBinaryFieldAsStringResponse>

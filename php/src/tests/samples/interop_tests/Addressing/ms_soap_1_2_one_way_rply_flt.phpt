--TEST--
SOAP 1.2 one-way message with a ReplyTo and FaultTo address of none
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
<notify xmlns="http://example.org/notify">test</notify>
XML;

try {
   
    $end_point = file_get_contents('epSoap12.txt');
	$reqMessage = new WSMessage($reqPayloadString, 
        array("to" => $end_point,
              "action" => "http://example.org/action/notify",
              "faultTo" => "http://www.w3.org/2005/08/addressing/none",
              "replyTo" => "http://www.w3.org/2005/08/addressing/none"));
	
	$client = new WSClient(array("useSOAP" => "1.2",
                                     "useWSA" => TRUE /*,
                                     "proxyHost" => "localhost",
                                     "proxyPort" => "9090"*/));

	$client->send($reqMessage);
	printf("Message Sent...\n");
	
   } catch (Exception $e) {
	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Code);
	}
}
?>
--EXPECT--
Message Sent...

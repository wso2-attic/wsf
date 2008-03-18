--TEST--
SOAP 1.1 Security -  SSL
--FILE--
<?php
/*
 * Copyright 2005,2007 WSO2, Inc. http://wso2.com
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

// Request payload string 
$reqPayloadString = <<<XML
<ns1:echo xmlns:ns1="http://InteropBaseAddress/interop"><ns1:request>Hello World!</ns1:request></ns1:echo>
XML;

try {
    // Create message with request payload and options
    $reqMessage = new WSMessage($reqPayloadString,
                         array("to" => "https://131.107.72.15/Security_WsSecurity_Service_Indigo/WsSecurity10.svc/UserNameOverTransport",
                               "action" => "http://InteropBaseAddress/interop/echo"));
   
    // Set up security options
    $policy_xml = file_get_contents("transport-binding-policy.xml");
    $policy = new WSPolicy($policy_xml);
    $security_token = new WSSecurityToken(array("user" => "Alice",
                                                "password" => "ecilA",
                                                "passwordType" => "PlainText"));
    
    // Create client with options
    $client = new WSClient(array( "useSOAP" => "1.1",
	                              "useWSA" => TRUE,
                                 "policy" => $policy,
                                 "securityToken" => $security_token,
                                 "CACert" => "keys/root.pem"));
	
    // Send request and capture response
    $resMessage = $client->request($reqMessage);
    
    printf("Response = %s \n", $resMessage->str);

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Reason);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>
--EXPECT--
Response = <echoResponse xmlns="http://InteropBaseAddress/interop"><echoResult>Hello World!</echoResult></echoResponse>

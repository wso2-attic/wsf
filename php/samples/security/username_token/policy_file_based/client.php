<?php
/*
 * Copyright 2005,2008 WSO2, Inc. http://wso2.com
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
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>
XML;

try {
	
    $my_cert = ws_get_cert_from_file("../../keys/alice_cert.cert");
    $my_key = ws_get_key_from_file("../../keys/alice_key.pem");
    $recv_cert = ws_get_cert_from_file("../../keys/bob_cert.cert");
// Create message with request payload and options
    $reqMessage = new WSMessage($reqPayloadString,
                         array("to" => "http://localhost/samples/security/username_token/policy_file_based/service.php",
                               "action" => "http://php.axis2.org/samples/echoString"));
   
    // Set up security options
    $policy_xml = file_get_contents("policy.xml");
    $policy = new WSPolicy($policy_xml);
    $security_token = new WSSecurityToken(array("user" => "Alice",
                                                "password" => "abcd!123",
                                                "passwordType" => "Digest",
    						"privateKey" => $my_key,
                                           	"receiverCertificate"=>$recv_cert,
						"certificate" => $my_cert));
    
    // Create client with options
    $client = new WSClient(array("useWSA" => TRUE,
                                 "policy" => $policy,
                                 "securityToken" => $security_token));
	
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

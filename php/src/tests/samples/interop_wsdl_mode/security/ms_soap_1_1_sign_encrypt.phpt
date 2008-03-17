--TEST--
SOAP 1.1 Security - Sign and encript
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

$reqPayloadString = <<<XML
<ns1:echo xmlns:ns1="http://InteropBaseAddress/interop"><ns1:request>Hello World!</ns1:request></ns1:echo>
XML;

try {
    $my_cert = ws_get_cert_from_file("keys/alice_cert.cert");
    $my_key = ws_get_key_from_file("keys/alice_key.pem");
    $rec_cert = ws_get_cert_from_file("keys/bob_cert.cert");
    
    $reqMessage = new WSMessage($reqPayloadString,
                                array("to" => "http://131.107.72.15/Security_WsSecurity_Service_Indigo/WsSecurity10.svc/MutualCertificate10SignEncrypt",
                                      "action" => "http://InteropBaseAddress/interop/echo"));

    
    $policy_xml = file_get_contents("sign-encrypt-policy.xml");
    $policy = new WSPolicy($policy_xml);
    $sec_token = new WSSecurityToken(array("privateKey" => $my_key,
                                           "certificate" => $my_cert,
                                           "receiverCertificate" => $rec_cert));
    
    $client = new WSClient(array("useWSA" => TRUE,
                                 "useSOAP" => "1.1",
                                 "policy" => $policy,
                                 "securityToken" => $sec_token /*,
                                 "proxyHost" => "localhost",
                                 "proxyPort" => "9090"*/));
   
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
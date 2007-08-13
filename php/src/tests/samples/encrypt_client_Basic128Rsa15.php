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
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>
XML;

try {
    $rec_cert = ws_get_cert_from_file("../keys/bob_cert.cert");
    $pvt_key = ws_get_key_from_file("../keys/alice_key.pem");
    
    $reqMessage = new WSMessage($reqPayloadString,
                                array("to"=>"http://localhost/samples/security/encryption/encrypt_service_Basic128Rsa15.php",
                                      "action" => "http://php.axis2.org/samples/echoString"));
    
    $sec_array = array("encrypt"=>TRUE,
                       "algorithmSuite" => "Basic128Rsa15",
                       "securityTokenReference" => "EmbeddedToken");
    
    $policy = new WSPolicy(array("security"=>$sec_array));
    $sec_token = new WSSecurityToken(array("privateKey" => $pvt_key,
                                           "receiverCertificate" => $rec_cert));
    
    $client = new WSClient(array("useWSA" => TRUE,
                                 "policy" => $policy,
                                 "securityToken" => $sec_token));
				
    $resMessage = $client->request($reqMessage);
    
    printf("Response = %s \n", $resMessage->str);

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}

}
?>

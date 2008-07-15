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

$reqPayloadString = <<<XML
<ns1:upload xmlns:ns1="http://wso2.org/wsfphp/samples/mtom">
               <ns1:fileName>test.jpg</ns1:fileName>
               <ns1:image xmlmime:contentType="image/jpeg" xmlns:xmlmime="http://www.w3.org/2004/06/xmlmime">
                  <xop:Include xmlns:xop="http://www.w3.org/2004/08/xop/include" href="cid:myid1"></xop:Include>
               </ns1:image>
</ns1:upload>
XML;

try {
    $f = file_get_contents("../../../resources/axis2.jpg");

    $rec_cert = ws_get_cert_from_file("../../keys/bob_cert.cert");
    $pvt_key = ws_get_key_from_file("../../keys/alice_key.pem");
    
    $reqMessage = new WSMessage($reqPayloadString,
                                array("to" => "http://localhost/samples/security/secure_mtom/encryption/service.php",
                                      "action" => "http://wso2.org/upload",
                                      "attachments" => array("myid1" => $f)));
    
    $sec_array = array("encrypt" => TRUE,
                       "algorithmSuite" => "Basic256Rsa15",
                       "securityTokenReference" => "IssuerSerial");
    
    $policy = new WSPolicy(array("security" => $sec_array));
    $sec_token = new WSSecurityToken(array("privateKey" => $pvt_key,
                                           "receiverCertificate" => $rec_cert));
    
    $client = new WSClient(array("useWSA" => TRUE,
                                 "useMTOM" => TRUE,
                                 "policy" => $policy,
                                 "securityToken" => $sec_token));
				
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

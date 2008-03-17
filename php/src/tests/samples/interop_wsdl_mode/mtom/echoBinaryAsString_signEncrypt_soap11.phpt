--TEST--
Echo Binary As String with sign only-MTOM
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
<EchoBinaryAsString xmlns="http://xmlsoap.org/Ping"><array><xop:Include href="cid:myid1" xmlns:xop="http://www.w3.org/2004/08/xop/include"/></array>
</EchoBinaryAsString>
XML;

try {
	$f = file_get_contents("string.txt");
/* 	$f = file_get_contents("axis2.jpg"); */
    
	$reqMessage = new WSMessage($reqPayloadString, 
        array("to" => "http://131.107.72.15/MTOM_Service_Indigo/Soap11MtomUtf8SignOnly.svc/MtomTest",
              "action" => "http://xmlsoap.org/echoBinaryAsString",
              "attachments" => array("myid1" => $f)));

	$my_cert = ws_get_cert_from_file("keys/alice_cert.cert");
        $my_key = ws_get_key_from_file("keys/alice_key.pem");
        $rec_cert = ws_get_cert_from_file("keys/bob_cert.cert");

	$policy_xml = file_get_contents("policySignEncrypt.xml");

        $policy = new WSPolicy($policy_xml);
        $sec_token = new WSSecurityToken(array("privateKey" => $my_key,
                                           "certificate" => $my_cert,
                                           "receiverCertificate" => $rec_cert));
	
	$client = new WSClient(array("useMTOM" => FALSE,
                                     "useSOAP" => "1.1",
                                     "useWSA" => TRUE,
				     "policy" => $policy,
                                     "securityToken" => $sec_token));

	$resMessage = $client->request($reqMessage);
	echo $resMessage->str;

} catch (Exception $e) {
	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Code);
		printf("Soap FaultReason: %s\n", $e->Reason);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>
--EXPECT--
<EchoBinaryAsStringResponse xmlns="http://xmlsoap.org/Ping"><EchoBinaryAsStringResult>H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! &#13;
</EchoBinaryAsStringResult></EchoBinaryAsStringResponse>

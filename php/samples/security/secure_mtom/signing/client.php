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

	$reqMessage = new WSMessage($reqPayloadString,
	array("to" => "http://localhost/samples/security/secure_mtom/signing/service.php",
              "action" => "http://wso2.org/upload",
              "attachments" => array("myid1" => $f)));

	$my_cert = ws_get_cert_from_file("../../keys/alice_cert.cert");
	$my_key = ws_get_key_from_file("../../keys/alice_key.pem");
	$rec_cert = ws_get_cert_from_file("../../keys/bob_cert.cert");

	$policy_xml = file_get_contents("policySignOnlyMtom.xml");

	$policy = new WSPolicy($policy_xml);
	$sec_token = new WSSecurityToken(array("privateKey" => $my_key,
                                           "certificate" => $my_cert,
                                           "receiverCertificate" => $rec_cert));

	$client = new WSClient(array("useMTOM" => TRUE,
                                     "useSOAP" => "1.1",
                                     "useWSA" => TRUE,
                                     "policy" => $policy,
                                     "securityToken" => $sec_token));

	$resMessage = $client->request($reqMessage);
	echo $resMessage->str."\n";

} catch (Exception $e) {
	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Code);
		printf("Soap FaultReason: %s\n", $e->Reason);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>

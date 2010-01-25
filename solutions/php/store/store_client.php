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

/* Generate a random number for the purchase order*/
$randNum = (rand()%99);

/* Requested date is two weeks from today*/
$reqDate = mktime(0,0,0,date("m"),date("d")+14,date("Y"));
$reqDateStr = date("Y/m/d", $reqDate);

/* The payload string*/
$requestPayloadString = <<<XML
      <po:Order xmlns:po="http://www.back_packers.com/ws/purchaseorder">
         <po:OrderId>po-$randNum</po:OrderId>
         <po:ReqDate>$reqDateStr</po:ReqDate>
         <po:Design>
            <po:FileName>design.jpg</po:FileName>
            <po:Image><xop:Include xmlns:xop="http://www.w3.org/2004/08/xop/include" href="cid:myid1"></xop:Include></po:Image>
         </po:Design>
      </po:Order>
XML;

try {
    /* Load the design*/
    $f = file_get_contents("./design.jpg");
   
    /* Build the message*/
    $requestMessage = new WSMessage($requestPayloadString, 
        array("to" => "http://localhost:8080/solutions/store/manuf_service.php",
                "action" => "http://www.back_packers.com/purchaseOrder",
                "attachments" => array("myid1" => $f)));
    
    /* Load certificates and keys*/
    $rec_cert = ws_get_cert_from_file("keys/bob_cert.cert");
    $my_cert = ws_get_cert_from_file("keys/alice_cert.cert");
    $my_key = ws_get_key_from_file("keys/alice_key.pem");

    /* Load policy file*/
    $policy_xml = file_get_contents("policy.xml");
    $policy = new WSPolicy($policy_xml);

    /* Ceate a security token with reqd configurations*/
    $sec_token = new WSSecurityToken(array("user" => "Alice",
                                            "password" => "abcd!1234",
                                            "passwordType" => "Digest",
                                            "privateKey" => $my_key,
                                           "certificate" => $my_cert,
                                           "receiverCertificate" => $rec_cert));

    /* Create a new client*/
    $client = new WSClient(array("useWSA" => TRUE,
                                 "useMTOM" => FALSE,
                                 "policy" => $policy,
                                 "securityToken" => $sec_token));

    /* Request*/
    $responseMessage = $client->request($requestMessage);
    
    /* Print the response*/
    echo $responseMessage->str;

} catch (Exception $e) {
    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n",$e->getMessage());
    }
}
?>

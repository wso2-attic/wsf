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

// Username Password mapping table
$store_pass_mapping = array(
                    "Raigama" => "RaigamaPW",
                    "Alice" => "abcd!1234",
                    "Bob" => "wxyz!123");

/* The password callback function */
function get_store_password_function($username)
{
    global $store_pass_mapping;

    if(isset($store_pass_mapping[$username])){
        $password = $store_pass_mapping[$username];
        return $password;
    }
    else
     return NULL;

}

/* The service logic. This function is mapped to an operation of the service*/
function manuf($inMessage) {

  $cid2stringMap = $inMessage->attachments;
    $cid2contentMap = $inMessage->cid2contentType;
    $imageName;
    $purchaseOrderNum = "NONE";

    foreach($cid2stringMap as $i=>$value){
        $f = $cid2stringMap[$i];
        $contentType = $cid2contentMap[$i];
        if(strcmp($contentType,"image/jpeg") ==0){
            $imageName = $i."."."jpg";
            file_put_contents("/tmp/".$imageName, $f);
        }
    }

    $arraysize = count($cid2contentMap);
    if($arraysize == 0){
        $dom = new DomDocument();
        $dom->loadXML($inMessage->str);
    
        /*Save image contents*/
        $images = $dom->documentElement->getElementsByTagName('Image');
        $image = $images->item(0);
        file_put_contents("/tmp/base64image.txt",$image->nodeValue);

        /*Get purchase order number for the confirmation*/
        $poElems = $dom->documentElement->getElementsByTagName('OrderId');
        $poElem = $poElems->item(0);
        $purchaseOrderNum = $poElem->nodeValue; 
    }

/* The response payload*/
$resPayload = <<<XML
      <manuf:RecievedOrder xmlns:manuf="http://www.factory.com/ws/purchaseOrder">
         <manuf:OrderId>$purchaseOrderNum</manuf:OrderId>
      </manuf:RecievedOrder>
XML;

    /* Create a response message*/
    $returnMessage = new WSMessage($resPayload);

    return $returnMessage;
}

/* Load certificates/keys*/
$rec_cert = ws_get_cert_from_file("keys/alice_cert.cert");
$my_key = ws_get_key_from_file("keys/bob_key.pem");
$my_cert = ws_get_key_from_file("keys/bob_cert.cert");

/*Function mapping = manuf*/
$operations = array("purchaseOrder" => "manuf");

/* Load and create a policy*/
$policy_xml = file_get_contents("policy.xml");
$policy = new WSPolicy($policy_xml);

/* Create a security token*/
$sec_token = new WSSecurityToken(array("passwordType" => "Digest",
                                        /* "passwordCallback" => "get_store_password_function",*/
                                        "password" => "abcd!1234",
                                        "user" => "Alice",
                                        "privateKey" => $my_key,
                                       "certificate" => $my_cert,
                                       "receiverCertificate" => $rec_cert));
/* Define actions*/
$actions = array("http://www.back_packers.com/purchaseOrder" => "purchaseOrder");

/* Create a new service*/
$svr = new WSService(array("actions" => $actions,
                           "operations" => $operations,
                           "policy" => $policy,
                           "requestXOP"=>TRUE,
                           "securityToken" => $sec_token));
/* Reply*/        
$svr->reply();

?>

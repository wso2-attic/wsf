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


function getAttachment($inMessage) {

  $cid2stringMap = $inMessage->attachments;
    $cid2contentMap = $inMessage->cid2contentType;
    $imageName;


    foreach($cid2stringMap as $i=>$value){
        $f = $cid2stringMap[$i];
        $contentType = $cid2contentMap[$i];
        if(strcmp($contentType,"image/jpeg") ==0){
		$imageName = $i."."."jpg";
		if (stristr(PHP_OS, 'WIN')) {
			file_put_contents($imageName, $f);
		}else{    
			file_put_contents("/tmp/".$imageName, $f);
		}
        }
    }

    $arraysize = count($cid2contentMap);
    if($arraysize == 0){
        $dom = new DomDocument();
        $dom->loadXML($inMessage->str);
        $images = $dom->documentElement->getElementsByTagName('image');
	$image = $images->item(0);
	if (stristr(PHP_OS, 'WIN')) {
		file_put_contents("base64image.txt",$image->nodeValue);
	}else{
		file_put_contents("/tmp/base64image.txt",$image->nodeValue);
	}
    }

$resPayload = <<<XML
<ns1:response xmlns:ns1="http://wso2.org/wsfphp/samples/mtom">Image Saved</ns1:response>
XML;

    $returnMessage = new WSMessage($resPayload);

    return $returnMessage;

}

$pub_key = ws_get_cert_from_file("../../keys/alice_cert.cert");
$pvt_key = ws_get_key_from_file("../../keys/bob_key.pem");

$operations = array("upload" => "getAttachment");
$sec_array = array("encrypt" => TRUE,
                    "algorithmSuite" => "Basic256Rsa15",
                    "securityTokenReference" => "IssuerSerial");

$actions = array("http://wso2.org/upload" => "upload");
 
$policy = new WSPolicy(array("security"=> $sec_array));
$sec_token = new WSSecurityToken(array("privateKey" => $pvt_key,
                                       "receiverCertificate" => $pub_key));

$svr = new WSService(array("actions" => $actions,
                           "operations" => $operations,
                           "policy" => $policy,
                           "requestXOP"=>TRUE,
                           "securityToken" => $sec_token));
        
$svr->reply();

?>

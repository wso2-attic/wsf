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
    
    $arraysize = count($cid2contentMap);
    if($arraysize == 0){
	    $dom = new DomDocument();
	    $dom->loadXML($inMessage->str);
	    $images = $dom->documentElement->getElementsByTagName('image');
        $image = $images->item(0);
        if (stristr(PHP_OS, 'WIN')) {
            file_put_contents("base64image.txt",$image->nodeValue);
            $str = base64_decode($image->nodeValue);
            file_put_contents("decoded_image.jpg", $str);
        }else{
            file_put_contents("/tmp/base64image.txt",$image->nodeValue);
        	$str = base64_decode($image->nodeValue);
            file_put_contents("/tmp/decoded_image.jpg", $str);
        }
    }

$responsePayload = <<<XML
<ns1:response xmlns:ns1="http://php.axis2.org/samples/mtom">Image Saved</ns1:response>
XML;

    $returnMessage = new WSMessage($responsePayload);

    return $returnMessage;
}

$operations = array("upload" => "getAttachment");

$service = new WSService(
            array(
                "operations" => $operations, 
                "requestXOP"=>TRUE));
        
$service->reply();

?>

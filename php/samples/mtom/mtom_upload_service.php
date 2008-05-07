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
    $file_saved = 0;

    foreach($cid2stringMap as $i=>$value){
        $f = $cid2stringMap[$i];
        $contentType = $cid2contentMap[$i];
        if(strcmp($contentType,"image/jpeg") ==0){
            $imageName = $i."."."jpg";
            if (stristr(PHP_OS, 'WIN')) {
                $file_saved = file_put_contents($imageName, $f);
            }else{                
                $file_saved = file_put_contents("/tmp/".$imageName, $f);
            }
        }
    }
    
if($file_saved){
$responsePayload = <<<XML
<ns1:response xmlns:ns1="http://php.axis2.org/samples/mtom">Image Saved</ns1:response>
XML;
}
else{
$responsePayload = <<<XML
<ns1:response xmlns:ns1="http://php.axis2.org/samples/mtom">Image Saving Failed</ns1:response>
XML;
}

    $returnMessage = new WSMessage($responsePayload);

    return $returnMessage;
}

$operations = array("upload" => "getAttachment");

$service = new WSService( array( "operations" => $operations, 
                                "requestXOP" => TRUE));
        
$service->reply();

?>

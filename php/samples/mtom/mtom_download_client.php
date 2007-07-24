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
	<download>
	</download>
XML;

try {

    $client = new WSClient(
        array("to"=>"http://localhost/samples/mtom/mtom_download_service.php",
               "useMTOM"=>TRUE,
		   "responseXOP"=>TRUE));
    $reqMessage = new WSMessage($reqPayloadString);					
    $resMessage = $client->request($reqMessage);
    
    printf("Response = %s \n", $resMessage->str);

    $cid2stringMap = $resMessage->attachments;
    $cid2contentMap = $resMessage->cid2contentType;
    $imageName;
    if($cid2stringMap && $cid2contentMap){
	    foreach($cid2stringMap as $i=>$value){
	        $f = $cid2stringMap[$i];
      	  $contentType = $cid2contentMap[$i];
	        if(strcmp($contentType,"image/jpeg") ==0){
      	      $imageName = $i."."."jpg";
	            file_put_contents("/tmp/".$imageName, $f);
      	  }
	    }
	}else{
		printf("attachments were not found ");
	}
    
} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Reason);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>

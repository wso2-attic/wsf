--TEST--
Echo String As Binary
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

 $f = file_get_contents("string.txt");

$reqPayloadString = <<<XML
<EchoStringAsBinary xmlns="http://xmlsoap.org/Ping" xmlns:s="http://schemas.xmlsoap.org/soap/envelope/"><s>$f</s>
</EchoStringAsBinary>
XML;

try {
//        $f = file_get_contents("string.txt");

	$reqMessage = new WSMessage($reqPayloadString, 
        array("to" => "http://131.107.72.15/MTOM_Service_Indigo/Soap12MtomUtf8.svc/MtomTest",
              "action" => "http://xmlsoap.org/EchoStringAsBinary"));
	
	$client = new WSClient(array("useWSA" => TRUE,
				     "useMTOM"=>TRUE,
/*                                   "proxyHost" => "localhost",*/
/*                                   "proxyPort" => "9093",*/
                                     "responseXOP"=>TRUE));

	$resMessage = $client->request($reqMessage);

        $cid2stringMap = $resMessage->attachments;
        $cid2contentMap = $resMessage->cid2contentType;
        $imageName;
        if($cid2stringMap && $cid2contentMap){
            foreach($cid2stringMap as $i=>$value){
                $f1 = $cid2stringMap[$i];
          	$contentType = $cid2contentMap[$i];
                if(strcmp($contentType,"application/octet-stream") ==0){
              	   $imageName = $i."."."txt";
                   file_put_contents("image.txt", $f1);
          }
            }
		echo $f1;
        }else{
                printf("attachments not found ");
		printf("\n");
        }
	



} catch (Exception $e) {
	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>
--EXPECT--
H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d ! H e l l o   W o r l d !

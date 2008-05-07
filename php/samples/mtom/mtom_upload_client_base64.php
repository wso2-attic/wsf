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

$requestPayloadString = <<<XML
<ns1:upload xmlns:ns1="http://php.axis2.org/samples/mtom">
               <ns1:fileName>test.jpg</ns1:fileName>
               <ns1:image xmlmime:contentType="image/jpeg" xmlns:xmlmime="http://www.w3.org/2004/06/xmlmime">
                  <xop:Include xmlns:xop="http://www.w3.org/2004/08/xop/include" href="cid:myid1"></xop:Include>
               </ns1:image>
</ns1:upload>
XML;

try {
    $f = file_get_contents("../resources/axis2.jpg");
    
    $requestMessage = new WSMessage($requestPayloadString, 
        array("to" => "http://localhost/samples/mtom/mtom_upload_service_base64.php",
        "attachments" => array("myid1" => $f)));
    
    $client = new WSClient(array("useMTOM" =>FALSE));

    $responseMessage = $client->request($requestMessage);
    
    echo $responseMessage->str;

} catch (Exception $e) {
    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n",$e->getMessage());
    }
}
?>

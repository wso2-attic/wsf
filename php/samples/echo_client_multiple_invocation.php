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

$requestPayloadStrings = array();

for ($i = 0 ; $i < 10; $i++) {
$tmp = "Hello World "."$i";
$requestPayloadString = <<<XML
<ns1:echoString xmlns:ns1="http://ws.apache.org/axis2/c/samples">
   <text>$tmp</text>
</ns1:echoString>
XML;
array_push($requestPayloadStrings,$requestPayloadString);
}

try
{
    $serviceClient = new WSClient();

    for($i = 0 ; $i < 10; $i++) {
        $msg = new WSMessage($requestPayloadStrings[$i],
                             array( "to" => "http://localhost/samples/echo_service.php"));
        $responsePayload = $serviceClient->request($msg);
        printf("Round %s<br>",$i);
        printf("--------<br>");
        printf("Response = %s <br><br>", htmlspecialchars($responsePayload->str));

        printf("Last Request = %s<br><br>",htmlspecialchars($serviceClient->getLastRequest()));
        printf("Last Response = %s<br><br>",htmlspecialchars($serviceClient->getLastResponse()));
    }

} catch (Exception $e) {
   if ($e instanceof WSFault) {
       printf("Soap Fault : %s<br>", $e->Reason());
   } else {
       printf("Fault Message = %s<br>",$e->getMessage());
   }
}
?>

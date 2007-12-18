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

/** 
  * Note: This is a simole example written just as a proof of concept. 
  * You may write a nice web interface to improve the usability.    
  * This sample sends a Goole key and a phrase to Google spell service. 
  * If everyting goes right, it returns a spell corrected version of 
  * the prase you submit.
  * Google spell uses SOAP 1.1.
  */

$requestPayloadString = <<<XML
<ns1:doSpellingSuggestion x:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/" xmlns:ns1="urn:GoogleSearch" xmlns:x="http://schemas.xmlsoap.org/soap/envelope/" xmlns:xsi="http://www.w3.org/1999/XMLSchema-instance" xmlns:xsd="http://www.w3.org/1999/XMLSchema">
    <key xsi:type="xsd:string">your_key_here</key>
    <phrase xsi:type="xsd:string">tamperature</phrase>
</ns1:doSpellingSuggestion>
XML;

try {
    $client = new WSClient(array( "to" => "http://api.google.com/search/beta2", 
                                  "useSOAP" => 1.1)); 
    $responseMessage = $client->request($requestPayloadString);

    printf("Response = %s <br/>\n", htmlspecialchars($responseMessage->str));

} catch (Exception $e) {
    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n",$e->getMessage());
    }
    
}


?>

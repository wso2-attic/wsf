--TEST--
Test for echo_rm_client sample
--FILE--
<?php
/*
 * Copyright 2005,2007 WSO2, Inc. http://wso2.com
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
    <ns1:echoString xmlns:ns1="http://php.axis2.org/samples">
        <text>Hello World!</text>
    </ns1:echoString>
XML;

try {

   

    $requestMessage = new WSMessage($requestPayloadString,
            array( "action" => "http://php.axis2.org/samples/echoString"));

    $client = new WSClient(array( "to" => "http://localhost/samples/reliable/echo_service_rm.php",
                                  "reliable" => TRUE));

    $responseMessage = $client->request($requestMessage);
    if($responseMessage){
        echo $responseMessage->str;
    }
    $client->wait(10);  
  
    
    
    
} catch (Exception $e) {

    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n",$e->getMessage());
    }
}
?>

--EXPECT--
<ns1:echoString xmlns:ns1="http://php.axis2.org/samples">
        <text>Hello World!</text>
    </ns1:echoString>
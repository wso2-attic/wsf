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
    <ns1:pingString xmlns:ns1="http://php.axis2.org/samples/reliable">
        <text>Hello World!</text>
    </ns1:pingString>
XML;

try {

    $message = new WSMessage($requestPayloadString,
            array( "to" => "http://localhost/samples/reliable/ping_service_rm.php",
                   "action" => "http://php.axis2.org/samples/pingString"));

    $client = new WSClient(array( "reliable" => TRUE, "useWSA" => TRUE, "willContinueSequence" => TRUE));

    $client->send($message);

    $message1 = new WSMessage($requestPayloadString,
            array( "to" => "http://localhost/samples/reliable/ping_service_rm.php",
                   "action" => "http://php.axis2.org/samples/pingString"));

    $client->send($message1);


    $message2 = new WSMessage($requestPayloadString,
        array( "to" => "http://localhost/samples/reliable/ping_service_rm.php",
               "action" => "http://php.axis2.org/samples/pingString",
               "lastMessage" => TRUE));
    
    $client->send($message2);

    echo "Messages Sent";

    /** wait 10 seconds for the requests to complete */
    $client->wait(10);
    
} catch (Exception $e) {

    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n",$e->getMessage());
    }
}
?>

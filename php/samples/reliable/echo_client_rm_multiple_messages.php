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

$reqPayloadString = <<<XML
    <ns1:echoString xmlns:ns1="http://wso2.org/wsfphp/samples/reliable">
        <text>Hello World!</text>
    </ns1:echoString>
XML;

try {

    $message = new WSMessage($reqPayloadString,
            array("to" => "http://localhost/samples/reliable/echo_service_rm.php",
                  "action" => "http://wso2.org/wsfphp/samples/echoString"));

    $client = new WSClient(array( "reliable" => TRUE , "useWSA" => TRUE, "willContinueSequence" => TRUE));

    $responseMsg = $client->request($message);
    echo "First Message Response => ";
    echo $responseMsg->str;
    


    $message1 = new WSMessage($reqPayloadString,
        array( "to" => "http://localhost/samples/reliable/echo_service_rm.php",
               "action" => "http://wso2.org/wsfphp/samples/echoString",
               "lastMessage" => TRUE));
    
    $responseMsg1 = $client->request($message1);

    /** wait 10 seconds for the operation to complete */
    $client->wait(10);
	
    echo "Second Message Response =>";
    echo $responseMsg1->str;
    
} catch (Exception $e) {

    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n",$e->getMessage());
    }
}
?>

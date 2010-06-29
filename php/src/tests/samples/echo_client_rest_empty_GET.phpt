--TEST--
Test for sending an empty value as a REST get request
--FILE--
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

try {

    $client = new WSClient( array("to" => "http://localhost/samples/echo_service_with_rest.php/echoString",
                                  "useSOAP" => FALSE,
                                  "HTTPMethod" => "GET"));

                
    $responseMessage =$client->request(NULL);
    printf("Response = %s <br>", htmlspecialchars($responseMessage->str));

} catch (Exception $e) {

    if ($e instanceof WSFault) {
	    printf("Error String: %s\n", $e->str);
	    printf("HTTP Code   : %s\n", $e->httpStatusCode);
    } else {
        printf("Message = %s\n",$e->getMessage());
    }
}
?>
--EXPECT--
Response = &lt;echoString&gt;&lt;/echoString&gt; <br>

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
    <ns1:echoString xmlns:ns1="http://php.axis2.org/samples">
        <text>Hello World!</text>
    </ns1:echoString>
XML;

function echoFunction($inMessage) {
    return new WSMessage($inMessage->str);
}

$operations = array( "echoString" => "echoFunction");
$actions = array( "http://php.axis2.org/samples/echoString" => "echoString");

$service = new WSService(array( "operations" => $operations,
                            "reliable"=>TRUE));
$service->reply();

?>

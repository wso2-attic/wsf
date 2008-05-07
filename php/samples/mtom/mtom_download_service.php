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

function sendAttachment($msg)
{
$responsePayloadString = <<<XML
        <ns1:download xmlns:ns1="http://php.axis2.org/samples/mtom">
            <ns1:fileName>test.jpg</ns1:fileName>
                <ns1:image xmlmime:contentType="image/jpeg" xmlns:xmlmime="http://www.w3.org/2004/06/xmlmime">
                    <xop:Include xmlns:xop="http://www.w3.org/2004/08/xop/include" href="cid:myid1"></xop:Include>
                </ns1:image>
        </ns1:download>
XML;
    $f = file_get_contents("../resources/axis2.jpg");                                        

    $responseMessage = new WSMessage($responsePayloadString, 
            array( "attachments" => array("myid1" => $f)));  
    return $responseMessage;    
}

$operations = array("download" => "sendAttachment");

$service = new WSService(array("operations" => $operations, "useMTOM" => TRUE));

$service->reply();

?>

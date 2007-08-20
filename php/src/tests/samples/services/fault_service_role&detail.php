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
 
/* sample test payload */
$reqPayloadString = <<<XML
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope">
   <soapenv:Header/>
   <soapenv:Body>
      <ns1:getFault xmlns:ns1="http://php.axis2.org/samples">
         <text>Hello World!</text>
      </ns1:getFault>
   </soapenv:Body></soapenv:Envelope>
XML;

function sendFault($inMessage) {

    return new WSFault("Sender", "Testing WSFault", "Fault Role", "Fault Detail");
}

$operations = array("getFault" => "sendFault");

$svr = new WSService(array("operations" => $operations));
        
$svr->reply($reqPayloadString);

?>

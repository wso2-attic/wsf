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

/* sample test payload */
$reqPayloadString = <<<XML
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope">
   <soapenv:Header/>
   <soapenv:Body>
      <ns1:add xmlns:ns1="http://ws.apache.org/axis2/services/math">
         <param1>40</param1>
         <param2>8</param2>
      </ns1:add>
   </soapenv:Body>
</soapenv:Envelope>
XML;

function addFunction($inMessage) {

    
    $simplexml = new SimpleXMLElement($inMessage->str);
    $value1 = $simplexml->param1[0];
    $value2 = $simplexml->param2[0];
    $Result = $value1 + $value2;    
     $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/math">$Result</ns1:result>
XML;
    $returnMessage = new WSMessage($resPayload);

    return $returnMessage;
}


function subFunction($inMessage) {

    $simplexml = new SimpleXMLElement($inMessage->str);
    $value1 = $simplexml->param1[0];
    $value2 = $simplexml->param2[0];
    $Result = $value1 - $value2;    
    $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/math">$Result</ns1:result>
XML;

    $returnMessage = new WSMessage($resPayload);

    return $returnMessage;


}


function mulFunction($inMessage) {
    
    $simplexml = new SimpleXMLElement($inMessage->str);
    $value1 = $simplexml->param1[0];
    $value2 = $simplexml->param2[0];
    $Result = $value1 * $value2;    
    $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/math">$Result</ns1:result>
XML;

    $returnMessage = new WSMessage($resPayload);

    return $returnMessage;
}



function divFunction($inMessage) {

    $simplexml = new SimpleXMLElement($inMessage->str);
    $value1 = $simplexml->param1[0];
    $value2 = $simplexml->param2[0];
    $Result = $value1 / $value2;    
    $resPayload = <<<XML
<ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/math">$Result</ns1:result>
XML;

    $returnMessage = new WSMessage($resPayload);

    return $returnMessage;
}


$operations = array("add" => "addFunction",
                    "sub" => "subFunction",
                    "mul" => "mulFunction",
                    "div" => "divFunction");

$svr = new WSService(array("operations" => $operations));
        
$svr->reply($reqPayloadString);

?>

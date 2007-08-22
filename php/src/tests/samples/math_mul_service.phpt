--TEST--
Test for math_add_service.phpt sample
--FILE--
<?php

$reqPayloadString = <<<XML
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope">
   <soapenv:Header/>
   <soapenv:Body>
      <ns1:mul xmlns:ns1="http://ws.apache.org/axis2/services/math">
         <param1>40</param1>
         <param2>8</param2>
      </ns1:mul>
   </soapenv:Body>
</soapenv:Envelope>
XML;


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

$operations = array("mul" => "mulFunction");

$svr = new WSService(array("operations" => $operations));
        
$svr->reply($reqPayloadString);

?>


--EXPECT--
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope"><soapenv:Header/><soapenv:Body><ns1:result xmlns:ns1="http://ws.axis2.org/axis2/php/math">320</ns1:result></soapenv:Body></soapenv:Envelope>
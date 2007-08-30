--TEST--
Test for fault_service sample
--FILE--
<?php

$reqPayloadString = <<<XML
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope">
   <soapenv:Body>
      <ns1:getFault xmlns:ns1="http://php.axis2.org/samples">
         <text>Hello World!</text>
      </ns1:getFault>
   </soapenv:Body></soapenv:Envelope>
XML;

function sendFault($inMessage) {

    return new WSFault("Sender", "Testing WSFault");
}

$operations = array("getFault" => "sendFault");

$svr = new WSService(array("operations" => $operations));
        
$svr->reply($reqPayloadString);

?>

--EXPECT--
<env:Envelope xmlns:env="http://www.w3.org/2003/05/soap-envelope"><env:Body><env:Fault><env:Code><env:Value>soapenv:Sender</env:Value></env:Code><env:Reason><env:Text xml:lang="en" xmlns:xml="http://www.w3.org/XML/1998/namespace">Testing WSFault</env:Text></env:Reason></env:Fault></env:Body></env:Envelope>
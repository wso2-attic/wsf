--TEST--
Test for ws_fault_constructor_toString sample
--FILE--

<?php

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
    
$toStringValue =  new WSFault("Sender", "Testing WSFault", "Fault Role", "Fault Detail");
$toStringValue->__toString();

}

$operations = array("getFault" => "sendFault");

$svr = new WSService(array("operations" => $operations));
        
$svr->reply($reqPayloadString);
    
?>

--EXPECT--
Soap Fault Reason: Testing WSFault
Soap Fault Code: soapenv:Sender 
Soap Fault Role: Fault Role 
Soap Fault Detail: <error>Fault Detail</error>
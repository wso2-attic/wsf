<?php

 
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
    throw new WSFault("Sender", "Testing WSFault","Role","This is a test");
}

$operations = array("getFault" => "sendFault");

$service = new WSService(array("operations" => $operations));
        
$service->reply();

?>

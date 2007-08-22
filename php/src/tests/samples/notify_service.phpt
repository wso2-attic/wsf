--TEST--
Test for echo_service sample
--FILE--
<?php

$reqPayloadString = <<<XML
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope">
   <soapenv:Header/>
   <soapenv:Body>
      <ns1:notifyString xmlns:ns1="http://php.axis2.org/samples">
         <text>Hello World!</text>
      </ns1:notifyString>
   </soapenv:Body></soapenv:Envelope>
XML;
   
function notifyFunction($inMessage) {

    return;
}

$operations = array("notifyString" => "notifyFunction");

$svr = new WSService(array("operations" => $operations));
        
$svr->reply($reqPayloadString);

printf("Notified");

?>

--EXPECT--
Notified
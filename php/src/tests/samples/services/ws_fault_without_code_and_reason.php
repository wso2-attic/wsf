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
    
return new WSFault(NULL,NULL);
}

$operations = array("getFault" => "sendFault");

$svr = new WSService(array("operations" => $operations));
        
$svr->reply($reqPayloadString);

?>
--TEST--
Test for echo_service sample
--FILE--
<?php

$reqPayloadString = <<<XML
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope">
   <soapenv:Header/>
   <soapenv:Body>
     <ns1:echoString xmlns:ns1="http://php.axis2.org/samples">
         <text>Hello World!</text>
     </ns1:echoString>
    </soapenv:Body>
</soapenv:Envelope>
XML;

function echoFunction($inMessage) {

    $returnMessage = new WSMessage($inMessage->str);

    return $returnMessage;
}

$operations = array("echoString" => "echoFunction");

$svr = new WSService(array("operations" => $operations));
        
$svr->reply($reqPayloadString);

?>

--EXPECT--
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope"><soapenv:Header/><soapenv:Body><ns1:echoString xmlns:ns1="http://php.axis2.org/samples">
         <text>Hello World!</text>
     </ns1:echoString></soapenv:Body></soapenv:Envelope>
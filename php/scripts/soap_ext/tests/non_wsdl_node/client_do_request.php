<?php

include_once '../soap_ext/soap_ext.php';

$reqPayloadString = <<<XML
<ns1:greet xmlns:ns1="http://localhost/axis/helloService"><name>Sam</name></ns1:greet>
XML;

try {
    
    $client = new WSSoapClient(null, 
        array('location' => 'http://localhost:9090/soapq/soap_ext/tests/ws_hello_service_nonwsdl.php',
              'uri' => 'http://localhost/axis/helloService',
              'soap_version' => SOAP_1_1));
    $result =  $client->__doRequest($reqPayloadString, 'http://localhost:9090/soap/soap_ext/tests/ws_hello_service_nonwsdl.php', NULL, NULL);
    printf("Result = %s\n", $result->str);

} catch (Exception $e) {
    printf("Message = %s\n",$e->__toString());
}
?> 


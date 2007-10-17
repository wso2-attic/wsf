<?php

include_once '../../soap_ext.php';

try {
    $client = new WSSoapClient(null, 
        array('location' => 'http://localhost:9090/ws_hello_service_nonwsdl.php',
              'uri' => 'http://localhost/axis/helloService',
              'soap_version' => SOAP_1_2,
              'proxy_host' =>"localhost",
              'proxy_port' => "9093" ));

    $a = 1; $b = 2; $c = 3;
    $result =  $client->__soapCall('SomeFunction', array($a, $b, $c), NULL, NULL);

    printf("Result = %s\n", $result);

} catch (Exception $e) {
    printf("Message = %s\n",$e->__toString());
}
?> 


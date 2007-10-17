<?php

include_once '../../soap_ext.php';

try {
    $client = new WSSoapClient(null, 
        array('location' => 'http://localhost:9090/soap/wsf_server.php',
              'uri' => 'http://localhost/axis/helloService',
              'soap_version' => SOAP_1_2,
              'trace' => 1 ));

    $a = 1; $b = 2; $c = 3;
    $result =  $client->__soapCall('SomeFunction', array($a, $b, $c), NULL, NULL);
    echo "RESULT :".$client->__getLastRequest(). "\n";
    
    printf("Result = %s\n", $result);

} catch (Exception $e) {
    printf("Message = %s\n",$e->__toString());
}
?> 


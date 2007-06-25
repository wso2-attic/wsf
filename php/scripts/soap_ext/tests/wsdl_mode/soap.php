<?php

include_once '../soap_ext/soap_ext.php';

try {
    $client = new WSSoapClient("r.wsdl");
    $test = $client->echoString("my test");
    echo $test;

} catch (Exception $e) {
    printf("Message = %s\n",$e->__toString());
}
?>

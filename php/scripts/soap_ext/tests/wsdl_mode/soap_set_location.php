<?php

include_once '../../soap_ext.php';

try {
    $client = new WSSoapClient("r.wsdl");
    $test = $client->__setLocation("http://localhost:9090/samples/wsdl_mode/echo_service_wsdl.php");
    echo $client->echoString("set location");
    

} catch (Exception $e) {
    printf("Message = %s\n",$e->__toString());
}
?>

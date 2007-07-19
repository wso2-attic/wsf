<?php

include_once '../../soap_ext.php';

try {
    $client = new WSSoapClient("sample.wsdl");
    $test = $client->addFunction(100, 200);
    echo $test;

} catch (Exception $e) {
    printf("Message = %s\n",$e->__toString());
}
?>

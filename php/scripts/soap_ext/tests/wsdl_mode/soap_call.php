<?php

include_once '../../soap_ext.php';

try {
    $client = new WSSoapClient("r.wsdl");
    $a = "this is request";
    $test = $client->__soapCall("echoString", array($a));
/*     $test = $client->echoString("my test"); */
    echo $test;

} catch (Exception $e) {
    printf("Message = %s\n",$e->__toString());
}
?>

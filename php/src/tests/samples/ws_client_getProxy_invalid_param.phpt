--TEST--
Test for ws_client_getProxy_invalid_param sample
--FILE--
<?php

try {

    $client = new WSClient(array("wsdl"=>"sample.wsdl"));

    $proxy = $client->getProxy(array("wsdl"=>"sample.wsdl"));	

    $val =  $proxy->echoString("Hello");    
    echo $val."\n";

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>
--EXPECT--
Warning: WSClient::getProxy() expects parameter 1 to be string, array given in C:\wsfphp\src\tests\samples\ws_client_getProxy_invalid_param.php on line 7

Fatal error: WSClient::getProxy(): Invalid Parameters,specify the service and port in C:\wsfphp\src\tests\samples\ws_client_getProxy_invalid_param.php on line 7
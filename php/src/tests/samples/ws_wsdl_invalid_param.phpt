--TEST--
Test for wsdl_mode sample
--FILE--

<?php

try {

    $client = new WSClient(array("wsdl"=>"C:\Apache2.2\htdocs\samples\wsdl_mode\sample.wsdl"));

    $proxy = $client->getProxy("SampleEchoService",10,"SampleEchoServicePort",2);	

    $val =  $proxy->echoString("Hello");    
    echo $val."\n";

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

--EXPECT--
Hello
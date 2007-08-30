--TEST--
Test for ws_cache_wsdl sample
--FILE--

<?php

try {

    $client = new WSClient(array("cache_wsdl"=>10));

    $proxy = $client->getProxy();	

    $val =  $proxy->echoString("Hello");    
    echo $val."\n";

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

--EXPECT--
Hello
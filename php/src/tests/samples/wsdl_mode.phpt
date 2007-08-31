--TEST--
Test for wsdl_mode sample
--FILE--

<?php

try {

    $client = new WSClient(array("wsdl"=>"misc_files/sample.wsdl"));

    $proxy = $client->getProxy();	

    $val =  $proxy->echoString("Hello");    
    echo $val."\n";

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

--EXPECT--
Hello
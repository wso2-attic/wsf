--TEST--
Test for ws_client_getProxy_invalid_param sample
--FILE--
<?php

try {

    $client = new WSClient(array("wsdl"=>"samples/misc_files/sample.wsdl"));

    $proxy = $client->getProxy(array("wsdl"=>"sample.wsdl"));	

} catch (Exception $e) {
		printf("Message = %s\n",$e->getMessage());
}
?>
--EXPECTF--
Warning: WSClient::getProxy() expects parameter 1 to be string, array given in %sws_client_getProxy_invalid_param.php on line %d

Fatal error: WSClient::getProxy(): Invalid Parameters,specify the service and port in %sws_client_getProxy_invalid_param.php on line %d
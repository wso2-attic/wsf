--TEST--
Test for ws_client_send_invalid_param sample
--FILE--
<?php
$reqPayloadString = <<<XML
	<ns1:echo xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echo>
XML;

try {

    $reqMessage = new WSMessage($reqPayloadString,
        array("to"=>"http://localhost/services/ws_service_actions.php",
              "action" => "http://php.axis2.org/samples/echoString"));
              
    $client = new WSClient(array("useWSA" => TRUE));
				
    $resMessage = $client->send();
    
    printf("Response = %s \n", $resMessage->str);

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}

}
?>
--EXPECTF--
Warning: WSClient::send() expects exactly 1 parameter, 0 given in %sws_client_send_invalid_param.php on line %d

Fatal error: WSClient::send(): Invalid parameters in %sws_client_send_invalid_param.php on line %d

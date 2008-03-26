--TEST--
Test for ws_message_consturctor_invalid_param sample
--FILE--
<?php
$reqPayloadString = <<<XML
	<ns1:echo xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echo>
XML;

try {

	$reqMessage = new WSMessage();
              
    $client = new WSClient(array("useWSA" => TRUE));
				
    $resMessage = $client->request($reqMessage);
    
    printf("Response = %s \n", $resMessage->str);

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}

}
?>
--EXPECT--
Warning: WSMessage::__construct() expects at least 1 parameter, 0 given in C:\wsfphp\src\tests\samples\ws_message_consturctor_invalid_param.php on line 10

Fatal error: WSMessage::__construct(): Invalid parameters in C:\wsfphp\src\tests\samples\ws_message_consturctor_invalid_param.php on line 10
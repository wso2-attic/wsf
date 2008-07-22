--TEST--
Test for ws_message_useWSA_string_1.0 sample
--FILE--
<?php
$reqPayloadString = <<<XML
	<ns1:echo xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echo>
XML;

try {

    $reqMessage = new WSMessage($reqPayloadString,
        array("to"=>"http://localhost/samples/echo_service_addr.php",
              "action" => "http://php.axis2.org/samples/echoString"));
              
    $client = new WSClient(array("useWSA" => "1.0"));
				
    $resMessage = $client->request($reqMessage);
    
    printf("Response = %s \n", $resMessage->str);

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}

}
?>
--EXPECT--
Response = <ns1:echo xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echo>

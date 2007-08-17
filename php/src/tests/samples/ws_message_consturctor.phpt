--TEST--
Test for echo_client_addr sample
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
              "action"=>"http://php.axis2.org/samples/echoString",
              "faultTo"=>"http://php.axis2.org/samples/echoString",
              "replyTo"=>"http://localhost/samples/echo_service.php",
              "from"=>"http://localhost/samples/echo_service_addr.php"));
              
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
Response = <ns1:echo xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echo>

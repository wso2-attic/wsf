--TEST--
Test for notify_client sample
--FILE--
<?php

$reqPayloadString = <<<XML
	<ns1:notifyString xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:notifyString>
XML;

try {

    $client = new WSClient(
        array("to"=>"http://localhost/samples/notify_service.php"));
				
    $client->send($reqPayloadString);
    
    printf("Request sent\n");
    
} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}

}
?>
--EXPECT--
Request sent

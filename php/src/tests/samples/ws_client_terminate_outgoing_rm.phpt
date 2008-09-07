--TEST--
Test for ws_client_terminate_outgoing_rm sample
--FILE--
<?php

$reqPayloadString = <<<XML
	<ns1:echoString xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echoString>
XML;

try {

    $msg = new WSMessage($reqPayloadString,
			array("action" => "http://php.axis2.org/samples/echoString"));

    $client = new WSClient(array( "to"=>"http://localhost/samples/reliable/echo_service_rm.php",
					    "reliable"=>"1.1",
					    "willContinueSequence" => TRUE));
    $result = $client->request($msg);

    if($result){
	echo $result->str;
    }
    $client->terminateOutgoingRM();
    $client->wait(10);  
    
} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Reason);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>
--EXPECT--
<ns1:echoString xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echoString>

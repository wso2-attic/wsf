<?php

$reqPayloadString = <<<XML
	<ns1:echoString xmlns:ns1="http://wso2.org/wsfphp/samples">
		<text>Hello World!</text>
	</ns1:echoString>
XML;

try {

    $msg = new WSMessage($reqPayloadString,
			array("action" => "http://wso2.org/wsfphp/samples/echoString"));

    $client = new WSClient(array( "to"=>"http://localhost/samples/reliable/echo_service_rm.php",
					    "reliable"=>"1.1",
					    "willContinueSequence" => TRUE));
    $result = $client->request($msg);

    if($result){
	echo $result->str;
    }
	/** Terminate outgong rm function can be used to terminate the sequence only when using RM 1.1 */
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

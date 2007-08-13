--TEST--
Test for fault_client sample
--FILE--
<?php

$reqPayloadString = <<<XML
<ns1:getFault xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:getFault>
XML;

try {

    $client = new WSClient(
        array("to"=>"http://localhost/samples/fault_service.php"));

				
    $resMessage = $client->request($reqPayloadString);
    
} catch (Exception $e) {

	if ($e instanceof WSFault) {
        printf("Soap Fault Reason: %s\n", $e->Reason);
        printf("Soap Fault Code: %s \n", $e->Code);

	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>
--EXPECT--
Soap Fault Reason: Testing WSFault
Soap Fault Code: soapenv:Sender

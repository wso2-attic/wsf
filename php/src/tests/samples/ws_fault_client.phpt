--TEST--
Test for ws_fault_client sample
--FILE--
<?php

$reqPayloadString = <<<XML
<ns1:getFault xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:getFault>
XML;

try {

    $client = new WSClient(
        array("to"=>"http://localhost/services/fault_service_role&detail.php"));

				
    $resMessage = $client->request($reqPayloadString);
    
} catch (Exception $e) {

	if ($e instanceof WSFault) {
        printf("Soap Fault Reason: %s\n", $e->Reason);
        printf("Soap Fault Code: %s \n", $e->Code);
        printf("Soap Fault Role: %s \n", $e->Role);
        printf("Soap Fault Detail: %s \n", $e->Detail);

	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>
--EXPECT--
Soap Fault Reason: Testing WSFault
Soap Fault Code: soapenv:Sender 
Soap Fault Role: Role 
Soap Fault Detail: <error>This is a test</error>

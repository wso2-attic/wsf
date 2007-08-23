--TEST--
Test for ws_fault_constructor sample
--FILE--

<?php

$reqPayloadString = <<<XML
<soapenv:Envelope xmlns:soapenv="http://www.w3.org/2003/05/soap-envelope">
   <soapenv:Header/>
   <soapenv:Body>
      <ns1:getFault xmlns:ns1="http://php.axis2.org/samples">
         <text>Hello World!</text>
      </ns1:getFault>
   </soapenv:Body></soapenv:Envelope>
XML;

function sendFault($inMessage) {
    
    return new WSFault("Sender", "Testing WSFault", "Fault Role", "Fault Detail");
    /*return new WSFault(array("operations" => $operations));*/
}

$operations = array("getFault" => "sendFault");

$svr = new WSService(array("operations" => $operations));
        
$svr->reply($reqPayloadString);

?>




/*<?php

$reqPayloadString = <<<XML
<ns1:getFault xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:getFault>
XML;

try {

    $client = new WSClient(
        array("to"=>"http://localhost/samples/fault_service_role&detail.php"));

				
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
?>*/
--EXPECT--
Soap Fault Reason: Testing WSFault
Soap Fault Code: soapenv:Sender 
Soap Fault Role: Fault Role 
Soap Fault Detail: <error>Fault Detail</error>

--TEST--
Test for add_soap_header_client_withmoreheaders sample
--FILE--
<?php
$reqPayloadString = <<<XML
	<ns1:echoString xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echoString>
XML;

try {

    $client = new WSClient(array( "to"=>"http://localhost/samples/echo_service.php"));

    $headers = array(new WSHeader(array( "ns" => "http://test.org",
                                   "name" => "header1",
                                   "data" => "value1",
                                   "mustUnderstand" => true)),
				 new WSHeader(array( "ns" => "http://test.org",
                                   "name" => "header2",
                                   "data" => "value2",
                                   "mustUnderstand" => true)),
				 new WSHeader(array( "ns" => "http://test.org",
                                   "name" => "header3",
                                   "data" => "value3",
                                   "mustUnderstand" => true)),
				 new WSHeader(array( "ns" => "http://test.org",
                                   "name" => "header4",
                                   "data" => "value4",
                                   "mustUnderstand" => true)),
				 new WSHeader(array( "ns" => "http://test.org",
                                   "name" => "header5",
                                   "data" => "value5",
                                   "mustUnderstand" => true)));

    $msg = new WSMessage($reqPayloadString, array( "inputHeaders" => $headers));

    

    $client->request($msg);
        
} catch (Exception $e) {
	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Reason);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>

--EXPECT--
Soap Fault: Header not understood
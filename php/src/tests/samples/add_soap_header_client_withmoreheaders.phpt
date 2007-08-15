--TEST--
Check for add_soap_header_client sample
--FILE--
<?php
$reqPayloadString = <<<XML
	<ns1:echoString xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echoString>
XML;

try {

    $client = new WSClient(array( "to"=>"http://localhost/samples/echo_service.php"));

    $msg = new WSMessage($reqPayloadString ,
			array("headers" => array(new WSHeader("http://test.org","header1", "value1", true, 1),
				 new WSHeader("http://test1.org","header2", "value2", true, 2),
				 new WSHeader("http://test2.org","header3", "value3", true, 3),
				 new WSHeader("http://test3.org","header4", "value4", true, 4),
				 new WSHeader("http://test4.org","header5", "value5", true, 5))
			      )
			);

    $client->request($msg);
        
} catch (Exception $e) {
	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>

--EXPECT--

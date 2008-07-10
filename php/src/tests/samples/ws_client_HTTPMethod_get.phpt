--TEST--
Test for ws_client_HTTPMethod_get sample
--FILE--
<?php

$reqPayloadString = <<<XML
    <ns1:echoString xmlns:ns1="http://php.axis2.org/samples">
        <text>Hello World!</text>
    </ns1:echoString>
XML;

try {

    $client = new WSClient(
        array("to"=>"http://localhost/samples/echo_service_with_rest.php/echoString",
	      "useSOAP"=>FALSE,
              "HTTPMethod"=>"get"));

				
    $resMessage = $client->request($reqPayloadString);
    
    printf("Response = %s <br>", htmlspecialchars($resMessage->str));

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Reason);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}

}
?>

--EXPECT--
Response = &lt;echoString&gt;&lt;text&gt;Hello World!&lt;/text&gt;&lt;/echoString&gt; <br>

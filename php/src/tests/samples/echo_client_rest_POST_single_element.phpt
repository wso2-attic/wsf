--TEST--
Test for echo_client_rest_POST sample with a single element
--FILE--
<?php

$reqPayloadString = <<<XML
    <echoString>Hello</echoString>
XML;

try {

    $client = new WSClient(
        array("to"=>"http://localhost/samples/echo_service_with_rest.php/echoString",
	      "useSOAP"=>FALSE,
              "HTTPMethod"=>"POST"));

				
    $resMessage = $client->request($reqPayloadString);
    
    printf("Response = %s <br>", htmlspecialchars($resMessage->str));

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("HTTP Status Code: %s\n", $e->httpStatusCode);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}

}
?>

--EXPECT--
Response = &lt;echoString&gt;Hello&lt;/echoString&gt; <br>


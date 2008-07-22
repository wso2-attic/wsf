--TEST--
Test for echo_client_rest_GET sample
--FILE--
<?php

$requestPayloadString = <<<XML
    <ns1:echoString xmlns:ns1="http://wso2.org/wsfphp/samples">
        <text>Hello World!</text>
    </ns1:echoString>
XML;

try {

    $client = new WSClient( array("to" => "http://localhost/samples/echo_service_with_rest.php/echoString",
                                  "useSOAP" => FALSE,
                                  "HTTPMethod" => "GET"));

                
    $responseMessage = $client->request($requestPayloadString);
    
    printf("Response = %s <br>", htmlspecialchars($responseMessage->str));

} catch (Exception $e) {

    if ($e instanceof WSFault) {
	    printf("Error String: %s\n", $e->str);
	    printf("HTTP Code   : %s\n", $e->httpStatusCode);
    } else {
        printf("Message = %s\n",$e->getMessage());
    }

}

?>

--EXPECT--
Response = &lt;echoString&gt;&lt;text&gt;Hello World!&lt;/text&gt;&lt;/echoString&gt; <br>

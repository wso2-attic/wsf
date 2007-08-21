--TEST--
Test for echo_client sample
--FILE--
<?php

$reqPayloadDomDoc = new DOMDocument();
$xmlFile = 'C:/WSO2-Projects/WSF_PHP/wso2-wsf-php-1.0.0/src/tests/samples/echo.xml';

$reqPayloadDomDoc->load($xmlFile);

try {

    $client = new WSClient(
        array("to"=>"http://localhost/samples/echo_service.php"));
				
    $resMessage = $client->request($reqPayloadDomDoc);
    
    printf("Response = %s <br>", htmlspecialchars($resMessage->str));

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}

}
?>
--EXPECT--
Response = &lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World!&lt;/text&gt;
&lt;/ns1:echoString&gt; <br>

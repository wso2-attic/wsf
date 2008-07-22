--TEST--
Test for math_client_divide sample
--FILE--
<?php
$reqPayloadString = <<<XML
      <ns1:div xmlns:ns1="http://ws.apache.org/axis2/php/math">     
         <param1>10</param1>      
         <param2>20</param2>
      </ns1:div>
XML;

try {

    $client = new WSClient(
        array("to"=>"http://localhost/samples/math_service.php"));
				
    $resMessage = $client->request($reqPayloadString);
    
    printf("Response = %s <br>", htmlspecialchars($resMessage->str));

} catch (Exception $e) {

	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}

}
?>
--EXPECT--
Response = &lt;ns1:result xmlns:ns1=&quot;http://ws.axis2.org/axis2/php/math&quot;&gt;0.5&lt;/ns1:result&gt; <br>

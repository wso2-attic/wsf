--TEST--
Test for math_client_subtract sample
--FILE--
<?php
$reqPayloadString = <<<XML
      <ns1:sub xmlns:ns1="http://ws.apache.org/axis2/php/math">     
         <param1>10</param1>      
         <param2>20</param2>
      </ns1:sub>
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
Response = &lt;ns1:result xmlns:ns1=&quot;http://ws.axis2.org/axis2/php/math&quot;&gt;-10&lt;/ns1:result&gt; <br>

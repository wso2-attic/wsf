--TEST--
Test for mtom_upload_client_base64 client sample
--FILE--
<?php

$reqPayloadString = <<<XML
<ns1:upload xmlns:ns1="http://php.axis2.org/samples/mtom">
               <ns1:fileName>test.jpg</ns1:fileName>
               <ns1:image xmlmime:contentType="image/jpeg" xmlns:xmlmime="http://www.w3.org/2004/06/xmlmime">
                  <xop:Include xmlns:xop="http://www.w3.org/2004/08/xop/include" href="cid:myid1"></xop:Include>
               </ns1:image>
</ns1:upload>
XML;

try {
	$f = file_get_contents("samples/resources/axis2.jpg");
    
	$reqMessage = new WSMessage($reqPayloadString, 
        array("to" => "http://localhost/samples/mtom/mtom_upload_service_base64.php",
		"attachments" => array("myid1" => $f)));
	
	$client = new WSClient(array("useMTOM" =>FALSE));

	$resMessage = $client->request($reqMessage);
	
    echo $resMessage->str;

} catch (Exception $e) {
	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>
--EXPECT--
<ns1:response xmlns:ns1="http://php.axis2.org/samples/mtom">Image Saved</ns1:response>

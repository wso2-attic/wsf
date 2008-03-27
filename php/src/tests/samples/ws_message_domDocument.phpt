--TEST--
Test for ws_message_domDocument sample
--FILE--
<?php


include_once('wsf.php');

$reqPayloadDomDoc = new DOMDocument();
$xmlFile = 'samples/misc_files/echo.xml';

$reqPayloadDomDoc->load($xmlFile);

try {
    
    $responseMessage = ws_request($reqPayloadDomDoc, 
                        array("to" => "http://localhost/samples/reply_echo_service.php",
						"action"=>"http://php.axis2.org/samples/echoString",
              "faultTo"=>"http://php.axis2.org/samples/echoString",
              "replyTo"=>"http://localhost/samples/echo_service.php",
              "from"=>"http://localhost/samples/echo_service_addr.php"));
    
    printf("Response = %s <br>", htmlspecialchars($responseMessage->str));

} catch (Exception $e) {

    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n",$e->getMessage());
    }
}
?>
--EXPECT--
Response = &lt;ns1:echoString xmlns:ns1=&quot;http://ws.apache.org/axis2/c/samples&quot;&gt;
   &lt;text&gt;Hello World!&lt;/text&gt;
&lt;/ns1:echoString&gt; <br>
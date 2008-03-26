--TEST--
Test for echo_client_addr sample
--FILE--
<?php

$requestPayloadString = <<<XML
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>
XML;

try {

    $reqMessage = new WSMessage($requestPayloadString,
        array( "to" => "http://localhost/samples/echo_service_addr.php",
               "action" => "http://php.axis2.org/samples/echoString",
			   "faultTo"=>"http://php.axis2.org/samples/echoString",
               "from"=>"http://localhost/samples/echo_service_addr.php"));
              
    $client = new WSClient(array("useWSA" => TRUE));
                
    $responseMessage = $client->request($reqMessage);
    
    printf("Response = %s \n", htmlspecialchars($responseMessage->str));

} catch (Exception $e) {

    if ($e instanceof WSFault) {
        printf("Soap Fault : %s\n", $e->Reason);
    } else {
        printf("Message = %s\n",$e->getMessage());
    }

}

?>
--EXPECT--
Response = &lt;ns1:echo xmlns:ns1=&quot;http://php.axis2.org/samples&quot;&gt;&lt;text&gt;Hello World!&lt;/text&gt;&lt;/ns1:echo&gt;
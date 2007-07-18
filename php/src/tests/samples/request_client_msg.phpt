--TEST--
Test for request_client_msg sample
--FILE--
<?php

include_once('../scripts/wsf.php');

$reqPayloadString = <<<XML
    <ns1:echoString xmlns:ns1="http://php.axis2.org/samples">
        <text>Hello World!</text>
    </ns1:echoString>
XML;

try {

    $reqMessage = new WSMessage($reqPayloadString, 
                        array("to"=>"http://localhost/samples/reply_echo_service.php"));
    
    $resMessage = ws_request($reqMessage);
    
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
PHP Warning:  Module 'wsf' already loaded in Unknown on line 0
Response = &lt;ns1:echoString xmlns:ns1=&quot;http://php.axis2.org/samples&quot;&gt;
        &lt;text&gt;Hello World!&lt;/text&gt;
    &lt;/ns1:echoString&gt; <br>

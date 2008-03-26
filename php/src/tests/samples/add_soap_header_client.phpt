--TEST--
Test for add_soap_header_client sample
--FILE--
<?php
$requestPayloadString = <<<XML
    <ns1:echoString xmlns:ns1="http://php.axis2.org/samples">
        <text>Hello World!</text>
    </ns1:echoString>
XML;

try {

    $client = new WSClient(array( "to" => "http://localhost/samples/echo_service.php" ));

    $header1 = new WSHeader(array( "ns" => "http://test.org",
                                   "name" => "header1",
                                   "data" => "value1",
                                   "mustUnderstand" => true));


    $msg = new WSMessage($requestPayloadString , array( "inputHeaders" => array($header1)));
    $client->request($msg);

    $sentMsg = $client->getLastRequest();
    $recvMsg = $client->getLastResponse();        
    
    echo "\nSent message \n";
    echo htmlspecialchars($sentMsg);
   
    echo "\n\n Received message \n";
    echo htmlspecialchars($recvMsg);
    


} catch (Exception $e) {
    if ($e instanceof WSFault) {
        printf("Soap Fault: %s\n", $e->Reason);
    } else {
        printf("Message = %s\n",$e->getMessage());
    }
}
?>
--EXPECT--
Soap Fault: Header not understood
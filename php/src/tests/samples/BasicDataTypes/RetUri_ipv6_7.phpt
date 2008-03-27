--TEST--
RetUri_ipv6_7("http://[3FFE:2A00:0100:7031:0000:0000:0000:0001]/");
--FILE--
<?php

try {

   $wsdl = file_get_contents('samples/config/SimpleDataTypesWsdlDoclitB.txt');
    $client = new WSClient(array("wsdl" => $wsdl));
    
    $proxy = $client->getProxy();
    $val =  $proxy->RetUri("http://[3FFE:2A00:0100:7031:0000:0000:0000:0001]/");
    echo $val."\n";

} catch (Exception $e) {

        if ($e instanceof WSFault) {
                printf("Soap Fault: %s\n", $e->Code);
                printf("Soap Reason: %s\n", $e->Reason);
        } else {
                printf("Message = %s\n",$e->getMessage());
        }
}
?>
--EXPECT--
http://[3FFE:2A00:0100:7031:0000:0000:0000:0001]/

--TEST--
inDecimal_minus_valid(-9223372036854775808)
--FILE--
<?php

try {

   $wsdl = file_get_contents('samples/config/SimpleDataTypesWsdlDoclitB.txt');

    $client = new WSClient(array("wsdl" => $wsdl));
    
    $proxy = $client->getProxy();
    $val =  $proxy->RetDecimal(-9223372036854775808);
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
-9.2233720368548E+18

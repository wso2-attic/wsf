--TEST--
inDecimal(90)
--FILE--
<?php

try {

   $wsdl = file_get_contents('config/SimpleDataTypesWsdlDoclitB.txt');

    $client = new WSClient(array("wsdl" => $wsdl,
	                             "to" => "http://localhost:9090/services/BasicTypesDoclitBSvc/BasicTypesDocLitB_Service.php"));
    
    $proxy = $client->getProxy();
    $val =  $proxy->RetDecimal(90);
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
90

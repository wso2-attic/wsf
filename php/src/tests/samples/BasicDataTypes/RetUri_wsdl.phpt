--TEST--
RetUri_wsdl();
--FILE--
<?php

try {

   $wsdl = file_get_contents('samples/config/SimpleDataTypesWsdlDoclitB.txt');
    $client = new WSClient(array("wsdl" => $wsdl));
    
    $proxy = $client->getProxy();
    $val =  $proxy->RetUri("http://xwsinterop.redmond.corp.microsoft.com/MTOM_Service_Indigo/MtomServiceSimplestBinding.svc?wsdl");
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
http://xwsinterop.redmond.corp.microsoft.com/MTOM_Service_Indigo/MtomServiceSimplestBinding.svc?wsdl

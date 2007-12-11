--TEST--
RetUri_query();
--FILE--
<?php

try {

    $client = new WSClient(array("wsdl" => "http://131.107.72.15/SoapWsdl_BaseDataTypes_XmlFormatter_Service_Indigo/BaseDataTypesDocLitB.svc?wsdl"));
    
    $proxy = $client->getProxy();
    $val =  $proxy->RetUri(array("http://66.102.7.104/search?q=cache:nAKRq2xF-YMJ:deutschlandsuchtensuperstar.rtl.de/+dsds&hl=en"));
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
http://66.102.7.104/search?q=cache:nAKRq2xF-YMJ:deutschlandsuchtensuperstar.rtl.de/+dsds&hl=en

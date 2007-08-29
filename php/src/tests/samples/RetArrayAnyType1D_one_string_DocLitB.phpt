--TEST--
Test for RetArrayAnyType1D_one_string sample
--FILE--

<?php

try {

    $client = new WSClient(array("wsdl"=>"tests/samples/misc_files/ComplexDataTypesDocLitB.wsdl",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost/samples/DocLitB_Service.php"));
    $proxy = $client->getProxy();	
    $empty_any= array("Hello World");
    $val =  $proxy->RetArrayAnyType1D(array($empty_any));    
    echo "\n";
    var_dump($val);

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

--EXPECT--
object(stdClass)#3 (0) {
}









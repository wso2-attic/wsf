--TEST--
Test for RetEnumInt5_service sample
--FILE--

<?php

try {

    $client = new WSClient(array("wsdl"=>"tests/samples/misc_files/ComplexDataTypesDocLitW.wsdl",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost/samples/DocLitW_Service.php"));
    $proxy = $client->getProxy();	
    $val =  $proxy->RetEnumInt(array("inEnumInt" => -5));    
    echo "\n";
    var_dump($val);

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

--EXPECT--
object(stdClass)#3 (1) {
  ["RetEnumIntResult"]=>
  string(2) "-5"
}







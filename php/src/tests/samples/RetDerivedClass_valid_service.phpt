--TEST--
Test for RetDerivedClass_valid_service sample
--FILE--


<?php


try {

    $client = new WSClient(array("wsdl"=>"tests/samples/misc_files/ComplexDataTypesDocLitW.wsdl",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost/samples/DocLitW_Service.php"));
    $proxy = $client->getProxy();	
    $der_array = array("color" => "Pink", "price" => "1dd23.34", "seatingCapacity" => 234);
    $val =  $proxy->RetDerivedClass(array("inDerivedClass" => $der_array));    
    echo "\n";
    var_dump($val);

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

--EXPECT--
object(stdClass)#3 (1) {
  ["RetDerivedClassResult"]=>
  object(stdClass)#4 (3) {
    ["color"]=>
    string(4) "Pink"
    ["price"]=>
    float(1)
    ["seatingCapacity"]=>
    int(234)
  }
}









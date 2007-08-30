--TEST--
Test for RetStructS1_valid_service sample
--FILE--

<?php


try {

    $client = new WSClient(array("wsdl"=>"tests/samples/misc_files/ComplexDataTypesDocLitW.wsdl",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost/samples/DocLitW_Service.php"));
    $proxy = $client->getProxy();	
    $s1_array = array("inStructS1" => array("name" => "WSO2 PHP developer"));
    $val =  $proxy->RetStructS1($s1_array);    
    echo "\n";
    var_dump($val);

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

--EXPECT--
object(stdClass)#3 (1) {
  ["RetStructS1Result"]=>
  object(stdClass)#4 (1) {
    ["name"]=>
    string(18) "WSO2 PHP developer"
  }
}









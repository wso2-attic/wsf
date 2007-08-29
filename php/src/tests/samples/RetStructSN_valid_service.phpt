--TEST--
Test for RetStructSN_valid_service sample
--FILE--

<?php


try {

    $client = new WSClient(array("wsdl"=>"tests/samples/misc_files/ComplexDataTypesDocLitW.wsdl",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost/samples/DocLitW_Service.php"));
    $proxy = $client->getProxy();	
    $sn_array = array("inStructSN" => array("Age" => 34, "ID" => 123.45, "Male" => TRUE, "Name" => "WSO2 PHP Developer"));
    $val =  $proxy->RetStructSN($sn_array);    
    echo "\n";
    var_dump($val);

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

--EXPECT--
object(stdClass)#3 (1) {
  ["RetStructSNResult"]=>
  object(stdClass)#4 (4) {
    ["Age"]=>
    float(34)
    ["ID"]=>
    float(123.45)
    ["Male"]=>
    bool(true)
    ["Name"]=>
    string(18) "WSO2 PHP Developer"
  }
}









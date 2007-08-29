--TEST--
Test for RetArrayAnyType1D_one_string sample
--FILE--

<?php


try {

    $client = new WSClient(array("wsdl"=>"tests/samples/misc_files/ComplexDataTypesDocLitB.wsdl",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost/samples/DocLitB_Service.php"));
    $proxy = $client->getProxy();	
    $sn_array = array("Age" => 34, "ID" => 123.45, "Male" => TRUE, "Name" => "WSO2 PHP Developer");
    $val =  $proxy->RetStructSN($sn_array);    
    echo "\n";
    var_dump($val);

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>


--EXPECT--
object(stdClass)#3 (0) {
}








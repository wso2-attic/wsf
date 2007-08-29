--TEST--
Test for RetArrayAnyType1D_one_string sample
--FILE--

<?php



try {

    $client = new WSClient(array("wsdl"=>"tests/samples/misc_files/ComplexDataTypesDocLitB.wsdl",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost/samples/DocLitB_Service.php"));
    $proxy = $client->getProxy();	
    $int_array = array(2147483647, -2147483647, 0, 1, -1, 50);
    $val =  $proxy->RetArrayInt1D($int_array);    
    echo "\n";
    var_dump($val);

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

--EXPECT--
object(stdClass)#3 (0) {
}
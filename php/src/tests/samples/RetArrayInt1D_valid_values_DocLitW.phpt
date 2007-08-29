--TEST--
Test for RetArrayInt1D_valid_values_DocLitW sample
--FILE--

<?php


try {

    $client = new WSClient(array("wsdl"=>"tests/samples/misc_files/ComplexDataTypesDocLitW.wsdl",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost/samples/DocLitW_Service.php"));
    $proxy = $client->getProxy();	
    $int_array = array(2147483647, -2147483647, 0, 1, -1, 50);
    $a = array("inArrayInt1D" => $int_array);
    $val =  $proxy->RetArrayInt1D($a);    
    echo "\n";
    var_dump($val);

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

--EXPECT--
object(stdClass)#3 (1) {
  ["RetArrayInt1DResult"]=>
  object(stdClass)#4 (1) {
    ["int"]=>
    array(6) {
      [0]=>
      int(2147483647)
      [1]=>
      int(-2147483647)
      [2]=>
      int(0)
      [3]=>
      int(1)
      [4]=>
      int(-1)
      [5]=>
      int(50)
    }
  }
}









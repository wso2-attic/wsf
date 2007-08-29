--TEST--
Test for RetArrayDecimal1D_valid_values_DocLitW sample
--FILE--

<?php


try {

    $client = new WSClient(array("wsdl"=>"tests/samples/misc_files/ComplexDataTypesDocLitW.wsdl",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost/samples/DocLitW_Service.php"));
    $proxy = $client->getProxy();	
    $int_array = array(2147483647, -2147483647, 0, 1, -1, 50);
    $a = array("inArrayDecimal1D" => $int_array);
    $val =  $proxy->RetArrayDecimal1D($a);    
    echo "\n";
    var_dump($val);

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>
--EXPECT--
object(stdClass)#3 (1) {
  ["RetArrayDecimal1DResult"]=>
  object(stdClass)#4 (1) {
    ["decimal"]=>
    array(6) {
      [0]=>
      string(10) "2147483647"
      [1]=>
      string(11) "-2147483647"
      [2]=>
      string(1) "0"
      [3]=>
      string(1) "1"
      [4]=>
      string(2) "-1"
      [5]=>
      string(2) "50"
    }
  }
}









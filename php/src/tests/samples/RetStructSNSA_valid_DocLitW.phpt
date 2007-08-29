--TEST--
Test for RetStructSNSA_valid_DocLitW sample
--FILE--

<?php


try {

    $client = new WSClient(array("wsdl"=>"tests/samples/misc_files/ComplexDataTypesDocLitW.wsdl",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost/samples/DocLitW_Service.php"));
    $proxy = $client->getProxy();
    $person_array = array("Age" => 25, "ID" => 203.56, "Male" => TRUE, "Name" => "WSO2 PHP DEVELOPER");
    $num_array = array(1, 0, 1);
    $sn_array = array( "inStructSNSA" => array("BaseDetails"=> $person_array, "HireDate" => date(DATE_ATOM), "JobID" => 0, "numbers" => $num_array));
    $val =  $proxy->RetStructSNSA($sn_array);    
    echo "\n";
    var_dump($val);

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>
--EXPECT--
object(stdClass)#3 (1) {
  ["RetStructSNSAResult"]=>
  object(stdClass)#4 (4) {
    ["BaseDetails"]=>
    object(stdClass)#5 (4) {
      ["Age"]=>
      float(25)
      ["ID"]=>
      float(203.56)
      ["Male"]=>
      bool(true)
      ["Name"]=>
      string(18) "WSO2 PHP DEVELOPER"
    }
    ["HireDate"]=>
    string(25) "2007-08-29T09:06:08+00:00"
    ["JobID"]=>
    int(0)
    ["numbers"]=>
    object(stdClass)#6 (1) {
      ["short"]=>
      array(3) {
        [0]=>
        int(1)
        [1]=>
        int(0)
        [2]=>
        int(1)
      }
    }
  }
}










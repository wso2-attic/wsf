--TEST--
Test for RetStructSNSAS_valid_DocLitW sample
--FILE--

<?php

try {

    $client = new WSClient(array("wsdl"=>"misc_files/ComplexDataTypesDocLitW.wsdl",
                                 "useSOAP" => "1.2",
                                 "to" => "http://localhost/samples/DocLitW_Service.php"));
    $proxy = $client->getProxy();	
    $snsas_array = array("inStructSNSAS" => array("members" => NULL, "name" => "WSO2"));
    $val =  $proxy->RetStructSNSAS($snsas_array);    
    echo "\n";
    var_dump($val);

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>
--EXPECT--
object(stdClass)#3 (1) {
  ["RetStructSNSASResult"]=>
  object(stdClass)#4 (2) {
    ["members"]=>
    NULL
    ["name"]=>
    string(4) "WSO2"
  }
}










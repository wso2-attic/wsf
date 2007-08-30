--TEST--
Test for RetArrayDateTime1D_thousand_DocLitB sample
--FILE--

<?php


try {

    $client = new WSClient(array("wsdl"=>"tests/samples/misc_files/ComplexDataTypesDocLitB.wsdl",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost/samples/DocLitB_Service.php"));
    $proxy = $client->getProxy();	
    $date_array = array();
    for($i =0; $i<1000; $i++){
        $date_array[$i] = date(DATE_ATOM);
    }
    $val =  $proxy->RetArrayDateTime1D($date_array);    
    echo "\n";
    var_dump($val);

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

--EXPECT--
object(stdClass)#3 (0) {
}









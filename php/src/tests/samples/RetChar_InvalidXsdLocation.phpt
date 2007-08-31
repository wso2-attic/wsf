--TEST--
Test for RetChar_InvalidXsdLocation sample
--FILE--

<?php


try {

    $client = new WSClient(array("wsdl"=>"misc_files/Invalid_BaseDataTypeDocLitB",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost/samples/DocLitB_Service.php"));
    $proxy = $client->getProxy();
    $char_arry = array("inChar" => '<');
    $val =  $proxy->RetChar($char_arry);
    echo "\n";
    echo $val."\n";
    

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

--EXPECT--
Hello
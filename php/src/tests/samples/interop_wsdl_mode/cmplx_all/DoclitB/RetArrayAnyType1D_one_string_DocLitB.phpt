--TEST--
Test for RetArrayAnyType1D_one_string_DocLitB sample
--FILE--

<?php

try {

    $client = new WSClient(array("wsdl"=>"http://131.107.72.15/SoapWsdl_ComplexDataTypes_XmlFormatter_Service_Indigo/ComplexDataTypesDocLitB.svc?wsdl"));

    $proxy = $client->getProxy();	
    $empty_any= array("Hello World");
    $val =  $proxy->RetArrayAnyType1D(array($empty_any));    
    echo "\n";
    var_dump($val);


} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

--EXPECT--
object(stdClass)#3 (0) {
}









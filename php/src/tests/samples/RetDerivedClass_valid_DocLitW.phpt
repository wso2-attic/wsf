--TEST--
Test for RetDerivedClass_valid_DocLitW sample
--FILE--

<?php


try {

    $client = new WSClient(array("wsdl"=>"misc_files/ComplexDataTypesDocLitB.wsdl",
                                 "useSOAP" => "1.1"));
    $proxy = $client->getProxy();	
    $der_array = array("color" => "Pink", "price" => 123.34, "seatingCapacity" => 234);
    $val =  $proxy->RetDerivedClass(array("inDerivedClass" => $der_array));    
    echo "\n";
    var_dump($val);

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>
--EXPECT--
Response = <ns1:echo xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echo>










--TEST--
Test for RetArrayAnyType1D_one_string sample
--FILE--

<?php



try {

    $client = new WSClient(array("wsdl"=>"ComplexDataTypesDocLitB.wsdl",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost:9090/SoapWsdl_ComplexDataTypes_XmlFormatter_Service_Indigo/ComplexDataTypesDocLitB.svc"));
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
Response = <ns1:echo xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echo>
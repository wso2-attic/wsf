--TEST--
Test for RetArrayAnyType1D_one_string sample
--FILE--

<?php

try {

    $client = new WSClient(array("wsdl"=>"ComplexDataTypesDocLitB.wsdl",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost:9090/SoapWsdl_ComplexDataTypes_XmlFormatter_Service_Indigo/ComplexDataTypesDocLitB.svc"));
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
Response = <ns1:echo xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echo>









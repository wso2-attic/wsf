--TEST--
Test for RetArrayAnyType1D_one_string_service sample
--FILE--

<?php

try {

    $client = new WSClient(array("wsdl"=>"misc_files/ComplexDataTypesDocLitW.wsdl",
                                 "useSOAP" => "1.1"));
    $proxy = $client->getProxy();	
    $empty_any= array("inArrayAnyType1D" =>array("Hello World"));
    $val =  $proxy->RetArrayAnyType1D($empty_any);    
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








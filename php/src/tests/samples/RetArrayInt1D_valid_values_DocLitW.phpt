--TEST--
Test for RetArrayInt1D_valid_values_DocLitW sample
--FILE--

<?php


try {

    $client = new WSClient(array("wsdl"=>"misc_files/ComplexDataTypesDocLitB.wsdl",
                                 "useSOAP" => "1.1"));
    $proxy = $client->getProxy();	
    $int_array = array(2147483647, -2147483647, 0, 1, -1, 50);
    $a = array("inArrayInt1D" => $int_array);
    $val =  $proxy->RetArrayInt1D($a);    
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









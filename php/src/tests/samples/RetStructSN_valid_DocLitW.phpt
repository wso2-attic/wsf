--TEST--
Test for RetStructSN_valid_DocLitW sample
--FILE--

<?php

try {

    $client = new WSClient(array("wsdl"=>"misc_files/ComplexDataTypesDocLitB.wsdl",
                                 "useSOAP" => "1.1"));
    $proxy = $client->getProxy();	
    $sn_array = array("inStructSN" => array("Age" => 34, "ID" => 123.45, "Male" => TRUE, "Name" => "WSO2 PHP Developer"));
    $val =  $proxy->RetStructSN($sn_array);    
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









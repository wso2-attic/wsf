--TEST--
Test for RetStructSNSAS_valid_DocLitW sample
--FILE--

<?php

try {

    $client = new WSClient(array("wsdl"=>"misc_files/ComplexDataTypesDocLitW.wsdl",
                                 "useSOAP" => "1.1"));
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
Response = <ns1:echo xmlns:ns1="http://php.axis2.org/samples">
		<text>Hello World!</text>
	</ns1:echo>










--TEST--
Test for RetStructSNSA_valid_DocLitW sample
--FILE--

<?php


try {

    $client = new WSClient(array("wsdl"=>"misc_files/ComplexDataTypesDocLitW.wsdl",
                                 "useSOAP" => "1.1"));
    $proxy = $client->getProxy();
    $person_array = array("Age" => 25, "ID" => 203.56, "Male" => TRUE, "Name" => "WSO2 PHP DEVELOPER");
    $num_array = array(1, 0, 1);
    $sn_array = array( "inStructSNSA" => array("BaseDetails"=> $person_array, "HireDate" => date(DATE_ATOM), "JobID" => 0, "numbers" => $num_array));
    $val =  $proxy->RetStructSNSA($sn_array);    
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










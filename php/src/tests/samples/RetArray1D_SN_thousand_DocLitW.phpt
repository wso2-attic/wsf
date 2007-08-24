--TEST--
Test for RetArrayAnyType1D_one_string sample
--FILE--

<?php


try {

    $client = new WSClient(array("wsdl"=>"ComplexDataTypesDocLitW.wsdl",
                                 "useSOAP" => "1.1",
                                 "to" => "http://localhost:9090/SoapWsdl_ComplexDataTypes_XmlFormatter_Service_Indigo/ComplexDataTypesDocLitW.svc"));
    $proxy = $client->getProxy();	
    
    for($i = 0; $i <1000; $i++){
        if ($odd = $i%2)
            $sex = FALSE;
        else
            $sex = TRUE;
        $person_array[$i] = array("Age" => (24+$i), "ID" => $i, "Male" => $sex, "Name" => "WSO2 PHP DEVELOPER".$i);
    }

    $sn_array = array("inArray1D_SN" => $person_array);
    $val =  $proxy->RetArray1D_SN($sn_array);    
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








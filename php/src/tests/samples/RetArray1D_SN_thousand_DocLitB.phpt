--TEST--
Test for RetArray1D_SN_thousand sample
--FILE--

<?php

try {

    $client = new WSClient(array("wsdl"=>"misc_files/ComplexDataTypesDocLitB.wsdl",
                                 "useSOAP" => "1.1"));
    $proxy = $client->getProxy();	
    $person_array = array();

    for($i = 0; $i <1000; $i++){
        if ($odd = $i%2)
            $sex = FALSE;
        else
            $sex = TRUE;
        $person_array[$i] = array("Age" => (24+$i), "ID" => $i, "Male" => $sex, "Name" => "WSO2 PHP DEVELOPER".$i);
    }
    $val =  $proxy->RetArray1D_SN($person_array);    
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
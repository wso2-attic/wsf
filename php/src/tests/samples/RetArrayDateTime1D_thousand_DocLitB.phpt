--TEST--
Test for RetArrayDateTime1D_thousand sample
--FILE--

<?php


try {

    $client = new WSClient(array("wsdl"=>"misc_files/ComplexDataTypesDocLitB.wsdl",
                                 "useSOAP" => "1.1"));
    $proxy = $client->getProxy();	
    $date_array = array();
    for($i =0; $i<1000; $i++){
        $date_array[$i] = date(DATE_ATOM);
    }
    $val =  $proxy->RetArrayDateTime1D($date_array);    
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









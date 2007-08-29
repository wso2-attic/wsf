--TEST--
Test for RetArrayString2D_mix_service sample
--FILE--


<?php


try {

    $client = new WSClient(array("wsdl"=>"misc_files/ComplexDataTypesDocLitW.wsdl",
                                 "useSOAP" => "1.1"));
    $proxy = $client->getProxy();
    $string_2D_array = array();

    
    $tmp_array[1] = "1,1";$tmp_array[2] = "1,2";$tmp_array[3] = "1,3";$tmp_array[4] = "1,4";$tmp_array[5] = "1,5";
    $string_2D_array[1] = $tmp_array;
    $tmp_array1[1] = "2,1";
    $string_2D_array[2] = $tmp_array1;
    $string_2D_array[3] = array();
    $string_2D_array[4] = NULL;
    $tmp_array[1] = "5,1";$tmp_array[2] = "5,2";$tmp_array[3] = NULL;$tmp_array[4] = "5,4";$tmp_array[5] = NULL;
    $string_2D_array[5] = $tmp_array;
    
    $a = array("inArrayString2D" => $string_2D_array);
    $val =  $proxy->RetArrayString2D($a);    
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









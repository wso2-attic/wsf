--TEST--
Test for RetArrayDateTime1D_thousand_DocLitB sample
--FILE--

<?php


try {

    $client = new WSClient(array("wsdl"=>"http://131.107.72.15/SoapWsdl_ComplexDataTypes_XmlFormatter_Service_Indigo/ComplexDataTypesDocLitB.svc?wsdl"));
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
Notice: Trying to get property of non-object in C:\wsfphp\wso2-wsf-php-bin-1.2.0-win32\scripts\dynamic_invocation\wsf_wsdl_util.php on line 730

array(1) {
  ["dateTime"]=>
  string(25) "2008-01-30T01:52:31-08:00"
}









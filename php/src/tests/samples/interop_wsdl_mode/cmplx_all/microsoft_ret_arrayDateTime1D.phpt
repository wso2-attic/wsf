--TEST--
RetArrayDateTime1D
--FILE--
<?php

class RetArrayDateTime1DWrapper
{
    public $inArrayDateTime1D;
}


class ArrayOfNullableOfdateTimeWrapper
{
    public $dateTime;
}

class RetArrayDateTime1DResponseWrapper
{
    public $RetArrayDateTime1DResult;
}



$classmap = array("RetArrayDateTime1D" => "RetArrayDateTime1DWrapper",
                  "ArrayOfNullableOfdateTime" => "ArrayOfNullableOfdateTimeWrapper",
                  "RetArrayDateTime1DResponse" => "RetArrayDateTime1DResponseWrapper");


try{

    $client = new WSClient(array("wsdl"=> "http://131.107.72.15/SoapWsdl_ComplexDataTypes_XmlFormatter_Service_Indigo/ComplexDataTypesDocLitW.svc?wsdl"/*  "./wsdls/ComplexDataTypesDocLitW.wsdl" */,
                                 "classmap" => $classmap));

    $input = new RetArrayDateTime1DWrapper();
    $obj = new ArrayOfNullableOfdateTimeWrapper();
    $obj->dateTime = "2005-01-01T19:29:00-08:00";

    $input->inArrayDateTime1D = $obj;

    
    $proxy = $client->getProxy();
    $val = $proxy->RetArrayDateTime1D($input);
    echo $val->RetArrayDateTime1DResult->dateTime;

}catch (Exception $e) {

    if ($e instanceof WSFault) {
        printf("Soap Fault Reason: %s\n", $e->Reason);
        printf("Soap Fault Code: %s \n", $e->Code);

    } else {
        printf("Message = %s\n",$e->getMessage());
    }

}
?>
--EXPECT--
2005-01-01T19:29:00-08:00

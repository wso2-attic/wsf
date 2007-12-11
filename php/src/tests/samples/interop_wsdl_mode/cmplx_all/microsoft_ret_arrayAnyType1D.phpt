--TEST--
RetArrayAnyType1D
--FILE--
<?php

class RetArrayAnyType1DWrapper
{
    public $inArrayAnyType1D;
}


class ArrayOfanyTypeWrapper
{
    public $anyType;
}

class RetArrayAnyType1DResponseWrapper
{
    public $RetArrayAnyType1DResult;
}



$classmap = array("RetArrayAnyType1D" => "RetArrayAnyType1DWrapper",
                  "ArrayOfanyType" => "ArrayOfanyTypeWrapper",
                  "RetArrayAnyType1DResponse" => "RetArrayAnyType1DResponseWrapper");


try{

    $client = new WSClient(array("wsdl"=> "http://131.107.72.15/SoapWsdl_ComplexDataTypes_XmlFormatter_Service_Indigo/ComplexDataTypesDocLitW.svc?wsdl" ,
                                 "classmap" => $classmap));

    $input = new RetArrayAnyType1DWrapper();
    $obj = new ArrayOfanyTypeWrapper();
    $obj->anyType = "Hello";
    $input->inArrayAnyType1D = $obj;

    
    $proxy = $client->getProxy();
    $val = $proxy->RetArrayAnyType1D($input);
    echo "Result is:"."\n"; 
    var_dump($val);
    print_r($val);

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
Result is:
string(2) "34"

string(12) "3.432543E+07"

string(4) "true"

string(6) "Tester"


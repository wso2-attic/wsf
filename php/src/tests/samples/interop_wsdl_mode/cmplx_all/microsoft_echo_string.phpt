--TEST--
RetArrayString1D
--FILE--
<?php

class RetArrayString1DWrapper
{
    public $inArrayString1D;
}


class ArrayOfstringWrapper
{
    public $string;
}

class RetArrayString1DResponseWrapper
{
    public $RetArrayString1DResult;
}



$classmap = array("RetArrayString1D" => "RetArrayString1DWrapper",
                  "ArrayOfstring" => "ArrayOfstringWrapper",
                  "RetArrayString1DResponse" => "RetArrayString1DResponseWrapper");


try{

    $client = new WSClient(array("wsdl"=> "http://131.107.72.15/SoapWsdl_ComplexDataTypes_XmlFormatter_Service_Indigo/ComplexDataTypesDocLitW.svc?wsdl"/*  "./wsdls/ComplexDataTypesDocLitW.wsdl" */,
                                 "classmap" => $classmap));

    $input = new RetArrayString1DWrapper();
    $obj = new ArrayOfstringWrapper();
    $obj->string = "Hello world";

    $input->inArrayString1D = $obj;

    
    $proxy = $client->getProxy();
    $val = $proxy->RetArrayString1D($input);
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
RetArrayString1DResponseWrapper Object
(
    [RetArrayString1DResult] => ArrayOfstringWrapper Object
        (
            [string] => Hello world
        )

)

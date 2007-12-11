--TEST--
RetArrayString2D
--FILE--
<?php

class RetArrayString2DWrapper
{
    public $inArrayString2D;
}


class ArrayOfArrayOfstringWrapper
{
    public $stringa;
}

class RetArrayString2DResponseWrapper
{
    public $RetArrayString2DResult;
}



$classmap = array("RetArrayString2D" => "RetArrayString1DWrapper",
                  "ArrayOfArrayOfstring" => "ArrayOfArrayOfstringWrapper",
                  "RetArrayString2DResponse" => "RetArrayString2DResponseWrapper");


try{

    $client = new WSClient(array("wsdl"=> "http://131.107.72.15/SoapWsdl_ComplexDataTypes_XmlFormatter_Service_Indigo/ComplexDataTypesDocLitW.svc?wsdl"/*  "./wsdls/ComplexDataTypesDocLitW.wsdl" */,
                                 "classmap" => $classmap));

    $input = new RetArrayString2DWrapper();
    $obj = new ArrayOfArrayOfstringWrapper();

    $string_2D_array = array();

    for ($i = 0; $i <100; $i++){
        for($j=0 ; $j < 100; $j++){
            $string = "2D 100x100: ".($i+1).", ".($j+1);
            $tmp_array[$j] = $string;
        }
        $string_2D_array[$i] = $tmp_array;
    }


    $obj->stringa = array("inArrayString2D" => $string_2D_array);

    $input->inArrayString2D = $obj;
    
    $proxy = $client->getProxy();
    $val = $proxy->RetArrayString2D($input);
    print_r($val);
    var_dump($val);

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

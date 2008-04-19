--TEST--
RetArrayAnyType1D
--FILE--
<?php

class RetArrayAnyType1DWrapper
{
    public $inArrayAnyType1D; // ArrayOfanyType
}


class ArrayOfanyTypeWrapper
{
    public $anyType; // array of anyType
}

class RetArrayAnyType1DResponseWrapper
{
    public $RetArrayAnyType1DResult; // ArrayOfanyType
}



$classmap = array("RetArrayAnyType1D" => "RetArrayAnyType1DWrapper",
                  "ArrayOfanyType" => "ArrayOfanyTypeWrapper",
                  "RetArrayAnyType1DResponse" => "RetArrayAnyType1DResponseWrapper");


try{
     $wsdl = file_get_contents('samples/config/cmplxDataTypesWsdlDoclitW.txt');
    $client = new WSClient(array("wsdl"=>$wsdl, "classmap" => $classmap));

    $input = new RetArrayAnyType1DWrapper();
    $obj = new ArrayOfanyTypeWrapper();
    $obj->anyType = array("Hello1", "Hello2");
    $input->inArrayAnyType1D = $obj;

    
    $proxy = $client->getProxy();
    $val = $proxy->RetArrayAnyType1D($input);
    echo "Result is:"."\n"; 
    
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
RetArrayAnyType1DResponseWrapper Object
(
    [RetArrayAnyType1DResult] => ArrayOfanyTypeWrapper Object
        (
            [anyType] => Array
                (
                    [0] => Hello1
                    [1] => Hello2
                )

        )

)



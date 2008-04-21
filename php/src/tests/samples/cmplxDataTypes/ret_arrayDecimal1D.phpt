--TEST--
RetArrayDecimal1D
--FILE--
<?php

class RetArrayDecimal1DWrapper
{
    public $inArrayDecimal1D;
}


class ArrayOfNullableOfdecimal1DWrapper
{
    public $decimal;
}

class RetArrayDecimal1DResponseWrapper
{
    public $RetArrayDecimal1DResult;
}



$classmap = array("RetArrayDecimal1D" => "RetArrayDecimal1DWrapper",
                  "ArrayOfNullableOfdecimal" => "ArrayOfNullableOfdecimal1DWrapper",
                  "RetArrayDecimal1DResponse" => "RetArrayDecimal1DResponseWrapper");


try{

     $wsdl = file_get_contents('samples/config/cmplxDataTypesWsdlDoclitW.txt');
    $client = new WSClient(array("wsdl"=>$wsdl, "classmap" => $classmap));

    $input = new RetArrayDecimal1DWrapper();
    $obj = new ArrayOfNullableOfdecimal1DWrapper();
    $obj->decimal = 0.61803398874989484820458683;

    $input->inArrayDecimal1D = $obj;

    
    $proxy = $client->getProxy();
    $val = $proxy->RetArrayDecimal1D($input);
    echo $val->RetArrayDecimal1DResult->decimal[0];

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
0.61803398874989

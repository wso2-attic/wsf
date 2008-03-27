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
     $wsdl = file_get_contents('samples/config/cmplxDataTypesWsdlDoclitW.txt');
    $client = new WSClient(array("wsdl"=>$wsdl , "classmap" => $classmap));

    $input = new RetArrayDateTime1DWrapper();
    $obj = new ArrayOfNullableOfdateTimeWrapper();
    $obj->dateTime = "2005-01-01T19:29:00-08:00";

    $input->inArrayDateTime1D = $obj;

    
    $proxy = $client->getProxy();
    $val = $proxy->RetArrayDateTime1D($input);
    echo $val->RetArrayDateTime1DResult->dateTime[0];

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

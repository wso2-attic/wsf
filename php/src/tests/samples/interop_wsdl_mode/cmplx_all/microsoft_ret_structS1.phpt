--TEST--
RetStructS1
--FILE--
<?php

class RetStructS1Wrapper
{
    public $inStructS1;
}


class NameWrapper
{
    public $name;
}

class RetStructS1ResponseWrapper
{
    public $RetStructS1Result;
}



$classmap = array("RetStructS1" => "RetStructS1Wrapper",
                  "Name" => "NameWrapper",
                  "RetStructS1Response" => "RetStructS1ResponseWrapper");


try{

    $client = new WSClient(array("wsdl"=> "http://131.107.72.15/SoapWsdl_ComplexDataTypes_XmlFormatter_Service_Indigo/ComplexDataTypesDocLitW.svc?wsdl" ,
                                 "classmap" => $classmap));

    $input = new RetStructS1Wrapper();
    $obj = new NameWrapper();
    $obj->name = "Tester";

    $input->inStructS1 = $obj;

    
    $proxy = $client->getProxy();
    $val = $proxy->RetStructS1($input);
    echo "Result is:"."\n"; 
    var_dump($val);
    echo $val->RetStructS1Result->name;	
    	

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
Tester

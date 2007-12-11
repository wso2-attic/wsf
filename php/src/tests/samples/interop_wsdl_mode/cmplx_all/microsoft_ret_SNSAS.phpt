--TEST--
RetStructSNSAS
--FILE--
<?php

class RetStructSNSASWrapper
{
    public $inStructSNSAS;
}


class GroupWrapper
{
    public $name;
    public $members;
   
}

class RetStructSNSASResponseWrapper
{
    public $RetStructSNSASResult;
}

class ArrayOfPersonWrapper
{
    public $Age;
    public $ID;
    public $Male;
    public $Name;
}

$classmap = array("RetStructSNSAS" => "RetStructSNSASWrapper",
                  "RetStructSNSASResponse" => "RetStructSNSASResponseWrapper",
                  "ArrayOfPerson" => "ArrayOfPersonWrapper",
                  "Group" => "GroupWrapper");
                  

try{

    $client = new WSClient(array("wsdl"=> "http://131.107.72.15/SoapWsdl_ComplexDataTypes_XmlFormatter_Service_Indigo/ComplexDataTypesDocLitW.svc?wsdl" ,
                                 "classmap" => $classmap));



    $input = new RetStructSNSASWrapper();
    $obj = new GroupWrapper();
    $objPerson = new ArrayOfPersonWrapper();

    $objPerson->Age = 23;
    $objPerson->ID = 12;
    $objPerson->Male =TRUE;
    $objPerson->Name = "TesterQA";

    $obj->name = "TesterDev";
    $obj->member = $objPerson;

    $input->inStructSNSAS = $obj;
    
    $proxy = $client->getProxy();
    $val = $proxy->RetStructSNSAS($input);
    echo "Result is:"."\n"; 
    var_dump($val);
    echo "\n";
    var_dump($val->RetStructSNSASResult);
    echo "\n";

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

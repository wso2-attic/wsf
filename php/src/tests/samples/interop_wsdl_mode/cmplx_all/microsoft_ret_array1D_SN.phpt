--TEST--
RetArray1D_SN
--FILE--
<?php

class RetArray1D_SNWrapper
{
    public $inArray1D_SN;
}


class ArrayOfPersonWrapper
{
    public $Age;
    public $ID;
    public $Male;
    public $Name;
}

class RetArray1D_SNResponseWrapper
{
    public $RetArray1D_SNResult;
}



$classmap = array("RetArray1D_SN" => "RetArray1D_SNWrapper",
                  "ArrayOfPerson" => "ArrayOfPersonWrapper",
                  "RetArray1D_SNResponse" => "RetArray1D_SNResponseWrapper");


try{

    $client = new WSClient(array("wsdl"=> "http://131.107.72.15/SoapWsdl_ComplexDataTypes_XmlFormatter_Service_Indigo/ComplexDataTypesDocLitW.svc?wsdl" ,
                                 "classmap" => $classmap));

    $input = new RetArray1D_SNWrapper();
    $obj = new ArrayOfPersonWrapper();
 
    $obj->Age = 23;
    $obj->ID = 4;
    $obj->Male = TRUE;
    $obj->Name = "Tester";     

    $input->inArray1D_SN = $obj;

    
    $proxy = $client->getProxy();
    $val = $proxy->RetArray1D_SN($input);
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


--TEST--
RetStructSNSA
--FILE--
<?php

class RetStructSNSAWrapper
{
    public $inStructSNSA;
}


class EmployeeWrapper
{
    public $BaseDetails;
    public $HireDate;
    public $JobID;
    public $numbers;
}

class RetStructSNSAResponseWrapper
{
    public $RetStructSNSAResult;
}

class PersonWrapper
{
    public $Age;
    public $ID;
    public $Male;
    public $Name;
}

class ArrayOfshortWrapper
{
    public $short;
}

$classmap = array("RetStructSNSA" => "RetStructSNSAWrapper",
                  "Employee" => "EmployeeWrapper",
                  "RetStructSNSAResponse" => "RetStructSNSAResponseWrapper",
                  "Person" => "PersonWrapper",
		  "ArrayOfshort" => "ArrayOfshortWrapper");
                  

try{

    $client = new WSClient(array("wsdl"=> "http://131.107.72.15/SoapWsdl_ComplexDataTypes_XmlFormatter_Service_Indigo/ComplexDataTypesDocLitW.svc?wsdl"/* "http://localhost/wsdls/microsoft/ComplexDataTypesDocLitW.wsdl" */,
                                 "classmap" => $classmap));



    $input = new RetStructSNSAWrapper();
    $obj = new EmployeeWrapper();
    $personObj= new PersonWrapper();
    $shortObj = new ArrayOfshortWrapper();

    $shortObj->short = 34;

	
    $personObj->Age = 23;
    $personObj->ID = 123.45;
    $personObj->Male = TRUE;
    $personObj->Name = "Tester";

    $obj->BaseDetails = $personObj;
    $obj->HireDate = "2005-12-12T12:00:00";
    $obj->JobID = 50;
    $obj->numbers = $shortObj;


    $input->inStructSNSA = $obj;

    
    $proxy = $client->getProxy();
    $val = $proxy->RetStructSNSA($input);
    echo "Result is:"."\n"; 
    var_dump($val);
    echo "\n";
    var_dump($val->RetStructSNSAResult->BaseDetails->Age);
    var_dump($val->RetStructSNSAResult->BaseDetails->ID);
    var_dump($val->RetStructSNSAResult->BaseDetails->Male);
    var_dump($val->RetStructSNSAResult->BaseDetails->Name);


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
object(RetStructSNSAResponseWrapper)#27 (1) {
  ["RetStructSNSAResult"]=>
  object(EmployeeWrapper)#18 (4) {
    ["BaseDetails"]=>
    object(PersonWrapper)#23 (4) {
      ["Age"]=>
      string(2) "23"
      ["ID"]=>
      string(6) "123.45"
      ["Male"]=>
      string(4) "true"
      ["Name"]=>
      string(6) "Tester"
    }
    ["HireDate"]=>
    string(19) "2005-12-12T12:00:00"
    ["JobID"]=>
    string(2) "50"
    ["numbers"]=>
    object(ArrayOfshortWrapper)#16 (1) {
      ["short"]=>
      string(2) "34"
    }
  }
}

object(PersonWrapper)#23 (4) {
  ["Age"]=>
  string(2) "23"
  ["ID"]=>
  string(6) "123.45"
  ["Male"]=>
  string(4) "true"
  ["Name"]=>
  string(6) "Tester"
}






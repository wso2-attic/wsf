--TEST--
RetStructSN
--FILE--
<?php

class RetStructSNWrapper
{
    public $inStructSN;
}


class PersonWrapper
{
    public $Age;
    public $ID;
    public $Male;
    public $Name;
}

class RetStructSNResponseWrapper
{
    public $RetStructSNResult;
}



$classmap = array("RetStructSN" => "RetStructSNWrapper",
                  "Person" => "PersonWrapper",
                  "RetStructSNResponse" => "RetStructSNResponseWrapper");


try{
    $wsdl = file_get_contents('samples/config/cmplxDataTypesWsdlDoclitW.txt');
    $client = new WSClient(array("wsdl"=>$wsdl , "classmap" => $classmap));

    $input = new RetStructSNWrapper();
    $obj = new PersonWrapper();
    $obj->Age = 34;
    $obj->ID = 34325434;
    $obj->Male = TRUE;
    $obj->Name = "Tester";

    $input->inStructSN = $obj;

    
    $proxy = $client->getProxy();
    $val = $proxy->RetStructSN($input);
    echo "Result is:"."\n"; 
    var_dump($val->RetStructSNResult->Age);
    echo "\n";
    var_dump($val->RetStructSNResult->ID);
    echo "\n";
    var_dump($val->RetStructSNResult->Male);
    echo "\n";
    var_dump($val->RetStructSNResult->Name);	
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
float(34)

float(34325434)

bool(true)

string(6) "Tester"



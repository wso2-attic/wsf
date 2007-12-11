--TEST--i
RetArrayInt1D
--FILE--
<?php

class RetArrayInt1DWrapper
{
    public $inArrayInt1D;
}


class ArrayOfIntWrapper
{
    public $int;
}

class RetArrayInt1DResponseWrapper
{
    public $RetArrayInt1DResult;
}



$classmap = array("RetArrayInt1D" => "RetArrayInt1DWrapper",
                  "ArrayOfint" => "ArrayOfIntWrapper",
                  "RetArrayInt1DResponse" => "RetArrayInt1DResponseWrapper");


try{

    $client = new WSClient(array("wsdl"=> "http://131.107.72.15/SoapWsdl_ComplexDataTypes_XmlFormatter_Service_Indigo/ComplexDataTypesDocLitW.svc?wsdl"/*  "./wsdls/ComplexDataTypesDocLitW.wsdl" */,
                                 "classmap" => $classmap));

    $input = new RetArrayInt1DWrapper();
    $obj = new ArrayOfIntWrapper();
    $obj->int = 100;

    $input->inArrayInt1D = $obj;

    
    $proxy = $client->getProxy();
    $val = $proxy->RetArrayInt1D($input);
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
RetArrayInt1DResponseWrapper Object
	(
	    [RetArrayInt1DResult] => ArrayOfIntWrapper Object
		(
		    [int] => Array
		        (
		            [0] => 100
		        )

		)

	)

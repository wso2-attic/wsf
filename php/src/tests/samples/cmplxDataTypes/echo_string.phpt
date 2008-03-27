--TEST--
RetArrayString1D
--FILE--
<?php

class inArrayString1D { 
    public $string; //string
}

class RetArrayString1DResult { 
    public $string; //string
}

class inArrayInt1D { 
    public $int; //int
}

class RetArrayInt1DResult { 
    public $int; //int
}

class inArrayDecimal1D { 
    public $decimal; //decimal
}

class RetArrayDecimal1DResult { 
    public $decimal; //decimal
}

class inArrayDateTime1D { 
    public $dateTime; //dateTime
}

class RetArrayDateTime1DResult { 
    public $dateTime; //dateTime
}

class inArrayString2D { 
    public $ArrayOfstring; //ArrayOfstring
}

class ArrayOfstring { 
    public $string; //string
}

class RetArrayString2DResult { 
    public $ArrayOfstring; //ArrayOfstring
}

class inArray1D_SN { 
    public $Person; //Person
}

class Person { 
    public $Age; //double
    public $ID; //float
    public $Male; //boolean
    public $Name; //string
}

class RetArray1D_SNResult { 
    public $Person; //Person
}

class inArrayAnyType1D { 
    public $anyType; //anyType
}

class anyType { 
}

class RetArrayAnyType1DResult { 
    public $anyType; //anyType
}

class inStructS1 { 
    public $name; //string
}

class RetStructS1Result { 
    public $name; //string
}

class inStructSN { 
    public $Age; //double
    public $ID; //float
    public $Male; //boolean
    public $Name; //string
}

class RetStructSNResult { 
    public $Age; //double
    public $ID; //float
    public $Male; //boolean
    public $Name; //string
}

class inStructSNSA { 
    public $BaseDetails; //Person
    public $HireDate; //dateTime
    public $JobID; //unsignedInt
    public $numbers; //ArrayOfshort
}

class ArrayOfshort { 
    public $short; //short
}

class RetStructSNSAResult { 
    public $BaseDetails; //Person
    public $HireDate; //dateTime
    public $JobID; //unsignedInt
    public $numbers; //ArrayOfshort
}

class inStructSNSAS { 
    public $members; //ArrayOfPerson
    public $name; //string
}

class ArrayOfPerson { 
    public $Person; //Person
}

class RetStructSNSASResult { 
    public $members; //ArrayOfPerson
    public $name; //string
}

// define the class map
$class_map = array(
 "inArrayString1D" => "inArrayString1D", "RetArrayString1DResult" => "RetArrayString1DResult", "inArrayInt1D" => "inArrayInt1D", "RetArrayInt1DResult" => "RetArrayInt1DResult", "inArrayDecimal1D" => "inArrayDecimal1D", "RetArrayDecimal1DResult" => "RetArrayDecimal1DResult", "inArrayDateTime1D" => "inArrayDateTime1D", "RetArrayDateTime1DResult" => "RetArrayDateTime1DResult", "inArrayString2D" => "inArrayString2D", "ArrayOfstring" => "ArrayOfstring", "RetArrayString2DResult" => "RetArrayString2DResult", "inArray1D_SN" => "inArray1D_SN", "Person" => "Person", "RetArray1D_SNResult" => "RetArray1D_SNResult", "inArrayAnyType1D" => "inArrayAnyType1D", "anyType" => "anyType", "RetArrayAnyType1DResult" => "RetArrayAnyType1DResult", "inStructS1" => "inStructS1", "RetStructS1Result" => "RetStructS1Result", "inStructSN" => "inStructSN", "RetStructSNResult" => "RetStructSNResult", "inStructSNSA" => "inStructSNSA", "ArrayOfshort" => "ArrayOfshort", "RetStructSNSAResult" => "RetStructSNSAResult", "inStructSNSAS" => "inStructSNSAS", "ArrayOfPerson" => "ArrayOfPerson", "RetStructSNSASResult" => "RetStructSNSASResult");

try {


  
    $wsdl = file_get_contents('samples/config/cmplxDataTypeWsdlDoclitB.txt');
    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>$wsdl, "classmap" => $class_map));

    // get proxy object reference form client 
    $proxy = $client->getProxy();
    
    $input = new inArrayString1D();
    $input->string = "Hello World";
    $val = $proxy->RetArrayString1D($input);
    print_r($val);

    
} catch (Exception $e) {
	// in case of an error, process the fault
	if ($e instanceof WSFault) {
		printf("Soap Fault: %s\n", $e->Reason);
	} else {
		printf("Message = %s\n", $e->getMessage());
	}
}
?>
--EXPECT--
RetArrayString1DResult Object
(
    [string] => Array
        (
            [0] => Hello World
        )

)

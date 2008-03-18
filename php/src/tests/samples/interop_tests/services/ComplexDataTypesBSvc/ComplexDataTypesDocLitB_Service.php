<?php

// PHP classes corresponding to the data types in defined in WSDL

class inArrayString1D { 
    public $string; // array of string
}

class RetArrayString1DResult { 
    public $string; // array of string
}

class inArrayInt1D { 
    public $int; // array of int
}

class RetArrayInt1DResult { 
    public $int; // array of int
}

class inArrayDecimal1D { 
    public $decimal; // array of decimal
}

class RetArrayDecimal1DResult { 
    public $decimal; // array of decimal
}

class inArrayDateTime1D { 
    public $dateTime; // array of dateTime
}

class RetArrayDateTime1DResult { 
    public $dateTime; // array of dateTime
}

class inArrayString2D { 
    public $ArrayOfstring; // array of ArrayOfstring
}

class ArrayOfstring { 
    public $string; // array of string
}

class RetArrayString2DResult { 
    public $ArrayOfstring; // array of ArrayOfstring
}

class inArray1D_SN { 
    public $Person; // array of Person
}

class Person { 
    public $Age; // double
    public $ID; // float
    public $Male; // boolean
    public $Name; // string
}

class RetArray1D_SNResult { 
    public $Person; // array of Person
}

class inArrayAnyType1D { 
    public $anyType; // array of anyType
}

class anyType { 
}

class RetArrayAnyType1DResult { 
    public $anyType; // array of anyType
}

class inStructS1 { 
    public $name; // string
}

class RetStructS1Result { 
    public $name; // string
}

class inStructSN { 
    public $Age; // double
    public $ID; // float
    public $Male; // boolean
    public $Name; // string
}

class RetStructSNResult { 
    public $Age; // double
    public $ID; // float
    public $Male; // boolean
    public $Name; // string
}

class inStructSNSA { 
    public $BaseDetails; // Person
    public $HireDate; // dateTime
    public $JobID; // unsignedInt
    public $numbers; // ArrayOfshort
}

class ArrayOfshort { 
    public $short; // array of short
}

class RetStructSNSAResult { 
    public $BaseDetails; // Person
    public $HireDate; // dateTime
    public $JobID; // unsignedInt
    public $numbers; // ArrayOfshort
}

class inStructSNSAS { 
    public $members; // ArrayOfPerson
    public $name; // string
}

class ArrayOfPerson { 
    public $Person; // array of Person
}

class RetStructSNSASResult { 
    public $members; // ArrayOfPerson
    public $name; // string
}

// define the class map
$class_map = array(
 "inArrayString1D" => "inArrayString1D", "RetArrayString1DResult" => "RetArrayString1DResult", "inArrayInt1D" => "inArrayInt1D", "RetArrayInt1DResult" => "RetArrayInt1DResult", "inArrayDecimal1D" => "inArrayDecimal1D", "RetArrayDecimal1DResult" => "RetArrayDecimal1DResult", "inArrayDateTime1D" => "inArrayDateTime1D", "RetArrayDateTime1DResult" => "RetArrayDateTime1DResult", "inArrayString2D" => "inArrayString2D", "ArrayOfstring" => "ArrayOfstring", "RetArrayString2DResult" => "RetArrayString2DResult", "inArray1D_SN" => "inArray1D_SN", "Person" => "Person", "RetArray1D_SNResult" => "RetArray1D_SNResult", "inArrayAnyType1D" => "inArrayAnyType1D", "anyType" => "anyType", "RetArrayAnyType1DResult" => "RetArrayAnyType1DResult", "inStructS1" => "inStructS1", "RetStructS1Result" => "RetStructS1Result", "inStructSN" => "inStructSN", "RetStructSNResult" => "RetStructSNResult", "inStructSNSA" => "inStructSNSA", "ArrayOfshort" => "ArrayOfshort", "RetStructSNSAResult" => "RetStructSNSAResult", "inStructSNSAS" => "inStructSNSAS", "ArrayOfPerson" => "ArrayOfPerson", "RetStructSNSASResult" => "RetStructSNSASResult");

// define PHP functions that maps to WSDL operations 
function RetArrayString1D($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inArrayString1D
    // NOTE: should return an object of type RetArrayString1DResult
	$ret = new RetArrayString1DResult();
        $ret->string = $input->string;
        return $ret;

}


function RetArrayInt1D($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inArrayInt1D
    // NOTE: should return an object of type RetArrayInt1DResult
    $ret = new RetArrayInt1DResult();
    $ret->int = $input->int;
    return $ret;
}


function RetArrayDecimal1D($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inArrayDecimal1D
    // NOTE: should return an object of type RetArrayDecimal1DResult
    $ret = new RetArrayDecimal1DResult();
    $ret->decimal = $input->decimal;
    return $ret;
}


function RetArrayDateTime1D($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inArrayDateTime1D
    // NOTE: should return an object of type RetArrayDateTime1DResult
    $ret = new RetArrayDateTime1DResult();
    $ret->dateTime = $input->dateTime;
    return $ret;
}


function RetArrayString2D($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inArrayString2D
    // NOTE: should return an object of type RetArrayString2DResult
    $ret = new RetArrayString2DResult();
    $ret->ArrayOfstring = $input->ArrayOfstring;
    return $ret;
}


function RetArray1D_SN($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inArray1D_SN
    // NOTE: should return an object of type RetArray1D_SNResult
    $ret = new RetArray1D_SNResult();
    $ret->Person = $input->Person;
    return $ret;
}


function RetArrayAnyType1D($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inArrayAnyType1D
    // NOTE: should return an object of type RetArrayAnyType1DResult
    $ret = new RetArrayAnyType1DResult();
    $ret->anyType = $input->anyType;
    return $ret;
}


function RetStructS1($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inStructS1
    // NOTE: should return an object of type RetStructS1Result
    $ret = new RetStructS1Result();
    $ret->name = $input->name;
    return $ret;
}


function RetStructSN($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inStructSN
    // NOTE: should return an object of type RetStructSNResult
    $ret = new RetStructSNResult();
    $ret->Age = $input->Age;
    $ret->ID = $input->ID;
    $ret->Male = $input->Male;
    $ret->Name = $input->Name;
    return $ret;
}


function RetStructSNSA($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inStructSNSA
    // NOTE: should return an object of type RetStructSNSAResult
    $ret = new RetStructSNSAResult();
    $ret->BaseDetails = $input->BaseDetails;
    $ret->HireDate = $input->HireDate;
    $ret->JobID = $input->JobID;
    $ret->numbers = $input->numbers;
    return $ret;
}


function RetStructSNSAS($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inStructSNSAS
    // NOTE: should return an object of type RetStructSNSASResult
    $ret = new RetStructSNSASResult();
    $ret->members = $input->members;
    $ret->name = $input->name;
    return $ret;
}





// define the operations map
$operations = array(
 "RetArrayString1D" => "RetArrayString1D", "RetArrayInt1D" => "RetArrayInt1D", "RetArrayDecimal1D" => "RetArrayDecimal1D", "RetArrayDateTime1D" => "RetArrayDateTime1D", "RetArrayString2D" => "RetArrayString2D", "RetArray1D_SN" => "RetArray1D_SN", "RetArrayAnyType1D" => "RetArrayAnyType1D", "RetStructS1" => "RetStructS1", "RetStructSN" => "RetStructSN", "RetStructSNSA" => "RetStructSNSA", "RetStructSNSAS" => "RetStructSNSAS");

// define the operations parameters map
$opParams = array(
 "RetArrayString1D" => "MIXED", "RetArrayInt1D" => "MIXED", "RetArrayDecimal1D" => "MIXED", "RetArrayDateTime1D" => "MIXED", "RetArrayString2D" => "MIXED", "RetArray1D_SN" => "MIXED", "RetArrayAnyType1D" => "MIXED", "RetStructS1" => "MIXED", "RetStructSN" => "MIXED", "RetStructSNSA" => "MIXED", "RetStructSNSAS" => "MIXED", "RetEnumString" => "MIXED", "RetEnumInt" => "MIXED", "RetDerivedClass" => "MIXED");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"ComplexDataTypesDocLitB.wsdl",
        "operations" => $operations,
        "opParams" => $opParams,
        "classmap" => $class_map));

// process client requests and reply 
$service->reply();

?>

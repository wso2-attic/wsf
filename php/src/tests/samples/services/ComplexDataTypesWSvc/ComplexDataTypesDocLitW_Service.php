<?php

// PHP classes corresponding to the data types in defined in WSDL

class RetArrayString1D { 
    public $inArrayString1D; // ArrayOfstring
}

class ArrayOfstring { 
    public $string; // array of string
}

class RetArrayString1DResponse { 
    public $RetArrayString1DResult; // ArrayOfstring
}

class RetArrayInt1D { 
    public $inArrayInt1D; // ArrayOfint
}

class ArrayOfint { 
    public $int; // array of int
}

class RetArrayInt1DResponse { 
    public $RetArrayInt1DResult; // ArrayOfint
}

class RetArrayDecimal1D { 
    public $inArrayDecimal1D; // ArrayOfNullableOfdecimal
}

class ArrayOfNullableOfdecimal { 
    public $decimal; // array of decimal
}

class RetArrayDecimal1DResponse { 
    public $RetArrayDecimal1DResult; // ArrayOfNullableOfdecimal
}

class RetArrayDateTime1D { 
    public $inArrayDateTime1D; // ArrayOfNullableOfdateTime
}

class ArrayOfNullableOfdateTime { 
    public $dateTime; // array of dateTime
}

class RetArrayDateTime1DResponse { 
    public $RetArrayDateTime1DResult; // ArrayOfNullableOfdateTime
}

class RetArrayString2D { 
    public $inArrayString2D; // ArrayOfArrayOfstring
}

class ArrayOfArrayOfstring { 
    public $ArrayOfstring; // array of ArrayOfstring
}

class RetArrayString2DResponse { 
    public $RetArrayString2DResult; // ArrayOfArrayOfstring
}

class RetArray1D_SN { 
    public $inArray1D_SN; // ArrayOfPerson
}

class ArrayOfPerson { 
    public $Person; // array of Person
}

class Person { 
    public $Age; // double
    public $ID; // float
    public $Male; // boolean
    public $Name; // string
}

class RetArray1D_SNResponse { 
    public $RetArray1D_SNResult; // ArrayOfPerson
}

class RetArrayAnyType1D { 
    public $inArrayAnyType1D; // ArrayOfanyType
}

class ArrayOfanyType { 
    public $anyType; // array of anyType
}

class anyType { 
}

class RetArrayAnyType1DResponse { 
    public $RetArrayAnyType1DResult; // ArrayOfanyType
}

class RetStructS1 { 
    public $inStructS1; // Name
}

class Name { 
    public $name; // string
}

class RetStructS1Response { 
    public $RetStructS1Result; // Name
}

class RetStructSN { 
    public $inStructSN; // Person
}

class RetStructSNResponse { 
    public $RetStructSNResult; // Person
}

class RetStructSNSA { 
    public $inStructSNSA; // Employee
}

class Employee { 
    public $BaseDetails; // Person
    public $HireDate; // dateTime
    public $JobID; // unsignedInt
    public $numbers; // ArrayOfshort
}

class ArrayOfshort { 
    public $short; // array of short
}

class RetStructSNSAResponse { 
    public $RetStructSNSAResult; // Employee
}

class RetStructSNSAS { 
    public $inStructSNSAS; // Group
}

class Group { 
    public $members; // ArrayOfPerson
    public $name; // string
}

class RetStructSNSASResponse { 
    public $RetStructSNSASResult; // Group
}

class RetEnumString { 
    public $inEnumString; // BitMask
}

class RetEnumStringResponse { 
    public $RetEnumStringResult; // BitMask
}

class RetEnumInt { 
    public $inEnumInt; // IntSet
}

class RetEnumIntResponse { 
    public $RetEnumIntResult; // IntSet
}

class RetDerivedClass { 
    public $inDerivedClass; // Table
}

class Table { 
}

class RetDerivedClassResponse { 
    public $RetDerivedClassResult; // Table
}

// define the class map
$class_map = array(
 "RetArrayString1D" => "RetArrayString1D", "ArrayOfstring" => "ArrayOfstring", "RetArrayString1DResponse" => "RetArrayString1DResponse", "RetArrayInt1D" => "RetArrayInt1D", "ArrayOfint" => "ArrayOfint", "RetArrayInt1DResponse" => "RetArrayInt1DResponse", "RetArrayDecimal1D" => "RetArrayDecimal1D", "ArrayOfNullableOfdecimal" => "ArrayOfNullableOfdecimal", "RetArrayDecimal1DResponse" => "RetArrayDecimal1DResponse", "RetArrayDateTime1D" => "RetArrayDateTime1D", "ArrayOfNullableOfdateTime" => "ArrayOfNullableOfdateTime", "RetArrayDateTime1DResponse" => "RetArrayDateTime1DResponse", "RetArrayString2D" => "RetArrayString2D", "ArrayOfArrayOfstring" => "ArrayOfArrayOfstring", "RetArrayString2DResponse" => "RetArrayString2DResponse", "RetArray1D_SN" => "RetArray1D_SN", "ArrayOfPerson" => "ArrayOfPerson", "Person" => "Person", "RetArray1D_SNResponse" => "RetArray1D_SNResponse", "RetArrayAnyType1D" => "RetArrayAnyType1D", "ArrayOfanyType" => "ArrayOfanyType", "anyType" => "anyType", "RetArrayAnyType1DResponse" => "RetArrayAnyType1DResponse", "RetStructS1" => "RetStructS1", "Name" => "Name", "RetStructS1Response" => "RetStructS1Response", "RetStructSN" => "RetStructSN", "RetStructSNResponse" => "RetStructSNResponse", "RetStructSNSA" => "RetStructSNSA", "Employee" => "Employee", "ArrayOfshort" => "ArrayOfshort", "RetStructSNSAResponse" => "RetStructSNSAResponse", "RetStructSNSAS" => "RetStructSNSAS", "Group" => "Group", "RetStructSNSASResponse" => "RetStructSNSASResponse", "RetEnumString" => "RetEnumString", "RetEnumStringResponse" => "RetEnumStringResponse", "RetEnumInt" => "RetEnumInt", "RetEnumIntResponse" => "RetEnumIntResponse", "RetDerivedClass" => "RetDerivedClass", "Table" => "Table", "RetDerivedClassResponse" => "RetDerivedClassResponse");

// define PHP functions that maps to WSDL operations 
function RetArrayString1D($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type RetArrayString1D
    // NOTE: should return an object of type RetArrayString1DResponse
	$ret =  new RetArrayString1DResponse();
	$ret->RetArrayString1DResult = $input->inArrayString1D;
        return $ret;

}


function RetArrayInt1D($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type RetArrayInt1D
    // NOTE: should return an object of type RetArrayInt1DResponse
    $ret = new RetArrayInt1DResponse();
    $ret->RetArrayInt1DResult = $input->inArrayInt1D;
    return $ret;
}


function RetArrayDecimal1D($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type RetArrayDecimal1D
    // NOTE: should return an object of type RetArrayDecimal1DResponse
    $ret = new RetArrayDecimal1DResponse();
    $ret->RetArrayDecimal1DResult = $input->inArrayDecimal1D;
    return $ret;
}


function RetArrayDateTime1D($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type RetArrayDateTime1D
    // NOTE: should return an object of type RetArrayDateTime1DResponse
    $ret = new RetArrayDateTime1DResponse();
    $ret->RetArrayDateTime1DResult = $input->inArrayDateTime1D;
    return $ret;
}


function RetArrayString2D($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type RetArrayString2D
    // NOTE: should return an object of type RetArrayString2DResponse
    $ret = new RetArrayString2DResponse();
    $ret->RetArrayString2DResult = $input->inArrayString2D;
    return $ret;
}


function RetArray1D_SN($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type RetArray1D_SN
    // NOTE: should return an object of type RetArray1D_SNResponse
    $ret = new RetArray1D_SNResponse();
    $ret->RetArray1D_SNResult = $input->inArray1D_SN;
    return $ret;
}


function RetArrayAnyType1D($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type RetArrayAnyType1D
    // NOTE: should return an object of type RetArrayAnyType1DResponse
    file_put_contents("/tmp/something", print_r($input, TRUE));
    $ret = new RetArrayAnyType1DResponse();
    $ret->RetArrayAnyType1DResult = $input->inArrayAnyType1D;
    return $ret;
}


function RetStructS1($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type RetStructS1
    // NOTE: should return an object of type RetStructS1Response
    $ret = new RetStructS1Response();
    $ret->RetStructS1Result = $input->inStructS1;
    return $ret;
}


function RetStructSN($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type RetStructSN
    // NOTE: should return an object of type RetStructSNResponse
    $ret = new RetStructSNResponse();
    $ret->RetStructSNResult = $input->inStructSN;
    return $ret;
}


function RetStructSNSA($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type RetStructSNSA
    // NOTE: should return an object of type RetStructSNSAResponse
    $ret = new RetStructSNSAResponse();
    $ret->RetStructSNSAResult = $input->inStructSNSA;
    return $ret;
}


function RetStructSNSAS($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type RetStructSNSAS
    // NOTE: should return an object of type RetStructSNSASResponse
    $ret = new RetStructSNSASResponse();
    $ret->RetStructSNSASResult = $input->inStructSNSAS;
    return $ret;
}


function RetEnumString($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type RetEnumString
    // NOTE: should return an object of type RetEnumStringResponse

    $res = new RetEnumStringResponse();
    $res->RetEnumStringResult = $input->inEnumString;
    return $res;
}


function RetEnumInt($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type RetEnumInt
    // NOTE: should return an object of type RetEnumIntResponse

    $res = new RetEnumIntResponse();
    $res->RetEnumIntResult = $input->inEnumInt;
    return $res;
}


function RetDerivedClass($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type RetDerivedClass
    // NOTE: should return an object of type RetDerivedClassResponse
    $ret = new RetDerivedClassResponse();
    $ret->RetDerivedClassResult = $input->inDerivedClass;
    return $ret;
}


// define the operations map
$operations = array(
 "RetArrayString1D" => "RetArrayString1D", "RetArrayInt1D" => "RetArrayInt1D", "RetArrayDecimal1D" => "RetArrayDecimal1D", "RetArrayDateTime1D" => "RetArrayDateTime1D", "RetArrayString2D" => "RetArrayString2D", "RetArray1D_SN" => "RetArray1D_SN", "RetArrayAnyType1D" => "RetArrayAnyType1D", "RetStructS1" => "RetStructS1", "RetStructSN" => "RetStructSN", "RetStructSNSA" => "RetStructSNSA", "RetStructSNSAS" => "RetStructSNSAS", "RetEnumString" => "RetEnumString", "RetEnumInt" => "RetEnumInt", "RetDerivedClass" => "RetDerivedClass");

// define the operations parameters map
$opParams = array(
 "RetArrayString1D" => "MIXED", "RetArrayInt1D" => "MIXED", "RetArrayDecimal1D" => "MIXED", "RetArrayDateTime1D" => "MIXED", "RetArrayString2D" => "MIXED", "RetArray1D_SN" => "MIXED", "RetArrayAnyType1D" => "MIXED", "RetStructS1" => "MIXED", "RetStructSN" => "MIXED", "RetStructSNSA" => "MIXED", "RetStructSNSAS" => "MIXED", "RetEnumString" => "MIXED", "RetEnumInt" => "MIXED", "RetDerivedClass" => "MIXED");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"ComplexDataTypesDocLitW.wsdl",
        "operations" => $operations,
        "opParams" => $opParams,
        "classmap" => $class_map));

// process client requests and reply 
$service->reply();

?>

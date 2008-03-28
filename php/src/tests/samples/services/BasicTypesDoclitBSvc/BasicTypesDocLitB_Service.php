<?php

// PHP classes corresponding to the data types in defined in WSDL
// These classes are not used in the barelit types - so the codegen should be corrected
class inBool { 
    public $boolean; // boolean
}

class RetBoolResult { 
    public $boolean; // boolean
}

class inByte { 
    public $unsignedByte; // unsignedByte
}

class RetByteResult { 
    public $unsignedByte; // unsignedByte
}

class inSByte { 
    public $byte; // byte
}

class RetSByteResult { 
    public $byte; // byte
}

class inByteArray { 
    public $base64Binary; // base64Binary
}

class RetByteArrayResult { 
    public $base64Binary; // base64Binary
}

class inDecimal { 
    public $decimal; // decimal
}

class RetDecimalResult { 
    public $decimal; // decimal
}

class inFloat { 
    public $float; // float
}

class RetFloatResult { 
    public $float; // float
}

class inDouble { 
    public $double; // double
}

class RetDoubleResult { 
    public $double; // double
}

class inSingle { 
    public $float; // float
}

class RetSingleResult { 
    public $float; // float
}

class inInt { 
    public $int; // int
}

class RetIntResult { 
    public $int; // int
}

class inShort { 
    public $short; // short
}

class RetShortResult { 
    public $short; // short
}

class inLong { 
    public $long; // long
}

class RetLongResult { 
    public $long; // long
}

class inObject { 
    public $anyType; // anyType
}

class RetObjectResult { 
    public $anyType; // anyType
}

class inUInt { 
    public $unsignedInt; // unsignedInt
}

class RetUIntResult { 
    public $unsignedInt; // unsignedInt
}

class inUShort { 
    public $unsignedShort; // unsignedShort
}

class RetUShortResult { 
    public $unsignedShort; // unsignedShort
}

class inULong { 
    public $unsignedLong; // unsignedLong
}

class RetULongResult { 
    public $unsignedLong; // unsignedLong
}

class inString { 
    public $string; // string
}

class RetStringResult { 
    public $string; // string
}

class inUri { 
    public $anyURI; // anyURI
}

class RetUriResult { 
    public $anyURI; // anyURI
}

class inDateTime { 
    public $dateTime; // dateTime
}

class RetDateTimeResult { 
    public $dateTime; // dateTime
}

class inDateTimeOffset { 
    public $DateTime; // dateTime
    public $OffsetMinutes; // short
}

class RetDateTimeOffsetResult { 
    public $DateTime; // dateTime
    public $OffsetMinutes; // short
}

class inQName { 
    public $QName; // QName
}

class RetQNameResult { 
    public $QName; // QName
}

// define the class map
$class_map = array(
 "inBool" => "inBool", "RetBoolResult" => "RetBoolResult", "inByte" => "inByte", "RetByteResult" => "RetByteResult", "inSByte" => "inSByte", "RetSByteResult" => "RetSByteResult", "inByteArray" => "inByteArray", "RetByteArrayResult" => "RetByteArrayResult", "inDecimal" => "inDecimal", "RetDecimalResult" => "RetDecimalResult", "inFloat" => "inFloat", "RetFloatResult" => "RetFloatResult", "inDouble" => "inDouble", "RetDoubleResult" => "RetDoubleResult", "inSingle" => "inSingle", "RetSingleResult" => "RetSingleResult", "inInt" => "inInt", "RetIntResult" => "RetIntResult", "inShort" => "inShort", "RetShortResult" => "RetShortResult", "inLong" => "inLong", "RetLongResult" => "RetLongResult", "inObject" => "inObject", "RetObjectResult" => "RetObjectResult", "inUInt" => "inUInt", "RetUIntResult" => "RetUIntResult", "inUShort" => "inUShort", "RetUShortResult" => "RetUShortResult", "inULong" => "inULong", "RetULongResult" => "RetULongResult", "inString" => "inString", "RetStringResult" => "RetStringResult", "inUri" => "inUri", "RetUriResult" => "RetUriResult", "inDateTime" => "inDateTime", "RetDateTimeResult" => "RetDateTimeResult", "inDateTimeOffset" => "inDateTimeOffset", "RetDateTimeOffsetResult" => "RetDateTimeOffsetResult", "inQName" => "inQName", "RetQNameResult" => "RetQNameResult");

// define PHP functions that maps to WSDL operations 
function RetBool($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inBool
    // NOTE: should return an object of type RetBoolResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


function RetByte($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inByte
    // NOTE: should return an object of type RetByteResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret =  $input;
    return $ret;
}


function RetSByte($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inSByte
    // NOTE: should return an object of type RetSByteResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


function RetByteArray($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inByteArray
    // NOTE: should return an object of type RetByteArrayResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}



function RetDecimal($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inDecimal
    // NOTE: should return an object of type RetDecimalResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


function RetFloat($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inFloat
    // NOTE: should return an object of type RetFloatResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


function RetDouble($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inDouble
    // NOTE: should return an object of type RetDoubleResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


function RetSingle($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inSingle
    // NOTE: should return an object of type RetSingleResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


function RetInt($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inInt
    // NOTE: should return an object of type RetIntResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
    
}


function RetShort($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inShort
    // NOTE: should return an object of type RetShortResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


function RetLong($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inLong
    // NOTE: should return an object of type RetLongResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


function RetObject($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inObject
    // NOTE: should return an object of type RetObjectResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


function RetUInt($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inUInt
    // NOTE: should return an object of type RetUIntResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


function RetUShort($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inUShort
    // NOTE: should return an object of type RetUShortResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


function RetULong($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inULong
    // NOTE: should return an object of type RetULongResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


function RetString($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inString
    // NOTE: should return an object of type RetStringResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}



function RetUri($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inUri
    // NOTE: should return an object of type RetUriResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


function RetDateTime($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inDateTime
    // NOTE: should return an object of type RetDateTimeResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


function RetDateTimeOffset($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inDateTimeOffset
    // NOTE: should return an object of type RetDateTimeOffsetResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}



function RetQName($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type inQName
    // NOTE: should return an object of type RetQNameResult

    // Here the $input is the actual simple value, you just set it to the ret value
    $ret = $input;
    return $ret;
}


// define the operations map
$operations = array(
 "RetBool" => "RetBool", "RetByte" => "RetByte", "RetSByte" => "RetSByte", "RetByteArray" => "RetByteArray", "RetDecimal" => "RetDecimal", "RetFloat" => "RetFloat", "RetDouble" => "RetDouble", "RetSingle" => "RetSingle", "RetInt" => "RetInt", "RetShort" => "RetShort", "RetLong" => "RetLong", "RetObject" => "RetObject", "RetUInt" => "RetUInt", "RetUShort" => "RetUShort", "RetULong" => "RetULong", "RetString" => "RetString", "RetUri" => "RetUri", "RetDateTime" => "RetDateTime", "RetDateTimeOffset" => "RetDateTimeOffset", "RetQName" => "RetQName");

// define the operations parameters map
$opParams = array(
 "RetBool" => "MIXED", "RetByte" => "MIXED", "RetSByte" => "MIXED", "RetByteArray" => "MIXED", "RetChar" => "MIXED", "RetDecimal" => "MIXED", "RetFloat" => "MIXED", "RetDouble" => "MIXED", "RetSingle" => "MIXED", "RetInt" => "MIXED", "RetShort" => "MIXED", "RetLong" => "MIXED", "RetObject" => "MIXED", "RetUInt" => "MIXED", "RetUShort" => "MIXED", "RetULong" => "MIXED", "RetString" => "MIXED", "RetGuid" => "MIXED", "RetUri" => "MIXED", "RetDateTime" => "MIXED", "RetDateTimeOffset" => "MIXED", "RetTimeSpan" => "MIXED", "RetQName" => "MIXED");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"BaseDataTypesDocLitB.wsdl",
        "operations" => $operations,
        "opParams" => $opParams,
        "classmap" => $class_map));

// process client requests and reply 
$service->reply();

?>

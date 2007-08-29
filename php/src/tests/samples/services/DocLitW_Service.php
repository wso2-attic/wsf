<?php


function RetArrayString1DFunction($value) 
{
    $str = array();
    
    $str = $value->inArrayString1D->string;
    $i = count($str);
    if ($i> 1)
        $string_arry = $str;
    else
        $string_arry = array($str);

    $val = array("RetArrayString1DResult" =>$string_arry);
    return $val;
}

function RetArrayInt1DFunction($value) 
{
    $str = array();
    
    $str = $value->inArrayInt1D->int;
    $i = count($str);
    if ($i> 1)
        $int_arry = $str;
    else
        $int_arry = array($str);

    $val = array("RetArrayInt1DResult" =>$int_arry);
    return $val;
}

function RetArrayDecimal1DFunction($value) 
{
    $str = array();
    
    $str = $value->inArrayDecimal1D->decimal;
    $i = count($str);
    if ($i> 1)
        $dec_arry = $str;
    else
        $dec_arry = array($str);

    $val = array("RetArrayDecimal1DResult" =>$dec_arry);
    return $val;
}


function RetArrayDateTime1DFunction($value) 
{
    $str = array();
    
    $str = $value->inArrayDateTime1D->dateTime;
    $i = count($str);
    if ($i> 1)
        $date_arry = $str;
    else
        $date_arry = array($str);

    $val = array("RetArrayDateTime1DResult" =>$date_arry);
    return $val;
}

function RetArray1D_SNFunction($value) 
{
    $str = array();
    $str = $value->inArray1D_SN->Person;
    $i = count($str);
    if ($i> 1)
        $sn1D_arry = $str;
    else
        $sn1D_arry = array($str);

    $val = array("RetArray1D_SNResult" =>$sn1D_arry);
    return $val;
}

function RetArrayString2DFunction($value) 
{
    $str = array();
    
    $str = $value->inArrayString2D->ArrayOfstring;
    $i = count($str);
    if ($i> 1)
        $string2_arry = $str;
    else
        $string2_arry = array($str);

    $val = array("RetArrayString2DResult" =>$string2_arry);
    return $val;
}

function RetArrayAnyType1DFunction($value) 
{
    $str = array();
    
    $str = $value->inArrayAnyType1D->anyType;
    $i = count($str);
    if ($i> 1)
        $string2_arry = $str;
    else
        $string2_arry = array($str);

    $val = array("RetArrayAnyType1DResult" =>$string2_arry);
    return $val;
}

function RetStructS1Function($value) 
{
    $str = array();
    
    $str = $value->inStructS1;
    $i = count($str);
    if ($i > 0)
        $string2_arry = $str;
    else
        $string2_arry = array($str);

    $val = array("RetStructS1Result" =>$string2_arry);
    return $val;
}

function RetStructSNFunction($value) 
{
    $str = array();
    
    $str = $value->inStructSN;
    $i = count($str);
    if ($i> 0)
        $string2_arry = $str;
    else
        $string2_arry = array($str);

    $val = array("RetStructSNResult" =>$string2_arry);
    return $val;
}

function RetStructSNSAFunction($value) 
{
    $str = array();
    
    $str = $value->inStructSNSA;
    $i = count($str);
    if ($i> 0)
        $string2_arry = $str;
    else
        $string2_arry = array($str);

    $val = array("RetStructSNSAResult" =>$string2_arry);
    return $val;
}

function RetStructSNSASFunction($value) 
{
    $str = array();
    
    $str = $value->inStructSNSAS;
    $i = count($str);
    if ($i> 0)
        $string2_arry = $str;
    else
        $string2_arry = array($str);

    $val = array("RetStructSNSASResult" =>$string2_arry);
    return $val;
}

function RetEnumStringFunction($value) 
{
    $str = array();
    
    $str = $value->inEnumString;
    $i = count($str);
    if ($i> 0)
        $string2_arry = $str;
    else
        $string2_arry = array($str);

    $val = array("RetEnumStringResult" =>$string2_arry);
    return $val;
}

function RetEnumIntFunction($value) 
{
    $str = $value->inEnumInt;
    $i = count($str);
    if ($i> 0)
        $string2_arry = $str;
    else
        $string2_arry = array($str);

    $val = array("RetEnumIntResult" =>$string2_arry);
    return $val;
}

function RetDerivedClassFunction($value) 
{
    $str = $value->inDerivedClass;
    $i = count($str);
    if ($i> 0)
        $string2_arry = $str;
    else
        $string2_arry = array($str);

    $val = array("RetDerivedClassResult" =>$string2_arry);
    return $val;
}





$operations = array("RetArrayString1D" => "RetArrayString1DFunction",
                    "RetArrayInt1D" => "RetArrayInt1DFunction",
                    "RetArrayDecimal1D" => "RetArrayDecimal1DFunction",
                    "RetArrayDateTime1D" => "RetArrayDateTime1DFunction",
                    "RetArrayString2D" => "RetArrayString2DFunction",
                    "RetArray1D_SN" => "RetArray1D_SNFunction",
                    "RetArrayAnyType1D" => "RetArrayAnyType1DFunction",
                    "RetStructS1" => "RetStructS1Function",
                    "RetStructSN" => "RetStructSNFunction",
                    "RetStructSNSA" => "RetStructSNSAFunction",
                    "RetStructSNSAS" => "RetStructSNSASFunction",
                    "RetEnumString" => "RetEnumStringFunction",
                    "RetEnumInt" => "RetEnumIntFunction",
                    "RetDerivedClass" => "RetDerivedClassFunction");

$opParams = array("RetArrayString1DFunction" => "MIXED",
                  "RetArrayInt1DFunction" => "MIXED",
                  "RetArrayDecimal1DFunction" => "MIXED",
                  "RetArrayDateTime1DFunction" => "MIXED",
                  "RetArrayString2DFunction" => "MIXED",
                  "RetArray1D_SNFunction" => "MIXED",
                  "RetArrayAnyType1D" => "MIXED",
                  "RetStructS1Function" => "MIXED",
                  "RetStructSNFunction" => "MIXED",
                  "RetStructSNSAFunction" => "MIXED",
                  "RetStructSNSASFunction" => "MIXED",
                  "RetEnumStringFunction" => "MIXED",
                  "RetEnumIntFunction" => "MIXED",
                  "RetDerivedClassFunction" => "MIXED");

$svr = new WSService(array("wsdl" =>"misc_files/ComplexDataTypesDocLitW.wsdl", "operations" => $operations, "opParams" => $opParams));
        
$svr->reply();

?>



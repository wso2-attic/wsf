<?php

/**
 * @return array of string $return
 */
function retArray() {
    $a [] = "test1";
    $a [] = "test2";

    return array("return" => $a);
}


$operations = array("retArray" => "retArray");
$opParams = array("retArray" => "MIXED");


$svr = new WSService(array("operations" => $operations,
                           "opParams" => $opParams));

$svr->reply();
?>

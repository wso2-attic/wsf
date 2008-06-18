--TEST--
WSDL Generation - return type is an array, no classmapped service
--FILE--
<?php


$client = new WSClient(array ("wsdl" => "http://localhost/services/wsdl_generation/return_type_array.php?wsdl",
                              "to" => "http://localhost/services/wsdl_generation/return_type_array.php"));


$proxy = $client->getProxy();
$response = $proxy->retArray();

print_r($response);
?>
--EXPECT--
Array
(
    [return] => Array
        (
            [0] => test1
            [1] => test2
        )

)


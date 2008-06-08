--TEST--
A client calling with custom headers defined in wsdl, echoing headers
--FILE--
<?php

// PHP classes corresponding to the data types in defined in WSDL

class Header1 {
    public $string; // string
    public $int; // int
}

class Header2 {
    public $int; // int
    public $string; // string
}

// define the class map
$class_map = array(
    "Header1" => "Header1",
    "Header2" => "Header2");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/header_service.php?wsdl",
        "to" => "http://localhost/services/wsdl_mode/header_service.php",
        "classmap" => $class_map));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    //TODO: fill $input with (data type: string) data to match your business logic
    $input = "test";

    $header_in0 = new Header1();
    // TODO: fill in the class fields of $header_in0 header to match your business logic
    $header_in0->string = "test1";
    $header_in0->int = 5;

    $header_in1 = new Header2();
    // TODO: fill in the class fields of $header_in1 header to match your business logic
    $header_in1->string = "test2";
    $header_in1->int = 8;

    // call the operation
    $response = $proxy->echoString($input, $header_in0, $header_in1, &$header_out0, &$header_out1);
    //TODO: Implement business logic to consume $response, which is of type string
    print_r($response);
    echo "\n";

    // TODO: Implement business logic to consume $header_out0, which is of type Header1
    print_r($header_out0);

    // TODO: Implement business logic to consume $header_out1, which is of type Header2
    print_r($header_out1);

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
test
Header1 Object
(
    [string] => test1
    [int] => 5
)
Header2 Object
(
    [int] => 8
    [string] => test2
)

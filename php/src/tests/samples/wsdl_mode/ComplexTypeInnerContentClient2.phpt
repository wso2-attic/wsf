--TEST--
ComplexType Inner Content 2
--FILE--
<?php

// PHP classes corresponding to the data types in defined in WSDL

class myDemo {

    // You may set only one from the following set
    // ---------------Start Choice----------------
    public $demo1; // int
    public $demo2; // string
    // ----------------End Choice---------------

    public $demo3; // int
    public $demo4; // string
    public $demo5; // string
}

// define the class map
$class_map = array(
 "anyType" => "anyType", "myDemo" => "myDemo");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/ComplexTypeInnerContentService.php?wsdl",
        "classmap" => $class_map,
                            ));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    $input = new myDemo();
    //TODO: fill in the class fields of $input to match your business logic

    //$input->demo1 = 3;
    $input->demo2 = "test";

    $input->demo3 = 4;
    $input->demo4 = "test 4 string";
    $input->demo5 = "test 5 string";

    // call the operation
    $response = $proxy->myDemo($input);
    //TODO: Implement business logic to consume $response, which is of type string


    echo $response."\n";

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
myDemo Object
(
    [demo1] => 
    [demo2] => test
    [demo3] => 4
    [demo4] => test 4 string
    [demo5] => test 5 string
)

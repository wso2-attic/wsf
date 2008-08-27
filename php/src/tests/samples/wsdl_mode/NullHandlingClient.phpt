--TEST--
A client to test null in different levels
--FILE--
<?php

// PHP classes corresponding to the data types in defined in WSDL

class myDemo_inner_nil {

    /**
     * @var int
     */
    public $demo1;

    /**
     * @var string
     */
    public $demo2;

}

// define the class map
$class_map = array(
    "myDemo_inner_nil" => "myDemo_inner_nil");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/NullHandlingService.php?wsdl",
        "to" =>"http://localhost/services/wsdl_mode/NullHandlingService.php",
        "classmap" => $class_map));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    //-----------------------------------------------------
    // setting the root element of the sequence null;
    //-----------------------------------------------------
    $input = NULL;
    $response = $proxy->myDemo_inner_nil($input);
    print_r($response);

    //-----------------------------------------------------
    // setting the inner element of the sequence to null;
    //-----------------------------------------------------
    $input = new myDemo_inner_nil();
    //TODO: fill in the class fields of $input to match your business logic
    $input->demo1 = NULL;
    $input->demo2 = NULL;

    // call the operation
    $response = $proxy->myDemo_inner_nil($input);
    //TODO: Implement business logic to consume $response, which is of type string
    print_r($response);


    //TODO: fill $input with (data type: string) data to match your business logic

    //-----------------------------------------------------
    // setting the root element of the root to null;
    //-----------------------------------------------------
    $input = NULL;
    // call the operation
    $response = $proxy->myDemo_root_nil($input);
    //TODO: Implement business logic to consume $response, which is of type string
    print_r($response);

    //-----------------------------------------------------
    // setting the inner element of the sequence to 0;
    //-----------------------------------------------------
    $input = new myDemo_inner_nil();
    //TODO: fill in the class fields of $input to match your business logic
    $input->demo1 = 0;
    $input->demo2 = "";

    // call the operation
    $response = $proxy->myDemo_inner_nil($input);
    //TODO: Implement business logic to consume $response, which is of type string
    print_r($response);


    //TODO: fill $input with (data type: string) data to match your business logic

    //-----------------------------------------------------
    // setting the root element of the root to empty;
    //-----------------------------------------------------
    $input = "";
    // call the operation
    $response = $proxy->myDemo_root_nil($input);
    //TODO: Implement business logic to consume $response, which is of type string
    print_r($response);

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
$input->demo1 === NULL
$input->demo1 === NULL
$input === NULL
$input->demo1 == NULL
$input == NULL

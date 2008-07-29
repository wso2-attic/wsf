--TEST--
Complex content extension, testing the use of xsi:type based serialization and deserialization from outer element
--FILE--
<?php

// PHP classes corresponding to the data types in defined in WSDL

class parentType {

    /**
     * @var int
     */
    public $demo3;

    /**
     * @var string
     */
    public $demo4;

}

class childType extends parentType {

    /**
     * @var int
     */
    public $demo1;

    /**
     * @var string
     */
    public $demo2;

}

class nextLevelChildType extends childType {

    /**
     * @var int
     */
    public $demo5;

    /**
     * @var string
     */
    public $demo6;

}

class anotherChildType extends parentType {

    /**
     * @var int
     */
    public $demo5;

    /**
     * @var string
     */
    public $demo6;

}

class myDemo {

    /**
     * @var int
     */
    public $demo3;

    /**
     * @var string
     */
    public $demo4;

}

// define the class map
$class_map = array(
    "parentType" => "parentType",
    "childType" => "childType",
    "nextLevelChildType" => "nextLevelChildType",
    "anotherChildType" => "anotherChildType",
    "myDemo" => "myDemo");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/ComplexTypeComplexExtensionParentTypeService.php?wsdl",
        "to" => "http://localhost/services/wsdl_mode/ComplexTypeComplexExtensionParentTypeService.php",
        "classmap" => $class_map));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    $input = new childType();
    /**
     * Here you can replace myDemo with a following class(es)
     * childType
     * nextLevelChildType
     * anotherChildType
     */
    //TODO: fill in the class fields of $input to match your business logic
    $input->demo1 = 5;
    $input->demo2 = "test2";
    $input->demo3 = 6;
    $input->demo4 = "test4";

    // call the operation
    $response = $proxy->myDemo($input);
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
childType Object
(
    [demo1] => 5
    [demo2] => test2
    [demo3] => 6
    [demo4] => test4
)


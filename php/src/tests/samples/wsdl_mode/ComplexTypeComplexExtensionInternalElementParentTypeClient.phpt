--TEST--
Complex content extension, testing the use of xsi:type based serialization and deserialization from internal element
--FILE--
<?php

// PHP classes corresponding to the data types in defined in WSDL

class myDemo {

    /**
     * @var (object)parentType
     *    Or one of following derived class(es)
     *       childType
     *       nextLevelChildType
     *       anotherChildType
     */
    public $internal;

}

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

// define the class map
$class_map = array(
    "myDemo" => "myDemo",
    "parentType" => "parentType",
    "childType" => "childType",
    "nextLevelChildType" => "nextLevelChildType",
    "anotherChildType" => "anotherChildType");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/ComplexTypeComplexExtensionInternalElementParentTypeService.php?wsdl",
        "to" =>"http://localhost/services/wsdl_mode/ComplexTypeComplexExtensionInternalElementParentTypeService.php",
        "classmap" => $class_map));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    $input = new myDemo();
    //TODO: fill in the class fields of $input to match your business logic


    $child = new nextLevelChildType();

    //TODO: fill in the class fields of $input to match your business logic
    $child->demo1 = 2;
    $child->demo2 = "test2";
    $child->demo3 = 23;
    $child->demo4 = "test4";
    $child->demo5 = 4;
    $child->demo6 = "test6";

    $input->internal = $child;

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
myDemo Object
(
    [internal] => nextLevelChildType Object
        (
            [demo5] => 4
            [demo6] => test6
            [demo1] => 2
            [demo2] => test2
            [demo3] => 23
            [demo4] => test4
        )

)


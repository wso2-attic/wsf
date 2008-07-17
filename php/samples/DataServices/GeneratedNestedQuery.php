<?php

// PHP classes corresponding to the data types in defined in WSDL

class customerOrders {
}

class Orders {
    public $Order; // array[0, unbounded] of (object)OrderType
}

class OrderType {
    public $Order_number; // long
    public $Order_date; // dateTime
    public $Status; // string
    public $Customers; // (object)CustomersType
    public $OrderId; // long
}

class CustomersType {
    public $Customer; // array[0, unbounded] of (object)CustomerType
}

class CustomerType {
    public $Name; // string
}

class customerName {
    public $customerNumber; // int
}

class Customers {
    public $Customer; // array[0, unbounded] of (object)CustomerType
}

// define the class map
$class_map = array(
    "customerOrders" => "customerOrders",
    "Orders" => "Orders",
    "OrderType" => "OrderType",
    "CustomersType" => "CustomersType",
    "CustomerType" => "CustomerType",
    "customerName" => "customerName",
    "Customers" => "Customers");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/samples/DataServices/NestedQueryService.php?wsdl",
        "classmap" => $class_map));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    $input = new customerOrders();
    //TODO: fill in the class fields of $input to match your business logic

    // call the operation
    $response = $proxy->customerOrders($input);
    //TODO: Implement business logic to consume $response, which is of type Orders
    
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

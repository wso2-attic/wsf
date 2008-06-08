--TEST--
A client calling a chain service - within matrix add it calls the simple add service
--FILE--
<?php

// PHP classes corresponding to the data types in defined in WSDL

class matrixAdd {
    public $param0; // (object)Matrix
    public $param1; // (object)Matrix
}

class Matrix {
    public $rows; // array[0, unbounded] of (object)MatrixRow
}

class MatrixRow {
    public $columns; // array[0, unbounded] of int
}

class matrixAddResponse {
    public $return; // (object)Matrix
}

// define the class map
$class_map = array(
    "matrixAdd" => "matrixAdd",
    "Matrix" => "Matrix",
    "MatrixRow" => "MatrixRow",
    "matrixAddResponse" => "matrixAddResponse");

try {

    // create client in WSDL mode
    $client = new WSClient(array ("wsdl" =>"http://localhost/services/wsdl_mode/matrix_service.php?wsdl",
        "to" =>"http://localhost:80/services/wsdl_mode/matrix_service.php",
        "classmap" => $class_map));

    // get proxy object reference form client 
    $proxy = $client->getProxy();

    // create input object and set values
    $input = new matrixAdd();
    //TODO: fill in the class fields of $input to match your business logic

    $row1 = new MatrixRow();
    $row1->columns = array(1, 2, 3);
    $row2 = new MatrixRow();
    $row2->columns = array(4, 5, 6);
    $row3 = new MatrixRow();
    $row3->columns = array(7, 8, 9);

    $matrix0 = new Matrix();
    $matrix0->rows = array($row1, $row2, $row3);
    $input->param0 = $matrix0;

    $matrix1 = new Matrix();
    $matrix1->rows = array($row1, $row2, $row3);
    $input->param1 = $matrix1;

    // call the operation
    $response = $proxy->matrixAdd($input);
    //TODO: Implement business logic to consume $response, which is of type matrixAddResponse

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
matrixAddResponse Object
(
    [return] => Matrix Object
        (
            [rows] => Array
                (
                    [0] => MatrixRow Object
                        (
                            [columns] => Array
                                (
                                    [0] => 2
                                    [1] => 4
                                    [2] => 6
                                )

                        )

                    [1] => MatrixRow Object
                        (
                            [columns] => Array
                                (
                                    [0] => 8
                                    [1] => 10
                                    [2] => 12
                                )

                        )

                    [2] => MatrixRow Object
                        (
                            [columns] => Array
                                (
                                    [0] => 14
                                    [1] => 16
                                    [2] => 18
                                )

                        )

                )

        )

)


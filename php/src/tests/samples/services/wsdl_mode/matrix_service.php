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

// define PHP functions that maps to WSDL operations 
function matrixAdd($input) {
    // TODO: fill in the business logic
    // NOTE: $input is of type matrixAdd
    // NOTE: should return an object of type matrixAddResponse

    include_once("simple_client.php");

    $matrix0 = $input->param0;
    $matrix1 = $input->param1;

    $matrix2 = new Matrix();
    $matrix2->rows = array();

    if(count($matrix0->rows) == count($matrix1->rows)) {
        for($i = 0; $i < count($matrix0->rows); $i ++ ) {
            $row0 = $matrix0->rows[$i];
            $row1 = $matrix1->rows[$i];

            $row2 = new MatrixRow();
            $matrix2->rows[] = $row2;
            $row2->columns = array();

            if(count($row0->columns) == count($row1->columns)) {
                for($j = 0; $j< count($row0->columns); $j ++ ) {
                    $col0 = $row0->columns[$j];
                    $col1 = $row1->columns[$j];
                    
                    $simpleadd = new SimpleAdd();
                    $simpleadd->param0 = $col0;
                    $simpleadd->param1 = $col1;

                    $res = $proxy->simpleAdd($simpleadd);

                    $col2 = $res->return;
                    
                    $row2->columns[] = $col2;
                }
            }
        }
    }

    /*$row1 = new MatrixRow();
    $row1->columns = array(1, 2, 3);
    $row2 = new MatrixRow();
    $row2->columns = array(4, 5, 6);
    $row3 = new MatrixRow();
    $row3->columns = array(7, 8, 9);

    $matrix2 = new Matrix();
    $matrix2 = array($row1, $row2, $row3);
    */
    $res = new matrixAddResponse();
    $res->return = $matrix2;
    return $res;
}


// define the operations map
$operations = array(
    "matrixAdd" => "matrixAdd");

// define the actions => operations map
$actions = array(
    "urn:matrixAdd" => "matrixAdd");

// create service in WSDL mode
$service = new WSService(array ("wsdl" =>"matrix_adder.wsdl",
        "actions" => $actions,
        "classmap" => $class_map,
        "operations" => $operations));

// process client requests and reply 
$service->reply();

?>

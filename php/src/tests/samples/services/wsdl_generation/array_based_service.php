<?php
//array based service - targetted data services

function matrix_add($matrix_add) {
}

function simple_add($simple_add) {
}

class MatrixAdd {
    public $matrix1;
    public $matrix2;
}

class MatrixAddResponse {
    public $matrix;
}

class Matrix {
    public $rows;
}

class MatrixRow {
    public $cols;
}

class SimpleAdd {
    public $x;
    public $y;
}

class SimpleAddResponse {
    public $return;
}


$opParams = array("matrix_add" => "MIXED", "simple_add" => "MIXED");
$operations = array("matrix_add" => "matrix_add", "simple_add" => "simple_add");
$classmap = array("MatrixAdd" => "MatrixAdd",
                  "MatrixAddResponse" => "MatrixAddResponse",
                  "SimpleAdd" => "SimpleAdd",
                  "SimpleAddResponse" => "SimpleAddResponse",
                  "Matrix" => "Matrix",
                  "MatrixRow" => "MatrixRow");

/**
 * this is how you will provide annotations as arrays
 */

// annotations for input and output elements
$matrix_add_element = array("name" => "matrix_add",
                            "namespace" => "http://labs.wso2.org/matrix_add",
                            "type" => "MatrixAdd");

$matrix_add_response_element = array("name" => "matrix_add_response",
                            "namespace" => "http://labs.wso2.org/matrix_add",
                            "type" => "MatrixAddResponse");

$simple_add_element = array("name" => "simple_add",
                            "namespace" => "http://labs.wso2.org/simple_add",
                            "type" => "simpleAdd");

$simple_add_response_element = array("name" => "simple_add_response",
                            "namespace" => "http://labs.wso2.org/simple_add",
                            "type" => "simpleAddResponse");

// types
/* matrix add type */
$matrix1_element = array("name" => "matrix1",
                        "type"=> "Matrix");
$matrix2_element = array("name" => "matrix2",
                        "type"=> "Matrix");
$matrix_add_type = array(
                         "name" => "MatrixAdd",
                         "sequence" => array($matrix1_element, $matrix2_element),
                         "namespace" => "http://labs.wso2.org/matrix_add/types");


$return_element = array("name" => "return",
                        "type"=> "Matrix");
$matrix_add_response_type = array(
                         "name" => "MatrixAddResponse",
                         "sequence" => array($return_element),
                         "namespace" => "http://labs.wso2.org/matrix_add/types");

$x_element = array("name" => "x",
                    "type" => "xsd:int");
$y_element = array("name" => "y",
                    "type" => "xsd:int");
$simple_add_type = array(
                    "name" => "simpleAdd",
                    "sequence" => array($x_element, $y_element),
                    "namespace" => "http://labs.wso2.org/simple_add/types");

$return_element = array("name" => "return",
                        "type" => "xsd:int");
$simple_add_response_type = array(
                    "name" => "simpleAddResponse",
                    "sequence" => array($return_element),
                    "namespace" => "http://labs.wso2.org/simple_add/types");


/* matrix type */
$rows_element = array("name" => "rows",
                      "type" => "MatrixRow",
                      "maxOccurs" => "unbounded");

$matrix_type = array("name" => "Matrix",
                     "sequence" => array($rows_element),
                     "namespace" => "http://labs.wso2.org/matrix_add/types");

/* matrix row type */
$cols_element = array("name" => "cols",
                     "type" => "xsd:int",
                     "maxOccurs" => "unbounded");

$matrix_rows_type = array("name" => "MatrixRow",
                          "sequence" => array($cols_element),
                          "namespace" => "http://labs.wso2.org/matrix_add/types");

$annotations = array("matrix_add" => array (
                         "input" => $matrix_add_element,
                         "output" => $matrix_add_response_element),
                     "simple_add" => array (
                         "input" => $simple_add_element,
                         "output" => $simple_add_response_element),
                     "types" => array($matrix_add_type, $matrix_type, $matrix_rows_type,
                                    $matrix_add_response_type, $simple_add_type, $simple_add_response_type));

$service = new WSService(array("opParams" => $opParams,
                            "annotations" => $annotations,
                            "classmap" => $classmap,
                            "operations" => $operations));

$service->reply();

?>

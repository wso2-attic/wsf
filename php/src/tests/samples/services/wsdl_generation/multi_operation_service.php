<?php
//multiple operations - simple_add and matrix_add
/**
 * operation matrix_add
 * @param object MatrixAdd $matrix_add
 * @return object MatrixAddResponse $matrix_add_response
 */
function matrix_add($matrix_add) {
}

/**
 * @namespace http://labs.wso2.org/tests/matrixadd
 */
class MatrixAdd {
    /**
     * @var object Matrix $matrix1
     */
    public $matrix1;
    /**
     * @var object Matrix $matrix2
     */
    public $matrix2;
}

/**
 * @namespace http://labs.wso2.org/tests/matrixadd/types
 */
class MatrixAddResponse {
    /**
     * @var object Matrix $matrix
     */
    public $matrix;
}

/**
 * @namespace http://labs.wso2.org/tests/matrixadd/types
 */
class Matrix {
    /**
     * @var array of object MatrixRow $rows;
     */
    public $rows;
}

/**
 * @namespace http://labs.wso2.org/tests/matrixadd/types
 */
class MatrixRow {
    /**
     * @var array of int $cols
     * maps to xs:int
     */
    public $cols;
}

/**
 * simple_add
 * @param object simpleAdd $simple_add
 * @return object simpleAddResponse $simple_add_response
 */
function simple_add($input) {
    $x = $input->x;
    $y = $input->y;

    $ret = new simpleAddResponse();
    
    $ret->return = $x + $y;
    return $ret;
}

/**
 * @namespace http://labs.wso2.org/tests/simpleadd/types
 */
class SimpleAdd {
    /**
     * @var int $x
     * xs:int
     */
     public $x;

    /**
     * @var int $y
     * xs:int
     */
     public $y;
}

/**
 * @namespace http://labs.wso2.org/tests/simpleadd/types
 */
class SimpleAddResponse {
    /**
     * @var int $return
     * xs:int
     */
     public $return;

}


$opParams = array("matrix_add" => "MIXED", "simple_add" => "MIXED");
$operations = array("matrix_add" => "matrix_add", "simple_add" => "simple_add");
$classmap = array("MatrixAdd" => "MatrixAdd",
                  "Matrix" => "Matrix",
                  "MatrixRow" => "MatrixRow");



$service = new WSService(array("opParams" => $opParams,
                            "classmap" => $classmap,
                            "operations" => $operations));

$service->reply();
?>

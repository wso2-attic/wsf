<?php

/**
 * @param object myRequest $myRequest
 */
function my_op_function() {
    $ret = new myResponse();
    return $ret;
}

class myResponse {
   
    /**
     * @var string $return
     */
    public $return;
}

class myRequest {
   
    /**
     * @var string $input
     */
    public $input;
}

$operations = array("myOp" => "my_op_function");
$actions = array("http://action/map/test" => "myOp");

$classmap = array("myResponse", "myResponse");

$svr = new WSService(array("operations" => $operations,
                           "classmap" => $classmap,
                           "actions" => $actions));

$svr->reply();
?>

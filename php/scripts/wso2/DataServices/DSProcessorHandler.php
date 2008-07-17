<?php

require_once("wso2/DataServices/DSQueryProcessor.php");

/* the callback handler for the WSService service operations */
class DSProcessorHandler {
    private $args;
    /**
     * @param array $args, argument passed by the user
     */
    public function __construct($args) {
        $this->args = $args;
    }

    /**
     * @param string $op_name, service opertion name
     * @param array $op_args, request message
     * @param returns the response
     */
    public function __call($op_name, $op_args) {
        
        // extracting out the request message
        $req_msg = NULL;
        if(array_key_exists(0, $op_args)) {
            $req_msg = $op_args[0];
        }
        if($req_msg == NULL) {
            DSUtils::error_log(__FILE__, __LINE__, 
                "Configs are missing in the DataService constructor");
            throw new WSFault("Sender", "Failed in reading the request message");
        }
        $req_msg_str = $req_msg->str;

        // extracting out the config and operation from theuser args
        $config = $this->args[DS_CONFIG];
        $operations = $this->args[DS_OPERATIONS];

        // extracting out the query information on current operation
        if(array_key_exists($op_name, $operations)) {
            $operation_query = $operations[$op_name];
        }
        else {
            DSUtils::error_log(__FILE__, __LINE__, 
                "current operation $op_name not in the user provided operations array");
            throw new WSFault("Sender", "Operation $op_name not found");
        }

        // create the database executor
        $dbe = new DSDBExecutor($config);

        // process the incomming message and operation query
        $ds_proc = new DSQueryProcessor($dbe, $operation_query);

        /* call the DSQueryProccessor with the configrations + incomming message*/
        $response = $ds_proc->process_inmessage($req_msg_str, $operation_query, $dbe);

        return $response;
    }
}
?>

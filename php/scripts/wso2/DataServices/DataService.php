<?php
/*
 * Copyright 2005,2006 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

require_once("wso2/DataServices/DSProcessorHandler.php");

class DataService extends WSService
{
    /**
     * @param array $args this should have entries for
     *      "config" and "operations" + other WSService constrctor arguments
     */
    public function __construct($args)
    {
        // validating the user args
        if(!array_key_exists(DS_CONFIG, $args)) {
            DSUtils::error_log(__FILE__, __LINE__, 
                "Configs are missing in the DataService constructor");
        }
        if(!array_key_exists(DS_OPERATIONS, $args)) {
            DSUtils::error_log(__FILE__, __LINE__, 
                "Operations are missing in the DataService constructor");
        }

        // deriving operations for WSService constructor
        $wsservice_operatoins = array();

        // build the operation array for the WSService constructor
        $args_ops = $args[DS_OPERATIONS];
        foreach($args_ops as $key => $value){
            $wsservice_operations[$key] = $key;
        }

        // building the WSService construtor arguments
        $wsservice_args = array(DS_CLASSES=> array(DS_PROCESSOR_HANDLER => 
            array(DS_OPERATIONS=> $wsservice_operations, DS_ARGS=>array($args))));

        /* put all the arguments except the operations and config
           as arguments for the WSConstructor */
        foreach($args as $args_key => $args_value){
            if($args_key != DS_OPERATIONS && $args_key != DS_CONFIG){
                $wsservice_args[$args_key]=$args_value;
            }
        }

        $args_config = $args[DS_CONFIG];
        
        $wsservice_args[DS_ANNOTATIONS] = $this->generate_annotations($args_ops, $args_config);

        // call the parent constructor
        parent::__construct($wsservice_args);
    }
    

    /**
     * reuturn the annotation which generate the WSDL
     *
     * @param array $op_args, user passed arguments for DataService 
     *  "operations" option
     * @param array $config, some db configuration stuff
     * @return array $annotations
     */
    public function generate_annotations($op_args, $config_args) {
        require_once("DSWSDLGenerator.php");
        
        $annotations = NULL;
    	if(array_key_exists(DS_QUERY_STRING, $_SERVER) && 
                ($_SERVER[DS_QUERY_STRING] == "wsdl" || $_SERVER[DS_QUERY_STRING] == "wsdl2")) {
            $wsdl_generator = new DSWSDLGenerator();
            $annotations = $wsdl_generator->generate_wsdl($op_args, $config_args);
            
    	}
        return $annotations;
    }
}
?>

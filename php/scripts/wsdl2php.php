<?php
/*
 * Copyright (c) 2005-2010 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

require_once ('wsf_wsdl.php');
require_once ('wsdl2php/wsf_utils.php');
require_once ('wsdl2php/wsf_class_writer.php');
require_once ('wsdl2php/wsf_help.php');

// array to keep track of classes that are already written 
global $written_classes;

// array to hold information on operations to help generate demo code 
global $operations;

// array to hold information on actions..
global $actions;

global $headers;

// start of main logic

$args = array();

// check if it is a web request or a command line request
if (isset($_GET['input'])) {
    // it is a HTTP GET request
    $args['input'] = array();
    $args['input'][1] = $_GET['input'];
    $args['s'] = isset($_GET['s']);
} else {
    //process command line arguments
    $args = wsf_arguments($argv);
}

if (array_key_exists('h', $args) && $args['h']) { // -h used for help; print help
	wsf_wsdl2php_print_help();
	return;
}

// pick the WSDL form command line arguments
$wsdl_location = $args['input'][1];

if (array_key_exists('d', $args) && $args['d']) { // -d used for debug; print sig model
	wsf_wsdl2sig($wsdl_location);
	return;
}

// call function to convert from WSDL to PHP
$class_code = wsf_wsdl2php($wsdl_location);

echo "<?php\n\n";

$class_map = NULL;
if($class_code) {

    echo "// PHP classes corresponding to the data types in defined in WSDL\n\n";
    echo $class_code;

    echo "// define the class map\n";
    echo "\$class_map = array(";
    $class_map = "";
    foreach ($written_classes as $class_name => $value) {
        if($class_name != WSF_XSD_ANYTYPE) {
            $class_map = $class_map . "\n    \"" . $class_name . "\" => \"" . $class_name . "\",";
        }
    }

    // print_cass_map only the classmap is present
    $class_map = substr_replace($class_map, "", -1);
    echo $class_map;
    echo ");\n\n";
}

if (array_key_exists('s', $args) && $args['s']) {
	// generate server side code
	echo "// define PHP functions that maps to WSDL operations \n";
	foreach ($operations as $op_name => $value) {
		//echo "function ".$op_name . "(\$input) {\n    // TODO: fill in the business logic\n}\n\n";
		echo $value[WSF_SERVICE] . "\n";
	}

	echo "// define the operations map\n";
	echo "\$operations = array(";
	$operations_map = "";
	foreach ($operations as $op_name => $value) {
		$operations_map = $operations_map . "\n    \"" . $op_name . "\" => \"" . $op_name . "\",";
	}
	
	$operations_map = substr_replace($operations_map, "", -1);
	echo $operations_map;
	echo ");\n\n";

    // this is not essential right now..
	/*echo "// define the operations parameters map\n";
	echo "\$opParams = array(\n";
	$op_params_map = "";
	foreach ($operations as $op_name => $value) {
		$op_params_map = $op_params_map . " \"" . $op_name . "\" => \"" . "MIXED" . "\",";
	}
	$op_params_map = substr_replace($op_params_map, "", -1);
	echo $op_params_map;
	echo ");\n\n"; */

    if($actions != NULL)
    {
     
        echo "// define the actions => operations map\n";
        echo "\$actions = array(";
        $actions_map_str = "";
        foreach ($actions as $action => $op_name) {
            $actions_map_str = $actions_map_str . "\n    \"" . $action . "\" => \"" . $op_name."\",";
        }
        $actions_map_str = substr_replace($actions_map_str, "", -1);
        echo $actions_map_str;
        echo ");\n\n";   
    }
	
	
	echo "// create service in WSDL mode\n";
	echo "\$service = new WSService(array (\"wsdl\" =>\"$wsdl_location\",\n";
	//echo "        \"opParams\" => \$opParams,\n";
    if($actions != NULL) {
        echo 
         "        \"actions\" => \$actions,\n";
    }
    if($class_map != NULL) {
	    echo 
         "        \"classmap\" => \$class_map,\n";
    }
	echo "        \"operations\" => \$operations));\n\n";
     
    echo "// process client requests and reply \n";
	echo "\$service->reply();\n\n";
	
	
} else {
	// generate client side code
	echo "try {\n\n";
	echo "    // create client in WSDL mode\n";
	echo "    \$client = new WSClient(array (\"wsdl\" =>\"$wsdl_location\",\n";
    if($class_map != NULL) {
	    echo 
         "        \"classmap\" => \$class_map));\n\n";
    }
    else {
        echo "                            ));\n\n";
    }
	
	echo "    // get proxy object reference form client \n";
	echo "    \$proxy = \$client->getProxy();\n\n";
	
	echo "    // create input object and set values\n";
	
	foreach ($operations as $op_name => $value) {
		echo $value[WSF_CLIENT] . "\n";
	}
	
	echo "} catch (Exception \$e) {\n";
	echo "    // in case of an error, process the fault\n";
	echo "    if (\$e instanceof WSFault) {\n";
	echo "        printf(\"Soap Fault: %s\\n\", \$e->Reason);\n";
	echo "    } else {\n";
	echo "        printf(\"Message = %s\\n\", \$e->getMessage());\n";
	echo "    }\n";
	echo "}\n";
}

echo "?>\n";
?>

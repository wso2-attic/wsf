<?php
require_once ('wsf_wsdl.php');

// array to keep track of classes that are already written 
$written_classes = array ();

// array to hold information on operations to help generate demo code 
$operations = array ();

/**
 * Function to write sub classes. Uses echo function to write the class to output 
 * $nodes array of nodes corresponding to the classes to be written
 * returns nothing
 */
function wsf_write_sub_classes($nodes) {
	global $written_classes;
	foreach ($nodes as $node) {
		if ($node) {

			if ($node->hasAttributes()) {
				// Wrapper element found
				$attrs = $node->attributes;
				$type_name = $attrs->getNamedItem(WSF_TYPE)->value;

				// array to hold child elements corresponding to sub classes
				$child_array = array ();

				// check if the class was already written 
				if ($written_classes[$type_name] == true)
					continue;
				echo "class " . $type_name . " { \n";
				$written_classes[$type_name] = true;

				$param_child_list = $node->childNodes;
				foreach ($param_child_list as $param_child) {
					$param_attr = $param_child->attributes;
					$param_name = $param_attr->getNamedItem(WSF_NAME)->value;
					$param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
					// write public members of the class 
					echo "    public $" . $param_name . "; //" . $param_type . "\n";
					// if it is not s simple type, we have to keep track of it to write a corresponding class
					if ($param_attr->getNamedItem(WSF_WSDL_SIMPLE)->value == 'no')
						$child_array[] = $param_child;
				}
				echo "}\n\n";
				// done writing the current class, now go and write the sub classes
				wsf_write_sub_classes($child_array);
			}
			// TODO: How to generate code if we do not have a wrapper element?
			// TODO: What about arrays?
		}
	}
}

/**
 * Function to write classes. Does the WSDL to PHP conversion using a 'sig model''. Uses echo function to write the class to output.  
 * $wsdl_location location of the WSDL
 * returns nothing
 */
function wsf_wsdl2php($wsdl_location) {

	require_once ('dynamic_invocation/wsf_wsdl_consts.php');
	require_once ('dynamic_invocation/wsf_wsdl_util.php');

	global $written_classes;
	global $operations;

	$wsdl_dom = new DomDocument();
	$sig_model_dom = new DOMDocument();

	$xslt_location = "./xslt/";

	$sig_model_dom->preserveWhiteSpace = false;
	$wsdl_dom->preserveWhiteSpace = false;

	if (!$wsdl_location)
		return "WSDL is not found";
	$is_multiple_interfaces = FALSE;

	// load WSDL as DOM
	if (!$wsdl_dom->load($wsdl_location))
		return "WSDL could not be loaded.";

	$wsdl_dom->preserveWhiteSpace = false;

	// changing code for processing mutiple port types in wsdl 1.1 
	$is_multiple_interfaces = wsf_is_mutiple_port_types($wsdl_dom);

	if ($is_multiple_interfaces == FALSE) {
		$wsdl_dom = wsf_get_wsdl_dom($wsdl_dom, $xslt_location);
		if (!$wsdl_dom)
			return "Error creating WSDL DOM document";
		$sig_model_dom = wsf_get_sig_model_dom($wsdl_dom, $xslt_location);
	} else {
		$wsdl_dom = wsf_get_wsdl_dom($wsdl_dom, $xslt_location);
		$sig_model_dom = wsf_process_multiple_interfaces($wsdl_dom, $sig_model_dom, $xslt_location);
	}

	if (!$sig_model_dom)
		return "Error creating intermediate service operations signature model";

	//echo $sig_model_dom->saveXML();

	// get the list of operations
	$op_nodes = $sig_model_dom->getElementsByTagName(WSF_OPERATION);

	// process each operation
	foreach ($op_nodes as $op_node) {
		$operations[$op_node->localName] = "";

		// get the nodes describing operation characteristics 
		$op_child_list = $op_node->childNodes;

		foreach ($op_child_list as $op_child) {
			// process the signature node
			if ($op_child->localName == WSF_SIGNATURE) {
				// get the nodes representing operation parameters and return types within signature
				$param_list = $op_child->childNodes;
				foreach ($param_list as $param_node) {
					if ($param_node) {
						// look for params and returns nodes 
						if ($param_node->localName == WSF_PARAMS || $param_node->localName == WSF_RETURNS) {
							if ($param_node->hasAttributes()) {
								// Wrapper element 
								$params_attr = $param_node->attributes;

								// get wrapper element name, this is going to be the class name
								$ele_name = $params_attr->getNamedItem(WSF_WRAPPER_ELEMENT)->value;

								// array to hold child elements corresponding to sub classes
								$child_array = array ();

								// check if the class is already written
								if ($written_classes[$ele_name] == true)
									continue;

								// start writing class	
								echo "class " . $ele_name . " { \n";
								$written_classes[$ele_name] = true;

								// prepare the demo code that the user could use for testing client. 
								// shows how to create the input and receive the response
								if ($param_node->localName == WSF_PARAMS)
									$operations[$op_node->localName] = $operations[$op_node->localName] . "    \$input = new $ele_name();\n    //TODO: fill in the class fields of \$input to match your business logic\n";
								if ($param_node->localName == WSF_RETURNS)
									$operations[$op_node->localName] = $operations[$op_node->localName] . "\n    // call the operation\n    \$response = \$proxy->" . $op_node->attributes->getNamedItem('name')->value . "(\$input);\n    //TODO: Implement business logic to consume \$response, which is of type $ele_name\n";

								$param_child_list = $param_node->childNodes;
								foreach ($param_child_list as $param_child) {
									$param_attr = $param_child->attributes;
									$param_name = $param_attr->getNamedItem(WSF_NAME)->value;
									$param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
									// write public members of the class 
									echo "    public $" . $param_name . "; //" . $param_type . "\n";
									// if it is not s simple type, we have to keep track of it to write a corresponding class
									if ($param_attr->getNamedItem(WSF_WSDL_SIMPLE)->value == 'no')
										$child_array[] = $param_child;
								}
								echo "}\n\n";
								// done writing the current class, now go and write the sub classes
								wsf_write_sub_classes($child_array);
							} else {
								// TODO: No wrapper element, how to handle the code generation? Following code does nothing. Need to modify it
								$child_array = array ();
								$param_child_list = $param_node->childNodes;
								foreach ($param_child_list as $param_child) {
									$param_attr = $param_child->attributes;
									$param_name = $param_attr->getNamedItem(WSF_NAME)->value;
									echo $param_name;
									$param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
									$ele_name = $param_name;
								}
							}
						}
					}
				}
			}
		}
	}
}

/**
 * Function to precess command line arguments.  
 * $argv array of command line arguments
 * returns array with broken down arguments.
 * e.g. for "php argv.php one -h -b --c=test"
 * returns:
 * Array
 * (
 *   [input] => Array
 *       (
 *             [0] => argv.php
 *             [1] => one
 *       )
 *     [h] => true
 *     [b] => true
 *     [c] => test
 * )
 */
function arguments($argv) {
	$_ARG = array ();
	foreach ($argv as $arg) {
		if (ereg('--([^=]+)=(.*)', $arg, $reg)) {
			$_ARG[$reg[1]] = $reg[2];
		}
		elseif (ereg('^-([a-zA-Z0-9])', $arg, $reg)) {
			$_ARG[$reg[1]] = 'true';
		} else {
			$_ARG['input'][] = $arg;
		}
	}
	return $_ARG;
}

// start of main logic

// process command line arguments
$cl_args = arguments($argv);

// pick the WSDL form command line arguments
$wsdl_location = $cl_args['input'][1];

echo "<?php\n\n";

// call function to convert from WSDL to PHP
wsf_wsdl2php($wsdl_location);

echo "// define the class map\n";
echo "\$class_map = array(\n";
$class_map = "";
foreach ($written_classes as $class_name => $value) {
	$class_map = $class_map . " \"" . $class_name . "\" => \"" . $class_name . "\",";
}

$class_map = substr_replace($class_map, "", -1);
echo $class_map;
echo ");\n\n";

echo "try {\n\n";
echo "    // create client in WSDL mode\n";
echo "    \$client = new WSClient(array (\"wsdl\" =>\"$wsdl_location\",\n";
echo "        \"classmap\" => \$class_map));\n\n";

echo "    // get proxy object reference form client \n";
echo "    \$proxy = \$client->getProxy();\n\n";

echo "    // create input object and set values\n";

foreach ($operations as $op_name => $value) {
	echo $value . "\n";
}

echo "} catch (Exception \$e) {\n";
echo "	// in case of an error, process the fault\n";
echo "	if (\$e instanceof WSFault) {\n";
echo "		printf(\"Soap Fault: %s\\n\", \$e->Reason);\n";
echo "	} else {\n";
echo "		printf(\"Message = %s\\n\", \$e->getMessage());\n";
echo "	}\n";
echo "}\n";

echo "?>\n";
?>
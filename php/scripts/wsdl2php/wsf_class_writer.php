<?php

// array to keep track of classes that are already written 
$written_classes = array ();

// array to hold information on operations to help generate demo code 
$operations = array ();

/**
 * Function to write sub classes.  
 * $nodes array of nodes corresponding to the classes to be written
 * returns code segment corresponding to sub classes as a strring
 */
function wsf_write_sub_classes($nodes) {
	global $written_classes;
	$code = "";
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

				$code = $code . "class " . $type_name . " { \n";
				$written_classes[$type_name] = true;

				$param_child_list = $node->childNodes;
				foreach ($param_child_list as $param_child) {
					$param_attr = $param_child->attributes;
					$param_name = $param_attr->getNamedItem(WSF_NAME)->value;
					$param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
					// write public members of the class 
					$code = $code . "    public $" . $param_name . "; //" . $param_type . "\n";
					// if it is not s simple type, we have to keep track of it to write a corresponding class
					if ($param_attr->getNamedItem(WSF_WSDL_SIMPLE)->value == 'no')
						$child_array[] = $param_child;
				}
				$code = $code . "}\n\n"; 
				// done writing the current class, now go and write the sub classes
				$code = $code . wsf_write_sub_classes($child_array);
			}
			// TODO: How to generate code if we do not have a wrapper element?
			// TODO: What about arrays?
		}
	}
	return $code;
}

/**
 * Function to write classes. Does the WSDL to PHP conversion using a 'sig model'.  
 * $wsdl_location location of the WSDL
 * returns code segment corresponding to classes as a strring
 */
function wsf_wsdl2php($wsdl_location) {

	require_once ('dynamic_invocation/wsf_wsdl_consts.php');
	require_once ('dynamic_invocation/wsf_wsdl_util.php');

	global $written_classes;
	global $operations;
	
	$code = "";

	$wsdl_dom = new DomDocument();
	$sig_model_dom = new DOMDocument();

	$xslt_location = "./xslt/";

	$sig_model_dom->preserveWhiteSpace = false;
	$wsdl_dom->preserveWhiteSpace = false;

	if (!$wsdl_location) {
		echo "WSDL is not found";
		return NULL;
	}
	$is_multiple_interfaces = FALSE;

	// load WSDL as DOM
	if (!$wsdl_dom->load($wsdl_location)) {
		echo "WSDL could not be loaded.";
		return NULL;
	}

	$wsdl_dom->preserveWhiteSpace = false;

	// changing code for processing mutiple port types in wsdl 1.1 
	$is_multiple_interfaces = wsf_is_mutiple_port_types($wsdl_dom);

	if ($is_multiple_interfaces == FALSE) {
		$wsdl_dom = wsf_get_wsdl_dom($wsdl_dom, $xslt_location);
		if (!$wsdl_dom) {
			echo "Error creating WSDL DOM document";
			return NULL;
		}
		$sig_model_dom = wsf_get_sig_model_dom($wsdl_dom, $xslt_location);
	} else {
		$wsdl_dom = wsf_get_wsdl_dom($wsdl_dom, $xslt_location);
		$sig_model_dom = wsf_process_multiple_interfaces($wsdl_dom, $sig_model_dom, $xslt_location);
	}

	if (!$sig_model_dom) {
		echo "Error creating intermediate service operations signature model";
		return NULL;
	}

	//echo $sig_model_dom->saveXML();

	// get the list of operations
	$op_nodes = $sig_model_dom->getElementsByTagName(WSF_OPERATION);

	// process each operation
	foreach ($op_nodes as $op_node) {
		
		// get operation name 
		$op_attr = $op_node->attributes;
		$op_name = $op_attr->getNamedItem(WSF_NAME)->value;

		if ($operations[$op_name] == NULL) { // it operation is already found in an earlier parse, should not re-set it
			$operations[$op_name] = array();
			$operations[$op_name][WSF_CLIENT] = "";
			$operations[$op_name][WSF_SERVICE] = "";
		}

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
								$code = $code .  "class " . $ele_name . " { \n";
								$written_classes[$ele_name] = true;

								// prepare the demo code that the user could use for testing client. 
								// shows how to create the input and receive the response
								
								if ($param_node->localName == WSF_PARAMS) {
									$operations[$op_name][WSF_CLIENT] = $operations[$op_name][WSF_CLIENT] . "    \$input = new $ele_name();\n    //TODO: fill in the class fields of \$input to match your business logic\n";
									$operations[$op_name][WSF_SERVICE] = $operations[$op_name][WSF_SERVICE] . "function ".$op_name . "(\$input) {\n    // TODO: fill in the business logic\n    // NOTE: \$input is of type $ele_name\n";
								}
								if ($param_node->localName == WSF_RETURNS) {
									$operations[$op_name][WSF_CLIENT] = $operations[$op_name][WSF_CLIENT] . "\n    // call the operation\n    \$response = \$proxy->" . $op_node->attributes->getNamedItem('name')->value . "(\$input);\n    //TODO: Implement business logic to consume \$response, which is of type $ele_name\n";
									$operations[$op_name][WSF_SERVICE] = $operations[$op_name][WSF_SERVICE] . "    // NOTE: should return an object of type $ele_name\n}\n\n";
								}

								$param_child_list = $param_node->childNodes;
								foreach ($param_child_list as $param_child) {
									$param_attr = $param_child->attributes;
									$param_name = $param_attr->getNamedItem(WSF_NAME)->value;
									$param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
									// write public members of the class 
									$code = $code .  "    public $" . $param_name . "; //" . $param_type . "\n";
									// if it is not s simple type, we have to keep track of it to write a corresponding class
									if ($param_attr->getNamedItem(WSF_WSDL_SIMPLE)->value == 'no')
										$child_array[] = $param_child;
								}
								$code = $code .  "}\n\n";
								// done writing the current class, now go and write the sub classes
								$code = $code .  wsf_write_sub_classes($child_array);
							} else {
								// TODO: No wrapper element, how to handle the code generation? Following code does nothing. Need to modify it
								$child_array = array ();
								$param_child_list = $param_node->childNodes;
								foreach ($param_child_list as $param_child) {
									$param_attr = $param_child->attributes;
									$param_name = $param_attr->getNamedItem(WSF_NAME)->value;
									$code = $code .  $param_name;
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
	
	return $code;
}

?>
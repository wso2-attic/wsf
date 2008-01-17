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
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


function wsf_serivce_invoke_function($operation_node, $function_name, $envelope_node, $class_map)
{
	if($operation_node){
		foreach($operation_node->childNodes as $style){
			if($style->tagName == WSF_SIGNATURE){
				$signature_node = $style;
			}
		}
	}

	if($signature_node){
		$params_node = $signature_node->firstChild;
		if($params_node && $params_node->localName == WSF_PARAMS){
			$args = $params_node->childNodes->length;
			$index = 1;
			$param_array = array();
			foreach($params_node->childNodes as $param_node){
				$param_attr = $param_node->attributes;
				$param_name = $param_attr->getNamedItem(WSF_NAME)->value;
				$param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
				$value_array[WSF_NAME] = $param_name;
				$value_array[WSF_TYPE] = $param_type;
				$param_array[$index] = $value_array;
				$index ++;
			}
		}
	}

	foreach($envelope_node->childNodes as $env_child_node){
		if($env_child_node->localName == 'Body'){
			$soap_body_node = $env_child_node->firstChild;
			break;
		}
	}

	if(!$soap_body_node){
		error_log("soap_body not found", 0);
	}

	$soap_body_child_list = $soap_body_node->childNodes;
	$payload_child_length = $soap_body_child_list->length;

	if($payload_child_length > $args)
	error_log("Input message is wrong", 0);


	if($class_map == NULL){
		$index2 = 1;
		$arg_array = array();
		foreach($soap_body_child_list as $param_soap_child){
			if($param_array[$index2][WSF_NAME] == $param_soap_child->localName){
				if (is_xsd_type($param_array[$index2][WSF_TYPE])){
					$converted_value =  wsf_wsdl_util_convert_value($param_array[$index2][WSF_TYPE], $param_soap_child->firstChild->wholeText);
					$arg_array[$index2 -1] = $converted_value;
				}
				else{
					// create an object
				}
				$index2++;
			}
		}

		$response_value = call_user_func_array($function_name, $arg_array);
		$response_payload_string = wsf_wsdl_create_response_payload($response_value, $signature_node);
	}
	else{
		//file_put_contents("/tmp/my.txt", print_r($soap_body_node->localName, TRUE));
	}
	
	return $response_payload_string;
}

function wsf_wsdl_create_response_payload($return_val, $signature_node)
{
	require_once('wsf_wsdl_client_response.php');

	$is_wrapper = FALSE;
	$tmp_param_struct = array();

	$res_payload_dom = new DOMDocument('1.0', 'iso-8859-1');
	 
	foreach ($signature_node->childNodes as $signature_child_node){
		if($signature_child_node->localName == WSF_RETURNS){
			$returns_node = $signature_child_node;
		}
	}

	if(!$returns_node)
	error_log("Returns node not found", 0);

	if($returns_node->hasAttributes()){
		$ret_value_name = $returns_node->attributes->getNamedItem(WSF_WRAPPER_ELEMENT)->value;
		$ret_value_namespace = $returns_node->attributes->getNamedItem(WSF_WRAPPER_ELEMENT_NS)->value;
		$body_array = array();
		$body_array[WSF_NS] = $ret_value_namespace;
		$is_wrapper = TRUE;
	}


	$param_child_list = $returns_node->childNodes;
	foreach($param_child_list as $param_child){
		$param_attr = $param_child->attributes;
		$param_name = $param_attr->getNamedItem(WSF_NAME)->value;
		$param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
		$body_array[$param_name] = wsf_create_response_struct($param_child, $ret_value_namespace);
	}

	if($is_wrapper == TRUE)
	$tmp_param_struct[$ret_value_name] = $body_array;
	else
	$tmp_param_struct = $body_array;



	$element = $res_payload_dom->createElementNS($ret_value_namespace, $ret_value_name);
	/* This is for array implementation */
	wsf_service_create_response_payload_for_array($res_payload_dom, $tmp_param_struct[$ret_value_name], $element, $return_val);
	$res_payload_dom->appendChild($element);
	$res_payload_node = $res_payload_dom->firstChild;
	$clone_node = $res_payload_node->cloneNode(TRUE);
	return $res_payload_dom->saveXML($clone_node);
}


function wsf_service_create_response_payload_for_array(DomDocument $payload_dom, $parameter_struct, DomNode $root_ele, $argument_array)
{
	static $i = 2;
	foreach($parameter_struct as $key => $value){
		if(is_array($value)){
			if($value[WSF_NS]){
				if (isset($value[WSF_TYPE]) && $value[WSF_TYPE]){
					foreach($argument_array as $arg_key => $arg_val){
						if($key == $arg_key){
							/* type conversion is needed */
							$element_2 = $payload_dom->createElementNS($value[WSF_NS], "ns".$i.":".$key, $arg_val);
							$root_ele->appendChild($element_2);
							$i++;
						}
					}
				}
				else {
					foreach($argument_array as $arg_key => $arg_val){
						if($key == $arg_key){
							$element_2 = $payload_dom->createElementNS($value[WSF_NS], "ns".$i.":".$key);
							wsf_service_create_response_payload_for_array($payload_dom, $value, $element_2, $arg_val);
							$root_ele->appendChild($element_2);
							$i++;
						}
					}

				}
			}
		}else if($key == WSF_TYPE && is_xsd_type($value)){
			/* TODO multiple values */
			if($value == 'boolean' && !$argument_array[0])
			$element_2 = $payload_dom->createTextNode(0);
			else
			$element_2 = $payload_dom->createTextNode($argument_array[0]);
			$root_ele->appendChild($element_2);
		}
	}

}


?>

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


/**
 * Processes and validate response message and assign values to class map.
 * @param DomDocument $envelope_dom response envelope
 * @param DomDocument $signature_dom response parameter string
 * @param array $response_parameters array of response parameters
 * @return mixed an object, an array or a simple type in line with the 
 * expected format of the response
 */
function wsf_client_response_and_validate(DomDocument $envelope_dom, DomDocument $signature_dom, $response_parameters)
{
    require_once('wsf_wsdl_consts.php');
    require_once('wsf_wsdl_util.php');

    $tmp_param_struct = array();

    $envelope_node = $envelope_dom->documentElement;
    $returns_node = $signature_dom->documentElement;

    $ele_ns = NULL;
    $is_wrapper = FALSE;

    if($returns_node){
        if($returns_node->localName == WSF_RETURNS){
            if($returns_node->hasAttributes()){
                /* Wrapper element of the request operation */
                $params_attr = $returns_node->attributes;
                $ele_name = $params_attr->getNamedItem(WSF_WRAPPER_ELEMENT)->value;
                $ele_ns = $params_attr->getNamedItem(WSF_WRAPPER_ELEMENT_NS)->value;
                $child_array =  array();
                $child_array[WSF_NS] = $ele_ns;
                $is_wrapper = TRUE;
                            
                $param_child_list = $returns_node->childNodes;
                foreach($param_child_list as $param_child){
                    $param_attr = $param_child->attributes;
                    $param_name = $param_attr->getNamedItem(WSF_NAME)->value;
                    $param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
                    $child_array[$param_name] = wsf_create_temp_struct($param_child, $ele_ns); 
                }
            }
            else{
                /* No wrapper element in the request */
                $child_array =  array();
                $param_child_list = $returns_node->childNodes;
                foreach($param_child_list as $param_child){
                    $param_attr = $param_child->attributes;
                    $param_name = $param_attr->getNamedItem(WSF_NAME)->value;
                    $param_type = $param_attr->getNamedItem(WSF_TYPE)->value;
                    $child_array[$param_name] = wsf_create_temp_struct($param_child, $ele_ns);
                    $ele_name = $param_name;
                }
            }
        }
    }

    if ($is_wrapper == TRUE)
        $tmp_param_struct = $child_array;
    else
        $tmp_param_struct = $child_array[$ele_name];



    /** get SOAP body DOM tree to compare with Sig model */
	foreach($envelope_node->childNodes as $env_child_node){
		if($env_child_node->localName == 'Body'){
			$soap_body_node = $env_child_node->firstChild;
			break;
		}
	}

	if(!$soap_body_node){
		error_log("soap_body not found", 0);
	}

    $class_map = NULL;
    if(isset($response_parameters[WSF_CLASSMAP]))
        $class_map = $response_parameters[WSF_CLASSMAP];

    $op_param_values = array();
    if($class_map !== NULL)
    {
        $op_param_values = wsf_parse_payload_for_class_map($soap_body_node, $tmp_param_struct, $ele_name, $class_map);
    }
    else
    {
        $op_param_values = wsf_parse_payload_for_array($soap_body_node, $tmp_param_struct);
    }

    return $op_param_values;
}

?>

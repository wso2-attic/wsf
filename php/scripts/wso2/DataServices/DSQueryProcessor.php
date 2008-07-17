<?php

require_once("wso2/DataServices/DSDBExecutor.php");
require_once("wso2/DataServices/DSConstants.php");
require_once("wso2/DataServices/DSUtils.php");

/**
 * DSQueryProcessor
 * Process the queries
 */
class DSQueryProcessor {

    private $type_map = array(
        "CHAR" => "string",
        "VARCHAR" => "string",
        "STRING" =>"string",
        "LONGVARCHAR" => "string",
        "NEMERIC" => "string",
        "DECIMAL" => "int",
        "BIT" =>"boolean",
        "SAMLLINT"=>"int",
        "INT"=>"int",
        "INTEGER"=>"int",
        "BIGINT"=>"int",
        "REAL"=>"double",
        "FLOAT"=>"double",
        "DOUBLE"=>"double");
    /**
     * Main entry point to the class, process the request message and returns
     * the response
     *
     * @param string $req_msg_str request message as a string
     * @param array $query query details for the current operation
     * @param DSDBExecutor object $dbe
     * @return string response message
     */
    public function process_inmessage($req_msg_str, $operation_query, $dbe) {
        // extract out the input params from the request message
        $input_params = $this->derive_params_from_req_message($req_msg_str);

        // build the response payload
        $doc = new DOMDocument();
       
        // process the query with the $input_params
        $root = $this->process_query($input_params, $operation_query, $dbe, $doc);
        $doc->appendChild($root);
        
        // save the dom to an string
        $res_msg_str = $doc->saveXML();

        // return the respone as an xml string
        return $res_msg_str;
    }
    
    /**
     * Fill the param_to_value array from the request message information
     *
     * @param DOMDocument $doc 
     */
    private function derive_params_from_req_message($req_msg_str) {
        $params = array();
        $doc = new DOMDocument();
        $doc->loadXML($req_msg_str);
        if($doc) {
            // $dom_node contains the request wrapper
            $dom_node = $doc->firstChild;
            while($dom_node->nodeType != XML_ELEMENT_NODE) {
                $dom_node = $dom_node->nextSibling;
            }
            if(!is_null($dom_node) && $dom_node->hasChildNodes()) {
                
                // go through each parameter elements
                $child_list = $dom_node->childNodes;
                
                foreach($child_list as $child) {
                    if($child->nodeType == XML_ELEMENT_NODE) {
                        $localname = $child->localName;
                        $nodevalue = $child->nodeValue;
                        $params[$localname] = $nodevalue;
                    }
                }
            }
        }
        else {
            DSUtils::error_log(__FILE__, __LINE__, "Dom Document creation failed, Invalid XML String");    
            throw new WSFault("Sender", "Failed to build the dom from the input message, Invalid request XML");
        }
        return $params;
    }

    /**
     * process the query with input params and return the output params with the
     * response is set to the response dom document
     *
     * @param array $input_params input param from the caller context
     * @param array $query the query to process
     * @param DSDBExectuor object $dbe executes the db sql queries
     * @return DOMNode $parent the parent of the current context of the response dom
     */
    private function process_query($input_params, $query, $dbe, $doc) {
        // extracting out the components from the query

        $input_format = NULL;
        $output_format = NULL;
        $sql = NULL;
        $input_mapping = NULL;

        // input format is an optional parameter
        if(array_key_exists(DS_INPUT_FORMAT, $query)) {
            $input_format = $query[DS_INPUT_FORMAT];
        }
        // output format is a required parameter
        if(array_key_exists(DS_OUTPUT_FORMAT, $query)) {
            $output_format = $query[DS_OUTPUT_FORMAT];
        }
        else {
            DSUtils::error_log(__FILE__, __LINE__, "Required configuration output param is not found in". print_r($query, TRUE));    
            throw new WSFault("Sender", "Failed to load Configurations");
        }
        
        // sql is a required parameter
        if(array_key_exists(DS_SQL, $query)) {
            $sql = $query[DS_SQL];
        }
        else {
            DSUtils::error_log(__FILE__, __LINE__, "Required configuration sql is not found in". print_r($query, TRUE));    
            throw new WSFault("Sender", "Failed to load Configurations");
        }

        // input mapping is an optional parameter
        if(array_key_exists(DS_INPUT_MAPPING, $query)) {
            $input_mapping = $query[DS_INPUT_MAPPING];
        }
      
        // do the input mapping, this will convert the input params from callers context to the query context
        $converted_input_params = $this->convert_input_params_to_context($input_params, $input_mapping);

        // this will validate the input params and ordered them and cast to the correct type
        $typed_ordered_input_params = $this->validate_input_params($converted_input_params, $input_format, $input_params);

        //simply execute the query, we done all preparation for the query execution
        $results = $dbe->execute_query($sql, $typed_ordered_input_params);

        $root = $this->build_response($results, $output_format, $input_params, $dbe, $doc);

        return $root;
    }

    /**
     * convert the callers input params to calling context input params
     * 
     * @param array $input_params input params from callers context
     * @param array $input_mapping mapping from callers context names to calling context names
     * @return arary input params w.r.t calling context
     */
    private function convert_input_params_to_context($input_params, $input_mapping)
    {
        // if input mapping is NULL, don't bother, we will take just input params without mapping
        if(is_null($input_mapping) || !is_array($input_mapping)) {
            return $input_params;
        }

        $converted_input_params = array();

        foreach($input_params as $param_key=> $param_value) {
            if(array_key_exists($param_key, $input_mapping)) {
                // the mapping is available, we are goint to the mapped key

                $mapped_key = $input_mapping[$param_key];
                $converted_input_params[$mapped_key] = $param_value;
            }
            else {
                // we take the input param as it is
                $converted_input_params[$param_key] = $param_value;
            }
        }
        return $converted_input_params;
    }

    /**
     * validate the input params and cast them to the correct type and correct order

     * @param array $input_param the input param in query context
     * @param array $input_format the input format given in the config
     *         map of "param name" => "param type"
     * @param array $original_input_param, for a descriptive error log
     * @return the input param cast to the correct type
     * @throws WSFault if validation fails
     */
    private function validate_input_params($input_params, $input_format, $original_input_params) {
        // if no input is required..
        if($input_format == NULL) {
            return NULL;
        }
        
        // if input params are not given
        if($input_params == NULL && !is_array($input_params)) {
            DSUtils::error_log(__FILE__, __LINE__, "Required configuration input param is not found for". print_r($input_format, TRUE).
                ", found params are ".print_r($input_params, TRUE). "original input params are ".print_r($original_input_params, TRUE));
            throw new WSFault("Sender", "Failed to load Configurations");
        }

        $ordered_input_params = array();
        foreach($input_format as $param_name => $param_type) {
            if(array_key_exists($param_name, $input_params)) {
                $param_value = $input_params[$param_name];
                $converted_param_value = $this->convert_type($param_value, $param_type);
                $ordered_input_params[] = $converted_param_value;
            }
            else {
                DSUtils::error_log(__FILE__, __LINE__, "Input parameter $param_name is missing,".
                        "this should be in $param_type type, ".
                        "found params are ".print_r($input_params, TRUE). "original input params are ".print_r($original_input_params, TRUE));
                throw new WSFault("Sender", "Input parameter $param_name is missing,".
                        "this should be in $param_type type");
            }
        }
        return $ordered_input_params;
    }
    
    /**
     * convert the value to the type
     *
     * @param string $value
     * @param string $type
     * @return converted $value to $type type
     */
    private function convert_type($value, $type) {
        if($value && $type) {
            
            if($this->type_map[$type] =='string' ) {
                return $value;
            }
            else if($this->type_map[$type] == 'int') {
                return (int)$value;    
            }
            else if($this->type_map[$type]== 'double') {
                return (double)$value;
            }
            else if($this->type_map[$type] == 'boolean') {
                return (boolean)$value;
            }
            else {
                 return $value;
            }
        }
    }

    /**
     * build the reponse from the result set
     *
     * @param array $result_table array of the result set from DB Execution
     * @param array $output_format format of the output
     * @param array $input_param input param of the query context
     * @param DSDBExecutor object $dbe used for recursive query processing
     * @param DOMDocument $doc reponse document
     * @return DOMNode $parent the parent of the current response dom structure
     */
    private function build_response($result_table, $output_format, $input_params, $dbe, $doc) {

        // extract the respones format in to variables

        $result_element_name = NULL;
        $row_element_name = NULL;
        $use_nil = TRUE;
        $namespace = NULL;
        $column_default_behaviour = NULL;
        $elements = array();
        $attributes = array();
        $texts = array();
        $queries = array();
        $elements_order = NULL;


        if(array_key_exists(DS_RESULT_ELEMENT, $output_format)) {
            $result_element_name = $output_format[DS_RESULT_ELEMENT];
        }
        else {
            $result_element_name = DS_DEFAULT_RESULT_ELEMENT;
        }
        if(array_key_exists(DS_ROW_ELEMENT, $output_format)) {
            $row_element_name = $output_format[DS_ROW_ELEMENT];
        }
        else {
            $row_element_name = DS_DEFAULT_ROW_ELEMENT;
        }
        if(array_key_exists(DS_USE_NIL, $output_format)) {
            $use_nil = $output_format[DS_USE_NIL];
        }
        if(array_key_exists(DS_DEFAULT_NAMESPACE, $output_format)) {
            $namespace = $output_format[DS_DEFAULT_NAMESPACE];
        }
        else {
            $namespace = DS_RESPONSE_NS_DEFAULT_URI;
        }
        if(array_key_exists(DS_COLUMN_DEFAULT, $output_format)) {
            $column_default_behaviour = $output_format[DS_COLUMN_DEFAULT];
        }
        else {
            $column_default_behaviour = DS_DEFAULT_COLUMN_DEFAULT;
        }
        if(array_key_exists(DS_ELEMENTS, $output_format)) {
            $elements = $output_format[DS_ELEMENTS];
        }
        if(array_key_exists(DS_ATTRIBUTES, $output_format)) {
            $attributes = $output_format[DS_ATTRIBUTES];
        }
        if(array_key_exists(DS_TEXTS, $output_format)) {
            $texts = $output_format[DS_TEXTS];
        }
        if(array_key_exists(DS_QUERIES, $output_format)) {
            $queries = $output_format[DS_QUERIES];
        }
        if(array_key_exists(DS_ELEMENTS_ORDER, $output_format)) {
            $elements_order = $output_format[DS_ELEMENTS_ORDER];
        }

        $result_element = $doc->createElementNS($namespace, $result_element_name);

        // iterate throught all the rows of the result table
        foreach($result_table as $result_row) {
            $row_element = $doc->createElementNS($namespace, $row_element_name);    
            $result_element->appendChild($row_element);

            // we first save all the column elements in an array
            $column_results_arr = array();
            
            // first iterate all the elements
            foreach($elements as $element_name => $column_info) {

                $column_value = $this->infer_column_value($column_info, $result_row, $input_params);

                if($column_value === NULL && !$use_nil) {
                    DSUtils::error_log(__FILE__, __LINE__, "$element_name is NULL".
                        "It should not be null");
                    throw new WSFault("Sender", "Non nillable $element_name element is NULL");
                }
                
                // create an element and save it
                $column_element = $doc->createElementNS($namespace, $element_name);
                $text_node = new DOMText($column_value);
                $column_element->appendChild($text_node);
                $column_results_arr[$element_name]= $column_element;
            }

            // second iterate all the attributes
            foreach($attributes as $attribute_name => $column_info) {

                $column_value = $this->infer_column_value($column_info, $result_row, $input_params);

                if($column_value === NULL && !$use_nil) {
                    DSUtils::error_log(__FILE__, __LINE__, "$column_name is NULL".
                        "It should not be null");
                    throw new WSFault("Sender", "Non nillable result attribute is NULL");
                }
                
                // create an attribute and save it
                $column_attribute = new DOMAttr($attribute_name, $column_value);
                $column_results_arr[$attribute_name]= $column_attribute;
            }

            // third iterate through all the texts
            foreach($texts as $text_id => $column_info) {

                $column_value = $this->infer_column_value($column_info, $result_row, $input_params);

                if($column_value === NULL && !$use_nil) {
                    DSUtils::error_log(__FILE__, __LINE__, "$column_name is NULL".
                        "It should not be null");
                    throw new WSFault("Sender", "Non nillable result text is NULL");
                }
                
                // create an text and save it
                $column_text = $doc->createTextNode($column_value);
                $column_results_arr[$text_id]= $column_text;
            }
            
            // build the new merged input params
            $merged_input_params = array_merge($input_params, $result_row);

            // forth iterate through quiries
            foreach($queries as $query_id => $query_info) {

                $query_result_element = $this->process_query($merged_input_params, $query_info, $dbe, $doc);
                $column_results_arr[$query_id]= $query_result_element;
            }

            // now check whether the order is provided
            if($elements_order && is_array($elements_order)) {
                //if provided render it in the order provided by that,
                foreach($elements_order as $next_name) {
                    if(array_key_exists($next_name, $column_results_arr)) {
                        $next_element = $column_results_arr[$next_name];
                        $row_element->appendChild($next_element);
                    }
                    else {
                        DSUtils::error_log(__FILE__, __LINE__, "$next_name in elementsOrder ".
                                        "is non identified");
                        throw new WSFault("Sender", "Failed loading configurations");
                    }
                }
            }
            else {
                //if not just render it in the order it is placed
                foreach($column_results_arr as  $result_id => $column_element) {
                    $row_element->appendChild($column_element);
                }
            }
        }
        
        return $result_element;
    }

    /**
     * This will parse the column info and results and provide the column value
     *
     * @param array/string $column_info here $column_info either can be a text
     *           which has the column_name or
     *           an array with the structure array("column" => COLUMN_NAME,
     *                                  "param" => PARAM_NAME,
     *                                  "value" => PARAM_VALUE_CONST,
     *                                  "xsdType" => XSD_TYPE);
     * @param array $result_row row of results $column_name => $column_value
     * @param array $input_params input params $param_name=> $param_value
     * @param string the $column_value
     */
    private function infer_column_value($column_info, $result_row, $input_params) {
        $column_value = NULL;
        if(!is_array($column_info)) {
            //this is the common case
            $column_name = $column_info;
            if(array_key_exists($column_name, $result_row)) {
                $column_value = $result_row[$column_name];
            }
        }
        else {
            if(array_key_exists(DS_COLUMN_NAME, $column_info)) {
                // either colum should be set
                $column_name = $column_info[DS_COLUMN_NAME];
                if(array_key_exists($column_name, $result_row)) {
                    $column_value = $result_row[$column_name];
                }
            }
            else if(array_key_exists(DS_COLUMN_PARAM, $column_info)) {
                // either column param should be set
                $column_param = $column_info[DS_COLUMN_PARAM];

                // if the param is available in the input param set we use that value
                if(array_key_exists($column_param, $input_param)) {
                    $column_value = $input_param[$column_param];
                }
            }
            else if(array_key_exists(DS_COLUMN_VALUE, $column_info)) {
                // just get the hard coded value
                $column_value = $column_info[DS_COLUMN_VALUE];
            }
        }
        return $column_value;
    }
}
?>

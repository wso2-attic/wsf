<?php
/**
 * class to keep logic on generating the WSDL
 */
class DSWSDLGenerator {

    // sql_type => $xsd_type
    private $sql_to_xsd_map = array(
        "CHAR" => "xsd:string",
        "VARCHAR" => "xsd:string",
        "STRING" =>"xsd:string",
        "LONGVARCHAR" => "xsd:string",
        "NUMERIC" => "xsd:string",
        "DECIMAL" => "xsd:int",
        "BIT" =>"xsd:boolean",
        "SAMLLINT"=>"xsd:int",
        "INT"=>"xsd:int",
        "INTEGER"=>"xsd:int",
        "BIGINT"=>"xsd:int",
        "REAL"=>"xsd:double",
        "FLOAT"=>"xsd:double",
        "DOUBLE"=>"xsd:double");

    // php type => $xsd_type
    private $php_to_xsd_map = array(
        "VAR_STRING" => "xsd:string",
        "BOOL" => "xsd:boolean",
        "LONG" =>"xsd:long",
        "DATE" =>"xsd:dateTime",
        "DATETIME" =>"xsd:dateTime",
        "BLOB" => "xsd:string",
        "DOUBLE" => "xsd:double");

    /**
     * reuturn the annotation which generate the WSDL
     *
     * @param array $op_args, user passed arguments for DataService 
     *  "operations" option
     * @param array $config_args, for db configurations
     * @return array $annotations
     */
    public function generate_wsdl($op_args, $config_args) {
        $annotations = array();
        $complex_types = array();

        try {
            $dbe = new DSDBExecutor($config_args);
        } catch(Exception $e) {
            echo $e->getMessage();
            exit(0);
        }

        foreach($op_args as $op_name => $op_config) {

            $op_annotation = array();
           
            $op_element = $this->generate_input_element($op_name, $op_config, $complex_types);
            $op_res_element = $this->generate_output_element($op_name, $op_config, $complex_types, $dbe);

            $op_annotation[DS_WSDL_INPUT] = $op_element;
            $op_annotation[DS_WSDL_OUTPUT] = $op_res_element;

            $annotations[$op_name] = $op_annotation;
        }

        $annotations[DS_WSDL_TYPES] = $complex_types;

        return $annotations;
    }

    /**
     * generate the input element
     * @param string $op_name operation name
     * @param array $op_config configurations to the operation
     * @param array $complex_types reference to where keeps the complex types
     * @return array corrosponding to the request element schema
     */
    public function generate_input_element($op_name, $op_config, &$complex_types)
    {
        $input_format = NULL;
        $input_mapping = array();

        if(array_key_exists(DS_INPUT_FORMAT, $op_config)) {
            $input_format = $op_config[DS_INPUT_FORMAT];
        }
        if(array_key_exists(DS_INPUT_MAPPING, $op_config)) {
            $input_mapping = $op_config[DS_INPUT_MAPPING];
        }

        $op_subelements = $this->generate_input_subelements($input_format, $input_mapping);

        // the op element name and the type name is same
        $op_element_type_name = $op_name;
        $op_element = array(DS_WSDL_NAME => $op_name,
                            DS_WSDL_NAMESPACE => DS_REQUEST_NS_DEFAULT_URI,
                            DS_WSDL_TYPE => $op_element_type_name);

        $op_element_type = array(DS_WSDL_NAME => $op_element_type_name,
                                DS_WSDL_NAMESPACE => DS_REQUEST_NS_DEFAULT_URI,
                                DS_WSDL_SEQUENCE => $op_subelements);
        
        $this->add_complex_type($complex_types, $op_element_type);

        return $op_element;
    }

    /**
     * return the array of input elements to type
     * 
     * @param array $input_format map of mapped_name => sql type
     * @param array $input_mapping map of element_name => mapped_name
     * @return element_name => xsd type mapping
     */
    public function generate_input_subelements($input_format, $input_mapping) {
        // first of all if input mapping is none, nothing need to be in op request schema
        if($input_format == NULL) {
            return array();
        }
        $subelements = array();


        // create the reverse of $input_mapping
        // mapped_name => element_name

        $rev_input_mapping = array();
        foreach($input_mapping as $element_name => $mapped_name) {
            $rev_input_mapping[$mapped_name] = $element_name;
        }

        // for each mapped_name to sql type
        foreach($input_format as $mapped_name => $sql_type) {
            $xsd_type = DS_XSD_ANY;
            if(array_key_exists($sql_type, $this->sql_to_xsd_map)) {
                $xsd_type = $this->sql_to_xsd_map[$sql_type];
            }

            // element name is default to the mapped name
            $element_name = $mapped_name;
            if(array_key_exists($mapped_name, $rev_input_mapping)) {
                $element_name = $rev_input_mapping[$mapped_name];
            }
           
            // fil the sub elements
            $subelements []= array(DS_WSDL_NAME => $element_name,
                                DS_WSDL_TYPE => $xsd_type);
        }
        return $subelements;
    }

    /**
     * generate the output element
     * @param string $op_name operation name
     * @param array $query configurations to the operation
     * @param array $complex_types reference to where keeps the complex types
     * @param DSDBExecutor $dbe database executor
     * @return array corrosponding to the response element schema
     */
    public function generate_output_element($op_name, $query, &$complex_types, $dbe)
    {
        $output_format = NULL;
        $input_format = NULL;
        $sql = NULL;

        if(array_key_exists(DS_OUTPUT_FORMAT, $query)) {
            $output_format = $query[DS_OUTPUT_FORMAT];
        }
        else {
            DSUtils::error_log(__FILE__, __LINE__, "Required configuration output param is not found in".
                        print_r($query, TRUE). " for $op_name");
            echo "Error generating the wsdl";
            exit(0);
        }
        if(array_key_exists(DS_SQL, $query)) {
            $sql = $query[DS_SQL];
        }
        else {
            DSUtils::error_log(__FILE__, __LINE__, "Required configuration sql is not found in".
                        print_r($query, TRUE). " for $op_name");
            echo "Error generating the wsdl";
            exit(0);
        }

        if(array_key_exists(DS_INPUT_FORMAT, $query)) {
            $input_format = $query[DS_INPUT_FORMAT];
        }

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


        // now we create the row element 
        $row_element_type_name = $row_element_name. DS_WSDL_TYPE_POSTFIX;
        if($use_nil) {
            $nillable = DS_WSDL_TRUE;
        }
        else {
            $nillable = DS_WSDL_FALSE;
        }


       
        // prepare the column to xsd map
        $column_to_xsd_map = array();
       
        // first create the dummy params
        $dummy_params = $this->generate_dummy_params($input_format);

        // then fetch the column menta info
        $result_meta_info = $dbe->get_result_meta_info($sql, $dummy_params);


        // and fill the column to xsd
        foreach($result_meta_info as $column_name => $php_type) {
            if(array_key_exists($php_type, $this->php_to_xsd_map)) {
                $column_to_xsd_map[$column_name] = $this->php_to_xsd_map[$php_type];
            }
            else {
                $column_to_xsd_map[$column_name] = DS_XSD_ANY;
            }
        }

        // prepare the elements arr with all the elements
        $elements_arr = array();
        // name to element map
        $name_to_element_map = array();
        foreach($elements as $element_name => $column_info) {
            $element_type = NULL;
            $xsd_type = NULL;

            if(is_array($column_info) && array_key_exists(DS_COLUMN_TYPE, $column_info)) {
                // first priority to the xsd_type
                $xsd_type = $column_info[DS_COLUMN_TYPE];
            }
            else if(!is_array($column_info) || array_key_exists(DS_COLUMN_NAME, $column_info)) {
                // second priority to the column name
                $column_name = NULL;
                if(is_array($column_info)) {
                    $column_name = $column_info[DS_COLUMN_NAME];
                }
                else {
                    $column_name = $column_info;
                }
                if(array_key_exists($column_name, $column_to_xsd_map)) {
                    $xsd_type = $column_to_xsd_map[$column_name];
                }
                else {
                    $xsd_type = DS_XSD_ANY;
                }
            }
            else if(is_array($column_info) && array_key_exists(DS_COLUMN_PARAM, $column_info)) {
                // third check the RARAM column
                $param_name = $column_info[DS_COLUMN_PARAM];

                if(array_key_exists($param_name, $input_format)) {
                    $sql_type = $input_format[$param_name];
                    if(array_key_exists($sql_type, $this->sql_to_xsd_map)) {
                        $xsd_type = $this->sql_to_xsd_map[$sql_type];
                    }
                    else {
                        $xsd_type = DS_XSD_ANY;
                    }
                }
                else {
                    $xsd_type = DS_XSD_ANY;
                }
            }
            else {
                $xsd_type = DS_XSD_ANY;
            }

            $current_element = array(DS_WSDL_NAME => $element_name,
                                    DS_WSDL_NAMESPACE => $namespace, 
                                    DS_WSDL_TYPE => $xsd_type);

            $elements_arr[] = $current_element;
            $element_to_name_map[$element_name] = $current_element;
        }

        // derive the schema for queries
        foreach($queries as $query_name => $nested_query) {
            $current_element = $this->generate_output_element($op_name, $nested_query, $complex_types, $dbe);
            $elements_arr[] = $current_element;
            $element_to_name_map[$query_name] = $current_element;
        }
        if($elements_order) {
            $ordered_elements = array();
            foreach($elements_order as $element_name) {
                if(array_key_exists($element_name, $element_to_name_map)) {
                    $ordered_elements []= $element_to_name_map[$element_name];
                }
            }
        }
        else {
            $ordered_elements = $elements_arr;
        }

        // now prepare the attributes
        // prepare the attributes arr with all the attributes
        $attributes_arr = array();
        foreach($attributes as $attribute_name => $column_info) {
            $attribute_type = NULL;
            $xsd_type = NULL;

            if(is_array($column_info) && array_key_exists(DS_COLUMN_TYPE, $column_info)) {
                // first priority to the xsd_type
                $xsd_type = $column_info[DS_COLUMN_TYPE];
            }
            else if(!is_array($column_info) || array_key_exists(DS_COLUMN_NAME, $column_info)) {
                // second priority to the column name
                $column_name = NULL;
                if(is_array($column_info)) {
                    $column_name = $column_info[DS_COLUMN_NAME];
                }
                else {
                    $column_name = $column_info;
                }
                if(array_key_exists($column_name, $column_to_xsd_map)) {
                    $xsd_type = $column_to_xsd_map[$column_name];
                }
                else {
                    $xsd_type = DS_XSD_ANY;
                }
            }
            else if(is_array($column_info) && array_key_exists(DS_COLUMN_PARAM, $column_info)) {
                // third check the RARAM column
                $param_name = $column_info[DS_COLUMN_PARAM];

                if(array_key_exists($param_name, $input_format)) {
                    $sql_type = $input_format[$param_name];
                    if(array_key_exists($sql_type, $this->sql_to_xsd_map)) {
                        $xsd_type = $this->sql_to_xsd_map[$sql_type];
                    }
                    else {
                        $xsd_type = DS_XSD_ANY;
                    }
                }
                else {
                    $xsd_type = DS_XSD_ANY;
                }
            }
            else {
                $xsd_type = DS_XSD_ANY;
            }

            $current_attribute = array(DS_WSDL_NAME => $attribute_name,
                                    DS_WSDL_NAMESPACE => $namespace, 
                                    DS_WSDL_TYPE => $xsd_type);

            $attributes_arr[] = $current_attribute;
        }

        // prepare the row element
        $row_element = array(DS_WSDL_NAME => $row_element_name,
                             DS_WSDL_NAMESPACE => $namespace,
                             DS_WSDL_NILLABLE => $nillable,
                             DS_WSDL_MIN_OCCURS => 0,
                             DS_WSDL_MAX_OCCURS => DS_WSDL_UNBOUNDED,
                             DS_WSDL_TYPE => $row_element_type_name);

        $row_element_type = array(DS_WSDL_NAME => $row_element_type_name,
                                DS_WSDL_SEQUENCE => $ordered_elements,
                                DS_WSDL_ATTRIBUTES => $attributes_arr,
                                DS_WSDL_NAMESPACE => $namespace);

        // at the end create the wrapper element
        $result_element_type_name = $result_element_name. DS_WSDL_TYPE_POSTFIX;

        $result_element = array(DS_WSDL_NAME => $result_element_name,
                             DS_WSDL_NAMESPACE => $namespace,
                             DS_WSDL_TYPE => $result_element_type_name);

        $result_element_type = array(DS_WSDL_NAME => $result_element_type_name,
                                DS_WSDL_SEQUENCE => array($row_element),
                                DS_WSDL_NAMESPACE => $namespace);
        
        $this->add_complex_type($complex_types, $result_element_type);
        $this->add_complex_type($complex_types, $row_element_type);

        return $result_element;

    }

    /**
     * add complex type to the schema
     *
     * @param array $complex_types 
     * @param array $new_type the new type to added
     */
    private function add_complex_type(&$complex_types, $new_type) {
        $new_type_name = $new_type[DS_WSDL_NAME];
        $new_type_namespace = $new_type[DS_WSDL_NAMESPACE];
        foreach($complex_types as $complex_type) {
            $complex_type_name = $complex_type[DS_WSDL_NAME];
            $complex_type_namespace = $complex_type[DS_WSDL_NAMESPACE];

            if($new_type_name == $complex_type_name &&
                    $new_type_namespace == $complex_type_namespace) {
                // we are not adding duplicate types
                return;
            }
        }

        $complex_types []= $new_type;
    }
    
    /**
     * generate dummy parameters for the query
     */
    private function generate_dummy_params($input_format) {
        if($input_format == NULL) {
            return array();
        }
        $dummy_map = array(
            "CHAR" => "x",
            "VARCHAR" => "test",
            "STRING" =>"test",
            "LONGVARCHAR" => "test",
            "NEMERIC" => "test",
            "DECIMAL" => "1",
            "BIT" =>"true",
            "SAMLLINT"=>"1",
            "INT"=>"1",
            "INTEGER"=>"1",
            "BIGINT"=>"1",
            "REAL"=>"1",
            "FLOAT"=>"1",
            "DOUBLE"=>"1");

        $dummy_values = array();
        
        foreach($input_format as $input_name => $input_type) {
            if(array_key_exists($input_type, $dummy_map)) {
                $dummy_value = $dummy_map[$input_type];
            }
            else {
                $dummy_value = "1"; // safe value for any type..
            }
            $dummy_values []= $dummy_value;
        }
        
        return $dummy_values;
    }
}
?>

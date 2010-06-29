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

/**
 * This class retrives the types information from the php function and
 * maps with xsd types 
 */
class WS_WSDL_Operations
{

    const WS_OPERATION_INPUT_TAG = WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME;
    const WS_OPERATION_OUTPUT_TAG = WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME;
    const WS_OPERATION_TYPE_TAG = 'type';
    const WS_OPERATION_RET_TAG = 'return';
    const WS_OPERATION_NAME_TAG = 'name';

    static public $mappingTable = array(
                                      "string"         =>  "string",
                                      "boolean"        =>  "boolean",
                                      "double"         =>  "float",
                                      "float"          =>  "float",
                                      "int"            =>  "int",
                                      "integer"        =>  "int",
                                      "byte"           =>  "int",
                                      "decimal"        =>  "string",
                                      "base64Binary"   =>  "string",
                                      "hexBinary"      =>  "string",
                                      "anyType"        =>  "soap Var Object",
                                      "any"            =>  "soap Var Object",
                                      "QName"          =>  "string",
                                      "dateTime"       =>  "string",
                                      "date"           =>  "string",
                                      "time"           =>  "string",
                                      "unsignedLong"   =>  "int",
                                      "unsignedInt"    =>  "int",
                                      "unsignedShort"  =>  "int",
                                      "unsignedByte"   =>  "int",
                                      "positiveInteger"=>  "int",
                                      "negativeInteger"=>  "int",
                                      "nonNegativeInteger"=>"int",
                                      "gYearMonth"     =>  "string",
                                      "gMonthDate"     =>  "string",
                                      "gYear"          =>  "string",
                                      "gMonth"         =>  "string",
                                      "gDay"           =>  "string",
                                      "duration"       =>  "string",
                                      "Name"           =>  "string",
                                      "NCName"         =>  "string",
                                      "NMTOKEN"        =>  "string",
                                      "NOTATION"       =>  "string",
                                      "NMTOKENS"       =>  "string",
                                      "ENTITY"         =>  "string",
                                      "ENTITIES"       =>  "string",
                                      "IDREF"          =>  "string",
                                      "IDREFS"         =>  "string",
                                      "anyURI"         =>  "string",
                                      "language"       =>  "string",
                                      "normalizedString"=> "string",
                                      "token"          => "string");



    public $createdTypes = array();
    public $operations = array();
    public $xsdMapArry = array();
    public $phpMapArry = array();
    public $operationName;

    public $xsdTypes = array();
    public $className = NULL;

    /*
     * constructor of the class
     * @param Array $operations Array of operations defined in the service
     */
    function __construct($operations, $class_arry)
    {
        if($class_arry != NULL)
        {
            foreach($class_arry as $name => $class_info)
            {
                if(is_array($class_info) && is_array($class_info["operations"]))
                {
                    foreach($class_info["operations"] as $i=>$value)
                    {
                        $this->operationName = $value;
                        $this->xsdMapArry[$this->operationName] = array();
                        $this->className = $name;
                        $this->setOperations($this->operationName, $this->className);
                    }
                }
            }
        }
        else if($operations != NULL)
        {
            foreach($operations as $i=>$value)
            {
                $this->operationName = $value;
                $this->xsdMapArry[$this->operationName] = array();
                $this->setOperations($this->operationName, NULL);
            }
        }
    }

    public function getOperations() {
        return $this->operations;
    }

    public function getSchemaTypes() {
        return $this->xsdTypes;
    }

    private function setOperations($operationName, $classname = NULL)
    {
        $this->operations[$operationName][self::WS_OPERATION_INPUT_TAG] = array();
        $this->operations[$operationName][self::WS_OPERATION_OUTPUT_TAG] = array();

        $doc_comment = "";
        if($classname != NULL)
        {
            $class = new ReflectionClass($classname);
            $operation = $class->getMethod($operationName);

            $doc_comment = $operation->getDocComment();
        }
        else
        {
            $operation = new ReflectionFunction($operationName);
            $doc_comment = $operation->getDocComment();
        }

        if (!$doc_comment)
        {
            $this->xsdTypes[$operationName][self::WS_OPERATION_INPUT_TAG] = array();

            foreach($operation->getParameters() as $i => $param)
            {
                $match[2] = $param->getName();
                $match[1] = "anyType";
                $this->xsdTypes[$operationName][self::WS_OPERATION_INPUT_TAG][$match[2]] = array("type"=>"anyType",
                                                                         "array" => NULL,
                                                                         "object" => NULL);


                $this->createdTypes[$match[1]] = 2;
                $this->operations[$operationName][self::WS_OPERATION_INPUT_TAG][] =
                    array(self::WS_OPERATION_NAME_TAG => $match[2],
                          self::WS_OPERATION_TYPE_TAG => $match[1]);
            }


            $this->xsdTypes[$operationName][self::WS_OPERATION_OUTPUT_TAG]["returnVal"] = array("type"=> "anyType",
                                                                            "array" => NULL,
                                                                            "object" => NULL);

            $this->createdTypes[$match[1]] = 2;
            $this->operations[$operationName][self::WS_OPERATION_OUTPUT_TAG][] =
                array(self::WS_OPERATION_NAME_TAG => self::WS_OPERATION_RET_TAG,
                      self::WS_OPERATION_TYPE_TAG => $match[1]);

        }
        else
        {
            if(preg_match_all('|xs:?(\w+).*|', $doc_comment, $matching, PREG_SET_ORDER))
            {
                $i = 0;
                foreach($matching as $matchs)
                {
                    $i++;
                    $this->xsdMapArry[$this->operationName][$i] = $matchs[1];

                }
            }
            $j = 0;
            $k = 0;
            if(preg_match_all(
                    '|@param\s+(?:(\[\s*\d*\s*,[^\]]*\])\s+)?(?:(array)\s+of\s+)?(?:(object)\s+)?(\w+)\s+\$(\w+)\s+(.*)|',
                    $doc_comment,
                    $matches, PREG_SET_ORDER))
            {
                $this->xsdTypes[$operationName][self::WS_OPERATION_INPUT_TAG] = array();
                foreach($matches as $match)
                {
                    $min_max_occurs = $match[1];
                    $is_array = $match[2];
                    $is_object = $match[3];
                    $type_name = $match[4];
                    $element_name = $match[5];

                    // the default is set to NULL
                    $min = NULL;
                    $max = NULL;
                    if($min_max_occurs && !empty($min_max_occurs)) {
                        $result = NULL;
                        preg_match_all("|\[\s*(\d*)\s*,\s*([^\]]*)\s*\]|", $min_max_occurs,
                                $result, PREG_PATTERN_ORDER);

                        $min = $result[1][0];
                        $max = $result[2][0];

                    }

                    $j++;
		    $k++;
                    $this->createdTypes[$type_name] = 1;
                    $this->phpMapArry[$j] = $type_name;

                    if($is_object == "object")
                    {
                        $releventType = $type_name;
                    }
                    else
                    {
                        $releventType = $this->checkValidTypes($j, $k);
                    } 
                    $this->xsdTypes[$operationName][self::WS_OPERATION_INPUT_TAG][$element_name] = array("type"=>$releventType,
                                                                             "array" => $is_array,
                                                                             "object"=> $is_object,
                                                                             "min" => $min,
                                                                             "max" => $max);

                    
                    // the following information is used in building the message element
                    $this->operations[$operationName][self::WS_OPERATION_INPUT_TAG][] =
                        array(self::WS_OPERATION_NAME_TAG => $element_name,
                              self::WS_OPERATION_TYPE_TAG => $releventType,
                              "object"=> $is_object);

                }
            }

            if(preg_match(
                '|@return\s+(?:(\[\s*\d*\s*,\s*[^\]]*\])\s+)?(?:(array)\s+of\s+)?(?:(object)\s+)?(\w+)\s+\$(\w+)\s+(.*)|',
                $doc_comment, $match_r))
            {

                $min_max_occurs = $match_r[1];
                $is_array = $match_r[2];
                $is_object = $match_r[3];
                $type_name = $match_r[4];
                $element_name = $match_r[5];

                // the default is set to NULL
                $min = NULL;
                $max = NULL;

                if($min_max_occurs && !empty($min_max_occurs)) {
                    $result = NULL;
                    preg_match_all("|\[\s*(\d*)\s*,\s*([^\]]*)\s*\]|", $min_max_occurs,
                            $result, PREG_PATTERN_ORDER);

                    $min = $result[1][0];
                    $max = $result[2][0];

                }

                $j++;
                $k++;
                $this->phpMapArry[$j] = $type_name;

                if($is_object == "object")
                {
                    $returnType = $type_name;
                }
                else
                {
                    //$k++;
                    $returnType = $this->checkValidTypes($j, $k);
                } 

                $this->xsdTypes[$operationName][self::WS_OPERATION_OUTPUT_TAG][$element_name] = array("type"=>$returnType,
                                                                             "array" => $is_array,
                                                                             "object"=> $is_object,
                                                                             "min" => $min,
                                                                             "max" => $max);

                $this->createdTypes[$type_name] = 1;


                // the following information is used in building the message element
                $this->operations[$operationName][self::WS_OPERATION_OUTPUT_TAG][] =
                    array(self::WS_OPERATION_NAME_TAG => self::WS_OPERATION_RET_TAG,
                          self::WS_OPERATION_TYPE_TAG => $returnType,
                          "object"=> $is_object);

            }
        }
        require_once('dynamic_invocation/wsf_wsdl_consts.php');
        ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "ouput :".print_r($this->operations[$operationName][self::WS_OPERATION_OUTPUT_TAG], TRUE));
        ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "input :".print_r($this->operations[$operationName][self::WS_OPERATION_INPUT_TAG], TRUE));
    }
    /**
     * check if the xsd type and php types are mathched if not a log
     *is written
     *@param string $keyIndex 
     */
    function checkValidTypes($keyIndex, $keyXsdIndex)
    {
        $keyPHPArray = NULL;
        if(array_key_exists($keyXsdIndex, $this->xsdMapArry[$this->operationName])) {
            $keyPHPArray = $this->xsdMapArry[$this->operationName][$keyXsdIndex];
        }

        $PHPType = NULL;
        if(array_key_exists($keyIndex, $this->phpMapArry)) {
            $PHPType = $this->phpMapArry[$keyIndex];
        }
        
        require_once('dynamic_invocation/wsf_wsdl_consts.php');
        ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "mapping :".$keyPHPArray." to ".$PHPType);

        if( $keyPHPArray && array_key_exists($keyPHPArray, self::$mappingTable) && 
                $PHPType == self::$mappingTable[$keyPHPArray])
        {
            return $keyPHPArray;
        }
        else
        {
            error_log("type missmatched", 0);
            return $PHPType;
        }

    }


}




?>

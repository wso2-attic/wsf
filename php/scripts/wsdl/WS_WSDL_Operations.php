<?php

/*
 * Copyright (c) 2005-2008 WSO2, Inc. http://wso2.com
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

    const WS_OPERATION_INPUT_TAG = 'input';
    const WS_OPERATION_OUTPUT_TAG = 'output';
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
                        $this->setOperations($this->operationName, $name);
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
                $this->setOperations($this->operationName);
            }
        }
    }

    private function setOperations($operationName, $classname = NULL)
    {
        $this->operations[$operationName][self::WS_OPERATION_INPUT_TAG] = array();
        $this->operations[$operationName][self::WS_OPERATION_OUTPUT_TAG] = array();

        $doc_comment = "";
        if($classname != NULL)
        {
            $class = new ReflectionClass($classname);
            $method = $class->getMethod($operationName);

            $doc_comment = $method->getDocComment();
        }
        else
        {
            $operation = new ReflectionFunction($operationName);
            $doc_comment = $operation->getDocComment();
        }

        if (!$doc_comment)
        {
            $this->xsdTypes[$operationName]["In"] = array();

            foreach($operation->getParameters() as $i => $param)
            {
                $match[2] = $param->getName();
                $match[1] = "anyType";
                $this->xsdTypes[$operationName]["In"][$match[2]] = array("type"=>"anyType",
                                                                         "array" => NULL,
                                                                         "object" => NULL);


                $this->createdTypes[$match[1]] = 2;
                $this->operations[$operationName][self::WS_OPERATION_INPUT_TAG][] =
                    array(self::WS_OPERATION_NAME_TAG => $match[2],
                          self::WS_OPERATION_TYPE_TAG => $match[1]);
            }


            $this->xsdTypes[$operationName]["Out"]["returnVal"] = array("type"=> "anyType",
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
                    $this->xsdMapArry[$i] = $matchs[1];

                }
            }
            $j = 0;
            $k = 0;
            if(preg_match_all('|@param\s+(?:(array)\s+of\s+)?(?:(object)\s+)?(\w+)\s+\$(\w+)\s+(.*)|', $doc_comment,
                              $matches, PREG_SET_ORDER))
            {
                $this->xsdTypes[$operationName]["In"] = array();
                foreach($matches as $match)
                {
                    $j++;
                    $this->createdTypes[$match[3]] = 1;
                    $this->phpMapArry[$j] = $match[3];

                    if($match[2] == "object")
                    {
                        $releventType = $match[3];
                    }
                    else
                    {
                        $k++;
                        $releventType = $this->checkValidTypes($j, $k);
                    } 
                    $this->xsdTypes[$operationName]["In"][$match[4]] = array("type"=>$releventType,
                                                                             "array" => $match[1],
                                                                             "object"=> $match[2]);

                    
                    $this->operations[$operationName][self::WS_OPERATION_INPUT_TAG][] =
                        array(self::WS_OPERATION_NAME_TAG => $match[4],
                              self::WS_OPERATION_TYPE_TAG => $releventType,
                              "array" => $match[1],
                              "object"=> $match[2]);

                }

            }

            if(preg_match('|@return\s+(?:(array)\s+of\s+)?(?:(object)\s+)?(\w+)\s+\$(\w+)\s+(.*)|', $doc_comment, $match_r))
            {
                $j++;
                $this->phpMapArry[$j] = $match_r[3];

                if($match[2] == "object")
                {
                    $returnType = $match_r[3];
                }
                else
                {
                    $k++;
                    $returnType = $this->checkValidTypes($j, $k);
                } 

                $this->xsdTypes[$operationName]["Out"][$match_r[4]] = array("type"=>$returnType,
                                                                             "array" => $match_r[1],
                                                                             "object"=> $match_r[2]);

                $this->createdTypes[$match_r[3]] = 1;


                $this->operations[$operationName][self::WS_OPERATION_OUTPUT_TAG][] =
                    array(self::WS_OPERATION_NAME_TAG => self::WS_OPERATION_RET_TAG,
                          self::WS_OPERATION_TYPE_TAG => $returnType,
                          "array" => $match_r[1],
                          "object"=> $match_r[2]);

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
        if(array_key_exists($keyXsdIndex, $this->xsdMapArry)) {
            $keyPHPArray = $this->xsdMapArry[$keyXsdIndex];
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

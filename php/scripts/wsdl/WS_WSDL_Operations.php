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
    function __construct($operations)
    {
        foreach($operations as $i=>$value)
        {
            $this->operationName = $operations[$i];
            $this->xsdMapArry[$this->operationName] = array();
            $this->setOperations($this->operationName);
        }
    }

    private function setOperations($operationName)
    {
        $this->operations[$operationName][self::WS_OPERATION_INPUT_TAG] = array();
        $this->operations[$operationName][self::WS_OPERATION_OUTPUT_TAG] = array();
        $operation = new ReflectionFunction($operationName);
        $doc_comment = $operation->getDocComment();

        if (!$doc_comment)
        {
            $this->xsdTypes[$operationName]["In"] = array();

            foreach($operation->getParameters() as $i => $param)
            {
                $match[2] = $param->getName();
                $match[1] = "any";
                $this->xsdTypes[$operationName]["In"][$match[2]] = "any";


                $this->createdTypes[$match[1]] = 2;
                $this->operations[$operationName][self::WS_OPERATION_INPUT_TAG][] =
                    array(self::WS_OPERATION_NAME_TAG => $match[2],
                          self::WS_OPERATION_TYPE_TAG => $match[1]);
            }


            $this->xsdTypes[$operationName]["Out"]["returnVal"] = "any";

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
            if(preg_match_all('|@param\s+(?:object\s+)?(\w+)\s+\$(\w+)\s+(.*)|', $doc_comment,
                              $matches, PREG_SET_ORDER))
            {
                $this->xsdTypes[$operationName]["In"] = array();
                foreach($matches as $match)
                {
                    $j++;
                    $this->createdTypes[$match[1]] = 1;
                    $this->phpMapArry[$j] = $match[1];

                    $relavantType = $this->checkValidTypes($j);
                    $this->xsdTypes[$operationName]["In"][$match[2]] = $relavantType;

                    $this->operations[$operationName][self::WS_OPERATION_INPUT_TAG][] =
                        array(self::WS_OPERATION_NAME_TAG => $match[2],
                              self::WS_OPERATION_TYPE_TAG => $relavantType);

                }

            }

            if(preg_match('|@return\s+(?:object\s+)?(\w+)\s+\$(\w+)\s+(.*)|', $doc_comment, $match_r))
            {
                $j++;
                $this->phpMapArry[$j] = $match_r[1];
                $returnType = $this->checkValidTypes($j);
                $this->xsdTypes[$operationName]["Out"][$match_r[2]] = $returnType;

                $this->createdTypes[$match_r[1]] = 1;
                $this->operations[$operationName][self::WS_OPERATION_OUTPUT_TAG][] =
                    array(self::WS_OPERATION_NAME_TAG => self::WS_OPERATION_RET_TAG,
                          self::WS_OPERATION_TYPE_TAG => $returnType);
            }
        }
    }
    /**
     * check if the xsd type and php types are mathched if not a log
     *is written
     *@param string $keyIndex 
     */
    function checkValidTypes($keyIndex)
    {
        $keyPHPArray = $this->xsdMapArry[$keyIndex];
        $PHPType = $this->phpMapArry[$keyIndex];
        if ($PHPType == self::$mappingTable[$keyPHPArray])
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
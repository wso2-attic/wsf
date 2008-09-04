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
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

require_once("wso2/DataServices/DataService.php");
require_once("constants.php");

// database configuration
$config = array(
	"db" => "mysql",
	"username" => DB_USERNAME,
    "password" => DB_PASSWORD,
    "dbname" => "ds",
    "dbhost" => "localhost");

// the input format array(param_name => SQL_type)
$inputFormat = array("lastName" => "STRING", "firstName" => "STRING");

// the output format (visit the API from http://wso2.org/wiki/display/wsfphp/API+for+Data+Services+Revised)
$outputFormat = array("resultElement" => "customer-addresse",
					  "rowElement" => "customer-address",
					  "elements" => array(
                            "contactlastname" => "CONTACTLASTNAME",
                            "contactfirstname" => "CONTACTFIRSTNAME",
                            "addressline1" => "ADDRESSLINE1",
                            "addressline2" => "ADDRESSLINE2",
                            "city" => "CITY",
                            "state" => "STATE",
                            "postalcode" => "POSTALCODE",
                            "country" => "COUNTRY"),
                        "attributes" => array(
                            "customernumber" => "CUSTOMERNUMBER"),
                        "elementsOrder" => array("customernumber", "contactfirstname", "contactlastname",
                                        "addressline1", "addressline2", "city", "state", "postalcode", "country")
                        );

// the sql to execute
$sql = "select CUSTOMERNUMBER, CONTACTLASTNAME, CONTACTFIRSTNAME, ADDRESSLINE1, ADDRESSLINE2, CITY, STATE, POSTALCODE, COUNTRY from Customers where CONTACTLASTNAME = ? and CONTACTFIRSTNAME = ?";

// operations are consists of inputFormat (optional), outputFormat(required), sql(sql), input_mapping(optional)
$operations = array("customerAddress" =>array("inputFormat" => $inputFormat, "outputFormat" => $outputFormat, "sql" => $sql));
$my_data_service = new DataService(array("config" => $config,"operations" => $operations, "serviceName" => "CustomerAddress"));

$my_data_service->reply();
?>

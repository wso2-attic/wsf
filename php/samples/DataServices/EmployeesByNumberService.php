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

// database configurations
$config = array(
	  "db" => "mysql",
	  "username" =>DB_USERNAME,
	  "password" => DB_PASSWORD,
	  "dbname" =>"ds",
	  "dbhost" =>"localhost");

// input format param_name=> SQL_TYPE map
$inputFormat = array("employeeByNumber" => "INT");

// output format, for more information please visit
// http://wso2.org/wiki/display/wsfphp/API+for+Data+Services+Revised
$outputFormat = array("resultElement" => "employees",
                      "rowElement" => "employee",
                      "elements" => array("last-name" => "lastName",
                                          "first-name" => "firstName",
                                          "email" => "email"));
// the sql query to execute
$sql = "select lastName,firstName,email from Employees where employeeNumber=?";

// operations array
$operations = array("employeesByNumber" =>array("inputFormat" => $inputFormat, "outputFormat" => $outputFormat, "sql" => $sql));

$my_data_service = new DataService(array("config" => $config,"operations" => $operations));
$my_data_service->reply();
?>

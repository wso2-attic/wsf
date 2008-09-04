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
	  "username" => DB_USERNAME,
	  "password" => DB_PASSWORD,
	  "dbname" => "ds",
	  "dbhost" => "localhost");

// output format, refer to the API from http://wso2.org/wiki/display/wsfphp/API+for+Data+Services+Revised
$outputFormat = array("resultElement" => "customers",
                      "rowElement" => "customer",
                      "elements" => array(
                            "customer-name" => "customerName",
                            "contact-last-name" => "contactLastName",
                            "contact-first-name" => "contactFirstName",
                            "phone" => "phone",
                            "city" => "city",
                            "country" => "country"));

// sql
$sql = "select  customerName,contactLastName, contactFirstName,phone,city,country from Customers where city = 'Boston' and country = 'USA'";

// operations are consist of inputFormat (optional), outputFormat(required), sql(sql), input_mapping(optional)
$operations = array("customersInBoston" =>array("outputFormat" => $outputFormat, "sql" => $sql));

$my_data_service = new DataService(array("config" => $config,"operations" => $operations));

$my_data_service->reply();
?>

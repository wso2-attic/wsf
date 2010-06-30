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

require_once("constants.php");
require_once("wso2/DataServices/DataService.php");

// database configuraitons
$config = array(
	  "db" => "mysql",
	  "username" => DB_USERNAME,
	  "password" => DB_PASSWORD,
	  "dbname" => "ds",
	  "dbhost" => "localhost");

// input format array(param_name => SQL_TYPE)
$inputFormat = array("customerNumber" => "INT");

// output format, plese check the API from http://wso2.org/wiki/display/wsfphp/API+for+Data+Services+Revised
$outputFormat = array("resultElement" => "Orders",
                      "rowElement" => "Order",
                      "elements" => array( "order-number" => "OrderNumber",
                                           "order-date" => "OrderDate",
                                           "status" => "status"));
// sql statment to execute
$sql="select o.OrderNumber, o.OrderDate, o.status from Customers c, Orders o where c.customerNumber=o.customerNumber and c.customerNumber=?";

// operations is consist of inputFormat (optional), outputFormat(required), sql(sql), input_mapping(optional)
$operations = array("customerOrders" => array("inputFormat" => $inputFormat, "outputFormat" => $outputFormat, "sql" => $sql));

// actions
$actions = array("http://wso2.org/samples/dataservices/customerOrders" => "customerOrders");

// Set up security options
$policy_file = file_get_contents("policy.xml");
$policy = new WSPolicy($policy_file);
$security_token = new WSSecurityToken(array("user" => "Raigama",
                                            "password" => "RaigamaPW",
                                            "passwordType" => "Digest"));

$my_data_service = new DataService(array("config" => $config,
                                         "operations" => $operations,
                                         "actions" => $actions,
                                         "useWSA" => TRUE,
                                         "policy" => $policy,
                                         "securityToken" => $security_token));
$my_data_service->reply();
?>

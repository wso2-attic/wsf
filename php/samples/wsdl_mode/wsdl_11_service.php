<?php
/*
 * Copyright 2005,2008 WSO2, Inc. http://wso2.com
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

function QueryPurchaseOrderFunction($pro_name, $quantity, $date, $orderNo) {


	$return_value = array("shipTo" => array("name" => "Jane Smith",
											"street" => "YorkStreet",
											"city" => "colombo", 
											"state" => "Sri Lanka", 
											"zip" => 32343),
	
                          "billTo" => array("name" => "John Smith", 
                          					"street" => "Maple Street", 
                          					"city" => "LA", "state" => "USA", 
                          					"zip" => 55432),
	
                          "product" => array("productId" => 2344, 
                          					"shippingDate" => date(20080101), 
                          					"status" => TRUE));
	return $return_value;
}

$operations = array("QueryPurchaseOrder" => "QueryPurchaseOrderFunction");

$svr = new WSService(array("wsdl"=>"sample_wsdl_11.wsdl",
                           "operations" => $operations));

$svr->reply();

?>

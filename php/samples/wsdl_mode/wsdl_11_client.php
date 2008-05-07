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

try {

    $client = new WSClient(array("wsdl"=>"sample_wsdl_11.wsdl",
                                 ));

    $proxy = $client->getProxy();	

    $return_val =  $proxy->QueryPurchaseOrder(array("productName"=> "Testing",
                                             "quantity" => 234,
                                             "date" => "2003-12-34",
                                             "orderNo" => 345));  
      
    printf("<strong>Shipping address </strong><br/>");
    printf("Name : %s <br/>", $return_val["shipTo"]["name"]);
    printf("Street : %s <br/>", $return_val["shipTo"]["street"]);
    printf("City : %s <br/>", $return_val["shipTo"]["city"]);
    printf("State : %s <br/>", $return_val["shipTo"]["state"]);
    printf("Zip : %s <br/>", $return_val["shipTo"]["zip"]);
    
    printf("<br/><strong>Billing address </strong><br/>");
    printf("Name : %s <br/>", $return_val["billTo"]["name"]);
    printf("Street : %s <br/>", $return_val["billTo"]["street"]);
    printf("City : %s <br/>", $return_val["billTo"]["city"]);
    printf("State : %s <br/>", $return_val["billTo"]["state"]);
    printf("Zip : %s <br/>", $return_val["billTo"]["zip"]);
    
    printf("<br/><strong>Product info </strong><br/>");
    printf("Product ID : %s <br/>", $return_val["product"]["productId"]);
    printf("ShippingDate : %s <br/>", $return_val["product"]["shippingDate"]);
    printf("Status : %s <br/>", $return_val["product"]["status"]);
   

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

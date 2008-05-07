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

    $client = new WSClient(array("wsdl"=>"sample_wsdl_20.wsdl"));

    $proxy = $client->getProxy();	

    $return_val =  $proxy->GetPrice(array("ProductType"=> "Testing",
                                          "ItemNo" => 234));    
    printf("Price is : %s <br/>", $return_val["Price"]);

} catch (Exception $e) {
    if ($e instanceof WSFault) {
        printf("Soap Fault Reason: %s<br/>", $e->Reason);
        printf("Soap Fault Code: %s <br/>", $e->Code);
        
    } else {
        printf("Message = %s<br/>",$e->getMessage());
    }
  }
?>

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

    $client = new WSClient(array("wsdl" => "http://localhost/samples/wsdl_generation/rpc_service.php?wsdl"));

    $proxy = $client->getProxy();	
    
    $val = $proxy->purchaseOrder(array("count"=>10, "date"=>5));

    printf("The Total Price is: %s \n", $val["return"]);

} catch (Exception $e) {
    if ($e instanceof WSFault) {
        printf("Soap Fault Reason: %s\n", $e->Reason);
        printf("Soap Fault Code: %s \n", $e->Code);
        
    } else {
        printf("Message = %s\n",$e->getMessage());
    }
  }
?>

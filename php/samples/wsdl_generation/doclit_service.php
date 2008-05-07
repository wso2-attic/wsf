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

$item = array("abc" => 101.5, "wso2" => 250.50, "xyz" => 99.99);

/** BuyItem function
 * @param string $item_name of the item to buy
 * (maps to the xs:string XML schema type )
 * @param int $amount no of items to buy
 * (maps to the xs:nonNegativeInteger XML schema type)
 * @return float $price total price
 *(maps to the xs:double XML schema type )
 */
function getPriceFunction($item_name ,$amount)
{
    global $item;
    if ($item_name && $amount){
        if(isset($item[$item_name])){
            return array("price" => ($item[$item_name] * $amount));
        }
        else
            return NULL;
    }
    return array("price" => 200043);
}


$operations = array("getPrice"=>"getPriceFunction");
$opParams = array("getPriceFunction"=>"MIXED");

$svr = new WSService(array("operations"=>$operations, 
			   "bindingStyle"=>"doclit",
		   	   "opParams"=>$opParams));


$svr->reply();


?>

    

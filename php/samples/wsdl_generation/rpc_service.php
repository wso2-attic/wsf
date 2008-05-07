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


/** The  purchaseOrder function
 * @param int $count the number of widgets to buy
 * (maps to the xs:nonNegativeInteger XML schema type )
 * @param string $date the date those items were sold
 * (maps to the xs:gDay XML schema type)
 * @return string $t time for buying it
 * (maps to the xs:QName XML schema type )
 */
function purchaseOrder($x,$y)
{
    return array("return"=>$x*$y);
}


$operations = array("purchaseOrder"=>"purchaseOrder");
$opParams = array("purchaseOrder"=>"MIXED");
$svr = new WSService(array("operations"=>$operations, "bindingStyle"=>"rpc-enc", "opParams" => $opParams));


$svr->reply();


?>

    

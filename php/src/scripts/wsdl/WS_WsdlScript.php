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
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


function ws_generate_wsdl($include_location, $service_name, $fn_arry,
			  $binding_style, $wsdl_version, $request_uri)
{
    include $include_location;
    
    $Binding_style = NULL;


    if ($binding_style == "rpc-enc")
    {
	$Binding_style = "rpc";
    }
    else if ($binding_style == "rpc")
    {
	$Binding_style = "rpc";
    }
    
    else if ($binding_style == "doc-lit")
    {
	$Binding_style = "doc-lit";
    }
    else
    {
	echo "Wrong binding style\n";
	exit(0);
    }

    
    $wsdl = new WS_WsdlCreator($fn_arry ,$service_name, $request_uri, $Binding_style, 'http://www.wso2.org/php/', $wsdl_version);
    $wsdl_out = $wsdl->WS_WsdlOut();


   return $wsdl_out; 
   
    
}

?>
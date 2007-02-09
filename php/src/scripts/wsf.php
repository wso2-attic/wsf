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

/** The version of this WSO2 WSF for PHP file */
define('WSF_VERSION', '1.0.0');

function ws_request($payload, $options = array(NULL))
{
    $payloadString = $payload;
    if ($payload instanceof SimpleXMLElement)
    {
        $payloadString = $payload->asXML();
    }
    else if ($payload instanceof domDocument)
    {
        $payloadString = $payload->saveXML();
    }

    try
    {
        $requestMessage = $payload;
        if (!($payload instanceof WSMessage))
        {
            $requestMessage = new WSMessage($payloadString);
        }

        $client = new WSClient($options);

        $resMessage = $client->request($requestMessage);

        return $resMessage;

    }
    catch (Exception $e)
    {
        throw $e;
    }
}

function ws_send($payload, $options = array(NULL))
{
    $payloadString = $payload;
    if ($payload instanceof SimpleXMLElement)
    {
        $payloadString = $payload->asXML();
    }
    else if ($payload instanceof domDocument)
    {
        $payloadString = $payload->saveXML();
    }

    try
    {
        $requestMessage = $payload;
        if (!($payload instanceof WSMessage))
        {
            $requestMessage = new WSMessage($payloadString);
        }

        $client = new WSClient($options);

        $client->send($requestMessage);

        return;

    }
    catch (Exception $e)
    {
        throw $e;
    }
}


function ws_reply($options)
{

    $svr = new WSService($options);

    $svr->reply();
}

function ws_generate_wsdl($include_location, $service_name, $fn_arry,
                          $binding_style, $wsdl_version, $request_uri)
{
    require_once($include_location);

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

    $namespace = "http://www.wso2.org/php";

    $wsdl = new WS_WSDL_Creator($fn_arry ,$service_name, $request_uri,
                               $Binding_style,$namespace, $wsdl_version);
    $wsdl_out = $wsdl->WS_WSDL_Out();


    return $wsdl_out;


}





?>

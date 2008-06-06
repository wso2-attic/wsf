<?php
/*
 * Copyright (c) 2005-2008 WSO2, Inc. http://wso2.com
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
define('WSF_VERSION', '1.2.1');

function ws_request($payload, $options = array(NULL))
{
    $payloadString = $payload;
    
    if ($payload instanceof domDocument)
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
    
    if ($payload instanceof domDocument)
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

function ws_generate_wsdl($service_name, $fn_arry, $class_arry, $binding_style, 
                          $wsdl_version, $request_uri, $op_arry,
                          $classmap = NULL, $annotations = NULL)
{
    require_once("wsdl/WS_WSDL_Creator.php");

    require_once('dynamic_invocation/wsf_wsdl_consts.php');
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "class map:".print_r($classmap, TRUE));
    ws_log_write(__FILE__, __LINE__, WSF_LOG_DEBUG, "class arry:".print_r($class_arry, TRUE));

    $Binding_style = NULL;

    if ($binding_style == "rpc-enc")
    {
        $Binding_style = "rpc";
    }
    else if ($binding_style == "rpc")
    {
        $Binding_style = "rpc";
    }

    else if ($binding_style == "doclit")
    {
        $Binding_style = "doclit";
    }
    else
    {
        echo "Wrong binding style\n";
        exit(0);
    }

    $namespace = "http://www.wso2.org/php";

    /* obtain the namespace form the first class name */
    $first_class_name = "";
    if($class_arry && is_array($class_arry)) {
        foreach($class_arry as $class_name => $value) {
            $first_class_name = $class_name;
        }
    }

    if($first_class_name) {
        try {
            $class = new ReflectionClass($first_class_name);
            $class_comment = $class->getDocComment();
    
            if(preg_match_all('|@namespace\s+([^\s]+).*|', $class_comment, $matches, PREG_SET_ORDER))
            {
                $namespace = $matches[0][1];
            }

        }
        catch(Exception $e) {
            //if the class doesn't exist, we just continue to use the default namespace
        }
    }


    /* Since WSDL 2.0 logic seems very buggy, better to use WSDL converter, should move this code to C level */
    if(strcmp($wsdl_version ,"wsdl2.0") == 0) {
      $wsdl_version = "wsdl1.1";
      $wsdl = new WS_WSDL_Creator($fn_arry, $class_arry, $service_name, $request_uri,
				  $Binding_style,$namespace, $wsdl_version, $op_arry, $classmap, $annotations);
      $wsdl_out = $wsdl->WS_WSDL_Out();
      $converted_wsdl = convert_to_wsdl20($wsdl_out);
      return $converted_wsdl;
    }
    else
    {
      $wsdl = new WS_WSDL_Creator($fn_arry, $class_arry, $service_name, $request_uri,
				  $Binding_style,$namespace, $wsdl_version, $op_arry, $classmap, $annotations);
      $wsdl_out = $wsdl->WS_WSDL_Out();
      return $wsdl_out;
    }
}


function convert_to_wsdl20($wsdl_out)
{
  $wsdl_dom = new DomDocument();
  $xslt_wsdl_20_dom = new DOMDocument();
  $xslt_11_to_20_dom = new DOMDocument();
  $xslt_11_to_20_dom->preserveWhiteSpace = false;
  $xslt = new XSLTProcessor();

  
  $xslt_str = file_get_contents("dynamic_invocation/xslt/wsdl11to20.xsl10.xsl", TRUE);
  if(!($xslt_wsdl_20_dom->loadXML($xslt_str)))
    error_log("WSDL can not be converted", 0);
  
  $xslt->importStyleSheet($xslt_wsdl_20_dom);
  $wsdl_dom->loadXML($wsdl_out);
  $xslt_11_to_20_dom->loadXML($xslt->transformToXML($wsdl_dom));
  $doc_ele = $xslt_11_to_20_dom->documentElement;
  foreach($doc_ele->childNodes as $child) {
      if($child->nodeType == XML_COMMENT_NODE ) {
         $old_child = $doc_ele->removeChild($child); 
          //echo "asdasd";
      }
  }
  
  return $xslt_11_to_20_dom->saveXML();
}


?>

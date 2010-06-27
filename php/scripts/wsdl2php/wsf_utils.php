<?php
/*
 * Copyright (c) 2005-2010 WSO2, Inc. http://wso2.com
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
 
/**
 * Function to precess command line arguments.  
 * $argv array of command line arguments
 * returns array with broken down arguments.
 * e.g. for "php argv.php one -h -b --c=test"
 * returns:
 * Array
 * (
 *   [input] => Array
 *       (
 *             [0] => argv.php
 *             [1] => one
 *       )
 *     [h] => true
 *     [b] => true
 *     [c] => test
 * )
 */
function wsf_arguments($argv) {
    $_ARG = array ();
    foreach ($argv as $arg) {
        if (preg_match('/--([^=]+)=(.*)/', $arg, $reg)) {
            $_ARG[$reg[1]] = $reg[2];
        }
        elseif (preg_match('/^-([a-zA-Z0-9])/', $arg, $reg)) {
            $_ARG[$reg[1]] = 'true';
        } else {
            $_ARG['input'][] = $arg;
        }
    }
    return $_ARG;
}

/**
 * Function to write 'sig model' for a given wsdl   
 * $wsdl_location location of the WSDL
 * returns none
 */
function wsf_wsdl2sig($wsdl_location) {

    require_once ('dynamic_invocation/wsf_wsdl_consts.php');
    require_once ('dynamic_invocation/wsf_wsdl_util.php');

    global $written_classes;
    global $operations;
    
    $code = "";

    $wsdl_dom = new DomDocument();
    $sig_model_dom = new DOMDocument();

    $xslt_location = "./xslt/";

    $sig_model_dom->preserveWhiteSpace = false;
    $wsdl_dom->preserveWhiteSpace = false;

    if (!$wsdl_location) {
        echo "WSDL is not found";
        return NULL;
    }
    $is_multiple_interfaces = FALSE;

    // load WSDL as DOM
    if (!$wsdl_dom->load($wsdl_location)) {
        echo "WSDL could not be loaded.";
        return NULL;
    }

    $wsdl_dom->preserveWhiteSpace = false;

    // changing code for processing mutiple port types in wsdl 1.1 
    $is_multiple_interfaces = wsf_is_mutiple_port_types($wsdl_dom);

    if ($is_multiple_interfaces == FALSE) {
        $wsdl_dom = wsf_get_wsdl_dom($wsdl_dom, $xslt_location);
        if (!$wsdl_dom) {
            echo "Error creating WSDL DOM document";
            return NULL;
        }
        $wsdl_dom = wsf_clear_wsdl_imports($wsdl_dom);
        $sig_model_dom = wsf_get_sig_model_dom($wsdl_dom, $xslt_location);
    } else {
        $wsdl_dom = wsf_clear_wsdl_imports($wsdl_dom);
        $wsdl_dom = wsf_get_wsdl_dom($wsdl_dom, $xslt_location);
        $sig_model_dom = wsf_process_multiple_interfaces($wsdl_dom, $sig_model_dom, $xslt_location);
    }

    if (!$sig_model_dom) {
        echo "Error creating intermediate service operations signature model";
        return NULL;
    }

    echo $sig_model_dom->saveXML();
}

?>

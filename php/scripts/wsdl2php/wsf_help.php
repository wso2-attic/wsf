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
 * Function to print help for wsdl2php command line options.  
 * returns nothing
 */
function wsf_wsdl2php_print_help() {
	echo "Usage: php wsdl2php.php [-s] <wsdl>\n";
	echo "    wsdl - URL or path to WSDL file\n\n";
	echo "Options:\n";
	echo "    -s        Generate code for service.\n";
	echo "              By default this is false, meaning code for client will be generated.\n";
}

?>
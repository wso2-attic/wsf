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
		if (ereg('--([^=]+)=(.*)', $arg, $reg)) {
			$_ARG[$reg[1]] = $reg[2];
		}
		elseif (ereg('^-([a-zA-Z0-9])', $arg, $reg)) {
			$_ARG[$reg[1]] = 'true';
		} else {
			$_ARG['input'][] = $arg;
		}
	}
	return $_ARG;
}

?>
<?php
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
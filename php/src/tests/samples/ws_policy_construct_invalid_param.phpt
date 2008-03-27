--TEST--
Test for ws_policy_construct_invalid_param sample
--FILE--
<?php
$policy = new WSPolicy();
?>
--EXPECTF--
Warning: WSPolicy::__construct() expects at least 1 parameter, 0 given in %sws_policy_construct_invalid_param.php on line %d

Fatal error: WSPolicy::__construct(): Invalid parameters in %sws_policy_construct_invalid_param.php on line %d


--TEST--
Test for ws_security_token_invalid_param sample
--FILE--
<?php
/** WSsecurityToken takes an array of options */
$sec_token = new WSSecurityToken(10);
?>
--EXPECTF--
Warning: WSSecurityToken::__construct() expects parameter 1 to be array, integer given in %sws_security_token_invalid_param.php on line %d

Fatal error: WSSecurityToken::__construct(): An array should be passed here in %sws_security_token_invalid_param.php on line %d



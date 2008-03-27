--TEST--
Test for ws_message_consturctor_invalid_param sample
--FILE--
<?php
	$message = new WSMessage();
    /** WSMessage constructor should have at least the payload string parameter */
?>
--EXPECTF--
Warning: WSMessage::__construct() expects at least 1 parameter, 0 given in %sws_message_consturctor_invalid_param.php on line %d

Fatal error: WSMessage::__construct(): Invalid parameters in %sws_message_consturctor_invalid_param.php on line %d
--TEST--
Test for ws_fault_constructor_IS_ARRAY sample
--FILE--

<?php
$fault = new WSFault(array("Sender", "Sender1"), "Testing WSFault");
?>

--EXPECTF--
Fatal error: WSFault::__construct(): Incorrect Fault Code, Code must be one of Client, Server, VersionMismatch,MustUnderstand,DataEncodingUnknown,Sender, Receiver in %sws_fault_constructor_IS_ARRAY.php on line %d

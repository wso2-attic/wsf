--TEST--
Test for ws_fault_constructor_IS_ARRAY_invalid_faultcode sample
--FILE--

<?php

try{
     new WSFault(array(10,"Sender1"), "Testing WSFault");
} catch (Exception $e) {
	if ($e instanceof WSFault) {
        printf("Soap Fault Code: %s \n", $e->Code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>

--EXPECTF--
Fatal error: WSFault::__construct(): Fault Code and Fault Code namespace must be strings in %sws_fault_constructor_IS_ARRAY_invalid_faultcode.php on line %d

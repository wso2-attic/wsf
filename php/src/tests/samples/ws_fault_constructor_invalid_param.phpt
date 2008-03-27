--TEST--
Test for ws_fault_constructor_invalid_param sample
--FILE--

<?php
try {

   throw new WSFault("Code" );
    
} catch (Exception $e) {
	if ($e instanceof WSFault) {
        printf("Soap Fault Code: %s \n", $e->Code);
	} else {
		printf("Message = %s\n",$e->getMessage());
	}
}
?>
--EXPECTF--
Warning: WSFault::__construct() expects at least 2 parameters, 1 given in %sws_fault_constructor_invalid_param.php on line %d

Fatal error: WSFault::__construct(): Invalid parameters in %sws_fault_constructor_invalid_param.php on line %d

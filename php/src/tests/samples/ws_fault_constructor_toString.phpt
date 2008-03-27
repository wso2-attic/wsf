--TEST--
Test for ws_fault_constructor_toString sample
--FILE--

<?php
    
$toStringValue =  new WSFault("Sender", "Testing WSFault", "Fault Role", "Fault Detail");
echo $toStringValue->__toString();

?>
--EXPECT--
WS FAULT exception: [Sender] Testing WSFault Fault Detail
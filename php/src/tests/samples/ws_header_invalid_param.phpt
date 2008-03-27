--TEST--
Test for ws_header_invalid_param sample
--FILE--
<?php
 new WSHeader("http://test1.org","header2", "value2", true, 2)
?>

--EXPECTF--
Warning: WSHeader::__construct() expects exactly 1 parameter, 5 given in %sws_header_invalid_param.php on line %d

Fatal error: WSHeader::__construct(): Invalid parameters in %sws_header_invalid_param.php on line %d

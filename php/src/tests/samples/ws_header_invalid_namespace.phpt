--TEST--
Test for ws_header_invalid_namespace sample
--FILE--
<?php
$child = new WSHeader(array("ns"=>"", "name"=>"header2","data"=>"value2"));
?>

--EXPECTF--
Fatal error: WSHeader::__construct(): Namespace should not be empty in %sws_header_invalid_namespace.php on line %d
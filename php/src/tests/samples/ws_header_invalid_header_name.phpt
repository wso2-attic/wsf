--TEST--
Test for ws_header_invalid_header_name sample
--FILE--
<?php
$child = new WSHeader(array("ns"=>"http://test.org", "name"=>"","data"=>"value2"));
?>

--EXPECTF--
Fatal error: WSHeader::__construct(): A Soap Header should have a non empty localname in %sws_header_invalid_header_name.php on line %d

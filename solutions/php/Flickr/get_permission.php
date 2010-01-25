<?php
require_once("FlickrClient.php");
session_start();
ob_start();
$api_key=$_SESSION["key"];
$shared=$_SESSION["shared"];
$options=array("photo_id"=>$photo_id);
$flicker_client=new FlickrClient($api_key);
$res_frob = $flicker_client->FlickrAuthGetFrob();
$special = array('&lt;','&quot;','&gt;');
$replace=array('<','"','>');
$str = str_replace($special,$replace,$res_frob);
$xml=<<<XML
<?xml version="1.0"?>
$str
XML;
file_put_contents("/tmp/xml1.txt",$xml);
$XML=new SimpleXMLElement($xml);
$frob=(string)$XML->frob;
file_put_contents("/tmp/f2.txt",$frob);
$_SESSION["frob"]=$frob;
ob_end_flush();

/*
complete authontication
*/
$perms="write";
$signature=md5($shared.'api_key'.$api_key.'frob'.$frob.'perms'.$perms);
$url="http://www.flickr.com/services/auth/?api_key=$api_key&perms=$perms&frob=$frob&api_sig=$signature";
header("Location:$url");
exit();



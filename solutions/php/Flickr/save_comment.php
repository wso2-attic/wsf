<?php
require_once("FlickrClient.php");
session_start();
ob_start();
$api_key=$_SESSION["key"];
$shared=$_SESSION["shared"];
$frob=$_SESSION["frob"];
$token=$_SESSION["token"];
file_put_contents("/tmp/toc.txt",$token);
$photo_id=$_GET["id"];
file_put_contents("/tmp/photoid.txt",$photo_id);
$url=$_GET["url"];
$title=$_GET["title"];
ob_end_flush();
$flicker_client=new FlickrClient($api_key);
if(isset($_POST['Submit']))
                      {
                        $comment=$_POST['comment'];
                        $res_comment= $flicker_client->FlickrPhotoAddComments($photo_id,$comment,$token,$shared);
                      }
$special = array('&lt;','&quot;','&gt;');
$replace=array('<','"','>');
$string = str_replace($special,$replace,$res_comment);
$xml2=<<<XML
<?xml version="1.0"?>
$string
XML;
$XML=new SimpleXMLElement($xml2);
$comment=(string)$XML->comment['id'];
/*
*Add specific URL as location
*/
$relative_url="flickr_interface2.php?id=$photo_id&url=$url&title=$title&comment=$comment";
$location = ereg_replace( ' +', '%20', $location );
header("Location: http://".$_SERVER['HTTP_HOST'].dirname($_SERVER['PHP_SELF'])."/".$relative_url);
?>

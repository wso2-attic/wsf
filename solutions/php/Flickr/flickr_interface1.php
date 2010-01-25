<?php
require_once("FlickrClient.php");
session_start();
ob_start();
$api_key=$_SESSION["key"];
ob_end_flush();
$small_image=array();
$medium_image=array();
$large_image=array();
$id=array();
$flicker_client=new FlickrClient($api_key);
$res_xml = $flicker_client->GetPhotoRecent();
$special = array('&lt;','&quot;','&gt;');
$replace=array('<','"','>');
$str = str_replace($special,$replace,$res_xml);
$xml=<<<XML
<?xml version="1.0"?>
$str
XML;
file_put_contents("/tmp/xml.txt",$xml);
$XML=new SimpleXMLElement($xml);
if($XML && $XML->photos && $XML->photos->photo) {
foreach ($XML->photos->photo as $photo)
{
 $image_id=(string)$photo['id'];
 array_push($id,$image_id);
 $server_id=(string)$photo['server'];
 $farm_id=(string)$photo['farm'];
 $secret=(string)$photo['secret'];
 $medium_url="http://farm{$farm_id}.static.flickr.com/{$server_id}/{$image_id}_{$secret}_m.jpg";
 array_push($medium_image,$medium_url);
 $small_url="http://farm{$farm_id}.static.flickr.com/{$server_id}/{$image_id}_{$secret}_s.jpg";
 $thumbnail_url="http://farm{$farm_id}.static.flickr.com/{$server_id}/{$image_id}_{$secret}_t.jpg";
 array_push($small_image,$small_url);
 array_push($large_image,$thumbnail_url);
}
}
?>

<html>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1" />
<meta http-equiv="Content-Style-Type" content="text/css" />
<title>
Flickr photo site
</title>
<link rel="stylesheet" href="./assets/style/style1.css" type="text/css" media="screen" />
</head>
<body>
<div id="body_wrapper">
 <div id="container">
   <div id="page_header">
     <h1>Visit recent photos</h1>
      <p>search photo<form method="post" action="#"><input name="search_txt" type="text" value="<?php echo $search_txt;?>"/><input value="Go" name="Go" class="button" type="submit" /></form></p>
     <?php

      if(isset($_POST['Go']))
      {   
       $text=$_POST["search_txt"];
       $relative_url="search.php";
       header( "Location: http://".$_SERVER['HTTP_HOST'].dirname($_SERVER['PHP_SELF'])."/".$relative_url."?text=".$text);
       exit();
      }

     ?>

    </div>
    <div id="nav_menu">
                <ul>
		<li id="menu1"><a href="http://www.flickr.com/"><span>Flicker</span></a></li>
		<li id="menu2"><a href="http://wso2.org/"><span>WSO2</span></a></li>
		<li id="menu3"><a href="http://www.flickr.com/services/api/"><span>Services</span></a></li>
		<li id="menu4"><a href="http://www.flickr.com/services/api/keys/"><span>Get api key</span></a></li>
		<li id="menu5"><a href="#"><span>Contacts</span></a></li>
		<li id="menu6"><a href="#"><span>Links</span></a></li>
		</ul>

		<div class="clearthis">&nbsp;</div>
    </div>
      <div class="clearthis">&nbsp;</div>
        <div id="mix">
          <div class="content_header">
		<h1><span></span></h1>
	  </div>
        <div id="gallery">
                 <ul>
                       <?php
                        for($i=0;$i<sizeof($small_image);$i++){
                          echo"<li><a href=\"flickr_interface2.php?id=$id[$i]&url=$medium_image[$i]\"><img src=\"$small_image[$i]\" width=\"84\" height=\"76\" alt=\"Thumbnail 1 Caption\" /></a></li>";
                         }
                        ?>
			</ul>
        </div>
         <div class="clearthis">&nbsp;</div>
      </div>
    </div>
  </div>
<div id="page_footer"></div>
</body>
</html>

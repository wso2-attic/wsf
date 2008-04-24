<?php
require_once("FlickrClient.php");
session_start();
ob_start();
$api_key=$_SESSION["key"];
$method=$_SESSION["method"];
$photo_id=$_GET["id"];
$url=$_GET["url"];
$comment=$_GET["comment"];
ob_end_flush();
$options=array("photo_id"=>$photo_id);
$flicker_client=new FlickrClient($api_key);
$res_xml = $flicker_client->GetPhotoInfo($options);
$special = array('&lt;','&quot;','&gt;');
$replace=array('<','"','>');
$str = str_replace($special,$replace,$res_xml);
$xml=<<<XML
<?xml version="1.0"?>
$str
XML;
file_put_contents("/tmp/xml.txt",$xml);
$tags=array();
$XML=new SimpleXMLElement($xml);
$username=(string)$XML->photo->owner['username'];
$title=(string)$XML->photo->title;
$description=(string)$XML->photo->description;
$comments=(string)$XML->photo->comments;
foreach ($XML->photo->tags->tag as $tag)
{
  array_push($tags,$tag);
}
if($description==NULL){
  $description="-";
}
if($comments==NULL){
  $comments="not added";
}
if(empty($tags)){
  $tags[0]="no tags";
}
?>

<html>
<head>
<title>Flickr recent photos</title>
<link rel="stylesheet" href="./assets/style/style2.css" type="text/css" media="screen" />
<link rel="stylesheet" href="./assets/style/style1.css" type="text/css" media="screen" />
</head>
<body>
<div id="body_wrapper">
  <div id="container">
        <div id="page_header">
          <p><h1>&nbsp;Visit recent photos
        <h2>&nbsp;&nbsp;with Flickr web services</h2></h1></p>
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
                 <h1></h1>
               </div>
              <div id="page_menu">
                     <h2><?php echo"$title";?></h2><br />
                     <?php echo"<img src=\"$url\" height=\'220px\' width=\'220px\'>"; ?>
		 </div
              <div id="info_wrap">
                               <p><b>Owner:</b>&nbsp;<?php echo"$username";?></p>
                               <p><b>Description:</b>&nbsp;<?php echo"$description";?></p>
                               <p><b>Comments:</b>&nbsp;<?php echo"$comments";?></p>
                               <p><b>Tags:</b>
                              
                               <?php
                                for($i=0;$i<sizeof($tags);$i++)
                                {
                                 echo"$tags[$i],";
                                }
                              ?>

                          <br />
                          <br />
                              <?php
                              if($comment!=NULL)
                              {
                               echo"<font color=\"red\">New comment is added...</font>";
                              }
                             ?>
               </div>
                        <br />
                        <br />   
                        <div class="clearthis">&nbsp;</div>
                        <div class="clearthis">&nbsp;</div>
	       	    </div>
                  </div>
	        </div>
              <div id="page_footer">
              <br />
              <div id="link">
                          <ul>
                             <li><a href="comments.php?id=<?php echo"$photo_id";?>&url=<?php echo"$url";?>&title=<?php echo"$title";?>"><b>Add comments...</b></a>&nbsp;&nbsp;&nbsp;
                          </ul>
              </div>
              <br />
              <br />
              <div id="link">
        </div>
           <br />
           <br />
           <br />
            <a href="flickr_interface1.php">Search photos</a>     
        </div>
          </div>
</body>
</html>

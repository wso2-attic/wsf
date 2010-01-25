<?php
require_once("FlickrClient.php");
session_start();
ob_start();
$api_key=$_SESSION["key"];
$shared=$_SESSION["shared"];
$method=$_SESSION["method"];
$photo_id=$_GET["id"];
$url=$_GET["url"];
$title=$_GET["title"];
ob_end_flush();
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
      <p><h1>Visit recent photos
        <h2>with Flickr web services</h2></h1></p>
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
                       <p><b>Step 1</b></p>
                       <p>Note:Please open this link in a new tab.(right click on link and select 'Open Link in new tab). Then see the authontication notice.Go to second step.
                       <p><a href="get_permission.php?id=<?php echo"$photo_id";?>&url=<?php echo"$url";?>&title=<?php echo"$title";?>">Get Permissions </a></p>
                       <br>
                       <p><b>Step 2</b></p><br>
                       <p><a href="add_comments.php?id=<?php echo"$photo_id";?>&url=<?php echo"$url";?>&title=<?php echo"$title"?>">Add Comments</a></p>
                       <br>
                       <br>
                       <br>
                       <br />
                       <br />   
                       
			<div class="clearthis">&nbsp;</div>
			<div class="clearthis">&nbsp;</div>
	      	</div>
             </div>
        </div>

	<div id="page_footer">
        <br />
        <br />       
        <a href="flickr_interface1.php">Search photos</a>     
	</div>
     </div>
</body>
</html>

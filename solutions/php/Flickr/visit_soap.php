<?php
require_once("FlickrClient.php");
session_start();
ob_start();
 $api_key=$_SESSION["key"];
 $method=$_SESSION["method"];
ob_end_flush();
?>
<html>
<head>
<link href="./assets/style/css.css" rel="stylesheet" type="text/css" />
<title>Flickr Client</title>
</head>
<body>
<h2><b><?php echo "$method"?><b></h2>
<h3>To see the demo enter the required fields</h3>
<br>
<form method="post" action="#">
   
   <div class="form1">
      <b>photo id(required)</b><br>
       <p>
         <div class="id" style="">
              <input name="photo_id" type="text" value="<?php echo $photo_id?>"/>
         </div>
        </p>
    </div>
<br>
    <div class="form3">
       <b>secret(optional)</b><br>
         <p>
           <div class="id" style="">
               <input name="secret" type="text" value="<?php echo $secret?>"/>
          </div>
         </p>
    </div>
<br>
<br>
 <input value="Submit" class="button" type="submit" />
</form>
<br>

<h4><b>Response<b></h4>
<?php
  $photo_id=$_POST['photo_id'];
  $secret=$POST['secret'];
  if($secret==NULL)
  {
    $options=array("photo_id"=>$photo_id);
  }
  else
  {
    $options=array("photo_id"=>$photo_id,"secret"=>$secret);
  }
 
  $flicker_client=new FlickrClient($api_key);

  switch($method)
  {
  case 'flickr.photos.getInfo':
  $photo_info = $flicker_client->GetPhotoInfo($options);
  break;

  case 'flickr.photos.getFavorites':
  $photo_info = $flicker_client->GetPhotoFevorite($options);
  break;

  case 'flickr.photos.getPerms':
  $photo_info = $flicker_client->GetPhotoPerms($options);
  break;

  case 'flickr.photos.getRecent':
  $photo_info = $flicker_client->GetPhotoRecent;
  break;

  case 'flickr.photos.getSizes':
  $photo_info = $flicker_client->GetPhotoSizes($options);
  break;

  }

  echo "<textarea name=\"res\" cols=\"100\" rows=\"20\" value=$photo_info></textarea>";
?>
<br>
<a href="flickr_interface1.php">Back to visit Photos</a>
<br>
<a href="soap_interface.php">Back to visit another SOAP</a>
</body>
</html>


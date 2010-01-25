<?php

require_once("defines.php");
require_once(REGISTRY_PATH. "RemoteRegistry.php");

session_start();

$username_logined = $_SESSION["wsf_php_demo_site_username"];

$username = $_POST["username"];
$password = $_POST["input_password"];
$confirm_password = $_POST["confirm_password"];
$friendly_name = $_POST["friendly_name"];

$real_image_code = $_POST["real_image_code"];
$image_code = $_POST["image_code"];

$dont_validate=$_POST["dont_validate"];

if($dont_validate != "TRUE")
{
	if(isset($username) && empty($username))
	{
		$registration_failed = TRUE;
		$registration_message = "Registration Failed, You should provide the Username!";
	}
	else if(isset($password) && empty($password))
	{
		$registration_failed = TRUE;
		$registration_message = "Registration Failed, Password should be provided!";
	}
	else if($password  != $confirm_password)
	{
		$registration_failed = TRUE;
		$registration_message = "Registration Failed, Passoword doesn't match!";
	}
	else if(isset($username) && $real_image_code != md5($image_code))
	{
		$registration_failed = TRUE;
		$registration_message = "You Image code is incorrect, Please correct it!";
	}
	else if($username !== NULL && !empty($username))
	{
		$rr = new RemoteRegistry(REGISTRY_ATOM_INTERFACE, ADMIN_USER, ADMIN_PASSWORD);
		$response = $rr->addUser($username, $password, $confirm_password, USER_ROLE, $friendly_name);
	
	    if($response == "200")
		{
			header("Location: http://" . $_SERVER['HTTP_HOST']
					 . dirname($_SERVER['PHP_SELF'])
					 . "/thanks.php");
		}
		else
		{
			$registration_failed = TRUE;
			$registration_message = "Registration Failed, Username already exist or entered fields are incorrect!";
		}
	}
}

/* to generate the image */

define("IMAGE_WIDTH", 200);
define("IMAGE_HEIGHT", 40);
define("IMAGE_QUALITY", 20);
define("IMAGE_LOOP", 10);
define("FONT_DIR", "font");
define("TEMP_DIR", "validation_image_tmp");

function generate_image()
{
    $image_loop_index = $_SESSION["wsf_php_demo_site_image_loop_index"];
    if($image_loop_index == NULL)
    {
    	$image_loop_index = 0;
    }

    $val_img = imagecreatetruecolor(IMAGE_WIDTH, IMAGE_HEIGHT);

    imagealphablending($val_img, 1);
    imagecolortransparent($val_img );

    // Allocate 2 colors to the image
    $white = imagecolorallocate($val_img, 255, 255, 255);
    $black = imagecolorallocate($val_img, 0, 0, 0);

    // Create a seed to generate a random number

    // Run the random number seed through the MD5 function
    srand((double)microtime()*1000000);

    $seed_string = md5(rand(0,9999));
    // Chop the random string down to 5 characters 4-7 time

    $number_of_chars = round(rand(4, 7));

    // This is the validation code we will use
    $val_string = substr($seed_string, 17, $number_of_chars);

    // Set the background of the image to black
    // file the image with the black background first..
    imagefill($val_img, 0, 0, $black);

    // coloring background..
    $rand_number = round(rand(300, 1000));
    for($i = 0; $i < $rand_number; $i ++)
    {
        $x1 = round(rand(0, IMAGE_WIDTH));
        $x2 = round(rand(0, IMAGE_WIDTH));
        $y1 = round(rand(0, IMAGE_HEIGHT));
        $y2 = round(rand(0, IMAGE_HEIGHT));
        $x3 = $x1 + round(rand(-8, 8));
        $x4 = $x2 + round(rand(-8, 8));
        $y3 = $y1 + round(rand(-8, 8));
        $y4 = $y2 + round(rand(-8, 8));

        $red = round(rand(28, 125));
        $green = round(rand(28, 125));
        $blue = round(rand(28, 125));

        $rand_color = imagecolorallocate($val_img, $red, $green, $blue);

        $points = array($x1, $y1,
                        $x2, $y2,
                        $x3, $y3,
                        $x4, $y4);
        //imagefilledrectangle($val_img, $x1, $y1, $x2, $y2, $rand_color);
        imagefilledpolygon($val_img, $points, 4, $rand_color);
    }

    $x_pos = 23;

    //$font = imageloadfont("FreeSans.ttf");
    for($i = 0; $i < $number_of_chars; $i ++)
    {
        $c = substr($val_string, $i ,1); 
        
        $size = round(rand(10, 27));
        
        $red = round(rand(128, 255));
        $green = round(rand(128, 255));
        $blue = round(rand(128, 255));
        $rand_color = imagecolorallocate($val_img, $red, $green, $blue);
        
        $x_width = round(rand(14, 20));
        $y_pos = round(rand(20, 32));

        $angle = round(rand(-25, 25));

        ImageTTFText($val_img, $size, $angle, $x_pos, $y_pos, $rand_color, "font/FreeSans.ttf", $c);
        //imagechar($val_img, $size, $x_pos, 5, $c, $rand_color);
        
        $x_pos += $x_width;
    }

    //imagepsfreefont($font);

    // Print the validation code on the image in white
    //imagestring($val_img, 4, 96, 19, $val_string, $white);

    // Write the image file to the current directory

    $image_path = TEMP_DIR."/verify".$image_loop_index.".jpg";
    imagejpeg($val_img, $image_path);

    imagedestroy($val_img);
   
    if($image_loop_index < IMAGE_LOOP)
    {
        $image_loop_index ++;
    }
    else
    {
        $image_loop_index = 0;
    }
    $_SESSION["wsf_php_demo_site_image_loop_index"] = $image_loop_index ;

    return array("string" => $val_string,
                 "path" => $image_path);
}

$ret = generate_image();

$val_string = $ret["string"];
$image_path = $ret["path"];

$encoded_val_string = md5($val_string);
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<?php
		if(WEB_VERSION == "php")
		{
			$title = "Registration - PHP Web Services - Code, Samples, Demos and Tutorials";
		}
		else if(WEB_VERSION == "c")
		{
			$title = "Registration - C Web Services - Code, Samples, Demos and Tutorials";
		}
	 ?>
	<title><?php echo $title; ?> </title>
	<link rel="Shortcut Icon" href="favicon.ico" type="image/x-icon" />
	<link href="styles/template.css" rel="stylesheet" type="text/css"/>
</head>
<body>
	<div id="page">

		<?php
			require("template/template_header.php")
		 ?>
		 
		<?php
			require("template/start_content.php");
		 ?>
		<div id="content">
			<div id="welcome">
				<h2> Registration to WSO2 WSF/PHP Demo Site</h2>
				<p> 
				  <?php
					if($registration_failed)
					{
					   echo '<font color="red">"'.$registration_message. '</font>';
					}
				   ?>
				</p>
			</div>

		                                     <form action="register.php" method="post" id="register_form">
												<div>
		                                            <div class="login_button_left">&nbsp;</div>
		                                            <div class="login_button">
		                                            	<table>
		                                            		<tr>
		                                            			<td>User Name<font color="red">*</font></td>
		                                            			<td>
		                                            				<input name="username" value="<?php echo $username?>" type="text"/>
		                                            			</td>
		                                            		</tr>
		                                            		<tr>
		                                            			<td>Full Name<font color="red">*</font></td>
		                                            			<td>
		                                            				<input name="friendly_name" value="<?php echo $friendly_name?>" type="text"/>
		                                            			</td>
		                                            		</tr>
		                                            		<tr>
		                                            			<td>Password<font color="red">*</font></td>
		                                            			<td>
		                                            				<input name="input_password" value="<?php echo $password?>" type="password"/>
		                                            			</td>
		                                            		</tr>
		                                            		<tr>
		                                            			<td>Retype Password<font color="red">*</font></td>
		                                            			<td>
		                                            				<input name="confirm_password" value="<?php echo $confirm_password?>" type="password"/>
		                                            			</td>
		                                            		</tr>
		                                            		<tr>
		                                            			<td>&nbsp;</td>
		                                            			<td>&nbsp;
		                                            			</td>
		                                            		</tr>
		                                            		<tr>
		                                            			<td>Type the Text in the Image<font color="red">*</font></td>
		                                            			<td>
		                                            				<input name="image_code" type="text"/>
		                                            				<div style="clear:both;">&nbsp;</div>
		                                            				<img id="random_image" src="<?php echo $image_path;?>"></img>
		                                            				<input type="hidden" value="<?php echo $encoded_val_string;?>" name="real_image_code" id="random_image_string"/>
		                                            				<input type="hidden" value="FALSE" name="dont_validate" id="dont_validate"/>
		                                            				<a href="javascript:document.getElementById('dont_validate').value='TRUE';document.getElementById('register_form').submit()">Generate a different Image</a>
		                                            			</td>
		                                            			
		                                            		</tr>
		                                            	</table>
		                                             </div>
		                                             <div class="login_button_right">&nbsp;</div>
		   										 </div>
		   										 <div class="clear">&nbsp;</div>
                                            	 <div>
                                            		 <div class="submit_button_left">&nbsp;</div>
                                              		 <div class="submit_button"><input type="submit" value="submit"/></div>
                                            		 <div class="submit_button_right">&nbsp;</div>
                                            	 </div>
		   										 <div class="clear">&nbsp;</div>
                                            </form>
		</div>
	
		<?php
			require("template/end_content.php");
		 ?>
	</div>

		<?php
			require("template/template_footer.php")
		 ?>
<?php require("tracker.php"); ?>

</body>
</html>

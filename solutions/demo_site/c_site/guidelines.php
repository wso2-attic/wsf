<?php
require_once("defines.php");
session_start();

$username = $_SESSION["wsf_php_demo_site_username"];
 ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<?php
		if(WEB_VERSION == "php")
		{
			$title = "PHP Web Services - Code, Samples, Demos and Tutorials";
		}
		else if(WEB_VERSION == "c")
		{
			$title = "C Web Services - Code, Sample, Demos and Tutorials";
		}
	 ?>
	<title><?php echo $title; ?> - Community Guidelines</title>
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
	        <?php
		    if(WEB_VERSION == "php")
            {
            ?>
                <h2>WSO2 WSF/PHP Demo Site - Community Guidelines </h2>
            <?php
            else if(WEB_VERSION == "c")
            {
            ?>
                <h2>WSO2 WSF/C Demo Site - Community Guidelines </h2>
            <?php
            }
            ?>

	<?php
		if(WEB_VERSION == "php")
        {
    ?>
<p>			
The following Community Guidelines help you understand the responsibilities of the membership of WSO2 WSF/PHP Demo Site which is hosted in <a href="http://labs.wso2.org/wsf/php">http://labs.wso2.org/wsf/php</a> (Hereafter the "Demo Site") owned by WSO2 Inc. (Hereafter the "Company"). Your use of the Demo Site is subject to these guidelines and the <a href="http://labs.wso2.org/wsf/php/terms.php">Terms of Service</a>.
</p>

<ol>
<li> Good practices
          
<ul>
<li>
<p>
			As a diverse user community, users are encouraged to be respectful and polite in their interactions with other members. Avoid flames, rants, harassment, abuse, or intimidation.
</p>
</li>
<li>
<p>

            Respect copyright law. Only post material for which you hold the copyright or a license which allows the content to be posted in accordance with the Demo Site licensing guidelines. For now, as the <a href="http://labs.wso2.org/wsf/php/terms.php">Terms of Service</a> detail, any content posted must be made available under the Apache 2.0 license which allows unrestricted use, copying, and derivative works without attribution. </p>
</li>
<li>
<p>
			Be honest. Don't lie about yourself in your bio, in comments you make, or in any of the content you generate. Don't impersonate others.
</p>
</li>
<li>
<p>
            Maintain your content. A community thrives when conversations aren't allowed to stagnate. Check your comments regularly and respond to comments there appropriately.
</p>
</li>
</ul>
</li>
<li>
      Bad practices
<ul>
<li>
<p>
            To make the Demo Site a safe community for members of all ages and cultures, refrain from using profanity, obscenity, mature content, and culturally sensitive material in content you generate.
</p>
</li>
<li>
<p>
            Using the Demo Site as a target for or platform originating spam of any sort will result in swift action. If you detect the Demo Site being used for such purposes please alert us immediately at <a href="http://labs.wso2.org/wsf/php/support.php">http://labs.wso2.org/wsf/php/support.php</a>
</p>
</li>
<li>
<p>

            Using the Demo Site for any activity that is illegal or prohibited will result in swift action which may include reporting you to the authorities.
</p>
</li>
<li>
<p>

            Using the Demo Site for commercial purposes is prohibited. Advertising, selling products or services, or conducting transactions on the Demo Site is not allowed. If you have questions about what constitutes a commercial purpose please contact the <a href="http://labs.wso2.org/wsf/php/support.php">Support team</a>.</p>
</li>
</ul>
</li>
</ol>
<p>
<em>Effective 05 March 2008</em>
</p>


<?php
        }
		if(WEB_VERSION == "c")
        {
?>

<p>			
The following Community Guidelines help you understand the responsibilities of the membership of WSO2 WSF/C Demo Site which is hosted in <a href="http://labs.wso2.org/wsf/c">http://labs.wso2.org/wsf/c</a> (Hereafter the "Demo Site") owned by WSO2 Inc. (Hereafter the "Company"). Your use of the Demo Site is subject to these guidelines and the <a href="http://labs.wso2.org/wsf/c/terms.php">Terms of Service</a>.
</p>

<ol>
<li> Good practices
          
<ul>
<li>
<p>
			As a diverse user community, users are encouraged to be respectful and polite in their interactions with other members. Avoid flames, rants, harassment, abuse, or intimidation.
</p>
</li>
<li>
<p>

            Respect copyright law. Only post material for which you hold the copyright or a license which allows the content to be posted in accordance with the Demo Site licensing guidelines. For now, as the <a href="http://labs.wso2.org/wsf/c/terms.php">Terms of Service</a> detail, any content posted must be made available under the Apache 2.0 license which allows unrestricted use, copying, and derivative works without attribution. </p>
</li>
<li>
<p>
			Be honest. Don't lie about yourself in your bio, in comments you make, or in any of the content you generate. Don't impersonate others.
</p>
</li>
<li>
<p>
            Maintain your content. A community thrives when conversations aren't allowed to stagnate. Check your comments regularly and respond to comments there appropriately.
</p>
</li>
</ul>
</li>
<li>
      Bad practices
<ul>
<li>
<p>
            To make the Demo Site a safe community for members of all ages and cultures, refrain from using profanity, obscenity, mature content, and culturally sensitive material in content you generate.
</p>
</li>
<li>
<p>
            Using the Demo Site as a target for or platform originating spam of any sort will result in swift action. If you detect the Demo Site being used for such purposes please alert us immediately at <a href="http://labs.wso2.org/wsf/c/support.php">http://labs.wso2.org/wsf/c/support.php</a>
</p>
</li>
<li>
<p>

            Using the Demo Site for any activity that is illegal or prohibited will result in swift action which may include reporting you to the authorities.
</p>
</li>
<li>
<p>

            Using the Demo Site for commercial purposes is prohibited. Advertising, selling products or services, or conducting transactions on the Demo Site is not allowed. If you have questions about what constitutes a commercial purpose please contact the <a href="http://labs.wso2.org/wsf/c/support.php">Support team</a>.</p>
</li>
</ul>
</li>
</ol>
<p>
<em>Effective 05 March 2008</em>
</p>




<?php
        }
?>
				<p>&nbsp;</p>
			</div>
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

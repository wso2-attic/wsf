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
	<title><?php echo $title; ?> - Privacy Policy</title>
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
				<h2>WSO2 WSF/PHP Demo Site - Privacy Policy </h2>
            <?php
            }else if(WEB_VERSION == "c")
            {
            ?>
				<h2>WSO2 WSF/C Demo Site - Privacy Policy </h2>
            <?php
            }
            ?>
<p>
<?php
if(WEB_VERSION == "php")
{
?>
WSO2 WSF/PHP Demo Site which is hosted at <a href="http://labs.wso2.org/wsf/php">http://labs.wso2.org/wsf/php</a> (Hereafter the "Demo Site") owned by WSO2 Inc. (Hereafter the "Company"), takes your privacy seriously. Please read the following to learn more about the Company's privacy policy.
<?php
}
else if(WEB_VERSION == "c")
{
?>
WSO2 WSF/C Demo Site which is hosted at <a href="http://labs.wso2.org/wsf/c">http://labs.wso2.org/wsf/c</a> (Hereafter the "Demo Site") owned by WSO2 Inc. (Hereafter the "Company"), takes your privacy seriously. Please read the following to learn more about the Company's privacy policy.
<?php
}
?>
</p>

<p>
INFORMATION COLLECTION AND USE
</p>

<ul>
<li>
<p>
      When you register with the Demo Site we ask for personal information such as your name, email address, and biographical information. When you sign into the Demo Site using your account, you are not anonymous.
</p>
</li>
<li>
<p>
      The Demo Site may collect information about your activities on the site from your computer and browser, including your IP address, the Demo Site cookie information, your software and hardware attributes, and the content you access on the Demo Site.
</p>
</li>
<li>
<p>
      The Demo Site may use this information to customize content you see, to fulfil request for products or services, to improve the services of the Company, and to provide anonymous reporting to internal and external clients of the Company.
</p>
</li>
<li>
<p>
      The Demo Site may also use this information to contact you or to conduct research.
</p>
</li>
</ul>

<p>
INFORMATION DISCLOSURE
</p>

<p>
The Demo Site does not rent, sell or share personal information about you with others except to provide products or services that you've requested, unless:
</p>
    
<ul>
<li>
<p>
      You or your legal guardian authorize to do so.
</p>
</li>
<li>
<p>
      The information is shared under a confidentiality agreement with a partner for the purpose of communicating with you about the services the Demo Site offers. These partners are prohibited from sharing your information with others.
 </p>
 </li>
 <li>
 <p>
      The information is requested under subpoena, court order or legal process.
 </p>
 </li>
 <li>
 <p>
      The information is needed to establish or exercise the legal rights of the Company or defend against legal claims.
 </p>
 </li>
 <li>
 <p>
      We believe the information is needed to investigate, prevent, or take action against illegal activities, violations of the Terms of Service of the Demo Site, or as otherwise required by law.
 </p>
 </li>
 <li>
 <p>
      The Demo Site or its owner, the Company, is acquired or merged with another company. The Demo Site will make efforts to announce any such change of ownership and any consequent change of privacy policy.
 </p>
 </li>
</ul>
 <p>
The Demo Site may set and access The Demo Site cookies on your computer.
</p>


<p>
CONFIDENTIALITY AND SECURITY
</p>

<p>
      Access to personal information about you is limited to the employees of the Company, who the Company believes reasonably need to access that information in order to maintain The Demo Site, to fulfill services you've requested, or to otherwise do their jobs.
</p>

<p>
      The Demo Site takes precautions to secure personal information against accidental or malicious release.
</p>

<p>
CHANGES TO THIS PRIVACY POLICY
</p>

<p>
The Demo Site may update this policy at any time. We will notify you of significant changes in the policy by sending a notice to the email address associated with each account or by placing a prominent notice on our site.
</p>

<p>
<?php
if(WEB_VERSION == "php")
{
?>
If you have questions or suggestions about our privacy policy, please contact <a href="http://labs.wso2.org/wsf/php/support.php">Support</a>.
<?php
}
else if(WEB_VERSION == "c")
{
?>
If you have questions or suggestions about our privacy policy, please contact <a href="http://labs.wso2.org/wsf/c/support.php">Support</a>.
<?php
}
?>
</p>

<p>
<em>
Effective 01st March 2008
</em>
</p>
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

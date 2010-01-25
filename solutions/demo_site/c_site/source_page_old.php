<?php

require_once("defines.php");
require_once(REGISTRY_PATH. "RemoteRegistry.php");

session_start();

$username = $_SESSION["wsf_php_demo_site_username"];
$password = $_SESSION["wsf_php_demo_site_password"];


if(FORM_METHOD == "GET")
{
	$src = $_GET["src"];
}
else
{
	$src = $_POST["src"];
}

$aschild = isset($_GET["aschild"]);

if($aschild)
{
	$js_parency = "parent.";
}
else
{
	$js_parency = "window.";
}

$basename = basename($src);

$src_contents = file_get_contents($src);

$pathinfo = pathinfo($src);
$extension = $pathinfo["extension"];

include_once(GESHI_PATH.'geshi.php');

switch($extension)
{
	case "html":
		$language = "html4strict";
		break;
	case "js":
		$language = "javascript";
        break;
    case "sh":
        $language = "bash";
        break;
    case "bat":
        $language = "dos";
        break;
    case "h":
        $language = "c";
        break;
	default:
		$language = $extension;
}

$geshi =& new GeSHi($src_contents, $language);
$highlighted = $geshi->parse_code(); 



?>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<title>Source: <?php echo $basename ?> </title>
	<link rel="Shortcut Icon" href="favicon.ico" type="image/x-icon" />
	<link href="styles/template.css" rel="stylesheet" type="text/css"/>
	<script language="javascript">
        function move_to_here(href)
        {
        	<?php echo $js_parency; ?>location = href;
        }
	</script>
</head>
<body>
	<div id="page">

		<?php
			require("template/template_header_with_js_links.php");
		 ?>
		
		<div id="content">
			<div id="welcome">

                <?php
                  if(isset($src)) {
                ?>

				<h2>Source: <?php echo $basename ?> </h2>
				<p>

				</p>

                <?php
                    }
                    else {
                ?>
                    <h3>Click a file name in the left frame to view its source code</h3>
                    <div style="height:400px">&nbsp;
                    </div>
                <?php
                    }
                ?>

			</div>
			<?php
			echo $highlighted;
			 ?>
		</div>
	</div>
		<?php
			require("template/template_footer.php");
		 ?>
<?php require("tracker.php"); ?>

</body>
</html>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<?php
$src = $_GET["src"];

if(!isset($_GET["src"])) {
    $src = "/home/dimuthu/wso2/www";
}

$source_page_toc = "source_page_toc.php?src=$src";
$source_page_content = "source_page_old.php?aschild=1";

?>
<html>
<head>
  <meta http-equiv="content-type" content="text/html; charset=UTF-8">
  <title>WSO2 WSF/PHP Demo Site - View Source</title>
  <meta name="CREATED" content="20061009;17484000">
  <meta name="CHANGED" content="20061011;10243100">

</head>

    <frameset cols="260,*" border="1" frameborder="yes" framespacing="10" margin="10">
        <frame name="leftFrame" src="<?php echo $source_page_toc; ?>" scrolling="yes" />
        <frame name="mainFrame" src="<?php echo $source_page_content; ?>" />
        <noframes>

            <body></body>

        </noframes>
    </frameset>

</html>


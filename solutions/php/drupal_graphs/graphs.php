<?php

$duration = $_GET["duration"];
$image_url = "image.php";
if(isset($duration)) {
	$image_url = "image.php?duration=$duration";
}
?>
<html>
<head>
<title>Graphs of Nodes and Comments Count</title>
<style>
body div {
	width: 600px;
	margin:0 auto;
	font-family: Verdana, Tahoma;
    font-size: 12px;
	text-align: center;
}
div#header {
	padding: 10px;
}
</style>
</head>
<body>
	<div>
		<div id="header">
			<a href="graphs.php?duration=lastDay">Last 24 Hours</a> |
			<a href="graphs.php?duration=lastMonth">Last 30 Days</a> |
			<a href="graphs.php?duration=lastYear">Last 12 Months</a> |
			<a href="graphs.php?duration=last5Years">Last 5 Years</a>
		</div>
		<div id="image">
			<img src="<?php echo $image_url."&show_comments=1&show_nodes=1";?>"/>
		</div>
	</div>
</body>
</html>
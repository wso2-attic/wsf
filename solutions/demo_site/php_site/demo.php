<?php

require_once("defines.php");
require_once(REGISTRY_PATH. "RemoteRegistry.php");

session_start();

$username = $_SESSION["wsf_php_demo_site_username"];
$password = $_SESSION["wsf_php_demo_site_password"];

if(FORM_METHOD == "GET")
{
	$name = $_GET["name"];
	$src = $_GET["src"];
	$demo = $_GET["demo"];
	$download = $_GET["download"];
	
}
else
{
	$name = $_POST["name"];
	$src = $_POST["src"];
	$demo = $_POST["demo"];
	$download = $_POST["download"];
}

$src=SOLUTIONS_HOME.$src;
$demo=DEMO_HOME.$demo;

$files = NULL;

if($demo == NULL || empty($demo))
{
	$labs_php_home = LABS_PHP_HOME;
	$demo = "resource_view.php?url={$name}&aschild=1";
}
else
{
	$pos = strpos($demo, "?");
	if($pos == FALSE)
	{
		$demo = $demo."?aschild=1";
	}
	else
	{
		$demo = $demo."&aschild=1";
	}
}

$dir_array_name = "_dirs_as_array";
$file_array_name = "_files_as_array";

if(is_dir($src))
{
	$childs = build_files_array($src);
	$files = array($src => $childs); //exclusing the childs..
	$js_map = build_js_map($files);
}
else
{
	$basename = basename($src);
	$js_map = "{\"{$basename}\":\"{$src}\", {$file_array_name}:[\"{$basename}\"], {$dir_array_name}:[]}";
}

//build informaton about directories
function build_files_array($dir)
{
	$childs = array();
	if(is_dir($dir))
	{
	    if ($dh = opendir($dir))
	    {
        	while (($file = readdir($dh)) !== false) 
        	{
        		if($file == "." || $file == ".." || $file == "~" || $file[0] == ".")
        		{
        			continue;
        		}
        		
            	$filename = $dir ."/". $file;
            	if(is_dir($filename))
            	{
            		$childs[$filename] = build_files_array($filename);
	        	}
            	else
            	{
	        		$pathinfo = pathinfo($filename);
	        		$extension = $pathinfo["extension"];
	        		if($extension != "php" && $extension != "html" && $extension != "htm" &&
	        			$extension != "css" && $extension != "js" && $extension != "txt"  &&
	        			$extension != "bat" && $extension != "sh" && $extension != "xslt"  &&
	        			$extension != "xsl" && $extension != "sql" &&
	        			$extension != "xml" && $extension != "wsdl" && $extension != "xsl" /* &&
                        $extension != "jpg" && $extension != "jpeg" && $extension != "gif" */)
	        		{
	        			
	        		}
	        		else
	        		{
            			$childs[$filename] = "FILE";
	        		}
            	}
        	}
        	closedir($dh);
    	}
	}
	return $childs;
}

//clean empty dirs
function clean_empty_dirs($files)
{
}

//build the same array built by build_file_array in js
function build_js_map($files, $align = 0)
{
	
	$tab_width = 4;
	global $dir_array_name;
	global $file_array_name;
	
	$align_string1 = "";
	$align_string2 = "";
	
	for($i = 0; $i < $tab_width * $align; $i ++)
	{
		$align_string1 .= " ";
	}
	
	$return_dir_map = "{\n";
	
	$align ++;
	for($i = 0; $i < $tab_width * $align; $i ++)
	{
		$align_string2 .= " ";
	}
	
	$i = 0;
	$dirs_i = 0;
	$files_i = 0;
	
	$files_str = "[";
	$dirs_str = "[";
	
	foreach($files as $file => $info)
	{
		$file_basename = basename($file);
		
		if(is_array($info)) //that mean this is a dir
		{
			$result = build_js_map($info, $align+1);
			$result_dir_map = $result;
			
			$return_dir_map .= "{$align_string2}\"{$file_basename}\":{$result_dir_map}";
			$return_dir_map .= "{$align_string2},\n";
			
			if($dirs_i != 0)
			{
				$dirs_str .= ", ";
			}
			$dirs_str .="\"{$file_basename}\"";
			$dirs_i ++;
		}
		else
		{
			//here the $dir supposed to be null,
			$return_dir_map .= "{$align_string2}\"{$file_basename}\":\"${file}\",\n";
			
			if($files_i != 0)
			{
				$files_str .= ", ";
			}
			$files_str .= "\"{$file_basename}\"";
			$files_i ++;
		}
		$i ++;
	}
	
	$dirs_str .= "],\n";
	$files_str .= "]\n";
	
	$return_dir_map .= "{$align_string2}{$dir_array_name}:$dirs_str";
	$return_dir_map .= "{$align_string2}{$file_array_name}:$files_str";
	
	$return_dir_map .= "{$align_string1}}\n";
	
	return $return_dir_map;
}


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
	<title><?php echo "$title - $name;"  ?></title>
	<link rel="Shortcut Icon" href="favicon.ico" type="image/x-icon" />
	<link rel="stylesheet" type="text/css" href="styles/demo.css"/>
	<link rel="stylesheet" type="text/css" href="styles/treeview.css"> 
	<link rel="stylesheet" type="text/css" href="styles/foldertree.css"> 
	
	<script language="javascript" src="yui/yahoo/yahoo-min.js"></script>
	<script language="javascript" src="yui/event/event-min.js"></script>
	<script language="javascript" src="yui/dom/dom-min.js"></script>
	<script language="javascript" src="yui/animation/animation-min.js"></script>
	<script language="javascript" src="yui/treeview/treeview-min.js"></script>
	
	<script language="javascript">
	
		
		function init_demo_bar()
		{
			var width = YAHOO.util.Dom.getViewportWidth();
			var height = YAHOO.util.Dom.getViewportHeight() - vertical_margin;
			
			var demo_bar_left = (width - demo_bar_width - demo_bar_right_margin);
			var demo_bar_height = height - demo_bar_top_margin - demo_bar_bottom_margin;
			
			var demo_bar = document.getElementById('demobar');
			YAHOO.util.Dom.setStyle(demo_bar, "left", demo_bar_left + "px");
			YAHOO.util.Dom.setStyle(demo_bar, "width", demo_bar_width + "px");
			YAHOO.util.Dom.setStyle(demo_bar, "top", demo_bar_top_margin + "px");
			YAHOO.util.Dom.setStyle(demo_bar, "height", demo_bar_height + "px");
			
			var toggle_arrow_top = height/2;
			var toggle_arrow_left = demo_bar_left + demo_bar_left_margin_for_array;
			var toggle_arrow = document.getElementById('toggle_arrow');
			YAHOO.util.Dom.setStyle(toggle_arrow, "left", toggle_arrow_left + "px");
			YAHOO.util.Dom.setStyle(toggle_arrow, "top", toggle_arrow_top + "px");
			
			var demoframe = document.getElementById('demoframe');
			YAHOO.util.Dom.setStyle(demoframe, "height", height + "px");
			width -= right_margin;
			YAHOO.util.Dom.setStyle(demoframe, "width", width + "px");
			
			var source_container = document.getElementById('source_container');
			var source_container_height = height - source_container_height_less_from_height;
			if(source_container_height < source_container_height_min)
			{
				source_container_height = source_container_height_min;
			}
			YAHOO.util.Dom.setStyle(source_container, "height", source_container_height + "px");
			
			
			current_selected_anchor = null;
		}
		
		function init_message_bar()
		{
			var width = YAHOO.util.Dom.getViewportWidth();
			var height = YAHOO.util.Dom.getViewportHeight();
			
			var demo_bar = document.getElementById('demobar');
			var demo_bar_left = Yahoo.util.Dom.getStyle(demo_bar, "left");
			
		}
		
		function init_source_tree()
		{
			var tree = new YAHOO.widget.TreeView('source_container');
			
			var root = tree.getRoot();
			
			<?php
			echo "var file_map = {$js_map};\n";
			
			?>
			build_source_tree(file_map, root, true);
			//var tmp_node = new YAHOO.widget.TextNode("mylabel", root, false);
			tree.draw();
		}
		
		function build_source_tree(file_map, parent, expand)
		{
			var file_array_name = "<?php echo $file_array_name; ?>";
			var dir_array_name = "<?php echo $dir_array_name; ?>";
			
			var files = file_map[file_array_name];
			var dirs = file_map[dir_array_name];
			
			var i = 0;
			
			for(i = 0; i < files.length; i ++)
			{
				var file = files[i];
				var path = file_map[file];
				
				var file_html = "<a class=\"link_normal\" href=\"#\" onclick=\"goto_source('" + path + "', this)\"> "+file+"</a>";
				
				new YAHOO.widget.HTMLNode(file_html, parent, expand);
			}
			
			for(i = 0; i < dirs.length; i ++)
			{
				var dir = dirs[i];
				var childs_map = file_map[dir];
				var tmp_node = new YAHOO.widget.TextNode(dir, parent, expand);
				
				build_source_tree(childs_map, tmp_node, false);
			}
		}
		
		function run_download()
		{
			//just call the run_demo..
			run_demo();
		}
		
		function run_demo()
		{
			var view_source_anchor = document.getElementById('view_source_anchor');
			var run_demo_anchor = document.getElementById('run_demo_anchor');
			
			run_demo_anchor.className =  "link_bold";
			view_source_anchor.className = "source_normal";
			
			if(current_selected_anchor != null)
			{
				current_selected_anchor.className = "link_normal";
				current_selected_anchor = null;
			}
			
			var demoframe = document.getElementById('demoframe');
			var url = "<?php echo $demo; ?>";
			
			demoframe.src = url;
			
		}
		
		function goto_source(src, anchor)
		{
			if(current_selected_anchor != null)
			{
				current_selected_anchor.className = "link_normal";
			}
			anchor.className = "link_bold";
			var view_source_anchor = document.getElementById('view_source_anchor');
			var run_demo_anchor = document.getElementById('run_demo_anchor');
			
			run_demo_anchor.className =  "link_normal";
			view_source_anchor.className = "source_bold";
			
			current_selected_anchor = anchor;
			
			var demoframe = document.getElementById('demoframe');
			
			var url = "source_page_old.php?src=" + encodeURIComponent(src) + "&aschild=1";
			demoframe.src = url;
		
			/*
		   	var src_input = document.getElementById('src_input');
        	src_input.value = src;
        	
			var form = document.getElementById("src_form");
			form.action = "source_page.php";
			form.method = "<?php echo FORM_METHOD; ?>";
			form.submit();  */
		}
		
		function toggle_bar()
		{
			if(!demobar_opened)
			{
				var demo_left_limit = YAHOO.util.Dom.getViewportWidth() - demo_bar_right_margin - demo_bar_minimize_width;
				var arrow_limit = demo_left_limit + demo_bar_left_margin_for_array;
				
				var handler = function (type, args) {
					var arrow_img = document.getElementById('arrow_img');
					arrow_img.src = "images/template/backarrow.png";
					document.getElementById('toggle_bar_text').innerHTML = "Show";
				};
				
				var anim = new YAHOO.util.Anim('demobar', {width: {to:demo_bar_minimize_width}, left:{to:demo_left_limit}});
				anim.animate();
				var anim2 = new YAHOO.util.Anim('toggle_arrow', {left:{to:arrow_limit}});
				anim2.onComplete.subscribe(handler);
				anim2.animate();
				
				demobar_opened = true;
			}
			else
			{
				var demo_left_limit = YAHOO.util.Dom.getViewportWidth() - demo_bar_right_margin - demo_bar_width;
				var arrow_limit = demo_left_limit + demo_bar_left_margin_for_array;
				
				var handler = function (type, args) {
					var arrow_img = document.getElementById('arrow_img');
					arrow_img.src = "images/template/forarrow.gif";
					document.getElementById('toggle_bar_text').innerHTML = "Hide";
				};
				
				var anim = new YAHOO.util.Anim('demobar', {width: {to:demo_bar_width}, left:{to:demo_left_limit}});
				anim.animate();
				var anim2 = new YAHOO.util.Anim('toggle_arrow', {left:{to:arrow_limit}});
				anim2.onComplete.subscribe(handler);
				anim2.animate();
								
				demobar_opened = false;
				
			}
			
		}
		function form_resources_view(url)
		{
            var resource_input = document.getElementById('resource_input');
            resource_input.value = url;
            
            
			var form = document.getElementById("resource_form");
			form.action = "resource_view.php";
			form.method = "<?php echo FORM_METHOD ?>";
			form.submit();
		}
			
	</script>
</head>
<body>
	<div style="overflow:visible">

		<?php
        if($src != NULL && !empty($src))
        {
        	$labs_php_home = LABS_PHP_HOME;
        	echo <<<DEMOBAR
        <div id="demobar">
			<div id="demobar_content">
				<div id="demobar_content_topic" style="width:250px;">
					<div style="float:left">
						<h2><a href="resource_view.php?url={$name}">{$name}</a></h2>
					</div>
					<div id="demobar_content_home" style="float:right; text-align:right;">
						<a  href="index.php" class="home2">Home</a>
						<!--<h2><a href="index.php">Home</a></h2>-->
					</div>
				</div>
			</div>
			<div style="clear:both">&nbsp;</div>
			<div id="demobar_content">
DEMOBAR;
			if($download != NULL && !empty($download))
			{
				echo <<<DEMOBAR
				<p>
				<a class="link_bold" id="run_demo_anchor" href="javascript:run_download()">Download</a>
				</p>
DEMOBAR;
			}
			else if($demo != NULL && !empty($demo))
			{
				echo <<<DEMOBAR
				<p>
				<a class="link_bold" id="run_demo_anchor" href="javascript:run_demo()">Run Demo</a>
				</p>
DEMOBAR;
			}
        	echo <<<DEMOBAR
				<p>
				<div class="source_normal" id="view_source_anchor">View Source</div>
				</p>
			</div>
			<div class="clear">&nbsp;</div>
			<div id="source_container">
				
			</div>
			
			<h3 class="downloads">Popular <a href="http://wso2.org/downloads/wsf/php">Downloads</a></h3>
			<div class="wsfphp_downloads">
			<ul>
			<li>
			<a class="binary" href="http://dist.wso2.org/products/wsf/php/1.3.2/wso2-wsf-php-bin-1.3.2-win32.zip">Windows Binary</a>
			</li>
			<li>
			<a class="zip" href="http://dist.wso2.org/products/wsf/php/1.3.2/wso2-wsf-php-src-1.3.2.zip">Source Zip</a>
			</li>
			<li>
			<a class="srctarball" href="http://dist.wso2.org/products/wsf/php/1.3.2/wso2-wsf-php-src-1.3.2.tar.gz">Source TarBall</a>
			</li>
			</ul>
			</div>
			
		</div>
		&nbsp;
		<div id="toggle_arrow">
			<a style="text-decoration:none" href="javascript:toggle_bar()">
				<span>
					<img style="background: transparent;" id="arrow_img" border="0px" width="25px" src="images/template/forarrow.gif"></img>
				</span>
				<span id="toggle_bar_text">
					Hide
				</span>
			</a>
		</div>
DEMOBAR;
		}
?>

	</div>
	<form id="src_form">
		<input id="src_input" type="hidden" name="src" value=""/>
	</form>
	<form id="resource_form">
		<input id="resource_input" type="hidden" name="url" value=""/>
	</form>
	<form id="rating_form">
		<input id="rating_input" type="hidden" name="rate" value=""/>
		<input type="hidden" name="url" value="<?php echo $href; ?>"/>
	</form>

	<form id="tag_form">
		<input id="tag_input" type="hidden" name="tag" value=""/>
	</form>
	<iframe  frameborder="0" scrolling="auto" id="demoframe" src="<?php echo $demo; ?>">
	</iframe>
			
	<script language="javascript">
	
		/* some layout constatns */
		var demo_bar_width = 330;
		var demo_bar_right_margin = 40;
		
		var demo_bar_left_margin = 20;
		
		var demo_bar_minimize_width = 30;
		
		var demo_bar_left_margin_for_array = 10;
		
		var vertical_margin = 0;
		var right_margin = 0;
		
		var demo_bar_top_margin = 40;
		var demo_bar_bottom_margin = 40;
		
		var source_container_height_min = 50;
		var source_container_height_less_from_height = 450;
		
		var current_selected_anchor = null;
		
		var demobar_opened = false;

		<?php
                    if($src != NULL && !empty($src))
                    {
			echo <<<CODE
			init_demo_bar();
			init_source_tree();
			window.onresize = function(){
		             init_demo_bar();
                     init_source_tree();
			};
CODE;
                    }
                    else
                    {
			echo <<<CODE
                        init_demo_bar();
                        window.onresize = function(){
                            init_demo_bar();
			};
CODE;
                    }
                ?>
	</script>
    <?php
    require("tracker.php");
    ?>
</body>
</html>

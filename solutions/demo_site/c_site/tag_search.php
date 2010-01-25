<?php

require_once("defines.php");
require_once(REGISTRY_PATH. "RemoteRegistry.php");

session_start();

$username = $_SESSION["wsf_php_demo_site_username"];
$password = $_SESSION["wsf_php_demo_site_password"];

if(FORM_METHOD == "GET")
{
	$tag = $_GET["tag"];
}
else
{
	$tag = $_POST["tag"];
}

$rr = new RemoteRegistry(REGISTRY_ATOM_INTERFACE, $username, $password);

$contents = $rr->getResourcePathsWithTag($tag);

//$parent_title = $contents->title;
$parent_title = LABS_PHP_HOME;

$entries = $contents->entries;

$resources = array();
$i = 0;
//print_r($entries);
if(is_array($entries))
{
	foreach($entries as $title => $href)
	{
		$extracted_href = substr($href, strlen(REGISTRY_ATOM_INTERFACE)-1);
		$content = $rr->get($extracted_href);
		
		if(strstr($extracted_href, $parent_title) === FALSE)
		{
			continue;
		}
		
		$extracted_title = substr($title, strlen($parent_title)+1);
		if(strlen($extracted_title) == 0)
		{
			continue;
		}
		$resources[$i] = array();
		$resources[$i]["title"] = $extracted_title;
		$resources[$i]["path"] = $title;
		
		$resources[$i]["author"] = $content->author_username;
		
		$resources[$i]["subtitle"] = $content->subtitle;
		
		$ratings = $rr->getAverageRating($extracted_href);
		$resources[$i]["ratings"] = $ratings;
		
		$tags_array = $rr->getTags($extracted_href);

		$tags = "";
		foreach($tags_array as $tagx)
		{
			$tag_html = "<a href=\"javascript:search_by_tag('{$tagx}')\">{$tagx}</a>";
			$tags .= $tag_html." ";
		}
		$resources[$i]["tags"] = $tags;
		
		$i ++;
	}
}

$properties = $contents->properties;

if(is_array($properties))
{
	$demo = $properties["demo"];
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
	<title><?php echo "$title - $tag"; ?></title>
	<link rel="Shortcut Icon" href="favicon.ico" type="image/x-icon" />
	<link href="styles/template.css" rel="stylesheet" type="text/css"/>
		<link href="styles/styles.css" rel="stylesheet" type="text/css"/>
		<script language="javascript">
			function form_resources_view(url)
			{
            	var resource_input = document.getElementById('resource_input');
            	resource_input.value = url;
            	
            	
				var form = document.getElementById("resource_form");
				form.action = "resource_view.php";
				form.method = "<?php echo FORM_METHOD ?>";
				form.submit();
			}

	        function refresh_rate(index, together_rate)
	        {
	            floor_rate = Math.floor(together_rate);
	            decimal = together_rate - floor_rate;
	            
	            half_star = floor_rate + 1;
	
	
	            var i;
	            for(i = 1; i <= floor_rate; i ++)
	            {
	                var img = document.getElementById("rated_" + index + "_" + i);
	                img.src = "images/stars/r04.gif"; 
	            }
	
	            if(decimal != 0 && half_star <=5)
	            {
	                var img = document.getElementById("rated_" + index + "_" + half_star);
	                if(decimal <= 0.25)
	                {
	                    img.src = "images/stars/r01.gif";
	                }
	                else if(decimal <= 0.75)
	                {
	                    img.src = "images/stars/r02.gif";
	                }
	                else
	                {
	                    img.src = "images/stars/r03.gif";
	                }
	            }
	        }
        
	        function search_by_tag(tag)
	        {
	        
	        	var tag_input = document.getElementById('tag_input');
	        	tag_input.value = tag;
	        	
				var form = document.getElementById("tag_form");
				form.action = "tag_search.php";
				form.method = "<?php echo FORM_METHOD; ?>";
				form.submit();
	        }
		</script>
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
				<h2> Tag Search: <?php echo $tag; ?>  </h2>
			<?php
				if(WEB_VERSION == "php")
				{
			?>
				<p>
					
					Enjoy the power of <strong>Web Services</strong> with <a href="http://wso2.org/projects/wsf/php"><strong>WSO2 Web Services Framework for PHP</strong>.</a>. 
					Learn how to build real world application using Web services technologies such as <strong>SOAP</strong> and <strong>REST</strong> in <strong>PHP</strong>.
				</p>
				<p>
					Navigate through the list of demos, try them on-line and view their source code. 
				</p>
			<?php
				}
				else if(WEB_VERSION == "c")
				{
			?>
				<p>
					
					Enjoy the power of <strong>Web Services</strong> with <a href="http://wso2.org/projects/wsf/c"><strong>WSO2 Web Services Framework for C</strong>.</a>. 
					Learn how to build real world application using Web services technologies such as <strong>SOAP</strong> and <strong>REST</strong> in <strong>C</strong>.
				</p>
				<p>
					Navigate through the list of demos, try them on-line and view their source code. 
				</p>
			<?php
				}
			 ?>
			</div>

		                                            	<form method="<?php echo FORM_METHOD; ?>" id="form_resources">
		                                            	<table class="demolist">
		                                            	<tbody>
		                                            		<tr>
		                                            			<td class="tableHeaders_left" width="15%">Name</td>
		                                            			<td class="tableHeaders" width="20%">Tags</td>
		                                            			<td class="tableHeaders" width="45%">Description</td>
		                                            			<td class="tableHeaders_right" width="20%">Ratings</td>
		                                            		</tr>
													<?php
														$i = 0;
														if(is_array($resources))
														{
															foreach($resources as $resource)
															{
																$title = $resource["title"];
																$path = urlencode($resource["path"]);
																$author = $resource["author"];
																$subtitle = $resource["subtitle"];
																$ratings = $resource["ratings"];
																$tags = $resource["tags"];
																
				                                            	//<td><a href="javascript:form_resources_view('resource_view.php?uri={$path}')">{$title}</a></td>
				                                            	//<td class="table_data"><a href="resource_view.php?url={$path}">{$title}</a></td>
															      echo <<<END
				                                            		<tr>
				                                            			<td class="table_data"><a href="javascript:form_resources_view('{$path}')">{$title}</a></td>
				                                            			<!--<td class="table_data"><a href="{$demo}">Run</a></td> -->
				                                            			<td class="table_data">{$tags}</td>
				                                            			<td class="table_data">{$subtitle}</td>
				                                            			<td class="table_data_right">
																	       <div>
																	            <img id="rated_{$i}_1" src="images/stars/r00.gif"/>
																	            <img id="rated_{$i}_2" src="images/stars/r00.gif"/>
																	            <img id="rated_{$i}_3" src="images/stars/r00.gif"/>
																	            <img id="rated_{$i}_4" src="images/stars/r00.gif"/>
																	            <img id="rated_{$i}_5" src="images/stars/r00.gif"/>
																	       </div>
				                                            			</td>
				                                            		</tr>
END;
																$i ++;
															}
														}
														if(!is_array($resources) || count($resources) == 0)
														{
															echo <<<END
				                                            		<tr>
				                                            			<td class="table_data">&nbsp;</td>
				                                            			<td class="table_data">&nbsp;</td>
				                                            			<td class="table_data">&nbsp;</td>
				                                            			<td class="table_data_right">
																	       <div>
																	       		&nbsp;
																	       </div>
				                                            			</td>
				                                            		</tr>
END;
															
														}
		                                             ?>
		                                             	</tbody>
		                                            	</table>
		                                            	</form>
		</div>
	
		<?php
			require("template/end_content.php");
		 ?>
		
	</div>
		<?php
			require("template/template_footer.php")
		 ?>
	
	<form id="resource_form">
		<input id="resource_input" type="hidden" name="url" value=""/>
	</form>
	<form id="tag_form">
		<input id="tag_input" type="hidden" name="tag" value=""/>
	</form>
	
	<script language="javascript">
		<?php
		$i = 0;
		if(is_array($resources))
		{
			foreach($resources as $resource)
			{
				$ratings = $resource["ratings"];
				echo "refresh_rate({$i}, {$ratings});\n";
				$i ++;
			}
		}
		?>		
	</script>
<?php require("tracker.php"); ?>

</body>
</html>

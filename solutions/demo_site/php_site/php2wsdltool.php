<?php

require_once("defines.php");
require_once(REGISTRY_PATH. "RemoteRegistry.php");

session_start();

$username = $_SESSION["wsf_php_demo_site_username"];
$password = $_SESSION["wsf_php_demo_site_password"];

if(FORM_METHOD == "GET")
{
	$rate = $_GET["rate"];
	$comment_area = $_GET["comment_area"];
}
else
{
	if(isset($_POST["url"]))
	{
		$href = $_POST["url"];
	}
	else
	{
		$href = $_GET["url"];
	}
		
	$rate = $_POST["rate"];
	$comment_area = $_POST["comment_area"];
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

//extracting data from registry,
$rr = new RemoteRegistry(REGISTRY_ATOM_INTERFACE, $username, $password);

$href = "/labs/tools/php2wsdl";

if(isset($rate) && !empty($rate))
{
	$rr->rateResource($href, $rate);
}

if(isset($comment_area) && !empty($comment_area))
{
	$comment = new Comment();
	$comment->text = $comment_area;
	$comment->user = $username;
	
	$rr->addComment($href, $comment);
}


$content = $rr->get($href);
	
$title = $content->title;

$parent_title = $content->parent_path;
$extracted_title = substr($title, strlen($parent_title)+1);

$author = $content->author_username;
$created_time = date('M d Y h:i:s A',(int)$content->created_time);
$last_updated_user = $content->last_updated_username;
$last_updated_time = date('M d Y h:i:s A',(int)strtotime($content->updated));

$subtitle = $content->subtitle;
$avg_ratings = $rr->getAverageRating($href);

if($username !== NULL && !empty($username))
{
	$user_ratings = $rr->getUserRating($href, $username);
}
else
{
	$user_ratings = 0;
}

$tags_array = $rr->getTags($href);

$tags = "";
foreach($tags_array as $tag)
{
	$tag_html = "<a href=\"javascript:search_by_tag('{$tag}')\">{$tag}</a>";
	$tags .= $tag_html." ";
}


$comments = $rr->getComments($href);

function format_xml($xml)
{
    $xml = str_replace(">", ">\n", $xml);
    $xml = str_replace("</", "\n</", $xml);
    $xml = str_replace(">\n\n</", ">\n</", $xml);

    return $xml;
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
	<title><?php echo "$title - $extracted_title"; ?></title>
	<link rel="Shortcut Icon" href="favicon.ico" type="image/x-icon" />
	<link href="styles/template.css" rel="stylesheet" type="text/css"/>
	<link href="styles/styles.css" rel="stylesheet" type="text/css"/>
	<script language="javascript">
	
        var current_rate = <?php echo $user_ratings; ?>;
        
        var rater_timeout = null;

        function highlight(num)
        {
            var i;
            for(i = 1; i <= num; i ++)
            {
                var img = document.getElementById("star" + i);
                img.src = "images/stars/r05.gif"; 
            }

            for(i = num + 1; i <= 5; i ++)
            {
                var img = document.getElementById("star" + i);
                img.src = "images/stars/r00.gif"; 
            }
            if(rater_timeout != null)
            {
	            clearTimeout(rater_timeout);
	            rater_timeout = null;
	        }
        }
       	
        function clearx()
        {
        	if(rater_timeout == null)
        	{
	        	rater_timeout = setTimeout(function(){
		            var i;
		            for(i = 1; i <= current_rate; i ++)
		            {
		                var img = document.getElementById("star" + i);
		                img.src = "images/stars/r05.gif"; 
		            }
		
		            for(i = current_rate + 1; i <= 5; i ++)
		            {
		                var img = document.getElementById("star" + i);
		                img.src = "images/stars/r00.gif"; 
		            }
		            rater_timeout = null;
		         }, 200);
		     }
        }

        function rate(i)
        {
            current_rate = i;
            var rating_input = document.getElementById('rating_input');
            rating_input.value = i + "";
            
			var form = document.getElementById("rating_form");

            var rating_service_code = document.getElementById("rating_service_code");
            var service_code = document.getElementById("service_code");
            rating_service_code.innerHTML = service_code.innerHTML;
			form.action = "php2wsdltool.php";
			form.method = "<?php echo FORM_METHOD; ?>";
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
                else if(decimal < 0.75)
                {
                    img.src = "images/stars/r02.gif";
                }
                else
                {
                    img.src = "images/stars/r03.gif";
                }
            }
        }
        comment_visible = false;
        function comment_make_visible(anchor)
        {
        
        	var comment_area_div = document.getElementById('comment_area_div');
        	var comment_anchor = document.getElementById('comment_anchor');
        	
        	if(comment_visible)
        	{
        		comment_area_div.innerHTML = "";
        		comment_visible = false;
        		comment_anchor.innerHTML = "Add a comment as <?php echo $username; ?>";
        	}
        	else
        	{
				comment_area_div.innerHTML = '<form action="php2wsdltool.php" method="<?php echo FORM_METHOD; ?>">'+
			                                        		'<textarea name="comment_area" rows="3" cols="50"></textarea>'+
                                                            '<input name="service_code" id="comment_service_code" type="hidden" value=""/> ' +
															'<input type="hidden" name="url" value="<?php echo $href; ?>"/>'+
			                                        		'<input type="submit" value="Submit"/></form>';

                var comment_service_code = document.getElementById("comment_service_code");
                var service_code = document.getElementById("service_code");
                comment_service_code.innerHTML = service_code.innerHTML;

        		comment_visible = true;
        		comment_anchor.innerHTML = "Discard the comment";
			}
        }
        
        function goto_demo()
        {
			var form = <?php echo $js_parency; ?>document.getElementById("demo_form");
			form.action = "demo.php";
			form.method = "<?php echo FORM_METHOD; ?>";
			form.submit();
        }
        
        function search_by_tag(tag)
        {
        
        	var tag_input = <?php echo $js_parency; ?>document.getElementById('tag_input');
        	tag_input.value = tag;
        	
			var form = <?php echo $js_parency; ?>document.getElementById("tag_form");
			form.action = "tag_search.php";
			form.method = "<?php echo FORM_METHOD; ?>";
			form.submit();
        }
        
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
		
		<?php
			require("template/start_content.php");
		 ?>
		
		<div id="content">
			<div id="welcome">
				<h2> <?php echo "<a href='javascript:goto_demo()'>{$extracted_title}</a>"; ?></h2>
			</div>

			                                            <div id="content_description">
			                                            	<table>
			                                            		<tbody>

			                                            		<tr>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            		</tr>
			                                            		<tr>
			                                            			<td class="right_align"><b>Description</b></td>
			                                            			<td class="left_align"><?php echo "$subtitle" ?></td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            		</tr>
			                                            		<tr>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            		</tr>
			                                            		<tr>
			                                            			<td class="right_align"><b>Your Code</b></td>
			                                            			<td class="left_align">&nbsp;
                                                                    </td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            		</tr>
			                                            		<tr>
			                                            			<td class="right_align"></td>
			                                            			<td class="left_align">
                                                                    <?php
                                                                        $default_text = "";
                                                                        if(array_key_exists("service_code", $_POST)) {
                                                                            $default_text = $_POST["service_code"];
                                                                        }
                                                                        require("php2wsdlexamples.php");
                                                                        $ex1_sel = $ex2_sel = $ex3_sel = $ex4_sel = $ex5_sel = $ex6_sel = "";
                                                                        if(array_key_exists("example", $_GET)) {
                                                                            switch($_GET["example"])
                                                                            {
                                                                                case "Example1":
                                                                                    $ex1_sel = "selected=\"true\"";
                                                                                    break;
                                                                                case "Example2":
                                                                                    $ex2_sel = "selected=\"true\"";
                                                                                    break;
                                                                                case "Example3":
                                                                                    $ex3_sel = "selected=\"true\"";
                                                                                    break;
                                                                                case "Example4":
                                                                                    $ex4_sel = "selected=\"true\"";
                                                                                    break;
                                                                                case "Example5":
                                                                                    $ex5_sel = "selected=\"true\"";
                                                                                    break;
                                                                                case "Example6":
                                                                                    $ex6_sel = "selected=\"true\"";
                                                                                    break;
                                                                            }
                                                                        }

                                                                    ?>
                                                                    <form id="php2wsdlform" method="GET" action="php2wsdltool.php">
                                                                        <div>
                                                                            <div style="float:left;width:150px">
                                                                                <label>Try Some Examples</label>
                                                                            </div>
                                                                            <div style="float:left;">
                                                                                <select onchange="javascript:document.getElementById('php2wsdlform').submit()" name="example">
                                                                                    <option value="">Select an Example from here</option>
                                                                                    <option <?php echo $ex1_sel ?> value="Example1">Example1</option>
                                                                                    <option <?php echo $ex2_sel ?> value="Example2">Example2</option>
                                                                                    <option <?php echo $ex3_sel ?> value="Example3">Example3</option>
                                                                                    <option <?php echo $ex4_sel ?> value="Example4">Example4</option>
                                                                                    <option <?php echo $ex5_sel ?> value="Example5">Example5</option>
                                                                                    <option <?php echo $ex6_sel ?> value="Example6">Example6</option>
                                                                                </select>
                                                                            </div>
                                                                            <div style="float:left">&nbsp;
                                                                            </div>
                                                                        </div>
                                                                    </form>
                                                                        <div>
                                                                            <div style="float:left;width:150px">
                                                                                <label>Edit your Code here</label>
                                                                            </div>
                                                                            <div style="float:left;">&nbsp;
                                                                            </div>
                                                                            <div style="float:left">&nbsp;
                                                                            </div>
                                                                        </div>
                                                                    <form id="php2wsdlform" method="post" action="php2wsdltool.php">
                                                                        <div style="clear:both">&nbsp;</div>
                                                                        <div>
                                                                            <textarea id="service_code" name="service_code" cols="60" rows="20"><?php echo $default_text; ?></textarea>
                                                                        </div>
                                                                        <div style="clear:both">&nbsp;</div>

                                                                        <div>
                                                                            <div style="float:left;width:50px">
                                                                                &nbsp;
                                                                            </div>
                                                                            <?php 
                                                                                $wsdl1_check = "checked=\"checked\"";
                                                                                $wsdl2_check = "";

                                                                                if(array_key_exists("generate_type", $_POST) && $_POST["generate_type"] == "wsdl2") {
                                                                                    $wsdl1_check = "";
                                                                                    $wsdl2_check = "checked=\"checked\"";
                                                                                } 
                                                                            ?>
                                                                            <div style="float:left;width:150px">
                                                                                <input <?php echo $wsdl1_check;?> type="radio" name="generate_type" value="wsdl1"/><label>WSDL 1.1</label>
                                                                            </div>
                                                                            <div style="float:left;width:150px">
                                                                                <input <?php echo $wsdl2_check;?> type="radio" name="generate_type" value="wsdl2"/><label>WSDL 2.0</label>
                                                                            </div>
                                                                            <div style="float:right">
                                                                                &nbsp;
                                                                            </div>
                                                                        </div>
                                                                        <div style="clear:both">&nbsp;</div>
                                                                        <div>
                                                                            <div style="float:left;width:150px">
                                                                                &nbsp;
                                                                            </div>
                                                                            <div style="float:left">
                                                                                    <input type="Submit" value="Generate.."/>
                                                                            </div>
                                                                            <div style="float:right">
                                                                                &nbsp;
                                                                            </div>
                                                                        </div>
                                                                     </form>
                                                                    </td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            		</tr>

                                                                <?php
                                                                    if(array_key_exists("service_code", $_POST)) {
                                                                ?>
			                                            		<tr>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            		</tr>
			                                            		<tr>
			                                            			<td>&nbsp;</td>
			                                            			<td>
                                                                        <div style="border:1px solid #C4DF9B; width:450px; height: 300px; overflow: auto">
                                                                        <?php 
                                                                            //doing the php2wsdl generation
                                                                            $service_code_index = $_SESSION["service_code_index"];
                                                                            $service_code = $_POST["service_code"];

                                                                            if($service_code_index == NULL) {
                                                                                $service_code_index = 1;
                                                                            }
                                                                            do {
                                                                                $service_file_name="users_service_code".$service_code_index.".php";
                                                                                $service_code_index += 1;
                                                                            }
                                                                            while(file_exists(USER_SERVICES_PATH.$service_file_name));
                                                                            //first put the stuff to the file
                                                                            file_put_contents(USER_SERVICES_PATH.$service_file_name, $service_code);
                                                                            $service_url = USER_SERVICES_HOST.$service_file_name;

                                                                            $url_postfix = "?wsdl";

                                                                            if(array_key_exists("generate_type", $_POST)
                                                                                    && $_POST["generate_type"] == "wsdl2") {
                                                                                $url_postfix = "?wsdl2";
                                                                            }

                                                                            //then read it from the localhost..
                                                                            $curl = curl_init();
                                                                            curl_setopt($curl, CURLOPT_URL, $service_url.$url_postfix);
                                                                            curl_setopt($curl, CURLOPT_HTTPGET, TRUE);
                                                                            curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
                                                                            curl_setopt($curl, CURLOPT_USERAGENT, "wsf/php codegen");
                                                                            $result = curl_exec($curl);
                                                                            $status = curl_getinfo($curl,CURLINFO_HTTP_CODE);
                                                                            curl_close($curl);

                                                                            if($status == 200) {
                                                                                //$xml = htmlspecialchars($result);
                                                                                $xml = format_xml($result);

                                                                                include_once(GESHI_PATH.'geshi.php');
                                                                                $geshi =& new GeSHi($xml, "xml");
                                                                                $highlighted = $geshi->parse_code();
                                                                                echo $highlighted;
                                                                            }

                                                                            //echo $service_code;
                                                                            unlink(USER_SERVICES_PATH.$service_file_name);
                                                                            $_SESSION["service_code_index"] = $service_code_index;
                                                                        ?>
                                                                        </div>
                                                                    </td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            		<tr>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            		</tr>
                                                                <?php
                                                                    }
                                                                ?>

			                                            		
			                                            		<?php
			                                            		if($username != NULL && !empty($username))
			                                            		{
			                                            		 ?>
			                                            		<tr>
			                                            			<td class="right_align"><b>Rate this Tool</b></td>
			                                            			<td class="left_align">
																       <div onmouseout="clearx()">
																            <img id="star1" onclick="rate(1)" onmouseover="highlight(1)" src="images/stars/r00.gif"/>
																            <img id="star2" onclick="rate(2)" onmouseover="highlight(2)" src="images/stars/r00.gif"/>
																            <img id="star3" onclick="rate(3)" onmouseover="highlight(3)" src="images/stars/r00.gif"/>
																            <img id="star4" onclick="rate(4)" onmouseover="highlight(4)" src="images/stars/r00.gif"/>
																            <img id="star5" onclick="rate(5)" onmouseover="highlight(5)" src="images/stars/r00.gif"/>
																       </div>
			                                            			
			                                            			</td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            		</tr>
			                                            		<?php
																}
			                                            		?>
                                                                <?php

                                                                    if($username == NULL) {
                                                                        $star_title = "title=\"Please login to rate the tool\"";
                                                                    }
                                                                    else {
                                                                        $star_title = "";
                                                                    }
			                                            		?>
			                                            		<tr>
			                                            			<td class="right_align"><b>Rating</b></td>
			                                            			<td class="rating_align">
																       <div <?php echo $star_title; ?>>
																            <img id="rated_0_1" src="images/stars/r00.gif"/>
																            <img id="rated_0_2" src="images/stars/r00.gif"/>
																            <img id="rated_0_3" src="images/stars/r00.gif"/>
																            <img id="rated_0_4" src="images/stars/r00.gif"/>
																            <img id="rated_0_5" src="images/stars/r00.gif"/>
			                                            					<?php echo "({$avg_ratings})"; ?>
																       </div>
			                                            			</td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            		</tr>
			                                            		<!--<tr>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            		</tr>
			                                            		<tr>
			                                            			<td class="right_align"><b>Tags</b></td>
			                                            			<td class="left_align"><?php echo $tags; ?></td>
			                                            			<td>&nbsp;</td>
			                                            			<td>&nbsp;</td>
			                                            		</tr> -->
			                                            	</tbody>
			                                            	</table>
			                                            </div>
		</div>
		<div id="comment">

                                            <h2>
                                            	Comments
                                            </h2>
                                            		<?php
                                            		if($username != NULL && !empty($username))
                                            		{
                                            		 ?>
				                                        <div class="addcomment">
				                                        	<a id="comment_anchor" href="javascript:comment_make_visible(this)">Add a comment as <?php echo $username; ?></a>
				                                        </div>
				                                        <div class="clear">&nbsp;</div>
				                                        <div id="comment_area_div" class="commenttext">
				                                        </div>
			                                        <?php
													}
			                                         ?>
													<table class="commentlist">
														<tbody>
		                                            		<tr>
		                                            			<td class="tableHeaders_left" width="30%">Date</td>
		                                            			<td class="tableHeaders" width="20%">Author</td>
		                                            			<td class="tableHeaders" width="50%">Comment</td>
		                                            		</tr>
															                                      
			                                            <?php
			                                            foreach($comments as $comment)
			                                            {
			                                            	$name = $comment->user;
			                                            	$text = $comment->text;
			                                            	$date_time = $comment->date_time;
			                                            	
															$date_time = date('M d Y h:i:s A',(int)strtotime($comment->date_time));
			                                            	
				                                            echo <<<END
				                                            <tr class="data_row">
				                                            	<td class="table_data">{$date_time}</td>
				                                            	<td class="table_data"> {$name}</td>
				                                            	<td class="table_data_right">{$text}</td>
				                                            </div>
END;
														}
														if(count($comments) == 0)
														{
				                                            echo <<<END
				                                            <tr class="data_row">
				                                            	<td class="table_data">&nbsp;</td>
				                                            	<td class="table_data">&nbsp;</td>
				                                            	<td class="table_data_right">&nbsp;</td>
				                                            </div>
END;
															
														}
			                                             ?>
			                                             
		                                             	</tbody>
		                                            </table>
		                                            	
		                                            		
		</div>
		
		<?php
			require("template/end_content.php");
		 ?>
		
	</div>
		<?php
			require("template/template_footer.php")
		 ?>
	<form id="rating_form">
		<input id="rating_input" type="hidden" name="rate" value=""/>
        <input id="rating_service_code" name="service_code" type="hidden" value=""/> 
		<input type="hidden" name="url" value="<?php echo $href; ?>"/>
	</form>
	<form id="demo_form">
		<input type="hidden" name="name" value="<?php echo $extracted_title; ?>"/>
		<input type="hidden" name="url" value="<?php echo $href; ?>"/>
		<input type="hidden" name="src" value="<?php echo $src ?>"/>
		<input type="hidden" name="demo" value="<?php echo $demo ?>"/>
	</form>
	<form id="tag_form">
		<input id="tag_input" type="hidden" name="tag" value=""/>
	</form>
	
	<script language="javascript">
	<?php
		echo "refresh_rate(0, {$avg_ratings});\n";
		
        if($username != NULL && !empty($username))
        {
        	echo "highlight(current_rate);\n";
        }
	 ?>
	 	
	</script>
<?php require("tracker.php"); ?>

<script language="javascript">
</script>
</body>
</html>

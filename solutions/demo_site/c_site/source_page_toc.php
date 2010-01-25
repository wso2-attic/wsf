<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<?php
$src = $_GET["src"];

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
		    	$extension != "c" && $extension != "h" &&
		    	$extension != "sh" && $extension != "bat" &&
                        $extension != "css" && $extension != "js" && $extension != "txt" /* &&
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
<html>
<head>
  <meta http-equiv="content-type" content="text/html; charset=UTF-8">
  <title></title>
  <meta name="CREATED" content="20061009;17484000">
  <meta name="CHANGED" content="20061011;10243100">
  <link href="style/api_style.css" rel="stylesheet" type="text/css" media="all">

  <link href="styles/template.css" rel="stylesheet" type="text/css"/>
  <link href="styles/styles.css" rel="stylesheet" type="text/css"/>

    <link rel="stylesheet" type="text/css" href="styles/demo.css"/>
    <link rel="stylesheet" type="text/css" href="styles/treeview.css">
    <link rel="stylesheet" type="text/css" href="styles/foldertree.css">

    <script language="javascript" src="yui/yahoo/yahoo-min.js"></script>
    <script language="javascript" src="yui/event/event-min.js"></script>
    <script language="javascript" src="yui/dom/dom-min.js"></script>
    <script language="javascript" src="yui/animation/animation-min.js"></script>
    <script language="javascript" src="yui/treeview/treeview-min.js"></script>


  <script language="javascript">
        
        function init_source_tree()
        {
            var tree = new YAHOO.widget.TreeView('tree_container');
            
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

                var url = "source_page_old.php?src=" + encodeURIComponent(path) + "&aschild=1";
                
                var file_html = "<a class=\"link_normal\" target=\"mainFrame\" href=\"" + url + "\"> "+file+"</a>";
                
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

  </script>
</head>

<body lang="en-US" dir="ltr">
<div style="height:60px">
&nbsp;
</div>
<h1>Source files</h1>
<div style="height:20px">
&nbsp;
</div>

<div id="tree_container">
</div>


<script>
   init_source_tree();
</script>


</body>
</html>

<?php

define("DEMO1_ENDPOINT", "http://localhost/samples/DataServices/EmployeesByNumberService.php");
define("DEMO2_ENDPOINT", "http://localhost/samples/DataServices/CustomersInBostonService.php");
define("DEMO3_ENDPOINT", "http://localhost/samples/DataServices/CustomerOrdersService.php");
define("DEMO4_ENDPOINT", "http://localhost/samples/DataServices/NestedQueryService.php");

$demo_no = NULL;
if(array_key_exists("demo", $_GET)) {
	$demo_no = $_GET["demo"];
}
if(!isset($demo_no))
{
    $demo_no = 1;
}
$error = FALSE;
?>
<html>
<head>
<title>Data Services Demo</title>
<link href="styles/demo.css" rel="stylesheet" type="text/css"/>
<style>

/* some dynamic styles; this helps to change the color of the boxes as they are selected */

#tab1 {
    width: 225px;
    float: left;
    padding: 10px;
    text-align: center;
    border:2px solid #ccccdd;
    font-size: 14px;
    <?php
        if($demo_no == 1)
            echo "background: #ccccdd;"
    ?>
}

#tab2 {
    width: 225px;
    float: left;
    padding: 10px;
    text-align: center;
    border:2px solid #ccccdd;
    font-size: 14px;
    <?php
        if($demo_no == 2)
            echo "background: #ccccdd;"
    ?>
}

#tab3 {
    float: left;
    padding: 10px;
    width: 225px;
    text-align: center;
    border:2px solid #ccccdd;
    font-size: 14px;
    <?php
        if($demo_no == 3)
            echo "background: #ccccdd;"
    ?>
}

#tab4 {
    float: left;
    padding: 10px;
    width: 225px;
    text-align: center;
    border:2px solid #ccccdd;
    font-size: 14px;
    <?php
        if($demo_no == 4)
            echo "background: #ccccdd;"
    ?>
}


</style>
</head>
<body>
    <div id="content">
        <h1>Data Services Demo</h1>
        <div>
            <div><!--the title bar -->
                <div id="tab1">
                    <a href="demo.php?demo=1">Demo1</a>
                </div>
                <div id="tab2">
                    <a href="demo.php?demo=2">Demo2</a>
                </div>
                <div id="tab3">
                    <a href="demo.php?demo=3">Demo3</a>
                </div>
                <div id="tab4">
                    <a href="demo.php?demo=4">Demo4</a>
                </div>
            </div>
            <div class="clear">
                    &nbsp;
            </div>

<?php

// The code for the EmployeesByNumber operation invocation and rendering results as HTML
if($demo_no == 1)
{
    // prepare the input parameters
	$param = NULL;
	if(array_key_exists("parameter", $_GET)) {
    	$param = $_GET["parameter"];
	}
    
    if(!isset($param))
    {
        $param=1002;
    }

// ---------- Start of the employeesByNumber Client Invocation Logic ----------------------------------
    // build the reuquest with the input parameter
    $request = <<<XML
<employeesByNumber>
    <employeeByNumber>{$param}</employeeByNumber>
</employeesByNumber>
XML;

    /* call the service */
    try {
        $client = new WSClient(array( "to" => DEMO1_ENDPOINT));
        $responseMessage = $client->request( $request );
        $response = $responseMessage->str;
       
        /* format the xml to looks little clear */ 
        $response = format_xml($response);
    } catch (Exception $e) {
		$error = TRUE;
        if ($e instanceof WSFault) {
            $response = "Soap Fault: ". $e->Reason;
        } else {
            $response = "Message = ".$e->getMessage();
        }
    }

// ---------- End of the employeesByNumber Client Invocation Logic ----------------------------------

?>
       
        <!-- html code to render the output for employeesByNumber-->
        <h2>Get Employees By Number</h2>

        <form method="GET">
            <p>
            <input name="parameter" type="text" value="<?php echo $param; ?>"/>
            </p>
            <p>
                <input type="submit" value="Send Again"/>
            </p>
            <p>
            <?php echo render_result_table($response); ?>
            </p>
        </form>
        <div class="clear">
                &nbsp;
        </div>

        <!-- render the request message and response in seperate boxes -->
        <h2>Messages</h2>
        <div>
            <div class="content-left">
                <p>
                    Request Message
                </p>
                <textarea class="config-textarea" readonly="readonly"><?php echo $request;?></textarea>
            </div>
            <div class="content-middle">
            </div>
            <div class="content-right">
                <p>
                    Output Message
                </p>
                <textarea class="config-textarea" readonly="readonly"><?php echo $response;?></textarea>
            </div>
        </div>
        <div class="clear">
                &nbsp;
        </div>

<?php
    }
    // End of the code for the EmployeesByNumber operation invocation and rendering results as HTML
?>
<?php

// The code for the customersInBoston operation invocation and rendering results as HTML
if($demo_no == 2)
{

// ---------- Start of the customersInBoston Client Invocation Logic ----------------------------------
    $request = <<<XML
<customersInBoston>
</customersInBoston>
XML;

    try {
        $client = new WSClient(array( "to" => DEMO2_ENDPOINT));
        $responseMessage = $client->request( $request );
        $response = $responseMessage->str;
       
        /* format the xml to looks little clear */ 
        $response = format_xml($response);

    } catch (Exception $e) {
		
		$error = TRUE;
        if ($e instanceof WSFault) {
            $response = "Soap Fault: ". $e->Reason;
        } else {
            $response = "Message = ".$e->getMessage();
        }
    }

// ---------- End of the customersInBoston Client Invocation Logic ----------------------------------

?>
        
        <h2>Customers in Boston DEMO</h2>

        <form method="GET">
            <p>
                <input type="submit" value="Send Again"/>
            </p>
                <input type="hidden" name="demo" value="2"/>
            <p>
            <?php echo render_result_table($response); ?>
            </p>
        </form>
        <div class="clear">
                &nbsp;
        </div>

        <!-- show messages as two different boxes -->
        <h2>Messages</h2>
        <div>
            <div class="content-left">
                <p>
                    Request Message
                </p>
                <textarea class="config-textarea" readonly="readonly"><?php echo $request;?></textarea>
            </div>
            <div class="content-middle">
            </div>
            <div class="content-right">
                <p>
                    Output Message
                </p>
                <textarea class="config-textarea" readonly="readonly"><?php echo $response;?></textarea>
            </div>
        </div>
        <div class="clear">
                &nbsp;
        </div>

        
<?php
    }
    // End of the code for the customersInBoston operation invocation and rendering results as HTML
?>
<?php

// The code for the customerOrders operation invocation and rendering results as HTML
if($demo_no == 3)
{
    // prepare the input parameters
	$param = NULL;
	if(array_key_exists("parameter", $_GET)) {
    	$param = $_GET["parameter"];
	}
    
    if(!isset($param))
    {
        $param =406;
    }

// ---------- Start of the customerOrders Client Invocation Logic ----------------------------------
    $request = <<<XML
<customerOrders>
<customerNumber>{$param}</customerNumber>
</customerOrders>
XML;

    try {
        $client = new WSClient(array( "to" => DEMO3_ENDPOINT));
        $responseMessage = $client->request( $request );
        $response = $responseMessage->str;
       
        /* format the xml to looks little clear */ 
        $response = format_xml($response);

    } catch (Exception $e) {

		$error = TRUE;
        if ($e instanceof WSFault) {
            $response = "Soap Fault: ". $e->Reason;
        } else {
            $response = "Message = ".$e->getMessage();
        }
    }

// ---------- End of the customerOrders Client Invocation Logic ----------------------------------

?>
        
        <h2> Get Orders By Customer Number </h2>

        <!-- rendering logic to the rendering as a table -->
        <form method="GET">
            <p>
            <input name="parameter" type="text" value="<?php echo $param; ?>"/>
            </p>
            <p>
                <input type="hidden" name="demo" value="3"/>
                <input type="submit" value="Send Again"/>
            </p>
            <p>
            <?php echo render_result_table($response); ?>
            </p>
        </form>
        <div class="clear">
                &nbsp;
        </div>

        <!-- show messages as two different boxes -->
        <h2>Messages</h2>
        <div>
            <div class="content-left">
                <p>
                    Request Message
                </p>
                <textarea class="config-textarea" readonly="readonly"><?php echo $request;?></textarea>
            </div>
            <div class="content-middle">
            </div>
            <div class="content-right">
                <p>
                    Output Message
                </p>
                <textarea class="config-textarea" readonly="readonly"><?php echo $response;?></textarea>
            </div>
        </div>
        <div class="clear">
                &nbsp;
        </div>

        
<?php
    }
?>
<?php
// The code for the customerOrders operation invocation and rendering results as HTML
if($demo_no == 4)
{
    // prepare the input parameters

// ---------- Start of the customerOrders Client Invocation Logic ----------------------------------
    $request = <<<XML
<customerOrders>
</customerOrders>
XML;

    try {
        $client = new WSClient(array( "to" => DEMO4_ENDPOINT));
        $responseMessage = $client->request( $request );
        $response = $responseMessage->str;
       
        /* format the xml to looks little clear */ 
        $response = format_xml($response);

    } catch (Exception $e) {

		$error = TRUE;
        if ($e instanceof WSFault) {
            $response = "Soap Fault: ". $e->Reason;
        } else {
            $response = "Message = ".$e->getMessage();
        }
    }

// ---------- End of the customerOrders Client Invocation Logic ----------------------------------

?>
        
        <h2> Get Orders for all the customers</h2>

        <!-- rendering logic to the rendering as a table -->
        <form method="GET">

            <p>
            <?php echo render_result_table($response); ?>
            </p>
        </form>
        <div class="clear">
                &nbsp;
        </div>

        <!-- show messages as two different boxes -->
        <h2>Messages</h2>
        <div>
            <div class="content-left">
                <p>
                    Request Message
                </p>
                <textarea class="config-textarea" readonly="readonly"><?php echo $request;?></textarea>
            </div>
            <div class="content-middle">
            </div>
            <div class="content-right">
                <p>
                    Output Message
                </p>
                <textarea class="config-textarea" readonly="readonly"><?php echo $response;?></textarea>
            </div>
        </div>
        <div class="clear">
                &nbsp;
        </div>

        
<?php
    }
?>

    </div>
    </div>
</body>
</html>


<?php
    // some utility functions
    /**
     * format the given xml to some print every tag in new line
     * @param $xml the xml string
     * @return format xml
     */
    function format_xml($xml)
    {
        $xml = str_replace(">", ">\n", $xml);
        $xml = str_replace("</", "\n</", $xml);
        $xml = str_replace(">\n\n</", ">\n</", $xml);

        return $xml;
    }




    /**
     * render the result table
     * @param $xml the response xml or the result error message
     * @return the html code for the table or the error message
     */
    function render_result_table($xml)
    {
        $html = "";

        if(empty($xml)) {
            $html .= "<div style=\"font:#ff0000\">";
            $html .= "Response is not found";
            $html .= "</div>";
            
            return $html;
        }
        $dom = new DOMDocument();
        try  {
            $status = $dom->loadXML($xml);
            
            $root = $dom->documentElement;
            
            if($status == TRUE || $root != NULL) {

                $title = $root->tagName;

                $first_child = $root->firstChild;
                while($first_child && $first_child ->nodeType != XML_ELEMENT_NODE)
                {
                    $first_child = $first_child->nextSibling;
                }

                if($first_child)
                {
                    $html .= "<h3>{$title}</h3>";
                    $html .= "<div>";
                    $html .= "<table border=\"1\">";

                    /* render the fields column */
                    $html .= "<tr style=\"background:#ccccdd\">";
                    foreach($first_child->childNodes as $field)
                    {
                        if($field->nodeType != XML_ELEMENT_NODE)
                            continue;
                        $field_name = $field->tagName;
                        $html.= "<td>{$field_name}</td>";
                    }
                    $html .= "</tr>";

                    /* render the data */

                    foreach($root->childNodes as $data)
                    {
                        if($data->nodeType != XML_ELEMENT_NODE)
                        {
                            continue;
                        }
                        $html .= "<tr>";
                        foreach($data->childNodes as $field)
                        {
                            if($field->nodeType != XML_ELEMENT_NODE)
                            {
                                continue;
                            }
                            $field_value = $field->nodeValue;
                            $html.= "<td>{$field_value}</td>";
                        }
                        $html .= "</tr>";
                    }
                    $html .= "</table>";

                    $html .= "</div>";
                }
                else {
                    $html .= "<div style=\"font:#ff0000\">";
                    $html .= "NO Results";
                    $html .= "</div>";
                }
            }
            else {
                $html .= "<div style=\"font:#ff0000\">";
                $html .= $xml;
                $html .= "</div>";
            }
            return $html;
        } catch (Exception $e) {
                $html .= "<div style=\"font:#ff0000\">";
                $html .= $e->getMessage();
                $html .= "</div>";
                return $html;
        }
    }
?>

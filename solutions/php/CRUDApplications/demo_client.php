<html>
<head>
<title>
RESTFul School DEMO Client
</title>

<script lanaguge="javascript">
// some functions to update the value with the user clicks

function update_getApplicationById() {
    var id = document.getElementById('select_getApplicationById').value;

    var link = document.getElementById("get_application_by_id_link");
    link.innerHTML = "http://labs.wso2.org/wsf/php/solutions/CRUDApplications/school_applications.php/applications/" + id;
    link.setAttribute("href", "http://localhost/solutions/CRUDApplications/school_applications.php/applications/" + id);
}



function update_createApplicationById() {
    var id = document.getElementById('text_createApplicationById').value;

    var link = document.getElementById("create_application_by_id_link");
    link.innerHTML = "http://labs.wso2.org/wsf/php/solutions/CRUDApplications/school_applications.php/applications/" + id;
}


function update_updateApplicationById() {
    var id = document.getElementById('text_updateApplicationById').value;

    var link = document.getElementById("update_application_by_id_link");
    link.innerHTML = "http://labs.wso2.org/wsf/php/solutions/CRUDApplications/school_applications.php/applications/" + id;
}


function update_deleteApplicationById() {
    var id = document.getElementById('select_deleteApplicationById').value;

    var link = document.getElementById("delete_application_by_id_link");
    link.innerHTML = "http://labs.wso2.org/wsf/php/solutions/CRUDApplications/school_applications.php/applications/" + id;

}


</script>

<link href="style.css" rel="stylesheet" type="text/css"/>

</head>
<body>

<h2>
CRUD Operations DEMO
</h2>
<p>
(NOTE: You are not given authority to update or delete application ids 1,2,3 for demo purposes)
</p>

<pre id="response">
<?php
// Here we are doing the call for POST, DELETE and PUT method depending on the user request and pring the 
// results

if(isset($_GET["op"]) && $_GET["op"] == "create") {

    $id = $_GET["id"];
    $name = $_GET["name"];
    $email = $_GET["email"];
    $address = $_GET["address"];

//invoking the POST call
    $requestPayloadString = <<<XML
        <setApplication>
		<name>{$name}</name>
		<email>{$email}</email>
		<address>{$address}</address>
        </setApplication>
XML;
    
    try {
    
        $client = new WSClient( array("to" => "http://localhost/solutions/CRUDApplications/school_applications.php/applications/{$id}",
                                      "useSOAP" => FALSE,
                                      "HTTPMethod" => "POST"));
    
                    
        $responseMessage = $client->request($requestPayloadString);
        
        printf("Response = %s <br>", htmlspecialchars($responseMessage->str));
    
    } catch (Exception $e) {
    
        if ($e instanceof WSFault) {
    	    printf("Error String: %s\n", $e->str);
    	    printf("HTTP Code   : %s\n", $e->httpStatusCode);
        } else {
            printf("Message = %s\n",$e->getMessage());
        }
    }
    
}
else if(isset($_GET["op"]) && $_GET["op"] == "delete") {

    $id = $_GET["id"];

//invoking the POST call
    $requestPayloadString = <<<XML
        <deleteApplication>
        </deleteApplication>
XML;
    
    try {
    
        $client = new WSClient( array("to" => "http://localhost/solutions/CRUDApplications/school_applications.php/applications/{$id}",
                                      "useSOAP" => FALSE,
                                      "HTTPMethod" => "DELETE"));
    
                    
        $responseMessage = $client->request($requestPayloadString);
        
        printf("Response = %s <br>", htmlspecialchars($responseMessage->str));
    
    } catch (Exception $e) {
    
        if ($e instanceof WSFault) {
    	    printf("Error String: %s\n", $e->str);
    	    printf("HTTP Code   : %s\n", $e->httpStatusCode);
        } else {
            printf("Message = %s\n",$e->getMessage());
        }
    }
    
}
else if(isset($_GET["op"]) && $_GET["op"] == "update") {

    $id = $_GET["id"];
    $name = $_GET["name"];
    $email = $_GET["email"];
    $address = $_GET["address"];


//invoking the POST call
    $requestPayloadString = <<<XML
        <updateApplication>
		<name>{$name}</name>
		<email>{$email}</email>
		<address>{$address}</address>
        </updateApplication>
XML;
    
    try {
    
        $client = new WSClient( array("to" => "http://localhost/solutions/CRUDApplications/school_applications.php/applications/{$id}",
                                      "useSOAP" => FALSE,
                                      "HTTPMethod" => "PUT"));
    
                    
        $responseMessage = $client->request($requestPayloadString);
        
        printf("Response = %s <br>", htmlspecialchars($responseMessage->str));
    
    } catch (Exception $e) {
    
        if ($e instanceof WSFault) {
    	    printf("Error String: %s\n", $e->str);
    	    printf("HTTP Code   : %s\n", $e->httpStatusCode);
        } else {
            printf("Message = %s\n",$e->getMessage());
        }
    }
    
}

?>
</pre>

<!--get applications from id-->
<!-- first we retireve the information from the get all applications operation  -->
<?php
$dom = new DOMDocument();
$dom->load("http://localhost/solutions/CRUDApplications/school_applications.php/applications");
$id_elements = $dom->getElementsByTagName("id");

$i = 0;
$student_first_id = "";
$application_options = "";
$last_id = 0;
foreach($id_elements as $id_element){
    $id = $id_element->nodeValue;
    $selected = "";
    if($i == 0) {
        $application_first_id = $id;
        $selected = " selected=\"true\"";
    }
    $i ++;


    if($id == 3 || $id == 1 || $id == 2) {
    }
    else {
    	$application_options .= "<option $selected value=\"$id\">$id</option>";
    }

    $last_id = $id + 1;
}

?>

<!-- rendering of the table -->
<table border="1px">
<tr id="title">
<td width="150px">
Operation
</td>
<td width="250px">
Parameters
</td>
<td width="100px">
HTTP Verb
</td>
<td width="350px">
Url
</td>
</tr>

<tr>
<td>
Get All Applications
</td>
<td>
-
</td>
<td>
GET
</td>
<td>
<a href="http://localhost/solutions/CRUDApplications/school_applications.php/applications">http://localhost/solutions/CRUDApplications/school_applications.php/applications</a>
</td>
</tr>


<tr>
<td>
Get Application By Number
</td>
<td>
ID:
<select id="select_getApplicationById" onchange="javascript:update_getApplicationById()">
<?php
echo $application_options;
?>
</select>
</td>
<td>
GET
</td>
<td>
<a target="_blank" id="get_application_by_id_link" href="http://localhost/solutions/CRUDApplications/school_applications.php/applications/<?php echo $application_first_id ?>">http://localhost/solutions/CRUDApplications/school_applications.php/students/<?php echo $application_first_id ?></a>
</td>
</tr>


<tr>
<form name="create" method="GET">
<input type="hidden" name="op" value="create"></input>
<td>
Create Application 
</td>
<td>
<table>
<tr>
<td>ID:</td><td><input name="id" id="text_createApplicationById" onchange="javascript:update_createApplicationById()" type="text" id="create_id" value="<?php echo $last_id; ?>"/></td>
</tr>
<tr>
<td>Name:</td><td><input type="text" name="name" value=""/></td>
</tr>
<tr>
<td>Email:</td><td><input type="text" name="email" value=""/></td>
</tr>
<tr>
<td>Address:</td><td><input type="text" name="address" value=""/></td>
</tr>
</table>
</td>
<td>
POST
</td>
<td>
<span id="create_application_by_id_link">http://localhost/solutions/CRUDApplications/school_applications.php/students/<?php echo $last_id ?></span> =&gt; <input type="submit" value="Execute Using WSClient"></a>
</input>
</form>
</tr>

<tr>
<form name="update" method="GET">
<input type="hidden" name="op" value="update"></input>
<td>
Update Application 
</td>
<td>
<table>
<tr>
<td>ID:</td><td>
<select name="id" id="text_updateApplicationById" onchange="javascript:update_updateApplicationById()">
<?php
echo $application_options;
?>
</select>

</td>
</tr>
<tr>
<td>Name:</td><td><input type="text" name="name" value=""/></td>
</tr>
<tr>
<td>Email:</td><td><input type="text" name="email" value=""/></td>
</tr>
<tr>
<td>Address:</td><td><input type="text" name="address" value=""/></td>
</tr>
</table>
</td>
<td>
PUT
</td>
<td>
<span id="update_application_by_id_link">http://localhost/solutions/CRUDApplications/school_applications.php/students/<?php echo $last_id ?></span> =&gt; <input type="submit" value="Execute Using WSClient"></a>
</input>
</form>
</tr>


<tr>
<form name="delete" method="GET">
<input type="hidden" name="op" value="delete"></input>
<td>
Delete Application By Number
</td>
<td>
ID:
<select name="id" id="select_deleteApplicationById" onchange="javascript:update_deleteApplicationById()">
<?php
echo $application_options;
?>
</select>
</td>
<td>
DELETE
</td>
<td>
<span id="delete_application_by_id_link">http://localhost/solutions/CRUDApplications/school_applications.php/students/<?php echo $application_first_id ?></span> =&gt;  <input type="submit" value="Execute Using WSClient"></a>
</td>
</form>
</tr>


</table>

<script>
update_getApplicationById();
update_deleteApplicationById();
update_createApplicationById();
update_updateApplicationById();

</script>

</body>
</html>

<html>
<head>
<title>
RESTFul School DEMO Client
</title>

<script lanaguge="javascript">
// some functions to update the value with the user clicks
function update_getStudentByName() {
    var name = document.getElementById('select_getStudentByName').value;

    var link = document.getElementById("get_student_by_name_link");
    link.innerHTML = "http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/students/" + name;
    link.setAttribute("href", "http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/students/" + name);
}

function update_getSubjectByName() {
    var name = document.getElementById('select_getSubjectByName').value;

    var link = document.getElementById("get_subject_by_name_link");
    link.innerHTML = "http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/subjects/" + name;
    link.setAttribute("href", "http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/subjects/" + name);
}

function update_namesForGetMarks() {
    var student = document.getElementById('selectStudentForMarks').value;
    var subject = document.getElementById('selectSubjectForMarks').value;

    var link = document.getElementById("get_marks_link");
    link.innerHTML = "http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/students/" + student + "/marks/" + subject ;
    link.setAttribute("href", "http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/students/" + student + "/marks/" + subject);
}
</script>

<link href="style.css" rel="stylesheet" type="text/css"/>

</head>
<body>
<h1>
RESTFul School DEMO Client
</h1>

<p>
Click the URLs to see how each URL maps to different data pieces.
</p>

<p>
<ul>
<!-- rendering of the table -->
<table border="1px">
<tr id="title">
<td width="150px">
Operation
</td>
<td width="250px">
Parameters
</td>
<td width="450px">
Url
</td>
</tr>

<!--get all subject -->
<tr>
<td>
Get All subjects 
</td>
<td>
No Parameters
</td>
<td>
<a target="_blank" href="http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/subjects">http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/subjects</a>
</td>

<!--get subject from name-->
<!-- first we retireve the information from the get all subject operation  -->
<?php
$dom = new DOMDocument();
$dom->load("http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/subjects");
$subject_name_elements = $dom->getElementsByTagName("name");

$i = 0;
$subject_first_name = "";
$subject_options = "";
foreach($subject_name_elements as $name_element){
    $name = $name_element->nodeValue;
    $selected = "";
    if($i == 0) {
        $subject_first_name = $name;
        $selected = " selected=\"true\"";
    }
    $subject_options .=  "<option $selected value=\"$name\">$name</option>";
}

?>
<tr>
<td>
Get subject information From Name 
</td>
<td>
Name:

<select id="select_getSubjectByName" onchange="javascript:update_getSubjectByName()">
<?php echo $subject_options;?>
</select>
</td>
<td>
<a target="_blank" id="get_subject_by_name_link" href="http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/students/<?php echo $subject_first_name ?>">http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/students/<?php echo $subject_first_name ?></a>
</td>

<!--get all students -->
<tr>
<td>
Get All students
</td>
<td>
No Parameters
</td>
<td>
<a target="_blank" href="http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/students">http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/students</a>
</td>

<!--get student from name-->
<!-- first we retireve the information from the get all students operation  -->
<?php
$dom = new DOMDocument();
$dom->load("http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/students");
$name_elements = $dom->getElementsByTagName("name");

$i = 0;
$student_first_name = "";
$student_options = "";
foreach($name_elements as $name_element){
    $name = $name_element->nodeValue;
    $selected = "";
    if($i == 0) {
        $student_first_name = $name;
        $selected = " selected=\"true\"";
    }
    $i ++;
    $student_options .= "<option $selected value=\"$name\">$name</option>";
}

?>

<tr>
<td>
Get students From Name 
</td>
<td>
Name:
<select id="select_getStudentByName" onchange="javascript:update_getStudentByName()">
<?php
echo $student_options;
?>
</select>
</td>
<td>
<a target="_blank" id="get_student_by_name_link" href="http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/students/<?php echo $student_first_name ?>">http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/students/<?php echo $student_first_name ?></a>
</td>
</tr>

<!-- get marks per students  per subject -->
<tr>
<td>
Get Marks per Students per Subjects
</td>
<td>
<p>
Student Name:
<select id="selectStudentForMarks" onchange="javascript:update_namesForGetMarks()">
<?php
echo $student_options;
?>
</select>
</p>

<p>
Subject Name:
<select id="selectSubjectForMarks" onchange="javascript:update_namesForGetMarks()">
<?php
echo $subject_options;
?>
</p>
</select>
</td>
<td>
<a target="_blank" id="get_marks_link" href="http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/students/<?php echo $student_first_name ?>/marks/<?php echo $subject_first_name ?>">
http://labs.wso2.org/wsf/php/solutions/RESTFulSchool/school_service.php/students/<?php echo $student_first_name ?>/<?php echo $subject_first_name ?></a>
</td>

</tr>
</table>
</p>
<script>

update_getStudentByName();
update_getSubjectByName();
update_namesForGetMarks();

</script>
</body>
</html>

<?php

require_once("wso2/DataServices/DataService.php");
require_once("constants.php");

// Database structure

// Subject:
// ------------------------------------------------
// |  subjectID  |  subjectName  | subjectTeacher | 
// ------------------------------------------------


// Students
// ---------------------------------------------------------------
// |  studentID  |  studentName  | studentAge |  studentAddress  |
// ---------------------------------------------------------------

// Marks
// --------------------------------------
// |  subjectID  |  studentID  | Marks  | 
// --------------------------------------


// database configurations
$config = array(
      "db" => "mysql",
      "username" => DB_USERNAME,
      "password" => DB_PASSWORD,
      "dbname" => "RESTfulSchool",
      "dbhost" => "localhost");


// ============= First get subjects operation ========================

$output_format = array(
                    "resultElement" => "subjects",
                    "rowElement" => "subject",
                    "elements" => array(
                            "name" => "subjectName",
                            "teacher" => "subjectTeacher"));

$sql = "SELECT subjectName, subjectTeacher FROM Subjects";

$get_subjects_op = array("outputFormat" => $output_format, "sql" => $sql);

$get_subjects_url = array("HTTPMethod" => "GET", "RESTLocation" => "subjects");


// ============= get subjects with name operation ========================

$input_format = array("name" => "STRING");

$output_format = array(
                    "resultElement" => "subjects",
                    "rowElement" => "subject",
                    "elements" => array(
                            "name" => "subjectName",
                            "teacher" => "subjectTeacher"));

$sql = "SELECT subjectName, subjectTeacher FROM Subjects where SubjectName = ?";

$get_subjects_with_name_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_subjects_with_name_url = array("HTTPMethod" => "GET", "RESTLocation" => "subjects/{name}");

// ==================================================================

// ============= Then get students operation ========================

$output_format = array(
                    "resultElement" => "students",
                    "rowElement" => "student",
                    "elements" => array(
                            "name" => "studentName",
                            "age" => "studentAge",
                            "address" => "studentAddress"));

$sql = "SELECT * FROM Students";

$get_students_op = array("outputFormat" => $output_format, "sql" => $sql);

$get_students_url = array("HTTPMethod" => "GET", "RESTLocation" => "students");

// ==================================================================


// ============= Then get students by name operation ========================


// ------------ Here we first prepare the inner query -------------

$inner_query_input_format = array("studentID" => "STRING");

$inner_query_output_format = array(
                    "resultElement" => "subjects",
                    "rowElement" => "subject",
                    "elements" => array(
                            "name" => "subjectName",
                            "marks" => "marks"));

$inner_query_sql = "SELECT subjectName, marks FROM Marks m, Subjects s where m.studentId = ? and m.subjectID = s.subjectId";

$inner_query = array("inputFormat" => $inner_query_input_format, "outputFormat" => $inner_query_output_format, "sql" => $inner_query_sql);


// ------------- Secondly we prepare the outer query and set the inner query in output format -----

$out_query_input_format = array("name" => "STRING");

$output_format = array(
                    "resultElement" => "students",
                    "rowElement" => "student",
                    "elements" => array(
                            "name" => "studentName",
                            "age" => "studentAge",
                            "address" => "studentAddress"),
                    "queries" => array($inner_query));

$sql = "SELECT * FROM Students where StudentName = ?";

$get_students_with_name_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

$get_students_with_name_url = array("HTTPMethod" => "GET", "RESTLocation" => "students/{name}");

// ==================================================================

// ============= Then get marks per student, per subject operation ========================

$input_format = array("student" => "STRING", "subject" => "STRING");

$output_format = array(
                    "resultElement" => "Marks",
                    "rowElement" => "mark",
                    "texts" => array("marks"));

$sql = "SELECT marks FROM Marks, Subjects, Students where StudentName = ? and SubjectName = ? ".
        "and Marks.subjectId = Subjects.subjectId and Marks.studentID = Students.StudentId;";
$marks_per_student_per_subject_op = array("inputFormat" => $input_format, "outputFormat" => $output_format, "sql" => $sql);

//$marks_per_student_per_subject_url = array("HTTPMethod" => "GET", "RESTLocation" => "marks/{student}/{subject}");
$marks_per_student_per_subject_url = array("HTTPMethod" => "GET", "RESTLocation" => "students/{student}/marks/{subject}");

// ==================================================================




// list of operations
$operations = array(
                "getSubjects" => $get_subjects_op,
                "getSubjectsWithName" => $get_subjects_with_name_op,
                "marksPerStudentPerSubject" => $marks_per_student_per_subject_op,
                "getStudentsWithName" => $get_students_with_name_op,
                "getStudents" => $get_students_op,
                );

// list of rest url mappping (operation => url)
$restmap = array(
                "getSubjects" => $get_subjects_url,
                "getSubjectsWithName" => $get_subjects_with_name_url,
                "getStudents" => $get_students_url,
                "marksPerStudentPerSubject" => $marks_per_student_per_subject_url,
                "getStudentsWithName" => $get_students_with_name_url,
                );

// creating DSService and reply
$service = new DataService(array("config" => $config, "operations" => $operations, "RESTMapping"=>$restmap));
$service->reply();

?>


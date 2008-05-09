<?php
/**
 * class student
 * @namespace http://test
 */
class Student
{
    /**
     * @var string id
     * (maps to the xs:string XML schema type )
     */
    public $id;
  
    public function __construct($id)
    {
        $this->id = $id;
    }
  
}


/**
 * @return array of object Student $a
 * (maps to the xs:anyType XML schema type )
 */
function getStudents()
{
    $a = array();
  
    for($i = 0; $i <= 2; $i++)
    {
        $a[$i] = new Student("$i");
    }
  
    return array("a" => $a);
}

$operations = array("getStudents");
$opParams = array("getStudents"=> "MIXED");
$service = new WSService(array("operations" => $operations, "opParams" => $opParams));
$service->reply();

?>

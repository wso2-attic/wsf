<?php
    if(array_key_exists("example", $_GET)) {
        if($_GET["example"] == "Example1") {
            $default_text = <<<TEXT1
<?php

/*
   This demonstrates a simple example of using php2wsdl
   The function parameters and return type are simple types
*/
\$item = array("abc" => 101.5, "wso2" => 250.50, "xyz" => 99.99);

/** BuyItem function
 * @param string \$item_name of the item to buy
 * (maps to the xs:string XML schema type )
 * @param int \$amount no of items to buy
 * (maps to the xs:nonNegativeInteger XML schema type)
 * @return float \$price total price
 *(maps to the xs:double XML schema type )
 */
function getPriceFunction(\$item_name ,\$amount)
{
    global \$item;
    if (\$item_name && \$amount){
        if(isset(\$item[\$item_name])){
            return array("price" => (\$item[\$item_name] * \$amount));
        }
        else
            return NULL;
    }
    return array("price" => 200043);
}


\$operations = array("getPrice"=>"getPriceFunction");
\$opParams = array("getPriceFunction"=>"MIXED");

\$svr = new WSService(array("operations"=>\$operations,
               "bindingStyle"=>"doclit",
               "opParams"=>\$opParams));


\$svr->reply();
 
TEXT1;
        }
        if($_GET["example"] == "Example2") {
            $default_text = <<<TEXT1
<?php

/* 
   This demonstrates a simple example of using php2wsdl.
   to generate a rpc type wsdl
   The function parameters and return type are simple types
*/

/** The  purchaseOrder function
 * @param int \$count the number of widgets to buy
 * (maps to the xs:nonNegativeInteger XML schema type )
 * @param string \$date the date those items were sold
 * (maps to the xs:gDay XML schema type)
 * @return string \$t time for buying it
 * (maps to the xs:QName XML schema type )
 */
function purchaseOrder(\$x,\$y)
{
    return array("return"=>\$x*\$y);
}


\$operations = array("purchaseOrder"=>"purchaseOrder");
\$opParams = array("purchaseOrder"=>"MIXED");
\$svr = new WSService(array("operations"=>\$operations,
    "bindingStyle"=>"rpc-enc", "opParams" => \$opParams));


\$svr->reply();

TEXT1;
        }
        if($_GET["example"] == "Example3") {
            $default_text = <<<TEXT1
<?php

/*
    Demonstrates the use of PHP classes as types
    Here the \$classmap option is given which is the\
    only difference from Example4.
*/

class Bar
{
    private \$value = "Test";
    private \$end = "Test";

    
    function Bar(\$start, \$end){
        \$this->value = \$start;
        \$this->end = \$end;
    }

    /**
     * echoValue function
     * @param object Foo \$echoString echoString description
     * @return object FooResponse \$echoStringResponse
     */
    function echoValue(\$echoString){

        \$boo1 = new Boo();
        \$boo1->boo1 = array("test1", "test2");
        \$boo1->boo2 = array("test3", "test4");

        \$boo2 = new Boo();
        \$boo2->boo1 = array("test1", "test2");
        \$boo2->boo2 = array("test3", "test4");

        //either following or the other
        return array("ret_value"=>array(\$boo1, \$boo2));

        return  new FooResponse(array(\$boo1, \$boo2));
    }
}
/**
 * classname Foo
 * @namespace http://mytest/xsd1 namespace of the class Foo
 */
class Foo
{
    /**
     * @var string \$foo1
     */
    public \$foo1;
    /**
     * @var string \$foo2
     * maps to xs:QName
     */
    public \$foo2;

    /**
     * @var array of string \$foo3
     * maps to xs:dateTime
     */
    public \$foo3;

    /**
     * @var object Bay \$foo4
     */
    public \$foo4;
}

/**
 * classname Bay
 * @namespace http://mytest/xsd2 namespace of the class Bay
 */
class Bay
{
    /**
     * @var array of string \$bar1
     */
    public \$bar1;

    /**
     * @var array of object Boo \$bar2
     */
    public \$bar2;
}

/**
 * classname Boo
 * @namespace http://mytest/xsd1
 */
class Boo
{
    /**
     * @var array of string \$boo1
     */
    public \$boo1;

    /**
     * @var array of string \$boo2
     * maps to xs:duration
     */
    public \$boo2;
}

/**
 * classname FooResponse
 * @namespace http://mytest/xsd3
 */
class FooResponse
{
    /**
     * @var array of object Boo \$ret_value
     */
    public \$ret_value;

    public function __construct(\$param_value)
    {
        \$this->ret_value = \$param_value;
    }
}


\$operations = array("echoString" => "echoValue");
\$opParams = array("echoValue" => "MIXED");
\$actions = array("urn:echoString" => "echoString");

\$classmap = array("Foo" => "Foo", "Bay" => "Bay");

\$service = new WSService(array("classes" => 
     array("Bar" => 
         array("operations" => \$operations,
               "args" => array("Welcome", "Bye!"))),
        "bindingStyle"=> "doclit",
        "actions" => \$actions,
        "classmap" => \$classmap,
        "opParams" => \$opParams));

\$service->reply();

?>
 
TEXT1;
        }
        if($_GET["example"] == "Example4") {
            $default_text = <<<TEXT1
<?php

/*
    Demonstrates the use of PHP classes as types
    Here the \$classmap is not given which is
    the only difference with Example3
*/

class Bar
{
    private \$value = "Test";
    private \$end = "Test";

    
    function Bar(\$start, \$end){
        \$this->value = \$start;
        \$this->end = \$end;
    }

    /**
     * echoValue function (here the array is ignored for rpc)
     * @param array of object Foo \$param1 param1 description
     * @param string \$param2
     * @return array of object Boo \$ret_value
     */
    function echoValue(\$param1, \$param2){

        \$boo1 = new Boo();
        \$boo1->boo1 = array("test1", "test2");
        \$boo1->boo2 = array("test3", "test4");


        //either following or the other
        return array("return"=>\$boo1);
    }
}
/**
 * classname Foo
 * @namespace http://mytest/xsd1 namespace of the class Foo
 */
class Foo
{
    /**
     * @var string \$foo1
     */
    public \$foo1;
    /**
     * @var string \$foo2
     * maps to xs:QName
     */
    public \$foo2;

    /**
     * @var array of string \$foo3
     * maps to xs:dateTime
     */
    public \$foo3;

    /**
     * @var object Bay \$foo4
     */
    public \$foo4;
}

/**
 * classname Bay
 * @namespace http://mytest/xsd2 namespace of the class Bay
 */
class Bay
{
    /**
     * @var array of string \$bar1
     */
    public \$bar1;

    /**
     * @var array of object Boo \$bar2
     */
    public \$bar2;
}

/**
 * classname Boo
 * @namespace http://mytest/xsd1
 */
class Boo
{
    /**
     * @var array of string \$boo1
     */
    public \$boo1;

    /**
     * @var array of string \$boo2
     * maps to xs:duration
     */
    public \$boo2;
}

class echoStringResponse
{
    public \$ret_value;

    public function __construct(\$param_value)
    {
        \$this->ret_value = \$param_value;
    }
}



\$operations = array("echoString" => "echoValue");
\$opParams = array("echoValue" => "MIXED");

\$classmap = array("Foo" => "Foo", "Bay" => "Bay");

\$service = new WSService(array("classes" => 
     array("Bar" => 
         array("operations" => \$operations,
               "args" => array("Welcome", "Bye!"))),
        "classmap" => \$classmap,
        "bindingStyle"=> "doclit",
        "opParams" => \$opParams));
        
\$service->reply();


?>

TEXT1;
        }
        if($_GET["example"] == "Example5") {
            $default_text = <<<TEXT1

<?php
/*
    Demonstrates the use of PHP classes as types
    to generate rpc wsdl
 */
class Bar
{
    private \$value = "Test";
    private \$end = "Test";

    
    function Bar(\$start, \$end){
        \$this->value = \$start;
        \$this->end = \$end;
    }

    /**
     * echoValue function
     * @param array of object Foo \$param1 param1 description
     * @param string \$param2
     * @return array of object Boo \$ret_value
     */
    function echoValue(\$param1, \$param2){

        \$boo1 = new Boo();
        \$boo1->boo1 = array("test1", "test2");
        \$boo1->boo2 = array("test3", "test4");

        \$boo2 = new Boo();
        \$boo2->boo1 = array("test1", "test2");
        \$boo2->boo2 = array("test3", "test4");

        //either following or the other
        return array("ret_value"=>array(\$boo1, \$boo2));

        return  new echoStringResponse(array(\$boo1, \$boo2));
    }
}
/**
 * classname Foo
 * @namespace http://mytest/xsd1 namespace of the class Foo
 */
class Foo
{
    /**
     * @var string \$foo1
     */
    public \$foo1;
    /**
     * @var string \$foo2
     * maps to xs:QName
     */
    public \$foo2;

    /**
     * @var array of string \$foo3
     * maps to xs:dateTime
     */
    public \$foo3;

    /**
     * @var object Bay \$foo4
     */
    public \$foo4;
}

/**
 * classname Bay
 * @namespace http://mytest/xsd2 namespace of the class Bay
 */
class Bay
{
    /**
     * @var array of string \$bar1
     */
    public \$bar1;

    /**
     * @var array of object Boo \$bar2
     */
    public \$bar2;
}

/**
 * classname Boo
 * @namespace http://mytest/xsd1
 */
class Boo
{
    /**
     * @var array of string \$boo1
     */
    public \$boo1;

    /**
     * @var array of string \$boo2
     * maps to xs:duration
     */
    public \$boo2;
}

class echoStringResponse
{
    public \$ret_value;

    public function __construct(\$param_value)
    {
        \$this->ret_value = \$param_value;
    }
}


\$operations = array("echoString" => "echoValue");
\$opParams = array("echoValue" => "MIXED");

\$classmap = array("Foo" => "Foo", "Bay" => "Bay");

\$service = new WSService(array("classes" => 
        array("Bar" => 
            array("operations" => \$operations,
                  "args" => array("Welcome", "Bye!"))),
           "bindingStyle"=> "rpc-enc",
           "opParams" => \$opParams));
        
\$service->reply();

?>

TEXT1;
        }
        if($_GET["example"] == "Example6") {
            $default_text = <<<TEXT1
<?php
/*
    Demonstrates how WSDLs with empty parameters for functions are generated
 */
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
    public \$id;
  
    public function __construct(\$id)
    {
        \$this->id = \$id;
    }
  
}


/**
 * @return array of object Student \$a
 * (maps to the xs:anyType XML schema type )
 */
function getStudents()
{
    \$a = array();
  
    for(\$i = 0; \$i <= 2; \$i++)
    {
        \$a[\$i] = new Student("\$i");
    }
  
    return array("a" => \$a);
}

\$operations = array("getStudents");
\$opParams = array("getStudents"=> "MIXED");
\$service = new WSService(
    array("operations" => \$operations,
          "opParams" => \$opParams));
\$service->reply();

?>

TEXT1;
        }
  }
?>

--TEST--
class_based - class map with policy case
--FILE--
<?php

/* 
 * Client.php
 */

/**
 * classname Foo
 * @namespace http://mytest/xsd1 namespace of the class Foo
 */
class Foo
{
    /**
     * @var string $foo1
     */
    public $foo1;
    /**
     * @var string $foo2
     * maps to xs:QName
     */
    public $foo2;

    /**
     * @var array of string $foo3
     * maps to xs:dateTime
     */
    public $foo3;

    /**
     * @var object Bay $foo4
     */
    public $foo4;
}

/**
 * classname Bay
 * @namespace http://mytest/xsd2 namespace of the class Bay
 */
class Bay
{
    /**
     * @var array of string $bar1
     */
    public $bar1;

    /**
     * @var array of object Boo $bar2
     */
    public $bar2;
}

/**
 * classname Boo
 * @namespace http://mytest/xsd1
 */
class Boo
{
    /**
     * @var array of string $boo1
     */
    public $boo1;

    /**
     * @var array of string $boo2
     * maps to xs:duration
     */
    public $boo2;
}

class HelloString
{
    public $param1;
    public $param2;
}

class HelloStringResponse
{
    public $ret_value;
}

$hello = new HelloString();

$param10= new Foo();

$param10->foo1 = "test10";
$param10->foo2 = "test20";
$param10->foo3 = array("test30", "test33");

$bay1 = new Bay();
$bay1->bar1 = array("test1", "test2");

$boo1 = new Boo();
$boo1->boo1 = array("test1", "test2");
$boo1->boo2 = array("test3", "test4");

$boo2 = new Boo();
$boo2->boo1 = array("test1", "test2");
$boo2->boo2 = array("test3", "test4");

$bay1->bar2 = array($boo1, $boo2);

$param10->foo4 = $bay1;

///////////////////////
$param11= new Foo();

$param11->foo1 = "test11";
$param11->foo2 = "test21";
$param11->foo3 = array("test31", "test33");

$bay1 = new Bay();
$bay1->bar1 = array("test3", "test4");

$boo1 = new Boo();
$boo1->boo1 = array("test1", "test2");
$boo1->boo2 = array("test3", "test4");

$boo2 = new Boo();
$boo2->boo1 = array("test1", "test2");
$boo2->boo2 = array("test3", "test4");

$bay1->bar2 = array($boo1, $boo2);

$param11->foo4 = $bay1;

$param2 = "test string";

$hello->param1 = array($param10, $param11);
$hello->param2 = $param2;

$classmap = array("HelloWorldResponse" => "HelloWorldResponse");

// Set up security options
$policy_xml = file_get_contents("samples/wsdl_generation/policy.xml");
$policy = new WSPolicy($policy_xml);
$security_token = new WSSecurityToken(array("user" => "Alice",
                                            "password" => "abcd!123",
                                            "passwordType" => "Digest"));


$wsclient = new WSClient( array(
                "useWSA" => TRUE,
                "policy" => $policy,
                "securityToken" => $security_token,
                "wsdl" => "http://localhost/services/wsdl_generation/policy_service.php?wsdl",
                "to" => "http://localhost/services/wsdl_generation/policy_service.php"));

$proxy = $wsclient->getProxy();

$ret_val = $proxy->echoString($param11);

print_r($ret_val);

?>
--EXPECT--
Array
(
    [ret_value] => Array
        (
            [0] => Array
                (
                    [boo1] => Array
                        (
                            [0] => test1
                            [1] => test2
                        )

                    [boo2] => Array
                        (
                            [0] => test3
                            [1] => test4
                        )

                )

            [1] => Array
                (
                    [boo1] => Array
                        (
                            [0] => test1
                            [1] => test2
                        )

                    [boo2] => Array
                        (
                            [0] => test3
                            [1] => test4
                        )

                )

        )

)


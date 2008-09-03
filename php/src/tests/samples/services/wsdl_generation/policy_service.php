<?php
/*
 * Copyright 2005,2006 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


class Bar
{
    private $value = "Test";
    private $end = "Test";

    
    function Bar($start, $end){
        $this->value = $start;
        $this->end = $end;
    }

    /**
     * echoValue function
     * @param object Foo $echoString echoString description
     * @return object FooResponse $echoStringResponse
     */
    function echoValue($echoString){

        $boo1 = new Boo();
        $boo1->boo1 = array("test1", "test2");
        $boo1->boo2 = array("test3", "test4");

        $boo2 = new Boo();
        $boo2->boo1 = array("test1", "test2");
        $boo2->boo2 = array("test3", "test4");

        //either following or the other
        return array("ret_value"=>array($boo1, $boo2));

        return  new FooResponse(array($boo1, $boo2));
    }
}
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

/**
 * classname FooResponse
 * @namespace http://mytest/xsd3
 */
class FooResponse
{
    /**
     * @var array of object Boo $ret_value
     */
    public $ret_value;

    public function __construct($param_value)
    {
        $this->ret_value = $param_value;
    }
}


$operations = array("echoString" => "echoValue");
$opParams = array("echoValue" => "MIXED");
$actions = array("urn:echoString" => "echoString");

$classmap = array("Foo" => "Foo", "Bay" => "Bay");


// Security options
$policy_xml = file_get_contents("policy.xml");
$policy = new WSPolicy($policy_xml);
$security_token = new WSSecurityToken(array("user" => "Alice",
                                            "password" => "abcd!123",
                                            "passwordType" => "Digest"));

$service = new WSService(array("classes" => 
                            array("Bar" => 
                                array("operations" => $operations,
                                      "args" => array("Welcome", "Bye!"))),
                               "bindingStyle"=> "doclit",
                               /* "bindingStyle"=> "rpc-enc", */
                               "cacheWSDL" => FALSE,
                               "useWSA" => TRUE,
                               "policy" => $policy,
                               "securityToken" => $security_token,
                               "actions" => $actions,
                               "classmap" => $classmap,
                               "opParams" => $opParams));
        
$service->reply();

?>

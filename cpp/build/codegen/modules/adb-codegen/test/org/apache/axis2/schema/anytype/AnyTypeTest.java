/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

package org.apache.axis2.schema.anytype;

import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import org.apache.axis2.databinding.ADBException;
import test.adb.anytype.*;

import javax.xml.namespace.QName;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;



public class AnyTypeTest extends TestCase {

    public void testAnyTypeElement1() {
        TestAnyTypeElement1 testAnyTypeElement;

        testAnyTypeElement = new TestAnyTypeElement1();
        testAnyTypeElement.setTestAnyTypeElement1("test");
        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement1.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement1 result = TestAnyTypeElement1.Factory.parse(xmlReader);
            assertEquals(result.getTestAnyTypeElement1(),"test");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

        testAnyTypeElement = new TestAnyTypeElement1();
        testAnyTypeElement.setTestAnyTypeElement1(null);
        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement1.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            fail();
        } catch (ADBException e) {
            assertTrue(true);
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

    }

    public void testAnyTypeElement2() {
        TestAnyTypeElement2 testAnyTypeElement;

        testAnyTypeElement = new TestAnyTypeElement2();
        testAnyTypeElement.setTestAnyTypeElement2("test");
        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement2.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement2 result = TestAnyTypeElement2.Factory.parse(xmlReader);
            assertEquals(result.getTestAnyTypeElement2(),"test");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

        testAnyTypeElement = new TestAnyTypeElement2();
        testAnyTypeElement.setTestAnyTypeElement2(null);
        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement1.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement2 result = TestAnyTypeElement2.Factory.parse(xmlReader);
            assertEquals(result.getTestAnyTypeElement2(),null);
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testAnyTypeElement3() {
        TestAnyTypeElement3 testAnyTypeElement;
        testAnyTypeElement = new TestAnyTypeElement3();
        testAnyTypeElement.setParam1(new Object[]{"test1","test2"});

        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement3.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement3 result = TestAnyTypeElement3.Factory.parse(xmlReader);
            assertEquals(result.getParam1()[0],"test1");
            assertEquals(result.getParam1()[1],"test2");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

        testAnyTypeElement = new TestAnyTypeElement3();
        testAnyTypeElement.setParam1(null);

        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement3.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement3 result = TestAnyTypeElement3.Factory.parse(xmlReader);
            assertEquals(result.getParam1()[0],null);
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

        testAnyTypeElement = new TestAnyTypeElement3();
        testAnyTypeElement.setParam1(new Object[]{"test",null});

        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement3.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement3 result = TestAnyTypeElement3.Factory.parse(xmlReader);
            assertEquals(result.getParam1()[0],"test");
            assertEquals(result.getParam1()[1],null);
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }


     public void testAnyTypeElement4() {
        TestAnyTypeElement4 testAnyTypeElement;
        testAnyTypeElement = new TestAnyTypeElement4();
        testAnyTypeElement.setParam1(new Object[]{"test1","test2"});

        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement4.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement4 result = TestAnyTypeElement4.Factory.parse(xmlReader);
            assertEquals(result.getParam1()[0],"test1");
            assertEquals(result.getParam1()[1],"test2");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

        testAnyTypeElement = new TestAnyTypeElement4();
        testAnyTypeElement.setParam1(null);

        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement4.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement4 result = TestAnyTypeElement4.Factory.parse(xmlReader);
            assertEquals(result.getParam1(),null);
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

        testAnyTypeElement = new TestAnyTypeElement4();
        testAnyTypeElement.setParam1(new Object[]{"test",null});

        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement4.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement4 result = TestAnyTypeElement4.Factory.parse(xmlReader);
            assertEquals(result.getParam1()[0],"test");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }


    public void testAnyTypeElement5() {
        TestAnyTypeElement5 testAnyTypeElement;
        testAnyTypeElement = new TestAnyTypeElement5();
        testAnyTypeElement.setParam1(new Object[]{"test1","test2"});

        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement5.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement5 result = TestAnyTypeElement5.Factory.parse(xmlReader);
            assertEquals(result.getParam1()[0],"test1");
            assertEquals(result.getParam1()[1],"test2");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

        testAnyTypeElement = new TestAnyTypeElement5();
        testAnyTypeElement.setParam1(null);

        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement5.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement5 result = TestAnyTypeElement5.Factory.parse(xmlReader);
            assertEquals(result.getParam1()[0],null);
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

        testAnyTypeElement = new TestAnyTypeElement5();
        testAnyTypeElement.setParam1(new Object[]{"test",null});

        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement5.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement5 result = TestAnyTypeElement5.Factory.parse(xmlReader);
            assertEquals(result.getParam1()[0],"test");
            assertEquals(result.getParam1()[1],null);
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }


    public void testAnyTypeElement6() {
        TestAnyTypeElement6 testAnyTypeElement;
        testAnyTypeElement = new TestAnyTypeElement6();
        testAnyTypeElement.setParam1(new Object[]{"test1","test2"});

        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement6.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement6 result = TestAnyTypeElement6.Factory.parse(xmlReader);
            assertEquals(result.getParam1()[0],"test1");
            assertEquals(result.getParam1()[1],"test2");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

        testAnyTypeElement = new TestAnyTypeElement6();
        testAnyTypeElement.setParam1(null);

        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement6.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            fail();
        } catch (ADBException e) {
            assertTrue(true);
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

        testAnyTypeElement = new TestAnyTypeElement6();
        testAnyTypeElement.setParam1(new Object[]{"test",null});

        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement6.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            fail();
        } catch (ADBException e) {
            assertTrue(true);
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testAnyTypeElement61(){
        TestAnyTypeElement6 testAnyTypeElement6 = new TestAnyTypeElement6();

        TestComplexParent[] testComplexParents = new TestComplexParent[2];
        testComplexParents[0] = new TestComplexParent();
        testComplexParents[0].setParam1("test param1");

        TestComplexChild testComplexChild = new TestComplexChild();
        testComplexChild.setParam1("test param1");
        testComplexChild.setParam2(3);
        testComplexParents[1] = testComplexChild;

        testAnyTypeElement6.setParam1(testComplexParents);

        try {
            OMElement omElement = testAnyTypeElement6.getOMElement(
                    TestAnyTypeElement6.MY_QNAME,OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(
                    new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement6 result = TestAnyTypeElement6.Factory.parse(xmlReader);
            TestComplexParent resultParent = (TestComplexParent) result.getParam1()[0];
            assertEquals(resultParent.getParam1(),"test param1");
            TestComplexChild resultChild = (TestComplexChild) result.getParam1()[1];
            assertEquals(resultChild.getParam1(), "test param1");
            assertEquals(resultChild.getParam2(), 3);
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            e.printStackTrace();
            fail();
        }
    }

    public void testAnyTypeElement7() {
        TestAnyTypeElement7 testAnyTypeElement;

        testAnyTypeElement = new TestAnyTypeElement7();
        testAnyTypeElement.setParam1("test");
        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement7.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement7 result = TestAnyTypeElement7.Factory.parse(xmlReader);
            assertEquals(result.getParam1(),"test");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

        testAnyTypeElement = new TestAnyTypeElement7();
        testAnyTypeElement.setParam1(null);
        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement7.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement7 result = TestAnyTypeElement7.Factory.parse(xmlReader);
            assertEquals(result.getParam1(),null);
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testAnyTypeElement71(){
        TestAnyTypeElement7 testAnyTypeElement7 = new TestAnyTypeElement7();
        TestComplexParent testComplexParent = new TestComplexParent();
        testComplexParent.setParam1("test param1");
        testAnyTypeElement7.setParam1(testComplexParent);

        try {
            OMElement omElement = testAnyTypeElement7.getOMElement(
                    TestAnyTypeElement7.MY_QNAME,OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(
                    new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement7 result = TestAnyTypeElement7.Factory.parse(xmlReader);
            TestComplexParent resultParent = (TestComplexParent) result.getParam1();
            assertEquals(resultParent.getParam1(),"test param1");

        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testAnyTypeElement8() {
        TestAnyTypeElement8 testAnyTypeElement;

        testAnyTypeElement = new TestAnyTypeElement8();
        testAnyTypeElement.setParam1("test");
        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement8.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement8 result = TestAnyTypeElement8.Factory.parse(xmlReader);
            assertEquals(result.getParam1(),"test");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

        testAnyTypeElement = new TestAnyTypeElement8();
        testAnyTypeElement.setParam1(null);
        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement8.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement8 result = TestAnyTypeElement8.Factory.parse(xmlReader);
            assertEquals(result.getParam1(),null);
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testAnyTypeElement9() {
        TestAnyTypeElement9 testAnyTypeElement;

        testAnyTypeElement = new TestAnyTypeElement9();
        testAnyTypeElement.setParam1("test");
        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement9.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement9 result = TestAnyTypeElement9.Factory.parse(xmlReader);
            assertEquals(result.getParam1(),"test");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

        testAnyTypeElement = new TestAnyTypeElement9();
        testAnyTypeElement.setParam1(null);
        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement9.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement9 result = TestAnyTypeElement9.Factory.parse(xmlReader);
            assertEquals(result.getParam1(),null);
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testAnyTypeElement10() {
        TestAnyTypeElement10 testAnyTypeElement;

        testAnyTypeElement = new TestAnyTypeElement10();
        testAnyTypeElement.setParam1("test");
        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement10.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement10 result = TestAnyTypeElement10.Factory.parse(xmlReader);
            assertEquals(result.getParam1(),"test");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

        testAnyTypeElement = new TestAnyTypeElement10();
        testAnyTypeElement.setParam1(null);
        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement10.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            fail();
        } catch (ADBException e) {
            assertTrue(true);
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testAnyElementInteger(){
        // datatype tests
        TestAnyTypeElement1 testAnyTypeElement;
        testAnyTypeElement = new TestAnyTypeElement1();
        testAnyTypeElement.setTestAnyTypeElement1(new Integer(5));
        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement1.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement1 result = TestAnyTypeElement1.Factory.parse(xmlReader);
            assertEquals(result.getTestAnyTypeElement1(),new Integer(5));
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testAnyElementQName(){
        // datatype tests
        TestAnyTypeElement1 testAnyTypeElement;
        testAnyTypeElement = new TestAnyTypeElement1();
        testAnyTypeElement.setTestAnyTypeElement1(new QName("http://wso2.org","testElement"));
        try {
            OMElement omElement = testAnyTypeElement.getOMElement(TestAnyTypeElement1.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestAnyTypeElement1 result = TestAnyTypeElement1.Factory.parse(xmlReader);
            assertEquals(result.getTestAnyTypeElement1(),new QName("http://wso2.org","testElement"));
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testTestElement(){
        TestElement testElement = new TestElement();

        DynamicProperty[] dynamicProperties = new DynamicProperty[3];
        TestComplexParent testComplexParent = null;

        dynamicProperties[0] = new DynamicProperty();
        dynamicProperties[0].setName("test name");
        dynamicProperties[0].setVal(new Integer(5));

        dynamicProperties[1] = new DynamicProperty();
        dynamicProperties[1].setName("test name");
        testComplexParent = new TestComplexParent();
        testComplexParent.setParam1("test complext type");
        dynamicProperties[1].setVal(testComplexParent);

        TestSimpleType testSimpleType = new TestSimpleType();
        testSimpleType.setTestSimpleType("test simple string");
        dynamicProperties[2] = new DynamicProperty();
        dynamicProperties[2].setName("test name");
        dynamicProperties[2].setVal(testSimpleType);


        testElement.setParam1(dynamicProperties);

        try {
            OMElement omElement = testElement.getOMElement(
                    TestElement.MY_QNAME,OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(
                    new ByteArrayInputStream(omElementString.getBytes()));
            TestElement result = TestElement.Factory.parse(xmlReader);
            DynamicProperty[] resultProperties = result.getParam1();
            assertEquals(resultProperties[0].getName(), "test name");
            assertEquals(resultProperties[0].getVal(), new Integer(5));
            assertEquals(resultProperties[1].getName(), "test name");
            assertEquals(((TestComplexParent)resultProperties[1].getVal()).getParam1(), "test complext type");
            assertEquals(resultProperties[2].getName(), "test name");
            assertEquals(((TestSimpleType)resultProperties[2].getVal()).getTestSimpleType(),"test simple string");

        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }
}


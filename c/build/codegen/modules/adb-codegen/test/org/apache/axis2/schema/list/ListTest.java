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

package org.apache.axis2.schema.list;

import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import test.axis2.apache.org.*;

import javax.xml.namespace.QName;
import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;


public class ListTest extends TestCase {


    public void testListString(){

        TestListStringElement testListStringElement = new TestListStringElement();
        TestListString testListString = new TestListString();
        testListStringElement.setTestListStringElement(testListString);
        testListString.setString(new String[]{"string1","string2"});

       try {
           OMElement omElement = testListStringElement.getOMElement(TestListStringElement.MY_QNAME,
                       OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestListStringElement result = TestListStringElement.Factory.parse(xmlReader);
            assertEquals(testListString.toString(),result.getTestListStringElement().toString());
        } catch (Exception e) {
            assertFalse(true);
        }

    }

    public void testListQName(){

        TestListQNameElement testListQNameElement = new TestListQNameElement();
        TestListQName testListQName = new TestListQName();
        testListQName.setQName(new QName[]{new QName("http://www.google.com","test1"),
                        new QName("http://www.google.com","test2"),
                        new QName("http://www.google","test3")});
        testListQNameElement.setTestListQNameElement(testListQName);

        try {
            OMElement omElement = testListQNameElement.getOMElement(TestListQNameElement.MY_QNAME,OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestListQNameElement result = TestListQNameElement.Factory.parse(xmlReader);
            assertEquals(result.getTestListQNameElement().getQName()[0],testListQName.getQName()[0]);
            assertEquals(result.getTestListQNameElement().getQName()[1],testListQName.getQName()[1]);
            assertEquals(result.getTestListQNameElement().getQName()[2],testListQName.getQName()[2]);
        } catch (Exception e) {
            assertFalse(true);
        }
    }

    public void testListOurs(){

        TestListOursElement testListOursElement = new TestListOursElement();
        TestListOurs testListOurs = new TestListOurs();
        testListOursElement.setTestListOursElement(testListOurs);
        TestString testString1 = new TestString();
        testString1.setTestString("test");
        TestString testString2 = new TestString();
        testString2.setTestString("test");
        TestString testString3 = new TestString();
        testString3.setTestString("test");
        testListOurs.setTestString(new TestString[]{testString1,testString2,testString3});

        try {
            OMElement omElement = testListOursElement.getOMElement(TestListOursElement.MY_QNAME,OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestListOursElement result = TestListOursElement.Factory.parse(xmlReader);
            assertEquals(result.getTestListOursElement().getTestString()[0].getTestString(),testString1.getTestString());
            assertEquals(result.getTestListOursElement().getTestString()[1].getTestString(),testString2.getTestString());
            assertEquals(result.getTestListOursElement().getTestString()[2].getTestString(),testString3.getTestString());
        } catch (Exception e) {
            assertFalse(true);
        }
    }

    public void testListSuper(){

        SuperTestListStringElement superTestListStringElement = new SuperTestListStringElement();
        SuperTestListString superTestListString = new SuperTestListString();
        superTestListStringElement.setSuperTestListStringElement(superTestListString);
        superTestListString.setString(new String[]{"test1","test2","test3"});

       try {
           OMElement omElement = superTestListStringElement.getOMElement(SuperTestListStringElement.MY_QNAME,
                   OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            SuperTestListStringElement result = SuperTestListStringElement.Factory.parse(xmlReader);
            assertEquals(superTestListString.getString()[0],result.getSuperTestListStringElement().getString()[0]);
        } catch (Exception e) {
            assertTrue(false);
        }
    }

    public void testInnerSimpleTypes(){
        TestInnerListSimpleType testInnerListSimpleType = new TestInnerListSimpleType();
        InnerListSimpleType innerListSimpleType = new InnerListSimpleType();
        testInnerListSimpleType.setTestInnerListSimpleType(innerListSimpleType);
        InnerListSimpleType_type0[] list = new InnerListSimpleType_type0[2];
        list[0] = InnerListSimpleType_type0.Access;
        list[1] = InnerListSimpleType_type0.Exist;

        innerListSimpleType.setInnerListSimpleType_type0(list);

         try {
             OMElement omElement = testInnerListSimpleType.getOMElement(TestInnerListSimpleType.MY_QNAME,
                      OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerListSimpleType result = TestInnerListSimpleType.Factory.parse(xmlReader);
            assertEquals(result.getTestInnerListSimpleType().getInnerListSimpleType_type0()[0],InnerListSimpleType_type0.Access);
            assertEquals(result.getTestInnerListSimpleType().getInnerListSimpleType_type0()[1],InnerListSimpleType_type0.Exist);
        } catch (Exception e) {
            assertTrue(false);
        }

    }


}

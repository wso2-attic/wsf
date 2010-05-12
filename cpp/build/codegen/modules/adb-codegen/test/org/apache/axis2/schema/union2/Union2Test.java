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

package org.apache.axis2.schema.union2;

import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import org.apache.axis2.databinding.ADBException;
import org.tempuri.union2.*;

import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;
import java.util.Date;


public class Union2Test extends TestCase {

    public void testUnionElement2() {
        TestUnionElement2 testUnionElement2 = new TestUnionElement2();

        TestUnion1 param1 = new TestUnion1();
        param1.setObject(Boolean.TRUE);
        testUnionElement2.setParam1(param1);

        TestUnion1 attribute1 = new TestUnion1();
        attribute1.setObject("test attribute");

        testUnionElement2.setAttribute1(attribute1);

        try {
            OMElement omElement = testUnionElement2.getOMElement(
                    TestUnionElement2.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader =
                    StAXUtils.createXMLStreamReader(
                            new ByteArrayInputStream(omElementString.getBytes()));
            TestUnionElement2 result = TestUnionElement2.Factory.parse(xmlReader);
            assertEquals(result.getParam1().getObject(), Boolean.TRUE);
            assertEquals(result.getAttribute1().getObject(), "test attribute");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testListElement2() {
        TestListElement1 testListElement1 = new TestListElement1();

        TestList1 param1 = new TestList1();
        param1.setString(new String[]{"param1", "param2"});
        testListElement1.setParam1(param1);

        TestList1 attribute1 = new TestList1();
        attribute1.setString(new String[]{"attribute1","attribute2"});
        testListElement1.setAttribute1(attribute1);

        try {
            OMElement omElement = testListElement1.getOMElement(
                    TestListElement1.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element String ==> " + omElementString);
            XMLStreamReader xmlReader =
                    StAXUtils.createXMLStreamReader(
                            new ByteArrayInputStream(omElementString.getBytes()));
            TestListElement1 result = TestListElement1.Factory.parse(xmlReader);
            assertEquals(result.getParam1().getString()[0], "param1");
            assertEquals(result.getParam1().getString()[1], "param2");
            assertEquals(result.getAttribute1().getString()[0], "attribute1");
            assertEquals(result.getAttribute1().getString()[1], "attribute2");
        } catch (ADBException e) {
            e.printStackTrace();
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

    }

    public void testFuzzDateType(){
        TestFuzzyDateType testFuzzyDateType = new TestFuzzyDateType();

        FuzzyDateType fuzzyDateType = new FuzzyDateType();
        fuzzyDateType.setObject(new Date());

        testFuzzyDateType.setTestFuzzyDateType(fuzzyDateType);

        try {
            OMElement omElement = testFuzzyDateType.getOMElement(
                    TestFuzzyDateType.MY_QNAME,OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader =
                    StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestFuzzyDateType result = TestFuzzyDateType.Factory.parse(xmlReader);
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }
}

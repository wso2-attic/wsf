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

package org.apache.axis2.schema.union;

import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import org.apache.axis2.databinding.types.URI;
import org.tempuri.union.*;

import javax.xml.namespace.QName;
import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;

public class UnionTest extends TestCase {

    public void testRecord2(){
        Object result;
        result = testRecord2(new Integer(10));
        assertEquals(result,new Integer(10));
        result = testRecord2(new Boolean(true));
        assertEquals(result,new Boolean(true));
    }

    private Object testRecord2(Object testObject) {
        Record2 record2 = new Record2();
        DateOrDateTimeType dateOrDateTimeType = new DateOrDateTimeType();
        record2.setElem1(dateOrDateTimeType);
        dateOrDateTimeType.setObject(testObject);

        try {
            OMElement omElement = record2.getOMElement(Record2.MY_QNAME,
                     OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            Record2 newRecord2 = Record2.Factory.parse(xmlReader);
            return newRecord2.getElem1().getObject();
        } catch (Exception e) {
            assertFalse(true);
        }
        return null;
    }

    public void testRecord1() {
        Object result;
        try {
            result = testRecord1(new URI("http://www.google.com"));
            assertEquals(result,new URI("http://www.google.com"));
            result = testRecord1(FooEnum._value1);
            assertEquals(result,FooEnum._value1);
        } catch (URI.MalformedURIException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private Object testRecord1(Object testObject) {
        Record1 record1 = new Record1();
        FooOpenEnum fooOpenEnum = new FooOpenEnum();
        record1.setElem1(fooOpenEnum);
        try {
            fooOpenEnum.setObject(testObject);
            OMElement omElement = record1.getOMElement(Record1.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            Record1 newRecord1 = Record1.Factory.parse(xmlReader);
            return newRecord1.getElem1().getObject();
        } catch (Exception e) {
            assertFalse(true);
        }
        return null;
    }

    public void testUnionQName(){
        UnionQNameTestElement unionQNameTestElement = new UnionQNameTestElement();
        UnionQNameTest unionQNameTest = new UnionQNameTest();
        unionQNameTestElement.setUnionQNameTestElement(unionQNameTest);
        unionQNameTest.setObject(new QName("http://www.google.com","test"));

        try {
            OMElement omElement = unionQNameTestElement.getOMElement(UnionQNameTestElement.MY_QNAME,OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            UnionQNameTestElement result = UnionQNameTestElement.Factory.parse(xmlReader);
            assertEquals(unionQNameTest.getObject(),result.getUnionQNameTestElement().getObject());
        } catch (Exception e) {
            assertTrue(false);
        }
    }

    public void testInnerSimpleTypes(){
        TestInnerUnionType testInnerUnionType = new TestInnerUnionType();
        PackingType_T packingType_t = new PackingType_T();
        testInnerUnionType.setTestInnerUnionType(packingType_t);
        PackingType_T_type0 packingType_t_type0 = new PackingType_T_type0();
        packingType_t_type0.setPackingType_T_type0("MINOR_a");
        packingType_t.setObject(packingType_t_type0);
        OMElement omElement;
        try {
            omElement = testInnerUnionType.getOMElement(TestInnerUnionType.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerUnionType result = TestInnerUnionType.Factory.parse(xmlReader);
            assertEquals(packingType_t_type0.toString(),result.getTestInnerUnionType().getObject().toString());
        } catch (Exception e) {
            assertTrue(false);
        }

        testInnerUnionType = new TestInnerUnionType();
        packingType_t = new PackingType_T();
        testInnerUnionType.setTestInnerUnionType(packingType_t);
        PackingType_T_type1 packingType_t_type1 = new PackingType_T_type1();
        packingType_t_type1.setPackingType_T_type1("PROP_a");
        packingType_t.setObject(packingType_t_type1);

         try {
            omElement = testInnerUnionType.getOMElement(TestInnerUnionType.MY_QNAME,OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerUnionType result = TestInnerUnionType.Factory.parse(xmlReader);
            assertEquals(packingType_t_type1.toString(),result.getTestInnerUnionType().getObject().toString());
        } catch (Exception e) {
            assertTrue(false);
        }

        testInnerUnionType = new TestInnerUnionType();
        packingType_t = new PackingType_T();
        testInnerUnionType.setTestInnerUnionType(packingType_t);
        packingType_t.setObject(PackingType_T_type2.TAR);

        try {
            omElement = testInnerUnionType.getOMElement(TestInnerUnionType.MY_QNAME,OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerUnionType result = TestInnerUnionType.Factory.parse(xmlReader);
            assertEquals(PackingType_T_type2.TAR,result.getTestInnerUnionType().getObject());
        } catch (Exception e) {
            assertTrue(false);
        }


    }
}

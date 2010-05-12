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

package org.apache.axis2.schema.restriction;

import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import org.tempuri.Address;
import org.tempuri.ComplexRestrictionTypeTestElement;
import org.tempuri.EnumerationSimpleTypeElement;
import org.tempuri.HairColor_type1;
import org.tempuri.NormalSimpleTypeElement;
import org.tempuri.ParentEnumerationSimpleType;
import org.tempuri.ParentNormalSimpleType;
import org.tempuri.ParentRestrictionType;
import org.tempuri.ParentSimpleType;
import org.tempuri.Person;
import org.tempuri.PersonElement;
import org.tempuri.TestSimpleAttribute;
import org.tempuri.TestSimpleAttributeElement;
import org.tempuri.Zip_type1;

import javax.xml.namespace.QName;
import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;
import java.util.Date;


public class SimpleRestrictionTest extends TestCase {

    public void testSimpleAttribute() {

        TestSimpleAttributeElement testSimpleAttributeElement = new TestSimpleAttributeElement();

        TestSimpleAttribute testSimpleAttribute = new TestSimpleAttribute();
        testSimpleAttributeElement.setTestSimpleAttributeElement(testSimpleAttribute);
        testSimpleAttribute.setTestElement1(new QName("http://wso2.com", "test1"));
        testSimpleAttribute.setTestElement2(new QName("http://wso2.com", "test2"));
        testSimpleAttribute.setTestElement3(new QName("http://wso2.com", "test3"));

        ParentSimpleType parentSimpleType1 = new ParentSimpleType();
        parentSimpleType1.setChildSimpleType("test simple type 1");

        ParentSimpleType parentSimpleType2 = new ParentSimpleType();
        parentSimpleType2.setChildSimpleType("test simple type 2");

        testSimpleAttribute.setAttrib1(parentSimpleType1);
        testSimpleAttribute.setAttrib2(parentSimpleType2);

         try {
             OMElement omElement = testSimpleAttributeElement.getOMElement(TestSimpleAttributeElement.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestSimpleAttributeElement result = TestSimpleAttributeElement.Factory.parse(xmlReader);
            assertEquals(result.getTestSimpleAttributeElement().getTestElement1(), testSimpleAttribute.getTestElement1());
            assertEquals(result.getTestSimpleAttributeElement().getTestElement2(), testSimpleAttribute.getTestElement2());
            assertEquals(result.getTestSimpleAttributeElement().getTestElement3(), testSimpleAttribute.getTestElement3());
            assertEquals(result.getTestSimpleAttributeElement().getAttrib1().getChildSimpleType(), parentSimpleType1.getChildSimpleType());
            assertEquals(result.getTestSimpleAttributeElement().getAttrib2().getChildSimpleType(), parentSimpleType2.getChildSimpleType());
        } catch (Exception e) {
            assertFalse(true);
        }

    }

    public void testNormalSimpleTypeElement() {

        NormalSimpleTypeElement normalSimpleTypeElement = new NormalSimpleTypeElement();
        ParentNormalSimpleType parentNormalSimpleType = new ParentNormalSimpleType();
        normalSimpleTypeElement.setNormalSimpleTypeElement(parentNormalSimpleType);
        parentNormalSimpleType.setNormalSimpleType(new QName("http://wso2.com", "test"));

        try {
            OMElement omElement = normalSimpleTypeElement.getOMElement(NormalSimpleTypeElement.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            NormalSimpleTypeElement result = NormalSimpleTypeElement.Factory.parse(xmlReader);
            assertEquals(result.getNormalSimpleTypeElement().getNormalSimpleType(), parentNormalSimpleType.getNormalSimpleType());
        } catch (Exception e) {
            assertFalse(true);
        }


    }

    public void testEnumerationSimpleTypeElement() {

        EnumerationSimpleTypeElement enumerationSimpleTypeElement = new EnumerationSimpleTypeElement();
        enumerationSimpleTypeElement.setEnumerationSimpleTypeElement(ParentEnumerationSimpleType.value1);

        try {
            OMElement omElement = enumerationSimpleTypeElement.getOMElement(EnumerationSimpleTypeElement.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            EnumerationSimpleTypeElement result = EnumerationSimpleTypeElement.Factory.parse(xmlReader);
            assertEquals(result.getEnumerationSimpleTypeElement().getValue(), ParentEnumerationSimpleType.value1.getValue());
        } catch (Exception e) {
            assertFalse(true);
        }

    }

    public void testComplexRestrictionType() {

        ComplexRestrictionTypeTestElement complexRestrictionTypeTestElement = new ComplexRestrictionTypeTestElement();
        ParentRestrictionType parentRestrictionType = new ParentRestrictionType();
        complexRestrictionTypeTestElement.setComplexRestrictionTypeTestElement(parentRestrictionType);
        parentRestrictionType.setBaseTypeElement1("test 1");
        parentRestrictionType.setBaseTypeElement2(5);

         try {
            OMElement omElement = complexRestrictionTypeTestElement.getOMElement(ComplexRestrictionTypeTestElement.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            ComplexRestrictionTypeTestElement result = ComplexRestrictionTypeTestElement.Factory.parse(xmlReader);
            assertEquals(result.getComplexRestrictionTypeTestElement().getBaseTypeElement1(), parentRestrictionType.getBaseTypeElement1());
            assertEquals(result.getComplexRestrictionTypeTestElement().getBaseTypeElement2(), parentRestrictionType.getBaseTypeElement2());
        } catch (Exception e) {
            e.printStackTrace();
            assertFalse(true);
        }

    }

    public void testPersonElement() {
        PersonElement personElement = new PersonElement();
        Person person = new Person();
        personElement.setPersonElement(person);
        person.setName("amila");
        person.setAge(23);
        person.setHairColor(HairColor_type1.black);
        Date date = new Date();
        person.setBirthDate(date);
        Address address = new Address();
        person.setAddress(address);
        address.setCity("Galle");
        address.setLine1("line1");
        address.setLine2("line2");
        address.setState("state");
        Zip_type1 ziptype = new Zip_type1();
        address.setZip(ziptype);
        ziptype.setZip_type0("C");

        try {
            OMElement omElement = personElement.getOMElement(ComplexRestrictionTypeTestElement.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            PersonElement result = PersonElement.Factory.parse(xmlReader);
            assertEquals(result.getPersonElement().getName(),"amila");
            assertEquals(result.getPersonElement().getAge(),23);
            assertEquals(result.getPersonElement().getHairColor(),HairColor_type1.black);
            Address resultAddress = result.getPersonElement().getAddress();
            assertEquals(resultAddress.getCity(),"Galle");
            assertEquals(resultAddress.getLine1(),"line1");
            assertEquals(resultAddress.getLine2(),"line2");
            assertEquals(resultAddress.getState(),"state");
            assertEquals(resultAddress.getZip().getZip_type0(),"C");
        } catch (Exception e) {
            e.printStackTrace();
            assertFalse(true);
        }


    }


}

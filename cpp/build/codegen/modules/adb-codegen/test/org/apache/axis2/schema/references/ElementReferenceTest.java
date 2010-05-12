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

package org.apache.axis2.schema.references;

import com.americanexpress.www.wsdl.ctn.utilities.atb.*;
import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import org.apache.axis2.databinding.ADBException;

import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;


public class ElementReferenceTest extends TestCase {

    public void testSingleElementReference() {
        CheckEligibility1 echCheckEligibility1 = new CheckEligibility1();
        AtbRequestCheckEligibility_type0 atbRequestCheckEligibility = new AtbRequestCheckEligibility_type0();
        echCheckEligibility1.setAtbRequestCheckEligibility(atbRequestCheckEligibility);
        atbRequestCheckEligibility.setCardNumber("carnumber");
        atbRequestCheckEligibility.setClientId("clientid");
        atbRequestCheckEligibility.setExpirationDate("date");
        atbRequestCheckEligibility.setNameAsOnCard("cardname");
        atbRequestCheckEligibility.setYearOfRedemption(2);


        try {
            OMElement omElement = echCheckEligibility1.getOMElement(CheckEligibility1.MY_QNAME, OMAbstractFactory.getSOAP12Factory());
            String omElementString = omElement.toStringWithConsume();
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            CheckEligibility1 result = CheckEligibility1.Factory.parse(xmlReader);
            assertEquals(result.getAtbRequestCheckEligibility().getCardNumber(), "carnumber");
            assertEquals(result.getAtbRequestCheckEligibility().getClientId(), "clientid");
            assertEquals(result.getAtbRequestCheckEligibility().getExpirationDate(), "date");
            assertEquals(result.getAtbRequestCheckEligibility().getNameAsOnCard(), "cardname");
            assertEquals(result.getAtbRequestCheckEligibility().getYearOfRedemption(), 2);
        } catch (Exception e) {
            fail();
        }
    }

    public void testMultipleElementReference() {
        CheckEligibility2 echCheckEligibility2 = new CheckEligibility2();
        AtbRequestCheckEligibility_type0[] atbRequestCheckEligibility = new AtbRequestCheckEligibility_type0[2];
        echCheckEligibility2.setAtbRequestCheckEligibility(atbRequestCheckEligibility);

        atbRequestCheckEligibility[0] = new AtbRequestCheckEligibility_type0();
        atbRequestCheckEligibility[0].setCardNumber("carnumber");
        atbRequestCheckEligibility[0].setClientId("clientid");
        atbRequestCheckEligibility[0].setExpirationDate("date");
        atbRequestCheckEligibility[0].setNameAsOnCard("cardname");
        atbRequestCheckEligibility[0].setYearOfRedemption(2);

        atbRequestCheckEligibility[1] = new AtbRequestCheckEligibility_type0();
        atbRequestCheckEligibility[1].setCardNumber("carnumber");
        atbRequestCheckEligibility[1].setClientId("clientid");
        atbRequestCheckEligibility[1].setExpirationDate("date");
        atbRequestCheckEligibility[1].setNameAsOnCard("cardname");
        atbRequestCheckEligibility[1].setYearOfRedemption(2);


        try {
            OMElement omElement = echCheckEligibility2.getOMElement(CheckEligibility2.MY_QNAME, OMAbstractFactory.getSOAP12Factory());
            String omElementString = omElement.toStringWithConsume();
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            CheckEligibility2 result = CheckEligibility2.Factory.parse(xmlReader);
            assertEquals(result.getAtbRequestCheckEligibility()[0].getCardNumber(), "carnumber");
            assertEquals(result.getAtbRequestCheckEligibility()[0].getClientId(), "clientid");
            assertEquals(result.getAtbRequestCheckEligibility()[0].getExpirationDate(), "date");
            assertEquals(result.getAtbRequestCheckEligibility()[0].getNameAsOnCard(), "cardname");
            assertEquals(result.getAtbRequestCheckEligibility()[0].getYearOfRedemption(), 2);

            assertEquals(result.getAtbRequestCheckEligibility()[1].getCardNumber(), "carnumber");
            assertEquals(result.getAtbRequestCheckEligibility()[1].getClientId(), "clientid");
            assertEquals(result.getAtbRequestCheckEligibility()[1].getExpirationDate(), "date");
            assertEquals(result.getAtbRequestCheckEligibility()[1].getNameAsOnCard(), "cardname");
            assertEquals(result.getAtbRequestCheckEligibility()[1].getYearOfRedemption(), 2);
        } catch (Exception e) {
            fail();
        }
    }

    public void testElement11(){

        Element1 element1 = new Element1();
        ComplexType1 complexType1 = new ComplexType1();
        element1.setElement1(complexType1);

        try {
            OMElement omElement = element1.getOMElement(Element1.MY_QNAME,OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            Element1 result = Element1.Factory.parse(xmlReader);
            assertNotNull(result);
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testElement12(){

        Element1 element1 = new Element1();
        ComplexType1 complexType1 = new ComplexType1();
        element1.setElement1(complexType1);
        ComplexType1 complexType2 = new ComplexType1();
        complexType1.setElement1(complexType2);
        ComplexType1 complexType3 = new ComplexType1();
        complexType2.setElement1(complexType3);


        try {
            OMElement omElement = element1.getOMElement(Element1.MY_QNAME,OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            Element1 result = Element1.Factory.parse(xmlReader);
            assertNotNull(result);
            assertNotNull(result.getElement1());
            assertNotNull(result.getElement1().getElement1());
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testElement21(){
        Element2 element2 = new Element2();
        Element2_type0 element2_type0 = new Element2_type0();
        element2.setElement2(element2_type0);
        element2_type0.setParam1("test string1");

        Element2_type0 element2_type1 = new Element2_type0();
        element2_type1.setParam1("test string2");
        element2_type0.setElement2(element2_type1);

        try {
            OMElement omElement = element2.getOMElement(Element2.MY_QNAME,OMAbstractFactory.getOMFactory());
            String omElmentString = omElement.toStringWithConsume();
            System.out.println("OM element ==>" + omElmentString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElmentString.getBytes()));
            Element2 result = Element2.Factory.parse(xmlReader);
            assertEquals(result.getElement2().getParam1(),"test string1");
            assertEquals(result.getElement2().getElement2().getParam1(), "test string2");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testSimpleReference() {
        TestSimpleReference testSimpleReference = new TestSimpleReference();
        Discard_transferToken discard_transferToken = new Discard_transferToken();
// FIXME: Breaks in IBM JDK 1.5 - the generated code there is looking for AuthInfo_type0 instead of AuthInfo_type1
//        AuthInfo_type1 authInfo_type1 = new AuthInfo_type1();
//        authInfo_type1.setAuthInfo_type1("Simple param");
//        discard_transferToken.setAuthInfo(authInfo_type1);
        discard_transferToken.setParam1("New parm");
        testSimpleReference.setTestSimpleReference(discard_transferToken);

        try {
            OMElement omElement = testSimpleReference.getOMElement(TestSimpleReference.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElmentString = omElement.toStringWithConsume();
            System.out.println("OM element ==>" + omElmentString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElmentString.getBytes()));
            TestSimpleReference result = TestSimpleReference.Factory.parse(xmlReader);
            assertEquals(result.getTestSimpleReference().getParam1(),"New parm");
// See FIXME above:
//            assertEquals(result.getTestSimpleReference().getAuthInfo().getAuthInfo_type1(),"Simple param");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }


    }


}

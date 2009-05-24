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

package org.apache.axis2.schema.innerparticles;

import com.mynamespace.testinnerparticle.*;
import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import org.apache.axis2.databinding.ADBException;

import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;



public class InnerParticlesTest extends TestCase {

    public void testInnerParticle1() {

        TestInnerParticle1 testInnerParticle1 = new TestInnerParticle1();
        testInnerParticle1.setParam1("Param1");
        TestInnerParticle1Sequence_type0 testInnerParticle1Sequence_type0 = new TestInnerParticle1Sequence_type0();
        testInnerParticle1Sequence_type0.setParam2("Param2");
        testInnerParticle1Sequence_type0.setParam3("Param3");
        testInnerParticle1.setTestInnerParticle1Sequence_type0(testInnerParticle1Sequence_type0);
        testInnerParticle1.setParam4("Param4");

         try {
            OMElement omElement = testInnerParticle1.getOMElement(TestInnerParticle1.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerParticle1 result = TestInnerParticle1.Factory.parse(xmlReader);
            assertEquals(result.getParam1(), "Param1");
            assertEquals(result.getTestInnerParticle1Sequence_type0().getParam2(), "Param2");
            assertEquals(result.getTestInnerParticle1Sequence_type0().getParam3(), "Param3");
            assertEquals(result.getParam4(), "Param4");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

    }

    public void testInnerParticle2() {

        TestInnerParticle2 testInnerParticle2 = new TestInnerParticle2();
        testInnerParticle2.setParam1("Param1");
        TestInnerParticle2Choice_type0 testInnerParticle2Choice_type1 = new TestInnerParticle2Choice_type0();
        testInnerParticle2Choice_type1.setParam2("Param2");
        testInnerParticle2Choice_type1.setParam3("Param3");
        testInnerParticle2.setTestInnerParticle2Choice_type0(testInnerParticle2Choice_type1);
        testInnerParticle2.setParam4("Param4");

       try {
            OMElement omElement =
                   testInnerParticle2.getOMElement(TestInnerParticle2.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerParticle2 result = TestInnerParticle2.Factory.parse(xmlReader);
            assertEquals(result.getParam1(), "Param1");
            assertEquals(result.getTestInnerParticle2Choice_type0().getParam3(), "Param3");
            assertEquals(result.getParam4(), "Param4");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

    }

    public void testInnerParticle31() {

        TestInnerParticle3 testInnerParticle3 = new TestInnerParticle3();
        testInnerParticle3.setParam1("Param1");

        try {
            OMElement omElement =
                     testInnerParticle3.getOMElement(TestInnerParticle3.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerParticle3 result = TestInnerParticle3.Factory.parse(xmlReader);
            assertEquals(result.getParam1(), "Param1");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

    }

    public void testInnerParticle32() {

        TestInnerParticle3 testInnerParticle3 = new TestInnerParticle3();
        TestInnerParticle3Choice_type0 testInnerParticle3Choice_type1 = new TestInnerParticle3Choice_type0();
        testInnerParticle3Choice_type1.setParam2("Param2");
        testInnerParticle3Choice_type1.setParam3("Param3");
        testInnerParticle3.setTestInnerParticle3Choice_type0(testInnerParticle3Choice_type1);

        try {
            OMElement omElement =
                    testInnerParticle3.getOMElement(TestInnerParticle3.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerParticle3 result = TestInnerParticle3.Factory.parse(xmlReader);
            assertEquals(result.getTestInnerParticle3Choice_type0().getParam3(), "Param3");
        } catch (XMLStreamException e) {
            e.printStackTrace();
            fail();
        } catch (Exception e) {
            e.printStackTrace();
            fail();
        }

    }

    public void testInnerParticle33() {

        TestInnerParticle3 testInnerParticle3 = new TestInnerParticle3();
        testInnerParticle3.setParam1("Param1");
        TestInnerParticle3Choice_type0 testInnerParticle3Choice_type1 = new TestInnerParticle3Choice_type0();
        testInnerParticle3Choice_type1.setParam2("Param2");
        testInnerParticle3Choice_type1.setParam3("Param3");
        testInnerParticle3.setTestInnerParticle3Choice_type0(testInnerParticle3Choice_type1);
        testInnerParticle3.setParam4("Param4");

         try {
             OMElement omElement =
                      testInnerParticle3.getOMElement(TestInnerParticle3.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerParticle3 result = TestInnerParticle3.Factory.parse(xmlReader);
            assertEquals(result.getParam4(), "Param4");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

    }

    public void testInnerParticle41() {

        TestInnerParticle4 testInnerParticle4 = new TestInnerParticle4();
        testInnerParticle4.setParam1("Param1");

         try {
             OMElement omElement =
                      testInnerParticle4.getOMElement(TestInnerParticle4.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerParticle4 result = TestInnerParticle4.Factory.parse(xmlReader);
            assertEquals(result.getParam1(), "Param1");
        } catch (XMLStreamException e) {
            e.printStackTrace();
            fail();
        } catch (Exception e) {
            e.printStackTrace();
            fail();
        }

    }

    public void testInnerParticle42() {

        TestInnerParticle4 testInnerParticle4 = new TestInnerParticle4();
        TestInnerParticle4Sequence_type0 TestInnerParticle4Sequence_type0 = new TestInnerParticle4Sequence_type0();
        TestInnerParticle4Sequence_type0.setParam2("Param2");
        TestInnerParticle4Sequence_type0.setParam3("Param3");
        testInnerParticle4.setTestInnerParticle4Sequence_type0(TestInnerParticle4Sequence_type0);

        try {
            OMElement omElement =
                     testInnerParticle4.getOMElement(TestInnerParticle4.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerParticle4 result = TestInnerParticle4.Factory.parse(xmlReader);
            assertEquals(result.getTestInnerParticle4Sequence_type0().getParam2(), "Param2");
            assertEquals(result.getTestInnerParticle4Sequence_type0().getParam3(), "Param3");
        } catch (XMLStreamException e) {
            e.printStackTrace();
            fail();
        } catch (Exception e) {
            e.printStackTrace();
            fail();
        }

    }

    public void testInnerParticle43() {

        TestInnerParticle4 testInnerParticle4 = new TestInnerParticle4();
        testInnerParticle4.setParam4("Param4");

         try {
            OMElement omElement =
                      testInnerParticle4.getOMElement(TestInnerParticle4.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerParticle4 result = TestInnerParticle4.Factory.parse(xmlReader);
            assertEquals(result.getParam4(), "Param4");
        } catch (XMLStreamException e) {
            e.printStackTrace();
            fail();
        } catch (Exception e) {
            e.printStackTrace();
            fail();
        }

    }

    public void testInnerParticle5() {

        TestInnerParticle5 testInnerParticle5 = new TestInnerParticle5();
        testInnerParticle5.setParam1("Param1");
        TestInnerParticle5Sequence_type1 testInnerParticle2Choice_type1 = new TestInnerParticle5Sequence_type1();
        testInnerParticle2Choice_type1.setParam2("Param2");
        testInnerParticle2Choice_type1.setParam3("Param3");

        TestInnerParticle5Sequence_type0 innerParticle5Sequence_type0 = new TestInnerParticle5Sequence_type0();
        innerParticle5Sequence_type0.setParam4("Param4");
        innerParticle5Sequence_type0.setParam5("Param5");

        testInnerParticle2Choice_type1.setTestInnerParticle5Sequence_type0(innerParticle5Sequence_type0);
        testInnerParticle5.setTestInnerParticle5Sequence_type1(testInnerParticle2Choice_type1);
        testInnerParticle5.setParam6("Param6");

        try {
            OMElement omElement =
                    testInnerParticle5.getOMElement(TestInnerParticle5.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerParticle5 result = TestInnerParticle5.Factory.parse(xmlReader);
            assertEquals(result.getParam1(), "Param1");
            assertEquals(result.getTestInnerParticle5Sequence_type1().getParam2(), "Param2");
            assertEquals(result.getTestInnerParticle5Sequence_type1().getParam3(), "Param3");
            assertEquals(result.getTestInnerParticle5Sequence_type1().getTestInnerParticle5Sequence_type0().getParam4(), "Param4");
            assertEquals(result.getTestInnerParticle5Sequence_type1().getTestInnerParticle5Sequence_type0().getParam5(), "Param5");
            assertEquals(result.getParam6(), "Param6");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }

    }

    public void testIntterParticalExtension(){
         TestInnterParticleExtension testInnterParticleExtension = new TestInnterParticleExtension();

        TestInnterParticleExtensionChildComplexType testInnterParticleExtensionChildComplexType =
                new TestInnterParticleExtensionChildComplexType();
        testInnterParticleExtension.setTestInnterParticleExtension(testInnterParticleExtensionChildComplexType);

        TestInnterParticleExtensionParentComplexTypeChoice_type0 testInnterParticleExtensionParentComplexTypeChoice_type0 =
                new TestInnterParticleExtensionParentComplexTypeChoice_type0();
        testInnterParticleExtensionChildComplexType.setTestInnterParticleExtensionParentComplexTypeChoice_type0(testInnterParticleExtensionParentComplexTypeChoice_type0);

        testInnterParticleExtensionParentComplexTypeChoice_type0.setParam1("param1");
        testInnterParticleExtensionParentComplexTypeChoice_type0.setParam2("param2");

        try {
            OMElement omElement = testInnterParticleExtension.getOMElement(TestInnterParticleExtension.MY_QNAME,
                                                            OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnterParticleExtension result = TestInnterParticleExtension.Factory.parse(xmlReader);
            assertTrue(result.getTestInnterParticleExtension() instanceof TestInnterParticleExtensionChildComplexType);
            TestInnterParticleExtensionChildComplexType resultComplexType =
                    (TestInnterParticleExtensionChildComplexType) result.getTestInnterParticleExtension();
            assertEquals(resultComplexType.getTestInnterParticleExtensionParentComplexTypeChoice_type0().getParam2(),"param2");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testTestComplexTypeElement(){
        TestComplexTypeElement testComplexTypeElement = new TestComplexTypeElement();

        TestComplexType testComplexType = new TestComplexType();
        testComplexTypeElement.setTestComplexTypeElement(testComplexType);

        TestElement_type0 testElement_type0 = new TestElement_type0();
        testElement_type0.setParam("param");
        testComplexType.setTestElement(testElement_type0);

        TestComplexTypeSequence_type0 testComplexTypeSequence_type0 = new TestComplexTypeSequence_type0();
        testComplexType.setTestComplexTypeSequence_type0(testComplexTypeSequence_type0);

        try {
            OMElement omElement = testComplexTypeElement.getOMElement(
                    TestComplexTypeElement.MY_QNAME,OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(
                    new ByteArrayInputStream(omElementString.getBytes()));
            TestComplexTypeElement result = TestComplexTypeElement.Factory.parse(xmlReader);
            assertEquals(result.getTestComplexTypeElement().getTestElement().getParam(),"param");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            e.printStackTrace();
            fail();
        }
    }


}

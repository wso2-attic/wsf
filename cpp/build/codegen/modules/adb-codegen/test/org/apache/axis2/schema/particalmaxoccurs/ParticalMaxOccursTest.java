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

package org.apache.axis2.schema.particalmaxoccurs;

import com.mynamespace.testparticlemaxoccurs.*;
import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;

import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;


public class ParticalMaxOccursTest extends TestCase {

    private int i = 0;

    public void testParticalSequenceMaxOccursTest1() {
        TestParticalSequenceMaxOccurs1 testParticalMaxOccures1 = new TestParticalSequenceMaxOccurs1();
        TestParticalSequenceMaxOccursType1 testParticalMaxOccursType1 = new TestParticalSequenceMaxOccursType1();
        testParticalMaxOccures1.setTestParticalSequenceMaxOccurs1(testParticalMaxOccursType1);

        TestParticalSequenceMaxOccursType1Sequence[] testSequences = new TestParticalSequenceMaxOccursType1Sequence[2];

        testSequences[0] = new TestParticalSequenceMaxOccursType1Sequence();
        testSequences[0].setParm1("Param11");
        testSequences[0].setParm2("Param12");

        testSequences[1] = new TestParticalSequenceMaxOccursType1Sequence();
        testSequences[1].setParm1("Param21");
        testSequences[1].setParm2("Param22");

        testParticalMaxOccursType1.setTestParticalSequenceMaxOccursType1Sequence(testSequences);

         try {
             OMElement omElement = testParticalMaxOccures1.getOMElement(TestParticalSequenceMaxOccurs1.MY_QNAME,
                       OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestParticalSequenceMaxOccurs1 result = TestParticalSequenceMaxOccurs1.Factory.parse(xmlReader);
            TestParticalSequenceMaxOccursType1Sequence[] resultSequences =
                    result.getTestParticalSequenceMaxOccurs1().getTestParticalSequenceMaxOccursType1Sequence();
            assertEquals(resultSequences[0].getParm1(), "Param11");
            assertEquals(resultSequences[0].getParm2(), "Param12");
            assertEquals(resultSequences[1].getParm1(), "Param21");
            assertEquals(resultSequences[1].getParm2(), "Param22");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testParticleSequenceMaxOccurs2() {
        TestParticalSequenceMaxOccurs2 testParticalMaxOccures2 = new TestParticalSequenceMaxOccurs2();
        TestParticalSequenceMaxOccursType2 testParticalMaxOccursType2 = new TestParticalSequenceMaxOccursType2();
        testParticalMaxOccures2.setTestParticalSequenceMaxOccurs2(testParticalMaxOccursType2);

        TestParticalSequenceMaxOccursType2Sequence[] testSequences = new TestParticalSequenceMaxOccursType2Sequence[2];

        testSequences[0] = new TestParticalSequenceMaxOccursType2Sequence();
        testSequences[0].setParm1(new String[]{"Param111", "Param112", "Param113"});
        testSequences[0].setParm2(new String[]{"Param111", "Param112", "Param113"});

        testSequences[1] = new TestParticalSequenceMaxOccursType2Sequence();
        testSequences[1].setParm1(new String[]{"Param121", "Param122", "Param123"});
        testSequences[1].setParm2(new String[]{"Param121", "Param122", "Param123"});

        testParticalMaxOccursType2.setTestParticalSequenceMaxOccursType2Sequence(testSequences);

        try {
            OMElement omElement = testParticalMaxOccures2.getOMElement(TestParticalSequenceMaxOccurs2.MY_QNAME,
                     OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestParticalSequenceMaxOccurs2 result = TestParticalSequenceMaxOccurs2.Factory.parse(xmlReader);
            TestParticalSequenceMaxOccursType2Sequence[] resultSequences =
                    result.getTestParticalSequenceMaxOccurs2().getTestParticalSequenceMaxOccursType2Sequence();
            assertEquals(resultSequences[0].getParm1()[0], "Param111");
            assertEquals(resultSequences[0].getParm1()[1], "Param112");
            assertEquals(resultSequences[0].getParm1()[2], "Param113");
            assertEquals(resultSequences[1].getParm2()[0], "Param121");
            assertEquals(resultSequences[1].getParm2()[1], "Param122");
            assertEquals(resultSequences[1].getParm2()[2], "Param123");
        } catch (XMLStreamException e) {
            e.printStackTrace();
            fail();
        } catch (Exception e) {
            e.printStackTrace();
            fail();
        }
    }

    public void testParticleSequenceMaxOccurs3() {
        TestParticalSequenceMaxOccurs3 testParticalMaxOccures3 = new TestParticalSequenceMaxOccurs3();
        TestParticalSequenceMaxOccursType3 testParticalMaxOccursType3 = new TestParticalSequenceMaxOccursType3();
        testParticalMaxOccures3.setTestParticalSequenceMaxOccurs3(testParticalMaxOccursType3);

        TestParticalSequenceMaxOccursType3Sequence[] testSequences = new TestParticalSequenceMaxOccursType3Sequence[2];

        testSequences[0] = new TestParticalSequenceMaxOccursType3Sequence();
        testSequences[0].setParm2(new String[]{"Param111", null, "Param113"});

        testSequences[1] = new TestParticalSequenceMaxOccursType3Sequence();
        testSequences[1].setParm1(new String[]{"Param121", "Param122", null});

        testParticalMaxOccursType3.setTestParticalSequenceMaxOccursType3Sequence(testSequences);

        try {
            OMElement omElement = testParticalMaxOccures3.getOMElement(TestParticalSequenceMaxOccurs3.MY_QNAME,
                      OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestParticalSequenceMaxOccurs3 result = TestParticalSequenceMaxOccurs3.Factory.parse(xmlReader);
            TestParticalSequenceMaxOccursType3Sequence[] resultSequences =
                    result.getTestParticalSequenceMaxOccurs3().getTestParticalSequenceMaxOccursType3Sequence();
            assertEquals(resultSequences[0].getParm2()[0], "Param111");
            assertEquals(resultSequences[0].getParm2()[1], null);
            assertEquals(resultSequences[0].getParm2()[2], "Param113");
            assertEquals(resultSequences[1].getParm1()[0], "Param121");
            assertEquals(resultSequences[1].getParm1()[1], "Param122");
            assertEquals(resultSequences[1].getParm1()[2], null);
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testParticleSequenceMaxOccurs4() {

        TestParticalSequenceMaxOccurs4 testParticalSequenceMaxOccurs4 = new TestParticalSequenceMaxOccurs4();
        TestParticalSequenceMaxOccursType4 testParticalSequenceMaxOccursType4 = new TestParticalSequenceMaxOccursType4();
        testParticalSequenceMaxOccurs4.setTestParticalSequenceMaxOccurs4(testParticalSequenceMaxOccursType4);

        TestParticalSequenceMaxOccursType4Sequence[] testParticalSequenceMaxOccursType4Sequence =
                new TestParticalSequenceMaxOccursType4Sequence[3];

        testParticalSequenceMaxOccursType4.setTestParticalSequenceMaxOccursType4Sequence(testParticalSequenceMaxOccursType4Sequence);
        testParticalSequenceMaxOccursType4Sequence[0] = new TestParticalSequenceMaxOccursType4Sequence();
        testParticalSequenceMaxOccursType4Sequence[0].setParm1(getNewCustomType());

        testParticalSequenceMaxOccursType4Sequence[1] = new TestParticalSequenceMaxOccursType4Sequence();
        testParticalSequenceMaxOccursType4Sequence[1].setParm2("Param2");

        testParticalSequenceMaxOccursType4Sequence[2] = new TestParticalSequenceMaxOccursType4Sequence();
        testParticalSequenceMaxOccursType4Sequence[2].setParm3(getNewCustomType());

        try {
            OMElement omElement = testParticalSequenceMaxOccurs4.getOMElement(TestParticalSequenceMaxOccurs4.MY_QNAME,
                     OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestParticalSequenceMaxOccurs4 result = TestParticalSequenceMaxOccurs4.Factory.parse(xmlReader);
            TestParticalSequenceMaxOccursType4Sequence[] resultSequences =
                    result.getTestParticalSequenceMaxOccurs4().getTestParticalSequenceMaxOccursType4Sequence();
            assertTrue(isEqual(resultSequences[0].getParm1(), testParticalSequenceMaxOccursType4Sequence[0].getParm1()));
            assertTrue(isEqual(resultSequences[0].getParm2(), testParticalSequenceMaxOccursType4Sequence[0].getParm2()));
            assertTrue(isEqual(resultSequences[0].getParm3(), testParticalSequenceMaxOccursType4Sequence[0].getParm3()));

            assertTrue(isEqual(resultSequences[1].getParm1(), testParticalSequenceMaxOccursType4Sequence[1].getParm1()));
            assertTrue(isEqual(resultSequences[1].getParm2(), testParticalSequenceMaxOccursType4Sequence[1].getParm2()));
            assertTrue(isEqual(resultSequences[1].getParm3(), testParticalSequenceMaxOccursType4Sequence[1].getParm3()));

            assertTrue(isEqual(resultSequences[2].getParm1(), testParticalSequenceMaxOccursType4Sequence[2].getParm1()));
            assertTrue(isEqual(resultSequences[2].getParm2(), testParticalSequenceMaxOccursType4Sequence[2].getParm2()));
            assertTrue(isEqual(resultSequences[2].getParm3(), testParticalSequenceMaxOccursType4Sequence[2].getParm3()));

        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }


    }

    public void testParticleSequenceMaxOccurs5() {

        TestParticalSequenceMaxOccurs5 testParticalSequenceMaxOccurs5 = new TestParticalSequenceMaxOccurs5();
        TestParticalSequenceMaxOccursType5 testParticalSequenceMaxOccursType5 = new TestParticalSequenceMaxOccursType5();
        testParticalSequenceMaxOccurs5.setTestParticalSequenceMaxOccurs5(testParticalSequenceMaxOccursType5);

        TestParticalSequenceMaxOccursType5Sequence[] testParticalSequenceMaxOccursType5Sequence =
                new TestParticalSequenceMaxOccursType5Sequence[3];

        testParticalSequenceMaxOccursType5.setTestParticalSequenceMaxOccursType5Sequence(testParticalSequenceMaxOccursType5Sequence);

        testParticalSequenceMaxOccursType5Sequence[0] = new TestParticalSequenceMaxOccursType5Sequence();
        testParticalSequenceMaxOccursType5Sequence[0].setParm1(new TestCustomType[]{getNewCustomType()});
        testParticalSequenceMaxOccursType5Sequence[0].setParm3(new TestCustomType[]{getNewCustomType()});

        testParticalSequenceMaxOccursType5Sequence[1] = new TestParticalSequenceMaxOccursType5Sequence();
        testParticalSequenceMaxOccursType5Sequence[1].setParm1(new TestCustomType[]{getNewCustomType()});
        testParticalSequenceMaxOccursType5Sequence[1].setParm2("Param2");
        testParticalSequenceMaxOccursType5Sequence[1].setParm3(new TestCustomType[]{getNewCustomType()});

        testParticalSequenceMaxOccursType5Sequence[2] = new TestParticalSequenceMaxOccursType5Sequence();
        testParticalSequenceMaxOccursType5Sequence[2].setParm1(new TestCustomType[]{getNewCustomType()});
        testParticalSequenceMaxOccursType5Sequence[2].setParm3(new TestCustomType[]{getNewCustomType()});

        try {
            OMElement omElement = testParticalSequenceMaxOccurs5.getOMElement(TestParticalSequenceMaxOccurs5.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestParticalSequenceMaxOccurs5 result = TestParticalSequenceMaxOccurs5.Factory.parse(xmlReader);
            TestParticalSequenceMaxOccursType5Sequence[] resultSequences =
                    result.getTestParticalSequenceMaxOccurs5().getTestParticalSequenceMaxOccursType5Sequence();
            assertTrue(isEqual(resultSequences[0].getParm1(), testParticalSequenceMaxOccursType5Sequence[0].getParm1()));
            assertTrue(isEqual(resultSequences[0].getParm2(), testParticalSequenceMaxOccursType5Sequence[0].getParm2()));
            assertTrue(isEqual(resultSequences[0].getParm3(), testParticalSequenceMaxOccursType5Sequence[0].getParm3()));

            assertTrue(isEqual(resultSequences[1].getParm1(), testParticalSequenceMaxOccursType5Sequence[1].getParm1()));
            assertTrue(isEqual(resultSequences[1].getParm2(), testParticalSequenceMaxOccursType5Sequence[1].getParm2()));
            assertTrue(isEqual(resultSequences[1].getParm3(), testParticalSequenceMaxOccursType5Sequence[1].getParm3()));

            assertTrue(isEqual(resultSequences[2].getParm1(), testParticalSequenceMaxOccursType5Sequence[2].getParm1()));
            assertTrue(isEqual(resultSequences[2].getParm2(), testParticalSequenceMaxOccursType5Sequence[2].getParm2()));
            assertTrue(isEqual(resultSequences[2].getParm3(), testParticalSequenceMaxOccursType5Sequence[2].getParm3()));

        } catch (XMLStreamException e) {
            e.printStackTrace();
            fail();
        } catch (Exception e) {
            e.printStackTrace();
            fail();
        }


    }

    public void testParticalSequenceMaxOccursTest6() {
        TestParticalSequenceMaxOccurs6 testParticalMaxOccures6 = new TestParticalSequenceMaxOccurs6();
        TestParticalSequenceMaxOccursType6 testParticalMaxOccursType6 = new TestParticalSequenceMaxOccursType6();
        testParticalMaxOccures6.setTestParticalSequenceMaxOccurs6(testParticalMaxOccursType6);

        TestParticalSequenceMaxOccursType6Sequence[] testSequences = new TestParticalSequenceMaxOccursType6Sequence[2];

        testSequences[0] = new TestParticalSequenceMaxOccursType6Sequence();
        testSequences[0].setParm1("Param11");
        testSequences[0].setParm2("Param12");

        testSequences[1] = new TestParticalSequenceMaxOccursType6Sequence();
        testSequences[1].setParm1("Param21");
        testSequences[1].setParm2("Param22");

        testParticalMaxOccursType6.setTestParticalSequenceMaxOccursType6Sequence(testSequences);
        testParticalMaxOccursType6.setAttribute1("Attribute1");
        testParticalMaxOccursType6.setAttribute2("Attribute2");

        try {
            OMElement omElement = testParticalMaxOccures6.getOMElement(TestParticalSequenceMaxOccurs6.MY_QNAME,
                     OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestParticalSequenceMaxOccurs6 result = TestParticalSequenceMaxOccurs6.Factory.parse(xmlReader);
            TestParticalSequenceMaxOccursType6Sequence[] resultSequences =
                    result.getTestParticalSequenceMaxOccurs6().getTestParticalSequenceMaxOccursType6Sequence();
            assertEquals(resultSequences[0].getParm1(), "Param11");
            assertEquals(resultSequences[0].getParm2(), "Param12");
            assertEquals(resultSequences[1].getParm1(), "Param21");
            assertEquals(resultSequences[1].getParm2(), "Param22");
            assertEquals(result.getTestParticalSequenceMaxOccurs6().getAttribute1(), "Attribute1");
            assertEquals(result.getTestParticalSequenceMaxOccurs6().getAttribute2(), "Attribute2");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testParticalMaxOccursTest() {
        TestParticalChoiceMaxOccurs testParticalChoiceMaxOccurs = new TestParticalChoiceMaxOccurs();
        TestParticalChoiceMaxOccursType testParticalChoiceMaxOccursType = new TestParticalChoiceMaxOccursType();
        testParticalChoiceMaxOccurs.setTestParticalChoiceMaxOccurs(testParticalChoiceMaxOccursType);

        testParticalChoiceMaxOccursType.setParm1("Param1");

        try {
            OMElement omElement =
                     testParticalChoiceMaxOccurs.getOMElement(TestParticalChoiceMaxOccurs.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM string ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestParticalChoiceMaxOccurs result = TestParticalChoiceMaxOccurs.Factory.parse(xmlReader);
            assertEquals(result.getTestParticalChoiceMaxOccurs().getParm1(), "Param1");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testParticalChoiceMaxOccursTest1() {
        TestParticalChoiceMaxOccurs1 testParticalMaxOccures1 = new TestParticalChoiceMaxOccurs1();
        TestParticalChoiceMaxOccursType1 testParticalMaxOccursType1 = new TestParticalChoiceMaxOccursType1();
        testParticalMaxOccures1.setTestParticalChoiceMaxOccurs1(testParticalMaxOccursType1);

        TestParticalChoiceMaxOccursType1Choice[] testChoices = new TestParticalChoiceMaxOccursType1Choice[2];

        testChoices[0] = new TestParticalChoiceMaxOccursType1Choice();
        testChoices[0].setParm1("Param11");

        testChoices[1] = new TestParticalChoiceMaxOccursType1Choice();
        testChoices[1].setParm2("Param12");

        testParticalMaxOccursType1.setTestParticalChoiceMaxOccursType1Choice(testChoices);

       try {
            OMElement omElement = testParticalMaxOccures1.getOMElement(TestParticalChoiceMaxOccurs1.MY_QNAME,
                   OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestParticalChoiceMaxOccurs1 result = TestParticalChoiceMaxOccurs1.Factory.parse(xmlReader);
            TestParticalChoiceMaxOccursType1Choice[] resultChoices =
                    result.getTestParticalChoiceMaxOccurs1().getTestParticalChoiceMaxOccursType1Choice();
            assertEquals(resultChoices[0].getParm1(), "Param11");
            assertEquals(resultChoices[1].getParm2(), "Param12");
        } catch (XMLStreamException e) {
           e.printStackTrace();
            fail();
        } catch (Exception e) {
           e.printStackTrace();
            fail();
        }
    }

    public void testParticleChoiceMaxOccurs2() {
        TestParticalChoiceMaxOccurs2 testParticalMaxOccures2 = new TestParticalChoiceMaxOccurs2();
        TestParticalChoiceMaxOccursType2 testParticalMaxOccursType2 = new TestParticalChoiceMaxOccursType2();
        testParticalMaxOccures2.setTestParticalChoiceMaxOccurs2(testParticalMaxOccursType2);

        TestParticalChoiceMaxOccursType2Choice[] testChoices = new TestParticalChoiceMaxOccursType2Choice[2];

        testChoices[0] = new TestParticalChoiceMaxOccursType2Choice();
        testChoices[0].setParm1(new String[]{"Param111", "Param112", "Param113"});

        testChoices[1] = new TestParticalChoiceMaxOccursType2Choice();
        testChoices[1].setParm2(new String[]{"Param121", "Param122", "Param123"});

        testParticalMaxOccursType2.setTestParticalChoiceMaxOccursType2Choice(testChoices);

         try {
             OMElement omElement = testParticalMaxOccures2.getOMElement(TestParticalChoiceMaxOccurs2.MY_QNAME,
                      OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestParticalChoiceMaxOccurs2 result = TestParticalChoiceMaxOccurs2.Factory.parse(xmlReader);
            TestParticalChoiceMaxOccursType2Choice[] resultChoices =
                    result.getTestParticalChoiceMaxOccurs2().getTestParticalChoiceMaxOccursType2Choice();
            assertEquals(resultChoices[0].getParm1()[0], "Param111");
            assertEquals(resultChoices[0].getParm1()[1], "Param112");
            assertEquals(resultChoices[0].getParm1()[2], "Param113");
            assertEquals(resultChoices[1].getParm2()[0], "Param121");
            assertEquals(resultChoices[1].getParm2()[1], "Param122");
            assertEquals(resultChoices[1].getParm2()[2], "Param123");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testParticleChoiceMaxOccurs3() {
        TestParticalChoiceMaxOccurs3 testParticalMaxOccures3 = new TestParticalChoiceMaxOccurs3();
        TestParticalChoiceMaxOccursType3 testParticalMaxOccursType3 = new TestParticalChoiceMaxOccursType3();
        testParticalMaxOccures3.setTestParticalChoiceMaxOccurs3(testParticalMaxOccursType3);

        TestParticalChoiceMaxOccursType3Choice[] testChoices = new TestParticalChoiceMaxOccursType3Choice[2];

        testChoices[0] = new TestParticalChoiceMaxOccursType3Choice();
        testChoices[0].setParm1(new String[]{"Param111", null, "Param113"});

        testChoices[1] = new TestParticalChoiceMaxOccursType3Choice();
        testChoices[1].setParm2(new String[]{"Param121", "Param122", null});

        testParticalMaxOccursType3.setTestParticalChoiceMaxOccursType3Choice(testChoices);

        try {
            OMElement omElement = testParticalMaxOccures3.getOMElement(TestParticalChoiceMaxOccurs3.MY_QNAME,
                     OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestParticalChoiceMaxOccurs3 result = TestParticalChoiceMaxOccurs3.Factory.parse(xmlReader);
            TestParticalChoiceMaxOccursType3Choice[] resultChoices =
                    result.getTestParticalChoiceMaxOccurs3().getTestParticalChoiceMaxOccursType3Choice();
            assertEquals(resultChoices[0].getParm1()[0], "Param111");
            assertEquals(resultChoices[0].getParm1()[1], null);
            assertEquals(resultChoices[0].getParm1()[2], "Param113");
            assertEquals(resultChoices[1].getParm2()[0], "Param121");
            assertEquals(resultChoices[1].getParm2()[1], "Param122");
            assertEquals(resultChoices[1].getParm2()[2], null);
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testParticleChoiceMaxOccurs4() {

        TestParticalChoiceMaxOccurs4 testParticalChoiceMaxOccurs4 = new TestParticalChoiceMaxOccurs4();
        TestParticalChoiceMaxOccursType4 testParticalChoiceMaxOccursType4 = new TestParticalChoiceMaxOccursType4();
        testParticalChoiceMaxOccurs4.setTestParticalChoiceMaxOccurs4(testParticalChoiceMaxOccursType4);

        TestParticalChoiceMaxOccursType4Choice[] testParticalChoiceMaxOccursType4Choice =
                new TestParticalChoiceMaxOccursType4Choice[3];

        testParticalChoiceMaxOccursType4.setTestParticalChoiceMaxOccursType4Choice(testParticalChoiceMaxOccursType4Choice);
        testParticalChoiceMaxOccursType4Choice[0] = new TestParticalChoiceMaxOccursType4Choice();
        testParticalChoiceMaxOccursType4Choice[0].setParm1(getNewCustomType());

        testParticalChoiceMaxOccursType4Choice[1] = new TestParticalChoiceMaxOccursType4Choice();
        testParticalChoiceMaxOccursType4Choice[1].setParm2("Param2");

        testParticalChoiceMaxOccursType4Choice[2] = new TestParticalChoiceMaxOccursType4Choice();
        testParticalChoiceMaxOccursType4Choice[2].setParm3(getNewCustomType());

         try {
             OMElement omElement = testParticalChoiceMaxOccurs4.getOMElement(TestParticalChoiceMaxOccurs4.MY_QNAME,
                      OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestParticalChoiceMaxOccurs4 result = TestParticalChoiceMaxOccurs4.Factory.parse(xmlReader);
            TestParticalChoiceMaxOccursType4Choice[] resultChoices =
                    result.getTestParticalChoiceMaxOccurs4().getTestParticalChoiceMaxOccursType4Choice();
            assertTrue(isEqual(resultChoices[0].getParm1(), testParticalChoiceMaxOccursType4Choice[0].getParm1()));
            assertTrue(isEqual(resultChoices[0].getParm2(), testParticalChoiceMaxOccursType4Choice[0].getParm2()));
            assertTrue(isEqual(resultChoices[0].getParm3(), testParticalChoiceMaxOccursType4Choice[0].getParm3()));

            assertTrue(isEqual(resultChoices[1].getParm1(), testParticalChoiceMaxOccursType4Choice[1].getParm1()));
            assertTrue(isEqual(resultChoices[1].getParm2(), testParticalChoiceMaxOccursType4Choice[1].getParm2()));
            assertTrue(isEqual(resultChoices[1].getParm3(), testParticalChoiceMaxOccursType4Choice[1].getParm3()));

            assertTrue(isEqual(resultChoices[2].getParm1(), testParticalChoiceMaxOccursType4Choice[2].getParm1()));
            assertTrue(isEqual(resultChoices[2].getParm2(), testParticalChoiceMaxOccursType4Choice[2].getParm2()));
            assertTrue(isEqual(resultChoices[2].getParm3(), testParticalChoiceMaxOccursType4Choice[2].getParm3()));

        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }


    }

    public void testParticleChoiceMaxOccurs5() {

        TestParticalChoiceMaxOccurs5 testParticalChoiceMaxOccurs5 = new TestParticalChoiceMaxOccurs5();
        TestParticalChoiceMaxOccursType5 testParticalChoiceMaxOccursType5 = new TestParticalChoiceMaxOccursType5();
        testParticalChoiceMaxOccurs5.setTestParticalChoiceMaxOccurs5(testParticalChoiceMaxOccursType5);

        TestParticalChoiceMaxOccursType5Choice[] testParticalChoiceMaxOccursType5Choice =
                new TestParticalChoiceMaxOccursType5Choice[3];

        testParticalChoiceMaxOccursType5.setTestParticalChoiceMaxOccursType5Choice(testParticalChoiceMaxOccursType5Choice);

        testParticalChoiceMaxOccursType5Choice[0] = new TestParticalChoiceMaxOccursType5Choice();
        testParticalChoiceMaxOccursType5Choice[0].setParm1(new TestCustomType[]{getNewCustomType()});

        testParticalChoiceMaxOccursType5Choice[1] = new TestParticalChoiceMaxOccursType5Choice();
        testParticalChoiceMaxOccursType5Choice[1].setParm2("Param2");

        testParticalChoiceMaxOccursType5Choice[2] = new TestParticalChoiceMaxOccursType5Choice();
        testParticalChoiceMaxOccursType5Choice[2].setParm3(new TestCustomType[]{getNewCustomType()});

       try {
            OMElement omElement = testParticalChoiceMaxOccurs5.getOMElement(TestParticalChoiceMaxOccurs5.MY_QNAME,
                   OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestParticalChoiceMaxOccurs5 result = TestParticalChoiceMaxOccurs5.Factory.parse(xmlReader);
            TestParticalChoiceMaxOccursType5Choice[] resultChoices =
                    result.getTestParticalChoiceMaxOccurs5().getTestParticalChoiceMaxOccursType5Choice();
            assertTrue(isEqual(resultChoices[0].getParm1(), testParticalChoiceMaxOccursType5Choice[0].getParm1()));
            assertTrue(isEqual(resultChoices[0].getParm2(), testParticalChoiceMaxOccursType5Choice[0].getParm2()));
            assertTrue(isEqual(resultChoices[0].getParm3(), testParticalChoiceMaxOccursType5Choice[0].getParm3()));

            assertTrue(isEqual(resultChoices[1].getParm1(), testParticalChoiceMaxOccursType5Choice[1].getParm1()));
            assertTrue(isEqual(resultChoices[1].getParm2(), testParticalChoiceMaxOccursType5Choice[1].getParm2()));
            assertTrue(isEqual(resultChoices[1].getParm3(), testParticalChoiceMaxOccursType5Choice[1].getParm3()));

            assertTrue(isEqual(resultChoices[2].getParm1(), testParticalChoiceMaxOccursType5Choice[2].getParm1()));
            assertTrue(isEqual(resultChoices[2].getParm2(), testParticalChoiceMaxOccursType5Choice[2].getParm2()));
            assertTrue(isEqual(resultChoices[2].getParm3(), testParticalChoiceMaxOccursType5Choice[2].getParm3()));

        } catch (XMLStreamException e) {
            e.printStackTrace();
            fail();
        } catch (Exception e) {
            e.printStackTrace();
            fail();
        }


    }

    public void testParticalChoiceMaxOccursTest6() {
        TestParticalChoiceMaxOccurs6 testParticalMaxOccures6 = new TestParticalChoiceMaxOccurs6();
        TestParticalChoiceMaxOccursType6 testParticalMaxOccursType6 = new TestParticalChoiceMaxOccursType6();
        testParticalMaxOccures6.setTestParticalChoiceMaxOccurs6(testParticalMaxOccursType6);

        TestParticalChoiceMaxOccursType6Choice[] testChoices = new TestParticalChoiceMaxOccursType6Choice[2];

        testChoices[0] = new TestParticalChoiceMaxOccursType6Choice();
        testChoices[0].setParm1("Param11");

        testChoices[1] = new TestParticalChoiceMaxOccursType6Choice();
        testChoices[1].setParm2("Param12");

        testParticalMaxOccursType6.setTestParticalChoiceMaxOccursType6Choice(testChoices);
        testParticalMaxOccursType6.setAttribute1("Attribute1");
        testParticalMaxOccursType6.setAttribute2("Attribute2");

        try {
            OMElement omElement = testParticalMaxOccures6.getOMElement(TestParticalChoiceMaxOccurs6.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestParticalChoiceMaxOccurs6 result = TestParticalChoiceMaxOccurs6.Factory.parse(xmlReader);
            TestParticalChoiceMaxOccursType6Choice[] resultChoices =
                    result.getTestParticalChoiceMaxOccurs6().getTestParticalChoiceMaxOccursType6Choice();
            assertEquals(resultChoices[0].getParm1(), "Param11");
            assertEquals(resultChoices[1].getParm2(), "Param12");
            assertEquals(result.getTestParticalChoiceMaxOccurs6().getAttribute1(), "Attribute1");
            assertEquals(result.getTestParticalChoiceMaxOccurs6().getAttribute2(), "Attribute2");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    private TestCustomType getNewCustomType() {
        i++;
        TestCustomType testCustomType = new TestCustomType();
        testCustomType.setParam1("Param" + i + "2");
        testCustomType.setParam2(new String[]{"Param" + i + "21", "Param" + i + "22", "Param" + i + "23"});
        testCustomType.setParam3("Param" + i + "3");
        return testCustomType;
    }

    private boolean isEqual(TestCustomType object1, TestCustomType object2) {
        boolean isEqual = false;
        if ((object1 != null) && (object2 != null)) {
            isEqual = isEqual(object1.getParam1(), object2.getParam1()) &&
                    isEqual(object1.getParam2(), object2.getParam2()) &&
                    isEqual(object1.getParam3(), object2.getParam3());
        } else if ((object1 == null) && (object2 == null)) {
            isEqual = true;
        }
        return isEqual;
    }

    private boolean isEqual(TestCustomType[] object1, TestCustomType[] object2) {
        boolean isEqual = false;
        if ((object1 != null) && (object2 != null)) {
            if (object1.length == object2.length) {
                isEqual = true;
                for (int i = 0; i < object1.length; i++) {
                    if (!isEqual(object1[i], object2[i])) {
                        isEqual = false;
                        break;
                    }
                }
            }
        } else if ((object1 == null) && (object2 == null)) {
            isEqual = true;
        }
        return isEqual;
    }

    private boolean isEqual(String[] object1, String[] object2) {
        boolean isEqual = false;
        if ((object1 != null) && (object2 != null)) {
            if (object1.length == object2.length) {
                isEqual = true;
                for (int i = 0; i < object1.length; i++) {
                    if (!isEqual(object1[i], object2[i])) {
                        isEqual = false;
                        break;
                    }
                }
            }
        } else if ((object1 == null) && (object2 == null)) {
            isEqual = true;
        }
        return isEqual;
    }

    private boolean isEqual(String object1, String object2) {
        boolean isEqual = false;
        if ((object1 != null) && (object2 != null)) {
            isEqual = object1.equals(object2);
        } else if ((object1 == null) && (object2 == null)) {
            isEqual = true;
        }
        return isEqual;
    }

}

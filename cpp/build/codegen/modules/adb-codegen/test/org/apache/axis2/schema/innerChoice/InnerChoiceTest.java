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

package org.apache.axis2.schema.innerChoice;

import com.mynamespace.testinnerparticle.TestInnerParticle1Sequence_type0;
import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import org.apache.axis2.databinding.utils.writer.MTOMAwareXMLSerializer;
import org.apache.axis2.databinding.utils.writer.MTOMAwareXMLStreamWriter;
import test.axis2.apache.org.*;

import javax.xml.stream.XMLStreamReader;
import javax.xml.stream.XMLStreamWriter;
import java.io.ByteArrayInputStream;

public class InnerChoiceTest extends TestCase {

    public void testInnerChoice1() {
        TestInnerSequence1 testSequence = new TestInnerSequence1();
        testSequence.setSequence1("test sequence");
        testSequence.setSequence2(3);

        TestInnerSequence1Choice_type0 TestInnerSequence1Choice_type0 = new TestInnerSequence1Choice_type0();
        TestInnerSequence1Choice_type0.setChoice1("test choice");
        TestInnerSequence1Choice_type0.setChoice2(5);
        testSequence.setTestInnerSequence1Choice_type0(TestInnerSequence1Choice_type0);

        try {
            OMElement omElement = testSequence.getOMElement(TestInnerSequence1.MY_QNAME,
                     OMAbstractFactory.getSOAP12Factory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OMelement ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerSequence1 result = TestInnerSequence1.Factory.parse(xmlReader);
            assertEquals(result.getSequence1(), "test sequence");
            assertEquals(result.getSequence2(), 3);
            assertEquals(result.getTestInnerSequence1Choice_type0().getChoice2(), 5);

            // writtig result back
            XMLStreamWriter xmlStreamWriter = StAXUtils.createXMLStreamWriter(System.out);
            MTOMAwareXMLStreamWriter mtomAwareXMLStreamWriter = new MTOMAwareXMLSerializer(xmlStreamWriter);
            result.serialize(new javax.xml.namespace.QName("org.apache.axis2.test", "TestInnerSequence1", "foo")
                    , OMAbstractFactory.getSOAP11Factory(), mtomAwareXMLStreamWriter);
            xmlStreamWriter.flush();

        } catch (Exception e) {
            fail();
        }
    }

    public void testInnerChoice21() {
        TestInnerSequence2 testSequence = new TestInnerSequence2();
        testSequence.setSequence1("sequence");
        testSequence.setSequence2(3);
        TestInnerSequence2Choice_type0 testInnerSequence2Choice_type1 = new TestInnerSequence2Choice_type0();
        testInnerSequence2Choice_type1.setChoice1(new String[]{"choice1", "choice2"});
        testSequence.setTestInnerSequence2Choice_type0(testInnerSequence2Choice_type1);

        try {
            OMElement omElement = testSequence.getOMElement(TestInnerSequence2.MY_QNAME,
                    OMAbstractFactory.getSOAP12Factory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OMelement ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerSequence2 result = TestInnerSequence2.Factory.parse(xmlReader);
            assertEquals(result.getSequence1(), "sequence");
            assertEquals(result.getSequence2(), 3);
            assertTrue(isEqual(result.getTestInnerSequence2Choice_type0().getChoice1(), new String[]{"choice1", "choice2"}));
        } catch (Exception e) {
            fail();
        }
    }

    public void testInnerChoice22() {
        TestInnerSequence2 testSequence = new TestInnerSequence2();
        testSequence.setSequence1("sequence");
        testSequence.setSequence2(3);
        TestInnerSequence2Choice_type0 testInnerSequence2Choice_type1 = new TestInnerSequence2Choice_type0();
        testInnerSequence2Choice_type1.setChoice2(new int[]{2, 4});
        testSequence.setTestInnerSequence2Choice_type0(testInnerSequence2Choice_type1);

         try {
             OMElement omElement = testSequence.getOMElement(TestInnerSequence2.MY_QNAME,
                      OMAbstractFactory.getSOAP12Factory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OMelement ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerSequence2 result = TestInnerSequence2.Factory.parse(xmlReader);
            assertEquals(result.getSequence1(), "sequence");
            assertEquals(result.getSequence2(), 3);
            assertTrue(isEqual(result.getTestInnerSequence2Choice_type0().getChoice2(), new int[]{2, 4}));
        } catch (Exception e) {
            fail();
        }
    }

    public void testInnerChoice31() {
        TestInnerSequence3 testSequence = new TestInnerSequence3();
        testSequence.setSequence1("sequence");
        testSequence.setSequence2(3);
        TestInnerSequence3Choice_type0 testInnerSequence3Choice_type0 = new TestInnerSequence3Choice_type0();
        testInnerSequence3Choice_type0.setChoice1(new String[]{"choice1", null, "choice2"});
        testSequence.setTestInnerSequence3Choice_type0(testInnerSequence3Choice_type0);

       try {
           OMElement omElement = testSequence.getOMElement(TestInnerSequence3.MY_QNAME,
                   OMAbstractFactory.getSOAP12Factory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OMelement ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerSequence3 result = TestInnerSequence3.Factory.parse(xmlReader);
            assertEquals(result.getSequence1(), "sequence");
            assertEquals(result.getSequence2(), 3);
            assertTrue(isEqual(result.getTestInnerSequence3Choice_type0().getChoice1(), new String[]{"choice1", null, "choice2"}));
        } catch (Exception e) {
            fail();
        }
    }

    public void testInnerChoice32() {
        TestInnerSequence3 testSequence = new TestInnerSequence3();
        testSequence.setSequence1("sequence");
        testSequence.setSequence2(3);
        TestInnerSequence3Choice_type0 testInnerSequence3Choice_type0 = new TestInnerSequence3Choice_type0();
        testInnerSequence3Choice_type0.setChoice2(new int[]{2, Integer.MIN_VALUE, 6});
        testSequence.setTestInnerSequence3Choice_type0(testInnerSequence3Choice_type0);


         try {
             OMElement omElement = testSequence.getOMElement(TestInnerSequence3.MY_QNAME,
                      OMAbstractFactory.getSOAP12Factory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OMelement ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestInnerSequence3 result = TestInnerSequence3.Factory.parse(xmlReader);
            assertEquals(result.getSequence1(), "sequence");
            assertEquals(result.getSequence2(), 3);
            assertTrue(isEqual(result.getTestInnerSequence3Choice_type0().getChoice2(), new int[]{2, Integer.MIN_VALUE, 6}));
        } catch (Exception e) {
            fail();
        }
    }


    private boolean isEqual(String[] test1, String[] test2) {
        boolean isEqual = true;
        if (test1.length != test2.length) {
            isEqual = false;
        } else {
            for (int i = 0; i < test1.length; i++) {
                if (test1[i] != null) {
                    if (!test1[i].equals(test2[i])) {
                        isEqual = false;
                        break;
                    }
                } else {
                    if (test2[i] != null) {
                        isEqual = false;
                        break;
                    }
                }

            }
        }

        return isEqual;
    }

    private boolean isEqual(int[] test1, int[] test2) {
        boolean isEqual = true;
        if (test1.length != test2.length) {
            isEqual = false;
        } else {
            for (int i = 0; i < test1.length; i++) {
                if (test1[i] != test2[i]) {
                    isEqual = false;
                    break;
                }
            }
        }

        return isEqual;
    }


}

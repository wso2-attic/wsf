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

package org.apache.axis2.schema.group;

import group.test.axis2.apache.org.*;
import group.test.axis2.apache.org.TestAttributeGroupElement;
import group.test.axis2.apache.org.TestNestedAttributeGroupElement;
import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;

import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;


public class GroupTest extends TestCase {

    public void testSequenceGroupElement(){

        TestSequenceGroupElement testGroupSequenceElement = new TestSequenceGroupElement();
        testGroupSequenceElement.setParam1("param1");
        TestSequenceGroup testSequenceGroup = new TestSequenceGroup();
        testSequenceGroup.setSequenceParam1("sequenceParam1");
        testSequenceGroup.setSequenceParam2("sequenceParam2");
        testGroupSequenceElement.setTestSequenceGroup(testSequenceGroup);

        try {
            OMElement omElement =
                    testGroupSequenceElement.getOMElement(TestSequenceGroupElement.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader =
                    StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestSequenceGroupElement result = TestSequenceGroupElement.Factory.parse(xmlReader);
            assertEquals(result.getParam1(),"param1");
            assertEquals(result.getTestSequenceGroup().getSequenceParam1(),"sequenceParam1");
            assertEquals(result.getTestSequenceGroup().getSequenceParam2(),"sequenceParam2");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testNestedSequenceGroupElement(){

        TestSequenceNestedGroupElement testSequenceNestedGroupElement = new TestSequenceNestedGroupElement();
        testSequenceNestedGroupElement.setParam1("param1");

        TestSequenceNestedGroup testSequenceNestedGroup = new TestSequenceNestedGroup();
        testSequenceNestedGroup.setNestedSequenceParam1("nestedSequenceParam1");

        TestSequenceGroup testSequenceGroup = new TestSequenceGroup();
        testSequenceGroup.setSequenceParam1("sequenceParam1");
        testSequenceGroup.setSequenceParam2("sequenceParam2");

        testSequenceNestedGroup.setTestSequenceGroup(testSequenceGroup);

        testSequenceNestedGroupElement.setTestSequenceNestedGroup(testSequenceNestedGroup);

       try {
           OMElement omElement =
                    testSequenceNestedGroupElement.getOMElement(TestSequenceNestedGroupElement.MY_QNAME, OMAbstractFactory.getOMFactory());

            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader =
                    StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestSequenceNestedGroupElement result = TestSequenceNestedGroupElement.Factory.parse(xmlReader);
            assertEquals(result.getParam1(),"param1");
            assertEquals(result.getTestSequenceNestedGroup().getNestedSequenceParam1(),"nestedSequenceParam1");
            assertEquals(result.getTestSequenceNestedGroup().getTestSequenceGroup().getSequenceParam1(),"sequenceParam1");
            assertEquals(result.getTestSequenceNestedGroup().getTestSequenceGroup().getSequenceParam2(),"sequenceParam2");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testChoiceGroupElement(){

        TestChoiceGroupElement testGroupChoiceElement = new TestChoiceGroupElement();
        testGroupChoiceElement.setParam1("param1");
        TestChoiceGroup testChoiceGroup = new TestChoiceGroup();
        testChoiceGroup.setChoiceParam1("choiceParam1");
        testGroupChoiceElement.setTestChoiceGroup(testChoiceGroup);

       try {
           OMElement omElement =
                   testGroupChoiceElement.getOMElement(TestChoiceGroupElement.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader =
                    StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestChoiceGroupElement result = TestChoiceGroupElement.Factory.parse(xmlReader);
            assertEquals(result.getTestChoiceGroup().getChoiceParam1(),"choiceParam1");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testNestedChoiceGroupElement(){

        TestChoiceNestedGroupElement testChoiceNestedGroupElement = new TestChoiceNestedGroupElement();
        testChoiceNestedGroupElement.setParam1("param1");

        TestChoiceNestedGroup testChoiceNestedGroup = new TestChoiceNestedGroup();
        testChoiceNestedGroup.setNestedChoiceParam1("nestedChoiceParam1");

        TestChoiceGroup testChoiceGroup = new TestChoiceGroup();
        testChoiceGroup.setChoiceParam1("choiceParam1");

        testChoiceNestedGroup.setTestChoiceGroup(testChoiceGroup);

        testChoiceNestedGroupElement.setTestChoiceNestedGroup(testChoiceNestedGroup);

       try {
           OMElement omElement =
                   testChoiceNestedGroupElement.getOMElement(testChoiceNestedGroupElement.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader =
                    StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestChoiceNestedGroupElement result = TestChoiceNestedGroupElement.Factory.parse(xmlReader);
            assertEquals(result.getTestChoiceNestedGroup().getTestChoiceGroup().getChoiceParam1(),"choiceParam1");
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

     public void testAttributeGroup(){
         TestAttributeGroupElement testAttributeGroup = new TestAttributeGroupElement();
         testAttributeGroup.setAttribute1("Attribute1");
         testAttributeGroup.setParam1("Param1");

         try {
             OMElement omElement =
                       testAttributeGroup.getOMElement(TestAttributeGroupElement.MY_QNAME,OMAbstractFactory.getOMFactory());
             String omElementString = omElement.toStringWithConsume();
             System.out.println("OM Element ==> " + omElementString);
             XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
             TestAttributeGroupElement result = TestAttributeGroupElement.Factory.parse(xmlReader);
             assertEquals(result.getParam1(),"Param1");
             assertEquals(result.getAttribute1(),"Attribute1");
         } catch (XMLStreamException e) {
             fail();
         } catch (Exception e) {
             fail();
         }

     }

    public void testNestedAttributeGroup(){
         TestNestedAttributeGroupElement testNestedAttributeGroupElement = new TestNestedAttributeGroupElement();
         testNestedAttributeGroupElement.setAttribute1("Attribute1");
         testNestedAttributeGroupElement.setAttribute2("Attribute2");
         testNestedAttributeGroupElement.setParam1("Param1");

        try {
            OMElement omElement =
                    testNestedAttributeGroupElement.getOMElement(TestNestedAttributeGroupElement.MY_QNAME,OMAbstractFactory.getOMFactory());
             String omElementString = omElement.toStringWithConsume();
             System.out.println("OM Element ==> " + omElementString);
             XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
             TestNestedAttributeGroupElement result = TestNestedAttributeGroupElement.Factory.parse(xmlReader);
             assertEquals(result.getParam1(),"Param1");
             assertEquals(result.getAttribute1(),"Attribute1");
             assertEquals(result.getAttribute2(),"Attribute2");
         } catch (XMLStreamException e) {
             fail();
         } catch (Exception e) {
             fail();
         }

     }



}

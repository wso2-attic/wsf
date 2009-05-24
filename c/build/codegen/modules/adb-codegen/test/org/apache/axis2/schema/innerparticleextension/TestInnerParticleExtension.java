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

package org.apache.axis2.schema.innerparticleextension;

import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import org.apache.axis2.databinding.ADBException;
import org.tempuri.innerparticalextension.ChildElement_type0;
import org.tempuri.innerparticalextension.ParentTypeChoice;
import org.tempuri.innerparticalextension.TestElement;

import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;

public class TestInnerParticleExtension extends TestCase {

    public void testTestElement(){
        TestElement testElement = new TestElement();

        ChildElement_type0 childElement_type0[] = new ChildElement_type0[2];
        childElement_type0[0] = new ChildElement_type0();
        childElement_type0[0].setTestAttribute("Test Attribute");

        ParentTypeChoice[] parentTypeChoices = new ParentTypeChoice[2];
        parentTypeChoices[0] = new ParentTypeChoice();
        parentTypeChoices[0].setParam1("param1");
        parentTypeChoices[1] = new ParentTypeChoice();
        parentTypeChoices[1].setParam2("param2");

        childElement_type0[0].setParentTypeChoice(parentTypeChoices);

        childElement_type0[1] = new ChildElement_type0();
        childElement_type0[1].setTestAttribute("Test Attribute");

        parentTypeChoices = new ParentTypeChoice[2];
        parentTypeChoices[0] = new ParentTypeChoice();
        parentTypeChoices[0].setParam1("param1");
        parentTypeChoices[1] = new ParentTypeChoice();
        parentTypeChoices[1].setParam2("param2");

        childElement_type0[1].setParentTypeChoice(parentTypeChoices);

        testElement.setChildElement(childElement_type0);

        try {
            OMElement omElement = testElement.getOMElement(TestElement.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM Element string ==> " + omElementString);
            XMLStreamReader xmlReader =
                    StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestElement result = TestElement.Factory.parse(xmlReader);
            assertEquals(result.getChildElement()[0].getTestAttribute(),"Test Attribute");
            assertEquals(result.getChildElement()[1].getTestAttribute(),"Test Attribute");

            assertEquals(result.getChildElement()[0].getParentTypeChoice()[0].getParam1(),"param1");
            assertEquals(result.getChildElement()[0].getParentTypeChoice()[1].getParam2(),"param2");
            assertEquals(result.getChildElement()[1].getParentTypeChoice()[0].getParam1(),"param1");
            assertEquals(result.getChildElement()[1].getParentTypeChoice()[1].getParam2(),"param2");

        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }


    }
}

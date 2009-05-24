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

package org.apache.axis2.schema.booleantest;

import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import org.tempuri.boolean1.TestBoolean1;
import org.tempuri.boolean1.TestBoolean2;

import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;


public class BooleanTest extends TestCase {

    public void testBooleanTest1(){
        TestBoolean1 testBoolean = new TestBoolean1();
        testBoolean.setTestBoolean1(true);

        try {
            OMElement omElement = testBoolean.getOMElement(TestBoolean1.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestBoolean1 result = TestBoolean1.Factory.parse(xmlReader);
            assertEquals(result.getTestBoolean1(),true);
        } catch (Exception e) {
            fail();
        }
    }

    public void testBooleanTest2(){
        TestBoolean2 testBoolean = new TestBoolean2();
        testBoolean.setParam1(false);
        testBoolean.setAttribute1(true);

         try {
            OMElement omElement = testBoolean.getOMElement(TestBoolean2.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("String ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            TestBoolean2 result = TestBoolean2.Factory.parse(xmlReader);
            assertEquals(result.getParam1(),false);
            assertEquals(result.getAttribute1(),true);
        } catch (Exception e) {
            fail();
        }
    }

}

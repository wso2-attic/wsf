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

package org.apache.axis2.schema.testsuite;

import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import services.echo.types.TestAny1;
import services.echo.types.TestAny2;
import services.echo.types.TestAny3;
import services.echo.types.TestAny4;

import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;


public class AnyElementsTest extends AbstractTest {

    public static final int MIN_EQUALS_ZERO = 0;
    public static final int MIN_EQUALS_ONE = 1;

    public void testAnyArray() {
        OMElement[] returnObject;
        try {
            returnObject = testAnyArray(null, MIN_EQUALS_ZERO);
            assertTrue(assertArrayEqual(returnObject, null));
            returnObject = testAnyArray(new OMElement[]{null}, MIN_EQUALS_ZERO);
            assertTrue(assertArrayEqual(returnObject, null));
            returnObject = testAnyArray(new OMElement[]{getOMElement()}, MIN_EQUALS_ZERO);
            assertTrue(assertArrayEqual(returnObject, new OMElement[]{getOMElement()}));
            returnObject = testAnyArray(new OMElement[]{getOMElement(), getOMElement()}, MIN_EQUALS_ZERO);
            assertTrue(assertArrayEqual(returnObject, new OMElement[]{getOMElement(), getOMElement()}));
        } catch (Exception e) {
            e.printStackTrace();
            fail();
        }

        try {
            returnObject = testAnyArray(null, MIN_EQUALS_ONE);
            fail();
        } catch (Exception e) {
            assertTrue(true);
        }

        try {
            returnObject = testAnyArray(new OMElement[]{null}, MIN_EQUALS_ONE);
            fail();
        } catch (Exception e) {
            assertTrue(true);
        }

        try {
            returnObject = testAnyArray(new OMElement[]{getOMElement(), getOMElement()}, MIN_EQUALS_ONE);
            assertTrue(assertArrayEqual(returnObject, new OMElement[]{getOMElement(), getOMElement()}));
        } catch (Exception e) {
            fail();
        }


    }

    private OMElement[] testAnyArray(OMElement[] innerObject, int type) throws Exception {
        OMElement omElement;
        String omElementString;
        OMElement[] returnObject = null;

        switch (type) {
            case MIN_EQUALS_ZERO : {
                TestAny1 testAny = new TestAny1();
                testAny.setExtraElement(innerObject);
                omElement = testAny.getOMElement(TestAny1.MY_QNAME, OMAbstractFactory.getSOAP12Factory());
                omElementString = omElement.toStringWithConsume();
                System.out.println("OMElement ==> " + omElementString);
                XMLStreamReader xmlReader =
                        StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
                returnObject = TestAny1.Factory.parse(xmlReader).getExtraElement();
                break;
            }
            case MIN_EQUALS_ONE : {
                TestAny3 testAny = new TestAny3();
                testAny.setExtraElement(innerObject);
                omElement = testAny.getOMElement(TestAny3.MY_QNAME, OMAbstractFactory.getSOAP12Factory());
                omElementString = omElement.toStringWithConsume();
                System.out.println("OMElement ==> " + omElementString);
                XMLStreamReader xmlReader =
                        StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
                returnObject = TestAny3.Factory.parse(xmlReader).getExtraElement();
                break;
            }
        }
        return returnObject;
    }

    public void testAny() {
        OMElement returnObject;
        try {
            returnObject = testAny(null, MIN_EQUALS_ZERO);
            assertTrue(isOMElementsEqual(returnObject, null));
            returnObject = testAny(getOMElement(), MIN_EQUALS_ZERO);
            assertTrue(isOMElementsEqual(returnObject, getOMElement()));

        } catch (Exception e) {
            fail();
        }

        try {
            returnObject = testAny(null, MIN_EQUALS_ONE);
            fail();
        } catch (Exception e) {
            assertTrue(true);
        }

        try {
            returnObject = testAny(getOMElement(), MIN_EQUALS_ONE);
            assertTrue(isOMElementsEqual(returnObject, getOMElement()));
        } catch (Exception e) {
            fail();
        }
    }

    private OMElement testAny(OMElement innerObject, int type) throws Exception {
        OMElement omElement;
        OMElement returnObject = null;
        String omElementString;

        switch (type) {
            case MIN_EQUALS_ZERO : {
                TestAny2 testAny = new TestAny2();
                testAny.setExtraElement(innerObject);
                omElement = testAny.getOMElement(TestAny2.MY_QNAME, OMAbstractFactory.getSOAP12Factory());
                omElementString = omElement.toStringWithConsume();
                System.out.println("OMElement ==> " + omElementString);
                XMLStreamReader xmlReader =
                        StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
                returnObject = TestAny2.Factory.parse(xmlReader).getExtraElement();
                break;
            }
            case MIN_EQUALS_ONE : {
                TestAny4 testAny = new TestAny4();
                testAny.setExtraElement(innerObject);
                omElement = testAny.getOMElement(TestAny4.MY_QNAME, OMAbstractFactory.getSOAP12Factory());
                omElementString = omElement.toStringWithConsume();
                System.out.println("OMElement ==> " + omElementString);
                XMLStreamReader xmlReader =
                        StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
                returnObject = TestAny4.Factory.parse(xmlReader).getExtraElement();
                break;
            }
        }
        return returnObject;
    }


}

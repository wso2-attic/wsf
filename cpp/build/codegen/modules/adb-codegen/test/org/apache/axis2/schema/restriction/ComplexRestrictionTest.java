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
import org.apache.axis2.databinding.ADBException;
import org.tempuri.GetExemplarResponseType;
import org.tempuri.GetExemplarResponseTypeElement;

import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;
import java.math.BigInteger;

public class ComplexRestrictionTest extends TestCase {

    public void testGetExemplarResponseTypeElement(){
        GetExemplarResponseTypeElement getExemplarResponseTypeElement = new GetExemplarResponseTypeElement();
        GetExemplarResponseType getExemplarResponseType = new GetExemplarResponseType();
        getExemplarResponseType.setExemplar("test string1");
        getExemplarResponseType.setResponseCode(new BigInteger("23"));
        getExemplarResponseType.setResponseMessage("test string2");
        getExemplarResponseType.setSupportedMethods("test string3");

        getExemplarResponseTypeElement.setGetExemplarResponseTypeElement(getExemplarResponseType);

        try {
            OMElement omElement =
                    getExemplarResponseTypeElement.getOMElement(GetExemplarResponseTypeElement.MY_QNAME,
                            OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OMElement string ==> " + omElementString);
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            GetExemplarResponseTypeElement result = GetExemplarResponseTypeElement.Factory.parse(xmlReader);
            GetExemplarResponseType resultType = result.getGetExemplarResponseTypeElement();
            assertEquals(resultType.getExemplar(),"test string1");
            assertEquals(resultType.getResponseMessage(),"test string2");
            assertEquals(resultType.getSupportedMethods(),"test string3");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

}

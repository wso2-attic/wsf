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

package org.apache.axis2.schema.all;

import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import org.tempuri.Update;

import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;


public class AllTest extends TestCase {

    public void testAll(){
        Update update = new Update();
        update.setArg0("test");
        update.setArg1(true);
        update.setId(2);


        try {
            OMElement omElement = update.getOMElement(Update.MY_QNAME, OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("om string ==> " + omElementString);
            omElementString = "<ns1:Update xmlns:ns1=\"http://tempuri.org/\"><ns1:arg1>true</ns1:arg1><ns1:id>2</ns1:id><ns1:arg0>test</ns1:arg0></ns1:Update>";
            XMLStreamReader xmlReader = StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            Update newUpdate = Update.Factory.parse(xmlReader);
            assertEquals(update.getArg0(),newUpdate.getArg0());
            assertEquals(update.getArg1(),newUpdate.getArg1());
            assertEquals(update.getId(),newUpdate.getId());
        } catch (Exception e) {
            assertFalse(true);
        }
    }
}

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

package org.apache.axis2.schema.decimal;

import junit.framework.TestCase;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.util.StAXUtils;
import org.apache.axis2.databinding.ADBException;
import org.apache.axis2.databinding.types.Duration;
import org.tempuri.boolean1.ArrayOfDecimal;
import org.tempuri.boolean1.GetHistoricNavResponse;

import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import java.io.ByteArrayInputStream;
import java.math.BigDecimal;
import java.util.Calendar;


public class DecimalTest  extends TestCase {

    public void testDecimal(){
        GetHistoricNavResponse getHistoricNavResponse = new GetHistoricNavResponse();
        ArrayOfDecimal arrayOfDecimal = new ArrayOfDecimal();
        getHistoricNavResponse.setOut(arrayOfDecimal);
        arrayOfDecimal.addDecimal(null);
        arrayOfDecimal.addDecimal(null);
        arrayOfDecimal.addDecimal(new BigDecimal("111.38"));
        arrayOfDecimal.addDecimal(new BigDecimal("111.38"));
        arrayOfDecimal.addDecimal(new BigDecimal("111.38"));
        arrayOfDecimal.addDecimal(new BigDecimal("111.54"));

        try {
            OMElement omElement = getHistoricNavResponse.getOMElement(GetHistoricNavResponse.MY_QNAME,
                    OMAbstractFactory.getOMFactory());
            String omElementString = omElement.toStringWithConsume();
            System.out.println("OM String ==> " + omElementString);
            XMLStreamReader xmlReader =
                    StAXUtils.createXMLStreamReader(new ByteArrayInputStream(omElementString.getBytes()));
            GetHistoricNavResponse result = GetHistoricNavResponse.Factory.parse(xmlReader);
            assertEquals(result.getOut().getDecimal()[0], null);
            assertEquals(result.getOut().getDecimal()[1], null);
            assertEquals(result.getOut().getDecimal()[2].toString(), "111.38");
            assertEquals(result.getOut().getDecimal()[3].toString(), "111.38");
            assertEquals(result.getOut().getDecimal()[4].toString(), "111.38");
            assertEquals(result.getOut().getDecimal()[5].toString(), "111.54");
        } catch (ADBException e) {
            fail();
        } catch (XMLStreamException e) {
            fail();
        } catch (Exception e) {
            fail();
        }
    }

    public void testDuration(){
        Calendar calendar = Calendar.getInstance();
        Duration duration = new Duration(false,0,0,23,12,24,23.45);
        System.out.println("Duration ==> " + duration.toString());
        // P2007Y5M30DT8H40M55.87S
        // "\\-?P(\\d*D)?(T(\\d*H)?(\\d*M)?(\\d*(\\.\\d*)?S)?)?"
        if (duration.toString().matches("\\-?P(\\d*D)?(T(\\d*H)?(\\d*M)?(\\d*(\\.\\d*)?S)?)?")){
            System.out.println("Matches");
        }
    }
}

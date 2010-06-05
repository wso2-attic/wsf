/*
 * Copyright 2008 WSO2, Inc. http://www.wso2.org
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.wso2.wsf.jython.client;

import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMFactory;
import org.apache.axiom.om.impl.builder.StAXOMBuilder;
import org.apache.axiom.om.impl.llom.OMTextImpl;
import org.apache.axis2.client.ServiceClient;
import org.apache.axis2.client.Options;
import org.apache.axis2.addressing.EndpointReference;
import org.apache.axis2.Constants;
import org.apache.axis2.AxisFault;
import org.apache.axis2.transport.http.HttpTransportProperties;
import org.python.core.PyDictionary;
import org.python.core.*;
import org.python.util.PythonInterpreter;
import org.apache.neethi.Policy;
import org.apache.neethi.PolicyEngine;
import org.apache.rampart.RampartMessageData;

import javax.xml.stream.XMLStreamException;
import javax.xml.namespace.QName;
import javax.activation.FileDataSource;
import javax.activation.DataHandler;
import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.util.HashMap;

/**
 * Web service client.
 */
public class WSClient {
    private ServiceClient client = null;

    private Options options = null;

    private boolean engageAddressing = false;

    private boolean hasAttachments = false;

    private HashMap<String, String> map;

    static PythonInterpreter interp;

    /**
     * Converts a python Dictionary to a java HashMap
     *
     * @param pyDict - Dictionary of configuration values
     * @return HashMap hashmap containing the parameters and values
     */
    public static HashMap dictToHashMap(PyDictionary pyDict) {
        interp = new PythonInterpreter();
        InputStream inpStream = Thread.currentThread().getContextClassLoader().getResourceAsStream("UtilityMethods.py");
        interp.execfile(inpStream);

        String st2 = "dictToJavaMap(" + pyDict + ")";
        PyObject ob2 = interp.eval(st2);
        return (HashMap) ob2.__tojava__(HashMap.class);
    }

    /**
     * Creates a WSClient out of the parameters specified in the python dictionary
     *
     * @param pyDict contains the values of the configurations
     * @param pyFile logs the details in to this file
     * @throws WSFault throws a WSFault
     */
    public WSClient(PyDictionary pyDict, String pyFile) throws WSFault {
        HashMap map = dictToHashMap(pyDict);

        HttpTransportProperties.ProxyProperties proxy = new HttpTransportProperties.ProxyProperties();

        try {
            client = new ServiceClient();
        } catch (AxisFault axisFault) {
            //axisFault.printStackTrace();
            throw new WSFault(axisFault.getMessage());
        }

        options = new Options();

        for (Object o : map.keySet()) {
            String key = (String) o;
            //System.out.println("\nKey2 " + key + " === Value " +/*(String)*/ map.get(key));            
            if ("to".equalsIgnoreCase(key)) {   // Setting End Point Reference
                options.setTo(new EndpointReference((String) map.get(key)));
            } else if ("action".equalsIgnoreCase(key)) {       // Setting SOAP action
                options.setAction(map.get(key).toString());
            } else if ("policy".equalsIgnoreCase(key)) {
                setPolicy(map.get(key).toString());
            } else if ("use_soap".equalsIgnoreCase(key)) {     // Checkig whether to use SOAP or REST
                if (map.get(key).toString().equalsIgnoreCase("FALSE")) {
                    options.setProperty(Constants.Configuration.ENABLE_REST, Boolean.TRUE);
                }
            } else if ("http_method".equalsIgnoreCase(key)) {      // Decides whether to use 'Get' or 'Post'
                String httpMethod = map.get(key).toString();
                if ("GET".equalsIgnoreCase(httpMethod)) {
                    options.setProperty(Constants.Configuration.HTTP_METHOD, Constants.Configuration.HTTP_METHOD_GET);
                } else if ("POST".equalsIgnoreCase(httpMethod)) {
                    options.setProperty(Constants.Configuration.HTTP_METHOD, Constants.Configuration.HTTP_METHOD_POST);
                }
            } else if ("use_mtom".equalsIgnoreCase(key)) {     // Setting up mtom or not
                String useMtom = map.get(key).toString();
                if ("TRUE".equalsIgnoreCase(useMtom)) {
                    options.setProperty(Constants.Configuration.ENABLE_MTOM, Constants.VALUE_TRUE);
                } else if ("FALSE".equalsIgnoreCase(useMtom)) {
                    // There is no option equal to the option specified in the jruby client
                    /*if use_mtom.eql?('FALSE')
                   @options.setProperty(Constants::Configuration::FORCE_MIME, Constants::VALUE_TRUE)*/
                }
            } else if ("proxy_host".equalsIgnoreCase(key)) {       // Setting up the proxy properties, if provided
                proxy.setProxyName(map.get(key).toString());
            } else if ("proxy_port".equalsIgnoreCase(key)) {
                proxy.setProxyPort(Integer.parseInt(map.get(key).toString()));
            } else if ("use_wsa".equalsIgnoreCase(key)) {      // Engage addressing module
                if ("TRUE".equalsIgnoreCase(map.get(key).toString())) {
                    try {
                        client.engageModule("addressing");
                        engageAddressing = true;
                    } catch (AxisFault axisFault) {
                        throw new WSFault(axisFault.getMessage());
                    }
                }
            }

        }

    }

    /**
     * Creates a request out of the object opt
     *
     * @param opt contains a String payload or a WSMessage
     * @return OMElement
     * @throws WSFault throws a WSFault
     */
    public OMElement request(Object opt) throws WSFault {
        String requesPayload = "";
        HashMap hashMap;

        if (opt instanceof String) {
            requesPayload = opt.toString();
        }

        if (opt instanceof WSMessage) {
            WSMessage wsMsg;
            wsMsg = (WSMessage) opt;
            requesPayload = wsMsg.getPayload();
            hashMap = wsMsg.getMap();

            for (Object o : hashMap.keySet()) {
                String key = (String) o;
                //System.out.println("\nKey2 " + key + " === Value " +/*(String)*/ map.get(key));
                if ("to".equals(key)) {
                    options.setTo(new EndpointReference((String) hashMap.get(key)));
                } else if ("action".equalsIgnoreCase(key)) {       // Setting SOAP action
                    options.setAction(hashMap.get(key).toString());
                } else if ("policy".equalsIgnoreCase(key)) {
                    setPolicy(hashMap.get(key).toString());
                } else if ("attachments".equalsIgnoreCase(key)) {
                    //saves the attachments in a hashmap
                    hasAttachments = true;
                    String attValues = hashMap.get(key).toString();
                    //System.out.println(attValues);  //{'myid2': 'second attachment', 'myid1': 'first attachment'}
                    attValues = attValues.replace("'", "");
                    attValues = attValues.replace("{", "");
                    attValues = attValues.replace("}", "");
                    String str[] = attValues.split(",");
                    String strTemp[];
                    map = new HashMap<String, String>();

                    for (String aStr : str) {
                        strTemp = aStr.split(":");
                        map.put(strTemp[0].trim(), strTemp[1].trim());
                    }

                    //testing : printing the stored aattachment array
                    /*Iterator k3 = map.keySet().iterator();
                    while (k3.hasNext()) {
                        String key2 = (String) k3.next();
                        System.out.println("key" + key2 + "||" + map.get(key2));
                    }*/

                } else if ("from".equalsIgnoreCase(key)) {
                    options.setFrom(new EndpointReference((String) hashMap.get(key)));
                } else if ("reply_to".equalsIgnoreCase(key)) {
                    options.setReplyTo(new EndpointReference((String) hashMap.get(key)));
                } else if ("fault_to".equalsIgnoreCase(key)) {
                    options.setFaultTo(new EndpointReference((String) hashMap.get(key)));
                }

            }
        }
        //setting options to the ServiceClient
        client.setOptions(options);
        StAXOMBuilder builder;
        try {
            builder = new StAXOMBuilder(new ByteArrayInputStream(requesPayload.getBytes()));
        } catch (XMLStreamException e) {
            throw new WSFault(e.getMessage());
        }
        OMElement omElement = builder.getDocumentElement();
        OMElement response;

        // if attachments are available , add them to the OMElement
        if (hasAttachments) {
            for (String key : map.keySet()) {
                //System.out.println("key" + key2 + "||" + map.get(key2));
                FileDataSource fileDataSource = new FileDataSource(map.get(key));
                DataHandler expectedDataHandler = new DataHandler(fileDataSource);
                OMFactory factory = OMAbstractFactory.getOMFactory();
                OMTextImpl expectedTextData = new OMTextImpl(expectedDataHandler, true, factory);
                OMElement tempElement = factory.createOMElement(new QName("wrapperElement"));
                omElement.addChild(tempElement);
                tempElement.addChild(expectedTextData);
            }
        }

        try {
            response = client.sendReceive(omElement);
        } catch (AxisFault axisFault) {
            throw new WSFault(axisFault.getMessage());
        }
        return response;
    }

    private static Policy loadPolicy(String xmlPath) throws Exception {
        StAXOMBuilder builder = new StAXOMBuilder(xmlPath);
        return PolicyEngine.getPolicy(builder.getDocumentElement());
    }

    /**
     * Sets a security policy to the client request
     *
     * @param policyPath path of the xml policy file
     */
    public void setPolicy(String policyPath) {
        // testing : How to set securtiy
        try {
            // If the user forgets to engage addressing before security, it is done here.
            if (!engageAddressing) {
                client.engageModule("addressing");
            }
            options.setProperty(RampartMessageData.KEY_RAMPART_POLICY, loadPolicy(policyPath));
            client.engageModule("rampart");
        } catch (Exception e) {
            //throw new AxisFault(e.getMessage());
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }

    }

    /**
     * Sets the reliable messaging support. passed in parameter should be specified in milliseconds
     *
     * @param milliSeconds time in milliseconds
     */
    public void setReliableMessaging(int milliSeconds) {
        try {
            client.engageModule("sandesha2");
            options.setUseSeparateListener(true);
            options.setTimeOutInMilliSeconds(milliSeconds);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}

/*
 * Copyright 2007 WSO2, Inc. http://www.wso2.org
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

package org.wso2.javascript.rhino;

import org.apache.axiom.om.OMElement;
import org.apache.axis2.AxisFault;
import org.apache.axis2.addressing.EndpointReference;
import org.apache.axis2.transport.http.server.HttpUtils;
import org.apache.axis2.context.ConfigurationContext;
import org.apache.axis2.description.Parameter;
import org.apache.axis2.description.TransportInDescription;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.util.Loader;
import org.apache.axis2.util.Utils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.mozilla.javascript.Scriptable;
import org.mozilla.javascript.ScriptableObject;
import org.mozilla.javascript.Context;

import javax.xml.namespace.QName;
import java.lang.reflect.InvocationTargetException;
import java.security.PrivilegedActionException;
import java.security.PrivilegedExceptionAction;
import java.util.Iterator;
import java.net.SocketException;

public class JavaScriptEngineUtils {

    /*
    * setup for logging
    */
    private static final Log log = LogFactory.getLog(JavaScriptEngineUtils.class);

    public static void loadHostObjects(JavaScriptEngine engine,
                                       AxisConfiguration axisConfig) throws AxisFault {

        Parameter hostObjectParameter = axisConfig.getParameter("javascript.hostobjects");
        if ((hostObjectParameter != null) && (hostObjectParameter.getParameterType() == 2)) {
            OMElement paraElement = hostObjectParameter.getParameterElement();
            JavaScriptEngineUtils.getHostObjectsList(paraElement, engine);
        }
    }

    private static void getHostObjectsList(OMElement hostObjectElement, JavaScriptEngine cx)
            throws AxisFault {
        Iterator iterator = hostObjectElement.getChildrenWithName(new QName("class"));
        while (iterator.hasNext()) {
            OMElement element = (OMElement) iterator.next();
            final String className = element.getText();
            if ((className != null) & (!"".equals(className))) {
                try {
                    ScriptableObject.defineClass(cx, loadClass(className));
                } catch (PrivilegedActionException e) {
                    log.fatal(e);
                    throw new AxisFault("Error occured while loading the host object :" + className,
                                        e);
                } catch (IllegalAccessException e) {
                    log.fatal(e);
                    throw new AxisFault("Error occured while loading the host object :" + className,
                                        e);
                } catch (InstantiationException e) {
                    log.fatal(e);
                    throw new AxisFault("Error occured while loading the host object :" + className,
                                        e);
                } catch (InvocationTargetException e) {
                    log.fatal(e);
                    throw new AxisFault("Error occured while loading the host object :" + className,
                                        e);
                }
            }
        }
    }

    private static Class loadClass(final String className) throws PrivilegedActionException {
        return (Class) org.apache.axis2.java.security.AccessController
                .doPrivileged(new PrivilegedExceptionAction() {
                    public Object run() throws AxisFault {
                        Class selectorClass;
                        try {
                            if ((className != null) && !"".equals(className)) {
                                selectorClass = Loader.loadClass(Thread.currentThread()
                                        .getContextClassLoader(), className);
                            } else {
                                log.fatal("Invalid Class Name for the HostObject");
                                throw new AxisFault("Invalid Class Name");
                            }
                        } catch (ClassNotFoundException e) {
                            log.fatal(e);
                            throw new AxisFault("Error occured while loading the host object :"
                                    + className, e);
                        }
                        return selectorClass;
                    }
                });
    }

    public static void loadGlobalPropertyObjects(JavaScriptEngine engine,
                                                 AxisConfiguration axisConfig, String serviceName) {
        Parameter propertyObjectParameter = axisConfig
                .getParameter("javascript.global.propertyobjects");
        if ((propertyObjectParameter != null) &&
                (propertyObjectParameter.getParameterType() == 2)) {
            OMElement paraElement = propertyObjectParameter.getParameterElement();
            loadGlobalProperties(paraElement, engine, serviceName);
        }
    }

    private static void loadGlobalProperties(OMElement hostObjectElement, JavaScriptEngine engine,
                                             String serviceName) {
        Iterator iterator = hostObjectElement.getChildrenWithName(new QName("global.property"));
        while (iterator.hasNext()) {
            OMElement element = (OMElement) iterator.next();
            String objectName = element.getText();
            String hostObject = element.getAttributeValue(new QName("hostObject"));
            if ((objectName != null) & (!"".equals(objectName)) & (hostObject != null)
                    & (!"".equals(hostObject))) {
                Scriptable entryHostObject = engine.getCx().newObject(engine, hostObject,
                                                                      new Object[0]);
                engine.defineProperty(objectName, entryHostObject, ScriptableObject.READONLY);

                // If this is the system host object we need to inject a property called wwwURL
                // which would return the http url to a certain service. As the system object is a
                // global object and does not have a pointer to the service calling it there is no
                // other way to do it
                if ("system".equals(objectName) && !"".equals(serviceName)) {
                    Object object = Context.getCurrentContext()
                            .getThreadLocal(JavaScriptEngineConstants.AXIS2_CONFIGURATION_CONTEXT);
                    if (object instanceof ConfigurationContext) {
                        ConfigurationContext configurationContext = (ConfigurationContext) object;
                        AxisConfiguration configuration = configurationContext.getAxisConfiguration();
                        Boolean allowHttpAccess = (Boolean) configuration.getParameterValue(
                                JavaScriptEngineConstants.ALLOW_HTTP_TRAFFIC_TO_MASHUPS);

                        // The Mashup server may be running behind a proxy so the best way to get
                        // the http address would be to get it from the http transport listener
                        // cause its configured correctly if its behind a proxy

                        // If httpAccess is allowed we take the http transport else we switch to the
                        // https transport
                        TransportInDescription inDescription;
                        if (allowHttpAccess.booleanValue()) {
                            inDescription = configuration
                                        .getTransportIn("http");
                        } else {
                            inDescription = configuration
                                        .getTransportIn("https");
                        }

                        // As this is a mashup service it would have the name in the form of
                        // authorName-serviceName and this service is not added to the axisConfig as
                        // yet. So the Listner would not fix the serviceName for us we need to fix
                        // it ourselves
                        int index = serviceName.indexOf("-");
                        if (index > -1) {
                            serviceName = serviceName.substring(0, index) + "/" +
                                    serviceName.substring(index + 1);
                        }
                        if (inDescription != null) {
                            try {
                                String requestIP = HttpUtils.getIpAddress(configuration);
                                EndpointReference endpointReference = inDescription.getReceiver()
                                        .getEPRForService(serviceName, requestIP);

                                // Once we get the EPR for this service we need to inject it into
                                // the script
                                engine.getCx()
                                        .evaluateString(engine, "system.wwwURL=\"" +
                                                endpointReference.getAddress() + "\"", "", 0, null);
                            } catch (SocketException e) {
                                log.error("Cannot get local IP address", e);
                            } catch (AxisFault axisFault) {
                                log.error(
                                        "Error obtaining endpoint reference for service " +
                                                serviceName, axisFault);
                            }

                        }
                    }
                }

            }
        }
    }
}

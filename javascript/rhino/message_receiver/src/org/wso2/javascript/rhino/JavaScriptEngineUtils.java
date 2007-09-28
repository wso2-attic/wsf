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

import java.lang.reflect.InvocationTargetException;
import java.security.PrivilegedActionException;
import java.security.PrivilegedExceptionAction;
import java.util.Iterator;

import javax.xml.namespace.QName;

import org.apache.axiom.om.OMElement;
import org.apache.axis2.AxisFault;
import org.apache.axis2.description.Parameter;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.util.Loader;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.mozilla.javascript.Scriptable;
import org.mozilla.javascript.ScriptableObject;

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
    
    private static void getHostObjectsList(OMElement hostObjectElement,JavaScriptEngine cx) throws AxisFault {
        Iterator iterator = hostObjectElement.getChildrenWithName(new QName("class"));
        while (iterator.hasNext()) {
            OMElement element = (OMElement) iterator.next();
            final String className = element.getText();
            if ((className != null) & (!className.equals(""))) {
                try {
                    ScriptableObject.defineClass(cx, loadClass(className));
                } catch (PrivilegedActionException e) {
                    log.fatal(e);
                    throw new AxisFault("Error occured while loading the host object :" + className, e);
                } catch (IllegalAccessException e) {
                    log.fatal(e);
                    throw new AxisFault("Error occured while loading the host object :" + className, e);
                } catch (InstantiationException e) {
                    log.fatal(e);
                    throw new AxisFault("Error occured while loading the host object :" + className, e);
                } catch (InvocationTargetException e) {
                    log.fatal(e);
                    throw new AxisFault("Error occured while loading the host object :" + className, e);
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
            AxisConfiguration axisConfig) {
        Parameter propertyObjectParameter = axisConfig
                .getParameter("javascript.global.propertyobjects");
        if ((propertyObjectParameter != null) && (propertyObjectParameter.getParameterType() == 2)) {
            OMElement paraElement = propertyObjectParameter.getParameterElement();
            loadGlobalProperties(paraElement, engine);
        }
    }
    
    private static void loadGlobalProperties(OMElement hostObjectElement, JavaScriptEngine engine) {
        Iterator iterator = hostObjectElement.getChildrenWithName(new QName("global.property"));
        while (iterator.hasNext()) {
            OMElement element = (OMElement) iterator.next();
            String objectName = element.getText();
            String hostObject = element.getAttributeValue(new QName("hostObject"));
            if ((objectName != null) & (!objectName.equals("")) & (hostObject != null)
                    & (!hostObject.equals(""))) {
                Scriptable entryHostObject = engine.getCx().newObject(engine, hostObject,
                        new Object[0]);
                engine.defineProperty(objectName, entryHostObject, ScriptableObject.READONLY);
            }
        }
    }
}

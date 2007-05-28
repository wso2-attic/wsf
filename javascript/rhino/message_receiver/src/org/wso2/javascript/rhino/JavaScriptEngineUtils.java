/*
 * Copyright 2006,2007 WSO2, Inc. http://www.wso2.org
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
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import javax.xml.namespace.QName;

import org.apache.axiom.om.OMElement;
import org.apache.axis2.AxisFault;
import org.apache.axis2.context.ConfigurationContext;
import org.apache.axis2.description.Parameter;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.util.Loader;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.mozilla.javascript.ScriptableObject;

public class JavaScriptEngineUtils {
    
    /*
     * setup for logging
     */
    private static final Log log = LogFactory.getLog(JavaScriptEngineUtils.class);

    public static void loadHostObjects(JavaScriptEngine cx, List list) throws AxisFault {
        Iterator iterator = list.iterator();
        while (iterator.hasNext()) {
            final String className = (String) iterator.next();
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

    public static Class loadClass(final String className) throws PrivilegedActionException {
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

    public static List getHostObjectsMap(OMElement hostObjectElement) {
        ArrayList list = new ArrayList();
        Iterator iterator = hostObjectElement.getChildrenWithName(new QName("class"));
        while (iterator.hasNext()) {
            OMElement element = (OMElement) iterator.next();
            String className = element.getText();
            if ((className != null) & (!className.equals(""))) {
                list.add(className);
            }
        }
        return list;
    }
    
    public static JavaScriptEngine getJavaScriptEngineWithHostObjects(AxisConfiguration axisConfig)
            throws AxisFault {
        JavaScriptEngine engine = new JavaScriptEngine();
        Parameter hostObjectParameter = axisConfig.getParameter(
                "javascript.hostobjects");
        if ((hostObjectParameter != null) && (hostObjectParameter.getParameterType() == 2)) {
            OMElement paraElement = hostObjectParameter.getParameterElement();
            List list = JavaScriptEngineUtils.getHostObjectsMap(paraElement);
            JavaScriptEngineUtils.loadHostObjects(engine, list);
        }
        return engine;
    }

}

/*
 * Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
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

import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.OMFactory;
import org.apache.axiom.om.OMNamespace;
import org.apache.axiom.om.impl.llom.OMSourcedElementImpl;
import org.apache.axis2.AxisFault;
import org.apache.axis2.databinding.utils.ConverterUtil;
import org.apache.axis2.json.JSONBadgerfishDataSource;
import org.apache.axis2.json.JSONDataSource;
import org.apache.axis2.json.JSONOMBuilder;
import org.mozilla.javascript.Context;
import org.mozilla.javascript.Function;
import org.mozilla.javascript.ImporterTopLevel;
import org.mozilla.javascript.JavaScriptException;
import org.mozilla.javascript.NativeArray;
import org.mozilla.javascript.NativeObject;
import org.mozilla.javascript.Scriptable;
import org.mozilla.javascript.ScriptableObject;
import org.mozilla.javascript.WrappedException;
import org.mozilla.javascript.xmlimpl.XML;
import org.mozilla.javascript.xmlimpl.XMLList;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.Reader;
import java.net.URL;
import java.util.Calendar;
import java.util.Date;

/**
 * Class JavaScriptEngine implements a simple Javascript evaluator using Rhino.
 * Two of the shell functionalities, print() and load(), are implemented as well.
 * Extending the ImporterTopLevel class gives access to the top level methods,
 * importClass() and importPackage().
 */
public class JavaScriptEngine extends ImporterTopLevel {
    //TODO Do we really need this?? (thilina)
    public static String axis2RepositoryLocation;

    private Context cx;

    /**
     * Constructs a new instance of the JavaScriptEngine class
     */
    public JavaScriptEngine() {
        super(Context.enter());
        cx = Context.getCurrentContext();
        String[] names = { "load", "print" };
        defineFunctionProperties(names, JavaScriptEngine.class, ScriptableObject.DONTENUM);
    }

    /**
     * Evaluates a Reader instance associated to a Javascript source.
     *
     * @param reader a Reader instance associated to a Javascript source
     * @throws IOException if the Reader instance generates an IOException
     */
    public void evaluate(Reader reader) throws IOException {
        cx.evaluateReader(this, reader, "<cmd>", 1, null);
    }

    /**
     * Loads and executes a set of Javascript source files. The source files
     * are searched relative to the service archive. If not found then the
     * search will assume absolute path is given. If fails again then it will
     * search under classes folder in Axis2 repository.
     *
     * <strong>We load this method to the JS Engine to be used internally by the java scripts.</strong>
     * @throws FileNotFoundException if the specified source cannot be found
     * @throws IOException           if evaluating the source produces an IOException
     */
    public static void load(Context cx, Scriptable thisObj, Object[] args, Function funObj)
            throws FileNotFoundException, IOException {

        JavaScriptEngine engine = (JavaScriptEngine) getTopLevelScope(thisObj);

        for (int i = 0; i < args.length; i++) {
            // Assumes resource's path is given relative to the service archive
            URL url = engine.getClass().getClassLoader().getResource(Context.toString(args[i]));
            File f = new File(url.getPath());
            if (!f.exists()) {
                // Assumes resource's path is given as absolute
                f = new File(Context.toString(args[i]));
                if (!f.exists() && axis2RepositoryLocation != null) {
                    // Assumes resource's path is given relative to the classes folder in Axis2 repository
                    f = new File(axis2RepositoryLocation + File.separator + "classes"
                            + File.separator + Context.toString(args[i]));
                }
            }
            FileReader fReader = new FileReader(f);
            engine.evaluate(fReader);
        }
    }

    /**
     * Prints the value of each element in the args array.
     * This is a similar implementation to the Rhino's print()
     * functionality in the shell.
     * <strong>We load this method to the JS Engine to be used internally by the java scripts.</strong>
     */
    public static void print(Context cx, Scriptable thisObj, Object[] args, Function funObj) {
        for (int i = 0; i < args.length; i++) {
            if (i > 0) {
                System.out.print(" ");
            }
            String s = Context.toString(args[i]);
            System.out.print(s);
        }
        System.out.println();
    }

    /**
     * Evaluates the requested operation in the Javascript service implementation.
     *
     * @param method Javascript operation name
     * @param reader a Reader instance associated with the Javascript service
     * @param args   an Object representing the input to the operation
     * @return an OMNode containing the result from executing the operation
     * @throws AxisFault
     */
    public OMElement call(String method, Reader reader, Object args) throws AxisFault {
        boolean json = false;
        Object functionArgs[];
        try {
            // Handle JSON messages
            if (args instanceof OMSourcedElementImpl) {
                Object datasource = ((OMSourcedElementImpl) args).getDataSource();
                if (datasource instanceof JSONDataSource) {
                    args = ((JSONDataSource) datasource).getCompleteJOSNString();
                    args = "var x = " + args + ";";
                    cx.evaluateString(this, (String) args, "Get JSON", 0, null);
                    args = this.get("x", this);
                    functionArgs = new Object [] { args };
                    json = true;
                } else if (datasource instanceof JSONBadgerfishDataSource) {
                    throw new AxisFault("Badgerfish Convention is not supported");
                } else {
                    throw new AxisFault("Unsupported Data Format");
                }

            } else if (args instanceof Object []) {
                 functionArgs = (Object [])args;
            } else if (args !=null) {
                Object[] objects = {args};
                args = cx.newObject(this, "XML",objects);
                functionArgs = new Object [] { args };
            } else {
                functionArgs = new Object [0];
            }
            
            // Evaluates the javascript file
            evaluate(reader);

            // Get the function from the scope the javascript object is in
            Object fObj = this.get(method, this);
            if (!(fObj instanceof Function) || (fObj == Scriptable.NOT_FOUND)) {
                throw new AxisFault("Method " + method + " is undefined or not a function");
            }
            // Invokes the java script function

            Function f = (Function) fObj;
            Object result = f.call(cx, this, this, functionArgs);

            if (json) {
                result = ((String) result).substring(1, ((String) result).length() - 1);
                InputStream in = new ByteArrayInputStream(((String) result).getBytes());
                JSONOMBuilder builder = new JSONOMBuilder();
                result = builder.processDocument(in, null, null);
            }
            // Convert the JS return to XML
            result = jsToXML(result, "return", false);
            return (OMElement) result;
        } catch (WrappedException exception) {
            throw AxisFault.makeFault(exception.getCause());
        } catch (JavaScriptException exception) {
            throw new AxisFault(exception.getValue().toString(), exception);
        } catch (Throwable throwable) {
            throw AxisFault.makeFault(throwable);
        }
    }

    /**
     * Evaluates the requested operation in the Javascript service
     * implementation. Any Javascript source defined under loadJSScripts
     * parameter is evaluated before evaluating the operation.
     * 
     * @param method
     *            Javascript operation name
     * @param reader
     *            a Reader instance associated with the Javascript service
     * @param args
     *            an Object representing the input to the operation
     * @param scripts
     *            a string represnting a set of Javascript files to be evaluated
     *            before evaluating the service
     * @return an OMNode containing the result from executing the operation
     * @throws AxisFault
     */
    public OMElement call(String method, Reader reader, Object args, String scripts) throws AxisFault {

        if (scripts != null) {
            // Generate load command out of the parameter scripts
            scripts = "load(" + ("[\"" + scripts + "\"]").replaceAll(",", "\"],[\"") + ")";
            cx.evaluateString(this, scripts, "Load JavaScripts", 0, null);
        }
        return call(method, reader, args);
    }

    public Context getCx() {
        return cx;
    }

    /**
     * Given a jsObject converts it to corresponding XML
     * @param jsObject  - The object that needs to be converted
     * @param elementName - The element name of the wrapper
     * @param addTypeInfo - Whether type information should be added into the element as an attribute
     * @return - OMelement which represents the JSObject
     * @throws AxisFault - Thrown in case an exception occurs during the conversion
     */
    private OMElement jsToXML(Object jsObject, String elementName, boolean addTypeInfo) throws AxisFault {
        String className = jsObject.getClass().getName();
        OMFactory fac = OMAbstractFactory.getOMFactory();
        OMNamespace namespace = fac.createOMNamespace("http://www.wso2.org/ns/jstype", "js");
        OMElement element = fac.createOMElement(elementName, null);
        // Get the OMNode inside the jsObjecting object
        if (jsObject instanceof XML) {
            element.addChild((((XML) jsObject).getAxiomFromXML()));
            if (addTypeInfo) {
                element.addAttribute("type", "xml", namespace);
            }
        } else if (jsObject instanceof XMLList) {
            XMLList list = (XMLList) jsObject;
            if (list.length() == 1) {
                element.addChild(list.getAxiomFromXML());
                if (addTypeInfo) {
                element.addAttribute("type", "xmlList", namespace);
                }
            } else if (list.length() == 0) {
                throw new AxisFault("Function returns an XMLList containing zero node");
            } else {
                throw new AxisFault(
                        "Function returns an XMLList containing more than one node");
            }
        } else {

            if (jsObject instanceof String) {
                element.setText((String) jsObject);
                if (addTypeInfo) {
                    element.addAttribute("type", "string", namespace);
                }
            } else if (jsObject instanceof Boolean) {
                Boolean booljsObject = (Boolean) jsObject;
                element.setText(booljsObject.toString());
                if (addTypeInfo) {
                    element.addAttribute("type", "boolean", namespace);
                }
            } else if (jsObject instanceof Number) {
                Number dbljsObject = (Number) jsObject;
                element.setText(dbljsObject.toString());
                if (addTypeInfo) {
                    element.addAttribute("type", "number", namespace);
                }
            } else if (jsObject instanceof Date || "org.mozilla.javascript.NativeDate".equals(className)) {
                Date date = (Date) Context.jsToJava(jsObject, Date.class);
                Calendar calendar = Calendar.getInstance();
                calendar.setTime(date);
                String dateTime = ConverterUtil.convertToString(calendar);
                element.setText(dateTime);
                if (addTypeInfo) {
                    element.addAttribute("type", "date", namespace);
                }
            } else if (jsObject instanceof NativeArray) {
                element.addAttribute("type", "array", namespace);
                NativeArray nativeArray = (NativeArray) jsObject;
                Object[] objects = nativeArray.getAllIds();
                for (int i = 0; i < objects.length; i++) {
                    Object object = objects[i];
                    Object o;
                    String propertyElementName;
                    if (object instanceof String) {
                        String property = (String) object;
                        if ("length".equals(property)) {
                            continue;
                        }
                        o = nativeArray.get(property, nativeArray);
                        propertyElementName = property;
                    } else {
                        Integer property = (Integer) object;
                        o = nativeArray.get(property.intValue(), nativeArray);
                        propertyElementName = "item";
                    }
                    OMElement paramElement = jsToXML(o, propertyElementName, true);
                    element.addChild(paramElement);
                }
            } else if (jsObject instanceof Object[]) {
                element.addAttribute("type", "array", namespace);
                Object[] objects = (Object[]) jsObject;
                for (int i = 0; i < objects.length; i++) {
                    Object object = objects[i];
                    OMElement paramElement = jsToXML(object, "item", true);
                    element.addChild(paramElement);
                }
            } else if (jsObject instanceof NativeObject) {
                element.addAttribute("type", "object", namespace);
                NativeObject nativeObject = (NativeObject) jsObject;
                Object[] objects = NativeObject.getPropertyIds(nativeObject);
                for (int i = 0; i < objects.length; i++) {
                    Object object = objects[i];
                    Object o;
                    if (object instanceof String) {
                        String property = (String) object;
                        o = nativeObject.get(property, nativeObject);
                        OMElement paramElement = jsToXML(o, property, true);
                        element.addChild(paramElement);
                    }
                }
            }
        }
        return element;
    }
}
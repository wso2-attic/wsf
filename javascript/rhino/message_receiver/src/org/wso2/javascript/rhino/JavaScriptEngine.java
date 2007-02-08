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

import org.mozilla.javascript.*;
import org.mozilla.javascript.xmlimpl.XML;
import org.apache.axis2.json.JSONOMBuilder;
import org.apache.axis2.AxisFault;
import org.apache.axiom.om.OMNode;

import java.io.*;
import java.net.URL;


public class JavaScriptEngine extends ImporterTopLevel {
    public static String repo;

    private Context cx;

    public JavaScriptEngine() {
        super(Context.enter());
        cx = Context.getCurrentContext();
        String[] names = {"load", "print"};
        defineFunctionProperties(names, JavaScriptEngine.class,
                ScriptableObject.DONTENUM);
    }


    public void evaluate(Reader reader) {
        try {
            cx.evaluateReader(this, reader, "<cmd>", 1, null);
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * Implements load functionality as in Rhino's shell
     *
     * @param cx
     * @param thisObj
     * @param args
     * @param funObj
     */
    public static void load(Context cx, Scriptable thisObj,
                            Object[] args, Function funObj) {

        JavaScriptEngine engine = (JavaScriptEngine) getTopLevelScope(thisObj);

        for (int i = 0; i < args.length; i++) {
            // Assumes resource's path is given relative to service archive
            URL url = engine.getClass().getClassLoader().getResource(Context.toString(args[i]));
            File f = new File(url.getPath());
            if (!f.exists()) {
                // Assumes resource's path is given as absolute
                f = new File(Context.toString(args[i]));
                if (!f.exists() && repo != null) {
                    // Assumes resource's path is given relative to classes folder in Axis2 repository
                    f = new File(repo + File.separator + "classes" + File.separator +
                            Context.toString(args[i]));
                }
            }
            try {
                FileReader fReader = new FileReader(f);
                engine.evaluate(fReader);
            } catch (FileNotFoundException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    /**
     * Implements print function as in Rhino's shell
     *
     * @param cx
     * @param thisObj
     * @param args
     * @param funObj
     */
    public static void print(Context cx, Scriptable thisObj,
                             Object[] args, Function funObj) {
        for (int i = 0; i < args.length; i++) {
            if (i > 0) {
                System.out.print(" ");
            }
            String s = Context.toString(args[i]);
            System.out.print(s);
        }
        System.out.println();
    }

    public OMNode call(String method, Reader reader, Object args, boolean json) throws AxisFault {
        return this.call(method, reader, args, null, json);
    }

    public OMNode call(String method, Reader reader, Object args, String scripts, boolean json) throws AxisFault {
        Object result = null;

        if (scripts != null) {
            //Generate load command out of the parameter scripts
            scripts = "load(" + ("[\"" + scripts + "\"]").replaceAll(",", "\"],[\"") + ")";
            cx.evaluateString(this, scripts, "Load JavaScripts", 0, null);
        }

        if (json) {
            args = "var x = " + args + ";";
            cx.evaluateString(this, (String) args, "Get JSON", 0, null);
            args = this.get("x", this);
        }

        // Evaluates the javascript file
        evaluate(reader);

        // Get the function from the scope the javascript object is in
        Object fObj = this.get(method, this);
        if (!(fObj instanceof Function) || (fObj == Scriptable.NOT_FOUND)) {
            throw new AxisFault("Method " + method + " is undefined or not a function");
        } else {
            Object functionArgs[] = {args};
            Function f = (Function) fObj;
            result = f.call(cx, this, this, functionArgs);
            if (json) {
                result = ((String) result).substring(1, ((String) result).length() - 1);
                InputStream in = new ByteArrayInputStream(((String) result).getBytes());
                JSONOMBuilder builder = new JSONOMBuilder();
                builder.init(in);
                result = builder.getDocumentElement();
            } else {
                // Get the OMNode inside the resulting object
                result = ((XML) result).getAxiomFromXML();
            }
        }
        return (OMNode) result;
    }
}
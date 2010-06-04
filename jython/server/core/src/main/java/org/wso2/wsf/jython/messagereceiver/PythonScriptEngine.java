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

package org.wso2.wsf.jython.messagereceiver;

import org.python.core.PySystemState;
import org.python.core.PyObject;
import org.python.util.PythonInterpreter;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/**
 * Contain the logic for programmetically executing python scripts.
 */
public class PythonScriptEngine {
    private static final Log log = LogFactory.getLog(PythonScriptEngine.class);

    /**
     * Takes the path of the python script, method name and method arguments and executes the given method and
     * returns the result
     *
     * @param method method to be executed.
     * @param reader python script which contains the methods to be executed.
     * @param args method arguments.
     * @return String returns the result after executing the method.
     */
    public static Object invoke(String method, String reader, Object args[]) {
        PySystemState.initialize();
        PythonInterpreter interpreter = new PythonInterpreter();
        interpreter.execfile(reader);

        String str = "";
        int len = args.length;
        for (int i = 0; i < len; i++) {
            if (i == len - 1) {
                str = str + args[i];
            } else {
                str = str + args[i] + ",";
            }
        }

        //PyFloat, PyInteger, PyLong , PyString, PyList, PyDictionary, PyTuple, PyArray, PyComplex,
        String s4 = "" + method + "(" + str + ")";
        if (log.isDebugEnabled()) {
            log.debug("String to be evaluated : " + s4);
        }

        return interpreter.eval(s4);
    }

    /**
     * Checks whether a given object is null.
     *
     * @param object object to be checked.
     * @return returns the result in boolean.
     */
    public static boolean isNull(Object object) {
        log.info(object == null);
        return object == null;
    }

    /**
     * Util method that can be used to execute a python script programmetically.
     */
    public void executeScript() {
        PySystemState.initialize();
        PythonInterpreter interp = new PythonInterpreter();

        interp.exec("import sys");
        interp.exec("print sys");
        String str2 = "filepy.py";
        interp.execfile(str2);

        PyObject x = interp.get("d");
        log.info("d: original value " + x);

        int s1 = 45, s2 = 45;
        String s3 = "addNumbers(" + s1 + "," + s2 + ")";
        log.info(interp.eval(s3));
    }

}

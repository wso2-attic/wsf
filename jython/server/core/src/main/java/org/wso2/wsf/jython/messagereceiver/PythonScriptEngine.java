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

public class PythonScriptEngine {
    private static final Log log = LogFactory.getLog(PythonScriptEngine.class);

    /**
     * Takes the path of the python script, method name and method arguments and executes the given method and
     * returns the result
     *
     * @param method
     * @param reader
     * @param args
     * @return String
     */
    public static Object invoke(String method, String reader, Object args[]) {
        PySystemState.initialize();
        PythonInterpreter interp = new PythonInterpreter();
        String fileName = reader;
        //String fileName = "/home/heshan/workspace/Axis2Service ver2/src/messagereceiver/filepy.py";
        interp.execfile(fileName);

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
        return interp.eval(s4);
    }


 public static boolean isNull(Object object) {
        System.out.println(object == null);
        return object == null;
    }


  /*     public void execute() {
        PySystemState.initialize();
        PythonInterpreter interp = new PythonInterpreter();
        //interp.exec("import sys");
        //interp.exec("print sys");
        String str2 = "filepy.py";
        interp.execfile(str2);
        PyObject x = interp.get("d");
        System.out.println("d: original value " + x);
        int s1 = 45, s2 = 45;
        String s3 = "addNumbers(" + s1 + "," + s2 + ")";
        PyObject y = interp.eval(s3);
    }
*/
    
}

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

import org.apache.log4j.Logger;
import org.mozilla.javascript.ErrorReporter;
import org.mozilla.javascript.EvaluatorException;

public class JavaScriptErrorReporter implements ErrorReporter {

    private static Logger log = Logger.getLogger(JavaScriptErrorReporter.class);

    public void warning(String message, String sourceName, int line, String lineSource,
                        int lineOffset) {
        String messageString =
                message + " in file " + sourceName + " at line " + line + " column " + lineOffset
                        + " in line :" + lineSource;
        log.warn(messageString);
    }

    public void error(String message, String sourceName, int line, String lineSource,
                      int lineOffset) {
        String messageString =
                message + " in file " + sourceName + " at line " + line + " column " + lineOffset
                        + " in line :" + lineSource;
        log.error(messageString);
    }

    public EvaluatorException runtimeError(String message, String sourceName, int line,
                                           String lineSource, int lineOffset) {
        String messageString =
                message + " in file " + sourceName + " at line " + line + " column " + lineOffset
                        + " in line :" + lineSource;
        log.error(messageString);
        return new EvaluatorException(message, sourceName, line, lineSource, lineOffset);
    }
}

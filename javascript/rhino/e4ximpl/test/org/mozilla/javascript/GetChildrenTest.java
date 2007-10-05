/*
* Copyright 2005,2006 WSO2, Inc. http://wso2.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

package org.wso2.javascript;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class GetChildrenTest extends AbstractTestCase {

    String scriptName = "getChildren";

    public GetChildrenTest(String testName) {
        super(testName);
    }

    public void setUp() {
        super.setUp();
    }

    public void testChildrenCount() {
        File testFile = getTestResourceFile(scriptName + ".js");
        Object result;

        try {
            cx.evaluateReader(scope, new FileReader(testFile), scriptName, 1, null);
            String command1 = "xml.*.length();";
            result = cx.evaluateString(scope, command1, scriptName, 1, null);
            assertEquals(Integer.parseInt(result.toString()), 2);

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    public void testDescendantChildrenCount() {
        File testFile = getTestResourceFile("getChildren.js");
        Object result;

        try {
            cx.evaluateReader(scope, new FileReader(testFile), scriptName, 1, null);
            String command1 = "xml..*.length();";
            result = cx.evaluateString(scope, command1, scriptName, 1, null);
            assertEquals(Integer.parseInt(result.toString()), 44);

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}

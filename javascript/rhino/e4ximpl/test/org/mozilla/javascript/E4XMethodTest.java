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
package org.mozilla.javascript;

import org.wso2.javascript.AbstractTestCase;

public class E4XMethodTest extends AbstractTestCase {
    /**
     * @param testName
     */
    public E4XMethodTest(String testName) {
        super(testName);
    }

    public void setUp() {
        super.setUp();
    }

//    public void testAppendChild() {
//            String command1 = "function testAppendChild(){\n" +
//                    "var test = <wrapper><item1>1</item1></wrapper>;\n" +
//                    "test.prependChild(<item0>0</item0>);\n" +
//                    "return test.toXMLString();\n" +
//                    "}" ;
//            Object result = cx.evaluateString(scope, command1, "testAppendChild", 1, null);
//            Object result2 = cx.evaluateString(scope, "testAppendChild();", "testAppendChild", 1, null);
//            assertEquals(Integer.parseInt(result2.toString()), 2);
//
//
//    }
}

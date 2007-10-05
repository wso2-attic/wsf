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

import junit.framework.TestCase;
import org.mozilla.javascript.Context;
import org.mozilla.javascript.ContextFactory;
import org.mozilla.javascript.Scriptable;
import org.mozilla.javascript.xml.XMLLib;

import java.io.File;
import java.net.URL;

public abstract class AbstractTestCase extends TestCase {

    public Context cx;
    public Scriptable scope;

    /**
     * @param testName
     */
    public AbstractTestCase(String testName) {
        super(testName);
    }

    public File getTestResourceFile(String relativePath) {
        URL url = this.getClass().getClassLoader().getResource(Context.toString(relativePath));
        return new File(url.getPath());
    }

    public void setUp() {
        if (!ContextFactory.hasExplicitGlobal()) {
            ContextFactory.initGlobal(new AxiomFactory());
        }
        cx = Context.enter();
        scope = cx.initStandardObjects();
    }

    class AxiomFactory extends ContextFactory {

        protected XMLLib.Factory getE4xImplementationFactory() {
            return org.mozilla.javascript.xml.XMLLib.Factory.create(
                    "org.wso2.javascript.xmlimpl.XMLLibImpl"
            );
        }
    }
}

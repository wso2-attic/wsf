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

package org.wso2.wsf.jython.deployer;

import org.apache.axis2.context.ConfigurationContext;
import org.apache.axis2.context.ConfigurationContextFactory;
import org.apache.axis2.transport.http.SimpleHTTPServer;

/**
 * This class programmetically starts up the Python deployer.
 */
public class JPythonServer {
    public static void main(String[] args) throws Exception {
        String repolocation = "/home/heshan/repo";
        String axis2XmlFilePath = "/home/heshan/IdeaProjects/PythDeployer/src/org/wso2/wsf/jython/deployer/axis.xml";
        ConfigurationContext configCtx =
                ConfigurationContextFactory.createConfigurationContextFromFileSystem(repolocation, axis2XmlFilePath);
        SimpleHTTPServer server = new SimpleHTTPServer(configCtx, 8080);
        server.start();
        System.out.println(" simpleHTTP server started !");
    }
}

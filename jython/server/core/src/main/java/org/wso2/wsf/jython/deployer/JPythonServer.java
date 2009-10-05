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
 * Created by IntelliJ IDEA.
 * User: heshan Suriyaarachchi
 * Date: Mar 25, 2008
 * Time: 2:07:50 PM
 * To change this template use File | Settings | File Templates.
 */
public class JPythonServer {
    public static void main(String[] args) throws Exception{
        ConfigurationContext configCtx = ConfigurationContextFactory.createConfigurationContextFromFileSystem("/home/heshan/repo","/home/heshan/IdeaProjects/PythDeployer/src/org/wso2/wsf/jython/deployer/axis.xml");
        SimpleHTTPServer  server = new SimpleHTTPServer(configCtx ,8080);
        server.start();
        System.out.println(" simpleHTTP server started !");
        
    }
}

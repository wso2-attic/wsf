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
package org.wso2.wsf.ide.wtp.ext.server.bean;

import org.wso2.wsf.ide.core.context.WSASEmitterContext;
import org.wso2.wsf.ide.core.plugin.WebServiceWSASCorePlugin;

public class WSASConfigurationBean {
	
	private static String wsasInstallationPath;
    private static String wsasDebugPort;
    private static boolean wsasCorrectPathSet = false;
    private static boolean wsasStartStatus = false;
    private static boolean wsasAlreadyRunning = false;
    private static WSASEmitterContext context;
    
    public static void Init(){
    	context = WebServiceWSASCorePlugin.getDefault().getWSASEmitterContext();
    	wsasInstallationPath = context.getWSASRuntimeLocation();
    	wsasCorrectPathSet = context.isCorrectWSASPathSet();
    	wsasDebugPort = context.getDebuPort();
    }

    public static boolean isWsasStartStatus() {
        return wsasStartStatus;
    }

    public static void setWsasStartStatus(boolean wsasStartStatus) {
        WSASConfigurationBean.wsasStartStatus = wsasStartStatus;
    }

    public static String getWsasInstallationPath() {
        return wsasInstallationPath;
    }

    public static void setWsasInstallationPath(String installationPath) {
        wsasInstallationPath = installationPath;
    }
    
    public static boolean isWSASAlreadyRunning() {
        return wsasAlreadyRunning;
    }

    public static void setWSASAlreadyRunning(boolean runningStatus) {
    	wsasAlreadyRunning = runningStatus;
    }

	public static boolean isWsasCorrectPathSet() {
		return wsasCorrectPathSet;
	}

	public static void setWsasCorrectPathSet(boolean wsasCorrectPathSet) {
		WSASConfigurationBean.wsasCorrectPathSet = wsasCorrectPathSet;
	}

	public static String getWsasDebugPort() {
		return wsasDebugPort;
	}

	public static void setWsasDebugPort(String wsasDebugPort) {
		WSASConfigurationBean.wsasDebugPort = wsasDebugPort;
	}

}

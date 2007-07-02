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
package org.wso2.wsf.wtp.server.command;

import java.lang.reflect.InvocationTargetException;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.wso2.wsf.wtp.server.bean.WSASConfigurationBean;

public class WSASStartCommand {
	
    private static IStatus status;
    //private Process wsasProcess = null;

	public  static IStatus run() throws InvocationTargetException {
		status = Status.OK_STATUS;
		Process wsasProcess = null;

		if (WSASConfigurationBean.isWsasStartStatus()) {
			status = new Status( IStatus.ERROR,"id",11,"WSAS Already Running !!",null);
			WSASConfigurationBean.setWSASAlreadyRunning(true);
		}else{
			//Init the Configuration Bean
			WSASConfigurationBean.Init();
		
				String wsasInstallationLocation = WSASConfigurationBean.getWsasInstallationPath();
				try {
					Runtime runtime = Runtime.getRuntime();
					String OS = System.getProperty("os.name").toLowerCase();
					if ((OS.indexOf("windows 9") > -1)
							|| (OS.indexOf("nt") > -1)
							|| (OS.indexOf("windows 2000") > -1)
							|| (OS.indexOf("windows xp") > -1)) {
						wsasProcess = runtime.exec(wsasInstallationLocation +"\\bin\\startup.bat");
					} else {
						wsasProcess = runtime.exec("sh " + wsasInstallationLocation +"\\bin\\startup.sh");
					}
					wsasProcess.waitFor();
				} catch (Exception e) {
					e.printStackTrace();
				}
				
				WSASConfigurationBean.setWSASAlreadyRunning(false);
				
		}
		return status;
	}

}

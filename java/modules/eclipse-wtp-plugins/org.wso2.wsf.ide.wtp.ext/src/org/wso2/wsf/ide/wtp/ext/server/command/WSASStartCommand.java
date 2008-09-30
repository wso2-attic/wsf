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
package org.wso2.wsf.ide.wtp.ext.server.command;

import java.io.File;
import java.lang.reflect.InvocationTargetException;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.FileUtils;
import org.wso2.wsf.ide.wtp.ext.server.bean.WSASConfigurationBean;
import org.wso2.wsf.ide.wtp.ext.server.util.WSASPing;
import org.wso2.wsf.ide.wtp.ext.server.util.WSASUtils;

public class WSASStartCommand {
	
    private static IStatus status;

	public  static IStatus run() throws InvocationTargetException {
		status = Status.OK_STATUS;

		if (WSASConfigurationBean.isWsasStartStatus()) {
			WSASPing pingUtil = new WSASPing();
			if(pingUtil.pingWSASService(WSASUtils.getWSASVersionServiceHTTPAddress())){
				status = new Status(IStatus.ERROR,"id",11,WSASCoreUIMessages.WSAS_ALREADY_RUNNING,null);
				WSASConfigurationBean.setWSASAlreadyRunning(true);
			}else{
				WSASConfigurationBean.setWsasStartStatus(false);
				//Close the browser
				WTPInternalBrowserCommand.closeUpInrernalBrouwser();
				startWSAS();
			}
		}else{
			startWSAS();
		}
		return status;
	}
	
	private static void startWSAS(){
		Process wsasProcess = null;
		WSASUtils.setTrustStoreDetails();
		String pathNodesStopWin[] = {WSASCoreUIMessages.DIR_BIN, WSASCoreUIMessages.WSAS_START_BAT};
		String pathNodesStopIx[] = {WSASCoreUIMessages.DIR_BIN, WSASCoreUIMessages.WSAS_START_SH};
		String pathNodesStopWinNew[] = {WSASCoreUIMessages.DIR_BIN, WSASCoreUIMessages.WSAS_START_BAT_NEW};
		String pathNodesStopIxNew[] = {WSASCoreUIMessages.DIR_BIN, WSASCoreUIMessages.WSAS_START_SH_NEW};		
		String wsasInstallationLocation = WSASConfigurationBean.getWsasInstallationPath();
		try {
			Runtime runtime = Runtime.getRuntime();
			String OS = System.getProperty(WSASCoreUIMessages.PROPERTIES_OS_NAME).toLowerCase();
			if ((OS.indexOf(WSASCoreUIMessages.OS_WIN_9) > -1)
					|| (OS.indexOf(WSASCoreUIMessages.OS_WIN_NT) > -1)
					|| (OS.indexOf(WSASCoreUIMessages.OS_WIN_2000) > -1)
					|| (OS.indexOf(WSASCoreUIMessages.OS_WIN_VISTA) > -1)
					|| (OS.indexOf(WSASCoreUIMessages.OS_WIN_XP) > -1)) {
				if ((new File(FileUtils.addNodesToPath(wsasInstallationLocation, 
						pathNodesStopWin))).exists())
					wsasProcess = runtime.exec(FileUtils.addNodesToPath(wsasInstallationLocation, 
																	pathNodesStopWin));
				else
					wsasProcess = runtime.exec(FileUtils.addNodesToPath(wsasInstallationLocation, 
							pathNodesStopWinNew));
				wsasProcess.waitFor();
			} else {
				if ((new File(FileUtils.addNodesToPath(wsasInstallationLocation, 
						pathNodesStopIx))).exists())
					wsasProcess = runtime.exec(WSASCoreUIMessages.XTERM_EXEC + 
							FileUtils.addNodesToPath(wsasInstallationLocation, pathNodesStopIx));
				else
					wsasProcess = runtime.exec(WSASCoreUIMessages.XTERM_EXEC + 
							FileUtils.addNodesToPath(wsasInstallationLocation, pathNodesStopIxNew));
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		WSASConfigurationBean.setWSASAlreadyRunning(false);
	}

}

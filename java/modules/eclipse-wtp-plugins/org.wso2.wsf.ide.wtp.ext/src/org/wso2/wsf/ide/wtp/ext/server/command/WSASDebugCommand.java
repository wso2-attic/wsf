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
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.FileUtils;
import org.wso2.wsf.ide.wtp.ext.server.bean.WSASConfigurationBean;
import org.wso2.wsf.ide.wtp.ext.server.util.WSASDebugUtil;

public class WSASDebugCommand {
	
    private static IStatus status;

	public  static IStatus run() throws InvocationTargetException{
	 try{
		status = Status.OK_STATUS;
		Process wsasProcess = null;
		String pathNodesStopWin[] = {WSASCoreUIMessages.DIR_BIN, WSASCoreUIMessages.WSAS_DEBUG_BAT};
		String pathNodesStopIx[] = {WSASCoreUIMessages.DIR_BIN, WSASCoreUIMessages.WSAS_START_SH};
		WSASDebugUtil debugUtil = new WSASDebugUtil();
		File runnerFile = debugUtil.createWindowsDebugRunnerFile();

		if (WSASConfigurationBean.isWsasStartStatus()) {
			status = new Status( IStatus.ERROR,"id",11,WSASCoreUIMessages.WSAS_ALREADY_RUNNING,null);
			WSASConfigurationBean.setWSASAlreadyRunning(true);
		}else{
		
				String wsasInstallationLocation = WSASConfigurationBean.getWsasInstallationPath();
					Runtime runtime = Runtime.getRuntime();
					String OS = System.getProperty(WSASCoreUIMessages.PROPERTIES_OS_NAME).toLowerCase();
					String debugAppender = WSASCoreUIMessages.WSAS_DEFAULT_DEBUG_APPENDER +
					                       WSASConfigurationBean.getWsasDebugPort();
					if ((OS.indexOf(WSASCoreUIMessages.OS_WIN_9) > -1)
							|| (OS.indexOf(WSASCoreUIMessages.OS_WIN_NT) > -1)
							|| (OS.indexOf(WSASCoreUIMessages.OS_WIN_2000) > -1)
							|| (OS.indexOf(WSASCoreUIMessages.OS_WIN_VISTA) > -1)
							|| (OS.indexOf(WSASCoreUIMessages.OS_WIN_XP) > -1)) {
						wsasProcess = runtime.exec(runnerFile.getAbsolutePath() + " "+ 
													FileUtils.addNodesToPath(wsasInstallationLocation, 
																			pathNodesStopWin) 
																			+debugAppender);
						wsasProcess.waitFor();
					} else {
						wsasProcess = runtime.exec(WSASCoreUIMessages.XTERM_EXEC + 
							FileUtils.addNodesToPath(wsasInstallationLocation, pathNodesStopIx) 
						              +debugAppender);
					}
				WSASConfigurationBean.setWSASAlreadyRunning(false);
		}
		runnerFile.delete();
	  } catch (Exception e) {
		e.printStackTrace();
	  }
	  return status;
	}

}

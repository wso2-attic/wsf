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
package org.wso2.wsf.ide.creation.core.command;

import java.io.File;

import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.wst.common.environment.IEnvironment;
import org.eclipse.wst.common.environment.IStatusHandler;
import org.eclipse.wst.common.frameworks.datamodel.AbstractDataModelOperation;
import org.eclipse.wst.ws.internal.wsrt.WebServiceScenario;
import org.wso2.wsf.ide.consumption.core.utils.ContentCopyUtils;
import org.wso2.wsf.ide.core.utils.FileUtils;
import org.wso2.wsf.ide.creation.core.data.DataModel;
import org.wso2.wsf.ide.creation.core.messages.WSASCreationUIMessages;

public class WSASWebservicesServerCommand extends AbstractDataModelOperation {

	private DataModel model;
	private int scenario;

	public WSASWebservicesServerCommand( DataModel model, int scenario ){
		this.model = model;  
		this.scenario = scenario;
	}

	public IStatus execute(IProgressMonitor monitor, IAdaptable info)
	throws ExecutionException {

		IStatus status = Status.OK_STATUS;
		IEnvironment environment = getEnvironment();
		IStatusHandler statusHandler = environment.getStatusHandler();	

		String workspaceDirectory = ResourcesPlugin.getWorkspace().getRoot().
													getLocation().toOSString();
		String currentDynamicWebProjectDir = FileUtils.addAnotherNodeToPath(
														workspaceDirectory, 
														model.getWebProjectName()); 

		//TODO The Web content directory can be different. cater that also
		String webContainerDirString = FileUtils.addAnotherNodeToPath(currentDynamicWebProjectDir,
															WSASCreationUIMessages.DIR_WEBCONTENT);

		ContentCopyUtils contentCopyUtils = new ContentCopyUtils();
		
		//Check for the server status
		if (model.getServerStatus()){
			if (scenario == WebServiceScenario.BOTTOMUP){
				//Import the tempory webservices directory according to the Resources API of eclipse 
				String webserviceTempDirString = model.getPathToWebServicesTempDir();
				String repositoryString = webContainerDirString 
				+ File.separator + WSASCreationUIMessages.DIR_WEB_INF 
				+ File.separator + WSASCreationUIMessages.DIR_SERVICES;
				//Copy the existing services to the repository
				status = contentCopyUtils.copyDirectoryRecursivelyIntoWorkspace(
											webserviceTempDirString, 
											repositoryString, 
											monitor, 
											statusHandler);
				FileUtils.deleteDirectories(webserviceTempDirString);


			}else if (scenario == WebServiceScenario.TOPDOWN){
				//Do topdown
				String webserviceTempDirString = model.getPathToWebServicesTempDir();
				String repositoryString = webContainerDirString 
				+ File.separator + WSASCreationUIMessages.DIR_WEB_INF 
				+ File.separator + WSASCreationUIMessages.DIR_SERVICES;
				//Copy the existing services to the repository
				status = contentCopyUtils.copyDirectoryRecursivelyIntoWorkspace(
											webserviceTempDirString, 
											repositoryString, 
											monitor, 
											statusHandler);
				FileUtils.deleteDirectories(webserviceTempDirString);
			}
			status = Status.OK_STATUS;
		}else{
			status = Status.CANCEL_STATUS;
		}

		return status;
	}

}

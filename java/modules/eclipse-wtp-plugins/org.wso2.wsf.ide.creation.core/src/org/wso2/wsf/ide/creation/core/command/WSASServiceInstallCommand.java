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
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.wst.common.frameworks.datamodel.AbstractDataModelOperation;
import org.eclipse.wst.ws.internal.wsrt.IWebService;
import org.eclipse.wst.ws.internal.wsrt.WebServiceScenario;
import org.wso2.wsf.ide.core.plugin.data.ServerModel;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.FileUtils;
import org.wso2.wsf.ide.core.utils.WSASCoreUtils;
import org.wso2.wsf.ide.creation.core.data.DataModel;
import org.wso2.wsf.ide.creation.core.utils.CommonUtils;

public class WSASServiceInstallCommand extends
		AbstractDataModelOperation {
	
	  	private DataModel model;
		private IWebService ws;
		private int scenario;

	  public WSASServiceInstallCommand( DataModel model,IWebService ws, String project,int scenario )
	  {
	    this.model = model;  
	    this.ws=ws;
	    this.scenario=scenario;
	  }

	public IStatus execute(IProgressMonitor monitor, IAdaptable info)
			throws ExecutionException {
		IStatus status = Status.OK_STATUS;  
	    try {
			//Install the created service to the WSAS Runtime
			Properties properties = new Properties();
			properties.load(new FileInputStream(WSASCoreUtils.tempWSASWebappFileLocation()));
			String wsasHomeLocation = null;
			if (properties.containsKey(WSASCoreUIMessages.PROPERTY_KEY_PATH)) {
				wsasHomeLocation = (ServerModel.getWsasServerPath() != null) 
						? ServerModel.getWsasServerPath()
						: properties.getProperty(WSASCoreUIMessages.PROPERTY_KEY_PATH);
			}
			String serviceName = null;
			//Get the Service name from the class name
			if (scenario==WebServiceScenario.BOTTOMUP) {
				serviceName = CommonUtils.classNameFromQualifiedName(ws.getWebServiceInfo().getImplURL());
			}else if (scenario == WebServiceScenario.TOPDOWN){
				serviceName = model.getServiceName();
			}
			
			String repoNodes[] = {"repository", "services", serviceName};
			String wsasRepoLocationOfService = FileUtils.addNodesToPath(wsasHomeLocation, repoNodes);
			File wsasRepoLocationOfServiceFile = new File(wsasRepoLocationOfService);
			if(!wsasRepoLocationOfServiceFile.exists()){
				FileUtils.createDirectorys(wsasRepoLocationOfService);
			}
			
			//New Web Service Folder Location 
			String workspaceDirectory = ResourcesPlugin.getWorkspace()
											.getRoot().getLocation().toOSString();
			String currentDynamicWebProjectDir = FileUtils.addAnotherNodeToPath(workspaceDirectory, 
					model.getWebProjectName());

			String newNodes[] = {"WebContent", "WEB-INF","services",serviceName};
			String servicesDirectory = FileUtils.addNodesToPath(currentDynamicWebProjectDir, newNodes);	
			
			//Copy the directory to wsas
			FileUtils.copyDirectory(new File(servicesDirectory), new File(wsasRepoLocationOfService));
		} catch (IOException e) {
		}
		return status;
	}
}

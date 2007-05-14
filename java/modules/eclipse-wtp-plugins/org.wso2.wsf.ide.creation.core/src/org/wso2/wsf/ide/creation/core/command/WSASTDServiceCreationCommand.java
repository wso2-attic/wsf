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
import java.io.IOException;

import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.osgi.util.NLS;
import org.eclipse.wst.command.internal.env.core.common.StatusUtils;
import org.eclipse.wst.common.environment.IEnvironment;
import org.eclipse.wst.common.frameworks.datamodel.AbstractDataModelOperation;
import org.eclipse.wst.ws.internal.wsrt.IWebService;
import org.wso2.wsf.ide.core.utils.FileUtils;
import org.wso2.wsf.ide.creation.core.data.DataModel;
import org.wso2.wsf.ide.creation.core.messages.WSASCreationUIMessages;

public class WSASTDServiceCreationCommand extends
AbstractDataModelOperation {
	
  	private DataModel model;

  public WSASTDServiceCreationCommand( DataModel model,IWebService ws, String project )
  {
    this.model = model;  
  }

public IStatus execute(IProgressMonitor monitor, IAdaptable info)
		throws ExecutionException {
	IStatus status = Status.OK_STATUS;  
	IEnvironment environment = getEnvironment();
	//The full Qulalified Service Class
//	String serviceDefinition = ws.getWebServiceInfo().getWsdlURL(); 
	try {
		
//		String workspaceDirectory = ResourceUtils.getWorkspaceRoot().getLocation().toOSString();
		String workspaceDirectory = ResourcesPlugin.getWorkspace()
														.getRoot().getLocation().toOSString();
		String currentDynamicWebProjectDir = FileUtils.addAnotherNodeToPath(workspaceDirectory, 
														model.getWebProjectName());
		String matadataDir = FileUtils.addAnotherNodeToPath(workspaceDirectory,
														WSASCreationUIMessages.DIR_DOT_METADATA);
	    String matadataPluginsDir = FileUtils.addAnotherNodeToPath(matadataDir,
	    												WSASCreationUIMessages.DIR_DOT_PLUGINS);
	    String matadataWSASDir = FileUtils.addAnotherNodeToPath(matadataPluginsDir, 
	    												WSASCreationUIMessages.WSAS_PROJECT);
	    String tempServicesDir = FileUtils.addAnotherNodeToPath(matadataWSASDir,
	    													   WSASCreationUIMessages.DIR_SERVICES);
	    
	    model.setPathToWebServicesTempDir(tempServicesDir);
		
	    //Exploded temperory services directory
		String currentservicesDirectory = FileUtils.addAnotherNodeToPath(tempServicesDir, 
														model.getServiceName());
		String metaInfDirectory = FileUtils.addAnotherNodeToPath(currentservicesDirectory, 
														WSASCreationUIMessages.DIR_META_INF);
		
		//Create the directories
		//Create the Webservices stuff on the workspace .matadata directory  
	    FileUtils.createDirectorys(currentservicesDirectory);
	    FileUtils.createDirectorys(metaInfDirectory);		    
	    
	    
	    //copy the generated resources (services.xml .wsdl ) files
	    //at resources/service.xml
	    String currentProjectResourcesDirString = FileUtils
	    		.addAnotherNodeToPath(currentDynamicWebProjectDir, 
	    							  WSASCreationUIMessages.DIR_RESOURCES);
	    File currentProjectResourcesDir = new File(currentProjectResourcesDirString);
	    if(!currentProjectResourcesDir.exists()){
	    	currentProjectResourcesDir.mkdir();
	    }
	    FileUtils.copyDirectory(currentProjectResourcesDir, new File(metaInfDirectory));
        
        // Copy the classes directory to the sevices directory
		String defaultClassesSubDirectory = WSASCreationUIMessages.DIR_BUILD + File.separator + 
											WSASCreationUIMessages.DIR_CLASSES;
		//TODO copy only the relevent .classes to the aar
		String classesDirectory = currentDynamicWebProjectDir + File.separator + 
											defaultClassesSubDirectory;
		
		FileUtils.copyDirectory(new File(classesDirectory), new File(currentservicesDirectory));
		
//		//Create the .aar file 
//		String aarDirString =  FileUtils.addAnotherNodeToPath(webservicesDir, 
// 		WSASCreationUIMessages.DIR_AAR);
//		File aarDir = new File(aarDirString);
//		FileUtils.createDirectorys(aarDirString);
//		AARFileWriter aarFileWriter = new AARFileWriter();
//		File serviseDir = new File(servicesDirectory);
//		aarFileWriter.writeAARFile(aarDir, serviceName + 
//		WSASCreationUIMessages.FILE_AAR, serviseDir);
		
		
		//Import all the stuff form the .matadata directory to inside the current web project
		} catch (IOException e) {
			status = StatusUtils.errorStatus(
					NLS.bind(WSASCreationUIMessages.ERROR_INVALID_FILE_READ_WRITEL,
							new String[]{e.getLocalizedMessage()}), e);
			environment.getStatusHandler().reportError(status); 
		} catch (Exception e) {
			status = StatusUtils.errorStatus(
					NLS.bind(WSASCreationUIMessages.ERROR_INVALID_SERVICE_CREATION,
							new String[]{e.getLocalizedMessage()}), e);
			environment.getStatusHandler().reportError(status); 
		}
	    
	
    
    return status;
}
}

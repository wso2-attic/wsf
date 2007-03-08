package org.wso2.wsf.wtp.ws.creation.core.command;

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
import org.wso2.wsf.wtp.core.utils.FileUtils;
import org.wso2.wsf.wtp.ws.creation.core.data.DataModel;
import org.wso2.wsf.wtp.ws.creation.core.messages.WSASCreationUIMessages;

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

		// Location of the axis2 plugin to copy tho the current project
//		String correctUserDir = Platform.getInstallLocation().getURL().getPath().toString();
		
		//TODO The Web content directory can be different. cater that also
		String webContainerDirString = FileUtils.addAnotherNodeToPath(currentDynamicWebProjectDir,
															WSASCreationUIMessages.DIR_WEBCONTENT);

//		//TODO some how get this plugin location 
//		String axis2WebappLocation = FileUtils.addAnotherNodeToPath(
//										workspaceDirectory, WSASCreationUIMessages.AXIS2_RUNTIME);
		
//		String[] webappPath= {WSASCreationUIMessages.DIR_PLUGINS, 		
//							  WSASCreationUIMessages.AXIS2_RUNTIME};
//		String axis2WebappLocation = FileUtils.addNodesToPath(correctUserDir, webappPath);
//
		ContentCopyUtils contentCopyUtils = new ContentCopyUtils();
//		status = contentCopyUtils.copyDirectoryRecursivelyIntoWorkspace(
//												axis2WebappLocation, 
//												webContainerDirString, 
//												monitor, 
//												statusHandler);
		
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
			//stsus = 
		}


		return status;

	}


}

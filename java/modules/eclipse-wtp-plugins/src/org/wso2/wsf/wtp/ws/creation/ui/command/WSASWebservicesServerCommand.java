package org.wso2.wsf.wtp.ws.creation.ui.command;

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
import org.wso2.wsf.wtp.ws.creation.ui.WSASCreationUIMessages;
import org.wso2.wsf.wtp.ws.creation.ui.data.DataModel;
import org.wso2.wsf.wtp.ws.creation.ui.widgets.utils.ContentCopyUtils;
import org.wso2.wsf.wtp.ws.creation.ui.widgets.utils.FileUtils;

public class WSASWebservicesServerCommand extends
AbstractDataModelOperation {

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
		String dir[] = System.getProperty("user.dir").split(File.separator+
															WSASCreationUIMessages.DIR_WORKSPACE);
		String correctUserDir = dir[0];
//		String pluginDir= correctUserDir + File.separator + Axis2CreationUIMessages.DIR_PLUGINS;
		//TODO The Web content directory can be different. cater that also
		String webContainerDirString = FileUtils.addAnotherNodeToPath(currentDynamicWebProjectDir,
															WSASCreationUIMessages.DIR_WEBCONTENT);
//		String currentDynamicWebProjectWebservicesDir = FileUtils.addAnotherNodeToPath(
//														currentDynamicWebProjectDir, 
//														Axis2CreationUIMessages.DIR_WEBSERVICES);

		//TODO some how get this plugin location 
		String wsasWebappLocation = 
		correctUserDir
		+ File.separator+ WSASCreationUIMessages.DIR_WORKSPACE
		+ File.separator+ WSASCreationUIMessages.WSAS_RUNTIME
		+ File.separator+ WSASCreationUIMessages.DIR_SRC;

//		String axis2WebappLocation = 
//			System.getProperty("user.dir")
//			+ File.separator+ Axis2CreationUIMessages.DIR_PLUGINS
//			+ File.separator+ Axis2CreationUIMessages.AXIS2_RUNTIME
//			+ File.separator+ Axis2CreationUIMessages.DIR_AXIS2;

		ContentCopyUtils contentCopyUtils = new ContentCopyUtils();
		status = contentCopyUtils.copyDirectoryRecursivelyIntoWorkspace(
												wsasWebappLocation, 
												webContainerDirString, 
												monitor, 
												statusHandler);

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
		return status;

	}


}

package org.wso2.wsf.wtp.ws.creation.ui.command;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
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
import org.wso2.wsf.wtp.ws.creation.ui.WSASCreationUIMessages;
import org.wso2.wsf.wtp.ws.creation.ui.data.DataModel;
import org.wso2.wsf.wtp.ws.creation.ui.widgets.utils.CommonUtils;
import org.wso2.wsf.wtp.ws.creation.ui.widgets.utils.FileUtils;
import org.wso2.wsf.wtp.ws.creation.ui.widgets.utils.ServiceXMLCreator;

public class WSASBUServiceCreationCommand extends
		AbstractDataModelOperation {
	
	  	private DataModel model;
		private IWebService ws;

	  public WSASBUServiceCreationCommand( DataModel model,IWebService ws, String project )
	  {
	    this.model = model;  
	    this.ws=ws;
	  }

	public IStatus execute(IProgressMonitor monitor, IAdaptable info)
			throws ExecutionException {
		IStatus status = Status.OK_STATUS;  
		IEnvironment environment = getEnvironment();
		//The full Qulalified Service Class
		String serviceClass = ws.getWebServiceInfo().getImplURL(); 
		try {
			
			String workspaceDirectory = ResourcesPlugin.getWorkspace().getRoot().getLocation().toOSString();
			String currentDynamicWebProjectDir = FileUtils.addAnotherNodeToPath(workspaceDirectory, model.getWebProjectName());
			String matadataDir = FileUtils.addAnotherNodeToPath(workspaceDirectory,WSASCreationUIMessages.DIR_DOT_METADATA);
		    String matadataPluginsDir = FileUtils.addAnotherNodeToPath(matadataDir,WSASCreationUIMessages.DIR_DOT_PLUGINS);
		    String matadataAxis2Dir = FileUtils.addAnotherNodeToPath(matadataPluginsDir, WSASCreationUIMessages.AXIS2_PROJECT);
		    String webservicesDir = FileUtils.addAnotherNodeToPath(matadataAxis2Dir,
		    													   WSASCreationUIMessages.DIR_WEBSERVICES);
		    model.setPathToWebServicesTempDir(webservicesDir);
		    
			//Get the Service name from the class name
		    String serviceName = CommonUtils.classNameFromQualifiedName(serviceClass); 
		    //String servicePackage = CommonUtils.packageNameFromQualifiedName(serviceClass); 
			
			String servicesDirectory = FileUtils.addAnotherNodeToPath(webservicesDir, serviceName);
			//String servicePackagePath = CommonUtils.packgeName2PathName(servicePackage); 
			//String serviceClassImplDirectory = servicesDirectory + File.separator + servicePackagePath;
			String serviceXMLDirectory = FileUtils.addAnotherNodeToPath(servicesDirectory, WSASCreationUIMessages.DIR_META_INF);
			
			//Create the directories
			//Create the Webservices stuff on the workspace .matadata directory  
		    FileUtils.createDirectorys(servicesDirectory);
		    FileUtils.createDirectorys(serviceXMLDirectory);		    
		    
		    //create the services.xml file
		    File serviceXMLFile;
            if (model.isGenerateServicesXML()){
			    ServiceXMLCreator serviceXMLCreator = new ServiceXMLCreator(serviceName, serviceClass, null);
			    serviceXMLFile = new File(serviceXMLDirectory + File.separator + WSASCreationUIMessages.FILE_SERVICES_XML);
			    FileWriter serviceXMLFileWriter;
	
				serviceXMLFileWriter = new FileWriter(serviceXMLFile, false);
	            BufferedWriter writer = new BufferedWriter(serviceXMLFileWriter) ;
	            writer.write(serviceXMLCreator.toString()) ;
	            writer.close() ;
            }else {
            	String pathToServicesXML = model.getPathToServicesXML();
            	if (pathToServicesXML == null){
    				status = StatusUtils.errorStatus(WSASCreationUIMessages.ERROR_INVALID_SERVICES_XML);
    				environment.getStatusHandler().reportError(status); 
            	}else{
            		serviceXMLFile = new File(pathToServicesXML);
            		File targetServicesXMLFile = new File(serviceXMLDirectory + File.separator + WSASCreationUIMessages.FILE_SERVICES_XML);
            		FileUtils.copy(serviceXMLFile, targetServicesXMLFile);
            	}
            	
            }
	        
            // Copy the classes directory to the sevices directory
			String defaultClassesSubDirectory = WSASCreationUIMessages.DIR_BUILD + File.separator + WSASCreationUIMessages.DIR_CLASSES;
			//TODO copy only the relevent .classes to the aar
			String classesDirectory = currentDynamicWebProjectDir + File.separator + defaultClassesSubDirectory;
			FileUtils.copyDirectory(new File(classesDirectory), new File(servicesDirectory));
			
		
			//Import all the stuff form the .matadata directory to inside the current web project
			} catch (IOException e) {
				status = StatusUtils.errorStatus(NLS.bind(WSASCreationUIMessages.ERROR_INVALID_FILE_READ_WRITEL,new String[]{e.getLocalizedMessage()}), e);
				environment.getStatusHandler().reportError(status); 
			} catch (Exception e) {
				status = StatusUtils.errorStatus(NLS.bind(WSASCreationUIMessages.ERROR_INVALID_SERVICE_CREATION,new String[]{e.getLocalizedMessage()}), e);
				environment.getStatusHandler().reportError(status); 
			}
		    
		
	    
	    return status;
	}
}

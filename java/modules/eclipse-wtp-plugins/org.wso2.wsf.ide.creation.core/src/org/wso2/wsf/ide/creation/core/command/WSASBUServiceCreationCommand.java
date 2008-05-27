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

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Path;
import org.eclipse.core.runtime.Status;
import org.eclipse.osgi.util.NLS;
import org.eclipse.wst.command.internal.env.core.common.StatusUtils;
import org.eclipse.wst.common.environment.IEnvironment;
import org.eclipse.wst.common.frameworks.datamodel.AbstractDataModelOperation;
import org.eclipse.wst.ws.internal.wsrt.IWebService;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.FileUtils;
import org.wso2.wsf.ide.core.utils.ServiceImplFilterUtil;
import org.wso2.wsf.ide.creation.core.data.DataModel;
import org.wso2.wsf.ide.creation.core.messages.WSASCreationUIMessages;
import org.wso2.wsf.ide.creation.core.utils.CommonUtils;
import org.wso2.wsf.ide.creation.core.utils.ServiceXMLCreator;

public class WSASBUServiceCreationCommand extends
		AbstractDataModelOperation {
	
	  	private DataModel model;
		private IWebService ws;
		//This Map contains the service include class list as <Class,[Package,Location]>
		private Map<String,String[]> serviceIncludeClassList = new HashMap<String, String[]>();

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
			
//			String workspaceDirectory = ResourceUtils.getWorkspaceRoot().getLocation().toOSString();
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
		    String webservicesDir = FileUtils.addAnotherNodeToPath(matadataWSASDir,
		    													   WSASCreationUIMessages.DIR_WEBSERVICES);
		    model.setPathToWebServicesTempDir(webservicesDir);
		    
			//Get the Service name from the class name
		    String serviceName = CommonUtils.classNameFromQualifiedName(serviceClass); 
		    //String servicePackage = CommonUtils.packageNameFromQualifiedName(serviceClass); 
			
			String servicesDirectory = FileUtils.addAnotherNodeToPath(webservicesDir, serviceName);
			String serviceXMLDirectory = FileUtils.addAnotherNodeToPath(servicesDirectory, 
														WSASCreationUIMessages.DIR_META_INF);
			
			//Create the directories
			//Create the Webservices stuff on the workspace .matadata directory  
		    FileUtils.createDirectorys(servicesDirectory);
		    FileUtils.createDirectorys(serviceXMLDirectory);		    
		    
		    //create the services.xml file
		    File serviceXMLFile;
            if (model.isGenerateServicesXML()){
			    ServiceXMLCreator serviceXMLCreator = new ServiceXMLCreator(serviceName, 
			    															serviceClass, 	
			    															null);
			    serviceXMLFile = new File(serviceXMLDirectory + File.separator + 
			    						  WSASCreationUIMessages.FILE_SERVICES_XML);
			    FileWriter serviceXMLFileWriter;
	
				serviceXMLFileWriter = new FileWriter(serviceXMLFile, false);
	            BufferedWriter writer = new BufferedWriter(serviceXMLFileWriter) ;
	            writer.write(serviceXMLCreator.toString()) ;
	            writer.close() ;
            }else {
            	String pathToServicesXML = model.getPathToServicesXML();
            	if (pathToServicesXML == null){
    				status = StatusUtils
    					.errorStatus(WSASCreationUIMessages.ERROR_INVALID_SERVICES_XML);
    				environment.getStatusHandler().reportError(status); 
            	}else{
            		serviceXMLFile = new File(pathToServicesXML);
            		File targetServicesXMLFile = new File(serviceXMLDirectory + File.separator + 
            										WSASCreationUIMessages.FILE_SERVICES_XML);
            		FileUtils.copy(serviceXMLFile, targetServicesXMLFile);
            	}
            	
            }
	        
            // Copy the classes directory to the sevices directory
			String defaultClassesSubDirectory = WSASCreationUIMessages.DIR_BUILD +File.separator+ 
													WSASCreationUIMessages.DIR_CLASSES;
			String classesDirectory = currentDynamicWebProjectDir + File.separator + 
			                                                        defaultClassesSubDirectory;
			//Copy only the relevent .classes to the service (Filter mechanism of impl classes)
			File[] matchingPossibleServiceFiles = ServiceImplFilterUtil.getMatchingFiles(classesDirectory,
					                             serviceName, ".class");

			if (model.isIncludeExtLibs()){
				//create the lib directory and copy the libraries from the list
				String[] includeLibList = model.getExternalLibFileSet();
				if (includeLibList != null) {
					for (int i = 0; i < includeLibList.length; i++) {
						IPath serviceLibDirectory = new Path(servicesDirectory);
						serviceLibDirectory = serviceLibDirectory
								.append(WSASCoreUIMessages.DIR_LIB);
						File serviceLibDir = new File(serviceLibDirectory
								.toOSString());
						if (!serviceLibDir.exists()) {
							serviceLibDir.mkdirs();
						}
						File actualJARFile = new File(includeLibList[i]);
						IPath newLibFile = new Path(serviceLibDir.getAbsolutePath());
						newLibFile = newLibFile.append(actualJARFile.getName());
						File newJARFile = new File(newLibFile.toOSString());
						newJARFile.createNewFile();
						FileUtils.copy(actualJARFile, newJARFile);
					}
				}
			}
			
			String classFileDestination = null;
			String mainPackage = null;
			String packageString = null;
			//This loop searches for the exact match of the service class
			//And identifies its main package
			for (int i = 0; i < matchingPossibleServiceFiles.length; i++) {
				if (matchingPossibleServiceFiles[i].getName().toString().equals(serviceName+".class")) {
					String[] result = new String[2];
					if (matchingPossibleServiceFiles[i].getAbsolutePath().contains("\\")) {
						result[0] = matchingPossibleServiceFiles[i].getAbsolutePath()
										.substring(classesDirectory.length());
						packageString = result[0];
					}else{
						result = matchingPossibleServiceFiles[i].getAbsolutePath().split(classesDirectory);
						packageString = result[1];
					}
					classFileDestination = FileUtils.addAnotherNodeToPath(servicesDirectory, packageString );
					String[] packageDestination = classFileDestination.split(serviceName+".class");
					mainPackage = packageDestination[0];
					serviceIncludeClassList.put(serviceName, 
							new String[]{mainPackage,matchingPossibleServiceFiles[i].getAbsolutePath()});
					break;
				}
			}
			
			//Matching other class files within the same package
			IPath servicePacakeDirLocation = new Path(classesDirectory);
			// Fix for the https://wso2.org/jira/browse/WSAS-752
			// Need the package always to be present
			if (packageString == null) {
				packageString="";
			}
			servicePacakeDirLocation = servicePacakeDirLocation.append(packageString);
			String servicePacakeDir[] = servicePacakeDirLocation.toOSString().split(serviceName+".class");
			File[] matchingPossibleRelatedFiles = ServiceImplFilterUtil.getMatchingFiles(servicePacakeDir[0],
                    null, ".class");
			
			//Adding other possible classes to the service include list
			for (int i = 0; i < matchingPossibleRelatedFiles.length; i++) {
				if (!(matchingPossibleRelatedFiles[i].getName().toString().equals(serviceName+".class"))) {
					serviceIncludeClassList.put(matchingPossibleRelatedFiles[i].getName(), 
							new String[]{mainPackage,matchingPossibleRelatedFiles[i].getAbsolutePath()});
				}
			}
			
			//By Looking at the class include list add all classes in to the service
			if(!serviceIncludeClassList.isEmpty()){
				Iterator it = serviceIncludeClassList.entrySet().iterator();
				while (it.hasNext()) {
					 Map.Entry pairs = (Map.Entry)it.next();
					 String[] value = (String[])pairs.getValue();
					 String PackageNewLocation = value[0].toString();
					 IPath classFileNewLocation = new Path(PackageNewLocation);
					 classFileNewLocation = classFileNewLocation.append(
							 (pairs.getKey().toString().endsWith(".class")?
									(pairs.getKey().toString()):
									(pairs.getKey().toString()+".class"))
							);
						File newClassFile = new File(classFileNewLocation.toOSString());
						if (!newClassFile.exists()){
							new File(PackageNewLocation).mkdirs();
							newClassFile.createNewFile();
							FileUtils.copy(new File(value[1].toString()), newClassFile);
						}
					
				}
			}
			
		
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

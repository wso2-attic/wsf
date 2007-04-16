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
package org.wso2.wsf.wtp.creation.core.command;

import java.io.File;
import java.util.Map;

import org.apache.axis2.description.AxisService;
import org.apache.axis2.wsdl.codegen.CodeGenConfiguration;
import org.apache.axis2.wsdl.codegen.CodeGenerationEngine;
import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.osgi.util.NLS;
import org.eclipse.wst.command.internal.env.core.common.StatusUtils;
import org.eclipse.wst.common.environment.IEnvironment;
import org.eclipse.wst.common.environment.IStatusHandler;
import org.eclipse.wst.common.frameworks.datamodel.AbstractDataModelOperation;
import org.wso2.wsf.wtp.consumption.core.utils.ContentCopyUtils;
import org.wso2.wsf.wtp.consumption.core.utils.FileUtils;
import org.wso2.wsf.wtp.consumption.core.utils.WSDL2JavaGenerator;
import org.wso2.wsf.wtp.creation.core.data.DataModel;
import org.wso2.wsf.wtp.creation.core.messages.WSASCreationUIMessages;

public class WSASWSDL2JavaCommand extends AbstractDataModelOperation {
	
	  private DataModel model;
		
	  public WSASWSDL2JavaCommand( DataModel model ){
	    this.model = model;  
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
		String matadataDir = FileUtils.addAnotherNodeToPath(
										workspaceDirectory,
										WSASCreationUIMessages.DIR_DOT_METADATA);
	    String matadataPluginsDir = FileUtils.addAnotherNodeToPath(
	    								matadataDir,
	    								WSASCreationUIMessages.DIR_DOT_PLUGINS);
	    String matadataWSASDir = FileUtils.addAnotherNodeToPath(
	    									matadataPluginsDir, 
	    									WSASCreationUIMessages.WSAS_PROJECT);
		String tempCodegenOutputLocation = FileUtils.addAnotherNodeToPath(
											matadataWSASDir, 
											WSASCreationUIMessages.CODEGEN_RESULTS);
		File tempCodegenLocationFile = new File(tempCodegenOutputLocation);
		if (tempCodegenLocationFile.exists())FileUtils.deleteDirectories(tempCodegenOutputLocation);
		FileUtils.createDirectorys(tempCodegenOutputLocation);
        WSDL2JavaGenerator generator = new WSDL2JavaGenerator(); 
        
        AxisService service;
	try {
		service = generator.getAxisService(model.getWsdlURI());
        Map optionsMap = generator.fillOptionMap(	
        	false,  //async always false
            false,	//sync always false
            true,   //is serverside true
            model.isServerXMLCheck(),
            model.isTestCaseCheck(),
            model.isGenerateAllCheck(),
            (model.getServiceName()!=null)?model.getServiceName():null,
            (model.getPortName()!=null)?model.getPortName():null,
            (model.getDatabindingType().toLowerCase()!=null)?model.getDatabindingType().toLowerCase():null,
            (model.getWsdlURI()!=null)?model.getWsdlURI():null,
            (model.getPackageText()!=null)?model.getPackageText():null,
            "java",
            tempCodegenOutputLocation,
            model.getNamespaseToPackageMapping(),
            model.isGenerateServerSideInterface()
          );
        
        CodeGenConfiguration codegenConfig = new CodeGenConfiguration(service, optionsMap);
        //set the baseURI
        codegenConfig.setBaseURI(generator.getBaseUri(model.getWsdlURI()));

        new CodeGenerationEngine(codegenConfig).generate();
        
		//Copy the existing codegen results to the current project
        ContentCopyUtils contentCopyUtils = new ContentCopyUtils();
	    status = contentCopyUtils.copyDirectoryRecursivelyIntoWorkspace(
	    							tempCodegenOutputLocation, 
	    							currentDynamicWebProjectDir, 
	    							monitor, 
	    							statusHandler);

        
	} catch (Exception e) {
		status = StatusUtils.errorStatus(NLS.bind(
											WSASCreationUIMessages.ERROR_CODEGEN_EXCEPTION,
											new String[]{e.getLocalizedMessage()}),
										e);
		environment.getStatusHandler().reportError(status); 
	}
		
		return status;
	}

}

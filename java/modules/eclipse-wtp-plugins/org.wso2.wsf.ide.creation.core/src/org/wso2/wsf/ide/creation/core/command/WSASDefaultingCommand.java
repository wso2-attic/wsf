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
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.wst.command.internal.env.core.common.StatusUtils;
import org.eclipse.wst.common.frameworks.datamodel.AbstractDataModelOperation;
import org.eclipse.wst.ws.internal.wsrt.IWebService;
import org.eclipse.wst.ws.internal.wsrt.WebServiceScenario;
import org.wso2.wsf.ide.consumption.core.utils.DefaultCodegenUtil;
import org.wso2.wsf.ide.core.context.ServiceContext;
import org.wso2.wsf.ide.core.context.WSASEmitterContext;
import org.wso2.wsf.ide.core.plugin.WebServiceWSASCorePlugin;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.WSASCoreUtils;
import org.wso2.wsf.ide.core.utils.FacetContainerUtils;
import org.wso2.wsf.ide.creation.core.data.DataModel;
import org.wso2.wsf.ide.creation.core.utils.CommonUtils;

public class WSASDefaultingCommand extends AbstractDataModelOperation 
{
	private DataModel model;
	private IWebService ws;
	private int scenario;
	IStatus status;

	public WSASDefaultingCommand( DataModel model ,IWebService ws, int scenario)
	{
		this.model = model;  
		this.ws=ws;
		this.scenario=scenario;
	}

	public IStatus execute( IProgressMonitor monitor, IAdaptable adaptable ){
		//Check wether the current dynamic Web Project is properly build to invoke web service
		Properties properties = new Properties();
		try {
			properties.load(new FileInputStream(WSASCoreUtils.tempRuntimeStatusFileLocation()));
			if (properties.containsKey(WSASCoreUIMessages.PROPERTY_KEY_STATUS)){
				 status = Status.OK_STATUS;
				 model.setServerStatus(true);
			}else{
				status = StatusUtils.errorStatus(WSASCoreUIMessages.ERROR_SERVER_IS_NOT_SET);
			}
		} catch (FileNotFoundException e) {
			status = StatusUtils.errorStatus(WSASCoreUIMessages.ERROR_INVALID_FILE_READ_WRITEL+
												WSASCoreUIMessages.ERROR_SERVER_IS_NOT_SET);
		} catch (IOException e) {
			status = StatusUtils.errorStatus(WSASCoreUIMessages.ERROR_INVALID_FILE_READ_WRITEL+
												WSASCoreUIMessages.ERROR_SERVER_IS_NOT_SET);
		}
		ServiceContext serviceContext = ServiceContext.getInstance();
		if (scenario == WebServiceScenario.TOPDOWN) {
			model.setWsdlURI(ws.getWebServiceInfo().getWsdlURL());
			model.setDatabindingType(WSASCoreUIMessages.DATA_BINDING_ADB);
			DefaultCodegenUtil defaultCodegenUtil = new DefaultCodegenUtil(model);
			defaultCodegenUtil.populateModelParamsFromWSDL();
			model.setServicesXML(true);
			model.setServerXMLCheck(true);
			serviceContext.setServiceName(model.getServiceName());
		}else if (scenario == WebServiceScenario.BOTTOMUP) {
			model.setServiceClass(ws.getWebServiceInfo().getImplURL());
			//set the service name inside BUServiceContext for used by client if invoke together
			serviceContext.setServiceName(
					CommonUtils.classNameFromQualifiedName(ws.getWebServiceInfo().getImplURL())
					);
			
			model.setGenerateServicesXML(true);
		}else{
			//never come here
		}
		serviceContext.addServiceToProjectMap(serviceContext.getServiceName(), model.getWebProjectName());

		// Fix for the Bugzilla Bug 175030
		// Axis2: WSDL representing Web service not passed to Axis2 client
		// After setting the initial wsdlURL return from the framework to the data model,
		// replace it with the deployed wsdlURL
		String deployedWSDLURL = FacetContainerUtils.getDeployedWSDLURL(
					model.getWebProjectName(),
					serviceContext.getServiceName());
		ws.getWebServiceInfo().setWsdlURL(deployedWSDLURL);
		
		WSASEmitterContext context = WebServiceWSASCorePlugin.getDefault().getWSASEmitterContext();
		
		System.setProperty("javax.net.ssl.trustStore", context.getWSASRuntimeLocation()+File.separator+"conf"+File.separator+"wso2wsas.jks");
        System.setProperty("javax.net.ssl.trustStorePassword", "wso2wsas");
        System.setProperty("javax.net.ssl.trustStoreType","wso2wsas");
		
		
		return status;      	
	}

	public DataModel getWebServiceDataModel()
	{
		return model;
	}
}

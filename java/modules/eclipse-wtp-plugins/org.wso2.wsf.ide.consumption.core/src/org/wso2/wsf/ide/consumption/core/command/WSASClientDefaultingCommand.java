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
package org.wso2.wsf.ide.consumption.core.command;

import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.wst.common.frameworks.datamodel.AbstractDataModelOperation;
import org.eclipse.wst.ws.internal.wsrt.IWebServiceClient;
import org.wso2.wsf.ide.consumption.core.data.DataModel;
import org.wso2.wsf.ide.consumption.core.utils.DefaultCodegenUtil;
import org.wso2.wsf.ide.core.context.ServiceContext;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.FacetContainerUtils;

public class WSASClientDefaultingCommand extends AbstractDataModelOperation {
	
	DataModel model;
	private IWebServiceClient ws;
	IStatus status;
	
	public WSASClientDefaultingCommand(DataModel model, IWebServiceClient ws){
		this.model=model;
		this.ws=ws;
	}

	public IStatus execute(IProgressMonitor monitor, IAdaptable info)
			throws ExecutionException {
		//Default Settings for the Codegeneration
		String deployedWSDLURL = FacetContainerUtils.getDeployedWSDLURL(
	  								model.getWebProjectName().split("Client")[0],
	  								ServiceContext.getInstance().getServiceName());
		String wsFrameworkWSDLURL = ws.getWebServiceClientInfo().getWsdlURL();
 
		model.setWsdlURI(
				((wsFrameworkWSDLURL!=null) || (deployedWSDLURL!=wsFrameworkWSDLURL))?
						wsFrameworkWSDLURL:
							deployedWSDLURL
		);
		
		// WSE with Client alone. 
		ws.getWebServiceClientInfo().setWsdlURL(deployedWSDLURL);
		
		model.setDatabindingType(WSASCoreUIMessages.DATA_BINDING_ADB);
		model.setASync(false);
		model.setSync(false);
		
		DefaultCodegenUtil defaultCodegenUtil = new DefaultCodegenUtil(model);
		defaultCodegenUtil.populateModelParamsFromWSDL();
		
		status = Status.OK_STATUS;
		return status;
	}
	
	public DataModel getWebServiceDataModel(){
		return model;
	}

}

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
package org.wso2.wsf.ide.consumption.core.utils;

import java.lang.reflect.Method;
import java.util.List;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.osgi.util.NLS;
import org.eclipse.wst.command.internal.env.core.common.StatusUtils;
import org.wso2.wsf.ide.consumption.core.data.Model;
import org.wso2.wsf.ide.consumption.core.messages.WSASConsumptionUIMessages;
import org.wso2.wsf.ide.core.utils.ClassLoadingUtil;

public class DefaultCodegenUtil {
	
	private WSDLPropertyReader reader;
	private Model model;
	private List serviceQNameList = null;
	IStatus status;
	
	public DefaultCodegenUtil(org.wso2.wsf.ide.consumption.core.data.DataModel model){
		this.model=model;
	}
	
	public DefaultCodegenUtil(org.wso2.wsf.ide.creation.core.data.DataModel model){
		this.model=model;
	}

	/**
	 * populate the model for the default scenario from the wsdl url
	 */
	public void populateModelParamsFromWSDL() {
		status = Status.OK_STATUS;
		if (reader == null)
			reader = new WSDLPropertyReader();
		try {
			String lname = model.getWsdlURI();
			if (!"".equals(lname.trim())) {

				reader.readWSDL(model.getWebProjectName(), lname);

				this.serviceQNameList = reader.getServiceList();
				if (!serviceQNameList.isEmpty()) {
					// add the local part of the
					Object serviceQnameInstance = serviceQNameList.get(0);
					Class QNameClass = ClassLoadingUtil
							.loadClassFromAntClassLoader("javax.xml.namespace.QName");
					Method GetLocalPartMethod  = QNameClass.getMethod("getLocalPart", null);
					Object resultLocalPart = GetLocalPartMethod.invoke(serviceQnameInstance, null);
					model.setServiceName(resultLocalPart.toString());
					// load the ports
					 loadPortNames();
				} 
				populatePackageName();
				//populate the namespacess
				//loadNamespaces(reader.getDefinitionNamespaceMap());
			}
		} catch (Exception e) {
			status = StatusUtils.errorStatus(NLS.bind(
					WSASConsumptionUIMessages.ERROR_INVALID_WSDL_FILE_READ_WRITEL,
					new String[]{e.getLocalizedMessage()}), e);
		}
	}
	
	private void loadPortNames() {
			java.util.List ports = reader.getPortNameList(serviceQNameList.get(0));
					// add the local part of the
					model.setPortName(ports.get(0).toString());
	}
	
	private void populatePackageName() {
		model.setPackageText(reader.packageFromTargetNamespace());
	}

}

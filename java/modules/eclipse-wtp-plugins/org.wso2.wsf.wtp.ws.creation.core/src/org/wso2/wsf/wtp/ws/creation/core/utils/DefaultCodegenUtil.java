/*******************************************************************************
 * Copyright (c) 2007 WSO2 Inc. and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 * WSO2 Inc. - initial API and implementation
 * yyyymmdd bug      Email and other contact information
 * -------- -------- -----------------------------------------------------------
 * 20070206   168762 sandakith@wso2.com - Lahiru Sandakith, Initial code to introduse the Axis2 
 * 										  runtime to the framework for 168762
 *******************************************************************************/
package org.wso2.wsf.wtp.ws.creation.core.utils;

import java.util.List;

import javax.xml.namespace.QName;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.osgi.util.NLS;
import org.eclipse.wst.command.internal.env.core.common.StatusUtils;
import org.wso2.wsf.wtp.ws.creation.core.data.Model;
import org.wso2.wsf.wtp.ws.creation.core.messages.WSASCreationUIMessages;

public class DefaultCodegenUtil {
	
	private WSDLPropertyReader reader;
	private Model model;
	private List serviceQNameList = null;
	IStatus status;
	
	public DefaultCodegenUtil(org.wso2.wsf.wtp.ws.consumption.core.data.DataModel model){
		this.model=model;
	}
	
	public DefaultCodegenUtil(org.wso2.wsf.wtp.ws.creation.core.core.data.DataModel model){
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

				reader.readWSDL(lname);

				this.serviceQNameList = reader.getServiceList();
				if (!serviceQNameList.isEmpty()) {
						// add the local part of the
						model.setServiceName((((QName) serviceQNameList.get(0))
								.getLocalPart()));
						
					// load the ports
					 loadPortNames();

				} 
				
				populatePackageName();

				//populate the namespacess
				//loadNamespaces(reader.getDefinitionNamespaceMap());
			}
		} catch (Exception e) {
			status = StatusUtils.errorStatus(NLS.bind(
					WSASCreationUIMessages.ERROR_INVALID_WSDL_FILE_READ_WRITEL,
					new String[]{e.getLocalizedMessage()}), e);
		}
	}
	
	
	private void loadPortNames() {
			java.util.List ports = reader.getPortNameList((QName) serviceQNameList
					.get(0));
					// add the local part of the
					model.setPortName(ports.get(0).toString());
	}
	
	private void populatePackageName() {
		model.setPackageText(reader.packageFromTargetNamespace());
	}

}

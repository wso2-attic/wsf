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
import org.wso2.wsf.ide.consumption.core.data.DataModel;

public class WSASWebservicesServerCommand extends
AbstractDataModelOperation {

	String project;
	DataModel model;
	public WSASWebservicesServerCommand(DataModel model, String project){
		this.model=model;
		this.project = project;
	}

	public IStatus execute(IProgressMonitor monitor, IAdaptable info)
	throws ExecutionException {
		//Copy the WSAS libs in to this client project
		//TODO No Need to copy the WSAS libs after the introduction of the facet 
		//     Check wether the facet is present and if not pop up a warning
		IStatus status = Status.OK_STATUS;
		model.setWebProjectName(project);
		return status;
	}

}

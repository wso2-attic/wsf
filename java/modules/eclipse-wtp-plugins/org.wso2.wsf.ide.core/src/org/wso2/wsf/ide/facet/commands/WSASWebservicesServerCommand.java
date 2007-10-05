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
package org.wso2.wsf.ide.facet.commands;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.wst.common.frameworks.datamodel.AbstractDataModelOperation;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.WSASCoreUtils;
import org.wso2.wsf.ide.core.utils.FacetContainerUtils;
import org.wso2.wsf.ide.core.utils.FileUtils;
import org.wso2.wsf.ide.facet.utils.WSASWebappUtils;
import org.wso2.wsf.ide.facet.utils.ContentCopyUtils;

public class WSASWebservicesServerCommand extends
AbstractDataModelOperation {

	String project;
	public WSASWebservicesServerCommand(String project){
		this.project = project;
	}

	public IStatus execute(IProgressMonitor monitor, IAdaptable info)
	throws ExecutionException {
		return Status.OK_STATUS;
	}
	
	public IStatus exexuteOverride(IProgressMonitor monitor)  {
		//Copy the wsas libs in to this client project
		IStatus status =null;
		String runtimeLocation = null;
		ContentCopyUtils contentCopyUtils = new ContentCopyUtils();
		try {
			runtimeLocation = WSASWebappUtils.copyWSASWar(
					monitor,
					WSASCoreUIMessages.PROPERTY_KEY_PATH,
					project);
		} catch (FileNotFoundException e) {
			return handleExceptionStatus(e);
		} catch (IOException e) {
			return handleExceptionStatus(e);
		} catch (Exception e) {
			return handleExceptionStatus(e);
		}
		
		
		//Copy all the WSAS libs to the DWP
		status = contentCopyUtils.copyDirectoryRecursivelyIntoWorkspace(
				runtimeLocation, 
				FacetContainerUtils.pathToWebProjectContainer(project), 
				monitor 
		);
		
		status = Status.OK_STATUS;
		//clean up tempory files
		File tempFacetDirectory = new File(runtimeLocation);
		if (tempFacetDirectory.exists()) {
			FileUtils.deleteDir(tempFacetDirectory);
		}
		return status;
	}
	
	private void cleanupIfFacetStatusFailed(String runtimeLocation){
		File tempFacetDirectory = new File(runtimeLocation);
		if (tempFacetDirectory.exists()) {
			FileUtils.deleteDir(tempFacetDirectory);
		}
	}
	
	private IStatus handleExceptionStatus(Exception e){
		IStatus status = null;
		status = new Status(1,project,1,WSASCoreUIMessages.ERROR_SERVER_IS_NOT_SET,e);
		cleanupIfFacetStatusFailed(WSASCoreUtils.tempWSASDirectory());
		return status;
	}
}

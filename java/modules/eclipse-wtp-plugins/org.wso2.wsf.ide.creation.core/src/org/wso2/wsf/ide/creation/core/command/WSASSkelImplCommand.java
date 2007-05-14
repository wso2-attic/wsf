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

import java.net.MalformedURLException;

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
import org.eclipse.wst.ws.internal.wsrt.WebServiceInfo;
import org.wso2.wsf.ide.core.utils.FileUtils;
import org.wso2.wsf.ide.creation.core.data.DataModel;
import org.wso2.wsf.ide.creation.core.messages.WSASCreationUIMessages;
import org.wso2.wsf.ide.creation.core.utils.CommonUtils;

public class WSASSkelImplCommand extends AbstractDataModelOperation {

	private WebServiceInfo webServiceInfo;
	private DataModel model;

	public WSASSkelImplCommand(WebServiceInfo webServiceInfo, DataModel model){
		this.webServiceInfo = webServiceInfo;
		this.model=model;
	}

	public IStatus execute(IProgressMonitor monitor, IAdaptable info) throws ExecutionException {
		
		IStatus status = Status.OK_STATUS;
		IEnvironment environment = getEnvironment();

		String workspaceDirectory = ResourcesPlugin.getWorkspace().getRoot().
													getLocation().toOSString();
		String currentDynamicWebProjectDir = FileUtils.addAnotherNodeToPath(
													   workspaceDirectory, 
													   model.getWebProjectName());
		String projectSrcDir =  FileUtils.addAnotherNodeToPath(
											currentDynamicWebProjectDir, 
											WSASCreationUIMessages.DIR_SRC);

		String packagePath = CommonUtils.packgeName2PathName(model.getPackageText());
		String packageDir = FileUtils.addAnotherNodeToPath(projectSrcDir, packagePath);
		String serviceSkeletonImpl = FileUtils.addAnotherNodeToPath(packageDir, model.
																	getServiceName());

		String serviceSkeletonImplURL =  serviceSkeletonImpl + 
										 WSASCreationUIMessages.SKELETON_SUFFIX;
		IPath serviceSkeletonImplURLPath = new Path(serviceSkeletonImplURL); 
		try {
			//webServiceInfo.setImplURL(serviceSkeletonImplURLPath.toFile().toURL().toString());
			//String[] implURLArray = {serviceSkeletonImplURL};
			//webServiceInfo.setImplURLs( implURLArray);
			
			String serviceSkeletonImplURLString = 
				serviceSkeletonImplURLPath.toFile().toURL().toString();

			webServiceInfo.setImplURL(serviceSkeletonImplURLString);
			String[] implURLArray = {serviceSkeletonImplURLString};
			webServiceInfo.setImplURLs( implURLArray);

			
		} catch (MalformedURLException e) {
			status = StatusUtils.errorStatus(
					NLS.bind(WSASCreationUIMessages.ERROR_INVALID_FILE_READ_WRITEL,
							new String[]{e.getLocalizedMessage()}), e);
			environment.getStatusHandler().reportError(status); 
		}

		return status;
		
	}
	
}

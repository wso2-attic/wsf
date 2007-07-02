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
package org.wso2.wsf.ide.facet.deligate;

import java.io.File;

import org.eclipse.core.resources.IProject;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.wst.common.project.facet.core.IDelegate;
import org.eclipse.wst.common.project.facet.core.IProjectFacetVersion;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.FacetContainerUtils;
import org.wso2.wsf.ide.core.utils.FileUtils;

public class WSASCoreFacetUnInstallDelegate implements IDelegate {
	
	private IStatus status;
	
	public void execute(IProject project, IProjectFacetVersion arg1, Object arg2,
			IProgressMonitor monitor) throws CoreException {
		monitor.beginTask(WSASCoreUIMessages.PROGRESS_UNINSTALL_WSAS_RUNTIME, 2 );
			File webContainerDir = new File(FacetContainerUtils.pathToWebProjectContainer(
																project.toString()));
			if (webContainerDir.isDirectory()) {
				FileUtils.deleteDirectories(webContainerDir);
			}

			// TODO rollback the dynamic web project to the previous state.
			if(!webContainerDir.exists()){
				FileUtils.createDirectorys(webContainerDir.getPath());
			}
			String web_infDir = FileUtils.addAnotherNodeToPath(webContainerDir.getPath(), "WEB-INF");
			String meta_infDir = FileUtils.addAnotherNodeToPath(webContainerDir.getPath(), "META-INF");
			
			if(!(new File(web_infDir).exists())){
				FileUtils.createDirectorys(web_infDir);
			}
			if(!(new File(meta_infDir).exists())){
				FileUtils.createDirectorys(meta_infDir);
			}
			
	        status = Status.OK_STATUS;
			monitor.worked( 1 );
	}
	
	public IStatus getStatus(){
		return status;
	}
}

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

import org.eclipse.core.resources.IProject;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.wst.common.project.facet.core.IDelegate;
import org.eclipse.wst.common.project.facet.core.IProjectFacetVersion;
import org.wso2.wsf.ide.core.context.ServiceContext;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.RuntimePropertyUtils;
import org.wso2.wsf.ide.facet.commands.WSASWebservicesServerCommand;

public class WSASCoreFacetInstallDelegate implements IDelegate {
	
	private IStatus status;
	
	public void execute(IProject project, IProjectFacetVersion arg1, Object arg2,
			IProgressMonitor monitor) throws CoreException {
			monitor.beginTask(WSASCoreUIMessages.PROGRESS_INSTALL_WSAS_RUNTIME, 2 );
			ServiceContext context = ServiceContext.getInstance();
			context.setProjectName(project.getName());
	        	WSASWebservicesServerCommand command = new WSASWebservicesServerCommand(
	        													project.toString()
	        												); 
	        	status = command.exexuteOverride(monitor);
	        	if (status.getCode() == Status.OK_STATUS.getCode() ){
	        		RuntimePropertyUtils.writeServerStausToPropertiesFile(
	        								WSASCoreUIMessages.SERVER_STATUS_PASS);
	        	}else{
	        		RuntimePropertyUtils.writeServerStausToPropertiesFile(
							WSASCoreUIMessages.SERVER_STATUS_FAIL);
	        		throw new CoreException(status);
	        	}
	            monitor.worked( 1 );
	            monitor.done();
	}

}

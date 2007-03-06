package org.wso2.wsas.wtp.facet.deligate;

import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.wst.common.project.facet.core.IDelegate;
import org.eclipse.wst.common.project.facet.core.IProjectFacetVersion;
import org.wso2.wsas.wtp.facet.commands.WSASWebservicesServerCommand;
import org.wso2.wsas.wtp.facet.model.WSASCoreFacetInstallConfig;
import org.wso2.wsf.wtp.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.wtp.core.utils.RuntimePropertyUtils;

public class WSASCoreFacetInstallDelegate implements IDelegate {
	
	private IStatus status;
	
	public void execute(IProject project, IProjectFacetVersion arg1, Object config,
			IProgressMonitor monitor) throws CoreException {
			monitor.beginTask(WSASCoreUIMessages.PROGRESS_INSTALL_WSAS_RUNTIME, 2 );
	        try {
	            final WSASCoreFacetInstallConfig cfg = (WSASCoreFacetInstallConfig) config;
	        	WSASWebservicesServerCommand command = new WSASWebservicesServerCommand(
	        													project.toString()
	        												); 
	        	status = command.exexuteOverrride(monitor);
	        	if (status.getCode() == Status.OK_STATUS.getCode() ){
	        		RuntimePropertyUtils.writeServerStausToPropertiesFile(
	        								WSASCoreUIMessages.SERVER_STATUS_PASS);
	        	}else{
	        		RuntimePropertyUtils.writeServerStausToPropertiesFile(
							WSASCoreUIMessages.SERVER_STATUS_FAIL);
	        	}
	            monitor.worked( 1 );
	            
	        } catch (ExecutionException e) {
				e.printStackTrace();
			}
	        finally {
	            monitor.done();
	        }
	}

}

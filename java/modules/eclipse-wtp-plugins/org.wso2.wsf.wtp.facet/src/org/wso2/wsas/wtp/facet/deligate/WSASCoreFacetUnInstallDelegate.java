package org.wso2.wsas.wtp.facet.deligate;

import java.io.File;

import org.eclipse.core.resources.IProject;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.wst.common.project.facet.core.IDelegate;
import org.eclipse.wst.common.project.facet.core.IProjectFacetVersion;
import org.wso2.wsas.wtp.facet.utils.FacetContainerUtils;
import org.wso2.wsf.wtp.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.wtp.core.utils.FileUtils;

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
	        status = Status.OK_STATUS;
			monitor.worked( 1 );
	}
	
	public IStatus getStatus(){
		return status;
	}
}

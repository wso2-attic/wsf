package org.wso2.wsas.wtp.facet.commands;

import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.wst.common.frameworks.datamodel.AbstractDataModelOperation;
import org.wso2.wsas.wtp.facet.utils.WSASRuntimeUtils;
import org.wso2.wsas.wtp.facet.utils.ContentCopyUtils;
import org.wso2.wsas.wtp.facet.utils.FacetContainerUtils;
import org.wso2.wsf.wtp.core.plugin.messages.WSASCoreUIMessages;

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
	
	public IStatus exexuteOverrride(IProgressMonitor monitor) throws ExecutionException {
		//Copy the wsas libs in to this client project
		IStatus status = Status.OK_STATUS;
		
		ContentCopyUtils contentCopyUtils = new ContentCopyUtils();
				String runtimeLocation = WSASRuntimeUtils.copyWSASWar(
															monitor,
															WSASCoreUIMessages.PROPERTY_KEY_PATH);
				status = contentCopyUtils.copyDirectoryRecursivelyIntoWorkspace(
						runtimeLocation, 
						FacetContainerUtils.pathToWebProjectContainer(project), 
						monitor 
					);
		return status;
	}
}

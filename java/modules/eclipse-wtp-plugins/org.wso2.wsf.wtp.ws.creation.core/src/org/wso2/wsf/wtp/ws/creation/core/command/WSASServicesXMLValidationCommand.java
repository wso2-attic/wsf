package org.wso2.wsf.wtp.ws.creation.core.command;

import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.wst.common.frameworks.datamodel.AbstractDataModelOperation;

public class WSASServicesXMLValidationCommand extends
		AbstractDataModelOperation {

	public IStatus execute(IProgressMonitor monitor, IAdaptable info)
			throws ExecutionException {
		//Here write the code to validate the services.xml
	    IStatus status = Status.OK_STATUS; 
	    return status;
	}
}

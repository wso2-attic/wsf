package org.wso2.wsf.wtp.ws.creation.core.command;


import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.wst.command.internal.env.core.common.StatusUtils;
import org.eclipse.wst.common.frameworks.datamodel.AbstractDataModelOperation;
import org.wso2.wsf.wtp.ws.creation.core.data.DataModel;
import org.wso2.wsf.wtp.ws.creation.core.messages.WSASCreationUIMessages;


public class WSASBUCommand extends AbstractDataModelOperation 
{
  private DataModel model;
  
  public WSASBUCommand( DataModel model )
  {
    this.model = model;  
  }
  
  public IStatus execute( IProgressMonitor monitor, IAdaptable adaptable ) 
  {
    IStatus status ;  
    // Check for the nessesary data are available for the scenario to begin
    if (model.getServiceClass() == null){
		status = StatusUtils.errorStatus(WSASCreationUIMessages.ERROR_INVALID_SERVICE_CREATION);
    }else {
		status = Status.OK_STATUS; // Ok to proceed 
	}
    return status;      	
  }
}

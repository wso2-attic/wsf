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


import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.wst.command.internal.env.core.common.StatusUtils;
import org.eclipse.wst.common.frameworks.datamodel.AbstractDataModelOperation;
import org.wso2.wsf.ide.creation.core.data.DataModel;
import org.wso2.wsf.ide.creation.core.messages.WSASCreationUIMessages;


public class WSASTDCommand extends AbstractDataModelOperation 
{
  private DataModel model;
  
  public WSASTDCommand( DataModel model )
  {
    this.model = model;  
  }
  
  public IStatus execute( IProgressMonitor monitor, IAdaptable adaptable ) 
  {
    IStatus status = Status.OK_STATUS;  
    // Check for the nessesary data are available for the scenario to begin
    if (model.getWsdlURI() == null){
		status = StatusUtils.errorStatus(WSASCreationUIMessages.ERROR_INVALID_SERVICE_CREATION);
    }else {
		status = Status.OK_STATUS; // Ok to proceed 
	}
    return status;      	
  }
}

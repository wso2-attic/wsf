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
package org.wso2.wsf.wtp.server.ui;

import java.lang.reflect.InvocationTargetException;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.jface.action.IAction;
import org.eclipse.swt.widgets.Control;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.ui.IWorkbenchWindow;
import org.eclipse.ui.IWorkbenchWindowActionDelegate;
import org.eclipse.ui.IWorkbenchWindowPulldownDelegate;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.actions.ActionDelegate;
import org.wso2.wsf.wtp.server.command.WSASStartCommand;
import org.wso2.wsf.wtp.server.command.WTPInternalBrowserCommand;

public class WSASStartMenuDelegate
	extends ActionDelegate
	implements IWorkbenchWindowPulldownDelegate {

    MessageBox box = new MessageBox(PlatformUI.getWorkbench().getActiveWorkbenchWindow().getShell());
    IStatus status;
    
	/**
	 * @see ActionDelegate#run(IAction)
	 */
	public void run(IAction action) {
		
		try {
			status = WSASStartCommand.run();
			if(status.getCode() == 11){
				box.setMessage(status.getMessage());box.open();
			}else{
				box.setMessage("WSO2 Web Services Server Started Successfully !! ");box.open();
			}
		} catch (InvocationTargetException e) {
			status = new Status( IStatus.ERROR,"id",1,e.getMessage(),null );
			box.setMessage("WSAS Failed to Start \n"+"Reason"+e.getMessage());box.open();
		}
		
		//Pop up the browser with the url
		WTPInternalBrowserCommand.popUpInrernalBrouwser("http://localhost:9762/");

	}

	/**
	 * @see IWorkbenchWindowPulldownDelegate#getMenu(Control)
	 */
	public Menu getMenu(Control parent) {
		return null;
	}

	/**
	 * @see IWorkbenchWindowActionDelegate#dispose()
	 */
	public void dispose() {
	}

	/**
	 * @see IWorkbenchWindowActionDelegate#init(IWorkbenchWindow)
	 */
	public void init(IWorkbenchWindow window) {
	}
	
}


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
package org.wso2.wsf.ide.wtp.ext.server.ui;

import java.lang.reflect.InvocationTargetException;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.jface.action.IAction;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.ui.IWorkbenchWindow;
import org.eclipse.ui.IWorkbenchWindowActionDelegate;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.actions.ActionDelegate;
import org.wso2.wsf.ide.wtp.ext.server.command.WSASStopCommand;
import org.wso2.wsf.ide.wtp.ext.server.command.WTPInternalBrowserCommand;
import org.wso2.wsf.ide.wtp.ext.server.constant.WSASMessageConstant;

public class WSASStopDelegate
	extends ActionDelegate
	implements IWorkbenchWindowActionDelegate {

	MessageBox box = new MessageBox(PlatformUI.getWorkbench().getActiveWorkbenchWindow().getShell());
	IStatus status;
	Shell shell = null;
	
	/**
	 * @see ActionDelegate#run(IAction)
	 */
	public void run(IAction action) {
		try {
			status = WSASStopCommand.run();
			if(status.getCode() == 12){
				box.setMessage(status.getMessage());box.open();
			}else{
				box.setMessage(WSASMessageConstant.INFO_WSAS_STOP_SUCCESS);box.open();
			}
			System.setProperty("WSASStartStatus", "wait");
			WTPInternalBrowserCommand.closeUpInrernalBrouwser();
			if (shell == null) {
				box.setMessage(WSASMessageConstant.INFO_LINUX_SHELL_INIT_FAIL + 
						WSASMessageConstant.INFO_WSAS_STOP_FAIL );box.open();
			}else{
				shell.getParent().redraw();
			}
		} catch (InvocationTargetException e) {
			status = new Status( IStatus.ERROR,"id",1,e.getMessage(),null );
			box.setMessage(WSASMessageConstant.INFO_WSAS_STOP_FAIL);box.open();
		}

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
		shell = window.getShell();
	}

}


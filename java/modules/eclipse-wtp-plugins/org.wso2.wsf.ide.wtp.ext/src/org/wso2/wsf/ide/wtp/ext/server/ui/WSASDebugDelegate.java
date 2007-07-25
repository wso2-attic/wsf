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
import org.eclipse.swt.widgets.Control;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.ui.IWorkbenchWindow;
import org.eclipse.ui.IWorkbenchWindowActionDelegate;
import org.eclipse.ui.IWorkbenchWindowPulldownDelegate;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.actions.ActionDelegate;
import org.wso2.wsf.ide.wtp.ext.server.bean.WSASConfigurationBean;
import org.wso2.wsf.ide.wtp.ext.server.command.WSASDebugCommand;
import org.wso2.wsf.ide.wtp.ext.server.command.WTPInternalBrowserCommand;
import org.wso2.wsf.ide.wtp.ext.server.constant.WSASMessageConstant;
import org.wso2.wsf.ide.wtp.ext.server.monitor.WSASUpMonitorThread;
import org.wso2.wsf.ide.wtp.ext.server.util.WSASUtils;

public class WSASDebugDelegate
	extends ActionDelegate
	implements IWorkbenchWindowPulldownDelegate {
	
	Shell shell = null;
	
    MessageBox box = new MessageBox(PlatformUI.getWorkbench().getActiveWorkbenchWindow().getShell());
    private IStatus status;
    private final long interval = 1000;
	
	/**
	 * @see ActionDelegate#run(IAction)
	 */
	public void run(IAction action) {
		//Init the Configuration Bean
		WSASConfigurationBean.Init();
		if (!WSASConfigurationBean.isWsasCorrectPathSet()) {
			box.setMessage(WSASMessageConstant.WARNING_WSAS_PATH_NOT_SET);box.open();
		}else{
			try {
				status = WSASDebugCommand.run();
				if(status.getCode() == 11){
					box.setMessage(status.getMessage());box.open();
				}else{
					WSASUpMonitorThread wsasMonitor = new WSASUpMonitorThread();
					wsasMonitor.start();
				}
			} catch (InvocationTargetException e) {
				status = new Status( IStatus.ERROR,"id",1,e.getMessage(),null );
				box.setMessage(WSASMessageConstant.INFO_WSAS_START_FAIL+"Reason"+e.getMessage());box.open();
			}
			System.setProperty("WSASStartStatus", "done");
			while(!WSASConfigurationBean.isWsasStartStatus()){
				try {
					Thread.sleep(interval);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			//Kill the WSAS Monitor Thread
			WSASUpMonitorThread.setAlive(false);
			if (!WSASConfigurationBean.isWSASAlreadyRunning()) {
				box.setMessage(WSASMessageConstant.INFO_WSAS_START_SUCCESS);box.open();
				//Pop up the browser with the url
				WTPInternalBrowserCommand.popUpInrernalBrouwser(WSASUtils.getWSASHTTPSAddtess());
				shell.getParent().redraw();
			}
		}
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
		shell = window.getShell();
	}
	

}


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
import org.wso2.wsf.wtp.server.bean.WSASConfigurationBean;
import org.wso2.wsf.wtp.server.command.WSASStartCommand;
import org.wso2.wsf.wtp.server.command.WTPInternalBrowserCommand;
import org.wso2.wsf.wtp.server.constant.WSASMessageConstant;
import org.wso2.wsf.wtp.server.monitor.WSASUpMonitorThread;
import org.wso2.wsf.wtp.server.util.WSASUtils;

public class WSASStartMenuDelegate
	extends ActionDelegate
	implements IWorkbenchWindowPulldownDelegate {

    MessageBox box = new MessageBox(PlatformUI.getWorkbench().getActiveWorkbenchWindow().getShell());
    private IStatus status;
    private final long interval = 1000;
    
	/**
	 * @see ActionDelegate#run(IAction)
	 */
	public void run(IAction action) {
		
		try {
			status = WSASStartCommand.run();
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
	}
	
}


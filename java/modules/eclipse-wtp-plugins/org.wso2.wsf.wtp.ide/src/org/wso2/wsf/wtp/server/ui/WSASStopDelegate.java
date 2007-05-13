package org.wso2.wsf.wtp.server.ui;

import org.eclipse.jface.action.IAction;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.ui.IWorkbenchWindow;
import org.eclipse.ui.IWorkbenchWindowActionDelegate;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.actions.ActionDelegate;

public class WSASStopDelegate
	extends ActionDelegate
	implements IWorkbenchWindowActionDelegate {

	/**
	 * @see ActionDelegate#run(IAction)
	 */
	public void run(IAction action) {
		
		MessageBox box = new MessageBox(PlatformUI.getWorkbench().getActiveWorkbenchWindow().getShell());
		box.setMessage("WSAS Succesfully Stoped !! ");
		box.open();
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


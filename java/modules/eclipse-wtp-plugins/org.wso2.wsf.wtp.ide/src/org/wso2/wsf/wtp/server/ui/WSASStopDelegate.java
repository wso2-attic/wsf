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
import java.lang.reflect.Method;

import org.eclipse.jface.action.IAction;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.ui.IWorkbenchWindow;
import org.eclipse.ui.IWorkbenchWindowActionDelegate;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.actions.ActionDelegate;
import org.wso2.wsf.wtp.server.bean.WSASConfigurationBean;

public class WSASStopDelegate
	extends ActionDelegate
	implements IWorkbenchWindowActionDelegate {

	MessageBox box = new MessageBox(PlatformUI.getWorkbench().getActiveWorkbenchWindow().getShell());
	
	/**
	 * @see ActionDelegate#run(IAction)
	 */
	public void run(IAction action) {
		
        if (WSASConfigurationBean.isWsasStartStatus()) {
            Class wsasMainClazz = WSASStartDelegate.getWSASMainClass();
           try {
               Method[] methods = wsasMainClazz.getMethods();
               Method shutdownMethod = null;
               for (int i = 0; i < methods.length; i++) {
                   if (methods[i].getName().equals("main")) {
                       shutdownMethod = methods[i];
                       break;
                   }
               }

               shutdownMethod.invoke(null, new Object[]{new String[]{"STOP"}});

               //set wsas start status to shutdown
               WSASConfigurationBean.setWsasStartStatus(false);
               box.setMessage("WSAS Succesfully Stoped !! ");box.open();
           }  catch (IllegalAccessException e1) {
               e1.printStackTrace();
               box.setMessage("WSAS Stopping Action Failed!! ");box.open();
           } catch (InvocationTargetException e1) {
               e1.printStackTrace();
               box.setMessage("WSAS Succesfully Stoped !! ");box.open();
           }
        }else{
            WSASConfigurationBean.setWsasStartStatus(false);
            box.setMessage("WSAS Not Started !! ");box.open();
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
	}

}


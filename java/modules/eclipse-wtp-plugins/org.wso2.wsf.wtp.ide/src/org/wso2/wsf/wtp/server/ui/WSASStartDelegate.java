package org.wso2.wsf.wtp.server.ui;

import java.io.File;
import java.lang.reflect.AccessibleObject;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import org.eclipse.jface.action.IAction;
import org.eclipse.swt.widgets.Control;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.ui.IWorkbenchWindow;
import org.eclipse.ui.IWorkbenchWindowPulldownDelegate;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.actions.ActionDelegate;
import org.wso2.wsf.wtp.server.bean.WSASConfigurationBean;
import org.wso2.wsf.wtp.server.constant.WSASConfigurationConstant;
import org.wso2.wsf.wtp.server.util.WSASClassLoadingUtil;
import org.wso2.wsf.wtp.server.util.WSASPropertiesUtil;

public class WSASStartDelegate
	extends ActionDelegate
	implements IWorkbenchWindowPulldownDelegate {

    private static Class wsasMainClazz;
	
	/**
	 * @see ActionDelegate#run(IAction)
	 */
	public void run(IAction action) {
		
        //Set WSAS system properties
        WSASPropertiesUtil.setWSASProperties();
        WSASClassLoadingUtil.init(WSASConfigurationBean.getWsasInstallationPath());
        wsasMainClazz = WSASClassLoadingUtil.loadClassFromClassLoader(WSASConfigurationConstant.WSAS_MAIN_CLASS);
        try {
            Method[] methods = wsasMainClazz.getMethods();
            Method mainMethod = null;
            for (int i = 0; i < methods.length; i++) {
                if (methods[i].getName().equals("main")) {
                    mainMethod = methods[i];
                    break;
                }
            }
            Class serviceConfic = WSASClassLoadingUtil.loadClassFromClassLoader(WSASConfigurationConstant.WSAS_SERVER_CONFIG_CLASS);
            Field[] fields = serviceConfic.getDeclaredFields();
            AccessibleObject.setAccessible(fields, true);

            for (int i = 0; i < fields.length; i++) {
                Field f = fields[i];
                if (f.getName().equals("configurationXMLLocation")) {
                    f.set(serviceConfic, WSASConfigurationBean.getWsasInstallationPath() + File.separator + "conf" + File
                            .separator + "server.xml");
                    break;
                }
            }

            mainMethod.invoke(null, new Object[]{new String[]{"RUN"}});

            //set wsas start status to pass
            WSASConfigurationBean.setWsasStartStatus(true);
            
        } catch (IllegalAccessException e1) {
            e1.printStackTrace();
            //PopupMessageUtil.popupInformationMessageBox(WSASMessageConstant.INFO_WSAS_START_FAIL);
        } catch (InvocationTargetException e1) {
            e1.printStackTrace();
            //PopupMessageUtil.popupInformationMessageBox(WSASMessageConstant.INFO_WSAS_START_FAIL);
        } finally {
            WSASClassLoadingUtil.cleanupAntClassLoader();
        }
		
		MessageBox box = new MessageBox(PlatformUI.getWorkbench().getActiveWorkbenchWindow().getShell());
		box.setMessage("WSAS Succesfully Started !! ");
		box.open();
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


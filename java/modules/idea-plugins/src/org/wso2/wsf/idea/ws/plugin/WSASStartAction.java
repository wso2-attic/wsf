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
package org.wso2.wsf.idea.ws.plugin;

import com.intellij.openapi.actionSystem.AnAction;
import com.intellij.openapi.actionSystem.AnActionEvent;
import com.intellij.openapi.actionSystem.Presentation;
import com.intellij.openapi.actionSystem.ActionPlaces;

import javax.swing.*;

import org.wso2.wsf.idea.ws.util.WSASClassLoadingUtil;
import org.wso2.wsf.idea.ws.util.PopupMessageUtil;
import org.wso2.wsf.idea.ws.util.WSASPropertiesUtil;
import org.wso2.wsf.idea.ws.bean.WSASConfigurationBean;
import org.wso2.wsf.idea.ws.constant.WSASMessageConstant;
import org.wso2.wsf.idea.ws.constant.WSASConfigurationConstant;

import java.lang.reflect.*;
import java.io.File;

public class WSASStartAction extends AnAction {
    private ImageIcon myIcon;
    private static Class wsasMainClazz;

    public void actionPerformed(AnActionEvent e) {
       if (!WSASConfigurationBean.isWsasStartStatus()) { 
            if (WSASConfigurationBean.getWsasInstallationPath().equals(null)) {
                PopupMessageUtil.popupWarningMessageBox(WSASMessageConstant.WARNING_WSAS_PATH_NOT_SET);
            } else
            if (WSASConfigurationBean.getWsasInstallationPath().equals(WSASConfigurationConstant.WSAS_DEFAULT_PATH)) {
                PopupMessageUtil.popupWarningMessageBox(WSASMessageConstant.WARNING_WSAS_PATH_NOT_SET);
            } else {
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

                    PopupMessageUtil.popupInformationMessageBox(WSASMessageConstant.INFO_WSAS_START_SUCCESS);

                } catch (IllegalAccessException e1) {
                    e1.printStackTrace();
                    PopupMessageUtil.popupInformationMessageBox(WSASMessageConstant.INFO_WSAS_START_FAIL);
                } catch (InvocationTargetException e1) {
                    e1.printStackTrace();
                    PopupMessageUtil.popupInformationMessageBox(WSASMessageConstant.INFO_WSAS_START_FAIL);
                } finally {
                    WSASClassLoadingUtil.cleanupAntClassLoader();
                }
        }
       }else{
           PopupMessageUtil.popupErrorMessageBox(WSASMessageConstant.ERROR_WSAS_ALREADY_RUNNING);
       }
    }

    public void update(AnActionEvent event) {
        super.update(event);
        Presentation presentation = event.getPresentation();
        if (ActionPlaces.MAIN_TOOLBAR.equals(event.getPlace())) {
            if (myIcon == null) {
                java.net.URL resource = WSASStartAction.class.getResource(WSASConfigurationConstant.ICON_WSAS_START);
                myIcon = new ImageIcon(resource);
            }
            presentation.setIcon(myIcon);
        }
    }

    public static Class getWSASMainClass(){
        return wsasMainClazz;
    }


    public static Object getWSASMainInstance(){
        Object wsasInstance = null;
        try {
          wsasInstance =  wsasMainClazz.getConstructor(null).newInstance(null);
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        } catch (InstantiationException e) {
            e.printStackTrace();  
        }
        return wsasInstance;
    }

}

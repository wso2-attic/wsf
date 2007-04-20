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

import org.wso2.wsf.idea.ws.bean.WSASConfigurationBean;
import org.wso2.wsf.idea.ws.util.PopupMessageUtil;
import org.wso2.wsf.idea.ws.constant.WSASMessageConstant;
import org.wso2.wsf.idea.ws.constant.WSASConfigurationConstant;

import java.lang.reflect.Method;
import java.lang.reflect.InvocationTargetException;

public class WSASStopAction extends AnAction {
    private ImageIcon myIcon;

    public void actionPerformed(AnActionEvent e) {
        if (WSASConfigurationBean.isWsasStartStatus()) {
            if (!WSASConfigurationBean.isWsasStartStatus()) {
                PopupMessageUtil.popupWarningMessageBox(WSASMessageConstant.WARNING_WSAS_NOT_STARTED);
            } else {
                Class wsasMainClazz = WSASStartAction.getWSASMainClass();
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

                    PopupMessageUtil.popupInformationMessageBox(WSASMessageConstant.INFO_WSAS_STOP_SUCCESS);

                }  catch (IllegalAccessException e1) {
                    e1.printStackTrace();
                    PopupMessageUtil.popupInformationMessageBox(WSASMessageConstant.INFO_WSAS_STOP_FAIL);
                } catch (InvocationTargetException e1) {
                    e1.printStackTrace();
                    PopupMessageUtil.popupInformationMessageBox(WSASMessageConstant.INFO_WSAS_STOP_FAIL);
                }

            }
        } else {
            PopupMessageUtil.popupErrorMessageBox(WSASMessageConstant.ERROR_WSAS_NOT_RUNNING);
        }
    }

    public void update(AnActionEvent event) {
        super.update(event);
        Presentation presentation = event.getPresentation();
        if (ActionPlaces.MAIN_TOOLBAR.equals(event.getPlace())) {
            if (myIcon == null) {
                java.net.URL resource = WSASStopAction.class.getResource(WSASConfigurationConstant.ICON_WSAS_STOP);
                myIcon = new ImageIcon(resource);
            }
            presentation.setIcon(myIcon);
        }
    }

}

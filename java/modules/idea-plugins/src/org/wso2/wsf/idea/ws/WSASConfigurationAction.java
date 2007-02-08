package org.wso2.wsf.idea.ws;

import com.intellij.openapi.actionSystem.AnAction;
import com.intellij.openapi.actionSystem.AnActionEvent;
import com.intellij.openapi.application.Application;
import com.intellij.openapi.application.ApplicationManager;

public class WSASConfigurationAction extends AnAction {
    public void actionPerformed(AnActionEvent e) {
        Application application =
                ApplicationManager.getApplication();
        WSASApplicationComponent helloWorldComponent =
                (WSASApplicationComponent) application.getComponent(
                        WSASApplicationComponent.class);
        helloWorldComponent.sayHello();
    }
}

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

import com.intellij.openapi.components.ApplicationComponent;
import com.intellij.openapi.ui.Messages;
import com.intellij.openapi.options.Configurable;
import com.intellij.openapi.options.ConfigurationException;
import com.intellij.openapi.util.JDOMExternalizable;
import com.intellij.openapi.util.InvalidDataException;
import com.intellij.openapi.util.DefaultJDOMExternalizer;
import com.intellij.openapi.util.WriteExternalException;

import javax.swing.*;

import org.jdom.Element;
import org.wso2.wsf.idea.ws.bean.WSASConfigurationBean;
import org.wso2.wsf.idea.ws.constant.WSASConfigurationConstant;
import org.wso2.wsf.idea.ws.WSASConfigurationForm;

public class WSASApplicationComponent implements ApplicationComponent, Configurable, JDOMExternalizable {

    private WSASConfigurationForm form;

    public WSASApplicationComponent() {
    }

    public void initComponent() {
    }

    public void disposeComponent() {
    }

    public String getComponentName() {
        return WSASConfigurationConstant.WSAS_COMPONENT_NAME;
    }

    public void showInstallationPath() {
        Messages.showMessageDialog(
                WSASConfigurationBean.getWsasInstallationPath(),
                "WSAS Installation Path",
                Messages.getInformationIcon()
        );
    }

    public String getInstallPath() {
        return WSASConfigurationBean.getWsasInstallationPath();
    }

    public void setInstallPath(final String installPath) {
       WSASConfigurationBean.setWsasInstallationPath(installPath);
    }
    public String getDisplayName() {
        // Return name of configuration icon in Settings dialog
        return WSASConfigurationConstant.WSAS_CONFIGURATION;
    }
    public Icon getIcon() {
        return null;
    }
    public String getHelpTopic() {
        return null;
    }
    public JComponent
            createComponent() {
        if (form == null) {
            form = new WSASConfigurationForm();
        }
        return form.getRootComponent();
    }
    public boolean isModified() {
        return form != null && form.isModified(this);
    }
    public void apply() throws ConfigurationException {
        if (form != null) {
            form.getData(this);
        }
    }
    public void reset() {
        if (form != null) {
            form.setData(this);
        }
    }
    public void disposeUIResources() {
        form = null;
    }

    public void readExternal(Element element) throws InvalidDataException {
        DefaultJDOMExternalizer.readExternal(this, element);
    }

    public void writeExternal(Element element) throws WriteExternalException {
        DefaultJDOMExternalizer.writeExternal(this, element);
    }

}

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
package org.wso2.wsf.idea.ws;

import org.wso2.wsf.idea.ws.plugin.WSASApplicationComponent;

import javax.swing.*;

/**
 * Created by IntelliJ IDEA.
 * User: sandakith
 * Date: 8/02/2007
 * Time: 23:41:01
 * To change this template use File | Settings | File Templates.
 */
public class WSASConfigurationForm {
    private JPanel rootComponent;
    private JTextField textInstallPath;
    private JLabel labelInstallPath;
    private JLabel labelWSASConfiguration;

    public void setData(WSASApplicationComponent data) {
        textInstallPath.setText(data.getInstallPath());
    }

    public void getData(WSASApplicationComponent data) {
        data.setInstallPath(textInstallPath.getText());
    }

    public boolean isModified(WSASApplicationComponent data) {
        if (textInstallPath.getText() != null ? !textInstallPath.getText().equals(data.getInstallPath()) : data.getInstallPath() != null)
            return true;
        return false;
    }

    // Method returns the root component of the form
    public JComponent getRootComponent() {
        return rootComponent;
    }

}

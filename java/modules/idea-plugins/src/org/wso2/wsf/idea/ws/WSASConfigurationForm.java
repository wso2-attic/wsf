package org.wso2.wsf.idea.ws;

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

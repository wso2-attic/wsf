package org.wso2.wsf.idea.ws;

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

public class WSASApplicationComponent implements ApplicationComponent, Configurable, JDOMExternalizable {

    private String installPath = "<WSAS Installation Path>";
    private WSASConfigurationForm form;

    public WSASApplicationComponent() {
    }

    public void initComponent() {
    }

    public void disposeComponent() {
    }

    public String getComponentName() {
        return "WSASApplicationComponent";
    }

    public void sayHello() {
        // Show dialog with message
        Messages.showMessageDialog(
                installPath,
                "Sample",
                Messages.getInformationIcon()
        );
    }

    public String getInstallPath() {
        return installPath;
    }

    public void setInstallPath(final String installPath) {
        this.installPath = installPath;
    }
    public String getDisplayName() {
        // Return name of configuration icon in Settings dialog
        return "WSAS Configuration";
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
    public String getPhrase() {
        return installPath;
    }
    public void setPhrase(final String installPath) {
        this.installPath = installPath;
    }

    public void readExternal(Element element) throws InvalidDataException {
        DefaultJDOMExternalizer.readExternal(this, element);
    }

    public void writeExternal(Element element) throws WriteExternalException {
        DefaultJDOMExternalizer.writeExternal(this, element);
    }
}

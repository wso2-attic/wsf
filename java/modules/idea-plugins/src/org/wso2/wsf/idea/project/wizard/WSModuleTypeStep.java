package org.wso2.wsf.idea.project.wizard;

import com.intellij.ide.util.projectWizard.ModuleWizardStep;
import com.intellij.ide.util.projectWizard.WizardContext;
import com.intellij.openapi.diagnostic.Logger;
import com.intellij.openapi.project.Project;

import javax.swing.*;

import org.wso2.wsf.idea.project.module.WSModuleBuilder;

/**
 * Created by IntelliJ IDEA.
 * User: Suran
 * Date: Sep 19, 2007
 * Time: 1:29:36 PM
 * To change this template use File | Settings | File Templates.
 */
public class WSModuleTypeStep extends ModuleWizardStep {
    private static final Logger LOG = Logger.getInstance("#org.wso2.wsf.idea.project");
    private WSModuleBuilder moduleBuilder;
    private String helpId;
    private Project project;
    private Icon icon;


    public WSModuleTypeStep(WSModuleBuilder moduleBuilder, WizardContext wizardContext,
                        Icon icon, String helpId) {
        this.moduleBuilder = moduleBuilder;
        this.helpId = helpId;
        this.icon = icon;

    }


    public void updateDataModel() {
        //To change body of implemented methods use File | Settings | File Templates.
    }

    public JComponent getComponent() {
        return null;  //To change body of implemented methods use File | Settings | File Templates.
    }
}

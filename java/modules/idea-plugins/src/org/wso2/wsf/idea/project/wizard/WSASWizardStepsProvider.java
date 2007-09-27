package org.wso2.wsf.idea.project.wizard;

import com.intellij.ide.util.projectWizard.*;
import com.intellij.openapi.roots.ui.configuration.ModulesProvider;
import com.intellij.openapi.roots.ModifiableRootModel;
import com.intellij.openapi.roots.libraries.Library;
import com.intellij.openapi.module.Module;
import com.intellij.openapi.project.Project;
import com.intellij.openapi.vfs.VirtualFile;
import com.intellij.openapi.vfs.LocalFileSystem;
import com.intellij.util.JavaeeIcons;

import javax.swing.*;

import java.io.File;

/**
 * Created by IntelliJ IDEA.
 * User: Suran
 * Date: Sep 24, 2007
 * Time: 2:53:33 PM
 * To change this template use File | Settings | File Templates.
 */
public class WSASWizardStepsProvider implements AddSupportStepsProvider {
    public String getCheckBoxLabel() {
        return null;  //To change body of implemented methods use File | Settings | File Templates.
    }

    public JComponent createDescriptionComponent() {
        return null;  //To change body of implemented methods use File | Settings | File Templates.
    }

      public AddSupportStep[] createAddSupportSteps(WizardContext context, ModuleBuilder builder,
                                                  ModulesProvider modulesProvider) {

        AddSupportContext asc = new WSASAddSupportContext("WSAS", context.getProject(), false);
        asc.setAddSupport(true);
       
        VirtualFile file = LocalFileSystem.getInstance().findFileByPath("c:/wso2wsas-2.0/lib/activation-1.1.jar");
        VirtualFile file2 = LocalFileSystem.getInstance().findFileByPath("c:/wso2wsas-2.0/lib/annogen-0.1.0.jar");

        asc.setJars(new VirtualFile[] { file, file2});
        
        builder.setAddSupportContexts(new AddSupportContext[] { asc});
        
        AddSupportStep step = ProjectWizardStepFactory.getInstance().createLoadJarsStep(asc, "WSAS Libraries", "WSAS Libraries",
                JavaeeIcons.WEB_WIZARD_ICON);

        return new AddSupportStep[] {step};
    }
}



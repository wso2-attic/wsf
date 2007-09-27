package org.wso2.wsf.idea.project.module;

import com.intellij.ide.util.projectWizard.*;
import com.intellij.openapi.module.ModuleType;
import com.intellij.openapi.roots.ui.configuration.ModulesProvider;
import com.intellij.openapi.project.Project;
import com.intellij.util.ArrayUtil;
import org.wso2.wsf.idea.project.util.WSASIcons;
import org.wso2.wsf.idea.project.wizard.WSASWizardStepsProvider;

import javax.swing.*;
import java.util.ArrayList;

public class WSModuleType extends ModuleType {
    private static WSModuleType instance = new WSModuleType();

    private WSModuleType() {
        super("Web Service Module");
    }

    public static WSModuleType getInstance() {
        return instance;
    }

    public ModuleBuilder createModuleBuilder() {
        return new WSModuleBuilder();
    }

    public String getName() {
        return "Web Service Module";
    }

    public String getDescription() {
        return "WSAS Dynamic Web Service";
    }

    public Icon getBigIcon() {

//        return WSASIcons.WIZARD_ICON;
        return null;
    }

    public Icon getNodeIcon(boolean isOpened) {

//        return WSASIcons.WIZARD_ICON;
        return null;
    }

    public ModuleWizardStep[] createWizardSteps(
            final WizardContext wizardContext, final WSModuleBuilder moduleBuilder,
            ModulesProvider modulesProvider) {
        final ProjectWizardStepFactory wizardStepFactory = ProjectWizardStepFactory.getInstance();
        final ModuleWizardStep nameAndLocationStep = wizardStepFactory.createNameAndLocationStep(wizardContext,
                moduleBuilder, modulesProvider, WSASIcons.WIZARD_ICON,
                "wsas.createWS");

        Project project = wizardContext.getProject();
        ArrayList stepList = new ArrayList();

        stepList.add(nameAndLocationStep);

        WSASWizardStepsProvider wwsp = new WSASWizardStepsProvider();
        wizardStepFactory.registerAddSupportProvider(this, wwsp);
        stepList.add(wwsp.createAddSupportSteps(wizardContext, moduleBuilder, modulesProvider)[0]);
        stepList.add(wizardStepFactory.createSourcePathsStep(nameAndLocationStep, moduleBuilder,
                WSASIcons.WIZARD_ICON, "help"));




        final ModuleWizardStep[] wizardSteps = (ModuleWizardStep[]) stepList.toArray(new ModuleWizardStep[stepList.size()]);

       

        //add more steps here if reqd.

        return (ModuleWizardStep[])ArrayUtil.mergeArrays(wizardSteps,
                super.createWizardSteps(wizardContext, moduleBuilder, modulesProvider),
                ModuleWizardStep.class);
    }


}


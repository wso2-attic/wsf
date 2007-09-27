package org.wso2.wsf.idea.project.module;

import com.intellij.ide.util.projectWizard.JavaModuleBuilder;
import com.intellij.openapi.diagnostic.Logger;
import com.intellij.openapi.roots.ModifiableRootModel;
import com.intellij.openapi.options.ConfigurationException;
import com.intellij.openapi.module.Module;

/**
 * Created by IntelliJ IDEA.
 * User: Suran
 * Date: Sep 19, 2007
 * Time: 12:38:20 PM
 * To change this template use File | Settings | File Templates.
 */
public class WSModuleBuilder extends JavaModuleBuilder {

    private static final Logger LOG = Logger.getInstance("#org.wso2.wsf.idea.project");
    private String explodedDirPath;
    private Module module;

    public Module getModule() {
        return module;
    }

    public void setModule(Module module) {
        this.module = module;
    }

    public void setupRootModel(final ModifiableRootModel rootModel) throws ConfigurationException {
         super.setupRootModel(rootModel);

        this.module = rootModel.getModule();

    }


  

}

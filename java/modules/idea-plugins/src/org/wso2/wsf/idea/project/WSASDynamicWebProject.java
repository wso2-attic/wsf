package org.wso2.wsf.idea.project;

import com.intellij.openapi.components.ApplicationComponent;
import com.intellij.openapi.components.ProjectComponent;
import com.intellij.openapi.module.ModuleTypeManager;
import org.wso2.wsf.idea.project.module.WSModuleType;


public class WSASDynamicWebProject implements ApplicationComponent {

       
    public WSASDynamicWebProject(ModuleTypeManager moduleTypeManager) {
        
        moduleTypeManager.registerModuleType(WSModuleType.getInstance(), true);

    }

    public void initComponent() {
        // TODO: insert component initialization logic here
    }

    public void disposeComponent() {
        // TODO: insert component disposal logic here
    }

    public String getComponentName() {
        return "WSASDynamicWebProject";
    }
}

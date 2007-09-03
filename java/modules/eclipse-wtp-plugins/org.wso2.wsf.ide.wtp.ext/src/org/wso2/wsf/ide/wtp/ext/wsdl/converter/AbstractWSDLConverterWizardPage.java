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
package org.wso2.wsf.ide.wtp.ext.wsdl.converter;

import org.eclipse.jface.dialogs.IDialogSettings;
import org.eclipse.jface.wizard.WizardPage;
import org.wso2.wsf.ide.wtp.ext.java2wsdl.util.SettingsConstants;

public abstract class AbstractWSDLConverterWizardPage extends WizardPage implements SettingsConstants{
    protected IDialogSettings settings;
    protected boolean restoredFromPreviousSettings = false;
    
    public AbstractWSDLConverterWizardPage(String pageName){
        super(pageName+".name");
        init(pageName);
    }
    
    protected void init(String pageName){
        setTitle(WSASWSDLConverterPlugin.getResourceString("main.title"));
        setDescription(WSASWSDLConverterPlugin.getResourceString("main.discription"));
        setImageDescriptor(WSASWSDLConverterPlugin.getWizardImageDescriptor());
        
        /*
         * Get the settings for this page. If there is no section in the
         * Plugin's settings for this OptionsPage, create a new section
         */
        IDialogSettings rootSettings = WSASWSDLConverterPlugin.getDefault()
                .getDialogSettings();
        IDialogSettings section = rootSettings.getSection(this.getClass()
                .getName());
        if (section == null) {
            settings = rootSettings.addNewSection(this.getClass().getName());
            restoredFromPreviousSettings = false;
            initializeDefaultSettings();
        } else {
            restoredFromPreviousSettings=true;
            settings = section;
        }
        
    }

    protected void updateStatus(String message) {
        setErrorMessage(message);
        setPageComplete(message == null);
    }

    protected abstract void initializeDefaultSettings(); 
    
    //Default implementation
    public boolean isSkipNext(){
        return false;
    }
    
    /**
     * a convenient method to get the wizard
     * @return
     */
    public WSASWSDLConverterPlugin getCodegenWizard(){
    	return (WSASWSDLConverterPlugin)getWizard();
    }
    
}

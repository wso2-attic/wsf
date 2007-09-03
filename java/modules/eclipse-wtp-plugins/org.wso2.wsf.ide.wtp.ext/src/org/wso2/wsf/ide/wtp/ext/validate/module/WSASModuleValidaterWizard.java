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
package org.wso2.wsf.ide.wtp.ext.validate.module;

import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.IWizardPage;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;
import org.wso2.wsf.ide.wtp.ext.validate.service.WSASArchiveValidatePlugin;


public class WSASModuleValidaterWizard extends Wizard implements INewWizard{

	WSASModuleValidatePage moduleValidatePage;
	
	public void init(IWorkbench workbench, IStructuredSelection selection) {
	}

	public WSASModuleValidaterWizard() {
		super();
		setNeedsProgressMonitor(true);
		setWindowTitle(WSASArchiveValidatePlugin.getResourceString("main.header"));
	}
	
	
    public boolean canFinish() {
        IWizardPage[] pages = getPages();
        AbstractModuleValidateWizardPage wizardPage = null;
        for (int i = 0; i < pages.length; i++) {
            wizardPage = (AbstractModuleValidateWizardPage) pages[i];
	            if (!wizardPage.isPageComplete()) {
	                    return false;
	            }
        }
        return true;
	}

    /* (non-Javadoc)
     * @see org.eclipse.jface.wizard.IWizard#getNextPage(org.eclipse.jface.wizard.IWizardPage)
     */
    public IWizardPage getNextPage(IWizardPage page) {
    	AbstractModuleValidateWizardPage thisPage = (AbstractModuleValidateWizardPage)page;
    	AbstractModuleValidateWizardPage nextPage = (AbstractModuleValidateWizardPage)super.getNextPage(page);
        while (thisPage!=null && thisPage.isSkipNext()) {
            if (nextPage!=null) {
                thisPage = nextPage;
                nextPage = (AbstractModuleValidateWizardPage)super.getNextPage(nextPage);
            }else{
                break;
            }
        }
        return nextPage;
    }

    /* (non-Javadoc)
     * @see org.eclipse.jface.wizard.IWizard#addPages()
     */
    public void addPages() {
    	moduleValidatePage = new WSASModuleValidatePage();
        this.addPage(moduleValidatePage);
    }

    /* (non-Javadobc)
     * @see org.eclipse.jface.wizard.IWizard#performFinish()
     */
    public boolean performFinish() {
    	return true;
    }

}
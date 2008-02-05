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
package org.wso2.wsf.ide.ds.creation.wizard;

import java.io.File;
import java.net.MalformedURLException;
import java.net.URL;

import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.IWizardPage;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;

public class WSASDSCreatorWizard extends Wizard implements INewWizard{

	WSASDSCreatorPage dsCreationPage;
	
	public void init(IWorkbench workbench, IStructuredSelection selection) {
	}

	public WSASDSCreatorWizard() {
		super();
		setNeedsProgressMonitor(true);
		setWindowTitle("WSAS DS Wizard");
	}
	
	
    public boolean canFinish() {
        IWizardPage[] pages = getPages();
        AbstractDSCreatorWizardPage wizardPage = null;
        for (int i = 0; i < pages.length; i++) {
            wizardPage = (AbstractDSCreatorWizardPage) pages[i];
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
    	AbstractDSCreatorWizardPage thisPage = (AbstractDSCreatorWizardPage)page;
    	AbstractDSCreatorWizardPage nextPage = (AbstractDSCreatorWizardPage)super.getNextPage(page);
        while (thisPage!=null && thisPage.isSkipNext()) {
            if (nextPage!=null) {
                thisPage = nextPage;
                nextPage = (AbstractDSCreatorWizardPage)super.getNextPage(nextPage);
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
    	dsCreationPage = new WSASDSCreatorPage();
        this.addPage(dsCreationPage);
    }

    /* (non-Javadobc)
     * @see org.eclipse.jface.wizard.IWizard#performFinish()
     */
    public boolean performFinish() {
    	return true;
    }
    
}

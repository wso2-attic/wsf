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
package org.wso2.wsf.ide.wtp.ext.dumpaar;

import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.IWizardPage;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;
import org.wso2.wsf.ide.wtp.ext.java2wsdl.JAVA2WSDLOptionsPage;


public class WSASDumpArchiverWizard extends Wizard implements INewWizard{

	WSASDumpAARSelectionPage dumpAARSelectionPage;
	JAVA2WSDLOptionsPage java2WSDLOptionsPage;
	
	public void init(IWorkbench workbench, IStructuredSelection selection) {
	}

	public WSASDumpArchiverWizard() {
		super();
		setNeedsProgressMonitor(true);
		setWindowTitle("WSO2 Web Services AAR Dump Tool");
	}
	
	
    public boolean canFinish() {
        IWizardPage[] pages = getPages();
        AbstractDumpAARWizardPage wizardPage = null;
        for (int i = 0; i < pages.length; i++) {
            wizardPage = (AbstractDumpAARWizardPage) pages[i];
            if (wizardPage.getName().equals("page4.name")){
	            if (!wizardPage.isPageComplete()) {
	                    return false;
	            }
            }
        }
        return true;
	}

    /* (non-Javadoc)
     * @see org.eclipse.jface.wizard.IWizard#getNextPage(org.eclipse.jface.wizard.IWizardPage)
     */
    public IWizardPage getNextPage(IWizardPage page) {
    	AbstractDumpAARWizardPage thisPage = (AbstractDumpAARWizardPage)page;
    	AbstractDumpAARWizardPage nextPage = (AbstractDumpAARWizardPage)super.getNextPage(page);
        while (thisPage!=null && thisPage.isSkipNext()) {
            if (nextPage!=null) {
                thisPage = nextPage;
                nextPage = (AbstractDumpAARWizardPage)super.getNextPage(nextPage);
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
    	dumpAARSelectionPage = new WSASDumpAARSelectionPage();
        this.addPage(dumpAARSelectionPage);
    }

    /* (non-Javadobc)
     * @see org.eclipse.jface.wizard.IWizard#performFinish()
     */
    public boolean performFinish() {
    	return true;
    }






}
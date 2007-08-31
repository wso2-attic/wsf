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
package org.wso2.wsf.ide.wtp.ext.java2wsdl;

import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.IWizardPage;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;


public class WSASJAVA2WSDLWizard extends Wizard implements INewWizard{

	JavaSourceSelectionPage javaSrcSelectionPage;
	JAVA2WSDLOptionsPage java2WSDLOptionsPage;
	JavaWSDLOutputLocationPage javaWSDLOutputLocationPage;
	
	public void init(IWorkbench workbench, IStructuredSelection selection) {
		//Do Nothing
	}

	public WSASJAVA2WSDLWizard() {
		super();
		setNeedsProgressMonitor(true);
		setWindowTitle("WSO2 JAVA 2 WSDL Tool");
	}
		
	
    public boolean canFinish() {
        IWizardPage[] pages = getPages();
        AbstractJAVA2WSDLWizardPage wizardPage = null;
        for (int i = 0; i < pages.length; i++) {
            wizardPage = (AbstractJAVA2WSDLWizardPage) pages[i];
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
    	AbstractJAVA2WSDLWizardPage thisPage = (AbstractJAVA2WSDLWizardPage)page;
    	AbstractJAVA2WSDLWizardPage nextPage = (AbstractJAVA2WSDLWizardPage)super.getNextPage(page);
        while (thisPage!=null && thisPage.isSkipNext()) {
            if (nextPage!=null) {
                thisPage = nextPage;
                nextPage = (AbstractJAVA2WSDLWizardPage)super.getNextPage(nextPage);
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
    	 javaSrcSelectionPage = new JavaSourceSelectionPage();
    	 java2WSDLOptionsPage = new JAVA2WSDLOptionsPage();
    	 javaWSDLOutputLocationPage = new JavaWSDLOutputLocationPage();
    	 this.addPage(javaSrcSelectionPage);
    	 this.addPage(java2WSDLOptionsPage);
         this.addPage(javaWSDLOutputLocationPage);
    }

    /* (non-Javadobc)
     * @see org.eclipse.jface.wizard.IWizard#performFinish()
     */
    public boolean performFinish() {
        try {
        	doFinishJava2WSDL();
        } catch (Exception e) {
            MessageDialog.openError(getShell(), 
                    WSASJAVA2WSDLPlugin.getResourceString("general.Error"), 
                    WSASJAVA2WSDLPlugin.getResourceString("general.Error.prefix") +
                    e.getMessage());
            return false;
        }
        MessageDialog.openInformation(this.getShell(), 
        		WSASJAVA2WSDLPlugin.getResourceString("general.name"),
        		WSASJAVA2WSDLPlugin.getResourceString("wizard.success"));
        return true;
    }
    
    
    private void doFinishJava2WSDL() throws Exception {
    	//TODO : Implement the JAVA2WSDL operation. 
    }
    
    public void setDefaultNamespaces(String fullyQualifiedClassName){
    	java2WSDLOptionsPage.setNamespaceDefaults(fullyQualifiedClassName);
    }
    

}
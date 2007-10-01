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
package org.wso2.wsf.ide.wtp.ext.validate.service;

import java.io.File;
import java.net.MalformedURLException;
import java.net.URL;

import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.IWizardPage;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.wtp.ext.validate.service.util.WSASUoloadServiceRequestUtil;


public class WSASArchiveValidaterWizard extends Wizard implements INewWizard{

	WSASUoloadServiceRequestUtil util = WSASUoloadServiceRequestUtil.getInstance();
	WSASArchiveValidatePage archiveValidatePage;
	WSASArchiveResultPage archiveResultPage;
	
	public void init(IWorkbench workbench, IStructuredSelection selection) {
	}

	public WSASArchiveValidaterWizard() {
		super();
		setNeedsProgressMonitor(true);
		setWindowTitle(WSASArchiveValidatePlugin.getResourceString("main.header"));
	}
	
	
    public boolean canFinish() {
        IWizardPage[] pages = getPages();
        AbstractArchiveValidateWizardPage wizardPage = null;
        for (int i = 0; i < pages.length; i++) {
            wizardPage = (AbstractArchiveValidateWizardPage) pages[i];
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
    	AbstractArchiveValidateWizardPage thisPage = (AbstractArchiveValidateWizardPage)page;
    	AbstractArchiveValidateWizardPage nextPage = (AbstractArchiveValidateWizardPage)super.getNextPage(page);
        while (thisPage!=null && thisPage.isSkipNext()) {
            if (nextPage!=null) {
                thisPage = nextPage;
                nextPage = (AbstractArchiveValidateWizardPage)super.getNextPage(nextPage);
            }else{
                break;
            }
        }
    	if (WSASArchiveValidatePlugin.getDefault().isGoAheadValidation()) {
    		try {
    			File resourceFile = null;
    			if (archiveValidatePage.getAarPathEnabled()) {
					resourceFile = new File(archiveValidatePage.getAarPathText());
				}
    			if(archiveValidatePage.getServicesXMlPathEnabled()){
    				resourceFile = new File(archiveValidatePage.getServicesXMlPathText());
    			}
				URL resultURL = new URL(
						WSASCoreUIMessages.LOCAL_SERVER_PORT
						+goAheadVelidation(resourceFile));
				WSASArchiveValidatePlugin.getDefault().setValidateURL(resultURL);
				archiveResultPage.fillBrowserWithResults();
			} catch (MalformedURLException e) {
				e.printStackTrace();
			}
		}
        return nextPage;
    }

    /* (non-Javadoc)
     * @see org.eclipse.jface.wizard.IWizard#addPages()
     */
    public void addPages() {
    	archiveValidatePage = new WSASArchiveValidatePage();
        this.addPage(archiveValidatePage);
        archiveResultPage = new WSASArchiveResultPage();
        this.addPage(archiveResultPage);
    }

    /* (non-Javadobc)
     * @see org.eclipse.jface.wizard.IWizard#performFinish()
     */
    public boolean performFinish() {
    	//Popup the browser upon user request
    	if (archiveResultPage.getBrowserPopUpCheck()) {
			util.popupInternalBrowser(WSASArchiveValidatePlugin.getDefault().getValidateURL());
		}
    	return true;
    }
    
    private String goAheadVelidation(File resourceFile){
		return util.requestValidate(resourceFile,archiveValidatePage.getFileType());
    }
    
}

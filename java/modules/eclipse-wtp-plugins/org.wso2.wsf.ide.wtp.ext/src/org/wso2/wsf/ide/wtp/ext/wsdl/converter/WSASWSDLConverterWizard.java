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

import java.io.File;
import java.net.MalformedURLException;
import java.net.URL;

import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.IWizardPage;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.wtp.ext.validate.service.WSASArchiveValidatePlugin;
import org.wso2.wsf.ide.wtp.ext.validate.service.util.WSASUoloadServiceRequestUtil;


public class WSASWSDLConverterWizard extends Wizard implements INewWizard{

	WSASUoloadServiceRequestUtil util = WSASUoloadServiceRequestUtil.getInstance();
	WSASWSDLConverterPage wsdlConverterPage;
	WSASWSDLConverterResultPage wsdlConverterResultPage;
	
	public void init(IWorkbench workbench, IStructuredSelection selection) {
	}

	public WSASWSDLConverterWizard() {
		super();
		setNeedsProgressMonitor(true);
		setWindowTitle(WSASWSDLConverterPlugin.getResourceString("main.header"));
	}
	
	
    public boolean canFinish() {
        IWizardPage[] pages = getPages();
        AbstractWSDLConverterWizardPage wizardPage = null;
        for (int i = 0; i < pages.length; i++) {
            wizardPage = (AbstractWSDLConverterWizardPage) pages[i];
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
    	AbstractWSDLConverterWizardPage thisPage = (AbstractWSDLConverterWizardPage)page;
    	AbstractWSDLConverterWizardPage nextPage = (AbstractWSDLConverterWizardPage)super.getNextPage(page);
        while (thisPage!=null && thisPage.isSkipNext()) {
            if (nextPage!=null) {
                thisPage = nextPage;
                nextPage = (AbstractWSDLConverterWizardPage)super.getNextPage(nextPage);
            }else{
                break;
            }
        }
    	if (WSASWSDLConverterPlugin.getDefault().isGoAheadConversion()) {
    		try {
    			File resourceFile = null;
    			String path = wsdlConverterPage.getWSDLPathText();
    			if (path != null && !path.equals("")) {
					resourceFile = new File(path);
				}
				URL resultURL = new URL(
						WSASCoreUIMessages.LOCAL_SERVER_PORT
						+goAheadConversion(resourceFile));
				WSASWSDLConverterPlugin.getDefault().setValidateURL(resultURL);
				wsdlConverterResultPage.fillBrowserWithResults();
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
    	wsdlConverterPage = new WSASWSDLConverterPage();
        this.addPage(wsdlConverterPage);
        wsdlConverterResultPage = new WSASWSDLConverterResultPage();
        this.addPage(wsdlConverterResultPage);
    }

    /* (non-Javadobc)
     * @see org.eclipse.jface.wizard.IWizard#performFinish()
     */
    public boolean performFinish() {
    	//Popup the browser upon user request
    	if (wsdlConverterResultPage.getBrowserPopUpCheck()) {
			util.popupInternalBrowser(WSASWSDLConverterPlugin.getDefault().getValidateURL());
		}
    	return true;
    }
    
    private String goAheadConversion(File resourceFile){
		return util.requestValidate(resourceFile,wsdlConverterPage.getFileType());
    }

}

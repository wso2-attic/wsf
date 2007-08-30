package org.wso2.wsf.ide.wtp.ext.dumpaar;

import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.IWizardPage;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;
import org.wso2.wsf.ide.wtp.ext.AbstractWizardPage;
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
        AbstractWizardPage wizardPage = null;
        for (int i = 0; i < pages.length; i++) {
            wizardPage = (AbstractWizardPage) pages[i];
            if (wizardPage.getName().equals("page4.name")){
	            if (!wizardPage.getWizardComplete() ) {
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
    	AbstractWizardPage thisPage = (AbstractWizardPage)page;
    	AbstractWizardPage nextPage = (AbstractWizardPage)super.getNextPage(page);
        while (thisPage!=null && thisPage.isSkipNext()) {
            if (nextPage!=null) {
                thisPage = nextPage;
                nextPage = (AbstractWizardPage)super.getNextPage(nextPage);
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
        java2WSDLOptionsPage = new JAVA2WSDLOptionsPage();
        this.addPage(dumpAARSelectionPage);
        this.addPage(java2WSDLOptionsPage);
    }

    /* (non-Javadobc)
     * @see org.eclipse.jface.wizard.IWizard#performFinish()
     */
    public boolean performFinish() {
    	return true;
    }






}
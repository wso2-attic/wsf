/*
 * Copyright 2005-2009 WSO2, Inc. http://wso2.com
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

package org.wso2.wsf.codegen.wizards;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;
import java.util.Map;

import javax.wsdl.Definition;

import org.wso2.wsf.codegen.Activator;
import org.wso2.wsf.codegen.WSDL2CodeGenerator;
import org.wso2.wsf.codegen.util.SettingsConstants;
import org.wso2.wsf.codegen.util.UIConstants;
import org.wso2.wsf.codegen.util.WSDLPropertyReader;
import org.wso2.wsf.codegen.wizards.WSDLFileSelectionPage;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.wsdl.WSDL2Code;
import org.apache.axis2.wsdl.codegen.CodeGenConfiguration;
import org.apache.axis2.wsdl.codegen.CodeGenerationEngine;
import org.eclipse.core.resources.IWorkspace;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.NullProgressMonitor;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.IWizardPage;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.jface.wizard.WizardPage;
import org.eclipse.ui.actions.WorkspaceModifyOperation;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;


public class CodegenWizard extends Wizard implements INewWizard {
	private WSDLFileSelectionPage wsdlFileSelectionPage;
	//private IStructuredSelection initialSelection;
	private OptionsPage optionsPage;
	private OutputPage outputPage;

 
    private int selectedCodegenOptionType = SettingsConstants.CODEGEN_DEFAULT_TYPE;//TODO change this
	
	
	public CodegenWizard(){
		super();
		setNeedsProgressMonitor(true);
		}
	
	
	public void addPages(){
		wsdlFileSelectionPage = new WSDLFileSelectionPage();
		addPage(wsdlFileSelectionPage);
		optionsPage  = new OptionsPage();
		addPage(optionsPage);
		outputPage = new OutputPage();
		addPage(outputPage);
		
	}
	
	 public boolean canFinish() {
	        IWizardPage[] pages = getPages();
	        AbstractWizardPage wizardPage = null;
	        for (int i = 0; i < pages.length; i++) {
	            wizardPage = (AbstractWizardPage) pages[i];
	            if (!(wizardPage.isPageComplete()))
	                    return false;
	          
	        }
	        return true;
	    }

	    public IWizardPage getNextPage(IWizardPage page) {
	        AbstractWizardPage pageout = (AbstractWizardPage) super.getNextPage(page);
	        return pageout;
	    }

	    /**
	     * This method is called when 'Finish' button is pressed in the wizard. We
	     * will create an operation and run it using wizard as execution context.
	     */
	    public boolean performFinish() {
	        try {
	                doFinishWSDL2Code();
	            
	        } catch (Exception e) {
	            MessageDialog.openError(getShell(), 
	                    Activator.getResourceString("general.Error"), 
	                    Activator.getResourceString("general.Error.prefix") +
	                    e.getMessage());
	            return false;
	        }
	        MessageDialog.openInformation(this.getShell(), 
	                 Activator
	                .getResourceString("general.name"), Activator
	                .getResourceString("wizard.success"));
	        return true;
	    }

	    /**
	     * The worker method, generates the code itself.
	     */
	    private void doFinishWSDL2Code() {
	        WorkspaceModifyOperation op = new WorkspaceModifyOperation() 
	        {
	           protected void execute(IProgressMonitor monitor) throws InvocationTargetException, CoreException,InterruptedException{
	              if (monitor == null)
	                 monitor = new NullProgressMonitor();

	              /*
	               * "3" is the total amount of steps, see below monitor.worked(amount)
	               */
	              monitor.beginTask(Activator.getResourceString("generator.generating"), 2);

	              try
	              {
	                 /*
	                  * TODO: Introduce a progress monitor interface for CodeGenerationEngine.
	                  * Since this monitor here doesn't make much sense, we
	                  * should either remove the progress monitor from the CodeGenWizard,
	                  * or give a (custom) progress monitor to the generate() method, so
	                  * we will be informed by Axis2 about the progress of code generation.  
	                  */
	                 WSDL2CodeGenerator generator = new WSDL2CodeGenerator(); 
	                 monitor.subTask(Activator.getResourceString("generator.readingWOM"));
	                 AxisService service = generator.getAxisService(wsdlFileSelectionPage.getFileName());
	                 monitor.worked(1);
	                 
	                 //The generate all fix (Axis2-1862)
	                 boolean isServerside,isServiceXML,isGenerateServerSideInterface  = false;
	                 if (optionsPage.getGenerateAll()){
	                         isServerside = true;
	                         isServiceXML = true;
	                         isGenerateServerSideInterface = true;
	                 }else{
	                         isServerside = optionsPage.isServerside();
	                         isServiceXML =optionsPage.isServerXML();
	                         isGenerateServerSideInterface = optionsPage.getGenerateServerSideInterface();
	                 }
	                 Map optionsMap = generator.fillOptionMap(optionsPage.isAsyncOnlyOn(),
                                                optionsPage.isSyncOnlyOn(),
                                                isServerside,
                                                isServiceXML,
                                                optionsPage.isGenerateTestCase(),
                                                optionsPage.getGenerateAll(),
                                                optionsPage.getServiceName(),
                                                optionsPage.getPortName(),
                                                optionsPage.getDatabinderName(),
                                                wsdlFileSelectionPage.getFileName(),
                                                optionsPage.getPackageName(),
                                                optionsPage.getSelectedLanguage(),
                                                outputPage.getOutputLocation(),
                                                optionsPage.getNs2PkgMapping(),
                                                isGenerateServerSideInterface,
                                                optionsPage.getAdvanceOptions());

	                 CodeGenConfiguration codegenConfig = new CodeGenConfiguration(optionsMap);
	                 codegenConfig.addAxisService(service);
	                 
	                 //set the WSDL definition for codegen config for skeleton generation.
	                 WSDLPropertyReader reader = new WSDLPropertyReader();
	                 reader.readWSDL(wsdlFileSelectionPage.getFileName());
	                 Definition wsdlDefinition = reader.getWsdlDefinition();
	                 codegenConfig.setWsdlDefinition(wsdlDefinition);
	                 
	                 //set the baseURI
	                 codegenConfig.setBaseURI(generator.getBaseUri(wsdlFileSelectionPage.getFileName()));
	                 monitor.worked(1);
	                 
	                 monitor.subTask(Activator.getResourceString("generator.generating"));
	                 new CodeGenerationEngine(codegenConfig).generate();
	              }
	              catch (Exception e)
	              {
	                 ///////////////////////////////
	            	  e.printStackTrace();
	            	 ///////////////////////////// 
	                 throw new InterruptedException(e.getMessage());
	              }

	              monitor.done();
	           }
	        };


	        /*
	         * Start the generation as new Workbench Operation, so the user
	         * can see the progress and, if needed, can stop the operation.
	         */
	        try
	        {
	           getContainer().run(false, true, op);
	        }
	        catch (InvocationTargetException e1)
	        {
	        	/////////////////////////
	        	e1.printStackTrace();
	        	////////////////////////
	            throw new RuntimeException(e1);
	        }
	        catch (InterruptedException e1)
	        {
	           throw new RuntimeException(e1);
	        }
	        catch (Exception e)
	        {
	           throw new RuntimeException(e);
	        }
	    }

	    /**
	     * We will accept the selection in the workbench to see if we can initialize
	     * from it.
	     * 
	     * @see IWorkbenchWizard#init(IWorkbench, IStructuredSelection)
	     */
	    public void init(IWorkbench workbench, IStructuredSelection selection) {
	        //do nothing
	    }


	    /**
	     * @return Returns the codegenOptionType.
	     */
	    public int getSelectedCodegenOptionType() {
	        return selectedCodegenOptionType;
	    }
	    
	    /**
	     * @param selectedCodegenOptionType
	     *            The selectedCodegenOptionType to set.
	     */
	    public void setSelectedCodegenOptionType(int selectedCodegenOptionType) {
	        this.selectedCodegenOptionType = selectedCodegenOptionType;
	    }

	    /**
	     * Get the selected WSDL from the WSDLselectionpage
	     * @return
	     */
	    public String getWSDLname(){
	        return wsdlFileSelectionPage.getFileName();	
	    }
	    
	    /**
	     * populate the options page. Usually done after reloading the WSDL
	     *
	     */
	    public void populateOptions(){
	    	optionsPage.populateParamsFromWSDL();
	    }
	    
	    
	    // Copies all files under srcDir to dstDir.
	    // If dstDir does not exist, it will be created.
	    public void copyDirectory(File srcDir, File dstDir) throws IOException {
	        if (srcDir.isDirectory()) {
	            if (!dstDir.exists()) {
	                dstDir.mkdir();
	            }
	    
	            String[] children = srcDir.list();
	            for (int i=0; i<children.length; i++) {
	                copyDirectory(new File(srcDir, children[i]),
	                                     new File(dstDir, children[i]));
	            }
	        } else {
	            copyFile(srcDir, dstDir);
	        }
	    }
	        
	    // Copies src file to dst file.
	    // If the dst file does not exist, it is created
	    private void copyFile(File src, File dst) throws IOException {
	        InputStream in = new FileInputStream(src);
	        OutputStream out = new FileOutputStream(dst);
	    
	        // Transfer bytes from in to out
	        byte[] buf = new byte[1024];
	        int len;
	        while ((len = in.read(buf)) > 0) {
	            out.write(buf, 0, len);
	        }
	        in.close();
	        out.close();
	    }
	    public WizardPage getOutPage(){
	    	return outputPage;
	    }
	    
}

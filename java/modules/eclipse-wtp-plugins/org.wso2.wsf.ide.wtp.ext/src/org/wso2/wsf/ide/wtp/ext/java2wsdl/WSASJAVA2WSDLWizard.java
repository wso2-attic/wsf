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

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Map;

import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.NullProgressMonitor;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.IWizardPage;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;
import org.eclipse.ui.actions.WorkspaceModifyOperation;
import org.wso2.wsf.ide.core.utils.ClassLoadingUtil;


public class WSASJAVA2WSDLWizard extends Wizard implements INewWizard{

	JavaSourceSelectionPage javaSrcSelectionPage;
	JAVA2WSDLOptionsPage java2WSDLOptionsPage;
	JavaWSDLOutputLocationPage javaWSDLOutputLocationPage;
	Class java2WSDLConstantsClazz;
	Constructor java2WSDLCommandLineOptionConstructor;
	
	public void init(IWorkbench workbench, IStructuredSelection selection) {
		//Do Nothing
	}

	public WSASJAVA2WSDLWizard() {
		super();
		setNeedsProgressMonitor(true);
		setWindowTitle("WSO2 JAVA2WSDL Tool");
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
    	org.eclipse.ui.actions.WorkspaceModifyOperation op = new WorkspaceModifyOperation() {
    		protected void execute(IProgressMonitor monitor) {
    			if (monitor == null)
    				monitor = new NullProgressMonitor();

    			monitor.beginTask(WSASJAVA2WSDLPlugin
    					.getResourceString("generator.generating"), 3);

    			try {
    				monitor.worked(1);
    				
    		        //Reflection invocatin resources
    				ClassLoadingUtil.init();
    				Class java2WSDLCommandLineOptionClazz = 
    								ClassLoadingUtil.loadClassFromAntClassLoader(
    									"org.apache.ws.java2wsdl.utils.Java2WSDLCommandLineOption");
    				java2WSDLConstantsClazz = ClassLoadingUtil.loadClassFromAntClassLoader(
    								"org.apache.axis2.description.java2wsdl.Java2WSDLConstants");
    				java2WSDLCommandLineOptionConstructor = 
    										java2WSDLCommandLineOptionClazz.getConstructor(
    										new Class[]{String.class,String[].class});
    				
    				//fill the option map
    				Map optionMap = new HashMap();
    				
    				loadOptionMapWithParams(optionMap,"CLASSNAME_OPTION",
    						getStringArray(javaSrcSelectionPage.getClassName()));

    				loadOptionMapWithParams(optionMap,"CLASSPATH_OPTION",
    						javaSrcSelectionPage.getClassPathList());   				

    				loadOptionMapWithParams(optionMap,"TARGET_NAMESPACE_OPTION",
    						getStringArray(java2WSDLOptionsPage.getTargetNamespace()));    				

     				loadOptionMapWithParams(optionMap,"TARGET_NAMESPACE_PREFIX_OPTION",
     						getStringArray(java2WSDLOptionsPage.getTargetNamespacePrefix()));   				

    				loadOptionMapWithParams(optionMap,"SCHEMA_TARGET_NAMESPACE_OPTION",
    						getStringArray(java2WSDLOptionsPage.getSchemaTargetNamespace()));    				

     				loadOptionMapWithParams(optionMap,"SERVICE_NAME_OPTION",
     						getStringArray(java2WSDLOptionsPage.getServiceName()));    				

    				loadOptionMapWithParams(optionMap,"SCHEMA_TARGET_NAMESPACE_PREFIX_OPTION",
    						getStringArray(java2WSDLOptionsPage.getSchemaTargetNamespacePrefix()));    				

     				loadOptionMapWithParams(optionMap,"OUTPUT_LOCATION_OPTION",
     						getStringArray(javaWSDLOutputLocationPage.getOutputLocation()));    				

    				loadOptionMapWithParams(optionMap,"OUTPUT_FILENAME_OPTION",
    						getStringArray(javaWSDLOutputLocationPage.getOutputWSDLName()));    				

    				monitor.worked(1);

    				//new Java2WSDLCodegenEngine(optionsMap).generate();
    				Class java2WSDLCodegenEngineClazz = ClassLoadingUtil
    						.loadClassFromAntClassLoader("org.apache.ws.java2wsdl.Java2WSDLCodegenEngine");
    				Constructor java2WSDLCodegenEngineConstructor = java2WSDLCodegenEngineClazz
    								.getConstructor(new Class[]{Map.class});
    				Object CodeGenerationEngineInstance  = java2WSDLCodegenEngineConstructor
    								.newInstance(new Object[]{optionMap});
    				
    				//Invoke Codegen Method
    				Method generateMethod = java2WSDLCodegenEngineClazz.getMethod("generate", null);
    				generateMethod.invoke(CodeGenerationEngineInstance, null);

    				monitor.worked(1);


    			} catch (Throwable e) {
    				e.printStackTrace();
    				throw new RuntimeException(e);
    			}

    			monitor.done();
    		}
    	};

    	try {
    		getContainer().run(false, true, op);
    	} catch (InvocationTargetException e1) {
    		throw new RuntimeException(e1);
    	} catch (InterruptedException e1) {
    		throw new RuntimeException(WSASJAVA2WSDLPlugin.
    				getResourceString("general.useraborted.state"));
    	} catch (Exception e) {
    		throw new RuntimeException(e);
    	}
    }
    
    public void setDefaultNamespaces(String fullyQualifiedClassName){
    	java2WSDLOptionsPage.setNamespaceDefaults(fullyQualifiedClassName);
    }
    
    /**
     * Converts a single String into a String Array
     * @param value a single string
     * @return an array containing only one element
     */
    private String[] getStringArray(String value){
       String[] values = new String[1];
       values[0] = value;
       return values;
    }
    
    /**
     * Util method to load the option map with the java2wsdl params
     * @param optionMap
     * @param option 
     * @param value
     */
    private void loadOptionMapWithParams(Map optionMap,String option,String[] value){
		try {
			Field optionField = java2WSDLConstantsClazz.getField(option);
			optionMap.put((String)optionField.get(String.class),
					java2WSDLCommandLineOptionConstructor.newInstance(
							new Object[]{(String)optionField.get(String.class),
							value}));
		} catch (InvocationTargetException e) {
			e.printStackTrace();
		} catch (Exception e){
			e.printStackTrace();
		}
    }

}
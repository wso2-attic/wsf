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

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Map;

import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.Path;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.IWizardPage;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;
import org.wso2.wsf.ide.core.context.ServiceContext;
import org.wso2.wsf.ide.core.utils.ArchiveManipulator;
import org.wso2.wsf.ide.core.utils.FileUtils;
import org.wso2.wsf.ide.core.utils.ScriptBuilder;
import org.wso2.wsf.ide.wtp.ext.dumpaar.script.AntBuildDTO;
import org.wso2.wsf.ide.wtp.ext.dumpaar.script.AntMapBuilder;
import org.wso2.wsf.ide.wtp.ext.java2wsdl.JAVA2WSDLOptionsPage;


public class WSASDumpArchiverWizard extends Wizard implements INewWizard{

	WSASDumpAARSelectionPage dumpAARSelectionPage;
	JAVA2WSDLOptionsPage java2WSDLOptionsPage;
	boolean alreadyInit;
	IPath systemDirPath;
	IPath dumpAARPath;
	IPath dumpAARTargetPath;
	IPath workspacePath;
	
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
    	String serviceToDump = dumpAARSelectionPage.getSelectedService();
    	if(!alreadyInit){
    		initFolderStructure();
    	}
    	IPath selectedServicePath = dumpAARPath.append(serviceToDump);
    	File selectedServiceFile = new File(selectedServicePath.toOSString());
    	if(selectedServiceFile.exists()){
    		FileUtils.deleteDirectories(selectedServiceFile);
    	}
    	FileUtils.createDirectorys(selectedServiceFile.getAbsolutePath());
    	
    	//Copy the service (src and classes) of the IDE Created Service
    	try {
			FileUtils.copyDirectory(
				new File(dumpAARSelectionPage.getWSASRepoPath().append(serviceToDump).toOSString()),
				selectedServiceFile);
			//Add the source also to the classes
			ServiceContext context = ServiceContext.getInstance();
			String projectName = getProjectForService(serviceToDump,context.getServiceToProjectMap());
			FileUtils.copyDirectory(
					new File(workspacePath.append(projectName).append("src").toOSString()),
					selectedServiceFile);
	
		ArchiveManipulator archiveManipulator = new ArchiveManipulator();
		archiveManipulator.archiveDir(serviceToDump+".aar", selectedServicePath.toOSString());
		
		File archiveLocation = new File(systemDirPath.append(serviceToDump+".aar").toOSString());
		IPath archiveDestLocation = new Path(dumpAARTargetPath.toOSString());
		archiveDestLocation = archiveDestLocation.append(serviceToDump+".aar");
		FileUtils.copyFile(archiveLocation.getAbsolutePath(), archiveDestLocation.toOSString());
		archiveLocation.delete();
		} catch (IOException e) {
			e.printStackTrace();
		}
    	
    	if (dumpAARSelectionPage.getBuildCheckBoxSelection()) {
			//Make the Ant Build DTO 
			AntBuildDTO antBuildDTO = new AntBuildDTO();
			antBuildDTO.setServiceName(serviceToDump);
			antBuildDTO.setTargetPath(dumpAARTargetPath.toOSString());
			
			//Generate the Map using the DTO
			AntMapBuilder antMapBuilder = new AntMapBuilder();
			antMapBuilder.buildAntBuildMap(antBuildDTO);
			
			try {
				//Make the ant build from transform
				ScriptBuilder scriptBuilder = new ScriptBuilder();
				FileInputStream inStream = new FileInputStream(antMapBuilder
						.getBuildFileLocation().toOSString());
				IPath antBuildLocation = new Path(antBuildDTO.getTargetPath());
				antBuildLocation = antBuildLocation.removeLastSegments(1);
				antBuildLocation = antBuildLocation.append(antBuildDTO
						.getServiceName()
						+ "AntBuild.xml");
				FileOutputStream outStream = new FileOutputStream(
						antBuildLocation.toOSString());
				InputStream xslStream = getClass()
						.getResourceAsStream(
								"org/wso2/wsf/ide/wtp/ext/dumpaar/xsl/AntBuildTemplate.xsl");
				if (xslStream == null) {
					xslStream = Thread
							.currentThread()
							.getContextClassLoader()
							.getResourceAsStream(
									"org/wso2/wsf/ide/wtp/ext/dumpaar/xsl/AntBuildTemplate.xsl");
				}
				scriptBuilder.parseXMLFile(inStream, outStream, xslStream);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
    	
		//Print the resulting message from a popup dialog 
		MessageDialog.openInformation(this.getShell(), 
				WSASDumpAARPlugin.getResourceString("page1.name"),
				WSASDumpAARPlugin.getResourceString("page1.success"));
		
    	return true;
    }
    
    private void initFolderStructure() {
    	systemDirPath = new Path(System.getProperty("user.dir"));
    	dumpAARPath = systemDirPath.append("dumpAAR");
    	dumpAARTargetPath = new Path(dumpAARPath.append("target").toOSString());
    	FileUtils.createDirectorys(dumpAARPath.toOSString());
    	FileUtils.createDirectorys(dumpAARTargetPath.toOSString());
    	workspacePath=ResourcesPlugin.getWorkspace().getRoot().getRawLocation();
    	alreadyInit = true;
    }
    
    private String getProjectForService(String service, Map<String, String> serviceToProjectMap){
    	String mappedProjectName = null;
    	if (serviceToProjectMap.containsKey(service)) {
    		mappedProjectName = serviceToProjectMap.get(service);
		}
    	return mappedProjectName;
    }

}

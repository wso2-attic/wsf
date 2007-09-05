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

import java.util.Iterator;
import java.util.List;

import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.Path;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.widgets.Composite;
import org.wso2.wsf.ide.core.utils.FileUtils;
import org.wso2.wsf.ide.wtp.ext.server.bean.WSASConfigurationBean;

public class WSASDumpAARSelectionPage extends AbstractDumpAARWizardPage{
	
    private Combo serviceSelectionCombo;
    private String selectedService;
    private Button antBuildCreationCheck;
    IPath wsasRepoPath;
   
    public WSASDumpAARSelectionPage(){
        super("page1");
    }

    /* (non-Javadoc)
     * @see org.apache.axis2.tool.service.eclipse.ui.AbstractServiceWizardPage#initializeDefaultSettings()
     */
    protected void initializeDefaultSettings() {
    }
    
    /* (non-Javadoc)
     * @see org.eclipse.jface.dialogs.IDialogPage#createControl(org.eclipse.swt.widgets.Composite)
     */
    public void createControl(Composite parent) {
        Composite container = new Composite(parent, SWT.NULL);
        GridLayout layout = new GridLayout();
        layout.numColumns=1;
        layout.verticalSpacing = 9;
        
        container.setLayout(layout);
        GridData gd = new GridData(GridData.FILL_HORIZONTAL);
        
		serviceSelectionCombo = new Combo(container,SWT.NONE | SWT.READ_ONLY);
		serviceSelectionCombo.setLayoutData(gd);
		fillSrviceSelectionCombo();
		serviceSelectionCombo.select(0);
		setSelectedService((serviceSelectionCombo.getItemCount()!=0)?
				serviceSelectionCombo.getItem(0):null);
		serviceSelectionCombo.addSelectionListener(new SelectionListener(){
			public void widgetSelected(SelectionEvent e) {
				handleModify(serviceSelectionCombo.getText());
			}
			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});
		
		antBuildCreationCheck = new Button(container,SWT.CHECK);
		antBuildCreationCheck.setLayoutData(gd);
		antBuildCreationCheck.setText(WSASDumpAARPlugin.getResourceString("page1.build.check"));
		antBuildCreationCheck.setSelection(true);
		antBuildCreationCheck.addSelectionListener(new SelectionListener(){
			public void widgetDefaultSelected(SelectionEvent e) {
			}
			public void widgetSelected(SelectionEvent e) {
			}
		});
		setControl(container);
		
		//call the handle modify method if the settings are restored
		if (restoredFromPreviousSettings){
		    handleModify(null);
		}
    }
    
    
    private void handleModify(String selectedService){
    	if (selectedService != null) {
			setSelectedService(selectedService);
		}
    }
    
	public boolean getWizardComplete() {
		return false;
	}
	
	private void fillSrviceSelectionCombo(){
		//Check whether there is IDE configured services in the WSAS services directory
		WSASConfigurationBean.Init();
		wsasRepoPath = new Path(WSASConfigurationBean.getWsasInstallationPath());
		wsasRepoPath = wsasRepoPath.append("repository");
		wsasRepoPath = wsasRepoPath.append("services");
		List<IPath> ideConfiguredServices=FileUtils.getDirsOnly(wsasRepoPath.toOSString());
		//If services are there
		if (ideConfiguredServices.size() != 0) {
			updateStatus(null);
			for (Iterator<IPath> iterator = ideConfiguredServices.iterator(); iterator.hasNext();){
				IPath serviPath = (IPath) iterator.next();
				serviceSelectionCombo.add(serviPath.lastSegment());
			}
		}else{
			updateStatus(WSASDumpAARPlugin.getResourceString("error.no.services"));
		}
	}

	public String getSelectedService() {
		return selectedService;
	}

	private void setSelectedService(String selectedService) {
		this.selectedService = selectedService;
	}
	
	public IPath getWSASRepoPath() {
		return wsasRepoPath;
	}
	
	public boolean getBuildCheckBoxSelection() {
		return antBuildCreationCheck.getSelection();
	}

}

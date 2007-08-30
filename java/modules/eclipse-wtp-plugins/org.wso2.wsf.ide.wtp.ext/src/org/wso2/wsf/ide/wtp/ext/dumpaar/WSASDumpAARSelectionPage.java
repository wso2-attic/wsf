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
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.widgets.Composite;
import org.wso2.wsf.ide.core.utils.FileUtils;
import org.wso2.wsf.ide.wtp.ext.AbstractWizardPage;
import org.wso2.wsf.ide.wtp.ext.server.bean.WSASConfigurationBean;

public class WSASDumpAARSelectionPage extends AbstractWizardPage{
	
    private Combo serviceSelectionCombo;
   
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
        layout.numColumns=3;
        layout.verticalSpacing = 9;
        
        container.setLayout(layout);
        GridData gd = new GridData(GridData.FILL_HORIZONTAL);
		
		serviceSelectionCombo = new Combo(container,SWT.NONE);
		serviceSelectionCombo.setLayoutData(gd);
		fillSrviceSelectionCombo();
		serviceSelectionCombo.select(0);
		serviceSelectionCombo.addModifyListener(new ModifyListener(){
		    public void modifyText(ModifyEvent e){
	        	handleModify();
	    	}
		});
		
		setControl(container);
		
		//call the handle modify method if the settings are restored
		if (restoredFromPreviousSettings){
		    handleModify();
		}
    }
    
    
    private void handleModify(){
    	//Handle the modify event 
    }
    
	public boolean getWizardComplete() {
		return false;
	}
	
	private void fillSrviceSelectionCombo(){
		//Check whether there is IDE configured services in the WSAS services directory
		WSASConfigurationBean.Init();
		IPath wsasInstallationPath = new Path(WSASConfigurationBean.getWsasInstallationPath());
		wsasInstallationPath = wsasInstallationPath.append("repository");
		wsasInstallationPath = wsasInstallationPath.append("services");
		List<IPath> ideConfiguredServices=FileUtils.getDirsOnly(wsasInstallationPath.toOSString());
		//If services are there
		if (ideConfiguredServices.size() != 0) {
			for (Iterator<IPath> iterator = ideConfiguredServices.iterator(); iterator.hasNext();){
				IPath serviPath = (IPath) iterator.next();
				serviceSelectionCombo.add(serviPath.lastSegment());
			}
		}else{
			//TODO : invalidate the wizard by error that no services are available
			//showErrorMessage(ServiceArchiver.getResourceString("wizard.codegen.unknown.error") + "  "+  e.getMessage());
		}
	}

}

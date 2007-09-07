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

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.FileDialog;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;

public class WSASArchiveValidatePage extends AbstractArchiveValidateWizardPage{
	
	Text servicesXMlPathText;
	Text aarPathText;
    public WSASArchiveValidatePage(){
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
        final Composite container = new Composite(parent, SWT.NULL);
        GridLayout lo = new GridLayout(1,true);
        container.setLayout(lo);
        
        Group aarGroup = new Group(container, SWT.NONE);
        aarGroup.setText("Select AAR (Service Archive)");
        GridLayout layout = new GridLayout();
        layout.numColumns = 14;
        aarGroup.setLayout(layout);
        GridData gd = new GridData(GridData.FILL_HORIZONTAL | GridData.VERTICAL_ALIGN_FILL);
        aarGroup.setLayoutData(gd);
        
        aarPathText = new Text(aarGroup,SWT.NONE);
        gd = new GridData(GridData.FILL_HORIZONTAL);
        gd.horizontalSpan=13;
        aarPathText.setLayoutData(gd);
        aarPathText.addModifyListener(new ModifyListener(){
			public void modifyText(ModifyEvent e) {
			}
        });
        
        Button validateAARBrowseButton = new Button(aarGroup,SWT.NONE);
        validateAARBrowseButton.setText("Browse");
        gd = new GridData();
        gd.horizontalSpan = 1;
        validateAARBrowseButton.setLayoutData(gd);
        validateAARBrowseButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				setPathVisible(servicesXMlPathText,false);
				setPathVisible(aarPathText,true);
				handleBrowse(container, aarPathText);
			}     
		}); 
       

        /////////////////////////////////////////////////////////////////////////////////
        
	    Label separator = new Label( container, SWT.NONE);  // Leave some vertical space.
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 1;
	    separator.setText( " " );
	    separator.setLayoutData( gd );
	    
        Group serviceXMLGroup = new Group(container, SWT.NONE);
        serviceXMLGroup.setText("Select Services.xml");
        GridLayout layout1 = new GridLayout();
        layout1.numColumns = 14;
        serviceXMLGroup.setLayout(layout);
        gd = new GridData(GridData.FILL_HORIZONTAL | GridData.VERTICAL_ALIGN_FILL);
        serviceXMLGroup.setLayoutData(gd);
        
        servicesXMlPathText = new Text(serviceXMLGroup,SWT.NONE);
        gd = new GridData(GridData.FILL_HORIZONTAL);
        gd.horizontalSpan=13;
        servicesXMlPathText.setLayoutData(gd);
        servicesXMlPathText.addModifyListener(new ModifyListener(){
			public void modifyText(ModifyEvent e) {
			}
        });
        
        Button validateServicesXmlBrowseButton = new Button(serviceXMLGroup,SWT.NONE);
        validateServicesXmlBrowseButton.setText("Browse");
        gd = new GridData();
        gd.horizontalSpan = 1;
        validateServicesXmlBrowseButton.setLayoutData(gd);
        validateServicesXmlBrowseButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				setPathVisible(servicesXMlPathText,true);
				setPathVisible(aarPathText,false);
				handleBrowse(container, servicesXMlPathText);
			}     
		}); 
        
        setPageComplete(false);
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
	
	/**
	 * Pops up the file browse dialog box
	 */
	private void handleBrowse(Composite parent, Text pathText) {
		
		FileDialog fileDialog = new FileDialog(parent.getShell());
		String fileName = fileDialog.open();
		if (fileName != null) {
			pathText.setText(fileName);
			updateStatus(null);
		}
	}
	
	public void updateWizardPageStatus(String message){
		updateStatus(message);
	}

	public String getServicesXMlPathText() {
		return servicesXMlPathText.getText();
	}

	public String getAarPathText() {
		return aarPathText.getText();
	}
	
	/**
	 * Toggle the path component visibility
	 * @param pathComponemt
	 * @param value
	 */
	public void setPathVisible(Text pathComponemt, boolean value){
		pathComponemt.setEditable(value);
		pathComponemt.setEnabled(value);
	}

}

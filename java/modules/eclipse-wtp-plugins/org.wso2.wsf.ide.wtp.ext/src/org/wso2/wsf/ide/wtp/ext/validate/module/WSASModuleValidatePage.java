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
package org.wso2.wsf.ide.wtp.ext.validate.module;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.DirectoryDialog;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;

public class WSASModuleValidatePage extends AbstractModuleValidateWizardPage{
	
	Text moduleXMlPathText;
	Text marPathText;
   
    public WSASModuleValidatePage(){
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
        
        Group marGroup = new Group(container, SWT.NONE);
        marGroup.setText("Select MAR (Module Archive)");
        GridLayout layout = new GridLayout();
        layout.numColumns = 14;
        marGroup.setLayout(layout);
        GridData gd = new GridData(GridData.FILL_HORIZONTAL | GridData.VERTICAL_ALIGN_FILL);
        marGroup.setLayoutData(gd);
        
        marPathText = new Text(marGroup,SWT.NONE);
        gd = new GridData(GridData.FILL_HORIZONTAL);
        gd.horizontalSpan=13;
        marPathText.setLayoutData(gd);
        marPathText.addModifyListener(new ModifyListener(){
			public void modifyText(ModifyEvent e) {
			}
        });
        
        Button validateMARBrowseButton = new Button(marGroup,SWT.NONE);
        validateMARBrowseButton.setText("Browse");
        gd = new GridData();
        gd.horizontalSpan = 1;
        validateMARBrowseButton.setLayoutData(gd);
        validateMARBrowseButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				handleBrowse(container, marPathText);
			}     
		}); 
       
        Button validateMARButton = new Button(marGroup,SWT.NONE);
        validateMARButton.setText("Validate");
        gd = new GridData();
        gd.horizontalSpan = 1;
        validateMARButton.setLayoutData(gd);
        validateMARButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				//TODO Call validate Mechanism
			}     
		}); 
        
        /////////////////////////////////////////////////////////////////////////////////
        
	    Label separator = new Label( container, SWT.NONE);  // Leave some vertical space.
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 1;
	    separator.setText( " " );
	    separator.setLayoutData( gd );
	    
        Group moduleXMLGroup = new Group(container, SWT.NONE);
        moduleXMLGroup.setText("Select Module.xml");
        GridLayout layout1 = new GridLayout();
        layout1.numColumns = 14;
        moduleXMLGroup.setLayout(layout);
        gd = new GridData(GridData.FILL_HORIZONTAL | GridData.VERTICAL_ALIGN_FILL);
        moduleXMLGroup.setLayoutData(gd);
        
        moduleXMlPathText = new Text(moduleXMLGroup,SWT.NONE);
        gd = new GridData(GridData.FILL_HORIZONTAL);
        gd.horizontalSpan=13;
        moduleXMlPathText.setLayoutData(gd);
        moduleXMlPathText.addModifyListener(new ModifyListener(){
			public void modifyText(ModifyEvent e) {
			}
        });
        
        Button validateServicesXmlBrowseButton = new Button(moduleXMLGroup,SWT.NONE);
        validateServicesXmlBrowseButton.setText("Browse");
        gd = new GridData();
        gd.horizontalSpan = 1;
        validateServicesXmlBrowseButton.setLayoutData(gd);
        validateServicesXmlBrowseButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				handleBrowse(container, moduleXMlPathText);
			}     
		}); 
        
        Button validateModulesXmlButton = new Button(moduleXMLGroup,SWT.NONE);
        validateModulesXmlButton.setText("Validate");
        gd = new GridData();
        gd.horizontalSpan = 1;
        validateModulesXmlButton.setLayoutData(gd);
        validateModulesXmlButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				//TODO Call validate Mechanism
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

	/**
	 * Pops up the file browse dialog box
	 */
	private void handleBrowse(Composite parent, Text pathText) {
		DirectoryDialog fileDialog = new DirectoryDialog(parent.getShell());
		String fileName = fileDialog.open();
		if (fileName != null) {
			pathText.setText(fileName);
		}
	}

}

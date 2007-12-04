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

import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.Path;
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
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;
import org.wso2.wsf.ide.wtp.ext.server.bean.WSASConfigurationBean;
import org.wso2.wsf.ide.wtp.ext.server.constant.WSASMessageConstant;
import org.wso2.wsf.ide.wtp.ext.validate.service.util.WSASUoloadServiceRequestUtil;

public class WSASModuleValidatePage extends AbstractModuleValidateWizardPage{
	
	Text moduleXMlPathText;
	Text marPathText;
	String fileType;
	Button validateMARBrowseButton;
	Button validateModuleXmlBrowseButton;
	Button validateMARRadioButton;
	Button validateModuleXmlRadioButton;
   
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
        GridLayout layout = new GridLayout();
        layout.numColumns = 14;
        container.setLayout(layout);
        GridData gd = new GridData(GridData.FILL_HORIZONTAL | GridData.VERTICAL_ALIGN_FILL);
        container.setLayoutData(gd);
        
        validateMARRadioButton = new Button(container,SWT.RADIO);
        validateMARRadioButton.setText("Select MAR (Module Archive)");
        gd = new GridData();
        gd.horizontalSpan = 14;
        validateMARRadioButton.setLayoutData(gd);
        validateMARRadioButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				setPathVisible(moduleXMlPathText,false);
				setPathVisible(marPathText,true);;
				toggleValidateMAR(true);
			}     
		}); 
        
        marPathText = new Text(container,SWT.BORDER);
        gd = new GridData(GridData.FILL_HORIZONTAL);
        gd.horizontalSpan=13;
        marPathText.setLayoutData(gd);
        marPathText.addModifyListener(new ModifyListener(){
			public void modifyText(ModifyEvent e) {
			}
        });
        
        validateMARBrowseButton = new Button(container,SWT.NONE);
        validateMARBrowseButton.setText("Browse");
        gd = new GridData();
        gd.horizontalSpan = 1;
        validateMARBrowseButton.setLayoutData(gd);
        validateMARBrowseButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				handleBrowse(container, marPathText);
			}     
		}); 
       
        /////////////////////////////////////////////////////////////////////////////////
        
	    Label separator = new Label( container, SWT.NONE);  // Leave some vertical space.
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 1;
	    separator.setText( " " );
	    separator.setLayoutData( gd );
	    
	    validateModuleXmlRadioButton = new Button(container,SWT.RADIO);
	    validateModuleXmlRadioButton.setText("Select Module.xml");
        gd = new GridData();
        gd.horizontalSpan = 14;
        validateModuleXmlRadioButton.setLayoutData(gd);
        validateModuleXmlRadioButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				setPathVisible(moduleXMlPathText,true);
				setPathVisible(marPathText,false);
				toggleValidateModuleXml(true);
			}     
		}); 
        
        moduleXMlPathText = new Text(container,SWT.BORDER);
        gd = new GridData(GridData.FILL_HORIZONTAL);
        gd.horizontalSpan=13;
        moduleXMlPathText.setLayoutData(gd);
        moduleXMlPathText.addModifyListener(new ModifyListener(){
			public void modifyText(ModifyEvent e) {
			}
        });
        
        validateModuleXmlBrowseButton = new Button(container,SWT.NONE);
        validateModuleXmlBrowseButton.setText("Browse");
        gd = new GridData();
        gd.horizontalSpan = 1;
        validateModuleXmlBrowseButton.setLayoutData(gd);
        validateModuleXmlBrowseButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				handleBrowse(container, moduleXMlPathText);
			}     
		}); 
        
        setPageComplete(false);
    	setControl(container);
    	
    	if (!WSASConfigurationBean.isWsasCorrectPathSet() || !WSASConfigurationBean.isWsasStartStatus()){
    		updateStatus(WSASMessageConstant.WARNING_WSAS_NOT_STARTED);
    		toggleControls(false);
    	}else{
    		toggleControls(true);
    		toggleValidateMAR(true);
			setPathVisible(moduleXMlPathText,false);
			setPathVisible(marPathText,true);;
    	}
    	
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
		WSASUoloadServiceRequestUtil uploadUtil = WSASUoloadServiceRequestUtil.getInstance();
		uploadUtil.reset();
		uploadUtil.setModule(true);
		FileDialog fileDialog = new FileDialog(parent.getShell());
		String fileName = fileDialog.open();
		if (fileName != null) {
			pathText.setText(fileName);
			updateStatus(null);
			IPath filePath = new Path(fileName);
			setFileType(filePath.getFileExtension());
			if (fileName.endsWith(".zip")||fileName.endsWith(".jar")||fileName.endsWith(".mar")) {
				WSASModuleValidatePlugin.getDefault().setGoAheadValidation(true);
				uploadUtil.setModule(true);
			}else if(fileName.endsWith(".xml")){
				WSASModuleValidatePlugin.getDefault().setGoAheadValidation(true);
				uploadUtil.setXml(true);
			}else{
				updateStatus("File Type Invalid !!, Valid Types {mar,zip,jar,xml'}");
			}
		}
	}
	
	public void updateWizardPageStatus(String message){
		updateStatus(message);
	}

	public String getModuleXMlPathText() {
		return moduleXMlPathText.getText();
	}

	public String getMarPathText() {
		return marPathText.getText();
	}
	
	public boolean getModuleXMlPathEnabled() {
		return moduleXMlPathText.getEnabled();
	}

	public boolean getMarPathEnabled() {
		return marPathText.getEnabled();
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

	public String getFileType() {
		return fileType;
	}

	public void setFileType(String fileType) {
		this.fileType = fileType;
	}
	
	private void toggleControls(boolean toggleValue){
		setPathVisible(moduleXMlPathText,toggleValue);
		setPathVisible(marPathText, toggleValue);
		validateModuleXmlBrowseButton.setEnabled(toggleValue);
		validateMARBrowseButton.setEnabled(toggleValue);
		validateMARRadioButton.setEnabled(toggleValue);
		validateModuleXmlRadioButton.setEnabled(toggleValue);
	}
	
	private void toggleValidateMAR(boolean toggleValue){
		validateModuleXmlBrowseButton.setEnabled(!toggleValue);
		validateMARBrowseButton.setEnabled(toggleValue);
		validateModuleXmlRadioButton.setSelection(!toggleValue);
		moduleXMlPathText.clearSelection();
		validateMARRadioButton.setSelection(toggleValue);
	}
	
	private void toggleValidateModuleXml(boolean toggleValue){
		validateModuleXmlBrowseButton.setEnabled(toggleValue);
		validateMARBrowseButton.setEnabled(!toggleValue);
		validateModuleXmlRadioButton.setSelection(toggleValue);
		marPathText.clearSelection();
		validateMARRadioButton.setSelection(!toggleValue);
	}

}

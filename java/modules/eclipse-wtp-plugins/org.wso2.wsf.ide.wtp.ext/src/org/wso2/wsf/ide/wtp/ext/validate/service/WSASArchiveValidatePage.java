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

public class WSASArchiveValidatePage extends AbstractArchiveValidateWizardPage{
	
	Text servicesXMlPathText;
	Text aarPathText;
	String fileType;
	Button validateAARBrowseButton;
	Button validateServicesXmlBrowseButton;
	Button validateAARRadioButton;
	Button validateServicesXmlRadioButton;
	
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
        GridLayout layout = new GridLayout();
        layout.numColumns = 14;
        container.setLayout(layout);
        GridData gd = new GridData(GridData.FILL_HORIZONTAL | GridData.VERTICAL_ALIGN_FILL);
        container.setLayoutData(gd);
        
        validateAARRadioButton = new Button(container,SWT.RADIO);
        validateAARRadioButton.setText("Select AAR (Service Archive)");
        gd = new GridData();
        gd.horizontalSpan = 14;
        validateAARRadioButton.setLayoutData(gd);
        validateAARRadioButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				setPathVisible(servicesXMlPathText,false);
				setPathVisible(aarPathText,true);
				toggleValidateAAR(true);
			}     
		}); 
        
        aarPathText = new Text(container,SWT.BORDER);
        gd = new GridData(GridData.FILL_HORIZONTAL);
        gd.horizontalSpan=13;
        aarPathText.setLayoutData(gd);
        aarPathText.addModifyListener(new ModifyListener(){
			public void modifyText(ModifyEvent e) {
			}
        });
        
        validateAARBrowseButton = new Button(container,SWT.NONE);
        validateAARBrowseButton.setText("Browse");
        gd = new GridData();
        gd.horizontalSpan = 1;
        validateAARBrowseButton.setLayoutData(gd);
        validateAARBrowseButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				handleBrowse(container, aarPathText);
			}     
		}); 

        /////////////////////////////////////////////////////////////////////////////////
        
	    Label separator = new Label( container, SWT.NONE);  // Leave some vertical space.
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 1;
	    separator.setText( " " );
	    separator.setLayoutData( gd );
	    
        validateServicesXmlRadioButton = new Button(container,SWT.RADIO);
        validateServicesXmlRadioButton.setText("Select Services.xml");
        gd = new GridData();
        gd.horizontalSpan = 14;
        validateServicesXmlRadioButton.setLayoutData(gd);
        validateServicesXmlRadioButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				setPathVisible(servicesXMlPathText,true);
				setPathVisible(aarPathText,false);
				toggleValidateServicesXml(true);
			}     
		}); 
        
        servicesXMlPathText = new Text(container,SWT.BORDER);
        gd = new GridData(GridData.FILL_HORIZONTAL);
        gd.horizontalSpan=13;
        servicesXMlPathText.setLayoutData(gd);
        servicesXMlPathText.addModifyListener(new ModifyListener(){
			public void modifyText(ModifyEvent e) {
			}
        });
        
        validateServicesXmlBrowseButton = new Button(container,SWT.NONE);
        validateServicesXmlBrowseButton.setText("Browse");
        gd = new GridData();
        gd.horizontalSpan = 1;
        validateServicesXmlBrowseButton.setLayoutData(gd);
        validateServicesXmlBrowseButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				handleBrowse(container, servicesXMlPathText);
			}     
		}); 
        
        setPageComplete(false);
		setControl(container);
		
    	if (!WSASConfigurationBean.isWsasCorrectPathSet() || !WSASConfigurationBean.isWsasStartStatus()){
    		updateStatus(WSASMessageConstant.WARNING_WSAS_NOT_STARTED);
    		toggleControls(false);
    	}else{
    		toggleControls(true);
    		toggleValidateAAR(true);
			setPathVisible(servicesXMlPathText,false);
			setPathVisible(aarPathText,true);
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
		uploadUtil.setService(true);
		FileDialog fileDialog = new FileDialog(parent.getShell());
		String fileName = fileDialog.open();
		if (fileName != null) {
			pathText.setText(fileName);
			updateStatus(null);
			IPath filePath = new Path(fileName);
			setFileType(filePath.getFileExtension());
			if (fileName.endsWith(".zip")||fileName.endsWith(".jar")||fileName.endsWith(".aar")) {
				WSASArchiveValidatePlugin.getDefault().setGoAheadValidation(true);
				uploadUtil.setArchive(true);
			}else if(fileName.endsWith(".xml")){
				WSASArchiveValidatePlugin.getDefault().setGoAheadValidation(true);
				uploadUtil.setXml(true);
			}else{
				updateStatus("File Type Invalid !!, Valid Types {aar,zip,jar,xml'}");
			}
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
	
	public boolean getServicesXMlPathEnabled() {
		return servicesXMlPathText.getEnabled();
	}

	public boolean getAarPathEnabled() {
		return aarPathText.getEnabled();
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
		setPathVisible(aarPathText,toggleValue);
		setPathVisible(servicesXMlPathText, toggleValue);
		validateAARBrowseButton.setEnabled(toggleValue);
		validateServicesXmlBrowseButton.setEnabled(toggleValue);
		validateAARRadioButton.setEnabled(toggleValue);
		validateServicesXmlRadioButton.setEnabled(toggleValue);
	}
	
	private void toggleValidateAAR(boolean toggleValue){
		validateServicesXmlBrowseButton.setEnabled(!toggleValue);
		validateAARBrowseButton.setEnabled(toggleValue);
		validateServicesXmlRadioButton.setSelection(!toggleValue);
		servicesXMlPathText.clearSelection();
		validateAARRadioButton.setSelection(toggleValue);
	}
	
	private void toggleValidateServicesXml(boolean toggleValue){
		validateServicesXmlBrowseButton.setEnabled(toggleValue);
		validateAARBrowseButton.setEnabled(!toggleValue);
		validateAARRadioButton.setSelection(!toggleValue);
		aarPathText.clearSelection();
		validateServicesXmlRadioButton.setSelection(toggleValue);
	}
	
}

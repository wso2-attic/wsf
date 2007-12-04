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
package org.wso2.wsf.ide.wtp.ext.wsdl.converter;

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
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Text;
import org.wso2.wsf.ide.wtp.ext.server.bean.WSASConfigurationBean;
import org.wso2.wsf.ide.wtp.ext.server.constant.WSASMessageConstant;
import org.wso2.wsf.ide.wtp.ext.validate.service.util.WSASUoloadServiceRequestUtil;

public class WSASWSDLConverterPage extends AbstractWSDLConverterWizardPage{
	
	Text wsdlPathText;
	String fileType;
	Button wsdlBrowseButton;
	
    public WSASWSDLConverterPage(){
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
        
        Group wsdlGroup = new Group(container, SWT.NONE);
        wsdlGroup.setText("Please upload your WSDL 1.1");
        GridLayout layout = new GridLayout();
        layout.numColumns = 14;
        wsdlGroup.setLayout(layout);
        GridData gd = new GridData(GridData.FILL_HORIZONTAL | GridData.VERTICAL_ALIGN_FILL);
        wsdlGroup.setLayoutData(gd);
        
        wsdlPathText = new Text(wsdlGroup,SWT.BORDER);
        gd = new GridData(GridData.FILL_HORIZONTAL);
        gd.horizontalSpan=13;
        wsdlPathText.setLayoutData(gd);
        wsdlPathText.addModifyListener(new ModifyListener(){
			public void modifyText(ModifyEvent e) {
			}
        });
        
        wsdlBrowseButton = new Button(wsdlGroup,SWT.NONE);
        wsdlBrowseButton.setText("Upload");
        gd = new GridData();
        gd.horizontalSpan = 1;
        wsdlBrowseButton.setLayoutData(gd);
        wsdlBrowseButton.addSelectionListener( new SelectionAdapter(){
			public void widgetSelected(SelectionEvent e){
				handleBrowse(container);
			}     
		}); 
       
        setPageComplete(false);
		setControl(container);
		
    	if (!WSASConfigurationBean.isWsasCorrectPathSet() || !WSASConfigurationBean.isWsasStartStatus()){
    		updateStatus(WSASMessageConstant.WARNING_WSAS_NOT_STARTED);
    		toggleControls(false);
    	}else{
    		toggleControls(true);
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
	private void handleBrowse(Composite parent) {
		WSASUoloadServiceRequestUtil uploadUtil = WSASUoloadServiceRequestUtil.getInstance();
		uploadUtil.reset();
		FileDialog fileDialog = new FileDialog(parent.getShell());
		String fileName = fileDialog.open();
		if (fileName != null) {
			wsdlPathText.setText(fileName);
			updateStatus(null);
			IPath filePath = new Path(fileName);
			setFileType(filePath.getFileExtension());
			if (fileName.endsWith(".wsdl")||fileName.endsWith(".xml")) {
				WSASWSDLConverterPlugin.getDefault().setGoAheadConvertion(true);
				uploadUtil.setWSDL(true);
			}else{
				updateStatus("File Type Invalid !!, Valid Types {aar,zip,jar,xml'}");
			}
		}
	}
	
	public String getWSDLPathText(){
		return this.wsdlPathText.getText();
	}
	
	public String getFileType() {
		return fileType;
	}

	public void setFileType(String fileType) {
		this.fileType = fileType;
	}
	
	private void toggleControls(boolean toggleValue){
		wsdlPathText.setEnabled(toggleValue);
		wsdlBrowseButton.setEnabled(toggleValue);
	}

}

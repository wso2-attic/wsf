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
package org.wso2.wsf.ide.consumption.ui.preferences;

import java.io.File;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.jface.preference.PreferencePage;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Control;
import org.eclipse.swt.widgets.DirectoryDialog;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.TabFolder;
import org.eclipse.swt.widgets.TabItem;
import org.eclipse.swt.widgets.Text;
import org.eclipse.ui.IWorkbench;
import org.eclipse.ui.IWorkbenchPreferencePage;
import org.wso2.wsf.ide.core.context.Axis2EmitterDefaults;
import org.wso2.wsf.ide.core.context.WSASEmitterContext;
import org.wso2.wsf.ide.core.plugin.WebServiceWSASCorePlugin;
import org.wso2.wsf.ide.core.plugin.data.ServerModel;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.WSASCoreUtils;
import org.wso2.wsf.ide.core.utils.RuntimePropertyUtils;

public class WSASRuntimePreferencePage extends PreferencePage implements
		IWorkbenchPreferencePage {

	private Button browseButton; 
	private Text wsasPath; 
	private Label statusLabel;
	@SuppressWarnings("unused")
	private IStatus status = Status.OK_STATUS;
	private boolean webappExist = false;
	//private boolean isWar = false;
	private String statusBanner = null;
	WSASEmitterContext context;

	  
	protected Control createContents(Composite superparent) {
		status = Status.OK_STATUS;
		context = WebServiceWSASCorePlugin.getDefault().getWSASEmitterContext();
		
		final Composite  mainComp = new Composite( superparent, SWT.NONE );
		
		TabFolder wsasPreferenceTab = new TabFolder(mainComp, SWT.NONE);
		TabItem runtimeInstalLocationItem = new TabItem(wsasPreferenceTab, SWT.NONE);
		runtimeInstalLocationItem.setText(WSASCoreUIMessages.WSAS_RUNTIME);
		runtimeInstalLocationItem.setToolTipText(WSASCoreUIMessages.WSAS_RUNTIME_TOOLTIP);
		
		//-----------------------------WSAS Rintume Location Group------------------------------//
		Group runtimeGroup = new Group(wsasPreferenceTab, SWT.NONE);
		runtimeGroup.setText(WSASCoreUIMessages.WSAS_RUNTIME_LOCATION);
		runtimeInstalLocationItem.setControl(runtimeGroup);
		runtimeGroup.setToolTipText(WSASCoreUIMessages.WSAS_RUNTIME_TOOLTIP);
		
		Label label = new Label( runtimeGroup, SWT.NONE );
		label.setText( WSASCoreUIMessages.WSAS_LOCATION );
		label.setLocation(10,30);
		label.setSize(100,20);
		
		wsasPath = new Text( runtimeGroup, SWT.BORDER );
	    String serverPath = null;
	    if (!(context.getWSASRuntimeLocation()==null)){
	          serverPath = context.getWSASRuntimeLocation();
	          wsasPath.setText(serverPath);
	    }else{
	      //never come here
	    }
	    
		webappExist =runtimeExist(serverPath);
		wsasPath.setLocation(110,30);
		wsasPath.setSize(400, 20);
		wsasPath.addModifyListener( new ModifyListener(){
			public void modifyText(ModifyEvent e){
				 context.setWSASRuntimeLocation( wsasPath.getText() );
				webappExist =runtimeExist(wsasPath.getText());
				status = RuntimePropertyUtils.writeServerPathToPropertiesFile(
						wsasPath.getText());
				if (webappExist) {
					status = Status.OK_STATUS;
					statusUpdate(true);
				}else{
					status = Status.CANCEL_STATUS;
					statusUpdate(false);
				}
			}
		});
		browseButton = new Button( runtimeGroup, SWT.NONE );
		browseButton.setText(WSASCoreUIMessages.LABEL_BROUSE);
		browseButton.setLocation(520,30);
		browseButton.setSize(70, 20);
		browseButton.addSelectionListener( new SelectionAdapter()
		{
			public void widgetSelected(SelectionEvent e)
			{
				handleBrowse(mainComp.getShell());
			}     
		}); 
	
		if(wsasPath.getText().equals(WSASCoreUIMessages.NULL)){
			status = new Status( IStatus.ERROR, 
					"id", 
					0, 
					WSASCoreUIMessages.ERROR_INVALID_WSAS_SERVER_LOCATION, 
					null ); 
		}
		
		
		statusLabel = new Label(runtimeGroup,SWT.BACKGROUND | SWT.READ_ONLY | SWT.CENTER);
		statusLabel.setLocation(20,100);
		statusLabel.setSize(560,40);
		statusLabel.setAlignment(SWT.CENTER);
		
		if (wsasPath.getText().equals("")) {
			statusBanner = WSASCoreUIMessages.LABEL_WSAS_RUNTIME_NOT_EXIT;
		} else if ( !wsasPath.getText().equals("") && (!webappExist)) {
			statusBanner = WSASCoreUIMessages.LABEL_WSAS_RUNTIME_LOAD_ERROR;
		}else{
			statusBanner = WSASCoreUIMessages.LABEL_WSAS_RUNTIME_LOAD;
		}
		statusLabel.setText(statusBanner);
		
		webappExist =runtimeExist(wsasPath.getText());
		
		TabItem codegenPreferencesItem = new TabItem(wsasPreferenceTab, SWT.NONE);
		codegenPreferencesItem.setText(WSASCoreUIMessages.WSAS_PREFERENCES);
		codegenPreferencesItem.setToolTipText(WSASCoreUIMessages.WSAS_PREFERENCES_TOOLTIP);
		
		//--------------------------------WSAS Runtime Preferences------------------------------//
		
		Group codegenGroup = new Group(wsasPreferenceTab, SWT.NONE);
		codegenGroup.setText(WSASCoreUIMessages.WSAS_RUNTIME_PREFERENCES);
		codegenPreferencesItem.setControl(codegenGroup);
		codegenGroup.setToolTipText(WSASCoreUIMessages.WSAS_PREFERENCES_TOOLTIP);
		
		//Service Codegen Options
		Text serviceCodegenLabel = new Text(codegenGroup,SWT.BACKGROUND | SWT.READ_ONLY);
		serviceCodegenLabel.setText( WSASCoreUIMessages.LABEL_WEB_SERVICE_CODEGEN);
		serviceCodegenLabel.setLocation(10,30);
		serviceCodegenLabel.setSize(220,20);
		
		//Data binding
		Label databindingLabel = new Label( codegenGroup, SWT.NONE );
		databindingLabel.setText( WSASCoreUIMessages.LABEL_DATABINDING);
		databindingLabel.setLocation(10,60);
		databindingLabel.setSize(200,20);
		
		final Text databindingText = new Text( codegenGroup,SWT.BORDER );
		databindingText.setText(ServerModel.getServiceDatabinding());
		databindingText.addModifyListener( new ModifyListener() {
			public void modifyText(ModifyEvent e){
				ServerModel.setServiceDatabinding( databindingText.getText() );
			}
		});
		databindingText.setLocation(220,60);
		databindingText.setSize(100,20);
		
		// generate test case option
		final Button testCaseCheckBoxButton = new Button(codegenGroup, SWT.CHECK);
		testCaseCheckBoxButton.setText(WSASCoreUIMessages.LABEL_GENERATE_TESTCASE_CAPTION);
		testCaseCheckBoxButton.setSelection(ServerModel.isServiceTestcase());
		testCaseCheckBoxButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
				ServerModel.setServiceTestcase(testCaseCheckBoxButton.getSelection());
			}

			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});
		testCaseCheckBoxButton.setLocation(10, 90);
		testCaseCheckBoxButton.setSize(300, 15);

		//model.setServerXMLCheck(true);

		//the server side interface option
		final Button generateServerSideInterfaceCheckBoxButton = 
							new Button(codegenGroup, SWT.CHECK);
		generateServerSideInterfaceCheckBoxButton.setText(
				WSASCoreUIMessages.LABEL_GENERATE_SERVERSIDE_INTERFACE);
		generateServerSideInterfaceCheckBoxButton.setSelection(
									ServerModel.isServiceInterfaceSkeleton());
		generateServerSideInterfaceCheckBoxButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
				ServerModel.setServiceInterfaceSkeleton(
						generateServerSideInterfaceCheckBoxButton.getSelection());
			}
			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});
		generateServerSideInterfaceCheckBoxButton.setLocation(10, 120);
		generateServerSideInterfaceCheckBoxButton.setSize(300, 15);

		// generate all
		final Button generateAllCheckBoxButton = new Button(codegenGroup, SWT.CHECK);
		generateAllCheckBoxButton.setSelection(ServerModel.isServiceGenerateAll());
		generateAllCheckBoxButton.setText(WSASCoreUIMessages.LABEL_GENERATE_ALL);
		generateAllCheckBoxButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
				ServerModel.setServiceGenerateAll(generateAllCheckBoxButton.getSelection());
			}
			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});
		generateAllCheckBoxButton.setLocation(10, 150);
		generateAllCheckBoxButton.setSize(350, 15);
		
		///////////////////////////////////////////////////////////////////////////////////////////
		
		//seperator
		Label seperatorLabel0 = new Label( codegenGroup, SWT.SEPARATOR|SWT.BORDER);
		seperatorLabel0.setLocation(10,185);
		seperatorLabel0.setSize(570,1);
		
		///Client Codegen Options
		Text clientCodegenLabel = new Text(codegenGroup,SWT.BACKGROUND | SWT.READ_ONLY);
		clientCodegenLabel.setText( WSASCoreUIMessages.LABEL_WEB_SERVICE_CLIENT_CODEGEN);
		clientCodegenLabel.setLocation(10,200);
		clientCodegenLabel.setSize(220,20);
		
		//Client type label 
		Label clientLabel = new Label(codegenGroup, SWT.HORIZONTAL | SWT.NULL);
		clientLabel.setText(WSASCoreUIMessages.LABEL_CLIENT_SIDE);
		clientLabel.setLocation(10,240);
		clientLabel.setSize(70,20); 
		
		//client side buttons
		final Button syncAndAsyncRadioButton = new Button(codegenGroup, SWT.RADIO);
		syncAndAsyncRadioButton.setText(WSASCoreUIMessages.LABEL_SYNC_AND_ASYNC);
		syncAndAsyncRadioButton.setVisible(true);
		syncAndAsyncRadioButton.setSelection(
				((ServerModel.isAsync() || ServerModel.isSync())==false)
				?true
				:(ServerModel.isAsync() && ServerModel.isSync()));
		syncAndAsyncRadioButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
				ServerModel.setSync(syncAndAsyncRadioButton.getSelection());
				ServerModel.setAsync(syncAndAsyncRadioButton.getSelection());
			}
			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});
		syncAndAsyncRadioButton.setLocation(80,240);
		syncAndAsyncRadioButton.setSize(190,20); 
		
		final Button syncOnlyRadioButton = new Button(codegenGroup, SWT.RADIO);
		syncOnlyRadioButton.setText(WSASCoreUIMessages.LABEL_SYNC);
		syncOnlyRadioButton.setSelection(ServerModel.isSync() && !ServerModel.isAsync() );
		syncOnlyRadioButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
				ServerModel.setSync(syncOnlyRadioButton.getSelection());
				ServerModel.setAsync(!syncOnlyRadioButton.getSelection());
			}
			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});
		syncOnlyRadioButton.setLocation(280,240);
		syncOnlyRadioButton.setSize(170,20); 

		final Button asyncOnlyRadioButton = new Button(codegenGroup, SWT.RADIO);
		asyncOnlyRadioButton.setText(WSASCoreUIMessages.LABEL_ASYNC);
		asyncOnlyRadioButton.setSelection(ServerModel.isAsync() && !ServerModel.isSync());
		asyncOnlyRadioButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
				ServerModel.setAsync(asyncOnlyRadioButton.getSelection());
				ServerModel.setSync(!asyncOnlyRadioButton.getSelection());
			}
			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});
		asyncOnlyRadioButton.setLocation(460,240);
		asyncOnlyRadioButton.setSize(170,20);
		
		//Data binding
		Label clientDatabindingLabel = new Label( codegenGroup, SWT.NONE );
		clientDatabindingLabel.setText( WSASCoreUIMessages.LABEL_DATABINDING);
		clientDatabindingLabel.setLocation(10,270);
		clientDatabindingLabel.setSize(200,20);
		
		final Text databindingText1 = new Text( codegenGroup, SWT.BORDER );
		databindingText1.setText(ServerModel.getCleintDatabinding());
		databindingText1.addModifyListener( new ModifyListener() {
			public void modifyText(ModifyEvent e){
				ServerModel.setWsasServerPath( databindingText1.getText() );
			}
		});
		databindingText1.setLocation(220,270);
		databindingText1.setSize(100,20);
		
		
		// generate test case option
		final Button clientTestCaseCheckBoxButton = new Button(codegenGroup, SWT.CHECK);
		clientTestCaseCheckBoxButton.setText(WSASCoreUIMessages.LABEL_GENERATE_TESTCASE_CAPTION);
		clientTestCaseCheckBoxButton.setSelection(ServerModel.isClientTestcase());
		clientTestCaseCheckBoxButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
				ServerModel.setClientTestcase(clientTestCaseCheckBoxButton.getSelection());
			}

			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});
		clientTestCaseCheckBoxButton.setLocation(10,300);
		clientTestCaseCheckBoxButton.setSize(300, 15);


		// generate all
		final Button clientGenerateAllCheckBoxButton = new Button(codegenGroup, SWT.CHECK);
		clientGenerateAllCheckBoxButton.setSelection(ServerModel.isClientGenerateAll());
		clientGenerateAllCheckBoxButton.setText(WSASCoreUIMessages.LABEL_GENERATE_ALL);
		clientGenerateAllCheckBoxButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
				ServerModel.setClientGenerateAll(clientGenerateAllCheckBoxButton.getSelection());
			}
			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});
		clientGenerateAllCheckBoxButton.setLocation(10, 330);
		clientGenerateAllCheckBoxButton.setSize(400, 15);
		
		///////////////////////////////////////////////////////////////////////////////////////////

		//seperator
		Label seperatorLabel1 = new Label( codegenGroup, SWT.SEPARATOR|SWT.BORDER);
		seperatorLabel1.setLocation(10,365);
		seperatorLabel1.setSize(570,1);
		
		///AAR Options
		Text aarLabel = new Text(codegenGroup,SWT.BACKGROUND | SWT.READ_ONLY);
		aarLabel.setText( WSASCoreUIMessages.LABEL_WEB_SERVICE_AAR);
		aarLabel.setLocation(10,380);
		aarLabel.setSize(220,20);
		
		//aar extention 
		Label aarExtentionLabel = new Label( codegenGroup, SWT.NONE );
		aarExtentionLabel.setText( WSASCoreUIMessages.LABEL_AAR_EXTENTION);
		aarExtentionLabel.setLocation(10,420);
		aarExtentionLabel.setSize(200,20);
		
		final Text aarExtentionText = new Text( codegenGroup, SWT.BORDER);
		aarExtentionText.setText(ServerModel.getAarExtention());
		aarExtentionText.addModifyListener( new ModifyListener() {
			public void modifyText(ModifyEvent e){
				ServerModel.setAarExtention( aarExtentionText.getText() );
			}
		});
		aarExtentionText.setLocation(220,420);
		aarExtentionText.setSize(100,20);
		

		wsasPreferenceTab.setSize(640, 500);
		
	    return mainComp;
	}

	public void init(IWorkbench workbench) {
		// TODO Auto-generated method stub
	}
	
	  
	/**
	 * Pops up the file browse dialog box
	 */
	private void handleBrowse(Shell parent) {
		DirectoryDialog fileDialog = new DirectoryDialog(parent);
		String fileName = fileDialog.open();
		if (fileName != null) {
			wsasPath.setText(fileName);
			ServerModel.setWsasServerPath( wsasPath.getText() );
			boolean status = runtimeExist(wsasPath.getText());
			statusUpdate(status);
		}
	}
	
	private void statusUpdate(boolean status){
		if(statusLabel != null){
			if(!wsasPath.getText().equals("")){
		if (status) {
			statusLabel.setText(WSASCoreUIMessages.LABEL_WSAS_RUNTIME_LOAD);
			this.setErrorMessage(null);
		} else {
			statusLabel.setText(WSASCoreUIMessages.LABEL_WSAS_RUNTIME_LOAD_ERROR);
					//this.setErrorMessage(WSASCoreUIMessages.LABEL_WSAS_RUNTIME_LOAD_ERROR);
		}
			}else{
				statusLabel.setText(WSASCoreUIMessages.LABEL_WSAS_RUNTIME_NOT_EXIT);
			}
		}
	}
	
	private boolean runtimeExist(String path){
		File wsasHomeDir = new File(path);
		if (wsasHomeDir.isDirectory()) {
			String wsasLibPath = WSASCoreUtils.addAnotherNodeToPath(
													wsasHomeDir.getAbsolutePath(),
													WSASCoreUIMessages.DIR_LIB);
			String wsasWebappPath = WSASCoreUtils.addAnotherNodeToPath(
													wsasHomeDir.getAbsolutePath(),
													WSASCoreUIMessages.DIR_CONF);
			if (new File(wsasLibPath).isDirectory() && new File(wsasWebappPath).isDirectory()) {
				statusUpdate(true);
				return true;
			} else {
				String wsasWarPath = WSASCoreUtils.addAnotherNodeToPath(
						path,
						"wsas.war");
				if (new File(wsasWarPath).isFile()) {
					statusUpdate(true);
					return true;
				} else {
					statusUpdate(false);
					return false;
				}
			}
		}else{
			statusUpdate(false);
			return false;
		}
	}
	
}

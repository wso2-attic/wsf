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
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Control;
import org.eclipse.swt.widgets.DirectoryDialog;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.TabFolder;
import org.eclipse.swt.widgets.TabItem;
import org.eclipse.swt.widgets.Text;
import org.eclipse.ui.IWorkbench;
import org.eclipse.ui.IWorkbenchPreferencePage;
import org.wso2.wsf.ide.core.context.WSASEmitterContext;
import org.wso2.wsf.ide.core.plugin.WebServiceWSASCorePlugin;
import org.wso2.wsf.ide.core.plugin.data.ServerModel;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.RuntimePropertyUtils;
import org.wso2.wsf.ide.core.utils.WSASCoreUtils;
import org.wso2.wsf.ide.facet.model.FacetModel;

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
	Combo serviceDatabindingCombo;
	Combo clientDatabindingCombo;

	  
	protected Control createContents(Composite superparent) {
		status = Status.OK_STATUS;
		context = WebServiceWSASCorePlugin.getDefault().getWSASEmitterContext();
		
		final Composite  mainComp = new Composite( superparent, SWT.NONE );
	    mainComp.setLayout( new GridLayout() );
	    mainComp.setLayoutData( new GridData( GridData.FILL_BOTH ) );
		
		TabFolder wsasPreferenceTab = new TabFolder(mainComp, SWT.NONE);
		wsasPreferenceTab.setLayoutData(new GridData(GridData.FILL_BOTH));
		
		//-----------------------------WSAS Rintume Location Group------------------------------//
		TabItem runtimeInstalLocationItem = new TabItem(wsasPreferenceTab, SWT.NONE);
		runtimeInstalLocationItem.setText(WSASCoreUIMessages.WSAS_RUNTIME);
		runtimeInstalLocationItem.setToolTipText(WSASCoreUIMessages.WSAS_RUNTIME_TOOLTIP);

	    final Composite runtimeGroup = new Composite(wsasPreferenceTab, SWT.NONE);
	    
	    runtimeInstalLocationItem.setControl(runtimeGroup);
	    runtimeGroup.setToolTipText(WSASCoreUIMessages.WSAS_RUNTIME_TOOLTIP);
	    
	    GridLayout layout = new GridLayout();
	    
	    layout.numColumns = 3;
	    layout.marginHeight = 10;
	    runtimeGroup.setLayout( layout );
	    runtimeGroup.setLayoutData( new GridData( GridData.FILL_BOTH ) );
		
		Label label = new Label( runtimeGroup, SWT.NONE );
		label.setText( WSASCoreUIMessages.WSAS_LOCATION );
		
		wsasPath = new Text( runtimeGroup, SWT.BORDER );
	    String serverPath = null;
	    if (!(context.getWSASRuntimeLocation()==null)){
	          serverPath = context.getWSASRuntimeLocation();
	          wsasPath.setText(serverPath);
	    }else{
	      //never come here
	    }
	    
		webappExist =runtimeExist(serverPath);
		GridData gd = new GridData(GridData.FILL_HORIZONTAL);

		gd.minimumWidth = 40;
		wsasPath.setLayoutData(gd);
		    
		wsasPath.addModifyListener( new ModifyListener(){
			public void modifyText(ModifyEvent e){
				 context.setWSASRuntimeLocation( wsasPath.getText() );
				webappExist =runtimeExist(wsasPath.getText());
				FacetModel.setCorrectWSASPathSet(webappExist);
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
		
	    Label separator = new Label( runtimeGroup, SWT.NONE);  // Leave some vertical space.
	    
	    gd = new GridData();
	    gd.horizontalSpan = 3;
	    separator.setText( " " );
	    separator.setLayoutData( gd );
		
		statusLabel = new Label(runtimeGroup,SWT.BACKGROUND | SWT.READ_ONLY | SWT.CENTER);
		statusLabel.setAlignment(SWT.CENTER);
	    gd = new GridData();
	    gd.horizontalSpan = 3;
	    gd.horizontalAlignment = GridData.CENTER;
	    statusLabel.setLayoutData( gd );
	    
		if (wsasPath.getText().equals("")) {
			statusBanner = WSASCoreUIMessages.LABEL_WSAS_RUNTIME_NOT_EXIT;
		} else if ( !wsasPath.getText().equals("") && (!webappExist)) {
			statusBanner = WSASCoreUIMessages.LABEL_WSAS_RUNTIME_LOAD_ERROR;
		}else{
			statusBanner = WSASCoreUIMessages.LABEL_WSAS_RUNTIME_LOAD;
		}
		statusLabel.setText(statusBanner);
		
		webappExist =runtimeExist(wsasPath.getText());
		
		//--------------------------------WSAS Runtime Preferences------------------------------//
		
		TabItem codegenPreferencesItem = new TabItem(wsasPreferenceTab, SWT.NONE);
		codegenPreferencesItem.setText(WSASCoreUIMessages.WSAS_PREFERENCES);
		codegenPreferencesItem.setToolTipText(WSASCoreUIMessages.WSAS_PREFERENCES_TOOLTIP);
		
		Composite codegenGroup = new Composite(wsasPreferenceTab, SWT.NONE);
		codegenPreferencesItem.setControl(codegenGroup);
		codegenGroup.setToolTipText(WSASCoreUIMessages.WSAS_PREFERENCES_TOOLTIP);

		layout = new GridLayout();
		codegenGroup.setLayout(layout);
		layout.numColumns = 2;
		layout.marginHeight = 10;
		gd = new GridData(GridData.FILL_BOTH);
		codegenGroup.setLayoutData( gd );

		
		//Service Codegen Options
		Text serviceCodegenLabel = new Text(codegenGroup,SWT.BACKGROUND | SWT.READ_ONLY);
		serviceCodegenLabel.setText( WSASCoreUIMessages.LABEL_WEB_SERVICE_CODEGEN);
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 2;
	    serviceCodegenLabel.setLayoutData(gd);
	    
		//Data binding
		Label databindingLabel = new Label( codegenGroup, SWT.NONE );
		databindingLabel.setText( WSASCoreUIMessages.LABEL_DATABINDING);
		

	    //Data binding items
	    final String[] databindingItems = {context.getServiceDatabinding().toUpperCase()};
	    
	    serviceDatabindingCombo = new Combo(codegenGroup,SWT.DROP_DOWN | SWT.BORDER | SWT.READ_ONLY);
	    serviceDatabindingCombo.setItems(databindingItems);
	    serviceDatabindingCombo.select(0);
	    context.setServiceDatabinding(serviceDatabindingCombo.getItem(0));
	    serviceDatabindingCombo.addSelectionListener(new SelectionAdapter(){
	        public void widgetSelected(SelectionEvent e) {
	          context.setServiceDatabinding(serviceDatabindingCombo
	              .getItem(serviceDatabindingCombo.getSelectionIndex()));
	        }
	    });
		
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
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 2;
	    generateServerSideInterfaceCheckBoxButton.setLayoutData(gd);
	    
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
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 2;
	    generateAllCheckBoxButton.setLayoutData(gd);
	    
		///////////////////////////////////////////////////////////////////////////////////////////
		
	    //seperator
	    Label seperatorLabel0 = new Label( codegenGroup, SWT.SEPARATOR | SWT.HORIZONTAL );
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 2;
	    gd.verticalIndent=5;
	    seperatorLabel0.setLayoutData(gd);
	    
		///Client Codegen Options
		Text clientCodegenLabel = new Text(codegenGroup,SWT.BACKGROUND | SWT.READ_ONLY);
		clientCodegenLabel.setText( WSASCoreUIMessages.LABEL_WEB_SERVICE_CLIENT_CODEGEN);
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 2;
	    gd.verticalIndent=5;
	    clientCodegenLabel.setLayoutData(gd);
	    
		//Client type label 
		Label clientLabel = new Label(codegenGroup, SWT.HORIZONTAL | SWT.NULL);
		clientLabel.setText(WSASCoreUIMessages.LABEL_CLIENT_SIDE);
		
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
	    // Skip a column
	    new Label( codegenGroup, SWT.NONE );
	    
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
	    // Skip a column
	    new Label( codegenGroup, SWT.NONE );
	    
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
	    // Skip a column
	    new Label( codegenGroup, SWT.NONE );
	    
		//Data binding
		Label clientDatabindingLabel = new Label( codegenGroup, SWT.NONE );
		clientDatabindingLabel.setText( WSASCoreUIMessages.LABEL_DATABINDING);
		
	    clientDatabindingCombo = new Combo(codegenGroup,SWT.DROP_DOWN | SWT.BORDER | SWT.READ_ONLY);
	    clientDatabindingCombo.setItems(databindingItems);
	    clientDatabindingCombo.select(0);
	    context.setClientDatabinding(clientDatabindingCombo.getItem(0));
	    clientDatabindingCombo.addSelectionListener(new SelectionAdapter(){
	        public void widgetSelected(SelectionEvent e) {
	            context.setClientDatabinding(clientDatabindingCombo
	                .getItem(clientDatabindingCombo.getSelectionIndex()));
	        }
	    });
		
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
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 2;
	    clientTestCaseCheckBoxButton.setLayoutData(gd);

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
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 2;
	    clientGenerateAllCheckBoxButton.setLayoutData(gd);
	    
		///////////////////////////////////////////////////////////////////////////////////////////

		//seperator
	    Label seperatorLabel11 = new Label( codegenGroup, SWT.SEPARATOR | SWT.HORIZONTAL );
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 2;
	    gd.verticalIndent=5;
	    seperatorLabel11.setLayoutData(gd);
	    
		///AAR Options
		Text aarLabel = new Text(codegenGroup,SWT.BACKGROUND | SWT.READ_ONLY);
		aarLabel.setText( WSASCoreUIMessages.LABEL_WEB_SERVICE_AAR);
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 2;
	    gd.verticalIndent=5;
	    aarLabel.setLayoutData(gd);
	    
		//aar extention 
		Label aarExtentionLabel = new Label( codegenGroup, SWT.NONE );
		aarExtentionLabel.setText( WSASCoreUIMessages.LABEL_AAR_EXTENTION);
		
		final Text aarExtentionText = new Text( codegenGroup, SWT.BORDER);
		aarExtentionText.setText(ServerModel.getAarExtention());
		aarExtentionText.addModifyListener( new ModifyListener() {
			public void modifyText(ModifyEvent e){
				ServerModel.setAarExtention( aarExtentionText.getText() );
			}
		});

	    wsasPreferenceTab.setEnabled(true);
	    wsasPreferenceTab.setVisible(true);
	    
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

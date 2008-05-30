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
import org.wso2.wsf.ide.core.context.WSASEmitterDefaults;
import org.wso2.wsf.ide.core.plugin.WebServiceWSASCorePlugin;
import org.wso2.wsf.ide.core.plugin.data.ServerModel;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.RuntimePropertyUtils;
import org.wso2.wsf.ide.core.utils.WSASCoreUtils;

public class WSASRuntimePreferencePage extends PreferencePage implements
		IWorkbenchPreferencePage {

	private Button browseButton; 
	private Text wsasPath; 
	private Text debugHostText;
	private Text debugPortText;
	private Label statusLabel;
	@SuppressWarnings("unused")
	private IStatus status = Status.OK_STATUS;
	private boolean webappExist = false;
	//private boolean isWar = false;
	private String statusBanner = null;
	WSASEmitterContext context;
	Combo serviceDatabindingCombo;
	Button generateServerSideInterfaceCheckBoxButton;
	Button generateAllCheckBoxButton;
	Combo clientDatabindingCombo;
	Button syncAndAsyncRadioButton;
	Button syncOnlyRadioButton;
	Button asyncOnlyRadioButton;
	Combo aarExtensionCombo;
	Button clientGenerateAllCheckBoxButton;
	Button clientUnpackClassesCheckBoxButton;
	Button clientTestCaseCheckBoxButton;

	  
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
				webappExist = runtimeExist(wsasPath.getText());
				context.setCorrectWSASPathSet(webappExist);
				status = RuntimePropertyUtils.writeServerPathToPropertiesFile(
						wsasPath.getText());
				if (webappExist) {
					status = Status.OK_STATUS;
					statusUpdate(true);
					System.setProperty("wso2wsas.home", wsasPath.getText());
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
		
	    //seperator
	    Label seperatorLabel = new Label( runtimeGroup, SWT.SEPARATOR | SWT.HORIZONTAL );
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 3;
	    gd.verticalIndent=10;
	    seperatorLabel.setLayoutData(gd);
	    
	    //fill label
	    Label fillLabel61 = new Label( runtimeGroup,SWT.HORIZONTAL );
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 3;
	    gd.verticalIndent=10;
	    fillLabel61.setLayoutData(gd);
	    
		//Runtime Configuration settings
		Label runtimeConfigurationLabel = new Label( runtimeGroup, SWT.NONE );
		runtimeConfigurationLabel.setText( WSASCoreUIMessages.WSAS_RUNTIME_CONFIGURATION );
	    gd = new GridData();
	    gd.horizontalSpan = 3;
	    runtimeConfigurationLabel.setLayoutData( gd );
	    
	    //fill label
	    Label fillLabel62 = new Label( runtimeGroup,SWT.HORIZONTAL );
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 3;
	    gd.verticalIndent=10;
	    fillLabel62.setLayoutData(gd);

		//Adding the debug host Label 
		Label debugHostLabel = new Label( runtimeGroup, SWT.NONE );
		debugHostLabel.setText( WSASCoreUIMessages.WSAS_DEBUG_HOST );
		
		//Adding the debug host Text
		debugHostText = new Text(runtimeGroup,SWT.NONE);
		debugHostText.setText( WSASCoreUIMessages.WSAS_DEFAULT_DEBUG_HOST);
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 1;
	    gd.minimumWidth=100;
	    debugHostText.setLayoutData(gd);
	    debugHostText.addModifyListener( new ModifyListener(){
			public void modifyText(ModifyEvent e){
				context.setDebugHost( debugHostText.getText() );
			}
		});
	    
	    Label fillLabel63 = new Label( runtimeGroup,SWT.HORIZONTAL );
	    fillLabel63.setText("");
	    
		//Adding the debug port Label 
		Label debugPortLabel = new Label( runtimeGroup, SWT.NONE );
		debugPortLabel.setText( WSASCoreUIMessages.WSAS_DEBUG_PORT );
		
		//Adding the debug port Text
		debugPortText = new Text(runtimeGroup,SWT.NONE);
		debugPortText.setText( WSASCoreUIMessages.WSAS_DEFAULT_DEBUG_PORT);
		gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 1;
	    gd.minimumWidth=100;
	    debugPortText.setLayoutData(gd);
	    debugPortText.addModifyListener( new ModifyListener(){
			public void modifyText(ModifyEvent e){
				context.setDebuPort( debugPortText.getText() );
			}
		});
	    
		
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
		generateServerSideInterfaceCheckBoxButton = 
							new Button(codegenGroup, SWT.CHECK);
		generateServerSideInterfaceCheckBoxButton.setText(
				WSASCoreUIMessages.LABEL_GENERATE_SERVERSIDE_INTERFACE);
		generateServerSideInterfaceCheckBoxButton.setSelection(
				context.isServiceInterfaceSkeleton());
		generateServerSideInterfaceCheckBoxButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
		        context.setServiceInterfaceSkeleton(
		                generateServerSideInterfaceCheckBoxButton.getSelection());
			}
			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 2;
	    generateServerSideInterfaceCheckBoxButton.setLayoutData(gd);
	    
		// generate all
	    generateAllCheckBoxButton = new Button(codegenGroup, SWT.CHECK);
		generateAllCheckBoxButton.setSelection(context.isServiceGenerateAll());
		generateAllCheckBoxButton.setText(WSASCoreUIMessages.LABEL_GENERATE_ALL);
		generateAllCheckBoxButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
				context.setServiceGenerateAll(generateAllCheckBoxButton.getSelection());
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
		syncAndAsyncRadioButton = new Button(codegenGroup, SWT.RADIO);
		syncAndAsyncRadioButton.setText(WSASCoreUIMessages.LABEL_SYNC_AND_ASYNC);
		syncAndAsyncRadioButton.setVisible(true);
		syncAndAsyncRadioButton.setSelection(
		        ((context.isSync() || context.isAsync())==false)
		        ?true
		        :(context.isSync()) && context.isAsync());
		syncAndAsyncRadioButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
		        context.setAsync(syncAndAsyncRadioButton.getSelection());
		        context.setSync(syncAndAsyncRadioButton.getSelection());
			}
			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});
	    // Skip a column
	    new Label( codegenGroup, SWT.NONE );
	    
	    syncOnlyRadioButton = new Button(codegenGroup, SWT.RADIO);
		syncOnlyRadioButton.setText(WSASCoreUIMessages.LABEL_SYNC);
		syncOnlyRadioButton.setSelection(context.isSync() && !context.isAsync());
		syncOnlyRadioButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
		        context.setAsync(!syncOnlyRadioButton.getSelection());
		        context.setSync(syncOnlyRadioButton.getSelection());
			}
			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});
	    // Skip a column
	    new Label( codegenGroup, SWT.NONE );
	    
	    asyncOnlyRadioButton = new Button(codegenGroup, SWT.RADIO);
		asyncOnlyRadioButton.setText(WSASCoreUIMessages.LABEL_ASYNC);
		asyncOnlyRadioButton.setSelection(context.isAsync() && !context.isSync());
		asyncOnlyRadioButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
		        context.setAsync(asyncOnlyRadioButton.getSelection());
		        context.setSync(!asyncOnlyRadioButton.getSelection());
			}
			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});

	    
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
	    
		// Client Unpack Classes
	    clientUnpackClassesCheckBoxButton = new Button(codegenGroup, SWT.CHECK);
	    clientUnpackClassesCheckBoxButton.setSelection(context.isClientUnpackClasses());
	    clientUnpackClassesCheckBoxButton.setText(WSASCoreUIMessages.LABEL_UNPACK_CLASSES);
	    clientUnpackClassesCheckBoxButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
				context.setClientUnpackClasses(clientUnpackClassesCheckBoxButton.getSelection());
			}
			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 2;
	    clientUnpackClassesCheckBoxButton.setLayoutData(gd);
		
		// generate test case option
	    clientTestCaseCheckBoxButton = new Button(codegenGroup, SWT.CHECK);
		clientTestCaseCheckBoxButton.setText(WSASCoreUIMessages.LABEL_GENERATE_TESTCASE_CAPTION);
		clientTestCaseCheckBoxButton.setSelection(context.isClientTestCase());
		clientTestCaseCheckBoxButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
	            context.setClientTestCase(clientTestCaseCheckBoxButton.getSelection());
			}
			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});
	    gd = new GridData(GridData.FILL_HORIZONTAL);
	    gd.horizontalSpan = 2;
	    clientTestCaseCheckBoxButton.setLayoutData(gd);

		// generate all
	    clientGenerateAllCheckBoxButton = new Button(codegenGroup, SWT.CHECK);
		clientGenerateAllCheckBoxButton.setSelection(context.isClientGenerateAll());
		clientGenerateAllCheckBoxButton.setText(WSASCoreUIMessages.LABEL_GENERATE_ALL);
		clientGenerateAllCheckBoxButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
				context.setClientGenerateAll(clientGenerateAllCheckBoxButton.getSelection());
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
		
	    //AAR extention items
	    final String[] aarExtentionItems = { WSASCoreUIMessages.AAR };

		aarExtensionCombo = new Combo(codegenGroup,SWT.DROP_DOWN | SWT.BORDER | SWT.READ_ONLY);
	    aarExtensionCombo.setItems(aarExtentionItems);
	    aarExtensionCombo.select(0);
	    context.setAarExtention( aarExtensionCombo.getItem(0) );
	    aarExtensionCombo.addSelectionListener(new SelectionAdapter(){
	        public void widgetSelected(SelectionEvent e) {
	            int index = aarExtensionCombo.getSelectionIndex();
	            context.setAarExtention(aarExtensionCombo.getItem(index));
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

	protected void performApply() {
		super.performApply();
	}

	public boolean performCancel() {
		return super.performCancel();
	}

  /**
   * Does anything necessary because the default button has been pressed.
   */
	protected void performDefaults() {
		super.performDefaults();
		initializeDefaults();
	}

	public boolean performOk() {
		return super.performOk();
	}
	
	  /**
	   * Initializes states of the controls using default values
	   * in the preference store.
	   */
	  private void initializeDefaults() {
		serviceDatabindingCombo.select(0);
		generateAllCheckBoxButton.setSelection(WSASEmitterDefaults.isServiceGenerateAll());
		generateServerSideInterfaceCheckBoxButton.setSelection(
									WSASEmitterDefaults.isServiceInterfaceSkeleton());
		syncAndAsyncRadioButton.setSelection(
		        ((WSASEmitterDefaults.isClientSync() || WSASEmitterDefaults.isClientAsync())==false)
		        ?true
		        :(WSASEmitterDefaults.isClientSync()) && WSASEmitterDefaults.isClientAsync());
		syncOnlyRadioButton.setSelection(
				WSASEmitterDefaults.isClientSync() && !WSASEmitterDefaults.isClientAsync());
		asyncOnlyRadioButton.setSelection(
				WSASEmitterDefaults.isClientAsync() && !WSASEmitterDefaults.isClientSync());
		clientTestCaseCheckBoxButton.setSelection(WSASEmitterDefaults.isClientTestCase());
		clientGenerateAllCheckBoxButton.setSelection(WSASEmitterDefaults.isClientTestCase());
		clientUnpackClassesCheckBoxButton.setSelection(WSASEmitterDefaults.isClientUnpackClasses());
		aarExtensionCombo.select(0);
	  }
	

}

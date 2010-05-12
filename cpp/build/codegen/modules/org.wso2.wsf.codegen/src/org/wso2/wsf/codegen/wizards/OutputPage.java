/*
 * Copyright 2005-2009 WSO2, Inc. http://wso2.com
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

package org.wso2.wsf.codegen.wizards;

import org.wso2.wsf.codegen.Activator;
import org.wso2.wsf.codegen.util.UIConstants;
import org.eclipse.core.resources.IWorkspaceRoot;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.Path;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.graphics.Color;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.DirectoryDialog;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;
import org.eclipse.ui.dialogs.ContainerSelectionDialog;

import java.io.File;

public class OutputPage extends AbstractWizardPage {

	private Text outputLocation;
	
	private Text axisHomeLocation;
	
	private Text jarFileNameText;

	private Button browseButton;
	
	private Button axisHomeBrowseButton;
	
	private Button axisLoadLibsButton;
	
	private Button copyLibButton;
	
	private Button jarCreationButton;

	private Button workspaceProjectOptionsButton;

	private Button filesyStemOptionsButton;

	private Button copyPluginLibButton;
	
	private boolean workspaceSaveOption = false;
	
	private boolean jarFileCopyOption = false;
	
	private Label axisHomeLabel;
	
	private Label axisLoadLibResultsLabel;
	
	private Label jarFileNameLabel;
	
	private String axis2LibsLocation = null;
	
	private Label hintLabel;
	
	private Button hintButton;
	
	private boolean hintVisible = false;

	

	/**
	 * 
	 */
	public OutputPage() {
		 super("page2");
	}

	/**
	 * Creates some initial values for the settings. 
	 */
	protected void initializeDefaultSettings() {
		settings.put(PREF_OUTPUT_LOCATION, "");
		settings.put(PREF_AXIS_HOME_OUTPUT_LOCATION, "");
		settings.put(PREF_JAR_FILE_NAME, "");
		settings.put(PREF_CHECK_WORKSPACE, false);
		settings.put(PREF_CHECK_FILE_SYSTEM, true);
		settings.put(PREF_CHECK_AXIS_LIB_COPY, false);
		settings.put(PREF_CHECK_JAR_CREATION, false);
		settings.put(PREF_CHECK_AXIS_PLUGIN_LIB_COPY, false);
		workspaceSaveOption = false;
		jarFileCopyOption = false;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see org.eclipse.jface.dialogs.IDialogPage#createControl(org.eclipse.swt.widgets.Composite)
	 */
	public void createControl(Composite parent) {
		Composite container = new Composite(parent, SWT.NULL);
		GridLayout layout = new GridLayout();
		container.setLayout(layout);
		layout.numColumns = 3;
		layout.verticalSpacing = 9;

		GridData gd = new GridData(GridData.FILL_HORIZONTAL);

		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3;
		Label selectLabel = new Label(container, SWT.NULL);
		selectLabel
				.setText(Activator
						.getResourceString("page2.result.decs"));
		selectLabel.setLayoutData(gd);

		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3;
		workspaceProjectOptionsButton = new Button(container, SWT.RADIO);
		workspaceProjectOptionsButton.setLayoutData(gd);
		workspaceProjectOptionsButton.setText(Activator
				.getResourceString("page2.workspace.caption"));
		workspaceProjectOptionsButton.setToolTipText(Activator
				.getResourceString("page2.workspace.desc"));
		settings.put(PREF_CHECK_WORKSPACE, false);
		settings.put(PREF_CHECK_FILE_SYSTEM, true);
		workspaceProjectOptionsButton.setSelection(settings
				.getBoolean(PREF_CHECK_WORKSPACE));
		workspaceProjectOptionsButton
				.addSelectionListener(new SelectionAdapter() {
					public void widgetSelected(SelectionEvent e) {
						handleCheckboxSelection();
					}
				});

		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3;
		filesyStemOptionsButton = new Button(container, SWT.RADIO);
		filesyStemOptionsButton.setLayoutData(gd);
		filesyStemOptionsButton.setText(Activator
				.getResourceString("page2.filesystem.caption"));
		filesyStemOptionsButton.setToolTipText(Activator
				.getResourceString("page2.filesystem.desc"));
		filesyStemOptionsButton.setSelection(settings
				.getBoolean(PREF_CHECK_FILE_SYSTEM));
		filesyStemOptionsButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				handleCheckboxSelection();
			}
		});

		gd = new GridData(GridData.FILL_HORIZONTAL);
		Label label = new Label(container, SWT.NULL);
		label
				.setText(Activator
						.getResourceString("page2.output.caption"));
		
		settings.put(PREF_OUTPUT_LOCATION, "");
		settings.put(PREF_AXIS_HOME_OUTPUT_LOCATION, "");
		outputLocation = new Text(container, SWT.BORDER);
		outputLocation.setText(settings.get(PREF_OUTPUT_LOCATION));
		outputLocation.setLayoutData(gd);
		outputLocation.addModifyListener(new ModifyListener() {
			public void modifyText(ModifyEvent e) {
				settings.put(PREF_OUTPUT_LOCATION, outputLocation.getText());
				handleModifyEvent();
			}
		});

		browseButton = new Button(container, SWT.PUSH);
		browseButton.setText(Activator
				.getResourceString("page2.outselection.browse"));
		browseButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				handleBrowse();
			}
		});
		
		
		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3;
		copyPluginLibButton = new Button(container, SWT.CHECK);
		copyPluginLibButton.setText(Activator
				.getResourceString("page2.copypluginlib.caption"));
		copyPluginLibButton.setToolTipText(Activator
				.getResourceString("page2.copypluginlib.caption"));
		settings.put(PREF_CHECK_AXIS_PLUGIN_LIB_COPY,false);
		copyPluginLibButton.setSelection(settings.getBoolean(PREF_CHECK_AXIS_PLUGIN_LIB_COPY));
		copyPluginLibButton.setLayoutData(gd);
		copyPluginLibButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				handleCopyPluginLibsCheckBox();
				settings.put(PREF_CHECK_AXIS_PLUGIN_LIB_COPY, copyPluginLibButton.getSelection());
			}
		});
		
		copyPluginLibButton.setEnabled(false);
		
		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan=3;
		Label fillLabel = new Label(container, SWT.NULL);
		fillLabel.setText("");
		
		//filling label 
		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3;
		Label fillLabel1 = new Label(container, SWT.HORIZONTAL | SWT.SEPARATOR);
		fillLabel1.setLayoutData(gd);

		
		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3;
		copyLibButton = new Button(container, SWT.CHECK);
		copyLibButton.setText(Activator
				.getResourceString("page2.addaxislib.caption"));
		copyLibButton.setToolTipText(Activator
				.getResourceString("page2.addaxislib.desc"));
		settings.put(PREF_CHECK_AXIS_LIB_COPY,false);
		copyLibButton.setSelection(settings.getBoolean(PREF_CHECK_AXIS_LIB_COPY));
		copyLibButton.setLayoutData(gd);
		copyLibButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				handlejarCheckBox();
				settings.put(PREF_CHECK_AXIS_LIB_COPY, copyLibButton.getSelection());
			}
		});
		copyLibButton.setEnabled(false);
		
		gd = new GridData(GridData.FILL_HORIZONTAL);
		axisHomeLabel = new Label(container, SWT.NULL);
		axisHomeLabel
				.setText(Activator
						.getResourceString("page2.axishome.caption"));
		
		
		axisHomeLocation = new Text(container, SWT.BORDER);
		axisHomeLocation.setLayoutData(gd);
		settings.put(PREF_AXIS_HOME_OUTPUT_LOCATION, "");
		axisHomeLocation.setText(settings.get(PREF_AXIS_HOME_OUTPUT_LOCATION));
		axisHomeLocation.addModifyListener(new ModifyListener() {
			public void modifyText(ModifyEvent e) {
				settings.put(PREF_AXIS_HOME_OUTPUT_LOCATION, axisHomeLocation.getText());
				handleAxisHomeModifyEvent();
			}
		});

		axisHomeBrowseButton = new Button(container, SWT.PUSH);
		axisHomeBrowseButton.setText(Activator
				.getResourceString("page2.outselection.browse"));
		axisHomeBrowseButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				handleAxisHomeBrowse();
			}
		});
		
		axisLoadLibsButton = new Button(container, SWT.PUSH);
		axisLoadLibsButton.setText(Activator
				.getResourceString("page2.loadlibs.browse"));
		axisLoadLibsButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				handleLoadLibsBrowse();
			}
		});
		
		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 2;
		gd = new GridData(GridData.FILL_HORIZONTAL);
		axisLoadLibResultsLabel = new Label(container, SWT.NULL);
		axisLoadLibResultsLabel	.setText("");
		axisLoadLibResultsLabel.setLayoutData(gd);
		
		//filling label 
		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3;
		Label fillLabel2 = new Label(container, SWT.HORIZONTAL | SWT.SEPARATOR);
		fillLabel2.setLayoutData(gd);
		
		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3;
		jarCreationButton= new Button(container, SWT.CHECK);
		jarCreationButton.setText(Activator
				.getResourceString("page2.jarcreation.caption"));
		jarCreationButton.setToolTipText(Activator
				.getResourceString("page2.jarcreation.desc"));
		settings.put(PREF_CHECK_JAR_CREATION,false);
		jarCreationButton.setSelection(settings.getBoolean(PREF_CHECK_JAR_CREATION));
		jarCreationButton.setLayoutData(gd);
		jarCreationButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				handlejarCreationCheckBox();
//				settings.put(PREF_CHECK_JAR_CREATION, jarCreationButton.getSelection());
			}
		});
		
		gd = new GridData(GridData.FILL_HORIZONTAL);
		jarFileNameLabel = new Label(container, SWT.NULL);
		jarFileNameLabel
				.setText(Activator
						.getResourceString("page2.jarname.caption"));
				
		jarFileNameText = new Text(container, SWT.BORDER);
		jarFileNameText.setLayoutData(gd);
		jarFileNameText.setText(settings.get(PREF_JAR_FILE_NAME));
		jarFileNameText.addModifyListener(new ModifyListener() {
			public void modifyText(ModifyEvent e) {
				settings.put(PREF_JAR_FILE_NAME, jarFileNameText.getText());
//				handleAxisHomeModifyEvent();
			}
		});
		
		//filling label 
		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3;
		Label fillLabel3 = new Label(container, SWT.HORIZONTAL | SWT.SEPARATOR);
		fillLabel3.setLayoutData(gd);
		
		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3; 
		
		hintButton = new Button(container, SWT.PUSH);
		hintButton.setText(Activator
				.getResourceString("page2.hint.off"));
		hintButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				handleHintBrowse();
			}
		});
		
		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3;
		hintLabel = new Label(container, SWT.NULL);
		hintLabel
				.setText(Activator
						.getResourceString("page2.hint.caption"));
		hintLabel.setLayoutData(gd);
		hintLabel.setVisible(hintVisible);
		
		disableControls();
		
		setControl(container);

		/*
		 * Update the buttons, in case this was restored from an earlier setting
		 */
		if (restoredFromPreviousSettings) {
			handleModifyEvent();
		}
	}
	
	private void handleHintBrowse() {
		if (hintVisible) {
			hintButton.setText(Activator
					.getResourceString("page2.hint.off"));
			hintVisible = false;
			hintLabel.setVisible(hintVisible);
		} else {
			hintButton.setText(Activator
					.getResourceString("page2.hint.on"));
			hintVisible = true;
			hintLabel.setVisible(hintVisible);
		}
		
	}

	/**
	 * get the output location
	 * 
	 * @return a string containing the full pathname of the output location
	 */
	public String getOutputLocation() {
		return outputLocation.getText();
	}

	public String getAxisHomeLocation() {
		return axisHomeLocation.getText();
	}
	
	public String getJarFilename() {
		return jarFileNameText.getText();
	}
	
	public boolean getAxis2PluginLibCopyCheckBoxSelection(){
//		return settings.getBoolean(PREF_CHECK_AXIS_PLUGIN_LIB_COPY);
		return this.copyPluginLibButton.getSelection();
	}
	
	public boolean getAxisLibCopyCheckBoxSelection(){
//		return settings.getBoolean(PREF_CHECK_AXIS_LIB_COPY);
		return this.copyLibButton.getSelection();
	}
	
	public boolean getCreateJarCheckBoxSelection(){
//		return settings.getBoolean(PREF_CHECK_JAR_CREATION);
		return jarCreationButton.getSelection();
		
	}
	
	public String getAxisJarsLocation(){
		return this.axis2LibsLocation;
		
	}
	
	public boolean oktoLoadLibs(){
		return this.jarFileCopyOption;
	}
	
	public void setJarFileName(String jarFileName){
		this.jarFileNameText.setText(jarFileName);
	}
	
	/**
	 * Worker method for handling modifications to the textbox
	 * 
	 */
	private void handleModifyEvent() {
		String text = this.outputLocation.getText();
		if ((text == null) || (text.trim().equals(""))) {
			updateStatus(Activator
					.getResourceString("page2.error.nolocation"));
			return;
		}
		updateStatus(null);
	}

	
	private void handleAxisHomeModifyEvent() {
		String text = this.axisHomeLocation.getText();
		if ((text == null) || (text.trim().equals(""))) {
			updateStatus(Activator
					.getResourceString("page2.error.nolocation"));
			return;
		}
		updateStatus(null);
	}
	
//	private void handleJarNameModifyEvent() {
//		String text = this.jarFileNameText.getText();
//		if ((text == null) || (text.trim().equals(""))) {
//			updateStatus(org.apache.axis2.tool.codegen.eclipse.plugin.CodegenWizardPlugin
//					.getResourceString("page2.error.nolocation"));
//			return;
//		}
//		updateStatus(null);
//	}

	private void handleCheckboxSelection() {
		if (workspaceProjectOptionsButton.getSelection()) {
			settings.put(PREF_CHECK_WORKSPACE, true);
			settings.put(PREF_CHECK_FILE_SYSTEM, false);
			workspaceSaveOption = true;
		} else if (filesyStemOptionsButton.getSelection()) {
			settings.put(PREF_CHECK_FILE_SYSTEM, true);
			settings.put(PREF_CHECK_WORKSPACE, false);
			workspaceSaveOption = false;
		}
	}
	
	
	private void handlejarCheckBox() {
		if(copyLibButton.getSelection()){
			enableControls();
			settings.put(PREF_CHECK_AXIS_LIB_COPY, true);
		}else{
			disableControls();
			settings.put(PREF_CHECK_AXIS_LIB_COPY, false);
		}
	}
	
	private void handleCopyPluginLibsCheckBox() {
		if(copyPluginLibButton.getSelection()){
			settings.put(PREF_CHECK_AXIS_PLUGIN_LIB_COPY, true);
		}else{
			settings.put(PREF_CHECK_AXIS_PLUGIN_LIB_COPY, false);
		}
	}
	
	private void handlejarCreationCheckBox() {
		if(jarCreationButton.getSelection()== true){
			settings.put(PREF_CHECK_JAR_CREATION, true);
		}else{
			settings.put(PREF_CHECK_JAR_CREATION, false);
			this.jarFileNameText.setText("");
		}
		if(jarFileNameLabel.equals("")){
			updateStatus("Please enter a valid name to the jar file");
		}
	}
	
	private void disableControls(){
		this.axisHomeLocation.setText("Unpacked Axis2 binary home Or Axis2 source location");
		this.axisHomeBrowseButton.setEnabled(false);
		this.axisHomeLocation.setEnabled(false);
		this.jarCreationButton.setSelection(false);
		this.jarCreationButton.setEnabled(false);
		this.axisHomeLabel.setEnabled(false);
		this.axisLoadLibResultsLabel.setText("");
		this.axisLoadLibResultsLabel.setEnabled(false);
		this.axisLoadLibsButton.setEnabled(false);
		this.jarFileNameLabel.setEnabled(false);
		this.jarFileNameText.setText("");
		this.jarFileNameText.setEnabled(false);
		settings.put(PREF_CHECK_JAR_CREATION, false);
		jarFileCopyOption = false;
		Color color = getShell().getDisplay().getSystemColor(SWT.COLOR_INFO_BACKGROUND);
		axisLoadLibResultsLabel.setBackground(color);
	}
	
	private void enableControls(){
		this.axisHomeBrowseButton.setEnabled(true);
		this.axisHomeLocation.setEnabled(true);
		this.jarCreationButton.setEnabled(true);
		this.axisHomeLabel.setEnabled(true);
		this.axisLoadLibResultsLabel.setEnabled(true);
		this.axisLoadLibsButton.setEnabled(true);
		this.jarFileNameLabel.setEnabled(true);
		this.jarFileNameText.setEnabled(true);
		if (axisLoadLibResultsLabel.getText().equals("")){
			updateStatus("Please enter a valid path to the Axis2 libs and then try to load the libraries using the check libs button");
		}
	     axisLoadLibResultsLabel.setText(Activator
					.getResourceString("page2.loadlib.fail.caption"));
	     Color color = getShell().getDisplay().getSystemColor(SWT.COLOR_RED);
	     axisLoadLibResultsLabel.setBackground(color);
	}
	
	private void handleAxisHomeBrowse() {
		    this.axisHomeLocation.setText("unpacked Axis2 binary home Or Axis2 source Location");
			DirectoryDialog dialog = new DirectoryDialog(this.getShell());
			String returnString = dialog.open();
			if (returnString != null) {
				axisHomeLocation.setText(returnString);
				settings.put(PREF_AXIS_HOME_OUTPUT_LOCATION, axisHomeLocation.getText());
			}
	}
	
	private void handleLoadLibsBrowse() {
		if(axisHomeLocation.getText().equals("")){
			 axisLoadLibResultsLabel.setText(Activator
						.getResourceString("page2.loadlib.fail.caption"));
			 jarFileCopyOption=false;
		     if (axisLoadLibResultsLabel.getText().equals("")){
					updateStatus("Please enter a valid path to the Axis2 libs and then try to load the libraries using the check libs button");
		     }
		}else{
			settings.put(PREF_AXIS_HOME_OUTPUT_LOCATION, axisHomeLocation.getText());
			String axis_home = settings.get(PREF_AXIS_HOME_OUTPUT_LOCATION);
			String axis_target_lib=axis_home+File.separator+UIConstants.TARGET+File.separator+UIConstants.LIB;
			String axis_std_lib_directory=axis_home+File.separator+UIConstants.LIB;

			File axis_target_libs_directory = new File(axis_target_lib);
			File axis_libs_directory = new File(axis_std_lib_directory);
			 if (axis_libs_directory.isDirectory() || axis_target_libs_directory.isDirectory()) {
				 axisLoadLibResultsLabel.setText(Activator
							.getResourceString("page2.loadlib.success.caption"));
				if(axis_libs_directory.isDirectory()){
					axis2LibsLocation=axis_std_lib_directory;
				}
				else if(axis_target_libs_directory.isDirectory()){
					axis2LibsLocation=axis_target_lib;
				}
				 jarFileCopyOption =true;
				 Color color = getShell().getDisplay().getSystemColor(SWT.COLOR_INFO_BACKGROUND);
				 axisLoadLibResultsLabel.setBackground(color);
			 }else{
			     axisLoadLibResultsLabel.setText(Activator
							.getResourceString("page2.loadlib.fail.caption"));
			     Color color = getShell().getDisplay().getSystemColor(SWT.COLOR_RED);
			     axisLoadLibResultsLabel.setBackground(color);
			     updateStatus(Activator
						.getResourceString("page2.loadlib.fail.message"));
			     jarFileCopyOption=false;
			 }
		}
	}

	
	/**
	 * Handle the browse button events: opens a dialog where the user can choose
	 * an external directory location
	 * 
	 */
	private void handleBrowse() {
		// Change this to add the clarity of 2 option buttions
		// boolean location = locationSelectCheckBox.getSelection();
		boolean location = false;
		if(settings.getBoolean(PREF_CHECK_FILE_SYSTEM)){
			location = false;
		}else if(settings.getBoolean(PREF_CHECK_WORKSPACE)){
			location = true;
		}

		if (workspaceSaveOption) {
			location = true;
		}

		if (!location) {
			DirectoryDialog dialog = new DirectoryDialog(this.getShell());
			String returnString = dialog.open();
			if (returnString != null) {
				outputLocation.setText(returnString);
			}
		} else {
			IWorkspaceRoot root = ResourcesPlugin.getWorkspace().getRoot();

			ContainerSelectionDialog dialog = new ContainerSelectionDialog(
					getShell(), root, false, Activator
							.getResourceString("page2.containerbox.title"));
			if (dialog.open() == ContainerSelectionDialog.OK) {
				Object[] result = dialog.getResult();
				if (result.length == 1) {
					Path path = ((Path) result[0]);
					// append to the workspace path
					if (root.exists(path)) {
						outputLocation.setText(root.getLocation().append(path)
								.toFile().getAbsolutePath());
					}
				}
			}
		}

	}
	
	public void enableLangDependentControls(){
		this.copyPluginLibButton.setEnabled(true);
		this.copyLibButton.setEnabled(true);
	}
	public void disableLangDependentControls(){
		this.copyPluginLibButton.setSelection(false);
		this.copyLibButton.setSelection(false);
		this.copyPluginLibButton.setEnabled(false);
		this.copyLibButton.setEnabled(false);
	}
}

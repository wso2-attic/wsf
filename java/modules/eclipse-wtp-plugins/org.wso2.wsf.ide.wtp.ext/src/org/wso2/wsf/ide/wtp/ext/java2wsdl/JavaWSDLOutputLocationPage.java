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
package org.wso2.wsf.ide.wtp.ext.java2wsdl;

import java.io.File;

import org.eclipse.core.resources.IWorkspaceRoot;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.Path;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.DirectoryDialog;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;
import org.eclipse.ui.dialogs.ContainerSelectionDialog;

public class JavaWSDLOutputLocationPage extends AbstractJAVA2WSDLWizardPage {

	private Text outputFolderTextBox;
	private Text outputFileNameTextBox;
	private Button workspaceProjectOptionsButton;
	private Button filesyStemOptionsButton;
	private boolean workspaceSaveOption = false;


	public JavaWSDLOutputLocationPage() {
		super("page3");
	}

	/* (non-Javadoc)
	 * @see org.apache.axis2.tool.codegen.eclipse.ui.AbstractWizardPage#initializeDefaultSettings()
	 */
	protected void initializeDefaultSettings() {
		settings.put(PREF_JAVA_OUTPUT_WSDL_LOCATION, "");
		settings.put(JAVA_OUTPUT_WSDL_NAME, "services.wsdl");
		settings.put(PREF_JAVA_OUTPUT_FILESYATEM, true);
		settings.put(PREF_JAVA_OUTPUT_WORKSPACE, false);
	}

	/* (non-Javadoc)
	 * @see org.apache.axis2.tool.codegen.eclipse.ui.AbstractWizardPage#getPageType()
	 */
	public int getPageType() {
		return JAVA_2_WSDL_TYPE;
	}

	/* (non-Javadoc)
	 * @see org.eclipse.jface.dialogs.IDialogPage#createControl(org.eclipse.swt.widgets.Composite)
	 */
	public void createControl(Composite parent) {
		Composite container = new Composite(parent, SWT.NULL);
		GridLayout layout = new GridLayout();
		layout.numColumns = 3;
		container.setLayout(layout);

		GridData gd = new GridData(GridData.FILL_HORIZONTAL);

		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3;
		Label selectLabel = new Label(container, SWT.NULL);
		selectLabel.setText(WSASJAVA2WSDLPlugin
						.getResourceString("Select the location where to put the output"));
		selectLabel.setLayoutData(gd);

		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3;
		workspaceProjectOptionsButton = new Button(container, SWT.RADIO);
		workspaceProjectOptionsButton.setLayoutData(gd);
		workspaceProjectOptionsButton.setText(WSASJAVA2WSDLPlugin
				.getResourceString("page3.workspace.caption"));
		workspaceProjectOptionsButton.setToolTipText(WSASJAVA2WSDLPlugin
				.getResourceString("page3.workspace.desc"));
		workspaceProjectOptionsButton.setSelection(settings
				.getBoolean(PREF_JAVA_OUTPUT_WORKSPACE));
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
		filesyStemOptionsButton.setText(WSASJAVA2WSDLPlugin
				.getResourceString("page3.filesystem.caption"));
		filesyStemOptionsButton.setToolTipText(WSASJAVA2WSDLPlugin
				.getResourceString("page3.filesystem.desc"));
		filesyStemOptionsButton.setSelection(settings
				.getBoolean(PREF_JAVA_OUTPUT_FILESYATEM));
		filesyStemOptionsButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				handleCheckboxSelection();
			}
		});

		Label label1 = new Label(container, SWT.NULL);
		label1.setText(WSASJAVA2WSDLPlugin
				.getResourceString("page3.output.label"));

		gd = new GridData(GridData.FILL_HORIZONTAL);
		outputFolderTextBox = new Text(container, SWT.BORDER);
		outputFolderTextBox.setLayoutData(gd);
		outputFolderTextBox.setText("");
		outputFolderTextBox.addModifyListener(new ModifyListener() {
			public void modifyText(ModifyEvent e) {
				handleFolderTextChange();
			}
		});

		Button browseButton = new Button(container, SWT.PUSH);
		browseButton.setText(WSASJAVA2WSDLPlugin
				.getResourceString("general.browse"));
		browseButton.addSelectionListener(new SelectionListener() {
			public void widgetSelected(SelectionEvent e) {
				handleBrowse();
			}

			public void widgetDefaultSelected(SelectionEvent e) {
			}
		});

		Label label = new Label(container, SWT.NULL);
		label.setText(WSASJAVA2WSDLPlugin
				.getResourceString("page3.outputname.label"));

		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 2;
		outputFileNameTextBox = new Text(container, SWT.BORDER);
		outputFileNameTextBox.setLayoutData(gd);
		outputFileNameTextBox.setText(settings.get(JAVA_OUTPUT_WSDL_NAME));
		outputFileNameTextBox.addModifyListener(new ModifyListener() {
			public void modifyText(ModifyEvent e) {
				handleFileNameTextChange();
			}
		});

		if (restoredFromPreviousSettings) {
			handleFolderTextChange();
			handleFolderTextChange();
		}
		
		setPageComplete(false);
		setControl(container);

	}

	private void handleCheckboxSelection() {
		if (workspaceProjectOptionsButton.getSelection()) {
			settings.put(PREF_JAVA_OUTPUT_WORKSPACE, true);
			settings.put(PREF_JAVA_OUTPUT_FILESYATEM, false);
			workspaceSaveOption = true;
		} else if (filesyStemOptionsButton.getSelection()) {
			settings.put(PREF_JAVA_OUTPUT_FILESYATEM, true);
			settings.put(PREF_JAVA_OUTPUT_WORKSPACE, false);
			workspaceSaveOption = false;
		}
	}

	private void handleFolderTextChange() {
		String outputFolder = outputFolderTextBox.getText();
		settings.put(PREF_JAVA_OUTPUT_WSDL_LOCATION, outputFolder);
		if ("".equals(outputFolder.trim())) {
			updateStatus("Input a proper location for the output");
		} else {
			updateStatus(null);
		}
	}

	private void handleFileNameTextChange() {
		String outFileName = outputFileNameTextBox.getText();
		settings.put(JAVA_OUTPUT_WSDL_NAME, outFileName);
		if ("".equals(outFileName.trim())) {
			updateStatus("Input a file name");
		} else if (outFileName.matches("\\W")) {
			updateStatus("Input a valid file name");
		} else if (!(outFileName.endsWith(".wsdl") || outFileName.endsWith(".xml")) ) {
			updateStatus("Input a valid file name , Example : services.wsdl or services.xml");
		} else {
			updateStatus(null);
		}
	}

	private void handleBrowse() {
		boolean location = false;
		if(settings.getBoolean(PREF_JAVA_OUTPUT_FILESYATEM)){
			location = false;
		}else if(settings.getBoolean(PREF_JAVA_OUTPUT_WORKSPACE)){
			location = true;
		}
		if (workspaceSaveOption) {
			location = true;
		}
		if (!location) {
			DirectoryDialog dialog = new DirectoryDialog(this.getShell());
			String returnString = dialog.open();
			if (returnString != null) {
				outputFolderTextBox.setText(returnString);
			}
		} else {
			IWorkspaceRoot root = ResourcesPlugin.getWorkspace().getRoot();

			ContainerSelectionDialog dialog = new ContainerSelectionDialog(
					getShell(), root, false, WSASJAVA2WSDLPlugin
							.getResourceString("page3.containerbox.title"));
			if (dialog.open() == ContainerSelectionDialog.OK) {
				Object[] result = dialog.getResult();
				if (result.length == 1) {
					Path path = ((Path) result[0]);
					// append to the workspace path
					if (root.exists(path)) {
						outputFolderTextBox.setText(root.getLocation().append(
								path).toFile().getAbsolutePath());
					}
				}
			}
		}

	}

	public String getFullFileName() {
		String folder = this.outputFolderTextBox.getText();
		String fileName = this.outputFileNameTextBox.getText();
		if (!fileName.endsWith(".wsdl")) {
			fileName = fileName + ".wsdl";
		}
		return folder + File.separator + fileName;
	}

	public String getOutputWSDLName() {
		return this.outputFileNameTextBox.getText();
	}

	public String getOutputLocation() {
		return this.outputFolderTextBox.getText();
	}

}

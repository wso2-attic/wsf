
package org.wso2.wsf.wtp.consumption.ui.preferences;

import java.io.File;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.jface.preference.PreferencePage;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
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
import org.wso2.wsf.wtp.core.plugin.data.ServerModel;
import org.wso2.wsf.wtp.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.wtp.core.utils.RuntimePropertyUtils;
import org.wso2.wsf.wtp.core.utils.WSASCoreUtils;

public class WSASRuntimePreferencePage extends PreferencePage implements
		IWorkbenchPreferencePage {

	private Button browseButton; 
	private Text wsasPath; 
	Label statusLabel;
	private IStatus status = Status.OK_STATUS;

	  
	protected Control createContents(Composite superparent) {
		status = Status.OK_STATUS;
		
		final Composite  mainComp = new Composite( superparent, SWT.NONE );
		
		TabFolder wsasPreferenceTab = new TabFolder(mainComp, SWT.NONE);
		TabItem runtimeInstalLocationItem = new TabItem(wsasPreferenceTab, SWT.NONE);
		runtimeInstalLocationItem.setText("WSAS Runtime");
		
		Group group = new Group(wsasPreferenceTab, SWT.NONE);
		group.setText("WSAS Rintume Location");
		runtimeInstalLocationItem.setControl(group);
		
		Label label = new Label( group, SWT.NONE );
		label.setText( WSASCoreUIMessages.WSAS_LOCATION );
		label.setLocation(10,30);
		label.setSize(100,20);
		
		wsasPath = new Text( group, SWT.BORDER );
		wsasPath.setText("");
		wsasPath.setLocation(110,30);
		wsasPath.setSize(400, 20);
		wsasPath.addModifyListener( new ModifyListener()
		{
			public void modifyText(ModifyEvent e)
			{
				ServerModel.setWSASServerPath( wsasPath.getText() );
				boolean warExist =runtimeExist(wsasPath.getText());
				if (warExist) {
					status = RuntimePropertyUtils.writeServerPathToPropertiesFile(
																wsasPath.getText());
				}
			}
		});
		browseButton = new Button( group, SWT.NONE );
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
		
		
		statusLabel = new Label( group, SWT.NONE );
		statusLabel.setLocation(20,100);
		statusLabel.setSize(560,40);
		statusLabel.setAlignment(SWT.CENTER);
		
		
		
		TabItem codegenPreferencesItem = new TabItem(wsasPreferenceTab, SWT.NONE);
		codegenPreferencesItem.setText("Codegen Preferences");
		
		

		wsasPreferenceTab.setSize(600, 300);
		
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
			ServerModel.setWSASServerPath( wsasPath.getText() );
		}
	}
	
	private void statusUpdate(boolean status){
		if (status) {
			statusLabel.setText(WSASCoreUIMessages.LABEL_WSAS_RUNTIME_LOAD);
		} else {
			statusLabel.setText(WSASCoreUIMessages.LABEL_WSAS_RUNTIME_LOAD_ERROR);
		}
		
	}
	
	private boolean runtimeExist(String path){
		File wsasHomeDir = new File(path);
		if (wsasHomeDir.isDirectory()) {
			String wsasDistPath = WSASCoreUtils.addAnotherNodeToPath(
													wsasHomeDir.getAbsolutePath(),
													"dist");
			if (new File(wsasDistPath).isDirectory()) {
				String wsasWarPath = WSASCoreUtils.addAnotherNodeToPath(
						wsasDistPath,
						"wsas.war");
				if (new File(wsasWarPath).isFile()) {
					statusUpdate(true);
					return true;
				} else {
					statusUpdate(false);
					return false;
				}
			} else {
				statusUpdate(false);
				return false;
			}
		}else{
			statusUpdate(false);
			return false;
		}
	}
	
}

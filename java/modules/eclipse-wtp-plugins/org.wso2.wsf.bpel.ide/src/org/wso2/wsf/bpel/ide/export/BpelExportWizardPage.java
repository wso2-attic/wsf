package org.wso2.wsf.bpel.ide.export;

import java.io.File;

import org.eclipse.jface.wizard.WizardPage;
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
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.swt.widgets.Text;

public class BpelExportWizardPage extends WizardPage {
	private String fileLocation;
	private Text deployInWorkspaceText;
	
	protected BpelExportWizardPage(String pageName) {
		super(pageName);
		setTitle("Bpel export path");
		setDescription("Path to export the bpel artifact");
	}

	public void createControl(Composite parent) {
		Composite container = new Composite(parent, SWT.NULL);
		GridLayout layout = new GridLayout();
		container.setLayout(layout);
		layout.numColumns = 3;
		layout.verticalSpacing = 9;
		GridData gd;
		Label label;	
		
		label=new Label(container,SWT.NULL);
		gd = new GridData(GridData.FILL_HORIZONTAL);
//		gd.horizontalSpan = 3;
		label.setLayoutData(gd);
		label.setText("Export location");
		

		deployInWorkspaceText = new Text(container, SWT.BORDER | SWT.SINGLE);
		gd = new GridData(GridData.FILL_HORIZONTAL);
		deployInWorkspaceText.setLayoutData(gd);
		deployInWorkspaceText.addModifyListener(new ModifyListener() {
			public void modifyText(ModifyEvent e) {
				handleDeployInWorkspaceText();
			}
		});
		
		Button deployInWorkspaceBrowseButton = new Button(container, SWT.PUSH);
		deployInWorkspaceBrowseButton.setText("Browse");
		deployInWorkspaceBrowseButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				handledeployInWorkspaceBrowseButton();
			}
		});
		
		deployInWorkspaceText.setText("");
		setControl(parent);
	}

	protected void handledeployInWorkspaceBrowseButton() {
		String fileName=getSavePath();
		if (fileName!=null)
			deployInWorkspaceText.setText(fileName);		
	}

	protected void handleDeployInWorkspaceText() {
		this.setFileLocation(deployInWorkspaceText.getText());
		String msg=null;
		File file = new File(getFileLocation());
		if ((file.getParentFile()==null)||(!file.getParentFile().exists()))
			msg="Invalid path specified";
		if (msg==null){
			if (!getFileLocation().substring(getFileLocation().length()-4).toLowerCase().endsWith(".zip"))
				msg="Invalid file extension. File extension should be zip.";
		}
		setErrorMessage(msg);
		setPageComplete(msg==null);
	}

	private String getSavePath(){
		String fileName = null;
		FileDialog dlg = new FileDialog(getShell());
		dlg.setFilterExtensions(new String[]{".zip"});
	    boolean done = false;

	    while (!done) {
	      // Open the File Dialog
	      fileName = dlg.open();
	      if (fileName == null) {
	        // User has cancelled, so quit and return
	        done = true;
	      } else {
	        // User has selected a file; see if it already exists
	        File file = new File(fileName);
	        if (file.exists()) {
	          // The file already exists; asks for confirmation
	          MessageBox mb = new MessageBox(dlg.getParent(), SWT.ICON_WARNING
	              | SWT.YES | SWT.NO);

	          // We really should read this string from a
	          // resource bundle
	          mb.setMessage(fileName + " already exists. Do you want to replace it?");

	          // If they click Yes, we're done and we drop out. If
	          // they click No, we redisplay the File Dialog
	          done = mb.open() == SWT.YES;
	        } else {
	          // File does not exist, so drop out
	          done = true;
	        }
	      }
	    }
	    return fileName;
	}

	public void setFileLocation(String fileLocation) {
		this.fileLocation = fileLocation;
	}

	public String getFileLocation() {
		return fileLocation;
	}
}

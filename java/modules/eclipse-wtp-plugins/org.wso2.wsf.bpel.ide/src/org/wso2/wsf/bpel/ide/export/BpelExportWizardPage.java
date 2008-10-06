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
import org.eclipse.swt.widgets.DirectoryDialog;
import org.eclipse.swt.widgets.FileDialog;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.swt.widgets.Text;

public class BpelExportWizardPage extends WizardPage {
	private String fileLocation;
	private Text deployInWorkspaceText;
	private String archiveName;
	
	protected BpelExportWizardPage(String pageName,String archiveName) {
		super(pageName);
		setTitle("Bpel export path");
		setDescription("Path to export the bpel artifact");
		this.archiveName=archiveName;
	}

	public void createControl(Composite parent) {
		Composite container = new Composite(parent, SWT.NULL);
		GridLayout layout = new GridLayout();
		container.setLayout(layout);
		layout.numColumns = 3;
		layout.verticalSpacing = 5;
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
		String fileName=getSavePath(archiveName);
		if (fileName!=null)
			deployInWorkspaceText.setText(fileName);		
	}

	protected void handleDeployInWorkspaceText() {
		this.setFileLocation(deployInWorkspaceText.getText());
		String msg=null;
		File file = new File(getFileLocation());
		if ((!file.exists())||(file.isFile()))
			msg="Invalid path specified.";
		if (msg==null){
			File bpelArchive = new File(file,archiveName);
        	if (bpelArchive.exists()) {
        		setDescription(archiveName+" already exists in the path specified. If you continue the file will be overwritten.");
        	}else
        		setDescription("Path to export the bpel artifact");
		}
		setErrorMessage(msg);
		setPageComplete(msg==null);
	}

	private String getSavePath(String archive){
		String fileName = null;
		DirectoryDialog dlg = new DirectoryDialog(getShell());
		
	    boolean done = false;

	    while (!done) {
	      fileName = dlg.open();
	      if (fileName == null) {
	        done = true;
	      } else {
	        File file = new File(fileName);
	        if (!file.exists()) {
	          MessageBox mb = new MessageBox(dlg.getParent(), SWT.ICON_ERROR);
	          mb.setMessage(fileName + " does not exists.");
	        } else {
	        	File bpelArchive = new File(file,archive);
	        	if (bpelArchive.exists()) {
	                MessageBox mb = new MessageBox(dlg.getParent(), SWT.ICON_WARNING
	                    | SWT.YES | SWT.NO);
	                mb.setMessage(archive + " already exists. Do you want to replace it?");
	        	    done = mb.open() == SWT.YES;
	        	}else
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
	
	public String getArchiveFileName(){
		return (new File(fileLocation,archiveName)).getAbsolutePath();
	}
}

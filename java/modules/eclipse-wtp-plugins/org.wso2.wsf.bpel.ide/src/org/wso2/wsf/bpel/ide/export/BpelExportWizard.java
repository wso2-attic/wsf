package org.wso2.wsf.bpel.ide.export;

import java.io.File;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.Iterator;
import java.util.List;

import org.eclipse.core.resources.IProject;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.jface.operation.IRunnableWithProgress;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.IExportWizard;
import org.eclipse.ui.IWorkbench;
import org.wso2.wsf.bpel.ide.utils.BpelConstants;
import org.wso2.wsf.bpel.ide.utils.BpelUtils;
import org.wso2.wsf.bpel.ide.utils.FileManagementUtil;

public class BpelExportWizard extends Wizard implements IExportWizard{
	private BpelExportWizardPage mainPage;
	private IStructuredSelection selection;
	private IProject selectedProject;
	private String archiveName;
	
	@Override
	public boolean performFinish() {
		IRunnableWithProgress op = new IRunnableWithProgress() {
			public void run(IProgressMonitor monitor) throws InvocationTargetException {
				try {
					doFinish(monitor);
				} catch (Exception e) {
					throw new InvocationTargetException(e);
				} finally {
					monitor.done();
				}
			}
		};
		try {
			getContainer().run(true, false, op);
		} catch (InterruptedException e) {
			return false;
		} catch (InvocationTargetException e) {
			Throwable realException = e.getTargetException();
			realException.printStackTrace();
			if (realException.getMessage().trim().equalsIgnoreCase(""))
				MessageDialog.openError(getShell(), "Error", "Error occured while deploying the data service");
			else
				MessageDialog.openError(getShell(), "Error", realException.getMessage());
			return false;
		}
		MessageDialog.openInformation(getShell(), "BPEL Process", "Bpel archive deployed successfully.");
		
		return true;	
	}

	public void init(IWorkbench arg0, IStructuredSelection arg1) {
		this.selection=arg1;
		if (selection.getFirstElement() instanceof IProject){
			selectedProject=(IProject)selection.getFirstElement();
			archiveName=selectedProject.getName()+BpelConstants.BPEL_ARCHIVE_EXTENSION;
		}else
			archiveName="";
	}
	public void addPages() {
		super .addPages();
		
		mainPage = new BpelExportWizardPage("Bpel Export",archiveName);
		addPage(mainPage);
	}
	private void doFinish(IProgressMonitor monitor) throws Exception {
		int a;
		a=10;
		if (selectedProject!=null){
			selectedProject=(IProject)selection.getFirstElement();
			monitor.beginTask("Determining whether the selected is a bpel project...", 100);
			if (!BpelUtils.isProjectContainsBpel(selectedProject)){
				throw new Exception("The selected project does not contain any bpel processes.");
			}
			String path = selectedProject.getLocation().toOSString();
			monitor.worked(10);
			monitor.setTaskName("Listing project artifacts...");
			List allFilesPresentInFolder = FileManagementUtil.getAllFilesPresentInFolder(new File(path));
			printList(allFilesPresentInFolder);
			monitor.worked(25);
			monitor.setTaskName("Filtering out non bpel artifacts...");
			List bpelValidFileList = BpelUtils.getBpelValidFileList(path,(String[]) allFilesPresentInFolder.toArray(new String[allFilesPresentInFolder.size()]));
			printList(bpelValidFileList);
			monitor.worked(40);
			File tempFolder = null;
			try {
				tempFolder = File.createTempFile("temp",".tmp");
				tempFolder.delete();
				tempFolder.mkdir();
				File zipFolder=new File(tempFolder,selectedProject.getName());
				File tmpZip=File.createTempFile("temp",".tmp");
				tmpZip.delete();
				//tmpZip.deleteOnExit();
				System.out.println(tempFolder.getAbsolutePath());
				System.out.println(tmpZip.getAbsolutePath());

				monitor.setTaskName("Creating tje bpel artifact...");
				FileManagementUtil.copyDirectory(new File(path), zipFolder, bpelValidFileList);
				monitor.worked(55);
				FileManagementUtil.removeEmptyDirectories(zipFolder);
				monitor.worked(60);
				FileManagementUtil.zipFolder(tempFolder.getAbsolutePath(), tmpZip.getAbsolutePath());
				monitor.worked(75);
				if (tmpZip.exists()){
					monitor.setTaskName("Exporting the artifact...");
					String deployableZip = mainPage.getArchiveFileName(); //FileManagementUtil.addNodesToPath(PersistentWSASEmitterContext.getInstance().getWSASRuntimeLocation(),new String[]{"repository", "bpel",p.getName()+".zip"});
					File deployedZip = new File(deployableZip);
					FileManagementUtil.copy(tmpZip, deployedZip);
					monitor.worked(100);
					monitor.done();
					if (deployedZip.exists())
						return;
					else
						throw new Exception("Could export the bpel archive.");	
				}else
					throw new Exception("Unable to create the bpel archive.");
			} catch (IOException e) {
				throw e;
			}finally{
				//FileManagementUtil.deleteDirectories(tempFolder);
			}
		}
	}
	private void printList(List list){
		for (Iterator iterator = list.iterator(); iterator.hasNext();) {
			String s = (String) iterator.next();
			//System.out.println(s);
			
		}
	}
}
                
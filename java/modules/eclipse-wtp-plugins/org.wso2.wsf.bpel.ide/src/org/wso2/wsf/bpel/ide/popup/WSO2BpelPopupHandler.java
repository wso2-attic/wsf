package org.wso2.wsf.bpel.ide.popup;

import java.io.File;
import java.io.IOException;
import java.util.List;

import org.eclipse.core.internal.resources.Project;
import org.eclipse.jface.action.IAction;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.TreeSelection;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.ui.IObjectActionDelegate;
import org.eclipse.ui.IWorkbenchPart;
import org.eclipse.ui.internal.ObjectPluginAction;
import org.wso2.wsf.bpel.ide.utils.BpelUtils;
import org.wso2.wsf.bpel.ide.utils.FileManagementUtil;

public class WSO2BpelPopupHandler implements IObjectActionDelegate {
	private Shell shell;
	public void setActivePart(IAction arg0, IWorkbenchPart arg1) {
		shell = arg1.getSite().getShell();
	}

	@SuppressWarnings("restriction")
	public void run(IAction arg0) {
		try{
			if (arg0 instanceof ObjectPluginAction){
				ObjectPluginAction obj=(ObjectPluginAction)arg0;
				if (obj.getSelection() instanceof TreeSelection){
					TreeSelection tree=(TreeSelection)obj.getSelection();
					if (tree.getFirstElement() instanceof Project){
						Project p=(Project)tree.getFirstElement();
						if (!BpelUtils.isProjectContainsBpel(p)){
							MessageDialog.openError(shell, "BPEL Process", "The selected project does not contain any bpel processes.");
							return;
						}
//						if (!WSASConfigurationBean.isWsasStartStatus()){
//							MessageDialog.openError(shell, "BPEL Process", "WSAS IDE instance is not running.");
//							return;
//						}
						String path = p.getLocation().toOSString();
						
						List allFilesPresentInFolder = FileManagementUtil.getAllFilesPresentInFolder(new File(path));
						List bpelValidFileList = BpelUtils.getBpelValidFileList(path,(String[]) allFilesPresentInFolder.toArray(new String[allFilesPresentInFolder.size()]));
						try {
							File tempFolder = File.createTempFile("temp",".tmp");
							tempFolder.delete();
							tempFolder.mkdir();
							File zipFolder=new File(tempFolder,p.getName());
							File tmpZip=File.createTempFile("temp",".tmp");
							tmpZip.delete();
							tmpZip.deleteOnExit();
							FileManagementUtil.copyDirectory(new File(path), zipFolder, bpelValidFileList);
							FileManagementUtil.removeEmptyDirectories(zipFolder);
							FileManagementUtil.zipFolder(tempFolder.getAbsolutePath(), tmpZip.getAbsolutePath());
							if (tmpZip.exists()){
//								String deployableZip = FileManagementUtil.addNodesToPath(PersistentWSASEmitterContext.getInstance().getWSASRuntimeLocation(),new String[]{"repository", "bpel",p.getName()+".zip"});
//								File deployedZip = new File(deployableZip);
//								FileManagementUtil.copy(tmpZip, deployedZip);
//								if (deployedZip.exists())
//									MessageDialog.openInformation(shell, "BPEL Process", "Bpel archive deployed successfully.");
//								else
//									MessageDialog.openError(shell, "BPEL Process", "Couldbpel archive file.");	
							}else
								MessageDialog.openError(shell, "BPEL Process", "Unable to create the bpel archive file.");
							FileManagementUtil.deleteDirectories(tempFolder);
						} catch (IOException e) {
							MessageDialog.openError(shell, "BPEL Process", "Unable to create the bpel archive file.");
							e.printStackTrace();
						}
					}
				}
			}
		}catch(Exception ex){
			MessageDialog.openError(shell, "BPEL Process", ex.getLocalizedMessage());
		}
	}

	public void selectionChanged(IAction arg0, ISelection arg1) {
	}

}

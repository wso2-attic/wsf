/*******************************************************************************
 * Copyright (c) 2007 WSO2 Inc. and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 * WSO2 Inc. - initial API and implementation
 * yyyymmdd bug      Email and other contact information
 * -------- -------- -----------------------------------------------------------
 * 20070118   168762 sandakith@wso2.com - Lahiru Sandakith, Initial code to introduse the Axis2 runtime to the framework for 168762
 *******************************************************************************/
package org.wso2.wsf.wtp.ws.creation.core.utils;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Path;
import org.eclipse.core.runtime.Status;
import org.eclipse.jst.ws.internal.plugin.WebServicePlugin;
import org.eclipse.osgi.util.NLS;
import org.eclipse.wst.command.internal.env.core.common.StatusUtils;
import org.eclipse.wst.command.internal.env.core.context.ResourceContext;
import org.eclipse.wst.common.environment.IStatusHandler;
import org.wso2.wsf.wtp.ws.creation.core.messages.WSASCreationUIMessages;

public class ContentCopyUtils {

	private List fileAndDirectoriesList = new ArrayList();
	FileInputStream finStream = null;		

	/**
	 * This method will copy the source directory into the eclipse workspace according to the Eclipse Framework API
	 * @param sourceDir
	 * @param destinationDir
	 * @param monitor
	 * @param statusHandler
	 * @return
	 */
	public IStatus copyDirectoryRecursivelyIntoWorkspace(String sourceDir, String destinationDir,IProgressMonitor monitor,IStatusHandler statusHandler) {
		IStatus status = Status.OK_STATUS;
		fileAndDirectoriesList.clear();
		File axis2WebappFolder = new File(sourceDir);
		visitAllDirsAndFiles(axis2WebappFolder);
		List deployFiles = new ArrayList();
		deployFiles= fileAndDirectoriesList;

		try {

			//Import the axis2 dependency plugin according to the Resources API of eclipse 
			ResourceContext context = WebServicePlugin.getInstance().getResourceContext();	

			IPath outputPath = new Path (destinationDir);

			String fileName;
			IPath targetPath=null;
			boolean isDirectory = false;

			String deployFile;
			Iterator iterator;

			String tempOutputDir = axis2WebappFolder.toString();
			iterator = deployFiles.iterator();
			while (iterator.hasNext()) {
				deployFile = (String) iterator.next();
				File source = new File(deployFile);
				if (source.isDirectory()) {
					isDirectory =true;
				}else{
					isDirectory=false;
					finStream = new FileInputStream(source);
				}

				if (deployFile.startsWith(tempOutputDir)) {
					fileName = deployFile.substring(tempOutputDir.length());
					targetPath = outputPath.append(fileName).makeAbsolute();
					if (isDirectory){
						org.eclipse.wst.command.internal.env.common.FileResourceUtils.makeFolderPathAtLocation(context,  
								targetPath,
								monitor,
								statusHandler);
					}else{
						if (finStream != null) {
							org.eclipse.wst.command.internal.env.common.FileResourceUtils.createFileAtLocation(context,  
									targetPath,
									finStream,
									monitor,
									statusHandler);
						}
						finStream.close();
					}
				}
			}
		} catch (IOException e) {
			status = StatusUtils.errorStatus(NLS.bind(WSASCreationUIMessages.ERROR_INVALID_FILE_READ_WRITEL,new String[]{e.getLocalizedMessage()}), e);
		} catch (CoreException e) {
			status = StatusUtils.errorStatus(NLS.bind(WSASCreationUIMessages.ERROR_INVALID_FILE_READ_WRITEL,new String[]{e.getLocalizedMessage()}), e);
		}

		return status;

	}

	//	Process all files and directories under dir
	private void visitAllDirsAndFiles(File dir) {

		fileAndDirectoriesList.add(dir.getAbsolutePath());

		if (dir.isDirectory()) {
			String[] children = dir.list();
			for (int i=0; i<children.length; i++) {
				visitAllDirsAndFiles(new File(dir, children[i]));
			}
		}
	}

}

package org.wso2.wsf.wtp.ws.creation.ui.command;

import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Path;
import org.eclipse.core.runtime.Status;
import org.eclipse.jdt.core.IClasspathEntry;
import org.eclipse.jdt.core.IJavaProject;
import org.eclipse.jdt.core.JavaCore;
import org.eclipse.jdt.core.JavaModelException;
import org.eclipse.wst.common.frameworks.datamodel.AbstractDataModelOperation;

public class WSASChengeBuildPathCommand extends AbstractDataModelOperation {
	
	private IProject project;
	private String srcDir;
	private String outDir;
	
	public WSASChengeBuildPathCommand(IProject project, String srcDir, String outDir) {
		this.project = project;
		this.srcDir = srcDir;
		this.outDir = outDir;
	}

	public IStatus execute(IProgressMonitor monitor, IAdaptable info)
				   throws ExecutionException {
		
		IPath srcPath = new Path(srcDir);
		IPath outPath = new Path(outDir);
		
		IStatus status = Status.OK_STATUS;
		final IJavaProject jproj = JavaCore.create(project);
        final IClasspathEntry[] cp = {JavaCore.newSourceEntry(srcPath)};

        try {
			jproj.setRawClasspath(cp, outPath, null);
			jproj.save(null, true);
		} catch (JavaModelException e) {
			e.printStackTrace();
		}
		return status;
	}

}

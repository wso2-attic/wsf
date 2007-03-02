package org.wso2.wsas.wtp.facet.deligate;

import org.eclipse.core.resources.IProject;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.wst.common.project.facet.core.IDelegate;
import org.eclipse.wst.common.project.facet.core.IProjectFacetVersion;

public class WSASExtFacetInstallDelegate implements IDelegate {

	public void execute(IProject arg0, IProjectFacetVersion arg1, Object arg2,
			IProgressMonitor arg3) throws CoreException {
			//TODO This will include the more requirements that needed to be automated
			//	   when we cover the other RFE s in future.
	}
}

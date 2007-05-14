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
package org.wso2.wsf.ide.creation.core.command;

//import org.apache.xerces.impl.validation.ValidationManager;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.resources.IncrementalProjectBuilder;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.NullProgressMonitor;
import org.eclipse.core.runtime.OperationCanceledException;
import org.eclipse.core.runtime.Status;
import org.eclipse.core.runtime.jobs.Job;
import org.eclipse.wst.common.frameworks.datamodel.AbstractDataModelOperation;

public class WSASBuildProjectCommand extends
		AbstractDataModelOperation {
	
//	  private ValidationManager validationManager;
	  private IProject project;
	  private boolean forceBuild;

	  /**
	   * Default CTOR;
	   */
	  public WSASBuildProjectCommand(){
	  }
	  
	  public WSASBuildProjectCommand(IProject project){
		  this.project = project;
	  }
	  
	  public WSASBuildProjectCommand(IProject project, boolean forceBuild){
		  this.project = project;
		  this.forceBuild = forceBuild;
	  }

	  /**
	   * Execute the command
	   */
	  public IStatus execute( IProgressMonitor monitor, IAdaptable adaptable )
	  {
	    try
	    {
	      if (forceBuild)
	        project.build(IncrementalProjectBuilder.INCREMENTAL_BUILD, new NullProgressMonitor());
//	      else if (validationManager == null)
//	        project.build(IncrementalProjectBuilder.INCREMENTAL_BUILD, new NullProgressMonitor());
//	      else if (validationManager.getWorkspaceAutoBuildPreference())
//	        project.build(IncrementalProjectBuilder.INCREMENTAL_BUILD, new NullProgressMonitor());
	    }
	    catch (Exception e){
	    }
	    
	    try{
	     Job.getJobManager().join(ResourcesPlugin.FAMILY_AUTO_BUILD,
  		  		new NullProgressMonitor());   
	    }
	    catch (InterruptedException ie){
	      // continue execution
	    }
	    catch (OperationCanceledException oce){
	      // continue execution
	    }
	    
	    return Status.OK_STATUS;
	  }
	  /**
	   * @param forceBuild The forceBuild to set.
	   */
	  public void setForceBuild(boolean forceBuild) {
	    this.forceBuild = forceBuild;
	  }

	  /**
	   * @param project The project to set.
	   */
	  public void setProject(IProject project) {
	    this.project = project;
	  }

//	  /**
//	   * @param validationManager The validationManager to set.
//	   */
//	  public void setValidationManager(ValidationManager validationManager) {
//	    this.validationManager = validationManager;
//	  }

}

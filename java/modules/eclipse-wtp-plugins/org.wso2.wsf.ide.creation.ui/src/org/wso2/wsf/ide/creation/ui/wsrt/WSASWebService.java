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
package org.wso2.wsf.ide.creation.ui.wsrt;

import java.util.Vector;

import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.wst.command.internal.env.core.ICommandFactory;
import org.eclipse.wst.command.internal.env.core.SimpleCommandFactory;
import org.eclipse.wst.common.environment.IEnvironment;
import org.eclipse.wst.ws.internal.wsrt.AbstractWebService;
import org.eclipse.wst.ws.internal.wsrt.IContext;
import org.eclipse.wst.ws.internal.wsrt.ISelection;
import org.eclipse.wst.ws.internal.wsrt.WebServiceInfo;
import org.eclipse.wst.ws.internal.wsrt.WebServiceScenario;
import org.wso2.wsf.ide.creation.core.command.WSASBUCommand;
import org.wso2.wsf.ide.creation.core.command.WSASBUServiceCreationCommand;
import org.wso2.wsf.ide.creation.core.command.WSASBuildProjectCommand;
import org.wso2.wsf.ide.creation.core.command.WSASCleanupCommand;
import org.wso2.wsf.ide.creation.core.command.WSASDefaultingCommand;
import org.wso2.wsf.ide.creation.core.command.WSASServiceInstallCommand;
import org.wso2.wsf.ide.creation.core.command.WSASServicesXMLValidationCommand;
import org.wso2.wsf.ide.creation.core.command.WSASSkelImplCommand;
import org.wso2.wsf.ide.creation.core.command.WSASTDCommand;
import org.wso2.wsf.ide.creation.core.command.WSASTDServiceCreationCommand;
import org.wso2.wsf.ide.creation.core.command.WSASWSDL2JavaCommand;
import org.wso2.wsf.ide.creation.core.command.WSASWebservicesServerCommand;
import org.wso2.wsf.ide.creation.core.data.DataModel;

public class WSASWebService extends AbstractWebService {
	
	DataModel model;
	public WSASWebService(WebServiceInfo info){
		super(info);
	}

	public ICommandFactory assemble(IEnvironment env, IContext ctx,
			ISelection sel, String project, String earProject) 	{
		return null;
	}

	public ICommandFactory deploy(IEnvironment env, IContext ctx, ISelection sel,
			String project, String earProject) {
		Vector commands = new Vector();
		commands.add(new WSASServiceInstallCommand(model, this, project,ctx.getScenario().getValue()));
		if (ctx.getScenario().getValue() == WebServiceScenario.BOTTOMUP)	{ 
			// Do nothing yet
		} else if (ctx.getScenario().getValue() == WebServiceScenario.TOPDOWN) {
			commands.add(new WSASCleanupCommand());
		} else {
			return null;
		}

		return new SimpleCommandFactory(commands);
	}

	public ICommandFactory develop(IEnvironment env, IContext ctx, ISelection sel,
			String project, String earProject)	{
		Vector commands = new Vector();
		model = new DataModel();

		model.setWebProjectName(project);
		
		if (ctx.getScenario().getValue() == WebServiceScenario.BOTTOMUP)	{ 
			commands.add(new WSASDefaultingCommand( model,this, ctx.getScenario().getValue() ) );
			commands.add(new WSASBUCommand( model ) );
			commands.add(new WSASServicesXMLValidationCommand());
			commands.add(new WSASBUServiceCreationCommand(model,this,project));
			commands.add(new WSASWebservicesServerCommand(model, ctx.getScenario().getValue() ));
		} else if (ctx.getScenario().getValue() == WebServiceScenario.TOPDOWN) {  
			commands.add(new WSASDefaultingCommand( model,this, ctx.getScenario().getValue()  ) );
			commands.add(new WSASTDCommand( model) );
			commands.add(new WSASWSDL2JavaCommand( model) );
			commands.add( new WSASBuildProjectCommand(
						ResourcesPlugin.getWorkspace().getRoot().getProject(project),true));
			commands.add(new WSASTDServiceCreationCommand(model,this,project));
			commands.add(new WSASWebservicesServerCommand(model, ctx.getScenario().getValue()));
			//yes, again invoke the build command to redeploy the service after complete full build
			commands.add( new WSASBuildProjectCommand(
						ResourcesPlugin.getWorkspace().getRoot().getProject(project),true));
			commands.add(new WSASSkelImplCommand(this.getWebServiceInfo(),model));
			commands.add(new WSASServiceInstallCommand(model, this, project,ctx.getScenario().getValue()));
			commands.add(new WSASCleanupCommand());
		} 
		else {
			return null;
		}

		return new SimpleCommandFactory(commands);
	}

	public ICommandFactory install(IEnvironment env, IContext ctx, ISelection sel,
			String project, String earProject)	{
		return null;
	}

	public ICommandFactory run(IEnvironment env, IContext ctx, ISelection sel,
			String project, String earProject)	{
		return null;
	}
}

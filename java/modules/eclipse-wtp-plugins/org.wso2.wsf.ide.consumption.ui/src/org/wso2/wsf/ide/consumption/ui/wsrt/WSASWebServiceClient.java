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
package org.wso2.wsf.ide.consumption.ui.wsrt;

import java.util.Vector;

import org.eclipse.wst.command.internal.env.core.ICommandFactory;
import org.eclipse.wst.command.internal.env.core.SimpleCommandFactory;
import org.eclipse.wst.command.internal.env.core.data.DataMappingRegistry;
import org.eclipse.wst.command.internal.env.eclipse.EclipseEnvironment;
import org.eclipse.wst.common.environment.IEnvironment;
import org.eclipse.wst.ws.internal.wsrt.AbstractWebServiceClient;
import org.eclipse.wst.ws.internal.wsrt.IContext;
import org.eclipse.wst.ws.internal.wsrt.ISelection;
import org.eclipse.wst.ws.internal.wsrt.WebServiceClientInfo;
import org.wso2.wsf.ide.consumption.core.command.WSASClientCodegenCommand;
import org.wso2.wsf.ide.consumption.core.command.WSASClientDefaultingCommand;
import org.wso2.wsf.ide.consumption.core.command.WSASWebservicesServerCommand;
import org.wso2.wsf.ide.consumption.core.data.DataModel;
import org.wso2.wsf.ide.consumption.ui.task.DefaultsForHTTPBasicAuthCommand;

public class WSASWebServiceClient extends AbstractWebServiceClient {

	public WSASWebServiceClient(WebServiceClientInfo info) {
		super(info);
	}

	public ICommandFactory assemble(IEnvironment env, IContext ctx,
			ISelection arg2, String arg3, String arg4) {
		return null;
	}

	public ICommandFactory deploy(IEnvironment env, IContext ctx,
			ISelection arg2, String arg3, String arg4) {
		return null;
	}

	public ICommandFactory develop(IEnvironment env, IContext ctx,
			ISelection sel, String project, String earProject) {
		DataModel model = new DataModel();
		
		EclipseEnvironment environment = (EclipseEnvironment)env;
		registerDataMappings( environment.getCommandManager().getMappingRegistry());
		model.setWebProjectName(project);
		Vector commands = new Vector();
		commands.add(new WSASClientDefaultingCommand(model,this));
		commands.add(new WSASWebservicesServerCommand(model, project));
		commands.add(new WSASClientCodegenCommand(model));
		
		return new SimpleCommandFactory(commands);
	}

	public ICommandFactory install(IEnvironment env, IContext ctx,
			ISelection sel, String project, String earProject) {
		return null;
	}

	public ICommandFactory run(IEnvironment env, IContext ctx,
			ISelection sel, String project, String earProject) {
		return null;
	}

	public void registerDataMappings(DataMappingRegistry registry){
		// AxisClientDefaultingCommand
		registry.addMapping(WSASClientDefaultingCommand.class, 
							"WsdlURL", 
							DefaultsForHTTPBasicAuthCommand.class,
							"WsdlServiceURL", null); //OK

	}

}

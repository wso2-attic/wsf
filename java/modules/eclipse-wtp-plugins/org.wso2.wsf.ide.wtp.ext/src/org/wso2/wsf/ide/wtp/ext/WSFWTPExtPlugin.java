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
package org.wso2.wsf.ide.wtp.ext;

import org.eclipse.ui.plugin.AbstractUIPlugin;
import org.osgi.framework.BundleContext;
import org.wso2.wsf.ide.wtp.ext.dumpaar.WSASDumpAARPlugin;
import org.wso2.wsf.ide.wtp.ext.java2wsdl.WSASJAVA2WSDLPlugin;
import org.wso2.wsf.ide.wtp.ext.server.bean.WSASConfigurationBean;
import org.wso2.wsf.ide.wtp.ext.server.command.WSASStopCommand;
import org.wso2.wsf.ide.wtp.ext.validate.module.WSASModuleValidatePlugin;
import org.wso2.wsf.ide.wtp.ext.validate.service.WSASArchiveValidatePlugin;
import org.wso2.wsf.ide.wtp.ext.wsdl.converter.WSASWSDLConverterPlugin;

/**
 * The activator class controls the plug-in life cycle
 */
public class WSFWTPExtPlugin extends AbstractUIPlugin {
	
	private final int WSAS_STOP_TIME_GAP = 1000;

	// The plug-in ID
	public static final String PLUGIN_ID = "org.wso2.wsf.ide.wtp.ext";

	// The shared instance
	private static WSFWTPExtPlugin plugin;
	
	/**
	 * The constructor
	 */
	public WSFWTPExtPlugin() {
	}

	/*
	 * (non-Javadoc)
	 * @see org.eclipse.ui.plugin.AbstractUIPlugin#start(org.osgi.framework.BundleContext)
	 */
	public void start(BundleContext context) throws Exception {
		super.start(context);
		WSASDumpAARPlugin.getDefault().start(context);
		WSASJAVA2WSDLPlugin.getDefault().start(context);
		WSASArchiveValidatePlugin.getDefault().start(context);
		WSASModuleValidatePlugin.getDefault().start(context);
		WSASWSDLConverterPlugin.getDefault().start(context);
		plugin = this;
	}

	/*
	 * (non-Javadoc)
	 * @see org.eclipse.ui.plugin.AbstractUIPlugin#stop(org.osgi.framework.BundleContext)
	 */
	public void stop(BundleContext context) throws Exception {
		plugin = null;
		super.stop(context);
		//Stop WSAS Server if already running 
		if(WSASConfigurationBean.isWsasStartStatus()){
			WSASStopCommand.run();
			Thread.sleep(WSAS_STOP_TIME_GAP);
		}
		WSASDumpAARPlugin.getDefault().stop(context);
		WSASJAVA2WSDLPlugin.getDefault().stop(context);
		WSASArchiveValidatePlugin.getDefault().stop(context);
		WSASModuleValidatePlugin.getDefault().stop(context);
		WSASWSDLConverterPlugin.getDefault().stop(context);
	}

	/**
	 * Returns the shared instance
	 *
	 * @return the shared instance
	 */
	public static WSFWTPExtPlugin getDefault() {
		return plugin;
	}
	
}

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
package org.wso2.wsf.ide.core.plugin;

import org.eclipse.core.runtime.Plugin;
import org.osgi.framework.BundleContext;
import org.wso2.wsf.ide.core.context.PersistentWSASEmitterContext;
import org.wso2.wsf.ide.core.context.WSASEmitterContext;

/**
 * The activator class controls the plug-in life cycle
 */
public class WebServiceWSASCorePlugin extends Plugin {

	// The plug-in ID
	public static final String PLUGIN_ID = "org.wso2.wsf.ide.core";

	// The shared instance
	private static WebServiceWSASCorePlugin plugin;
	
	private PersistentWSASEmitterContext wsasEmitterContext_;
	
	/**
	 * The constructor
	 */
	public WebServiceWSASCorePlugin() {
		plugin = this;
	}

	/*
	 * (non-Javadoc)
	 * @see org.eclipse.core.runtime.Plugins#start(org.osgi.framework.BundleContext)
	 */
	public void start(BundleContext context) throws Exception {
		super.start(context);
	}

	/*
	 * (non-Javadoc)
	 * @see org.eclipse.core.runtime.Plugin#stop(org.osgi.framework.BundleContext)
	 */
	public void stop(BundleContext context) throws Exception {
		plugin = null;
		super.stop(context);
	}

	/**
	 * Returns the shared instance
	 *
	 * @return the shared instance
	 */
	public static WebServiceWSASCorePlugin getDefault() {
		return plugin;
	}
	
	public WSASEmitterContext getWSASEmitterContext(){
		if (wsasEmitterContext_ == null) 
			wsasEmitterContext_ = PersistentWSASEmitterContext.getInstance();
		return wsasEmitterContext_;
	}

}

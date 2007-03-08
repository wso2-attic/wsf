package org.wso2.wsf.wtp.ws.creation.core.plugin;

import org.eclipse.core.runtime.Plugin;
import org.osgi.framework.BundleContext;

/**
 * The activator class controls the plug-in life cycle
 */
public class WebServiceWSASCreationCorePlugin extends Plugin {

	// The plug-in ID
	public static final String PLUGIN_ID = "org.wso2.wsf.wtp.ws.creation.core.plugin";

	// The shared instance
	private static WebServiceWSASCreationCorePlugin plugin;
	
	/**
	 * The constructor
	 */
	public WebServiceWSASCreationCorePlugin() {
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
	public static WebServiceWSASCreationCorePlugin getDefault() {
		return plugin;
	}

}

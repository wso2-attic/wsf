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
 * 20070213  168766 sandakith@wso2.com - Lahiru Sandakith, Initial code to introduse the Axis2 
 * 										  facet to the framework for 168766
 *******************************************************************************/
package org.wso2.wsas.wtp.facet.plugin;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.ui.plugin.AbstractUIPlugin;
import org.osgi.framework.BundleContext;

/**
 * The activator class controls the plug-in life cycle
 */
public class WSASFacetPlugin extends AbstractUIPlugin {

	// The plug-in ID
	public static final String PLUGIN_ID = "org.wso2.wsf.wtp.facet";

	// The shared instance
	private static WSASFacetPlugin plugin;
	
	/**
	 * The constructor
	 */
	public WSASFacetPlugin() {
		plugin = this;
	}

	/*
	 * (non-Javadoc)
	 * @see org.eclipse.ui.plugin.AbstractUIPlugin#start(org.osgi.framework.BundleContext)
	 */
	public void start(BundleContext context) throws Exception {
		super.start(context);
	}

	/*
	 * (non-Javadoc)
	 * @see org.eclipse.ui.plugin.AbstractUIPlugin#stop(org.osgi.framework.BundleContext)
	 */
	public void stop(BundleContext context) throws Exception {
		plugin = null;
		super.stop(context);
	}

	public static WSASFacetPlugin getDefault() {
		return plugin;
	}
	
	public static WSASFacetPlugin getInstance() {
		return plugin;
	}
	
    public static void log( final Exception e ){
        final String msg = e.getMessage() + "";
        log( new Status( IStatus.ERROR, PLUGIN_ID, IStatus.OK, msg, e ) );
    }

    public static void log( final IStatus status ){
        getInstance().getLog().log( status );
    }

    public static void log( final String msg ){
        log( new Status( IStatus.ERROR, PLUGIN_ID, IStatus.OK, msg, null ) );
    }

    public static IStatus createErrorStatus( final String msg ){
        return createErrorStatus( msg, null );
    }

    public static IStatus createErrorStatus( final String msg,
                                             final Exception e ){
        return new Status( IStatus.ERROR, PLUGIN_ID, 0, msg, e );
    }

}

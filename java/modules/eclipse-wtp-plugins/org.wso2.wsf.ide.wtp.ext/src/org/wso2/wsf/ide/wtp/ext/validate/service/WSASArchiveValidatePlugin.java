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
package org.wso2.wsf.ide.wtp.ext.validate.service;

import org.eclipse.jface.resource.ImageDescriptor;
import org.eclipse.ui.plugin.AbstractUIPlugin;
import org.osgi.framework.BundleContext;

import java.net.URL;
import java.util.MissingResourceException;
import java.util.ResourceBundle;

/**
 * The main plugin class to be used in the desktop.
 */
public class WSASArchiveValidatePlugin extends AbstractUIPlugin {
    //The shared instance.
    private static WSASArchiveValidatePlugin plugin;
    //Resource bundle.
    private ResourceBundle resourceBundle;
    private static ImageDescriptor wizardImageDescriptor;
    private boolean goAheadValidation;
    private boolean validURL;
    private URL resultURL;

    /**
     * The constructor.
     */
    public WSASArchiveValidatePlugin() {
        super();
        plugin = this;
        try {
            resourceBundle = ResourceBundle.getBundle(
                  "org.wso2.wsf.ide.wtp.ext.validate.service.resources.ArchiveValidateResources");
        } catch (MissingResourceException x) {
            resourceBundle = null;
        }
    }

    /**
     * This method is called upon plug-in activation
     */
    public void start(BundleContext context) throws Exception {
        super.start(context);
    }

    /**
     * This method is called when the plug-in is stopped
     */
    public void stop(BundleContext context) throws Exception {
        super.stop(context);
    }

    /**
     * Returns the shared instance.
     */
    public static WSASArchiveValidatePlugin getDefault() {
    	if (plugin == null) {
			plugin = new WSASArchiveValidatePlugin();
		}
        return plugin;
    }

    /**
     * Returns the string from the plugin's resource bundle,
     * or 'key' if not found.
     */
    public static String getResourceString(String key) {
        ResourceBundle bundle = WSASArchiveValidatePlugin.getDefault().getResourceBundle();
        try {
            return (bundle != null) ? bundle.getString(key) : key;
        } catch (MissingResourceException e) {
            return key;
        }
    }

    /**
     * Returns the plugin's resource bundle,
     */
    public ResourceBundle getResourceBundle() {
        return resourceBundle;
    }

    public static ImageDescriptor getWizardImageDescriptor() {
        if (wizardImageDescriptor == null) {
            wizardImageDescriptor =
            	WSASArchiveValidatePlugin.imageDescriptorFromPlugin(
            			"org.wso2.wsf.ide.wtp.ext.validate.service.archiveValidaterWizard", 
            			"icons/services.gif");
        }
        return wizardImageDescriptor;
    }

	public boolean isGoAheadValidation() {
		return goAheadValidation;
	}

	public void setGoAheadValidation(boolean goAheadValidation) {
		this.goAheadValidation = goAheadValidation;
	}

	public URL getValidateURL() {
		return resultURL;
	}

	public void setValidateURL(URL validateURLSet) {
		this.resultURL = validateURLSet;
	}

	public boolean isValidURL() {
		return validURL;
	}

	public void setValidURL(boolean validURL) {
		this.validURL = validURL;
	}
}

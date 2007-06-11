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
package org.wso2.wsf.ide.core.context;

import org.eclipse.wst.command.internal.env.context.PersistentContext;
import org.wso2.wsf.ide.core.plugin.WebServiceWSASCorePlugin;

public class PersistentWSASEmitterContext extends PersistentContext implements
		WSASEmitterContext {

	private static PersistentWSASEmitterContext context_ = null;

	public static PersistentWSASEmitterContext getInstance() 
	{
		if (context_ == null) {
			context_ = new PersistentWSASEmitterContext();
			context_.load();
		}
		return context_;
	}
	
	public void load(){
		setDefault(PREFERENCE_WSAS_RUNTIME_LOCATION, Axis2EmitterDefaults.getWSASRuntimeLocation());
	}
	
	private PersistentWSASEmitterContext() 	{
		super(WebServiceWSASCorePlugin.getDefault());
	}

	public String getWSASRuntimeLocation() {
		return getValueAsString(PREFERENCE_WSAS_RUNTIME_LOCATION);
	}

	public void setWSASRuntimeLocation(String runtimeLocation) {
		setValue(PREFERENCE_WSAS_RUNTIME_LOCATION, runtimeLocation);
	}
	
}

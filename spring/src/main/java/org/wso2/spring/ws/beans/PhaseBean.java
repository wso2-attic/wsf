/*
 * Copyright 2005-2008 WSO2, Inc. (http://wso2.com)
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

package org.wso2.spring.ws.beans;

import java.util.ArrayList;
import java.util.Iterator;

import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.engine.Phase;
import org.apache.axis2.i18n.Messages;
import org.apache.axis2.util.Loader;

/**
 * The Phase Bean replaces the Phase property 
 * of the configuration .xml files 
 */

public class PhaseBean {

	private ArrayList<HandlerBean> handlers;
	private String name;
	private String clazz;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public ArrayList<HandlerBean> getHandlers() {
		return handlers;
	}

	public void setHandlers(ArrayList<HandlerBean> handlers) {
		this.handlers = handlers;
	}

	public String getClazz() {
		return clazz;
	}

	public void setClazz(String clazz) {
		this.clazz = clazz;
	}
	
	// populate Axis Configuration with phase information
	public Phase populatePhases(AxisConfiguration axisConfig) throws DeploymentException {

		// get required data from thebean
		PhaseBean phaseBean = this;
		String phaseName = phaseBean.getName();
		String phaseClassName = phaseBean.getClazz();
		Phase phase = null;
		
		// load phase classes and create phase instance
		if (phaseClassName == null) {
			phase =  new Phase();
		}
		else {
			try {
				Class phaseClass = Loader.loadClass(axisConfig.getSystemClassLoader(), phaseClassName);
				phase = (Phase) phaseClass.newInstance();
			} catch (Exception e) {
				throw new DeploymentException(
						Messages.getMessage("phaseclassnotfound", phaseClassName, e.getMessage()));
			}
		}
		// set phase name
		phase.setName(phaseName);
		
		// obtain handler data of the phase
		if (!(phaseBean.getHandlers() == null)) {
			Iterator pit = phaseBean.getHandlers().iterator();

			while (pit.hasNext()) {
				
				// populate Axis Configuration with handlers of the the phase
				HandlerBean handlerBean = (HandlerBean) pit.next();
				handlerBean.populateHandlers(phase, axisConfig);
			}
		}
		return phase;
	}

}

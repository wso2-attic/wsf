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
import org.apache.axis2.deployment.util.PhasesInfo;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.engine.Phase;
import org.wso2.spring.ws.axis2.SpringAxisConstants;

/**
 * The Phase Order Bean replaces the Phase Order
 * property of the configuration .xml files 
 */

public class PhaseOrderBean implements Axis2Bean {
	
	// types of phase orders
	
	private ArrayList<PhaseBean> phases;
	private String phaseOrderType;
		
	public String getPhaseOrderType() {
		return phaseOrderType;
	}

	public void setPhaseOrderType(String phaseOrderType) {
		this.phaseOrderType = phaseOrderType;
	}

	public ArrayList<PhaseBean> getPhases() {
		return phases;
	}

	public void setPhases(ArrayList<PhaseBean> phases) {
		this.phases = phases;
	}


	// populate Axis Configuration with phase order information
	
	public void populateConfig(AxisConfiguration axisConfig) throws DeploymentException{
		// TODO Auto-generated method stub

		// get phase info 
		PhasesInfo info = axisConfig.getPhasesInfo();

		
		// process phases according to the phase order
		String flowType = getPhaseOrderType();
		Iterator it = getPhases().iterator();
		

		if (SpringAxisConstants.TAG_FLOW_IN.equals(flowType)) {
			info.setINPhases(processPhases(it, axisConfig));
		} else if (SpringAxisConstants.TAG_FLOW_IN_FAULT.equals(flowType)) {
			info.setIN_FaultPhases(processPhases(it, axisConfig));
		} else if (SpringAxisConstants.TAG_FLOW_OUT.equals(flowType)) {
			info.setOUTPhases(processPhases(it, axisConfig));
		} else if (SpringAxisConstants.TAG_FLOW_OUT_FAULT.equals(flowType)) {
			info.setOUT_FaultPhases(processPhases(it, axisConfig));
		}

	}
	
	// process phases in a phase order
	
	public ArrayList processPhases(Iterator it, AxisConfiguration axisConfig) throws DeploymentException {
		
		// set configuration class loader
		axisConfig.setSystemClassLoader(Thread.currentThread().getContextClassLoader());
		
		ArrayList phaselist = new ArrayList();
		Phase phase = null;
		
		while (it.hasNext()) {
			
			PhaseBean phaseBean = (PhaseBean) it.next();
			
			// populate axis configuration with phase information of the phase order
			phase = phaseBean.populatePhases(axisConfig);
			phaselist.add(phase);
			
		}
		return phaselist;
	}
	
	
}

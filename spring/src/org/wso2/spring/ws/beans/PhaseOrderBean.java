package org.wso2.spring.ws.beans;

import java.util.ArrayList;
import java.util.Iterator;

import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.deployment.util.PhasesInfo;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.engine.Phase;

// Replaces the Phase Order property of the configuration .xml files

public class PhaseOrderBean implements Axis2Bean {
	
	// types of phase orders
	private final String TAG_FLOW_IN = "InFlow";
	private final String TAG_FLOW_IN_FAULT = "InFaultFlow";
	private final String TAG_FLOW_OUT = "OutFlow";
	private final String TAG_FLOW_OUT_FAULT = "OutFaultFlow";
	
	
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
	@Override
	public void populateConfig(AxisConfiguration axisConfig) throws DeploymentException{
		// TODO Auto-generated method stub

		// get phase info 
		PhasesInfo info = axisConfig.getPhasesInfo();

		
		// process phases according to the phase order
		String flowType = getPhaseOrderType();
		Iterator it = getPhases().iterator();
		

		if (TAG_FLOW_IN.equals(flowType)) {
			info.setINPhases(processPhases(it, axisConfig));
		} else if (TAG_FLOW_IN_FAULT.equals(flowType)) {
			info.setIN_FaultPhases(processPhases(it, axisConfig));
		} else if (TAG_FLOW_OUT.equals(flowType)) {
			info.setOUTPhases(processPhases(it, axisConfig));
		} else if (TAG_FLOW_OUT_FAULT.equals(flowType)) {
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

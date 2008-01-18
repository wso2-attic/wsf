package org.wso2.spring.ws.beans;

import org.apache.axis2.deployment.DeploymentErrorMsgs;
import org.apache.axis2.deployment.DeploymentException;
import org.apache.axis2.deployment.util.Utils;
import org.apache.axis2.description.HandlerDescription;
import org.apache.axis2.description.PhaseRule;
import org.apache.axis2.engine.AxisConfiguration;
import org.apache.axis2.engine.Phase;
import org.apache.axis2.i18n.Messages;
import org.apache.axis2.phaseresolver.PhaseException;

// Replaces the Handler property of the configuration .xml files

public class HandlerBean {
	
	private String name;
	private String clazz;
	private String orderPhase;
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getClazz() {
		return clazz;
	}
	public void setClazz(String clazz) {
		this.clazz = clazz;
	}
	public String getOrderPhase() {
		return orderPhase;
	}
	public void setOrderPhase(String orderPhase) {
		this.orderPhase = orderPhase;
	}
	
	// populate Axis Configuration with handler information
	public void populateHandlers(Phase phase, AxisConfiguration axisConfig) throws DeploymentException{
		
		String phaseName = phase.getName();
		HandlerDescription handler = processHandler( this,phaseName );
		handler.getRules().setPhaseName(phaseName);
		Utils.loadHandler(axisConfig.getSystemClassLoader(), handler);

		try {
			phase.addHandler(handler);
		} catch (PhaseException e) {
			throw new DeploymentException(e);
		}
	}
	
	// Get handler description from the handler Bean
	public HandlerDescription processHandler(HandlerBean hBean, String containingPhase) throws DeploymentException{
		
		 // Setting handler name
       String name_attribute = hBean.getName();

       if (name_attribute == null || name_attribute.equals("")) {
           throw new DeploymentException(Messages.getMessage(
                   DeploymentErrorMsgs.INVALID_HANDLER, "Unknown", "Name missing"));
       }

       HandlerDescription handler = new HandlerDescription(name_attribute);

		String class_attribute = hBean.getClazz();

		if (class_attribute == null) {
			throw new DeploymentException((Messages.getMessage(
					DeploymentErrorMsgs.INVALID_HANDLER, name_attribute,
					"class name is missing")));
		} else {
			handler.setClassName(class_attribute);
		}

		// processing phase rules (order)
		String order_element = hBean.getOrderPhase();

		PhaseRule rules = handler.getRules();
		
		if (order_element == null) {
			if (containingPhase == null) {
				
				throw new DeploymentException((Messages.getMessage(
						DeploymentErrorMsgs.INVALID_HANDLER, name_attribute,
						"phase rule has not been specified")));
			}
			rules.setPhaseName(containingPhase);
		}
		
		return handler;
	}
}

package org.wso2.spring.ws.axis2;

/**
 * Constants related to Axis2 used in WSF/Spring
 */
public class SpringAxisConstants {

	/**
	 * The parameter that stores the name of the spring bean
	 */
	public static final String SERVICE_SPRING_BEANNAME = "SpringBeanName";
	
	/**
	 * The parameter that stores the POJO that will be exposed as a web service
	 */
	public static final String SPRING_POJO = "SpringPOJO";
	
	/**
	 * The parameter used to store Object Supplier class in Axis 2
	 */
	public static final String TAG_OBJECT_SUPPLIER = "ObjectSupplier";
	
	/**
	 * The parameter used to store the operation name in Axis 2
	 */
	public static final String OPERATION_NAME = "operationName";
	
	/**
	 * The tag used for the flow type In
	 */
	public static final String TAG_FLOW_IN = "InFlow";
	
	/**
	 * The tag used for the flow type In Fault 
	 */
	public static final String TAG_FLOW_IN_FAULT = "InFaultFlow";
	
	/**
	 * The tag used for the flow type Out 
	 */
	public static final String TAG_FLOW_OUT = "OutFlow";
	
	/**
	 * The tag used for the flow type Out Fault
	 */
	public static final String TAG_FLOW_OUT_FAULT = "OutFaultFlow";
	
	
}

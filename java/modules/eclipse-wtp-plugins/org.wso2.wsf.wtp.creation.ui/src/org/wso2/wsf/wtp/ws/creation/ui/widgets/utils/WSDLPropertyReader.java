package org.wso2.wsf.wtp.ws.creation.ui.widgets.utils;



/**
 * This class presents a convenient way of reading the 
 * WSDL file(url) and producing a useful set of information
 * It does NOT use any of the standard WSDL classes from 
 * Axis2, rather it uses wsdl4j to read the wsdl and extract 
 * the properties (This is meant as a convenience for the UI
 * only. We may not need the whole conversion the WSDLpump 
 * goes through)
 * One would need to change this to suit a proper WSDL 
 */
public class WSDLPropertyReader {
//    private Definition wsdlDefinition = null;
//    
//	public void readWSDL(String filepath) throws WSDLException {
//		WSDLReader reader = WSDLFactory.newInstance().newWSDLReader();
//		wsdlDefinition = reader.readWSDL(filepath); 
//	}
//	
//	/**
//	 * Returns the namespace map from definition
//	 * @return
//	 */
//	public Map getDefinitionNamespaceMap(){
//		return wsdlDefinition.getNamespaces();
//	}
//	
//	/**
//	 * get the default package derived by the targetNamespace
//	 */
//	public String packageFromTargetNamespace(){
//		return  URLProcessor.makePackageName(wsdlDefinition.getTargetNamespace());
//		
//	}
//	
//	/**
//	 * Returns a list of service names
//	 * the names are QNames
//	 * @return
//	 */
//	public List getServiceList(){
//		List returnList = new ArrayList();
//		Service service = null;
//		Map serviceMap = wsdlDefinition.getServices();
//		if(serviceMap!=null && !serviceMap.isEmpty()){
//		   Iterator serviceIterator = serviceMap.values().iterator();
//		   while(serviceIterator.hasNext()){
//			   service = (Service)serviceIterator.next();
//			   returnList.add(service.getQName());
//		   }
//		}
//		
//		return returnList;
//	}
//
//	/**
//	 * Returns a list of ports for a particular service
//	 * the names are QNames
//	 * @return
//	 */
//	public List getPortNameList(QName serviceName){
//		List returnList = new ArrayList();
//		Service service = wsdlDefinition.getService(serviceName);
//		Port port = null; 
//		if(service!=null){
//		   Map portMap = service.getPorts();
//		   if (portMap!=null && !portMap.isEmpty()){
//			   Iterator portIterator = portMap.values().iterator();
//			   while(portIterator.hasNext()){
//				 port = (Port)portIterator.next();
//				 returnList.add(port.getName());
//			   }
//		   }
//		  
//		}
//		
//		return returnList;
//	}
}

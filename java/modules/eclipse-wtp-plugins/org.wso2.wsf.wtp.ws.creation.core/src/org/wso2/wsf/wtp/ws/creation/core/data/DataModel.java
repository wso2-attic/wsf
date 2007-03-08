package org.wso2.wsf.wtp.ws.creation.core.data;

public class DataModel{
	
	private String  webProjectName;
	
	//Client Side
	private String serviceClass;
	private boolean generateServicesXML;
	private boolean servicesXML;
	private boolean generateAAR;
	private String  pathToServicesXML;
	private String  pathToWebServicesTempDir;
	
	//Server Side 
	private String  wsdlURI;
	private boolean generateServerSideInterface;
    private boolean serverXMLCheck;
	private boolean generateAllCheck;
	private boolean testCaseCheck;
	private String databindingType;
	private String portName;
	private String serviceName;
	private String packageText;
	private String namespaseToPackageMapping;
	private boolean serverStatus;


	public boolean isGenerateServicesXML()
	{
		return generateServicesXML;
	}

	public void setGenerateServicesXML(boolean generateServicesXML)
	{
		this.generateServicesXML = generateServicesXML;
	}

	public String getPathToServicesXML()
	{
		return pathToServicesXML;
	}

	public void setPathToServicesXML(String pathToServicesXML)
	{
		this.pathToServicesXML = pathToServicesXML;
	}

	public boolean isGenerateAAR() {
		return generateAAR;
	}

	public void setGenerateAAR(boolean generateAAR) {
		this.generateAAR = generateAAR;
	}

	public String getWebProjectName() {
		return webProjectName;
	}

	public void setWebProjectName(String webProjectName) {
		this.webProjectName = webProjectName;
	}

	public boolean isServicesXML() {
		return servicesXML;
	}

	public void setServicesXML(boolean servicesXML) {
		this.servicesXML = servicesXML;
	}

	public String getPathToWebServicesTempDir() {
		return pathToWebServicesTempDir;
	}

	public void setPathToWebServicesTempDir(String pathToWebServicesTempDir) {
		this.pathToWebServicesTempDir = pathToWebServicesTempDir;
	}

	public String getWsdlURI() {
		return wsdlURI;
	}

	public void setWsdlURI(String wsdlURI) {
		this.wsdlURI = wsdlURI;
	}

	public String getDatabindingType() {
		return databindingType;
	}

	public void setDatabindingType(String databindingType) {
		this.databindingType = databindingType;
	}

	public boolean isGenerateAllCheck() {
		return generateAllCheck;
	}

	public void setGenerateAllCheck(boolean generateAllCheck) {
		this.generateAllCheck = generateAllCheck;
	}

	public boolean isGenerateServerSideInterface() {
		return generateServerSideInterface;
	}

	public void setGenerateServerSideInterface(boolean generateServerSideInterface) {
		this.generateServerSideInterface = generateServerSideInterface;
	}

	public String getPortName() {
		return portName;
	}

	public void setPortName(String portName) {
		this.portName = portName;
	}

	public boolean isServerXMLCheck() {
		return serverXMLCheck;
	}

	public void setServerXMLCheck(boolean serverXMLCheck) {
		this.serverXMLCheck = serverXMLCheck;
	}

	public String getServiceName() {
		return serviceName;
	}

	public void setServiceName(String serviceName) {
		this.serviceName = serviceName;
	}

	public boolean isTestCaseCheck() {
		return testCaseCheck;
	}

	public void setTestCaseCheck(boolean testCaseCheck) {
		this.testCaseCheck = testCaseCheck;
	}

	public String getPackageText() {
		return packageText;
	}

	public void setPackageText(String packageText) {
		this.packageText = packageText;
	}

	public String getServiceClass() {
		return serviceClass;
	}

	public void setServiceClass(String serviceClass) {
		this.serviceClass = serviceClass;
	}

	public String getNamespaseToPackageMapping() {
		return namespaseToPackageMapping;
	}

	public void setNamespaseToPackageMapping(String namespaseToPackageMapping) {
		this.namespaseToPackageMapping = namespaseToPackageMapping;
	}

	public boolean getServerStatus() {
		return serverStatus;
	}

	public void setServerStatus(boolean serverStatus) {
		this.serverStatus = serverStatus;
	}

}

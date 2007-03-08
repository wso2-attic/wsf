package org.wso2.wsf.wtp.ws.creation.core.utils;

import java.util.ArrayList;

public class ServiceXMLCreator {
    private String serviceName;
    private String serviceClass;
    private ArrayList operations;

    public ServiceXMLCreator(String serviceName, String serviceClass, ArrayList operations) {
        this.serviceName = serviceName;
        this.serviceClass = serviceClass;
        this.operations = operations;
    }

    public String getServiceName() {
        return serviceName;
    }

    public String getServiceClass() {
        return serviceClass;
    }

    public ArrayList getOperations() {
        return operations;
    }

    public String toString() {
        String serviceXML = "<service name=\"" + serviceName + "\" >\n" +
        "\t<description>\n" +
        "\t\tPlease Type your service description here\n" +
        "\t</description>\n" +
        "\t<messageReceivers>\n" +
        "\t\t<messageReceiver mep=\"http://www.w3.org/2004/08/wsdl/in-only\" " +
        "class=\"org.apache.axis2.rpc.receivers.RPCInOnlyMessageReceiver\" />\n" +
        "\t\t<messageReceiver  mep=\"http://www.w3.org/2004/08/wsdl/in-out\"  " +
        "class=\"org.apache.axis2.rpc.receivers.RPCMessageReceiver\"/>\n" +
        "\t</messageReceivers>\n" + 
        "\t<parameter name=\"ServiceClass\" locked=\"false\">" + serviceClass + "</parameter>\n" ; 
        serviceXML = serviceXML + "</service>\n";
        return serviceXML;
    }

}
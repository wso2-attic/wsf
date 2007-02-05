package org.wso2.wsf.wtp.ws.creation.ui.wsrt;

import org.eclipse.wst.ws.internal.wsrt.AbstractWebServiceRuntime;
import org.eclipse.wst.ws.internal.wsrt.IWebService;
import org.eclipse.wst.ws.internal.wsrt.IWebServiceClient;
import org.eclipse.wst.ws.internal.wsrt.WebServiceClientInfo;
import org.eclipse.wst.ws.internal.wsrt.WebServiceInfo;

public class WSASWebServiceRuntime extends AbstractWebServiceRuntime
{

	public IWebService getWebService(WebServiceInfo info){
		return new WSASWebService(info);
	}

	public IWebServiceClient getWebServiceClient(WebServiceClientInfo info){
		return null;
	}
	
}

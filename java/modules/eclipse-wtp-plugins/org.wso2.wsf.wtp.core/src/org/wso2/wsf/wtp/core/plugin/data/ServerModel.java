package org.wso2.wsf.wtp.core.plugin.data;

public class ServerModel {
	
	private static String wsasServerPath = null;

	public static String getWSASServerPath() {
		return wsasServerPath;
	}

	public static void setWSASServerPath(String wsasServerPathParam) {
		wsasServerPath = wsasServerPathParam;
	}

}

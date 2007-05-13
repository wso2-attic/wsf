package org.wso2.wsf.wtp.server.bean;

public class WSASConfigurationBean {
	
	//private static String wsasInstallationPath = "/home/sandakith/ProjectCheckouts/wso2/wsf/java/modules/eclipse-wtp-plugins/org.wso2.wsas";
	//private static String wsasInstallationPath = "/media/Sansa m240/wso2wsas-1.2-SNAPSHOT";
	//private static String wsasInstallationPath = "/media/Sansa m240/wso2wsas-1.2-SNAPSHOT.zip_FILES/wso2wsas-1.2-SNAPSHOT";
    private static String wsasInstallationPath = "/home/sandakith/Desktop/wso2wsas-1.2-SNAPSHOT";
    
    private static boolean wsasStartStatus = false;

    public static boolean isWsasStartStatus() {
        return wsasStartStatus;
    }

    public static void setWsasStartStatus(boolean wsasStartStatus) {
        WSASConfigurationBean.wsasStartStatus = wsasStartStatus;
    }

    public static String getWsasInstallationPath() {
        return wsasInstallationPath;
    }

    public static void setWsasInstallationPath(String installationPath) {
        wsasInstallationPath = installationPath;
    }

}

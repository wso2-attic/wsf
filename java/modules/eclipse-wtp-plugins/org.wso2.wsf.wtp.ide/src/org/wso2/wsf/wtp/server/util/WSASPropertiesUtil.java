package org.wso2.wsf.wtp.server.util;

import java.io.File;

import org.wso2.wsf.wtp.server.bean.WSASConfigurationBean;
import org.wso2.wsf.wtp.server.constant.WSASConfigurationConstant;

public class WSASPropertiesUtil {
	
    public static void setWSASProperties() {
        System.setProperty(WSASConfigurationConstant.WSO2WSAS_HOME,
                WSASConfigurationBean.getWsasInstallationPath());
        System.setProperty(
                WSASConfigurationConstant.LOG4J_CONFIGURATION,
                getLog4JConfigurationPath(WSASConfigurationBean.getWsasInstallationPath())
        );
        
    }

    private static String getLog4JConfigurationPath(String wsasPath) {

        return wsasPath + File.separator +
               WSASConfigurationConstant.CONF_FOLDER + File.separator +
               WSASConfigurationConstant.LOG4J_CONFIGURATION;
    }

}

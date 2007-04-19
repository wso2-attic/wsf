/*
 * Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.wso2.wsf.idea.ws.util;

import org.wso2.wsf.idea.ws.constant.WSASConfigurationConstant;
import org.wso2.wsf.idea.ws.bean.WSASConfigurationBean;

import java.io.File;

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

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
package org.wso2.wsf.idea.ws.bean;

import org.wso2.wsf.idea.ws.constant.WSASConfigurationConstant;

public class WSASConfigurationBean {

    private static String wsasInstallationPath = WSASConfigurationConstant.WSAS_DEFAULT_PATH;
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

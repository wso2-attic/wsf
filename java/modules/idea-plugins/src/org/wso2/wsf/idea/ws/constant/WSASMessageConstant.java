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
package org.wso2.wsf.idea.ws.constant;

public class WSASMessageConstant {
    //warnings
    public static String WARNING_WSAS_HEADING = "WSAS Warning Message";
    public static String WARNING_WSAS_PATH_NOT_SET = "Please set the Correct WSAS Installation Path !!";
    public static String WARNING_WSAS_NOT_STARTED = "Configured WSAS instance is not active !!";

    //errors
    public static String ERROR_WSAS_ALREADY_RUNNING = "WSO2 Web Services Application Server instance is already running, \n" +
            "Please Stop the server..";
    public static String ERROR_WSAS_NOT_RUNNING = "WSO2 Web Services Application Server instance is not active,\n" +
            "Ignoring Stop server..";

    //wsas
    public static String INFO_WSAS_START_SUCCESS = "WSO2 Web Services Application Server instance started successfully";
    public static String INFO_WSAS_START_FAIL = "Error Occured while starting WSO2 Web Services Application Server instance";
    public static String INFO_WSAS_STOP_SUCCESS = "WSO2 Web Services Application Server instance stoped successfully";
    public static String INFO_WSAS_STOP_FAIL = "Error Occured while stopping WSO2 Web Services Application Server instance";

}

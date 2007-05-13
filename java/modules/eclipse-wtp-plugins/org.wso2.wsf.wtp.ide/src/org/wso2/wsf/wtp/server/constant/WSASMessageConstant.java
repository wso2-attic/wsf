package org.wso2.wsf.wtp.server.constant;

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

    //WSAS
    public static String INFO_WSAS_START_SUCCESS = "WSO2 Web Services Application Server instance started successfully";
    public static String INFO_WSAS_START_FAIL = "Error Occured while starting WSO2 Web Services Application Server instance";
    public static String INFO_WSAS_STOP_SUCCESS = "WSO2 Web Services Application Server instance stoped successfully";
    public static String INFO_WSAS_STOP_FAIL = "Error Occured while stopping WSO2 Web Services Application Server instance";

}

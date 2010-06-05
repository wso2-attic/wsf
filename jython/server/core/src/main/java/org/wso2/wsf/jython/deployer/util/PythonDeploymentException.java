package org.wso2.wsf.jython.deployer.util;

/**
 * Created by IntelliJ IDEA.
 * User: heshan
 * Date: Jun 5, 2010
 * Time: 9:42:06 AM
 * To change this template use File | Settings | File Templates.
 */
public class PythonDeploymentException extends Exception{

    public PythonDeploymentException(String message) {
        super(message);
    }

    public PythonDeploymentException(Throwable cause) {
        super(cause);
    }

    public PythonDeploymentException(String message, Throwable cause) {
        super(message, cause);
    }
}

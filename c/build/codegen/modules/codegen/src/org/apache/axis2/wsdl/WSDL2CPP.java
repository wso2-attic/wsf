package org.apache.axis2.wsdl;

/**
 * Created by IntelliJ IDEA.
 * User: NandikaJayawardana
 * Date: Mar 6, 2009
 * Time: 12:44:02 PM
 * To change this template use File | Settings | File Templates.
 */
public class WSDL2CPP {
    public static void main(String[] args) throws Exception{
        String[] cppargs = new String[args.length + 2];
        System.arraycopy(args, 0, cppargs, 0, args.length);
        System.setProperty("org.apache.adb.properties",
                           "/org/apache/axis2/schema/cpp-schema-compile.properties");
        cppargs[args.length] = "-l";
        cppargs[args.length + 1] = "cpp";

        WSDL2Code.main(cppargs);
    }
}

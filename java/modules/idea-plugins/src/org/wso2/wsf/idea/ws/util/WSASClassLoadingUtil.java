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

import java.io.File;
import java.net.MalformedURLException;
import java.net.URL;

import org.apache.tools.ant.AntClassLoader;
import org.apache.tools.ant.Project;
import org.apache.tools.ant.types.Path;
import org.wso2.wsf.idea.ws.constant.WSASConfigurationConstant;

public class WSASClassLoadingUtil {

    private static String[] wsasClassPath = null;
    private static int libCount = 0;
    private static AntClassLoader antClassLoader;

    public static void init(String wsasPath) {

        //Obtain a ant class loader instance
        antClassLoader =  new AntClassLoader();

        // Set the class loader to child first
        antClassLoader.setParentFirst(false);

        String[] classLoadPath = getWSASLibs(wsasPath);
        URL[] urls = new URL[classLoadPath.length];

        Path classpath = new Path(new Project());

        try{
            for (int i = 0; i < classLoadPath.length; i++) {
                //Create a File object on the root of the directory containing the class file
                if(classLoadPath[i]!=null){
                    File file = new File(classLoadPath[i]);
                    // Convert File to a URL
                    URL url = file.toURL();
                    urls[i]= url;
                    classpath.setPath(classLoadPath[i]);
                }
            }

        }catch(MalformedURLException e){
            e.printStackTrace();
        }
            antClassLoader.setClassPath(classpath);
    }




    public static Class loadClassFromAntClassLoader(String fillyQualifiedClassName){

        Class cls = null;
        try{
            cls = antClassLoader.loadClass(fillyQualifiedClassName);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        return cls;
    }



    private static String[] getWSASLibs(String wsasPath){
        File wsasLibPath = new File(wsasPath+File.separator+ WSASConfigurationConstant.LIB);
        wsasClassPath = new String[wsasLibPath.list().length];
        libCount = 0;
        visitAllFiles(wsasLibPath);
        return wsasClassPath;
    }


    public static void visitAllFiles(File dir) {
        if(!dir.toString().endsWith(WSASConfigurationConstant.DOT_TEXT)){
            if (dir.isDirectory()) {

                String[] children = dir.list();
                for (int i=0; i<children.length; i++) {
                    visitAllFiles(new File(dir, children[i]));
                }

            } else {
                wsasClassPath[libCount]=dir.getAbsolutePath();
                libCount+=1;
            }

        }

    }


}


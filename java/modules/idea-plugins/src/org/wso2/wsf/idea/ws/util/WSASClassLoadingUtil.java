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
import java.io.FileNotFoundException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.ArrayList;

public class WSASClassLoadingUtil {

    private static ArrayList wsasClassPath = null;
    private static WSASLibraryHelper helper = null;
    private static ClassLoader contextClassLoader = null;
    private static ClassLoader wsasClassLoader = null;

    public static void cleanupAntClassLoader(){
         Thread.currentThread().setContextClassLoader(contextClassLoader);
    }

    public static void init(String wsasPath) {
        contextClassLoader = Thread.currentThread().getContextClassLoader();
        File wsasHome = new File(wsasPath);
        loadWSASLibs(wsasHome);
        URL[] urls = (URL[]) wsasClassPath.toArray(new URL[wsasClassPath.size()]);
        wsasClassLoader = URLClassLoader.newInstance(urls, contextClassLoader);

    }

    public static Class loadClassFromClassLoader(String fillyQualifiedClassName) {
        Class clazz = null;
        try {
            clazz = wsasClassLoader.loadClass(fillyQualifiedClassName);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        return clazz;
    }


    private static void loadWSASLibs(File wsasHome) {
        helper = WSASLibraryHelper.getInstance();
        wsasClassPath = new ArrayList();
        try {
            File[] jars = helper.loadJars(new File(wsasHome.getAbsolutePath(), "lib"));
            for (int i = 0; i < jars.length; i++) {
                wsasClassPath.add(new URL("file:" + jars[i].getAbsolutePath()));
            }
            File resource = helper.loadResources(new File(wsasHome.getAbsolutePath(), "conf"));
            wsasClassPath.add(new URL("file:" + resource.getAbsolutePath() + File.separator));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (MalformedURLException e) {
            e.printStackTrace();
        }
    }


}


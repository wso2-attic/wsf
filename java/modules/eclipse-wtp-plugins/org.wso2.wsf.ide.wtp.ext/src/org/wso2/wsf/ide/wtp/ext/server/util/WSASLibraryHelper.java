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
package org.wso2.wsf.ide.wtp.ext.server.util;

import java.io.FileFilter;
import java.io.File;
import java.io.FileNotFoundException;

public class WSASLibraryHelper {
	
    private  static WSASLibraryHelper object = new WSASLibraryHelper();

    private WSASLibraryHelper(){}

    public static WSASLibraryHelper getInstance() {
        return  object;
    }

    public File[] loadJars(File libDir) throws FileNotFoundException {
        if (!libDir.exists()) {
            throw new FileNotFoundException("dirs not found");
        }

        return libDir.listFiles(new FileFilter(){

            public boolean accept(File pathname) {
                return pathname.getName().endsWith(".jar");
            }
        });


    }

    public File loadResources(File resourceDir) throws FileNotFoundException {
        if (!resourceDir.exists()) {
            throw new FileNotFoundException("resource dir is not found");
        }

        return resourceDir;
    }

}

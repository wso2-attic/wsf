package org.wso2.wsf.wtp.server.util;

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

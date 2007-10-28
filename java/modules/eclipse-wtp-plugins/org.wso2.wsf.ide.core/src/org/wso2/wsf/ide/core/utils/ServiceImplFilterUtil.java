package org.wso2.wsf.ide.core.utils;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class ServiceImplFilterUtil {
	
	private static List fileList = null;
	
    public static File[] getMatchingFiles(String sourceDir, String fileNamePrefix, String extension) {
    	fileList = new ArrayList();
    	fileList.clear();
        File libDir = new File(sourceDir);
        String[] items = libDir.list();
        for (int i = 0; i < items.length; i++) {
            String item = items[i];
            File itemFile = new File(FileUtils.addAnotherNodeToPath(sourceDir,item));
            if (itemFile.exists() && itemFile.isDirectory()) {
            	visitAllFiles(itemFile,fileNamePrefix, extension);
			}
            else if (itemFile.exists() && itemFile.isFile() 
            		&& ((fileNamePrefix != null)?item.contains(fileNamePrefix):true) 
            		&& ((extension != null)?item.endsWith(extension):true)) {
                fileList.add(new File(FileUtils.addAnotherNodeToPath(sourceDir,item)));
            }
        }
        return (File[]) fileList.toArray(new File[fileList.size()]);
    }
    
    public static void visitAllFiles(File dir, String fileNamePrefix, String extension) {
        if (dir.isDirectory()) {
            String[] children = dir.list();
            for (int i=0; i<children.length; i++) {
                visitAllFiles(new File(dir, children[i]), fileNamePrefix , extension);
            }
        } else {
            if (dir.exists() && dir.isFile() && dir.toString().contains(fileNamePrefix) 
           		 && dir.toString().endsWith(extension)) {
               fileList.add(dir);
           }
        }
    }

}

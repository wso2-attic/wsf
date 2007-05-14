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
package org.wso2.wsf.ide.facet.utils;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.channels.FileChannel;
import java.util.Enumeration;
import java.util.Properties;
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import org.eclipse.core.runtime.IProgressMonitor;
import org.wso2.wsf.ide.core.plugin.data.ServerModel;
import org.wso2.wsf.ide.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.ide.core.utils.WSASCoreUtils;
import org.wso2.wsf.ide.core.utils.FileUtils;

public class WSASRuntimeUtils {
	
	public static final int ZIP=0, UNZIP = 1;
	protected static int mode = UNZIP;
	static ZipFile zipFile;
	protected static byte[] b;
	static SortedSet createdDirs;
	static String outputPath;

	public static String  copyWSASWar(IProgressMonitor monitor, String wsasHome)
							throws FileNotFoundException, IOException{
		String tempWarFile = null;
		String tempWarLocation = null;
		String  tempUnzipLocation = null;
		try {
			if (new File (WSASCoreUtils.tempWSASDirectory()).isDirectory()) {
				tempWarLocation = WSASCoreUtils.addAnotherNodeToPath(
															WSASCoreUtils.tempWSASDirectory(),
															WSASCoreUIMessages.DIR_TEMPWAR);
			File tempWarLocationFile= new File(tempWarLocation);
			if (tempWarLocationFile.exists()) {
				FileUtils.deleteDirectories(tempWarLocationFile);
			}
			tempWarLocationFile.mkdirs();
			tempWarFile = WSASCoreUtils.addAnotherNodeToPath(
															tempWarLocation,	
															WSASCoreUIMessages.FILE_WSAS_WAR);
			new File(tempWarFile).createNewFile();
			Properties properties = new Properties();
			properties.load(new FileInputStream(WSASCoreUtils.tempWSASWebappFileLocation()));
				if (properties.containsKey(WSASCoreUIMessages.PROPERTY_KEY_PATH)){
					String wsasWarFile = WSASCoreUtils.addAnotherNodeToPath(
													(ServerModel.getWsasServerPath()!=null)
													?ServerModel.getWsasServerPath()
													:properties.getProperty(
															WSASCoreUIMessages.PROPERTY_KEY_PATH),
																WSASCoreUIMessages.FILE_WSAS_WAR);
					FileChannel srcChannel = new FileInputStream(wsasWarFile).getChannel();
					FileChannel dstChannel = new FileOutputStream(tempWarFile).getChannel();
					// Copy file contents from source to destination
					dstChannel.transferFrom(srcChannel, 0, srcChannel.size());
					// Close the channels
					srcChannel.close();
					dstChannel.close();
				
				//unzip this into another foulder
				tempUnzipLocation = FileUtils.addAnotherNodeToPath(tempWarLocation, 
											WSASCoreUIMessages.DIR_UNZIP);
				File tempUnzipLocationFile= new File(tempUnzipLocation);
				if (!tempUnzipLocationFile.exists()) {
					tempUnzipLocationFile.mkdirs();
				}
				unzipWSASWar(tempWarFile,tempUnzipLocation );

				}
				
			} else {
				//Throws an error message
			}
		} catch (FileNotFoundException e) {
			throw e;	
		} catch (IOException e) {
			throw e;
		}

		return tempUnzipLocation;
	}
	
	
	private static void unzipWSASWar(String fileName,String outputPath){
	      b = new byte[8092];
	      setOutputPath(outputPath);
	      if (fileName.endsWith(".war") )
	        unZip(fileName);
	      else
	    	  throw new IllegalStateException("Wrong file type" + fileName);
	}

	/** For a given Zip file, process each entry. */
	public static void unZip(String fileName) {
	
	  createdDirs = new TreeSet();
	  try {
	    zipFile = new ZipFile(fileName);
	    Enumeration all = zipFile.entries();
	    while (all.hasMoreElements()) {
	      unzipFile((ZipEntry) all.nextElement());
	    }
	  } catch (IOException e) {
	    e.printStackTrace();
	  }
	}

	
	protected static void unzipFile(ZipEntry e) throws IOException {

	  boolean warnedMkDir = false;
	    String zipName = e.getName();
	    switch (mode) {
	    case UNZIP:
	      if (zipName.startsWith("/")) {
	        if (!warnedMkDir)
	        warnedMkDir = true;
	        zipName = zipName.substring(1);
	      }
	      if (zipName.endsWith("/")) {
	        return;
	      }
	      int ix = zipName.lastIndexOf('/');
	      if (ix > 0) {
	        String dirName = zipName.substring(0, ix);
	        if (!createdDirs.contains(dirName)) {
	          File d = new File(getOutputPath()+File.separator+dirName);
	          if (!(d.exists() && d.isDirectory())) {
	            if (!d.mkdirs()) {
	              throw new IllegalStateException("Warning: unable to mkdir " + dirName);
	            }
	            createdDirs.add(dirName);
	          }
	        }
	      }
          FileOutputStream os = new FileOutputStream(getOutputPath()+File.separator+zipName);
	      InputStream is = zipFile.getInputStream(e);
	      int n = 0;
	      while ((n = is.read(b)) > 0)
	        os.write(b, 0, n);
	      is.close();
	      os.close();
	      break;
	    default:
	      throw new IllegalStateException("mode value (" + mode + ") bad");
	    }
	  }

	

	public static String getOutputPath() {
		return outputPath;
	}


	public static void setOutputPath(String outputPath) {
		WSASRuntimeUtils.outputPath = outputPath;
	}

		    
}

package org.wso2.wsas.wtp.facet.utils;

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
import org.wso2.wsf.wtp.core.plugin.data.ServerModel;
import org.wso2.wsf.wtp.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.wtp.core.utils.WSASCoreUtils;

public class WSASRuntimeUtils {
	
	/** Constants for mode listing or mode extracting. */
	public static final int LIST = 0, EXTRACT = 1;

	/** Whether we are extracting or just printing TOC */
	protected static int mode = EXTRACT;

	/** The ZipFile that is used to read an archive */
	static ZipFile zippy;

	/** The buffer for reading/writing the ZipFile data */
	protected static byte[] b;
	
	static SortedSet dirsMade;
	
	static String outputPath;

	public static String  copyWSASWar(IProgressMonitor monitor, String wsasHome) {
		String tempWarFile = null;
		String tempWarLocation = null;
		try {
			if (new File (WSASCoreUtils.tempWSASDirectory()).isDirectory()) {
				tempWarLocation = WSASCoreUtils.addAnotherNodeToPath(
															WSASCoreUtils.tempWSASDirectory(),
															WSASCoreUIMessages.DIR_TEMPWAR);
			File tempWarLocationFile= new File(tempWarLocation);
			if (tempWarLocationFile.exists()) {
				tempWarLocationFile.delete();
			}
			tempWarLocationFile.mkdirs();
			tempWarFile = WSASCoreUtils.addAnotherNodeToPath(
															tempWarLocation,	
															WSASCoreUIMessages.FILE_WSAS_WAR);
			new File(tempWarFile).createNewFile();
			Properties properties = new Properties();
			properties.load(new FileInputStream(WSASCoreUtils.tempWSASWebappFileLocation()));
				if (properties.containsKey(WSASCoreUIMessages.PROPERTY_KEY_PATH)){
					String wsasWarLocation = WSASCoreUtils.addAnotherNodeToPath(
//													properties.getProperty(
//													WSASCoreUIMessages.PROPERTY_KEY_PATH),
													ServerModel.getWSASServerPath(),
													WSASCoreUIMessages.DIR_DIST);
					String wsasWarFile = WSASCoreUtils.addAnotherNodeToPath(
																wsasWarLocation,
																WSASCoreUIMessages.FILE_WSAS_WAR);
					
					FileChannel srcChannel = new FileInputStream(wsasWarFile).getChannel();
					FileChannel dstChannel = new FileOutputStream(tempWarFile).getChannel();
					// Copy file contents from source to destination
					dstChannel.transferFrom(srcChannel, 0, srcChannel.size());
					// Close the channels
					srcChannel.close();
					dstChannel.close();
				
				//unzip this into another foulder
				unzipAxis2War(tempWarFile, tempWarLocation);
				File wsasWarFileCache = new File(tempWarFile);
					if (wsasWarFileCache.exists()) {
						wsasWarFileCache.delete();
					}
				}
				
			} else {
				//Throws an error message
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();	
		} catch (IOException e) {
			e.printStackTrace();
		}

		return tempWarLocation;
	}
	
	
	private static void unzipAxis2War(String fileName,String outputPath){
	      b = new byte[8092];
	      setMode(1);
	      setOutputPath(outputPath);
	      if (fileName.endsWith(".war") )
	        unZip(fileName);
	      else
	        System.err.println("Not a zip file? " + fileName);
	}

	/** For a given Zip file, process each entry. */
	public static void unZip(String fileName) {
	
	  dirsMade = new TreeSet();
	  try {
	    zippy = new ZipFile(fileName);
	    Enumeration all = zippy.entries();
	    while (all.hasMoreElements()) {
	      unzipFile((ZipEntry) all.nextElement());
	    }
	  } catch (IOException err) {
	    System.err.println("IO Error: " + err);
	    return;
	  }
	}

	
	protected static void unzipFile(ZipEntry e) throws IOException {

	  boolean warnedMkDir = false;
	    String zipName = e.getName();
	    switch (mode) {
	    case EXTRACT:
	      if (zipName.startsWith("/")) {
	        if (!warnedMkDir)
	        warnedMkDir = true;
	        zipName = zipName.substring(1);
	      }
	      // if a directory, just return. We mkdir for every file,
	      // since some widely-used Zip creators don't put out
	      // any directory entries, or put them in the wrong place.
	      if (zipName.endsWith("/")) {
	        return;
	      }
	      // Else must be a file; open the file for output
	      // Get the directory part.
	      int ix = zipName.lastIndexOf('/');
	      if (ix > 0) {
	        String dirName = zipName.substring(0, ix);
	        if (!dirsMade.contains(dirName)) {
	          File d = new File(getOutputPath()+File.separator+dirName);
	          // If it already exists as a dir, don't do anything
	          if (!(d.exists() && d.isDirectory())) {
	            // Try to create the directory, warn if it fails
	            if (!d.mkdirs()) {
	              System.err.println("Warning: unable to mkdir "
	                  + dirName);
	            }
	            dirsMade.add(dirName);
	          }
	        }
	      }
	      System.err.println("Creating " + zipName);
	      FileOutputStream os = new FileOutputStream(getOutputPath()+File.separator+zipName);
	      InputStream is = zippy.getInputStream(e);
	      int n = 0;
	      while ((n = is.read(b)) > 0)
	        os.write(b, 0, n);
	      is.close();
	      os.close();
	      break;
	    case LIST:
	      // Not extracting, just list
	      if (e.isDirectory()) {
	      } else {
	      }
	      break;
	    default:
	      throw new IllegalStateException("mode value (" + mode + ") bad");
	    }
	  }

	

	  /** Set the Mode (list, extract). */
	  private static void setMode(int m) {
	    if (m == LIST || m == EXTRACT)
	      mode = m;
	  }


	public static String getOutputPath() {
		return outputPath;
	}


	public static void setOutputPath(String outputPath) {
		WSASRuntimeUtils.outputPath = outputPath;
	}

		    
}

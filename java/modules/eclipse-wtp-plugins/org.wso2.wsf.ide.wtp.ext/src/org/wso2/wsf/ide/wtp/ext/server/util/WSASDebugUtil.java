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

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.Path;

public class WSASDebugUtil {
	
	public File createWindowsDebugRunnerFile() 
												throws 	IllegalArgumentException,
														FileNotFoundException,
														IOException
														{
		IPath runnerPath = new Path(System.getProperty("user.dir"));
		runnerPath = runnerPath.append("runner.bat");
		File aFile = new File(runnerPath.toOSString());
		aFile.createNewFile();
		String aContents ="start %1 %2 %3 & exit";
	    if (aFile == null) {
	        throw new IllegalArgumentException("File should not be null.");
	      }
	      if (!aFile.exists()) {
	        throw new FileNotFoundException ("File does not exist: " + aFile);
	      }
	      if (!aFile.isFile()) {
	        throw new IllegalArgumentException("Should not be a directory: " + aFile);
	      }
	      if (!aFile.canWrite()) {
	        throw new IllegalArgumentException("File cannot be written: " + aFile);
	      }

	      //declared here only to make visible to finally clause; generic reference
	      Writer output = null;
	      try {
	        //use buffering
	        //FileWriter always assumes default encoding is OK!
	        output = new BufferedWriter( new FileWriter(aFile) );
	        output.write( aContents );
	      }
	      finally {
	        //flush and close both "output" and its underlying FileWriter
	        if (output != null) output.close();
	      }
	      return aFile;
	}

}

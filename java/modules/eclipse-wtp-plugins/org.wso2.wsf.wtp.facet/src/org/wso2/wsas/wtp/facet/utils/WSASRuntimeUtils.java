package org.wso2.wsas.wtp.facet.utils;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

import org.eclipse.core.runtime.IProgressMonitor;
import org.wso2.wsf.wtp.core.plugin.data.ServerModel;
import org.wso2.wsf.wtp.core.plugin.messages.WSASCoreUIMessages;
import org.wso2.wsf.wtp.core.utils.FileUtils;
import org.wso2.wsf.wtp.core.utils.RuntimePropertyUtils;
import org.wso2.wsf.wtp.core.utils.WSASCoreUtils;

public class WSASRuntimeUtils {

	public static String  copyWSASWebapp(IProgressMonitor monitor, String wsasHome) {
		String tempWarLocation = null;
		try {
			File tempWSASDir = new File (WSASCoreUtils.tempWSASDirectory());
			if (tempWSASDir.exists()) {
				tempWSASDir.delete();
			}
			tempWSASDir.mkdirs();
			if (tempWSASDir.isDirectory()) {
				tempWarLocation = WSASCoreUtils.addAnotherNodeToPath(
															WSASCoreUtils.tempWSASDirectory(),
															WSASCoreUIMessages.DIR_TEMPWAR);
			File tempWarLocationFile= new File(tempWarLocation);
			if (tempWarLocationFile.exists()) {
				tempWarLocationFile.delete();
			}
			tempWarLocationFile.mkdirs();
					
					//Copy the WSAS Web Application.
					String wsasWebappLocation = RuntimePropertyUtils.getWSASWebappLocation(
															ServerModel.getWSASServerPath()
											 	);
					
					FileUtils.copyDirectory(new File(wsasWebappLocation), new File(tempWarLocation));
					
					String tempWarWEBINFDir = FileUtils.addAnotherNodeToPath(
															tempWarLocation,	
																"WEB-INF");
					
					//Copy the WSAS lib Application.
					String wsasLibLocation = RuntimePropertyUtils.getWSASWebappLibLocation(
															ServerModel.getWSASServerPath()
											 );
					
					String tempWarLibDir = FileUtils.addAnotherNodeToPath(
														tempWarWEBINFDir, 
														"lib");
					
					File tempWarLibDirFile = new File(tempWarLibDir);
					if (tempWarLibDirFile.exists()) {
						tempWarLibDirFile.delete();
					}
					tempWarLibDirFile.mkdirs();
										
					
					FileUtils.copyDirectory(new File(wsasLibLocation), new File(tempWarLibDir));

					//Copy the WSAS conf Application.
					String wsasConfLocation = RuntimePropertyUtils.getWSASWebappConfLocation(
															ServerModel.getWSASServerPath()
											 );
					
					String tempWarConfDir = FileUtils.addAnotherNodeToPath(
							tempWarWEBINFDir, 
					"conf");

					File tempWarConfDirFile = new File(tempWarConfDir);
					if (tempWarConfDirFile.exists()) {
						tempWarConfDirFile.delete();
				}
					tempWarConfDirFile.mkdirs();					
				
					FileUtils.copyDirectory(new File(wsasConfLocation), new File(tempWarConfDir));								
					
					//Copy the WSAS database Application.
					String wsasDatabaseLocation = RuntimePropertyUtils.getWSASWebappDatabaseLocation(
															ServerModel.getWSASServerPath()
											 );
					
					String tempWarDatabaseDir = FileUtils.addAnotherNodeToPath(
							tempWarWEBINFDir, 
					"database");

					File tempWarDatabaseDirFile = new File(tempWarDatabaseDir);
					if (tempWarDatabaseDirFile.exists()) {
						tempWarDatabaseDirFile.delete();
					}
					tempWarDatabaseDirFile.mkdirs();					
					
					FileUtils.copyDirectory(new File(wsasConfLocation), new File(tempWarDatabaseDir));
					
					
					
					FileUtils.copyDirectory(new File(wsasDatabaseLocation), new File(tempWarLocation));					
					
					//Copy the WSAS repository Application.
					String wsasRepoLocation = RuntimePropertyUtils.getWSASWebappRepositoryLocation(
															ServerModel.getWSASServerPath()
											 );

					String tempRepositoryDir = FileUtils.addAnotherNodeToPath(
							tempWarWEBINFDir, 
					"repository");

					File tempRepositoryDirFile = new File(tempRepositoryDir);
					if (tempRepositoryDirFile.exists()) {
						tempRepositoryDirFile.delete();
					}
					tempRepositoryDirFile.mkdirs();	
					
					
					FileUtils.copyDirectory(new File(wsasRepoLocation), new File(tempRepositoryDir));					
					
		
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();	
		} catch (IOException e) {
			e.printStackTrace();
		}

		return tempWarLocation;
	}
	
		    
}

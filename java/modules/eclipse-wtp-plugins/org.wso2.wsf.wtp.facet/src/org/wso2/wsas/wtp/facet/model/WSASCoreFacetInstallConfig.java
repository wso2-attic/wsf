package org.wso2.wsas.wtp.facet.model;

import java.io.File;

import org.eclipse.wst.common.project.facet.core.IActionConfigFactory;

public final class WSASCoreFacetInstallConfig {
	private String wsasLocation;

	public String getWSASLocation(){
		return this.wsasLocation;
	}

	public void setWSASLocation( final String location ) {
		if(new File(location).isDirectory()){
			this.wsasLocation = location;
		}else{
			this.wsasLocation = null;
		}
	}

	public static final class Factory implements IActionConfigFactory {
		public Object create() {
			return new WSASCoreFacetInstallConfig();
			//return null;
		}
	}
}
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
package org.wso2.wsf.ide.consumption.ui.wizard.client;

import org.eclipse.wst.command.internal.env.core.data.DataMappingRegistry;
import org.eclipse.wst.command.internal.env.core.fragment.CommandFragment;
import org.eclipse.wst.command.internal.env.core.fragment.CommandFragmentFactory;
import org.eclipse.wst.command.internal.env.core.fragment.SimpleFragment;
import org.eclipse.wst.command.internal.env.ui.widgets.CanFinishRegistry;
import org.eclipse.wst.command.internal.env.ui.widgets.CommandWidgetBinding;
import org.eclipse.wst.command.internal.env.ui.widgets.WidgetContributor;
import org.eclipse.wst.command.internal.env.ui.widgets.WidgetContributorFactory;
import org.eclipse.wst.command.internal.env.ui.widgets.WidgetRegistry;
import org.wso2.wsf.ide.consumption.core.data.DataModel;
import org.wso2.wsf.ide.consumption.core.messages.WSASConsumptionUIMessages;
import org.wso2.wsf.ide.consumption.ui.widgets.WSASProxyWidget;

public class WebServiceClientWSASType implements CommandWidgetBinding {
	
	DataModel model;
	
	public WebServiceClientWSASType(DataModel model){
		this.model = model;
	}

	
	  /* (non-Javadoc)
	   * @see org.eclipse.wst.command.env.ui.widgets.CommandWidgetBinding#registerDataMappings
	   * (org.eclipse.wst.command.internal.env.core.data.DataMappingRegistry)
	   */
	  public void registerDataMappings(DataMappingRegistry dataRegistry) {
	  	// AxisClientDefaultingCommand  	
	    // dataRegistry.addMapping( WSASClientDefaultingCommand.class, 
		// "CustomizeClientMappings", WSASProxyWidget.class );
	    
	  }
	  
	  /* (non-Javadoc)
	   * @see org.eclipse.wst.command.env.ui.widgets.CommandWidgetBinding#registerWidgetMappings
	   * (org.eclipse.wst.command.env.ui.widgets.WidgetRegistry)
	   */
	  public void registerWidgetMappings(WidgetRegistry widgetRegistry) {
	   
	    widgetRegistry.add( "AxisClientStart", 
	        WSASConsumptionUIMessages.PAGE_TITLE_WS_WSAS_PROXY,
	        WSASConsumptionUIMessages.PAGE_DESC_WS_WSAS_PROXY,
	        new WidgetContributorFactory()
	        {
	          public WidgetContributor create()
	          {
	            return new WSASProxyWidget(model);
	          }
	        } );
	    
	  }
	  
	  /* (non-Javadoc)
	   * @see org.eclipse.wst.command.internal.env.core.fragment
	   * .CommandFragmentFactoryFactory#create()
	   */
	  public CommandFragmentFactory create() 
	  {
	    return new CommandFragmentFactory()
	           {
	             public CommandFragment create()
	             {
	               //dead code - doesn't matter what gets returned here.
	               return new SimpleFragment();
	             }
	           };
	  }
	  /* (non-Javadoc)
	   * @see org.eclipse.wst.command.env.ui.widgets.CommandWidgetBinding#registerCanFinish
	   * (org.eclipse.wst.command.env.ui.widgets.CanFinishRegistry)
	   */
	  public void registerCanFinish(CanFinishRegistry canFinishRegistry){
	  }
	  
	  public void setWebServiceDataModel( DataModel model ){
			this.model = model;
	  }
}

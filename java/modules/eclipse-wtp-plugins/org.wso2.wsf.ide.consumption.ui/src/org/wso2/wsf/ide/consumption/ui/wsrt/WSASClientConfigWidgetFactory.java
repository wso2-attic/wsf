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
package org.wso2.wsf.ide.consumption.ui.wsrt;

import org.eclipse.wst.command.internal.env.core.data.DataMappingRegistry;
import org.eclipse.wst.command.internal.env.ui.widgets.INamedWidgetContributor;
import org.eclipse.wst.command.internal.env.ui.widgets.INamedWidgetContributorFactory;
import org.eclipse.wst.command.internal.env.ui.widgets.WidgetBindingToWidgetFactoryAdapter;
import org.wso2.wsf.ide.consumption.core.command.WSASClientDefaultingCommand;
import org.wso2.wsf.ide.consumption.core.data.DataModel;
import org.wso2.wsf.ide.consumption.core.messages.WSASConsumptionUIMessages;
import org.wso2.wsf.ide.consumption.ui.widgets.WSASProxyWidget;
import org.wso2.wsf.ide.consumption.ui.wizard.client.WebServiceClientWSASType;

public class WSASClientConfigWidgetFactory implements INamedWidgetContributorFactory{
	private INamedWidgetContributor             proxyConfigWidget;
	private INamedWidgetContributor             mappingsWidget;
	private WSASProxyWidget                     proxyWidget;
	private WidgetBindingToWidgetFactoryAdapter adapter;
	private DataModel 							model;
	private WebServiceClientWSASType           wsClientWSASType;
	private DataMappingRegistry dataRegistry;
	
	public WSASClientConfigWidgetFactory(){
	}
	
	public INamedWidgetContributor getFirstNamedWidget() {
		init();
		//wsClientWSASType.setWebServiceDataModel(model);
		return proxyConfigWidget;
	}

	public INamedWidgetContributor getNextNamedWidget( INamedWidgetContributor widgetContributor) {
	  return widgetContributor == proxyConfigWidget && proxyWidget.isGenProxy() 
	  								? mappingsWidget 
	  								: null;
	}
	
	public void registerDataMappings(DataMappingRegistry dataRegistry) {
		this.dataRegistry=dataRegistry;
		// Map the data model from the defaulting command to this widget factory.
		// The framework will actually to the call to getWebServiceDataModel in
		// the ExampleDefaultingCommand class and then call the setWebServiceDataModel
		// method in this class.
		dataRegistry.addMapping( WSASClientDefaultingCommand.class, 
								 WSASConsumptionUIMessages.LABEL_DATA_MODEL, 
								 WSASClientConfigWidgetFactory.class );
	}
	
	public void setWebServiceDataModel( DataModel model ){
		this.model = model;
	}
	
	private void init(){
		  wsClientWSASType = new WebServiceClientWSASType(model);
		  adapter = new WidgetBindingToWidgetFactoryAdapter(wsClientWSASType );
		  proxyConfigWidget = adapter.getWidget( "AxisClientStart" );
		  proxyWidget       = (WSASProxyWidget)proxyConfigWidget
		  				.getWidgetContributorFactory().create();
		  mappingsWidget   = adapter.getWidget( "AxisClientBeanMapping" );
		  adapter.registerDataMappings( dataRegistry );

	}
}

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

package org.wso2.wsf.ide.creation.ui.wsrt;

import org.eclipse.wst.command.internal.env.core.data.DataMappingRegistry;
import org.eclipse.wst.command.internal.env.ui.widgets.INamedWidgetContributor;
import org.eclipse.wst.command.internal.env.ui.widgets.INamedWidgetContributorFactory;
import org.eclipse.wst.command.internal.env.ui.widgets.SimpleWidgetContributor;
import org.eclipse.wst.command.internal.env.ui.widgets.WidgetContributor;
import org.eclipse.wst.command.internal.env.ui.widgets.WidgetContributorFactory;
import org.eclipse.wst.command.internal.env.ui.widgets.WidgetDataContributor;
import org.wso2.wsf.ide.creation.core.command.WSASDefaultingCommand;
import org.wso2.wsf.ide.creation.core.data.DataModel;
import org.wso2.wsf.ide.creation.core.messages.WSASCreationUIMessages;
import org.wso2.wsf.ide.creation.ui.widgets.bean.ServicesXMLSelectBeanWidget;

public class WSASBeanConfigWidgetFactory implements INamedWidgetContributorFactory {

	private SimpleWidgetContributor  servicesXMLSelectWidgetContrib;
	private DataModel                model;

	public WSASBeanConfigWidgetFactory(){	  
	}

	public INamedWidgetContributor getFirstNamedWidget(){
		if( servicesXMLSelectWidgetContrib == null ) init();
		return servicesXMLSelectWidgetContrib;
	}

	public INamedWidgetContributor getNextNamedWidget( INamedWidgetContributor widgetContributor){
		if( servicesXMLSelectWidgetContrib == null ) init();
		INamedWidgetContributor nextWidgetContrib = null;
		return nextWidgetContrib;
	}

	public void registerDataMappings(DataMappingRegistry dataRegistry) 
	{
		// Map the data model from the defaulting command to this widget factory.
		// The framework will actually to the call to getWebServiceDataModel in
		// the ExampleDefaultingCommand class and then call the setWebServiceDataModel
		// method in this class.
		dataRegistry.addMapping(WSASDefaultingCommand.class, 
								WSASCreationUIMessages.LABEL_DATA_MODEL, 
								WSASBeanConfigWidgetFactory.class );
	}

	public void setWebServiceDataModel( DataModel model ){
		this.model = model;
	}

	private void init(){
		//Pages of WSAS Web Services Java Bean Scenario
		ServicesXMLSelectBeanWidget servicesXMLSelectWidget = 
								new ServicesXMLSelectBeanWidget(model);
		servicesXMLSelectWidgetContrib  = createWidgetContributor( 
				WSASCreationUIMessages.LABEL_WSAS_PREFERENCE_PAGE_HEADING,
				WSASCreationUIMessages.LABEL_WSAS_PREFERENCE_PAGE_SUB_HEADING, 
				servicesXMLSelectWidget );
	}

	private SimpleWidgetContributor createWidgetContributor(String title, 
															String description, 
															final WidgetDataContributor contributor){
		SimpleWidgetContributor widgetContrib  = new SimpleWidgetContributor();
		widgetContrib.setTitle(title);
		widgetContrib.setDescription(description);
		widgetContrib.setFactory( new WidgetContributorFactory(){
			public WidgetContributor create(){
				return contributor;
			}
		});
		return widgetContrib;
	}   
}

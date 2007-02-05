package org.wso2.wsf.wtp.ws.creation.ui.wsrt;

import org.eclipse.wst.command.internal.env.core.data.DataMappingRegistry;
import org.eclipse.wst.command.internal.env.ui.widgets.INamedWidgetContributor;
import org.eclipse.wst.command.internal.env.ui.widgets.INamedWidgetContributorFactory;
import org.eclipse.wst.command.internal.env.ui.widgets.SimpleWidgetContributor;
import org.eclipse.wst.command.internal.env.ui.widgets.WidgetContributor;
import org.eclipse.wst.command.internal.env.ui.widgets.WidgetContributorFactory;
import org.eclipse.wst.command.internal.env.ui.widgets.WidgetDataContributor;
import org.wso2.wsf.wtp.ws.creation.ui.WSASCreationUIMessages;
import org.wso2.wsf.wtp.ws.creation.ui.command.WSASDefaultingCommand;
import org.wso2.wsf.wtp.ws.creation.ui.data.DataModel;
import org.wso2.wsf.wtp.ws.creation.ui.widgets.bean.ServicesXMLSelectBeanWidget;

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
		ServicesXMLSelectBeanWidget servicesXMLSelectWidget = new ServicesXMLSelectBeanWidget(model);
		servicesXMLSelectWidgetContrib  = createWidgetContributor( 
				WSASCreationUIMessages.LABEL_AXIS2_PREFERENCE_PAGE_HEADING,
				WSASCreationUIMessages.LABEL_AXIS2_PREFERENCE_PAGE_SUB_HEADING, 
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

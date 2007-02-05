package org.wso2.wsf.wtp.ws.creation.ui.wsrt;

import java.util.Vector;

import org.eclipse.wst.command.internal.env.core.ICommandFactory;
import org.eclipse.wst.command.internal.env.core.SimpleCommandFactory;
import org.eclipse.wst.common.environment.IEnvironment;
import org.eclipse.wst.ws.internal.wsrt.AbstractWebService;
import org.eclipse.wst.ws.internal.wsrt.IContext;
import org.eclipse.wst.ws.internal.wsrt.ISelection;
import org.eclipse.wst.ws.internal.wsrt.WebServiceInfo;
import org.eclipse.wst.ws.internal.wsrt.WebServiceScenario;
import org.wso2.wsf.wtp.ws.creation.ui.command.WSASBUCommand;
import org.wso2.wsf.wtp.ws.creation.ui.command.WSASBUServiceCreationCommand;
import org.wso2.wsf.wtp.ws.creation.ui.command.WSASDefaultingCommand;
import org.wso2.wsf.wtp.ws.creation.ui.command.WSASServicesXMLValidationCommand;
import org.wso2.wsf.wtp.ws.creation.ui.command.WSASWebservicesServerCommand;
import org.wso2.wsf.wtp.ws.creation.ui.data.DataModel;

public class WSASWebService extends AbstractWebService{

    public WSASWebService(WebServiceInfo info) {
        super(info);
    }

    public ICommandFactory assemble(IEnvironment env, IContext ctx,
                                    ISelection sel, String project, String earProject){
        return null;
    }

    public ICommandFactory deploy(IEnvironment env, IContext ctx, ISelection sel,
                                  String project, String earProject){
        return null;
    }

    public ICommandFactory develop(IEnvironment env, IContext ctx, ISelection sel,
                                   String project, String earProject){
        Vector commands = new Vector();
        DataModel model = new DataModel();

        model.setWebProjectName(project);

        if (ctx.getScenario().getValue() == WebServiceScenario.BOTTOMUP)
        {
            commands.add(new WSASDefaultingCommand( model,this, ctx.getScenario().getValue() ) );
            commands.add(new WSASBUCommand( model ) );
//			commands.add(new WSASServicesXMLValidationCommand());
            commands.add(new WSASBUServiceCreationCommand(model,this,project));
            commands.add(new WSASWebservicesServerCommand(model, ctx.getScenario().getValue() ));
        }
        else if (ctx.getScenario().getValue() == WebServiceScenario.TOPDOWN){
        }
        else{
            return null;
        }

        return new SimpleCommandFactory(commands);
    }

    public ICommandFactory install(IEnvironment env, IContext ctx, ISelection sel,
                                   String project, String earProject){
        return null;
    }

    public ICommandFactory run(IEnvironment env, IContext ctx, ISelection sel,
                               String project, String earProject){
        return null;
    }
}

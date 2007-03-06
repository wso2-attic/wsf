package org.wso2.wsas.wtp.facet.ui;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.DirectoryDialog;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;
import org.eclipse.wst.common.project.facet.ui.AbstractFacetWizardPage;
import org.wso2.wsas.wtp.facet.model.WSASCoreFacetInstallConfig;
import org.wso2.wsf.wtp.core.plugin.data.ServerModel;
import org.wso2.wsf.wtp.core.plugin.messages.WSASCoreUIMessages;

public final class WSASFacetInstallPage extends AbstractFacetWizardPage
{
    private WSASCoreFacetInstallConfig wsasConfig;
    private Text wsasLocationTextField;
    private Button browseButton;
    

    public WSASFacetInstallPage() {
        super( "wsas.core.facet.install.page" );

        setTitle( "WSAS Core Facet" );
        setDescription( "Configure the WSAS Installation Location." );
    }

    public void createControl( final Composite parent ) {
        final Composite composite = new Composite( parent, SWT.NONE );
        composite.setLayout( new GridLayout( 1, false ) );

        final Label label = new Label( composite, SWT.NONE );
        label.setLayoutData( gdhfill() );
        label.setText( "WSAS Location:" );

        this.wsasLocationTextField = new Text( composite, SWT.BORDER );
        this.wsasLocationTextField.setLayoutData( gdhfill() );
        this.wsasLocationTextField.setText( "" );
        this.wsasLocationTextField.setLayoutData(gdhfill());
        
		this.browseButton = new Button( composite, SWT.NONE );
		this.browseButton.setText(WSASCoreUIMessages.LABEL_BROUSE);
		//this.browseButton.setLocation(520,30);
		//this.browseButton.setSize(70, 20);
		this.browseButton.addSelectionListener( new SelectionAdapter()
		{
			public void widgetSelected(SelectionEvent e)
			{
				handleBrowse(composite.getShell());
			}     
		}); 

		setControl( composite );
    }

    public void setConfig( final Object config ) {
        this.wsasConfig = (WSASCoreFacetInstallConfig) config;
    }

    public void transferStateToConfig() {
        this.wsasConfig.setWSASLocation( this.wsasLocationTextField.getText() );
    }

    private static GridData gdhfill() {
        return new GridData( GridData.FILL_HORIZONTAL );
    }
    
	/**
	 * Pops up the file browse dialog box
	 */
	private void handleBrowse(Shell parent) {
		DirectoryDialog fileDialog = new DirectoryDialog(parent);
		String fileName = fileDialog.open();
		if (fileName != null) {
			wsasLocationTextField.setText(fileName);
			ServerModel.setWSASServerPath( wsasLocationTextField.getText() );
		}
	}
}


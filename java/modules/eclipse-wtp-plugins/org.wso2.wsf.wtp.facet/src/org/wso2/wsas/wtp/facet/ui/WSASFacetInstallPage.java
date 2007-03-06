package org.wso2.wsas.wtp.facet.ui;

import java.io.File;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
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
import org.wso2.wsf.wtp.core.utils.RuntimePropertyUtils;

public final class WSASFacetInstallPage extends AbstractFacetWizardPage
{
    private WSASCoreFacetInstallConfig wsasConfig;
    private Text wsasLocationTextField;
    private Button browseButton;
    private Label  statusLabel, fillLabel1, fillLabel2;
    

    public WSASFacetInstallPage() {
        super( "wsas.core.facet.install.page" );

        setTitle( "WSAS Core Facet" );
        setDescription( "Configure the WSAS Installation Location." );
    }

    public void createControl( final Composite parent ) {
        final Composite composite = new Composite( parent, SWT.NONE );
        composite.setLayout( new GridLayout( 3, false ) );

        final Label label = new Label( composite, SWT.NONE );
        label.setLayoutData( gdhfill() );
        label.setText( "WSAS Location:" );

        this.wsasLocationTextField = new Text( composite, SWT.BORDER );
        this.wsasLocationTextField.setLayoutData( gdhfill() );
        this.wsasLocationTextField.setText((RuntimePropertyUtils.alreadyWSASHomeSet())?
												ServerModel.getWSASServerPath():"");
        this.wsasLocationTextField.setLayoutData(gdhfill());
        this.wsasLocationTextField.addModifyListener( new ModifyListener(){
			public void modifyText(ModifyEvent e){
				checkAndSetRuntimeCheckField();
			}
		});
        
		this.browseButton = new Button( composite, SWT.NONE );
		this.browseButton.setText(WSASCoreUIMessages.LABEL_BROUSE);
		this.browseButton.addSelectionListener( new SelectionAdapter()	{
			public void widgetSelected(SelectionEvent e){
				handleBrowse(composite.getShell());
			}     
		}); 
		
		fillLabel1 = new Label(composite, SWT.NONE );
		fillLabel1.setLayoutData(gdhfill());
		
		statusLabel = new Label( composite, SWT.NONE );
		statusLabel.setLayoutData(gdhfill());
		statusLabel.setAlignment(SWT.CENTER);
		
		fillLabel1 = new Label(composite, SWT.NONE );
		fillLabel1.setLayoutData(gdhfill());
		
        checkAndSetRuntimeCheckField();

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
	
	
	private void statusUpdate(boolean inStatus){
		if (inStatus) {
			statusLabel.setText(WSASCoreUIMessages.LABEL_WSAS_RUNTIME_LOAD);
			this.setErrorMessage(null);
			this.setPageComplete(true);
		} else {
			statusLabel.setText(WSASCoreUIMessages.LABEL_WSAS_RUNTIME_LOAD_ERROR);
			this.setErrorMessage(WSASCoreUIMessages.LABEL_WSAS_RUNTIME_LOAD_ERROR);
			this.setPageComplete(false);
		}
	}
	
	private boolean runtimeExist(String path){
		File wsasHomeDir = new File(path);
		if (wsasHomeDir.isDirectory()) {
			String wsasDistPath = RuntimePropertyUtils.getWSASWebappLocation(wsasHomeDir.getAbsolutePath());
			String wsasLibPath = RuntimePropertyUtils.getWSASWebappLibLocation(wsasHomeDir.getAbsolutePath());
			
			if (new File(wsasDistPath).isDirectory() &&
					RuntimePropertyUtils.checkWSASLibExsistance(wsasLibPath)) {
					statusUpdate(true);
					return true;
			} else {
				statusUpdate(false);
				return false;
			}
		}else{
			statusUpdate(false);
			return false;
		}
	}
	

	private void checkAndSetRuntimeCheckField(){
		if (runtimeExist(wsasLocationTextField.getText())) {
			ServerModel.setWSASServerPath( wsasLocationTextField.getText() );
		}
	}
	
	
}


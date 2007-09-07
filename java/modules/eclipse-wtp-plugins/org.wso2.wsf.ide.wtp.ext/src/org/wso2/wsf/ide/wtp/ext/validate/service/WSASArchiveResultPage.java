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
package org.wso2.wsf.ide.wtp.ext.validate.service;

import java.net.URL;

import org.eclipse.swt.SWT;
import org.eclipse.swt.browser.Browser;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Group;

public class WSASArchiveResultPage extends AbstractArchiveValidateWizardPage{
	
	Browser browser;
	Button browserPopUpCheck;
	boolean correctURLSet;
	URL browserURL;
	
    public WSASArchiveResultPage(){
        super("page2");
    }

    /* (non-Javadoc)
     * @see org.apache.axis2.tool.service.eclipse.ui.AbstractServiceWizardPage#initializeDefaultSettings()
     */
    protected void initializeDefaultSettings() {
    }
    
    /* (non-Javadoc)
     * @see org.eclipse.jface.dialogs.IDialogPage#createControl(org.eclipse.swt.widgets.Composite)
     */
    public void createControl(Composite parent) {
        final Composite container = new Composite(parent, SWT.NULL);
        GridLayout lo = new GridLayout(1,true);
        container.setLayout(lo);
        
        Group resultsGroup = new Group(container, SWT.NONE);
        resultsGroup.setText("Validation Results : ");
        GridLayout layout = new GridLayout();
        layout.numColumns = 14;
        resultsGroup.setLayout(layout);
        GridData gd = new GridData(GridData.FILL_HORIZONTAL | GridData.VERTICAL_ALIGN_FILL);
        resultsGroup.setLayoutData(gd);
        
        Browser browser = new Browser(resultsGroup, SWT.NONE);
        gd = new GridData(GridData.FILL_HORIZONTAL | GridData.VERTICAL_ALIGN_FILL);
        gd.horizontalSpan = 14;
        browser.setLayoutData(gd);
        
        browserPopUpCheck = new Button(container,SWT.CHECK);
		browserPopUpCheck.setLayoutData(gd);
		browserPopUpCheck.setText(WSASArchiveValidatePlugin.getResourceString("page2.browser.check"));
		browserPopUpCheck.setSelection(true);
		browserPopUpCheck.addSelectionListener(new SelectionListener(){
			public void widgetDefaultSelected(SelectionEvent e) {
			}
			public void widgetSelected(SelectionEvent e) {
			}
		});
        
        setPageComplete(false);
        setControl(container);
		
        fillBrowserWithResults();
		
    }
    
    
	public boolean getWizardComplete() {
		return false;
	}
	
	private void fillBrowserWithResults(){
		if(correctURLSet){
			browser.setUrl(browserURL.toString());
			updateStatus(null);
		}else{
			updateStatus("Error Occured Displaying Results !!");
		}
	}
	
	public void setBrowserURL(URL url){
		this.browserURL = url;
		correctURLSet = true;
	}
	
	
	
}

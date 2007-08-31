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
package org.wso2.wsf.ide.wtp.ext.java2wsdl;

import java.util.ArrayList;
import java.util.Iterator;

import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.events.MouseAdapter;
import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.DirectoryDialog;
import org.eclipse.swt.widgets.FileDialog;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.List;
import org.eclipse.swt.widgets.Text;
import org.wso2.wsf.ide.wtp.ext.java2wsdl.util.ClassFileReader;

public class JavaSourceSelectionPage extends AbstractJAVA2WSDLWizardPage{

    private Composite container;
    private Text javaClassNameBox;
    private List javaClasspathList;
    private Label statusLabel;

    public JavaSourceSelectionPage() {  
    	super("page1");
    }

    protected void initializeDefaultSettings() {
        settings.put(JAVA_CLASS_NAME, "");
        settings.put(JAVA_CLASS_PATH_ENTRIES, new String[]{""});
    }

    /*
     * (non-Javadoc)
     * @see org.apache.axis2.tool.codegen.eclipse.ui.CodegenPage#getPageType()
     */
    public int getPageType() {
        return JAVA_2_WSDL_TYPE;
    }

    /*
     * (non-Javadoc)
     * @see org.eclipse.jface.dialogs.IDialogPage#createControl(org.eclipse.swt.widgets.Composite)
     */
    public void createControl(Composite parent) {
        container = new Composite(parent, SWT.NULL);
        GridLayout layout = new GridLayout();
        container.setLayout(layout);
        layout.numColumns = 3;
        layout.verticalSpacing = 9;

        GridData gd = new GridData(GridData.FILL_HORIZONTAL);
        
        //class name  entry
        Label label = new Label(container, SWT.NULL);
        label.setText(WSASJAVA2WSDLPlugin.getResourceString("page1.classname.label"));
        
        gd = new GridData(GridData.FILL_HORIZONTAL);
        gd.horizontalSpan = 2;
        javaClassNameBox = new Text(container,SWT.BORDER);
        javaClassNameBox.setLayoutData(gd);
        javaClassNameBox.setText(settings.get(JAVA_CLASS_NAME));
        javaClassNameBox.addModifyListener(new ModifyListener(){
            public void modifyText(ModifyEvent e){
                handleClassNameTextChange();
             }
         });
        
        //class path entry
        gd = new GridData(GridData.FILL_HORIZONTAL);
        gd.horizontalSpan=3;
        label = new Label(container, SWT.NULL);
        label.setLayoutData(gd);
        label.setText(WSASJAVA2WSDLPlugin.getResourceString("page1.classpath.label"));
        
        
        
        gd = new GridData(GridData.FILL_HORIZONTAL);
        Button addDirButton = new Button(container,SWT.PUSH);
        addDirButton.setLayoutData(gd);
        addDirButton.setText(WSASJAVA2WSDLPlugin.getResourceString("page1.addDir.label"));
        addDirButton.addMouseListener(new MouseAdapter(){
        	public void mouseUp(MouseEvent e) {
        		handleDirectoryBrowse();
        	}
        });
        
        gd = new GridData(GridData.FILL_HORIZONTAL);
        Button addJarButton = new Button(container,SWT.PUSH);
        addJarButton.setLayoutData(gd);
        addJarButton.setText(WSASJAVA2WSDLPlugin.getResourceString("page1.addJar.label"));
        addJarButton.addMouseListener(new MouseAdapter(){
        	public void mouseUp(MouseEvent e) {
        		handleFileBrowse();
        	}
        });
        
        gd = new GridData(GridData.FILL_HORIZONTAL);
        Button removeEntryButton = new Button(container,SWT.PUSH);
        removeEntryButton.setLayoutData(gd);
        removeEntryButton.setText(WSASJAVA2WSDLPlugin.getResourceString("page1.removeEntry.label"));
        removeEntryButton.addMouseListener(new MouseAdapter(){
        	public void mouseUp(MouseEvent e) {
        		handleRemove();
        	}
        });
        
		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3;
		gd.verticalSpan = 2;
        ScrolledComposite c2 = new ScrolledComposite(container, SWT.V_SCROLL);
        c2.setExpandHorizontal(false);
        c2.setExpandVertical(false);
		c2.setLayoutData(gd);
		javaClasspathList = new List(c2,SWT.READ_ONLY |SWT.BORDER | SWT.V_SCROLL);
		javaClasspathList.setLayoutData(gd);
        settings.put(JAVA_CLASS_PATH_ENTRIES, new String[]{});
		javaClasspathList.setItems(settings.getArray(JAVA_CLASS_PATH_ENTRIES));
		javaClasspathList.setSize(600, 250);
		c2.setContent(javaClasspathList);

        gd = new GridData(GridData.FILL_HORIZONTAL);
        Button tryLoadButton = new Button(container,SWT.PUSH);
        tryLoadButton.setLayoutData(gd);
        tryLoadButton.setText(WSASJAVA2WSDLPlugin.getResourceString("page1.tryLoad.label"));
        tryLoadButton.addMouseListener(new MouseAdapter(){
        	public void mouseUp(MouseEvent e) {
        		java.util.List errorListener = new ArrayList();
        		if (!ClassFileReader.tryLoadingClass(getClassName(),
        				getClassPathList(),
        				errorListener)){
        			Iterator it = errorListener.iterator();
        			while(it.hasNext()){
        				Object nextObject = it.next();
        				String errorMessage = nextObject==null?WSASJAVA2WSDLPlugin
				                .getResourceString("page1.unknownError.label"):nextObject.toString();
						updateStatus(errorMessage);
						updateStatusTextField(false,errorMessage);
        			}
        			
        		}else{
        			updateStatusTextField(true,WSASJAVA2WSDLPlugin
			                .getResourceString("page1.successLoading.label"));
        			updateStatus(null);
        			
        		}
        	}
        });
        
        gd = new GridData(GridData.FILL_HORIZONTAL);
        gd.horizontalSpan = 2;
        statusLabel = new Label(container,SWT.NULL);
        statusLabel.setLayoutData(gd);
        
		//filling label 
		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3;
		Label fillLabel3 = new Label(container, SWT.HORIZONTAL | SWT.SEPARATOR);
		fillLabel3.setLayoutData(gd);
		
		gd = new GridData(GridData.FILL_HORIZONTAL);
		gd.horizontalSpan = 3; 
		Label hintLabel = new Label(container, SWT.NULL);
		hintLabel
				.setText(WSASJAVA2WSDLPlugin
						.getResourceString("page1.hint.caption"));
		hintLabel.setLayoutData(gd);
        
        setPageComplete(false);
        setControl(container);
        
        if (restoredFromPreviousSettings){
            handleClassNameTextChange();
        }

    }

    
    /**
     * Pops up the file browse directory box
     */
    private void handleDirectoryBrowse() {
        DirectoryDialog fileDialog = new DirectoryDialog(this.getShell());
        String dirName = fileDialog.open();
        if (dirName != null) {
        	if (!checkFilenameExistsInList(dirName)){  
        		javaClasspathList.add(dirName);
        		updateListEntries();
        	}
        }
        updateStatusTextField(false,"");
    }
    
    
    /**
     * Remove the path entry
     */
    private void handleRemove() {
        int[] selectionIndices = javaClasspathList.getSelectionIndices();
        for (int i=0;i<selectionIndices.length;i++){
        	javaClasspathList.remove(selectionIndices[i]);
        }
        updateListEntries();
        updateStatusTextField(false,"");
    }
    
   
    /**
     * Pops up the file browse dialog box
     */
    private void handleFileBrowse() {
        FileDialog fileDialog = new FileDialog(this.getShell());
        fileDialog.setFilterExtensions(new String[]{"*.jar"});
        String fileName = fileDialog.open();
        if (fileName != null) {
        	if (!checkFilenameExistsInList(fileName)){
            	javaClasspathList.add(fileName);
            	updateListEntries();
        	}
        }
        updateStatusTextField(false,"");
    }
    
    /**
     * Method checks the list antries and compare that to the file name 
     * return the results of the comparison
     * @param filename to checked
     * @return : boolean result
     */
    private boolean checkFilenameExistsInList(String filename){
    	String[] array = javaClasspathList.getItems();

    	for (int i = 0; i < array.length; i++) {
			if (array[i].equals(filename)) {
				return true;
			}
		}
    	return false;
    }
    
    private void updateStatusTextField(boolean success,String text){
    	if (success){
    		getCodegenWizard().setDefaultNamespaces(javaClassNameBox.getText());
    	}
     	statusLabel.setText(text);
    }
    
    private void updateListEntries(){
    	settings.put(JAVA_CLASS_PATH_ENTRIES,javaClasspathList.getItems());
    }

    private void handleClassNameTextChange(){
        String className = javaClassNameBox.getText();
        settings.put(JAVA_CLASS_NAME,className);
        if (className==null || "".equals(className.trim())){
            updateStatus(WSASJAVA2WSDLPlugin
                    .getResourceString("page1.error.invalidClassName"));
        }else if(className.endsWith(".")){
            updateStatus(WSASJAVA2WSDLPlugin
                    .getResourceString("page1.error.ClassNameNotTerminated"));
        }else{
        	//just leave it
            //updateStatus(null);
        }
    }
    
    /**
     * Returns the class name form the javaClassNameBox
     * @return : String ClassName
     */
    public String getClassName(){
        return javaClassNameBox.getText();
    }
    
    /**
     * Returns the class path list form the classPathList
     * @return : String[] of Classpaths 
     */
    public String[] getClassPathList(){
        return javaClasspathList.getItems();
    }

   
}

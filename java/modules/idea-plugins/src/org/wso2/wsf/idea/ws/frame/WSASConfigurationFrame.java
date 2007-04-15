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
package org.wso2.wsf.idea.ws.frame;

import org.wso2.wsf.idea.ws.bean.WSASConfigurationBean;

import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.*;

public class WSASConfigurationFrame extends JFrame implements ActionListener {
    private int defaultCloseOperation;
    private JLabel wsasLable;
    private JLabel wsasHomeLable;
    private JButton butOK,butCancel;
    private JTextField wsasHomeText;

    public WSASConfigurationFrame(){
        setBackground(Color.white);
        Dimension dim = getPreferredSize();
        setSize(dim);
        setBounds(200, 200, dim.width, dim.height);
        setBounds(200, 200, dim.width, dim.height);
        WSASConfigurationLayout customLayout = new WSASConfigurationLayout();

        setFont(new Font("Helvetica", Font.PLAIN, 12));
        getContentPane().setLayout(customLayout);
        setTitle("WSAS Configuration");

        wsasLable =new JLabel("WSO2 WEB Services Application Server");
        getContentPane().add(wsasLable);

        wsasHomeLable = new JLabel("WSAS Installation Path");
        getContentPane().add(wsasHomeLable);

        wsasHomeText = new JTextField(WSASConfigurationBean.getWsasInstallationPath());
        getContentPane().add(wsasHomeText);

        butOK = new JButton("OK");
        butOK.addActionListener(this);
        getContentPane().add(butOK);

        butCancel = new JButton("Cancel");
        butCancel.addActionListener(this);
        getContentPane().add(butCancel);



    }

    public void actionPerformed(ActionEvent e) {
        Object obj = e.getSource();
        if (obj == butCancel) {
            this.hide();
            setVisible(false);
        } else if (obj == butOK) {
            WSASConfigurationBean.setWsasInstallationPath(wsasHomeText.getText());
            this.hide();
            setVisible(false);
        }
    }

    public void setDefaultCloseOperation(int operation) {
        if (operation != DO_NOTHING_ON_CLOSE &&
                operation != HIDE_ON_CLOSE &&
                operation != DISPOSE_ON_CLOSE &&
                operation != EXIT_ON_CLOSE) {
            throw new IllegalArgumentException("defaultCloseOperation must be one of: DO_NOTHING_ON_CLOSE, HIDE_ON_CLOSE, DISPOSE_ON_CLOSE, or EXIT_ON_CLOSE");
        }
        if (this.defaultCloseOperation != operation) {
            if (operation == EXIT_ON_CLOSE) {
                SecurityManager security = System.getSecurityManager();
                if (security != null) {
                    security.checkExit(0);
                }
            }
            int oldValue = this.defaultCloseOperation;
            this.defaultCloseOperation = operation;
            firePropertyChange("defaultCloseOperation", oldValue, operation);
        }
    }

    public void showUI() {
        pack();
        this.setVisible(true);
        show();
    }


    public JComponent getRootComponent() {
        return this.getRootPane();
    }

}


class WSASConfigurationLayout implements LayoutManager {

    public WSASConfigurationLayout() {
    }

    public void addLayoutComponent(String name, Component comp) {
    }

    public void removeLayoutComponent(Component comp) {
    }

    public Dimension preferredLayoutSize(Container parent) {
        Dimension dim = new Dimension(0, 0);

        Insets insets = parent.getInsets();
        dim.width = 450 + insets.left + insets.right;
        dim.height = 100 + insets.top + insets.bottom;

        return dim;
    }

    public Dimension minimumLayoutSize(Container parent) {
        return new Dimension(0, 0);
    }

    public void layoutContainer(Container parent) {
        Insets insets = parent.getInsets();
        Component c;
        c = parent.getComponent(0);
        if (c.isVisible()) {
            c.setBounds(insets.left + 100, insets.top + 5, 250, 24);
        }
        c = parent.getComponent(1);
        if (c.isVisible()) {
            c.setBounds(insets.left + 10, insets.top + 30, 150, 24);
        }
        c = parent.getComponent(2);
       if (c.isVisible()) {
           c.setBounds(insets.left + 170, insets.top + 30, 250, 24);
       }
       c = parent.getComponent(3);
       if (c.isVisible()) {
           c.setBounds(insets.left + 200, insets.top + 60, 80, 24);
       }
       c = parent.getComponent(4);
       if (c.isVisible()) {
           c.setBounds(insets.left + 285, insets.top + 60, 80, 24);
       }

    }
}


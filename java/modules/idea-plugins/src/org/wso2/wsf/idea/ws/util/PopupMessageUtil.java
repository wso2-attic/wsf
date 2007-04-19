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
package org.wso2.wsf.idea.ws.util;

import com.intellij.openapi.ui.Messages;
import org.wso2.wsf.idea.ws.constant.WSASMessageConstant;

public class PopupMessageUtil {

    public static void popupWarningMessageBox(String warningMessage) {
        Messages.showMessageDialog(
                warningMessage,
                WSASMessageConstant.WARNING_WSAS_HEADING,
                Messages.getWarningIcon()
        );
    }

    public static void popupErrorMessageBox(String errorMessage) {
        Messages.showMessageDialog(
                errorMessage,
                WSASMessageConstant.WARNING_WSAS_HEADING,
                Messages.getErrorIcon()
        );
    }

        public static void popupInformationMessageBox(String infoMessage) {
        Messages.showMessageDialog(
                infoMessage,
                WSASMessageConstant.WARNING_WSAS_HEADING,
                Messages.getInformationIcon()
        );
    }

}

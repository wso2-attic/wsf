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
package org.wso2.wsf.ide.facet.messages;

import org.eclipse.osgi.util.NLS;

public final class WSASFacetUIMessages extends NLS {

	private static final String BUNDLE_NAME = 
				"org.wso2.wsf.ide.facet.messages.WSASFacetUI";//$NON-NLS-1$
	public static final String FILE_SERVLET_API="servletapi";//$NON-NLS-1$

	private WSASFacetUIMessages() {
		// Do not instantiate
	}

	public static String WEB_INF_LIB;
	
	static {
		NLS.initializeMessages(BUNDLE_NAME, WSASFacetUIMessages.class);
	}
}

package org.wso2.wsas.wtp.facet.messages;

import org.eclipse.osgi.util.NLS;

public final class WSASFacetUIMessages extends NLS {

	private static final String BUNDLE_NAME = "org.wso2.wsas.wtp.facet.messages.WSASFacetUI";//$NON-NLS-1$

	private WSASFacetUIMessages() {
		// Do not instantiate
	}

	public static String WEB_INF_LIB;
	
	static {
		NLS.initializeMessages(BUNDLE_NAME, WSASFacetUIMessages.class);
	}
}

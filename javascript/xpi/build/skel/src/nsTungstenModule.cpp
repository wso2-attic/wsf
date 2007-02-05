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
#include "nsCOMPtr.h"
#include "nsplugin.h"
#include "nsIGenericFactory.h"
#include "nsICategoryManager.h"
#include "nsIServiceManager.h"
#include "nsIScriptNameSpaceManager.h"
/* following header required to build on Deer Park 1.6 or more */
/*#include "nsIClassInfoImpl.h"*/
#include "nsIDOMClassInfo.h"
#include "stdio.h"

/// these are the component to register
#include "nsWSRequest.h"
#include "nsWSRequestException.h"
  
/////////////////////////////////////////////////
// Declare extension for DOM
//
/*307fb644-8e62-4303-a2cb-7066607bcfba*/ 
#define WSREQUEST_DOMCI_EXTENSION_CID   \
  { 0x307fb644, 0x8e62, 0x4303, {0xa2, 0xcb, 0x70, 0x66, 0x60, 0x7b, 0xcf, 0xba} }

#define WSREQUEST_DOMCI_EXTENSION_CONTRACTID \
  "@mozilla.org/tungsten-domci-extender;1"

NS_DOMCI_EXTENSION(TungstenWS)
    //Dom info for WSRequest
    static NS_DEFINE_CID(kSOAPHttpRequestCID, NS_WSREQUEST_CID);
    NS_DOMCI_EXTENSION_ENTRY_BEGIN(WSRequest)
        NS_DOMCI_EXTENSION_ENTRY_INTERFACE(nsIWSRequest)
        NS_DOMCI_EXTENSION_ENTRY_INTERFACE(nsIXMLHttpRequest)
        NS_DOMCI_EXTENSION_ENTRY_INTERFACE(nsIJSXMLHttpRequest)
    NS_DOMCI_EXTENSION_ENTRY_END_NO_PRIMARY_IF(WSRequest, PR_TRUE, &kSOAPHttpRequestCID)
NS_DOMCI_EXTENSION_END

/////////////////////////////////////////////////
// Define the constructor function for the objects
//
//NS_GENERIC_FACTORY_CONSTRUCTOR_INIT (nsWSRequest, Init)
NS_GENERIC_FACTORY_CONSTRUCTOR (nsWSRequest)

/////////////////////////////////////////////////
// Declare the class Info
//
NS_DECL_CLASSINFO(nsWSRequest)

NS_DECL_CLASSINFO(nsWSRequestException)


	
/////////////////////////////////////////////////
// Register the components
//
static NS_METHOD nsTungstenwsRegistrationProc(nsIComponentManager *aCompMgr,
                                          nsIFile *aPath,
                                          const char *registryLocation,
                                          const char *componentType,
                                          const nsModuleComponentInfo *info)
{  
  nsresult rv;
  nsCOMPtr<nsIServiceManager> servman =
          do_QueryInterface((nsISupports*)aCompMgr, &rv);
  if (NS_FAILED(rv))
    return rv;


  /**
   * Registering the catagories
   */
  nsCOMPtr<nsICategoryManager> catman;
  rv = servman->GetServiceByContractID(NS_CATEGORYMANAGER_CONTRACTID,
                  NS_GET_IID(nsICategoryManager),
                  getter_AddRefs(catman));

  if (NS_FAILED(rv))
      return rv;

  char *previous;
  char *iidString;
  /**
   * Registering DOM classes
   */
  rv=catman->AddCategoryEntry(JAVASCRIPT_DOM_CLASS,
                        "WSRequest",
                        WSREQUEST_DOMCI_EXTENSION_CONTRACTID,
                        PR_TRUE, PR_TRUE, &previous);
  if (NS_FAILED(rv) )
    return rv; 
  /*nsCRT::free ( previous );*/

  /**
   * Registering DOM interfaces
   */
  iidString = NS_GET_IID(nsIWSRequest).ToString();
  if (!iidString)
  {
    return NS_ERROR_OUT_OF_MEMORY;
  }

  rv = catman->AddCategoryEntry(JAVASCRIPT_DOM_INTERFACE,
                                "nsIWSRequest",
                                iidString,
                                PR_TRUE, PR_TRUE, &previous);
  nsCRT::free(iidString);
  if ( NS_FAILED(rv ) )
  {
    return rv;
  }
  /*nsCRT::free ( previous );*/

  return rv;
}

//////////////////////////////////////////////////
// Undo the registration
//
static NS_METHOD nsTungstenwsUnregistrationProc(nsIComponentManager *aCompMgr,
                                            nsIFile *aPath,
                                            const char *registryLocation,
                                            const nsModuleComponentInfo *info)
{
  nsresult rv;

  nsCOMPtr<nsIServiceManager> servman =
          do_QueryInterface((nsISupports*)aCompMgr, &rv);
  if (NS_FAILED(rv))
    return rv;
    

  nsCOMPtr<nsICategoryManager> catman;
  rv = servman->GetServiceByContractID(NS_CATEGORYMANAGER_CONTRACTID,
                  NS_GET_IID(nsICategoryManager),
                  getter_AddRefs(catman));

  if (NS_FAILED(rv))
      return rv;

  /**
   * Unregistering DOM classes
   */
  rv=catman-> DeleteCategoryEntry ( JAVASCRIPT_DOM_CLASS,
                        "WSRequest",
                        PR_TRUE );

  if (NS_FAILED(rv))
      return rv;

  /**
   * Unregistering DOM interfaces
   */
  char* iidString;
  iidString = NS_GET_IID(nsIWSRequest).ToString();
  if (!iidString)
    return NS_ERROR_OUT_OF_MEMORY;

  rv = catman-> DeleteCategoryEntry(JAVASCRIPT_DOM_INTERFACE,
                                "nsIWSRequest",
                                PR_TRUE );
  nsCRT::free(iidString);
  if ( NS_FAILED(rv ) )
    return rv;

  return NS_OK;
}

//////////////////////////////////////////////////
// Define a table of IDs implemented by the module
//
static const nsModuleComponentInfo components[] = 
{
  { "TungstenWS DOMCI Extender",
    WSREQUEST_DOMCI_EXTENSION_CID,
    WSREQUEST_DOMCI_EXTENSION_CONTRACTID,
    NS_DOMCI_EXTENSION_CONSTRUCTOR(TungstenWS)
  },
  { "WSRequest component",
    NS_WSREQUEST_CID,
    NS_WSREQUEST_CONTRACTID,
    nsWSRequestConstructor,
    nsTungstenwsRegistrationProc,
    nsTungstenwsUnregistrationProc,
    nsnull,
    NS_CI_INTERFACE_GETTER_NAME(nsWSRequest),
    nsnull,
    &NS_CLASSINFO_NAME(nsWSRequest),
    nsIClassInfo::DOM_OBJECT
  },
  { "WSRequestException component",
    NS_TUNGSTENEXCEPTION_CID,
    NS_TUNGSTENEXCEPTION_CONTRACTID,
    nsnull,
    nsnull,
    nsnull,
    nsnull,
    NS_CI_INTERFACE_GETTER_NAME(nsWSRequestException),
    nsnull,
    &NS_CLASSINFO_NAME(nsWSRequestException),
    nsIClassInfo::DOM_OBJECT
  },

};

//////////////////////////////////////////////////
// Define the module
//
NS_IMPL_NSGETMODULE(nsWSRequestWSModule, components)


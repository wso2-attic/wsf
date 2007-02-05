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


#include "nsWSRequestException.h"
#include "nsCOMPtr.h"
#include "nsXPCOM.h"
#include "string.h"
#include "plstr.h"
#include "nsMemory.h"
#include "stdlib.h"
#include "stdio.h"
#include "nsIXPConnect.h"
/** following would requried to compile in Deer Park ver1.6 or later */
//#include "nsIClassInfoImpl.h"

NS_IMPL_ISUPPORTS1_CI(nsWSRequestException, nsIException )

nsWSRequestException::nsWSRequestException(char* aName,
	       	char *aMessage,
	       	nsresult aResult,
                nsISupports* aData,
	       	nsIException* aInner)
{
  
  nsresult rc;
  nsCOMPtr<nsIXPConnect> xpc ( do_GetService(nsIXPConnect::GetCID(), &rc));
  if(NS_SUCCEEDED(rc)) {
      xpc->GetCurrentJSStack( getter_AddRefs(mFrame ) );
  }
 
  mName = PL_strdup ( aName );
  mMessage = PL_strdup ( aMessage );
  mData = aData;
  mResult = aResult;
  mInner = aInner;
}

nsWSRequestException::~nsWSRequestException()
{
  if (mName ) free (mName );
  if (mMessage ) free (mMessage );
}

/* readonly attribute string message; */
NS_IMETHODIMP nsWSRequestException::GetMessage(char * *aMessage)
{
  NS_PRECONDITION( aMessage, "null ptr");
  *aMessage = strdup ( mMessage);
  return NS_OK;
}

/* readonly attribute nsresult result; */
NS_IMETHODIMP nsWSRequestException::GetResult(nsresult *aResult)
{
  NS_PRECONDITION( aResult, "null ptr");
  *aResult = mResult;
  return NS_OK;

}

/* readonly attribute string name; */
NS_IMETHODIMP nsWSRequestException::GetName(char * *aName)
{
  NS_PRECONDITION( aName, "null ptr");
  *aName = strdup ( mName );
  return NS_OK;
}

/* readonly attribute string filename; */
NS_IMETHODIMP nsWSRequestException::GetFilename(char * *aFilename)
{
  
  NS_PRECONDITION( aFilename, "null ptr");
  if (mFrame) {
      return mFrame->GetFilename(aFilename);
  }

  *aFilename = nsnull; 
  return NS_OK;
 ;
}

/* readonly attribute PRUint32 lineNumber; */
NS_IMETHODIMP nsWSRequestException::GetLineNumber(PRUint32 *aLineNumber)
{
  NS_PRECONDITION( aLineNumber, "null ptr");
  if (mFrame) {
      return mFrame-> GetLineNumber ( (PRInt32*) aLineNumber );
  }
  return NS_OK;
}

/* readonly attribute PRUint32 columnNumber; */
NS_IMETHODIMP nsWSRequestException::GetColumnNumber(PRUint32 *aColumnNumber)
{
  return SetException ("COLUMN NUMBER NOT AVAILABLE", 
                       "Implementation doesnt return column Number",
                        nsnull, 
                        NS_ERROR_NOT_IMPLEMENTED );
}

/* readonly attribute nsIStackFrame location; */
NS_IMETHODIMP nsWSRequestException::GetLocation(nsIStackFrame * *aLocation)
{
  NS_ENSURE_ARG_POINTER(aLocation);

  *aLocation = mFrame;
  NS_IF_ADDREF(*aLocation);
  return NS_OK;
}

/* readonly attribute nsIException inner; */
NS_IMETHODIMP nsWSRequestException::GetInner(nsIException * *aInner)
{
  NS_PRECONDITION( aInner, "null ptr");
  *aInner = mInner;
  NS_IF_ADDREF(*aInner);
  return NS_OK;
}

/* readonly attribute nsISupports data; */
NS_IMETHODIMP nsWSRequestException::GetData(nsISupports * *aData)
{
  return NS_OK;
}

/* string toString (); */
NS_IMETHODIMP nsWSRequestException::ToString(char **_retval)
{
  *_retval = (char*) malloc ( sizeof(char) * (strlen(mName) + //exception name
                              2 +                             //': '
                              strlen (mMessage) +             //exception msg
                              1                               //null character
                               ) ) ;
  sprintf(*_retval, "%s: %s", mName, mMessage );

  return NS_OK;
}

nsresult nsWSRequestException::SetException( char* aName,
	       	char* aMessage,
                nsISupports* aData,
	       	nsresult aResult )
{
  nsCOMPtr<nsIExceptionService> xs =
	    do_GetService(NS_EXCEPTIONSERVICE_CONTRACTID);
  if (xs) {
    nsCOMPtr<nsIExceptionManager> xm;
    xs->GetCurrentExceptionManager(getter_AddRefs(xm));
    if ( !xm )
      return NS_ERROR_FAILURE;
    nsCOMPtr<nsIException> old;
    xs->GetCurrentException(getter_AddRefs(old));
    if (old )
    {
      char* sz;
      old-> ToString( &sz );
      printf("%s\n", sz );
    }
    nsCOMPtr<nsIException> exception = 
	    new nsWSRequestException( aName, aMessage, aResult, aData, old);
    if (exception)
    {
      xm-> SetCurrentException( exception);
    }
  }
  return aResult;
}


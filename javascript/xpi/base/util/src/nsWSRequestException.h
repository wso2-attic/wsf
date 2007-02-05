/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef _NS_WSREQUESTNEXCEPTION_
#define _NS_WSREQUESTNEXCEPTION_

//mozilla libraries
#include <plstr.h>
#include <stdlib.h>
/**#include <unistd.h>*/
#include <nsCOMPtr.h>
#include <nsXPCOM.h>
#include <string.h>
#include <nsIVariant.h>
#include <nsIComponentManager.h>
#include <nsComponentManagerUtils.h>
#include <nsMemory.h>
#include <nsCRT.h>

#include <nsIException.h>
#include <nsIServiceManager.h>
#include <nsIExceptionService.h>
#include <nsServiceManagerUtils.h>

#define WSREQUEST_EXCEPTION(name, message, data, result) \
          nsWSRequestException::SetException ( name, message, data, result )


class nsWSRequestException: public nsIException
{
  public:
    NS_DECL_ISUPPORTS
    NS_DECL_NSIEXCEPTION

    nsWSRequestException(char* aName, char* aMessage, nsresult aResult,
                               nsISupports* aData, nsIException* aInner);
    ~nsWSRequestException();
    /* Exception setter */
    static nsresult SetException( char* aName, char* aMessage,
                               nsISupports* aData, nsresult aResult );
  private:

  protected:
    /* member variables  */
    char* mName;
    char* mMessage;
    nsresult mResult;
    nsCOMPtr<nsIException> mInner;
    nsCOMPtr<nsIStackFrame> mFrame;
    nsCOMPtr<nsISupports> mData;
		
};

#define NS_TUNGSTENEXCEPTION_CID 		\
  { /*fddac4b4-2e72-405c-be5d-a9b9ccc91029*/	\
  0xfddac4b4, 0x2e72, 0x405c, 			\
  { 0xbe,0x5d, 0xa9, 0xb9, 0xcc, 0xc9, 0x10, 0x29} }
#define NS_TUNGSTENEXCEPTION_CONTRACTID "@mozilla.org/tungsten/exception;1"

#endif


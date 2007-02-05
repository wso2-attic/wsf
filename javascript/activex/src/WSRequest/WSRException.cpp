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

#include "StdAfx.h"
#include "WSRException.h"

HRESULT WSRException::DispatchError(HRESULT hError, const IID &clsid, LPTSTR szDescription)
{	
	USES_CONVERSION;

	// Convert the description to OLE string
	LPOLESTR wszError = NULL;
	if(szDescription != NULL)
	{
		wszError = T2OLE(szDescription);
	}

	// Get the ICreateErrorInfo Interface
	ICreateErrorInfo *pErrorInfoCreate = NULL;
    HRESULT hSuccess = CreateErrorInfo(&pErrorInfoCreate);
	ATLASSERT(SUCCEEDED(hSuccess));

	pErrorInfoCreate->SetGUID(clsid);
	if(wszError != NULL)
		pErrorInfoCreate->SetDescription(wszError);

	// Get the IErrorInfo interface
	IErrorInfo *pErrorInfo = NULL;
	hSuccess = pErrorInfoCreate->QueryInterface(IID_IErrorInfo,
				(LPVOID *)&pErrorInfo);

	if(FAILED(hSuccess))
	{
		pErrorInfoCreate->Release();
		return hSuccess;
	}
	// Set this error information in the current thread
	hSuccess = SetErrorInfo(0, pErrorInfo);
	if(FAILED(hSuccess))
	{
		pErrorInfoCreate->Release();
		pErrorInfo->Release();
		return hSuccess;
	}

	// Finally release the interfaces
	pErrorInfoCreate->Release();
	pErrorInfo->Release();
	
	// And, Return the error code that was asked
	// to be dispatched
	return hError;	
}


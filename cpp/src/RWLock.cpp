/*
* Copyright 2005,2006 WSO2, Inc. http://wso2.com
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
#include <RWLock.h>

using namespace wso2wsf;

RWLock::RWLock()
{
	_readers = 0;
	
}

int RWLock::init()
{
	if(!(_readEvent = CreateEvent(NULL, TRUE, FALSE, NULL)))
	{
		return GetLastError();
	}
	if(!(_writeMutex =  CreateMutex(NULL, FALSE, NULL)))
	{
		CloseHandle(_readEvent);
		return GetLastError();
	}
	return 0;
}

int RWLock::readLockCore(DWORD milliseconds)
{
	DWORD   code = WaitForSingleObject(_writeMutex, milliseconds);

	if (code == WAIT_FAILED || code == WAIT_TIMEOUT)
		return GetLastError();  
	/* We've successfully acquired the writer mutex, we can't be locked
	* for write, so it's OK to add the reader lock.  The writer mutex
	* doubles as race condition protection for the readers counter.   
	*/
	InterlockedIncrement(&_readers);

	if (! ResetEvent(_readEvent))
		return GetLastError();

	if (! ReleaseMutex(_writeMutex))
		return GetLastError();

	return 0;
}

int RWLock::readLock()
{
	return readLockCore(INFINITE);
}

int RWLock::tryReadLock()
{
	return readLockCore(0);
}

int RWLock::writeLockCore(DWORD milliseconds)
{
	DWORD  code = WaitForSingleObject(_writeMutex , milliseconds);

	if (code == WAIT_FAILED || code == WAIT_TIMEOUT)
		return GetLastError();

	/* We've got the writer lock but we have to wait for all readers to
	* unlock before it's ok to use it.
	*/
	if (_readers) {
		/* Must wait for readers to finish before returning, unless this
		* is an trywrlock (milliseconds == 0):
		*/
		code = milliseconds 
			? WaitForSingleObject(_readEvent, milliseconds)
			: WAIT_TIMEOUT;

		if (code == WAIT_FAILED || code == WAIT_TIMEOUT) {
			/* Unable to wait for readers to finish, release write lock: */
			if (! ReleaseMutex(_writeMutex))
				return GetLastError();

			return GetLastError();
		}
	}
	return 0;
}

int RWLock::writeLock()
{
	return writeLockCore(INFINITE);
}

int RWLock::unlock()
{
	int rv =0;

	/* First, guess that we're unlocking a writer */
	if (! ReleaseMutex(_writeMutex))
		rv = GetLastError();
		/**  Attempt to release mutex not owned by caller error code is 288L */
	if (rv == 288L) {
		/* Nope, we must have a read lock */
		if (_readers &&
			! InterlockedDecrement(&_readers) &&
			! SetEvent(_readEvent)) {
				rv = GetLastError();
		}
		else {
			rv = 0;
		}
	}
	return rv;
}

RWLock::~RWLock()
{
	if(!CloseHandle(_readEvent))
	{
	}
	if(!CloseHandle(_writeMutex	))
	{
	}
}

/*
* Copyright 2005,2009 WSO2, Inc. http://wso2.com
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

#ifndef RWLOCK_H
#define RWLOCK_H

#include <WSFDefines.h>
#include <Windows.h>

namespace wso2wsf
{
	class RWLock{
	private:
		HANDLE _writeMutex;
		HANDLE _readEvent;
		LONG _readers;
		int readLockCore(DWORD milliseconds);
		int writeLockCore(DWORD milliseconds);
	public:
			RWLock();

			int init();
			/**
			* Acquire a shared-read lock on the given read-write lock. This will allow
			* multiple threads to enter the same critical section while they have acquired
			* the read lock.
			*/
			int readLock();
			/**
			* Acquire an exclusive-write lock on the given read-write lock. This will
			* allow only one single thread to enter the critical sections. If there
			* are any threads currently holding the read-lock, this thread is put to
			* sleep until it can have exclusive access to the lock.
			*/
			int writeLock();
			/**
			* Attempt to acquire the exclusive-write lock on the given read-write lock. 
			* only that the function fails if there is any other thread holding the lock
			* (for reading or writing), in which case the function will return an error code,
			* it can be used to determine the error.
			*/
			int tryWriteLock();
			/**
			* Attempt to acquire the shared-read lock on the given read-write lock. This
			* is the same as apr_thread_rwlock_rdlock(), only that the function fails
			* if there is another thread holding the write lock, or if there are any
			* write threads blocking on the lock. If the function fails for this case,
			* return value can be used to determine the error.
			*/
			int tryReadLock();
			/**
			* Release either the read or write lock currently held by the calling thread
			* associated with the given read-write lock.
			* @param rwlock the read-write lock to be released (unlocked).
			*/
			int unlock();
			~RWLock();
	};
}
#endif //RWLOCK_H
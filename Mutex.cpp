////////////////////////////////////////////////////////////////////////////////////////////////////
// IpPyProxy
//
// Copyright �2008 Liam Kirton <liam@int3.ws>
////////////////////////////////////////////////////////////////////////////////////////////////////
// Mutex.cpp
//
// Created: 27/02/2008
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Mutex.h"

#include <exception>

////////////////////////////////////////////////////////////////////////////////////////////////////

Mutex::Mutex()
{
	hMutex_ = CreateMutex(NULL, FALSE, NULL);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

Mutex::~Mutex()
{
	CloseHandle(hMutex_);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

bool Mutex::Lock(unsigned int timeout)
{
	return (WaitForSingleObject(hMutex_, timeout) == WAIT_OBJECT_0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void Mutex::Unlock()
{
	ReleaseMutex(hMutex_);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
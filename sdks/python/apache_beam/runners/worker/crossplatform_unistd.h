#ifndef BEAM_CROSSPLATFORM_UNISTD_H
#define BEAM_CROSSPLATFORM_UNISTD_H

#ifdef _WIN32
#include <windows.h>
void usleep(unsigned int usec)
{
	HANDLE timer;
	LARGE_INTEGER ft;

	ft.QuadPart = -(10 * (__int64)usec);

	timer = CreateWaitableTimer(NULL, TRUE, NULL);
	SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
	WaitForSingleObject(timer, INFINITE);
	CloseHandle(timer);
}
#else
#include "unistd.h"
#endif

#endif
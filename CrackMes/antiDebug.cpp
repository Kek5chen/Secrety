#include <stdio.h>

#include "antiDebug.h"
#include "time.h"
#include "output.h"

int antiDebugLink::lastCall;

void antiDebugLink::CheckIfThreadRunning() {
	long millis = GetCurrentTimeMillis();
	bool flag = antiDebugLink::lastCall < millis - 1000 || antiDebugLink::lastCall > millis;
	if (flag) {
		int noPatchPls[] = { 2, 14, 5, 1, 10, 0, 8, 21, -68, 14, 1, 9, 5, 10, 0, 1, 14, -68, 16, 11, -68, 10, 11, 16, -68, 12, -3, 16, -1, 4, -68, 9, 21, -68, 15, 16, 17, 2, 2, 5, 1, 15, -68, -1, -42 };
		out::printOut(noPatchPls, _countof(noPatchPls), true);
		exit(0x420);
	}
}

void antiDebug() {
	BOOL debuggerPresent = FALSE;
	CheckRemoteDebuggerPresent(GetCurrentProcess(), &debuggerPresent);
	if (debuggerPresent || IsDebuggerPresent()) {
		int noDebugPls[] = { 4, 1, 4, 1, -68, 10, -3, 4, -56, -68, 5, -68, 15, 1, 1, -68, 21, 11, 17, -68, 12, -3, 16, -1, 4, 5, 10, 3, -68, 9, 21, -68, 15, 16, 17, 2, 2 };
		out::printOut(noDebugPls, _countof(noDebugPls), true);
		exit(0x420);
	}
	antiDebugLink::lastCall = GetCurrentTimeMillis();
}

void antiDebugLoop() {
	while (true) { antiDebug(); Sleep(1); }
}
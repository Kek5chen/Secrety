#pragma once

#include <windows.h>

namespace antiDebugLink {
	extern int lastCall;
	void CheckIfThreadRunning();
}

void antiDebug();
void antiDebugLoop();

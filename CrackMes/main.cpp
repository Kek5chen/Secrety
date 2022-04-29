#include <iostream>
#include <thread>
#include <Windows.h>

#include "output.h"
#include "actualprogram.h"
#include "antiDebug.h"

uintptr_t p_program_create_instance;

int main() {

	antiDebug();

	p_program_create_instance = (uintptr_t) &Program::CreateInstance;
	int inputSerialKeyChars[] = { -20, 8, 1, -3, 15, 1, -68, 5, 10, 12, 17, 16, -68, 21, 11, 17, 14, -68, 15, 1, 14, 5, -3, 8, 7, 1, 21, -42 };
	out::printOut(inputSerialKeyChars, _countof(inputSerialKeyChars), false);

	while (true) {
	}
	return 0;
}

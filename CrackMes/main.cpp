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
	p_program_create_instance -= 0x60;

	int inputSerialKeyChars[] = { -20, 8, 1, -3, 15, 1, -68, 5, 10, 12, 17, 16, -68, 21, 11, 17, 14, -68, 15, 1, 14, 5, -3, 8, 7, 1, 21, -42 };
	out::printOut(inputSerialKeyChars, _countof(inputSerialKeyChars), false);

	for (int i = 0; i < 10; i++) {
		for (unsigned int i = 0; i < 0x60; i += 0x20) {
			p_program_create_instance += i;
		}
		((void (*)())p_program_create_instance)();
		p_program_create_instance -= 0x60;
	}

	while (true) {
	}
	return 0;
}

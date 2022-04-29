#pragma once

#include <iostream>

using namespace std;

namespace out {
	static void printOut(int textChars[], int size, bool endLine) {
		for (int i = 0; i < size; i++) {
			cout << (char)(textChars[i] + 100);
		}
		if(endLine) cout << endl;
	}
}
#include <iostream>
#include <thread>
#include <math.h>

#include "time.h"
#include "antiDebug.h"
#include "actualprogram.h"
#include "output.h"

using namespace std;

int Program::instanceCount = 0;
int Program::a = 0;
int Program::b = 0;
int Program::c = 0;

char* toArray(int number)
{
	int n = log10(number) + 1;
	int i;
	char* numberArray = (char*)calloc(n, sizeof(char));
	for (i = n - 1; i >= 0; --i, number /= 10)
	{
		numberArray[i] = (number % 10) + '0';
	}
	return numberArray;
}

// 9812-3568-1346-5967 result: 2457, 1600, 3535, 1670
int adder[] = { 1525, 1256, 6236, 7341 };
int expectedResult[] = { 2457, 1600, 3535, 1670 };
int wrongTxt[] = { 16, 4, -3, 16, -56, -68, 15, -3, 0, 8, 21, -68, 5, 15, -68, 19, 14, 11, 10, 3, -54, -68, 9, -3, 7, 1, -68, 15, 17, 14, 1, -68, 21, 11, 17, -68, 14, 1, -3, 0, -68, 16, 4, 1, -68, 14, 5, 3, 4, 16, -68, -1, 11, 0, 1, -68, 11, 10, -68, 16, 4, 1, -68, -2, -3, -1, 7, -68, 11, 2, -68, 21, 11, 17, 14, -68, 12, 14, 11, 0, 17, -1, 16, -54 };
int rightTxt[] = { 3, 11, 11, 0, -68, 6, 11, -2, -56, -68, 21, 11, 17, -68, -3, -1, 16, 5, 18, -3, 16, 1, 0, -68, 21, 11, 17, 14, -68, 12, 14, 11, 0, 17, -1, 16 };

Program::Program() {
	if (instanceCount == 0) {
		thread t(&antiDebugLoop);
		t.detach();
	}
	else if (instanceCount * ((a + b) / 3) == 6 * (c / 3)) {
		char str[20];
		int length;
		length = scanf_s("%19s", str, (unsigned)_countof(str));
		antiDebugLink::CheckIfThreadRunning();
		int calcResults[4]{};
		for (int i = 0; i < 19; i++) {
			int currentNum = str[i];
			currentNum = currentNum * currentNum ^ (adder[i % 4] / 4) ^ i;
			currentNum += 0xFFFFFFF;
			currentNum = currentNum % 1000;
			calcResults[i % 4] += currentNum;
		}
	    // ---
	    // i looked back at it after i uploaded it to crackmes.one, and i have no idea where this comes from
	    // or what it is used for
	    // it seems to just translate a int serial to a string which is completely useless.
	    // though since i dont know if it affects the compiled binary, i decided to leave it in.
		char key[16]{};
		for (int i = 0; i < 4; i++) {
			int num = calcResults[i];
			if (num < 1000)
				key[i * 4] = '0';
			char* arr = toArray(num);
			for (int j = 0; j < 4 - (num < 1000); j++) {
				key[i * 4 + j + (num < 1000)] = arr[j];
			}
		}
	    // ---
		bool flag = true;
		for (int i = 0; i < 4; i++)
			flag = flag && calcResults[i] == expectedResult[i];
		if (flag)
			out::printOut(rightTxt, _countof(rightTxt), true);
		else
			out::printOut(wrongTxt, _countof(wrongTxt), true);

	}
	a++;
	b += 2;
	c += 3;
	instanceCount++;
}

void Program::CreateInstance() {
	Program t = Program();
}

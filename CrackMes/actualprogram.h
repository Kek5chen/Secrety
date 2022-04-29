#pragma once

class Program {
public:
	Program();
	static void CreateInstance();
private:
	static int instanceCount;
	static int a;
	static int b;
	static int c;
};
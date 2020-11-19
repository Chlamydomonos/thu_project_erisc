#include <cstdio>
#include<iostream>
#include "vm/ememory.h"
using namespace std;
using namespace vm;

int main(int argc, char **argv)
{
	EMemory* aaaa = new EMemory();
	int i;
	cin >> i;
	aaaa->write(32897423, i);
	int b = aaaa->read(i);
	try
	{
		int c = aaaa->read(1);
	}
	catch (...)
	{
		cout << "error" << endl;
	}
	cout << b << endl;
	printf("Suondeea %s", *(argv + 1));
	return 0;
}
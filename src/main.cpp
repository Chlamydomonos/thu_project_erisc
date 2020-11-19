#include <cstdio>

#include "vm/ememory.h"

using namespace vm;

int main(int argc, char **argv)
{
	EMemory* aaaa = new EMemory();
	int b = aaaa->read(0);
	printf("%d", b);
	printf("Suondeea %s", *(argv + 1));
	return 0;
}
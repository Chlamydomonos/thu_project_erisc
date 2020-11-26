#include <cstdio>
#include "testmain.h"

#define DEBUG

int main(int argc, char **argv)
{
#ifdef DEBUG
	testMain();
	return 0;
#endif // DEBUG
	printf("Suondeea");
	return 0;
}
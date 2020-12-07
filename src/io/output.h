#ifndef OUTPUT_H
#define OUTPUT_H
#include <cstdio>

namespace vm
{
	class VM;
}

namespace output
{
	void outputText(vm::VM* vm);
}
#endif // !OUTPUT_H

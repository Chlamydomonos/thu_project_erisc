#include "ret.h"

using namespace erisc;

erisc::Ret::Ret():Command()
{
}

erisc::Ret::~Ret()
{
}

void erisc::Ret::run(vm::VM* vm)
{
	try {
		int linnum = vm->getStack()->pop();
		vm->currentRunningLine = linnum;
	}
	catch (Exception&e) {
		throw Exception("Failed to run command \" ret\"", e);
	}
}

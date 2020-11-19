#include "vm.h"

vm::VM::VM()
{
	eMemory = new EMemory();
	eRegister = new ERegister[REGISTER_AMOUNT];
	eStack = new EStack();
}

vm::VM::~VM()
{
	delete eMemory;
	delete []eRegister;
	delete eStack;
}

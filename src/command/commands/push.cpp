#include "push.h"
#include "../../vm/vm.h"

using vm::VM;

erisc::Push::Push(const char* paramString) :erisc::Command(1, paramString)
{
}

erisc::Push::~Push()
{
}

void erisc::Push::run(VM* vm)
{
	try
	{
		if (params[0].type != ParamType::REGISTER)
		{
			throw Exception("Param type error");
		}
		int value = vm->getRegister(params[0].value)->read();
		vm->getStack()->push(value);
	}
	catch (Exception& e)
	{
		throw Exception("Failed to run command \"push\"", e);
	}
}

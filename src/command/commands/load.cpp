#include "load.h"
#include "../../vm/vm.h"

using vm::VM;

erisc::Load::Load(const char* paramString) : erisc::Command(2, paramString)
{
}

erisc::Load::~Load()
{
}

void erisc::Load::run(VM* vm)
{
	try
	{
		if (!(params[0].type == ParamType::REGISTER && params[1].type == ParamType::REGISTER))
			throw Exception("Param type error");
		int value = params[1].getValue(vm);
		value = vm->getMemory()->read(value);
		vm->getRegister(params[0].value)->write(value);
	}
	catch (Exception& e)
	{
		throw Exception("Failed to run command \"load\"", e);
	}
}

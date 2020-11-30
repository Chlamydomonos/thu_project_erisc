#include "mov.h"
#include "../../vm/vm.h"

using vm::VM;

erisc::Mov::Mov(char* paramString):erisc::Command(2,paramString)
{
}

erisc::Mov::~Mov()
{
}

void erisc::Mov::run(VM* vm)
{
	try
	{
		if (!(params[0].type == ParamType::REGISTER && (params[1].type == ParamType::NUMBER || params[1].type == ParamType::REGISTER)))
		{
			throw Exception("Param type error");
		}
		int value = params[1].getValue(vm);
		vm->getRegister(params[0].value)->write(value);
	}
	catch (Exception& e)
	{
		throw Exception("Failed to run command \"mov\"", e);
	}
}

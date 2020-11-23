#include "load.h"
#include "../../vm/vm.h"

erisc::Load::Load(char* paramString) : erisc::Command(2, paramString)
{
}

erisc::Load::~Load()
{
}

void erisc::Load::run(VM* vm)
{
	if (!(params[0].type == ParamType::REGISTER && params[1].type == ParamType::REGISTER))
		throw Exception("Param type error");
	try
	{
		int value = params[1].getValue(vm);
		vm->getRegister(params[0].value)->write(value);
	}
	catch (Exception& e)
	{
		throw;
	}
}

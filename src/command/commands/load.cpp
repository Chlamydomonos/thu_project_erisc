#include "load.h"

erisc::Load::Load(char* paramString) : erisc::Command(2, paramString)
{
}

erisc::Load::~Load()
{
}

void erisc::Load::run(VM* vm)
{
	try
	{
		if (!(params[0].type == ParamType::REGISTER && params[1].type == ParamType::NUMBER))
			throw "Param type error";
		int value = params[1].getValue(vm);
		vm->getRegister(params[0].value)->write(value);
	}
	catch (const char* e)
	{
		throw e;
	}
}

#include "pop.h"
#include "../../vm/vm.h"

erisc::Pop::Pop(char* paramString):erisc::Command(1,paramString)
{
}

erisc::Pop::~Pop()
{
}

void erisc::Pop::run(VM* vm)
{
	try
	{
		if (params[0].type != ParamType::REGISTER)
		{
			throw Exception("Param Type Error!");
		}
		int stackTopValue=vm->getStack()->pop();
		vm->getRegister(params[0].value)->write(stackTopValue);
	}
	catch (Exception& e)
	{
		throw Exception("Failed to run command \"pop\"", e);
	}
}

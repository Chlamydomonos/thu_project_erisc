#include "command.h"

erisc::Param::Param(ParamType type, int value)
{
	this->type = type;
	this->value = value;
}

int erisc::Param::getValue(VM* vm)
{
	if (type == ParamType::NUMBER)
		return value;
	else
	{
		try
		{
			return vm->getRegister(value)->read();
		}
		catch (const char* e)
		{
			throw e;
		}
	}
}

erisc::Command::Command()
{
	paramAmount = 0;
	params = nullptr;
}

erisc::Command::Command(int paramAmount, char* paramString)
{
	this->paramAmount = paramAmount;
	getParamsFromString(paramString);
}

erisc::Command::~Command()
{
	delete []params;
}

void erisc::Command::run(VM* vm)
{
}

void erisc::Command::getParamsFromString(char* str)
{
}

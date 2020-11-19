#include "command.h"

erisc::Param::Param(ParamType type, int value)
{
	this->type = type;
	this->value = value;
}

erisc::Command::Command(int paramAmount, char* paramString)
{
	this->paramAmount = paramAmount;
}

erisc::Command::~Command()
{
}

void erisc::Command::run(VM vm)
{
}

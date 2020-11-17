#include "eregister.h"

erisc::ERegister::ERegister()
{
}

erisc::ERegister::~ERegister()
{
}

void erisc::ERegister::write(int value)
{
}

int erisc::ERegister::read()
{
	return 0;
}

bool erisc::ERegister::getRead()
{
	return false;
}

bool erisc::ERegister::getWritten()
{
	return false;
}

bool erisc::ERegister::clearHistory()
{
	return false;
}

erisc::ERegister *erisc::eRegister = new erisc::ERegister[32];
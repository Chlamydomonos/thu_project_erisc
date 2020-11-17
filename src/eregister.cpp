#include "eregister.h"

erisc::Register::Register()
{
}

erisc::Register::~Register()
{
}

void erisc::Register::write(int value)
{
}

int erisc::Register::read()
{
	return 0;
}

bool erisc::Register::getRead()
{
	return false;
}

bool erisc::Register::getWritten()
{
	return false;
}

bool erisc::Register::clearHistory()
{
	return false;
}

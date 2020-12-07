#include "eregister.h"

vm::ERegister::ERegister()
{
	value = 0;
	hasRead = 0;
	hasWritten = 0;
}

vm::ERegister::~ERegister()
{
}

void vm::ERegister::write(int value)
{
	this->value = value;
	hasWritten = true;
}

int vm::ERegister::read()
{	
	hasRead = true;
	return this->value;
}

bool vm::ERegister::getRead()
{
	return hasRead;
}

bool vm::ERegister::getWritten()
{
	return hasWritten;
}

int vm::ERegister::getValue()
{
	return value;
}

void vm::ERegister::clearHistory()
{
	hasRead = false;
	hasWritten = false;
}
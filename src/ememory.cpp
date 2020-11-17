#include "ememory.h"

erisc::EMemory::EMemory()
{
}

erisc::EMemory::~EMemory()
{
}

int erisc::EMemory::read(int address)
{
	return 0;
}

void erisc::EMemory::write(int value, int address)
{
}

bool erisc::EMemory::getAccessed(int zone)
{
	return false;
}

void erisc::EMemory::clearHistory()
{
}

erisc::EMemory* erisc::eMemory = new erisc::EMemory();
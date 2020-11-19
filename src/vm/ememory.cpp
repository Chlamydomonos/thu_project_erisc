#include "ememory.h"

vm::EMemory::EMemory()
{
	memoryList = new char[MAX_MEMORY];
	hasAccessed = new bool[16];
	for (int i = 0; i < MAX_MEMORY; i++)
		memoryList[i] = 0;
	for (int i = 0; i < 16; i++)
		*(hasAccessed + i) = false;
}

vm::EMemory::~EMemory()
{
	delete[] memoryList;
	delete[] hasAccessed;
}

int vm::EMemory::read(int address)
{
	border_judge(address)
	int ret = 0;
	for (int i = 0; i < 4; i++) {
			ret = ret * 256 + *(memoryList + address + i);
	}
	hasAccessed[address / (1 << 18)] = true;
	hasAccessed[(address + 3) / (1 << 18)] = true;
	return ret;
}

void vm::EMemory::write(int value, int address)
{
	border_judge(address);
	hasAccessed[address / (1 << 18)] = true;
	hasAccessed[(address + 3) / (1 << 18)] = true;
	*(memoryList + address + 3) = value % 256;
	*(memoryList + address + 2) = (value / 256) % 256;
	*(memoryList + address + 1) = (value / (256 * 256)) % 256;
	*(memoryList + address + 0) = (value / (256 * 256 * 256)) % 256;
}

bool vm::EMemory::getAccessed(int zone)
{
	return hasAccessed[zone];
}

void vm::EMemory::clearHistory()
{
	for (int i = 0; i < 16; i++)
		*(hasAccessed + i) = false;
}

void vm::EMemory::border_judge(int address)
{
	if ((address + 3 >= MAX_MEMORY) || (address < 0)) 
		throw "The address you visited is not in memory";
}
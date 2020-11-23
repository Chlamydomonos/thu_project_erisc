#include "ememory.h"
#include "../exception/exception.h"

vm::EMemory::EMemory()
{
	memoryList = new unsigned char[MAX_MEMORY];
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
	border_judge(address);
	int ret = 0;
	for (int i = 0; i < 4; i++) {
			ret = (ret << 8) | (int)*(memoryList + address + i);
	}
	hasAccessed[address >> 18] = true;
	hasAccessed[(address + 3) >> 18] = true;
	return ret;
}

void vm::EMemory::write(int value, int address)
{
	border_judge(address);
	hasAccessed[address >> 18] = true;
	hasAccessed[(address + 3) >> 18] = true;
	for (int i = 0; i < 4; i++) {
		*(memoryList + address + 3 - i) = (value >> (8 * i)) & 255;
	}
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
		throw Exception("The address you visited is not in memory");
}
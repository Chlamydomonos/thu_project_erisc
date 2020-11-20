#include "estack.h"

vm::EStack::EStack()
{
	stackTop = new int[MAX_STACK];
	stackBottom = stackTop + (MAX_STACK);
	for (int i = 0;i < MAX_STACK;i++) {
		stackTop[i] = 0;
	}
	accessed = false;
}

vm::EStack::~EStack()
{
	stackTop = stackBottom - (MAX_STACK);
	delete[] stackTop;
}

void vm::EStack::push(int value)
{
	if (stackTop == stackBottom - 1)
		throw "Stack out of range";
	*stackTop = value;
	stackTop++;
	accessed = true;
}

int vm::EStack::pop()
{
	if (stackTop == stackBottom - (MAX_STACK))
		throw "Stack out of range";
	stackTop--;
	return (*stackTop);
}
bool vm::EStack::getAccessed()
{
	return accessed;
}

void vm::EStack::clearHistory()
{
	accessed = false;
}
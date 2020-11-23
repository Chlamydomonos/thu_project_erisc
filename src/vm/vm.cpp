#include "vm.h"
#include "../command/command.h"

vm::VM::VM(int maxCommands)
{
	maxCommandAmount = maxCommands;
	eMemory = new EMemory();
	eRegister = new ERegister[REGISTER_AMOUNT];
	eStack = new EStack();
	commands = new Command[maxCommands];
}

vm::VM::~VM()
{
	delete eMemory;
	delete []eRegister;
	delete eStack;
	delete[]commands;
}

vm::EMemory* vm::VM::getMemory()
{
	return eMemory;
}

vm::EStack* vm::VM::getStack()
{
	return eStack;
}

vm::ERegister* vm::VM::getRegister(int index)
{
	return eRegister + index;
}

void vm::VM::initCommands(Command* commands, int commandAmount)
{
	if (commandAmount > maxCommandAmount)
		throw "Command amount out of range";
	for (int i = 0; i < commandAmount; i++)
	{
		this->commands[i] = commands[i];
	}
	currentCommandAmount = commandAmount;
}

void vm::VM::runCommand(int line)
{
	if (line > currentCommandAmount)
		throw "line number out of range";
	commands[line - 1].run(this);
}

void vm::VM::addCommand(Command command)
{
	if (currentCommandAmount == maxCommandAmount)
		throw "Command amount out of range";
	commands[currentCommandAmount] = command;
	currentCommandAmount++;
}

#include "vm.h"
#include "../command/command.h"
#include "../exception/exception.h"
#include <cmath>

#define HEAD_LEN 19
#define BUFFER_LEN 64

namespace
{
	const char* exceptionHead = "Error running line ";

	char* genExceptionStr(int line)
	{
		char* buffer = new char[BUFFER_LEN];

		for (int i = 0; i < HEAD_LEN; i++)
			buffer[i] = exceptionHead[i];
		char* i = buffer + HEAD_LEN + (int)floor(log10(line));
		i[1] = 0;
		while (line > 0)
		{
			*i = line % 10 + '0';
			line /= 10;
			i--;
		}
		return buffer;
	}
}

using erisc::Command;

vm::VM::VM(int maxCommands)
{
	maxCommandAmount = maxCommands;
	eMemory = new EMemory();
	eRegister = new ERegister[REGISTER_AMOUNT];
	eStack = new EStack();
	commands = new Command*[maxCommands + 1];
	lineIds = new LineIdList();
	currentCommandAmount = 0;
	currentRunningLine = 1;
	timesOfDraw = 0;
	end = false;
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

vm::LineIdList* vm::VM::getLineIdList()
{
	return this->lineIds;
}

void vm::VM::initCommands(Command** commands)
{
	int commandAmount = 0;
	for (int i = 1;; i++)
	{
		commandAmount++;
		if (commands[i] == nullptr)
			break;

		if (commandAmount > maxCommandAmount)
			throw Exception("Command amount out of range");

		this->commands[i] = commands[i];
	}
	currentCommandAmount = commandAmount - 1;
}

void vm::VM::runCommand(int line)
{
	if (line > currentCommandAmount || line < 1)
		throw Exception("line number out of range");

	try
	{
		commands[line]->run(this);
	}
	catch (Exception& e)
	{
		throw Exception(genExceptionStr(line), e);
	}
}

void vm::VM::runCurrentCommand()
{
	try
	{
		runCommand(currentRunningLine);
		currentRunningLine++;
	}
	catch (Exception& e)
	{
		throw e;
	}
}

void vm::VM::addCommand(Command* command)
{
	if (currentCommandAmount == maxCommandAmount)
		throw Exception("Command amount out of range");
	commands[currentCommandAmount] = command;
	currentCommandAmount++;
}

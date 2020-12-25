#ifndef INPUTUTIL_H
#define INPUTUTIL_H
#include "../command/command.h"

using erisc::Command;

namespace input
{
	extern Command** readCommandsFromFile(const char* fileName, vm::VM* vm);
}

#endif // !INPUTUTIL_H

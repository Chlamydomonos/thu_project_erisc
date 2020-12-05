#ifndef INPUTUTIL_H
#define INPUTUTIL_H
#include "../command/command.h"

using erisc::Command;

namespace input
{
	extern Command* readCommandsFromFile(const char* fileName);
}

#endif // !INPUTUTIL_H

#include "testmain.h"
#include "../vm/vm.h"
#include "../command/allcommands.h"
#include <iostream>
using namespace std;
using namespace vm;
using namespace erisc;
int testMain()
{
	VM* vm = new VM(1024);
	Command* draw = new Draw();
	vm->addCommand(new Command());
	vm->addCommand(draw);
	vm->runCommand(1);
	return 0;
}

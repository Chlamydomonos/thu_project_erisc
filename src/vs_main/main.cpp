#include <cstdio>
#include "testmain.h"
#include "../vm/vm.h"
#include "../command/allcommands.h"
#include "../io/vmconfigreader.h"
#include "../io/inpututil.h"
using namespace vm;
using namespace erisc;
using namespace input;

//#define DEBUG

int main(int argc, char **argv)
{
#ifdef DEBUG
	testMain();
	return 0;
#endif // DEBUG
	try
	{
		VMConfigReader* config = new VMConfigReader("vm.vmcfg");
		VM* vm = new VM(config->getMaxCommandAmount());
		delete config;

		char* fileName = nullptr;

		if (argc == 1)
		{
			printf("Please input the file name to run\n> ");
			fileName = new char[1024];

			for (char* i = fileName; i < fileName + 1024; i++)
				*i = 0;

			int len = 0;
			while(true)
			{
				char temp = getchar();
				if (temp == EOF || temp == '\n')
					break;
				fileName[len] = temp;
				len++;
			}
		}
		else if (argc == 2)
		{
			fileName = argv[1];
		}
		else
		{
			throw Exception("Wrong command line params!");
		}

		Command** commandList = readCommandsFromFile(fileName, vm);
		delete fileName;
		vm->initCommands(commandList);
		delete[] commandList;

		while(!vm->end)
		{
			vm->runCurrentCommand();
		}

		delete vm;
	}
	catch (Exception& e)
	{
		printf("Error occured when running this program:\n%s", e.what());
	}

	return 0;
}
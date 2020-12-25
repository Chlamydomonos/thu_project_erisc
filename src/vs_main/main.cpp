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

void dynamicInput(char** argv);

int main(int argc, char **argv)
{
#ifdef DEBUG
	testMain();
	return 0;
#endif // DEBUG
	try
	{
		if (argc == 2 && argv[1][0] == '-')
		{
			dynamicInput(argv);
			return 0;
		}

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

void dynamicInput(char** argv)
{
	char* param1 = argv[1];
	if (!(param1[0] == '-' && param1[1] == 'd' && (param1[2] == 0 || param1[2] == '\n' || param1[2] == '\r' || param1[2] == EOF)))
	{
		int len = strlen(param1);
		const char* head = "invalid command line param: ";
		int headLen = strlen(head);
		char* message = new char[headLen + len + 1];
		for (int i = 0; i < headLen; i++)
			message[i] = head[i];
		for (int i = headLen; i < len + headLen; i++)
			message[i] = param1[i - headLen];
		message[len + headLen] = 0;
		Exception exception(message);
		delete message;
		throw exception;
	}

	try
	{
		VMConfigReader* config = new VMConfigReader("vm.vmcfg");
		VM* vm = new VM(config->getMaxCommandAmount());
		delete config;
		printf("This is the dynamic input mode of this program.\n You can input commands in this console.\n Inputing command \"end\" will stop this program.\n");
		char* line = new char[1024];
		for (int lineNum = 1;; lineNum++)
		{
			printf(">");
			for (int i = 0; i < 1024; i++)
			{
				line[i] = getchar();
				if (line[i] == '\n' || line[i] == 0 || line[i] == EOF)
				{
					line[i] = '\n';
					line[i + 1] = 0;
					break;
				}
			}

			vm->addCommand(readSingleCommand(line, vm, lineNum));

			while (vm->currentRunningLine <= lineNum)
				vm->runCurrentCommand();

			if (vm->end)
			{
				delete vm;
				delete[] line;
				return;
			}
		}
	}
	catch (Exception& e)
	{
		throw e;
	}
}
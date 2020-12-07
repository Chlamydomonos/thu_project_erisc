#include "output.h"
#include "../vm/vm.h"
#include "../fuckide/fuckide.h"

void output::outputText(vm::VM* vm)
{
	FILE* file = fuckIDEfopen("result.txt", "w");
	for (int i = 0;i < REGISTER_AMOUNT;i++)
	{
		fprintf(file, "%x ", vm->getRegister(i)->getValue());
	}
	for (int i = 0;i < MAX_MEMORY;i++)
	{
		if (i % 64 == 0) {
			fprintf(file, "\n");
		}
		fprintf(file, "%x ", vm->getMemory()->getValue(i));
		
	}
	fclose(file);
}

#include "end.h"

erisc::End::End():Command()
{
}

erisc::End::~End()
{
}

void erisc::End::run(vm::VM* vm)
{
	output::outputText(vm);
}

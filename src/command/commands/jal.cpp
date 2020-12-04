#include "jal.h"
#include "../../vm/vm.h"
#include "../lineid.h"
using namespace erisc;
using namespace vm;

erisc::Jal::Jal(const char* paramString):erisc::Command(1,paramString)
{
}

erisc::Jal::~Jal()
{
}

void erisc::Jal::run(vm::VM* vm)
{
	try
	{
		LineIdList* p = vm->getLineIdList();
		LineId* q_id = *p[params[0]];
		int lineNumber = q_id->getLine();
		vm->currentRunningLine = lineNumber;
	}
	catch (Exception& e) 
	{
		throw Exception("Failed to run command \"jal\"", e);
	}
}

#include "cal.h"
#include "../../vm/vm.h"
#include "../../vm/lineidlist.h"
#include "../lineid.h"

using namespace erisc;
using namespace vm;

erisc::Cal::Cal(const char* paramstring):Command(1,paramstring)
{
}

erisc::Cal::~Cal()
{
}

void erisc::Cal::run(vm::VM* vm)
{
	try {
		if (params[0].type != ParamType::LINE_ID)
			throw Exception("Param Type error!");
		int linnum = vm->currentRunningLine + 1;
		vm->getStack()->push(linnum);
		char* linname = params[0].id;
		LineIdList* list = vm->getLineIdList();
		LineId* line = (*list)[linname];
		int value = line->getLine();
		vm->currentRunningLine = value;
	}catch(Exception&e){
		throw Exception("Failed to run command \"cal\"", e);
	}
}

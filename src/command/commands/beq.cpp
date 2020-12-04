#include "beq.h"
#include "../../vm/vm.h"
#include "../lineid.h"
using namespace erisc;
using namespace vm;

erisc::Beq::Beq(const char* paramString) :erisc::Command(3, parastring)
{
}

erisc::Beq::~Beq()
{
}

void erisc::Beq::run(vm::VM* vm)
{
	try
	{
		if (params[0].type != ParamType::LINE_ID)
			throw Exception("Param type error");
		int value1 = params[0].getValue(vm);
		int	value2 = params[1].getValue(vm);
		if (value1 == value2) {
			LineIdList* p = vm->getLineIdList();
			LineId* q_id = (*p)[params[2]];
			int lineNumber = q_id->getLine();
			vm->currentRunningLine = lineNumber;
		}
	}
	catch (Exception& e)
	{
		throw Exception("Failed to run command \"jal\"", e);
	}
}

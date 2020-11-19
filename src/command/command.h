#ifndef COMMAND_H
#define COMMAND_H

#include "../vm/vm.h"

using vm::VM;

namespace erisc
{
	enum ParamType
	{
		REGISTER,
		NUMBER
	};

	struct Param
	{
		ParamType type;
		int value;
		Param(ParamType type, int value);
	};

	class Command
	{
	public:
		Command(int paramAmount, char *paramString);
		~Command();
		virtual void run(VM vm);
	protected:
		int paramAmount;
		Param* params;
	};
}

#endif // !COMMAND_H

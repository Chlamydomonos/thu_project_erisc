#ifndef COMMAND_H
#define COMMAND_H

#include "param.h"

namespace erisc
{
	enum CommandType
	{
		LOAD,
		STORE,
		PUSH,
		POP,
		MOV,
		ADD,
		SUB,
		MUL,
		DIV,
		REM,
		AND,
		OR,
		JAL,
		BEQ,
		BNE,
		BLE,
		BGE,
		CALL,
		RET,
		END,
		DRAW
	};

	class Command
	{
	public:
		Command(int paramAmount, char *paramString);
		~Command();

	protected:
		int paramAmount;
		Param* params;
	};
}

#endif // !COMMAND_H

#ifndef BEQ_H
#define BEQ_H
#include"../command.h"
#include "../../exception/exception.h"

namespace erisc
{
	class Beq : public Command
	{
	public:
		Beq(const char* paramString);
		~Beq();
		void run(vm::VM* vm);
	};
}
#endif
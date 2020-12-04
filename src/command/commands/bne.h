#ifndef BNE_H
#define BNE_H
#include"../command.h"
#include "../../exception/exception.h"

namespace erisc
{
	class Bne : public Command
	{
	public:
		Bne(const char* paramString);
		~Bne();
		void run(vm::VM* vm);
	};
}
#endif // !JAL_H

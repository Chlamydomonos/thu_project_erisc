#ifndef BLT_H
#define BLT_H
#include"../command.h"
#include "../../exception/exception.h"

namespace erisc
{
	class Blt : public Command
	{
	public:
		Blt(const char* paramString);
		~Blt();
		void run(vm::VM* vm);
	};
}
#endif // !JAL_H

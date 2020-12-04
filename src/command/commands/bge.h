#ifndef BGE_H
#define BGE_H
#include"../command.h"
#include "../../exception/exception.h"

namespace erisc
{
	class Bge : public Command
	{
	public:
		Bge(const char* paramString);
		~Bge();
		void run(vm::VM* vm);
	};
}
#endif // !JAL_H

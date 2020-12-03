#ifndef MOV_H
#define MOV_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc
{
	class Mov : public Command
	{
	public:
		Mov(const char* paramString);
		~Mov();
		void run(vm::VM* vm);
	};
}
#endif // !MOV_H

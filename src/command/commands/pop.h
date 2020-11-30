#ifndef POP_H
#define POP_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc
{
	class Pop : public Command
	{
	public:
		Pop(char* paramString);
		~Pop();
		void run(vm::VM* vm);
	};	
}
#endif // !POP_H

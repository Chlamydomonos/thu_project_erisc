#ifndef JAL_H
#define JAL_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc 
{
	class Jal : public Command
	{
	public:
		Jal(const char* paramString);
		~Jal();
		void run(vm::VM* vm);
	};
}
#endif // !JAL_H

#ifndef RET_H
#define RET_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc {
	class Ret:public Command
	{
	public:
		Ret();
		~Ret();
		void run(vm::VM* vm);


	};

}

#endif
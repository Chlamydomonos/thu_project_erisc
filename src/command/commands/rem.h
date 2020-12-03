#ifndef REM_H
#define REM_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc{
	class Rem :public Command {
	public:
		Rem(const char* parastring);
		~Rem();
		void run(vm::VM* vm);
	};
}

#endif
#ifndef SUB_H
#define SUB_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc {
	class Sub :public Command {
	public:
		Sub(const char* parastring);
		~Sub();
		void run(vm::VM* vm);
	};
}

#endif
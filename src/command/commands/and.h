#ifndef AND_H
#define AND_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc {
	class And :public Command {
	public:
		And(const char* parastring);
		~And();
		void run(vm::VM* vm);
	};
}

#endif
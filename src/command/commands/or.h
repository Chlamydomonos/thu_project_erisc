#ifndef OR_H
#define OR_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc {
	class Or :public Command {
	public:
		Or(const char* parastring);
		~Or();
		void run(vm::VM* vm);
	};
}

#endif
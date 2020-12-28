#ifndef CALL_H
#define CALL_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc {
	class Call :public Command {
	public:
		Call(const char* paramstring);
		~Call();
		void run(vm::VM* vm);
	};
}

#endif
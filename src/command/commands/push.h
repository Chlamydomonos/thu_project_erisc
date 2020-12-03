#ifndef PUSH_H
#define PUSH_H
#include "../command.h"
#include "../../exception/exception.h"
namespace erisc {
	class Push :public Command {
	public:
		Push(const char* parastring);
		~Push();
		void run(vm::VM* vm);
	};
}

#endif
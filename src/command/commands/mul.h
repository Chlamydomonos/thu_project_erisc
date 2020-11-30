#ifndef MUL_H
#define MUL_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc {
	class Mul :public Command{
	public:
		Mul(char* parastring);
		~Mul();
		void run(vm::VM*vm);
	};
}

#endif
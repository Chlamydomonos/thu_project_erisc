#ifndef STORE_H
#define STORE_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc {
	class Store :public Command {
	public:
		Store(const char* paramstring);
		~Store();
		void run(vm::VM* vm);
	};
}


#endif
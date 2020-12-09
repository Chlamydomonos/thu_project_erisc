#ifndef CAL_H
#define CAL_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc {
	class Cal :public Command {
	public:
		Cal(const char* paramstring);
		~Cal();
		void run(vm::VM* vm);
	};
}

#endif
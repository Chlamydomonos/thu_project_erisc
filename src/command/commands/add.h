#ifndef ADD_H
#define ADD_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc {
	class Add :public Command {
	public:
		Add(char* parastring);
		~Add();
		void run(VM* vm);
	};
}

#endif
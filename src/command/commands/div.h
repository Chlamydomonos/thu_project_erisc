#ifndef DIV_H
#define DIV_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc {
	class Div :public Command {
	public:
		Div(char* parastring);
		~Div();
		void run(VM* vm);
	};
}

#endif

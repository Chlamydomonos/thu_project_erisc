#ifndef PUSH_H
#define PUSH_H
#include "../command.h"
#include "../../exception/exception.h"
namespace erisc {
	class Push :public Command {
	public:
		Push(char* parastring);
		~Push();
		void run(VM* vm);
	};
}

#endif
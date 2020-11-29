#ifndef REM_H
#define REM_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc{
	class Rem :public Command {
	public:
		Rem(char* parastring);
		~Rem();
		void run(VM* vm);
	};
}

#endif
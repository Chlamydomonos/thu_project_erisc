#ifndef STORE_H
#define STORE_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc {
	class Store :public Command {
	public:
		Store(char* paramstring);
		~Store();
		void run(VM* vm);
	};
}


#endif
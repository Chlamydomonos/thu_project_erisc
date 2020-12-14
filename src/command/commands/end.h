#ifndef END_H
#define END_H
#include "../../io/output.h"
#include "../../vm/vm.h"
#include "../command.h"

namespace erisc
{
	class End :public Command
	{
	public:
		End();
		~End();
		void run(vm::VM* vm);
	};

}

#endif // !END_H


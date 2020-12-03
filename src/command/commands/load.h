#ifndef LOAD_H
#define LOAD_H
#include "../command.h"
#include "../../exception/exception.h"

namespace erisc
{
	class Load : public Command
	{
	public:
		Load(const char* paramString);
		~Load();
		void run(vm::VM* vm);
	};
}

#endif // !LOAD_H

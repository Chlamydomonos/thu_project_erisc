#ifndef VM_H


#include "ememory.h"
#include "eregister.h"
#include "estack.h"

#define REGISTER_AMOUNT 32

namespace vm
{
	class VM
	{
	public:
		VM();
		~VM();
	private:
		EMemory *eMemory;
		EStack *eStack;
		ERegister *eRegister;
	};
}

#endif // !VM_H
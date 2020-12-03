#include "store.h"
#include "../../vm/vm.h"

using vm::VM;

erisc::Store::Store(const char* paramstring) :erisc::Command(2, paramstring) {

}

erisc::Store::~Store() {

}

void erisc::Store::run(VM* vm) {
	try {
		if (!(params[0].type == ParamType::REGISTER && params[1].type == ParamType::REGISTER))
			throw Exception("Param type error!");
		int value = params[0].getValue(vm);
		int address = params[1].getValue(vm);
		vm->getMemory()->write(value, address);
	}
	catch(Exception&e){
		throw Exception("Failed to run command\"store\"", e);
	}
}
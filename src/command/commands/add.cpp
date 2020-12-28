#include "add.h"
#include "../../vm/vm.h"

using vm::VM;

erisc::Add::Add(const char* parastring) :erisc::Command(3, parastring) {

}

erisc::Add::~Add() {

}

void erisc::Add::run(VM* vm) {
	try {
		if (!(params[0].type == ParamType::REGISTER && params[1].type == ParamType::REGISTER))
			throw Exception("Param type error");
		int address = params[0].value;
		int value1 = params[1].getValue(vm);
		int	value2 = params[2].getValue(vm);
		int value = value1 + value2;
		vm->getRegister(address)->write(value);
	}
	catch (Exception& e) {
        throw Exception("Failed to run command\"add\"", e);
	}
}

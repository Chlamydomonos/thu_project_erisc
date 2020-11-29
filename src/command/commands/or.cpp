#include "or.h"
#include "../../vm/vm.h"

erisc::Or::Or(char* parastring) :erisc::Command(3, parastring) {

}

erisc::Or::~Or(){

}

void erisc::Or::run(VM* vm) {
	try {
		if (!(params[0].type == ParamType::REGISTER && params[1].type == ParamType::REGISTER))
			throw Exception("Param type error!");
		int address = params[0].getValue(vm);
		int value1 = params[1].getValue(vm);
		int value2 = params[2].getValue(vm);
		int value = value1 | value2;
		vm->getRegister(address)->write(value);
	}
	catch (Exception& e) {
		throw("Failed to run command\"or\"", e);
	}
}
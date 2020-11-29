#include "mul.h"
#include "../../vm/vm.h"

erisc::Mul::Mul(char* parastring) :erisc::Command(3, parastring) {

}

erisc::Mul::~Mul() {

}

void erisc::Mul::run(VM* vm) {
	try {
		if (!(params[0].type == ParamType::REGISTER && params[1].type == ParamType::REGISTER))
			throw Exception("Param type error!");
		int address = params[0].getValue(vm);
		int value1 = params[1].getValue(vm);
		int	value2 = params[2].getValue(vm);
		int value = value1 * value2;
		vm->getRegister(address)->write(value);
	}
	catch (Exception& e) {
		throw("Failed to run command\"mul\"",e);
	}
}
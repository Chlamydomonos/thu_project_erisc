#ifndef OUTPUT_H
#define OUTPUT_H
#include <cstdio>

namespace vm
{
	class VM;
}

namespace output
{
	/**
	* @brief 输出result.txt文件
	* @param vm 虚拟机
	*/
	void outputText(vm::VM* vm);
}
#endif // !OUTPUT_H

#ifndef INPUTUTIL_H
#define INPUTUTIL_H
#include "../command/command.h"

using erisc::Command;

namespace input
{
	/**
	* @brief 从指定的文件向虚拟机读取指令列表（该函数并不会替换虚拟机的指令列表，需要手动替换）
	* @param fileName 文件名
	* @param vm 将运行该指令的虚拟机
	*/
	extern Command** readCommandsFromFile(const char* fileName, vm::VM* vm);

	/**
	* @brief 从字符串读取一条指令
	* @param str 字符串
	* @param vm 将运行该指令的虚拟机
	* @param lineNum 该指令的行号
	*/
	extern Command* readSingleCommand(const char* str, vm::VM* vm, int lineNum);
}

#endif // !INPUTUTIL_H

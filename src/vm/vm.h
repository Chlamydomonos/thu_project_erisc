#ifndef VM_H
#define VM_H

#include "ememory.h"
#include "eregister.h"
#include "estack.h"

#define REGISTER_AMOUNT 32

//为防止头文件互相包含，在此重新声明erisc::Command
namespace erisc
{
	class Command;
}

namespace vm
{
	/**
	* @brief 虚拟机。拥有一个4MB内存，32个寄存器与一个4MB栈
	*/
	class VM
	{
	public:
		/**
		* @brief 构造函数
		* @param maxCommands 虚拟机能储存的最大指令数量
		*/
		VM(int maxCommands);
		~VM();

		/*
		* @brief 获取虚拟机的内存
		* @return 虚拟机的内存
		*/
		EMemory* getMemory();

		/**
		* @brief 获取虚拟机的栈
		* @return 虚拟机的栈
		*/
		EStack* getStack();

		/**
		* @brief 获取一个寄存器
		* @param index 寄存器的序号 (范围为[0, 32))
		* @return 该序号下的寄存器
		*/
		ERegister* getRegister(int index);

		/**
		* @brief 把虚拟机的指令列表初始化为给定的指令列表
		* @warning 该函数执行后并不会删除传入的指令列表，请在传入的指令列表使用完毕后手动删除
		* @param commands 给定的指令列表
		* @param commandAmount 该指令列表中指令的数量
		*/
		void initCommands(erisc::Command* commands, int commandAmount);

		/**
		* @brief 执行一条指令
		* @param line 该指令的行号 (从1开始)
		*/
		void runCommand(int line);

		/**
		* 向指令列表中添加一条指令
		* @param command 要添加的指令
		*/
		void addCommand(erisc::Command command);

		///目前正在运行的指令的行号
		int currentRunningLine;

	private:
		///虚拟机的内存
		EMemory* eMemory;
		///虚拟机的栈
		EStack* eStack;
		///虚拟机的寄存器列表
		ERegister* eRegister;
		///虚拟机的指令列表
		erisc::Command* commands;
		///虚拟机的最大指令数量
		int maxCommandAmount;
		///虚拟机目前的指令数量
		int currentCommandAmount;
	};
}

#endif // !VM_H
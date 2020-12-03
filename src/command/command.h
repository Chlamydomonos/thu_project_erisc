#ifndef COMMAND_H
#define COMMAND_H

#include "../vm/vm.h"

namespace erisc
{
	/**
	* @brief 指令参数的类型
	*/
	enum class ParamType
	{
		/// 寄存器
		REGISTER,
		/// 立即数
		NUMBER
	};

	/**
	* @brief 指令参数
	*/
	struct Param
	{
		/// 类型（寄存器/立即数）
		ParamType type;

		/// 值【是立即数时即为数字大小，是寄存器时即为寄存器编号（从0开始）】
		int value;

		/**
		* @brief 构造函数
		* @param type 类型（寄存器/立即数）
		* @param value 值【是立即数时即为数字大小，是寄存器时即为寄存器编号（从0开始）】
		*/
		Param(ParamType type, int value);

		/**
		* @brief 默认构造函数，将参数初始化为数字0
		*/
		Param();

		/*
		* @brief 获取参数在虚拟机中代表的实际数值
		* @param vm 虚拟机
		* @return 若参数为立即数则直接返回值，若参数为寄存器则返回寄存器中存储的值
		*/
		int getValue(vm::VM *vm);
	};

	/*
	* @brief 命令的基类，其它命令需要继承它
	*/
	class Command
	{
	public:
		/**
		* @brief 创建参数数量为0的命令
		*/
		Command();

		/**
		* @brief 创建参数数量不为0的命令
		* @param paramAmount 命令的参数数量
		* @param paramString 代表参数的字符串
		*/
		Command(int paramAmount, const char *paramString);
		~Command();

		/**
		* @brief 命令在虚拟机运行时执行的逻辑
		* @param vm 虚拟机
		*/
		virtual void run(vm::VM* vm);
	protected:

		/// 参数数量
		int paramAmount;
		/// 参数列表
		Param* params;
	private:
		void getParamsFromString(const char* str);
	};
}

#endif // !COMMAND_H

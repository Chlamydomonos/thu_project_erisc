#ifndef STACK_H
#define STACK_H

#define MAX_STACK 1<<20
namespace erisc
{
	class Stack
	{
	public:
		Stack();
		~Stack();

		/**
		* @brief 把一个32位整数压入栈
		* @param value 要压入栈的整数
		*/
		void push(int value);

		/**
		* @brief 取出栈顶的整数
		* @return 栈顶的数
		*/
		int pop();

		/**
		* @brief 判断栈是否被读写过
		* @return 栈是否被读写过
		*/
		bool* getAccessed();

		/**
		* @brief 清空栈读写的历史记录
		*/
		void clearHistory();
	private:
		int* stack_list;
		int* stack_top;
		bool accessed;
	};
}
#endif // !STACK_H

#ifndef STACK_H
#define STACK_H
#include "../exception/exception.h"

#define MAX_STACK 1<<20
namespace vm
{
	class EStack
	{
	public:
		EStack();
		~EStack();

		/**
		* @brief ��һ��32λ����ѹ��ջ
		* @param value Ҫѹ��ջ������
		*/
		void push(int value);

		/**
		* @brief ȡ��ջ��������
		* @return ջ������
		*/
		int pop();

		/**
		* @brief �ж�ջ�Ƿ񱻶�д��
		* @return ջ�Ƿ񱻶�д��
		*/
		bool getAccessed();

		/**
		* @brief ���ջ��д����ʷ��¼
		*/
		void clearHistory();
	private:
		int* stackTop;
		bool accessed;
		int* stackBottom;
	};
}

#endif // !STACK_H

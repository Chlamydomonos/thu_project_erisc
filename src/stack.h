#ifndef STACK_H
#define STACK_H

#define MAX_STACK 1<<20
class Stack
{
public:
	Stack();
	~Stack();

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
	bool* getAccessed();

	/**
	* @brief ���ջ��д����ʷ��¼
	*/
	void clearHistory();
private:
	int* stack_list;
	int* stack_top;
	bool accessed;
};
#endif // !STACK_H

#ifndef VM_H
#define VM_H

#include "ememory.h"
#include "eregister.h"
#include "estack.h"

#define REGISTER_AMOUNT 32

namespace erisc
{
	class Command;
}

using erisc::Command;

namespace vm
{
	/**
	* @brief �������ӵ��һ��4MB�ڴ棬32���Ĵ�����һ��4MBջ
	*/
	class VM
	{
	public:
		/**
		* @brief ���캯��
		* @param maxCommands ������ܴ�������ָ������
		*/
		VM(int maxCommands);
		~VM();

		/*
		* @brief ��ȡ��������ڴ�
		* @return ��������ڴ�
		*/
		EMemory* getMemory();

		/**
		* @brief ��ȡ�������ջ
		* @return �������ջ
		*/
		EStack* getStack();

		/**
		* @brief ��ȡһ���Ĵ���
		* @param index �Ĵ�������� (��ΧΪ[0, 32))
		* @return ������µļĴ���
		*/
		ERegister* getRegister(int index);

		/**
		* @brief ���������ָ���б��ʼ��Ϊ������ָ���б�
		* @warning �ú���ִ�к󲢲���ɾ�������ָ���б����ڴ����ָ���б�ʹ����Ϻ��ֶ�ɾ��
		* @param commands ������ָ���б�
		* @param commandAmount ��ָ���б���ָ�������
		*/
		void initCommands(Command* commands, int commandAmount);

		/**
		* @brief ִ��һ��ָ��
		* @param line ��ָ����к� (��1��ʼ)
		*/
		void runCommand(int line);

		/**
		* ��ָ���б������һ��ָ��
		* @param command Ҫ��ӵ�ָ��
		*/
		void addCommand(Command command);

	private:
		///��������ڴ�
		EMemory* eMemory;
		///�������ջ
		EStack* eStack;
		///������ļĴ����б�
		ERegister* eRegister;
		///�������ָ���б�
		Command* commands;
		///����������ָ������
		int maxCommandAmount;
		///�����Ŀǰ��ָ������
		int currentCommandAmount;
	};
}

#endif // !VM_H
#ifndef INPUTUTIL_H
#define INPUTUTIL_H
#include "../command/command.h"

using erisc::Command;

namespace input
{
	/**
	* @brief ��ָ�����ļ����������ȡָ���б��ú����������滻�������ָ���б���Ҫ�ֶ��滻��
	* @param fileName �ļ���
	* @param vm �����и�ָ��������
	*/
	extern Command** readCommandsFromFile(const char* fileName, vm::VM* vm);

	/**
	* @brief ���ַ�����ȡһ��ָ��
	* @param str �ַ���
	* @param vm �����и�ָ��������
	* @param lineNum ��ָ����к�
	*/
	extern Command* readSingleCommand(const char* str, vm::VM* vm, int lineNum);
}

#endif // !INPUTUTIL_H

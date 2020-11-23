#ifndef COMMAND_H
#define COMMAND_H

#include "../vm/vm.h"

using vm::VM;

namespace erisc
{
	/**
	* @brief ָ�����������
	*/
	enum class ParamType
	{
		/// �Ĵ���
		REGISTER,
		/// ������
		NUMBER
	};

	/**
	* @brief ָ�����
	*/
	struct Param
	{
		/// ���ͣ��Ĵ���/��������
		ParamType type;

		/// ֵ����������ʱ��Ϊ���ִ�С���ǼĴ���ʱ��Ϊ�Ĵ�����ţ���0��ʼ����
		int value;

		/**
		* @brief ���캯��
		* @param type ���ͣ��Ĵ���/��������
		* @param value ֵ����������ʱ��Ϊ���ִ�С���ǼĴ���ʱ��Ϊ�Ĵ�����ţ���0��ʼ����
		*/
		Param(ParamType type, int value);

		/*
		* @brief ��ȡ������������д����ʵ����ֵ
		* @param vm �����
		* @return ������Ϊ��������ֱ�ӷ���ֵ��������Ϊ�Ĵ����򷵻ؼĴ����д洢��ֵ
		*/
		int getValue(VM *vm);
	};

	/*
	* @brief ����Ļ��࣬����������Ҫ�̳���
	*/
	class Command
	{
	public:
		/**
		* @brief ������������Ϊ0������
		*/
		Command();

		/**
		* @brief ��������������Ϊ0������
		* @param paramAmount ����Ĳ�������
		* @param paramString ����������ַ���
		*/
		Command(int paramAmount, char *paramString);
		~Command();

		/**
		* @brief ���������������ʱִ�е��߼�
		* @param vm �����
		*/
		virtual void run(VM* vm);
	protected:

		/// ��������
		int paramAmount;
		/// �����б�
		Param* params;
	private:
		void getParamsFromString(char* str);
	};
}

#endif // !COMMAND_H

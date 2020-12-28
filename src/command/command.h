#ifndef COMMAND_H
#define COMMAND_H

#include "../vm/vm.h"

#ifdef QT_IN_PROJECT

#include <QObject>

#endif

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
		NUMBER,
		/// �б�ʶ
		LINE_ID
	};

	/**
	* @brief ָ�����
	*/
	struct Param
	{
		/// ���ͣ��Ĵ���/������/�б�ʶ��
		ParamType type;

		/// ֵ����������ʱ��Ϊ���ִ�С���ǼĴ���ʱ��Ϊ�Ĵ�����ţ���0��ʼ�������б�ʶʱ�����塿
		int value;

		/// �б�ʶ�����ƣ��ǼĴ���/������ʱ�����壩
		char* id;

		/**
		* @brief ���캯������������ʼ��Ϊ�Ĵ�����������
		* @param type ���ͣ��Ĵ���/��������
		* @param value ֵ����������ʱ��Ϊ���ִ�С���ǼĴ���ʱ��Ϊ�Ĵ�����ţ���0��ʼ����
		*/
		Param(ParamType type, int value);

		/**
		* @brief ���캯������������ʼ��Ϊ�б�ʶ
		* @param id �б�ʶ������
		*/
		Param(const char* id);

		/**
		* @brief Ĭ�Ϲ��캯������������ʼ��Ϊ����0
		*/
		Param();

		/*
		* @brief ��ȡ������������д����ʵ����ֵ
		* @param vm �����
		* @return ������Ϊ��������ֱ�ӷ���ֵ��������Ϊ�Ĵ����򷵻ؼĴ����д洢��ֵ
		*/
		int getValue(vm::VM *vm);
	};
#ifndef QT_IN_PROJECT
	/*
	* @brief ����Ļ��࣬����������Ҫ�̳���
	*/
	class Command
#else
    class Command : public QObject
#endif
	{
#ifdef QT_IN_PROJECT
        Q_OBJECT
    signals:
        void draw();
#endif
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
		Command(int paramAmount, const char *paramString);
		~Command();

		/**
		* @brief ���������������ʱִ�е��߼�
		* @param vm �����
		*/
		virtual void run(vm::VM* vm);
	protected:

		/// ��������
		int paramAmount;
		/// �����б�
		Param* params;
	private:
		void getParamsFromString(const char* str);
	};
}

#endif // !COMMAND_H

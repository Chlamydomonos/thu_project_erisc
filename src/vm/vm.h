#ifndef VM_H
#define VM_H

#include "ememory.h"
#include "eregister.h"
#include "estack.h"
#include "lineidlist.h"

#ifdef QT_IN_PROJECT
#include <QObject>
#endif

#define REGISTER_AMOUNT 32

namespace erisc
{
	//Ϊ��ֹͷ�ļ�����������ڴ���������erisc::Command
	class Command;
}

namespace vm
{
	/**
	* @brief �������ӵ��һ��4MB�ڴ棬32���Ĵ�����һ��4MBջ
	*/
#ifndef QT_IN_PROJECT
        class VM
        {
        public:
            /**
            * @brief ���캯��
            * @param maxCommands ������ܴ�������ָ������
            */
            VM(int maxCommands);
            ~VM();
#else
        class VM : public QObject
        {
            Q_OBJECT

        signals:
            void draw();

        public slots:
            void emitDraw();
        public:
            explicit VM(int maxCommands, QObject* parent = nullptr);
            ~VM() override;
#endif

        /**
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
		* @brief ��ȡ�б�ʶ�б�
		* @return ��������б�ʶ�б�
		*/
		LineIdList* getLineIdList();

		/**
		* @brief ���������ָ���б��ʼ��Ϊ������ָ���б�
		* @warning �ú���ִ�к󲢲���ɾ�������ָ���б����ڴ����ָ���б�ʹ����Ϻ��ֶ�ɾ��
		* @param commands ������ָ���б�
		*/
		void initCommands(erisc::Command** commands);

		/**
		* @brief ִ��һ��ָ��
		* @param line ��ָ����к� (��1��ʼ)
		*/
		void runCommand(int line);

		/**
		* @brief ִ��ĿǰӦ��ִ��ָ��
		*/
		void runCurrentCommand();

		/**
		* ��ָ���б������һ��ָ��
		* @param command Ҫ��ӵ�ָ��
		*/
		void addCommand(erisc::Command* command);

        int getCurrentCommandAmount();

		///Ŀǰ�������е�ָ����к�
		int currentRunningLine;
		///�ڼ���ִ��draw����
		int timesOfDraw;
		///������Ƿ������н���
		bool end;

	private:
		///��������ڴ�
		EMemory* eMemory;
		///�������ջ
		EStack* eStack;
		///������ļĴ����б�
		ERegister* eRegister;
		///�������ָ���б�
		erisc::Command** commands;
		///��������б�ʶ�б�
		LineIdList* lineIds;
		///����������ָ������
		int maxCommandAmount;
		///�����Ŀǰ��ָ������
		int currentCommandAmount;
	};
}

#endif // !VM_H

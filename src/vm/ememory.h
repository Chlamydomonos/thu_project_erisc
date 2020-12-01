#ifndef MEMORY_H
#define MEMORY_H

#include"../exception/exception.h"

#define MAX_MEMORY 1<<22
namespace vm
{
	class EMemory
	{
	public:
		EMemory();
		~EMemory();

		/**
		* @brief ��ȡ�ڴ���ָ����ַ
		* @param address	 ��address����ʼ��ȡ
		* @return ������ȡ4�ֽ���ɵ�����
		*/
		int read(int address);

		/**
		* @brief ��һ��32λ����д���ڴ���ָ���ĵ�ַ
		* @param value Ҫд���ڴ����
		* @param address ��ʼд��ĵ�ַ������д��4�ֽ�
		*/
		void write(int value, int address);

		/**
		* @brief �ж��ڴ��ĳ�����Ƿ񱻷��ʹ�
		* @param zone ���ڴ����Ϊ��16�������е�һ������Χ0-15
		* @return �������Ƿ񱻷��ʹ�
		*/
		bool getAccessed(int zone);

		/**
		* @brief ����ڴ���ʵ���ʷ��¼
		*/
		void clearHistory();
	private:
		unsigned char* memoryList;
		bool* hasAccessed;
	};
}
#endif // !MEMORY_H

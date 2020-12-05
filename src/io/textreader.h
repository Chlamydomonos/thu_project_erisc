#ifndef TEXTREADER_H
#define TEXTREADER_H
#include <cstdio>

namespace input
{
	/**
	* @brief Ϊ��ʵ�ֲ����������봴����һ���򵥵�����
	*/
	struct ListNode
	{
		char value;
		ListNode* next;
		ListNode(char value, ListNode* pre);
		~ListNode();
	};

	/**
	* @brief ���ڶ�ȡ�ı�����
	*/
	class TextReader
	{
	public:

		/**
		* @brief ���캯��
		* @param fileName �ı��ļ����ļ���
		*/
		TextReader(const char* fileName);
		~TextReader();

		/**
		* @brief ��ȡ�ı���һ��
		* @return �������ַ���
		*/
		char* readLine();
	private:
		FILE* file;
		bool eof;
	};
}
#endif // !TEXTREADER_H

#ifndef TEXTREADER_H
#define TEXTREADER_H
#include <cstdio>

namespace input
{
	/**
	* @brief Ϊ��ʵ�ֲ����������봴����һ���򵥵�����
	*/
	template<typename T>
	struct ListNode
	{
		T value;
		ListNode* next;
		bool isArray;
		ListNode(T value, ListNode* pre, bool isArray);
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
		ListNode<char*>* root;
		ListNode<char*>* end;
	};
}
#endif // !TEXTREADER_H

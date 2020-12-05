#ifndef TEXTREADER_H
#define TEXTREADER_H
#include <cstdio>

namespace input
{
	/**
	* @brief 为了实现不定长度输入创建的一个简单的链表
	*/
	struct ListNode
	{
		char value;
		ListNode* next;
		ListNode(char value, ListNode* pre);
		~ListNode();
	};

	/**
	* @brief 用于读取文本的类
	*/
	class TextReader
	{
	public:

		/**
		* @brief 构造函数
		* @param fileName 文本文件的文件名
		*/
		TextReader(const char* fileName);
		~TextReader();

		/**
		* @brief 读取文本的一行
		* @return 读到的字符串
		*/
		char* readLine();
	private:
		FILE* file;
		bool eof;
	};
}
#endif // !TEXTREADER_H

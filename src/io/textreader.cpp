#include "textreader.h"
#include <cstring>
#include "../exception/exception.h"
#include "../fuckide/fuckide.h"
using namespace input;

input::TextReader::TextReader(const char* fileName)
{
	file = fuckIDEfopen(fileName, "r");
	root = new ListNode<char*>(new char[1]{ 0 }, nullptr, true);
	end = root;
	if (file == nullptr)
	{
		const char* head = "File \"";
		int len1 = strlen(head);
		int len2 = len1 + strlen(fileName);
		const char* tail = "\" does not exist";
		int len3 = len2 + strlen(tail);
		char* message = new char[len3 + 1];
		for (int i = 0; i < len1; i++)
			message[i] = head[i];
		for (int i = len1; i < len2; i++)
			message[i] = fileName[i - len1];
		for (int i = len2; i < len3; i++)
			message[i] = fileName[i - len2];
		message[len3] = 0;
		throw Exception(message);
		delete[] message;
	}
	eof = false;
	if (feof(file))
		eof = true;
}

input::TextReader::~TextReader()
{
	fclose(file);
	delete root;
}

char* input::TextReader::readLine()
{
	if (eof)
	{
		char* temp = new char[1]{ 0 };
		ListNode<char*>* tempNode = new ListNode<char*>(temp, end, true);
		end = tempNode;
		return temp;
	}
	int len = 0;
	ListNode<char>* root = nullptr;
	ListNode<char>* temp = nullptr;
	while (true)
	{
		len++;
		ListNode<char>* temp2 = new ListNode<char>(fgetc(file), temp, false);
		if (root == nullptr)
			root = temp2;
		temp = temp2;
		if (temp2->value == '\n')
			break;
		if (feof(file))
		{
			eof = true;
			break;
		}
	}
	char* str = new char[len + 1];
	temp = root;
	for (char* i = str; i < str + len; i++)
	{
		*i = temp->value;
		temp = temp->next;
	}
	str[len] = 0;
	delete root;
	ListNode<char*>* tempNode = new ListNode<char*>(str, end, true);
	end = tempNode;
	return str;
}

template<typename T>
input::ListNode<T>::ListNode(T value, ListNode* pre, bool isArray)
{
	this->value = value;
	this->isArray = isArray;
	next = nullptr;
	if (pre != nullptr)
		pre->next = this;
}

template<typename T>
input::ListNode<T>::~ListNode()
{
	if (isArray)
		delete[] (char*)value;
	if (next != nullptr)
		delete next;
}

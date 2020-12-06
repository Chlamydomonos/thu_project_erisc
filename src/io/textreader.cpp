#include "textreader.h"
#include <cstring>
#include "../exception/exception.h"
#include "../fuckide/fuckide.h"
using namespace input;

input::TextReader::TextReader(const char* fileName)
{
	file = fuckIDEfopen(fileName, "r");
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
}

char* input::TextReader::readLine()
{
	if (eof)
		return new char[1]{ 0 };
	int len = 0;
	ListNode* root = nullptr;
	ListNode* temp = nullptr;
	while (true)
	{
		len++;
		ListNode* temp2 = new ListNode(fgetc(file), temp);
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
	return str;
}

input::ListNode::ListNode(char value, ListNode* pre)
{
	this->value = value;
	next = nullptr;
	if (pre != nullptr)
		pre->next = this;
}

input::ListNode::~ListNode()
{
	if (next != nullptr)
		delete next;
}

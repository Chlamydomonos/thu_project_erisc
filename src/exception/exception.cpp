#include "exception.h"

void myStrcpy(char* destination, const char* source)
{
	int len = strlen(source);
	for (int i = 0; i < len; i++)
		destination[i] = source[i];
}

Exception::Exception(const char* message)
{
	int len = strlen(message);
	this->message = new char[len + 1];
	for (int i = 0; i <= len; i++)
		this->message[i] = 0;
	myStrcpy(this->message, message);
}

Exception::Exception(const char* message, Exception& e)
{
	int len1 = strlen(message);
	int len2 = strlen(e.what());
	this->message = new char[len1 + len2 + 3];
	for (int i = 0; i < len1 + len2 + 3; i++)
		this->message[i] = 0;
	myStrcpy(this->message, message);
	this->message[len1] = ':';
	this->message[len1 + 1] = '\n';
	myStrcpy(this->message + len1 + 2, e.what());
}

char* Exception::what()
{
	return message;
}

Exception::~Exception()
{
	delete[]message;
}

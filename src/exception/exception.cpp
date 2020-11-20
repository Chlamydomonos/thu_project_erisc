#include "exception.h"

Exception::Exception(const char* message)
{
	this->message = new char[strlen(message)];
	strcpy(this->message, message);
}

char* Exception::what()
{
	return message;
}

Exception::~Exception()
{
	delete[]message;
}

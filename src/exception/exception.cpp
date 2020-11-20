#include "exception.h"

exception::Exception::Exception(char* message)
{
	this->message = message;
}

char* exception::Exception::what()
{
	return message;
}

exception::Exception::~Exception()
{
	delete[]message;
}

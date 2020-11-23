#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <cstring>
class Exception
{
public:
	Exception(const char* message);
	Exception(const char* message, Exception& e);
	char* what();
	~Exception();
private:
	char* message;
	void myStrcpy(char* destination, const char* source);
};

#endif // !EXCEPTION_H

#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <cstring>
class Exception
{
public:
	Exception(const char* message);
	char* what();
	~Exception();
private:
	char* message;
};

#endif // !EXCEPTION_H

#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception
{
public:
	Exception(char* message);
	char* what();
	~Exception();
private:
	char* message;
};

#endif // !EXCEPTION_H

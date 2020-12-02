#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <cstring>
/**
* @brief 异常。此程序中抛出的所有异常都应使用此异常类
*/
class Exception
{
public:
	/**
	* @brief 构造函数
	* @param message 异常信息
	*/
	Exception(const char* message);
	/**
	* @brief 在已有异常上附加信息的构造函数
	* @param message 附加的信息（格式为“新信息:\\n原信息”）
	* @param e 原来的异常
	*/
	Exception(const char* message, Exception& e);

	/**
	* @用于异常处理系统复制异常对象的构造函数
	* @param e 需要复制的原异常
	*/
	Exception(const Exception& e);

	/**
	* @brief 获取异常信息
	* @return 异常信息
	*/
	const char* what();
	~Exception();
private:
	char* message;
};

#endif // !EXCEPTION_H

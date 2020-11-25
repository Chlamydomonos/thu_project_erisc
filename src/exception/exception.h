#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <cstring>
/**
* @brief �쳣���˳������׳��������쳣��Ӧʹ�ô��쳣��
*/
class Exception
{
public:
	/**
	* @brief ���캯��
	* @param message �쳣��Ϣ
	*/
	Exception(const char* message);
	/**
	* @brief �������쳣�ϸ�����Ϣ�Ĺ��캯��
	* @param message ���ӵ���Ϣ����ʽΪ������Ϣ:\\nԭ��Ϣ����
	* @param e ԭ�����쳣
	*/
	Exception(const char* message, Exception& e);
	/**
	* @brief ��ȡ�쳣��Ϣ
	* @return �쳣��Ϣ
	*/
	char* what();
	~Exception();
private:
	char* message;
};

#endif // !EXCEPTION_H

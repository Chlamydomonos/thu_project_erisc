#ifndef REGISTER_H
#define REGISTER_H
namespace vm
{
	class ERegister
	{
	public:
		ERegister();
		~ERegister();

		/**
		* @brief ��һ��32λ����д��Ĵ���
		* @param value д��Ĵ�������
		*/
		void write(int value);

		/**
		* @brief ��ȡ�Ĵ�����ֵ
		* @return �Ĵ�����ֵ
		*/
		int read();

		/**
		* @brief �жϼĴ����Ƿ񱻶���
		* @return �Ĵ����Ƿ񱻶���
		*/
		bool getRead();

		/**
		* @brief �жϼĴ����Ƿ�д��
		* @return �Ĵ����Ƿ�д��
		*/
		bool getWritten();

		/**
		* @brief ��ռĴ�����д����ʷ��¼
		*/
		bool clearHistory();
	private:
		int value;
		bool hasRead;
		bool hasWritten;
	};
}
#endif // !REGISTER_H

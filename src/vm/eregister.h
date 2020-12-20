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
		* @brief 将一个32位整数写入寄存器
		* @param value 写入寄存器的数
		*/
		void write(int value);

		/**
		* @brief 读取寄存器的值
		* @return 寄存器的值
		*/
		int read();

		/**
		* @brief 判断寄存器是否被读过
		* @return 寄存器是否被读过
		*/
		bool getRead();

		/**
		* @brief 判断寄存器是否被写过
		* @return 寄存器是否被写过
		*/
		bool getWritten();

		/**
		* @brief 获取寄存器的值（仅限文本输出使用！）
		* @return 寄存器的值
		*/
		int getValue();

		/**
		* @brief 获取寄存器的值（仅限文本输出使用！）
		* @return 寄存器的值
		*/
		int getValue();

		/**
		* @brief 清空寄存器读写的历史记录
		*/
		void clearHistory();
	private:
		int value;
		bool hasRead;
		bool hasWritten;
	};
}

#endif // !REGISTER_H

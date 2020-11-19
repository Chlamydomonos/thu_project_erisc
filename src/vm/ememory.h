#ifndef MEMORY_H
#define MEMORY_H

#define MAX_MEMORY 1<<22
namespace vm
{
	class EMemory
	{
	public:
		EMemory();
		~EMemory();

		/**
		* @brief 读取内存中指定地址
		* @param address	 从address处开始读取
		* @return 连续读取4字节组成的整数
		*/
		int read(int address);

		/**
		* @brief 把一个32位整数写入内存中指定的地址
		* @param value 要写入内存的数
		* @param address 开始写入的地址，连续写入4字节
		*/
		void write(int value, int address);

		/**
		* @brief 判断内存的某区域是否被访问过
		* @param zone 把内存均分为的16个区域中的一个，范围0-15
		* @return 该区域是否被访问过
		*/
		bool getAccessed(int zone);

		/**
		* @brief 清空内存访问的历史记录
		*/
		void clearHistory();
	private:
		unsigned char* memoryList;
		bool* hasAccessed;
		/*
		* 判断是否超出内存的边界
		*/
		void border_judge(int address);
	};
}
#endif // !MEMORY_H

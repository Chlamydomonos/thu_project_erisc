#ifndef LINEID_H
#define LINEID_H

#include "command.h"

namespace erisc
{
	/**
	* @brief 行标识
	*/
	class LineId : public Command
	{
	public:
		/**
		* @brief 构造函数
		* @param name 行标识的名称
		* @param line 行标识所在行的行号（行号从1开始）
		*/
		LineId(const char* name, int line);
		~LineId();

		/**
		* @brief 获取名称
		* @return 该行标识的名称
		*/
		char* getName();

		/**
		* @brief 获取行标识代表的行号（行号从1开始）
		* @return 该行标识所在行的行号
		*/
		int getLine();

		/**
		* @brief 判断两个只由大小写字母组成的字符串是否相同
		* @param a 参与比较的第一个字符串
		* @param b 参与比较的第二个字符串
		* @return a与b是否相同
		*/
		static bool strSame(const char* a, const char* b);

		/**
		* @brief 判断一个只由大小写字母组成的字符串是否在字典序（AaBbCc……）上位于另一个之后（如“Zzz” > “xxx” > “Xxx” > “Xax”）
		* @param a 参与比较的第一个字符串
		* @param b 参与比较的第二个字符串
		* @return a是否在字典序上位于b之后
		*/
		static bool strBigger(const char* a, const char* b);

		/**
		* @brief 判断一个只由大小写字母组成的字符串是否在字典序（AaBbCc……）上位于另一个之前（如“Aaa” < “Aba” < “aaa” < “Bbb”）
		* @param a 参与比较的第一个字符串
		* @param b 参与比较的第二个字符串
		* @return a是否在字典序上位于b之前
		*/
		static bool strSmaller(const char* a,const char* b);

		/**
		* @brief 重载的运算符==，判断两行标识是否相同
		* @param b 参与比较的另一个行标识
		* @return 两行标识是否相同
		*/
		bool operator==(const LineId& b);

		/**
		* @brief 重载的运算符>，判断一个行标识是否在字典序（AaBbCc……）上位于另一个之后（如“Zzz” > “xxx” > “Xxx” > “Xax”）
		* @param b 参与比较的另一个行标识
		* @return 此行标识是否在字典序上位于b之后
		*/
		bool operator>(const LineId& b);

		/**
		* @brief 重载的运算符<，判断一个行标识是否在字典序（AaBbCc……）上位于另一个之前（如“Aaa” < “Aba” < “aaa” < “Bbb”）
		* @param b 参与比较的另一个行标识
		* @return 此行标识是否在字典序上位于b之前
		*/
		bool operator<(const LineId& b);

		/**
		* @brief 重载的运算符>=，为“>”和“==”的析取
		* @param b 参与比较的另一个行标识
		* @return 比较结果
		*/
		bool operator>=(const LineId& b);

		/**
		* @brief 重载的运算符<=，为“<”和“==”的析取
		* @param b 参与比较的另一个行标识
		* @return 比较结果
		*/
		bool operator<=(const LineId& b);
	private:
		char* name;
		int line;
	};
}

#endif // !LINEID_H

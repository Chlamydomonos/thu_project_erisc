#ifndef LINEID_H
#define LINEID_H

#include "command.h"

namespace erisc
{
	/**
	* @brief �б�ʶ
	*/
	class LineId : public Command
	{
	public:
		/**
		* @brief ���캯��
		* @param name �б�ʶ������
		* @param line �б�ʶ��һ�е��кţ��кŴ�1��ʼ��
		*/
		LineId(char* name, int line);
		~LineId();

		/**
		* @brief ��ȡ����
		* @return ���б�ʶ������
		*/
		char* getName();

		/**
		* @brief ��ȡ�б�ʶ������кţ��кŴ�1��ʼ��
		* @return ���б�ʶ��һ�е��к�
		*/
		int getLine();

		/**
		* @brief ���ص������==���ж����б�ʶ�Ƿ���ͬ
		* @param b ����Ƚϵ���һ���б�ʶ
		* @return ���б�ʶ�Ƿ���ͬ
		*/
		bool operator==(const LineId* b);

		/**
		* @brief ���ص������>���ж�һ���б�ʶ�Ƿ����ֵ���AaBbCc��������λ����һ��֮���硰Zzz�� > ��xxx�� > ��Xxx�� > ��Xax����
		* @param b ����Ƚϵ���һ���б�ʶ
		* @return ���б�ʶ�Ƿ����ֵ�����λ��b֮��
		*/
		bool operator>(const LineId* b);

		/**
		* @brief ���ص������<���ж�һ���б�ʶ�Ƿ����ֵ���AaBbCc��������λ����һ��֮ǰ���硰Aaa�� < ��Aba�� < ��aaa�� < ��Bbb����
		* @param b ����Ƚϵ���һ���б�ʶ
		* @return ���б�ʶ�Ƿ����ֵ�����λ��b֮ǰ
		*/
		bool operator<(const LineId* b);

		/**
		* @brief ���ص������>=��Ϊ��>���͡�==������ȡ
		* @param b ����Ƚϵ���һ���б�ʶ
		* @return �ȽϽ��
		*/
		bool operator>=(const LineId* b);

		/**
		* @brief ���ص������<=��Ϊ��<���͡�==������ȡ
		* @param b ����Ƚϵ���һ���б�ʶ
		* @return �ȽϽ��
		*/
		bool operator<=(const LineId* b);
	private:
		char* name;
		int line;
	};
}

#endif // !LINEID_H

#ifndef IMAGECONFIGREADER_H
#define IMAGECONFIGREADER_H

#include <cstdio>

namespace input
{
	/**
	* @brief ���ڶ�ȡͼƬ�����ļ����ࣨ��ȡ�����������õ�����ϵԭ��ΪͼƬ���Ͻǣ���BMP�ļ���ͬ��
	*/
	class ImageConfigReader
	{
	public:
		/**
		* @brief ���캯��
		* @param fileName Ҫ��ȡ���ļ���
		*/
		ImageConfigReader(const char* fileName);
		~ImageConfigReader();

		/**
		* @brief ��ȡ����Ĵ������������㣨���Ͻǣ������꣨�����λ�ڵ�һ����������ϱ߿��ڲࣩ
		* @return ����Ĵ������������������
		*/
		int getRegisterOffsetX();

		/**
		* @brief ��ȡ����Ĵ������������㣨���Ͻǣ������꣨�����λ�ڵ�һ����������ϱ߿��ڲࣩ
		* @return ����Ĵ�������������������
		*/
		int getRegisterOffsetY();

		/**
		* @brief ��ȡ�����ڴ���������㣨���Ͻǣ������꣨�����λ�ڵ�һ����������ϱ߿��ڲࣩ
		* @return �����ڴ���������������
		*/
		int getMemoryOffsetX();

		/**
		* @brief ��ȡ�����ڴ���������㣨���Ͻǣ������꣨�����λ�ڵ�һ����������ϱ߿��ڲࣩ
		* @return �����ڴ����������������
		*/
		int getMemoryOffsetY();

		/**
		* @brief ��ȡ����ջ���������㣨���Ͻǣ������꣨�����λ�ڵ�һ����������ϱ߿��ڲࣩ
		* @return ����ջ���������������
		*/
		int getStackOffsetX();

		/**
		* @brief ��ȡ����ջ���������㣨���Ͻǣ������꣨�����λ�ڵ�һ����������ϱ߿��ڲࣩ
		* @return ����ջ����������������
		*/
		int getStackOffsetY();

		/**
		* @brief ��ȡÿ������Ĵ����ķ���Ŀ�ȣ���������߿��ȣ��������ұ߿��ȣ�
		* @return ����Ĵ����ķ���Ŀ��
		*/
		int getRegisterSquareWidth();

		/**
		* @brief ��ȡÿ������Ĵ����ķ���ĸ߶ȣ��������ϱ߿�߶ȣ��������±߿�߶ȣ�
		* @return ����Ĵ����ķ���ĸ߶�
		*/
		int getRegisterSquareHeight();

		/**
		* @brief ��ȡÿ�������ڴ�ķ���Ŀ�ȣ���������߿��ȣ��������ұ߿��ȣ�
		* @retur	n �����ڴ�ķ���Ŀ��
		*/
		int getMemorySquareWidth();

		/**
		* @brief ��ȡÿ�������ڴ�ķ���ĸ߶ȣ��������ϱ߿�߶ȣ��������±߿�߶ȣ�
		* @return �����ڴ�ķ���ĸ߶�
		*/
		int getMemorySquareHeight();
	private:
		FILE* file;
		int* values;
	};
}

#endif // !IMAGECONFIGREADER_H

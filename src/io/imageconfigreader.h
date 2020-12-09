#ifndef IMAGECONFIGREADER_H
#define IMAGECONFIGREADER_H

#include <cstdio>

namespace input
{
	/**
	* @brief 用于读取图片配置文件的类（读取到的坐标所用的坐标系原点为图片左上角，与BMP文件不同）
	*/
	class ImageConfigReader
	{
	public:
		/**
		* @brief 构造函数
		* @param fileName 要读取的文件名
		*/
		ImageConfigReader(const char* fileName);
		~ImageConfigReader();

		/**
		* @brief 读取代表寄存器的区域的起点（左上角）横坐标（该起点位于第一个方格的左上边框内侧）
		* @return 代表寄存器的区域的起点横坐标
		*/
		int getRegisterOffsetX();

		/**
		* @brief 读取代表寄存器的区域的起点（左上角）纵坐标（该起点位于第一个方格的左上边框内侧）
		* @return 代表寄存器的区域的起点纵坐标
		*/
		int getRegisterOffsetY();

		/**
		* @brief 读取代表内存的区域的起点（左上角）横坐标（该起点位于第一个方格的左上边框内侧）
		* @return 代表内存的区域的起点横坐标
		*/
		int getMemoryOffsetX();

		/**
		* @brief 读取代表内存的区域的起点（左上角）纵坐标（该起点位于第一个方格的左上边框内侧）
		* @return 代表内存的区域的起点纵坐标
		*/
		int getMemoryOffsetY();

		/**
		* @brief 读取代表栈的区域的起点（左上角）横坐标（该起点位于第一个方格的左上边框内侧）
		* @return 代表栈的区域的起点横坐标
		*/
		int getStackOffsetX();

		/**
		* @brief 读取代表栈的区域的起点（左上角）纵坐标（该起点位于第一个方格的左上边框内侧）
		* @return 代表栈的区域的起点纵坐标
		*/
		int getStackOffsetY();

		/**
		* @brief 读取每个代表寄存器的方格的宽度（不包括左边框宽度，但包括右边框宽度）
		* @return 代表寄存器的方格的宽度
		*/
		int getRegisterSquareWidth();

		/**
		* @brief 读取每个代表寄存器的方格的高度（不包括上边框高度，但包括下边框高度）
		* @return 代表寄存器的方格的高度
		*/
		int getRegisterSquareHeight();

		/**
		* @brief 读取每个代表内存的方格的宽度（不包括左边框宽度，但包括右边框宽度）
		* @retur	n 代表内存的方格的宽度
		*/
		int getMemorySquareWidth();

		/**
		* @brief 读取每个代表内存的方格的高度（不包括上边框高度，但包括下边框高度）
		* @return 代表内存的方格的高度
		*/
		int getMemorySquareHeight();
	private:
		FILE* file;
		int* values;
	};
}

#endif // !IMAGECONFIGREADER_H

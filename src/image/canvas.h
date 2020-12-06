#ifndef CANVAS_H
#define CANVAS_H

namespace image
{
	/**
	* @brief 画布，其坐标系起点为左上角（与BMP文件不同），使用RGB颜色
	*/
	class Canvas
	{
	public:
		/**
		* @brief 构造函数，构造指定大小的纯黑色(0x000000)画布
		* @param width 画布的宽度
		* @param height 画布的高度
		*/
		Canvas(int width, int height);

		/**
		* @brief 构造函数，从给定的bmp文件生成画布
		* @param fineName bmp文件名
		*/
		Canvas(const char* fileName);

		~Canvas();

		/**
		* @brief 把画布的内容写入bmp文件
		* @param fileName 要写入的bmp文件名
		*/
		void writeToFile(const char* fileName);

		/**
		* @brief 获取画布的宽度
		* @return 画布的宽度
		*/
		int getWidth();

		/**
		* @brief 获取画布的高度
		* @return 画布的高度
		*/
		int getHeight();

		/**
		* @brief 获取画布上一点的R(红色)值
		* @param x 该点的横坐标
		* @param y 该点的纵坐标
		* @return 该点的R值
		*/
		unsigned char getR(int x, int y);

		/**
		* @brief 获取画布上一点的G(绿色)值
		* @param x 该点的横坐标
		* @param y 该点的纵坐标
		* @return 该点的G值
		*/
		unsigned char getG(int x, int y);

		/**
		* @b	rief 获取画布上一点的B(蓝色)值
		* @param x 该点的横坐标
		* @param y 该点的纵坐标
		* @return 该点的B值
		*/
		unsigned char getB(int x, int y);

		/**
		* @b	rief 获取画布上一点的颜色
		* @param x 该点的横坐标
		* @param y 该点的纵坐标
		* @return 该点的颜色【格式为0xRRGGBB（例：0xff0000为红色）】
		*/
		int getColor(int x, int y);

		/**
		* @brief 把画布上一点设置为指定颜色
		* @param x 该点的横坐标
		* @param y 该点的纵坐标
		* @param r 要设置的颜色的R(红色)值
		* @param g 要设置的颜色的G(绿色)值
		* @param b 要设置的颜色的B(蓝色)值
		*/
		void setColor(int x, int y, unsigned char r, unsigned char g, unsigned char b);

		/**
		* @brief 把画布上的一个矩形区域设置为指定颜色
		* @param x 矩形区域起点(左上角)的横坐标
		* @param x 矩形区域起点(左上角)的纵坐标
		* @param width 矩形区域的宽度
		* @param height 矩形区域的高度
		* @param r 要设置的颜色的R(红色)值
		* @param g 要设置的颜色的G(绿色)值
		* @param b 要设置的颜色的B(蓝色)值
		*/
		void setColor(int x, int y, int width, int height, unsigned char r, unsigned char g, unsigned char b);

		/**
		* @brief 把画布上一点设置为指定颜色
		* @param x 该点的横坐标
		* @param y 该点的纵坐标
		* @param color 要设置的颜色【格式为0xRRGGBB（例：0xff0000为红色）】
		*/
		void setColor(int x, int y, int color);

		/**
		* @brief 把画布上的一个矩形区域设置为指定颜色
		* @param x 矩形区域起点(左上角)的横坐标
		* @param	 x 矩形区域起点(左上角)的纵坐标
		* @param width 矩形区域的宽度
		* @param height 矩形区域的高度
		* @param color 要设置的颜色【格式为0xRRGGBB（例：0xff0000为红色）】
		*/
		void setColor(int x, int y, int width, int height, int color);

		/**
		* @brief 把另一张画布覆盖到画布上的指定位置（另一张画布的左上角将会对准该位置）
		* @param x 该位置的横坐标
		* @param y 该位置的纵坐标
		* @param canvas 另一张画布
		*/
		void applyCanvas(int x, int y, Canvas* canvas);
	private:
		int width;
		int height;
		unsigned char* content;
		int getIndex(int x, int y);
	};
}

#endif // !CANVAS_H

#ifndef CANVAS_H
#define CANVAS_H

namespace image
{
	/**
	* @brief ������������ϵ���Ϊ���Ͻǣ���BMP�ļ���ͬ����ʹ��RGB��ɫ
	*/
	class Canvas
	{
	public:
		/**
		* @brief ���캯��������ָ����С�Ĵ���ɫ(0x000000)����
		* @param width �����Ŀ��
		* @param height �����ĸ߶�
		*/
		Canvas(int width, int height);

		/**
		* @brief ���캯�����Ӹ�����bmp�ļ����ɻ���
		* @param fineName bmp�ļ���
		*/
		Canvas(const char* fileName);

		~Canvas();

		/**
		* @brief �ѻ���������д��bmp�ļ�
		* @param fileName Ҫд���bmp�ļ���
		*/
		void writeToFile(const char* fileName);

		/**
		* @brief ��ȡ�����Ŀ��
		* @return �����Ŀ��
		*/
		int getWidth();

		/**
		* @brief ��ȡ�����ĸ߶�
		* @return �����ĸ߶�
		*/
		int getHeight();

		/**
		* @brief ��ȡ������һ���R(��ɫ)ֵ
		* @param x �õ�ĺ�����
		* @param y �õ��������
		* @return �õ��Rֵ
		*/
		unsigned char getR(int x, int y);

		/**
		* @brief ��ȡ������һ���G(��ɫ)ֵ
		* @param x �õ�ĺ�����
		* @param y �õ��������
		* @return �õ��Gֵ
		*/
		unsigned char getG(int x, int y);

		/**
		* @b	rief ��ȡ������һ���B(��ɫ)ֵ
		* @param x �õ�ĺ�����
		* @param y �õ��������
		* @return �õ��Bֵ
		*/
		unsigned char getB(int x, int y);

		/**
		* @b	rief ��ȡ������һ�����ɫ
		* @param x �õ�ĺ�����
		* @param y �õ��������
		* @return �õ����ɫ����ʽΪ0xRRGGBB������0xff0000Ϊ��ɫ����
		*/
		int getColor(int x, int y);

		/**
		* @brief �ѻ�����һ������Ϊָ����ɫ
		* @param x �õ�ĺ�����
		* @param y �õ��������
		* @param r Ҫ���õ���ɫ��R(��ɫ)ֵ
		* @param g Ҫ���õ���ɫ��G(��ɫ)ֵ
		* @param b Ҫ���õ���ɫ��B(��ɫ)ֵ
		*/
		void setColor(int x, int y, unsigned char r, unsigned char g, unsigned char b);

		/**
		* @brief �ѻ����ϵ�һ��������������Ϊָ����ɫ
		* @param x �����������(���Ͻ�)�ĺ�����
		* @param x �����������(���Ͻ�)��������
		* @param width ��������Ŀ��
		* @param height ��������ĸ߶�
		* @param r Ҫ���õ���ɫ��R(��ɫ)ֵ
		* @param g Ҫ���õ���ɫ��G(��ɫ)ֵ
		* @param b Ҫ���õ���ɫ��B(��ɫ)ֵ
		*/
		void setColor(int x, int y, int width, int height, unsigned char r, unsigned char g, unsigned char b);

		/**
		* @brief �ѻ�����һ������Ϊָ����ɫ
		* @param x �õ�ĺ�����
		* @param y �õ��������
		* @param color Ҫ���õ���ɫ����ʽΪ0xRRGGBB������0xff0000Ϊ��ɫ����
		*/
		void setColor(int x, int y, int color);

		/**
		* @brief �ѻ����ϵ�һ��������������Ϊָ����ɫ
		* @param x �����������(���Ͻ�)�ĺ�����
		* @param	 x �����������(���Ͻ�)��������
		* @param width ��������Ŀ��
		* @param height ��������ĸ߶�
		* @param color Ҫ���õ���ɫ����ʽΪ0xRRGGBB������0xff0000Ϊ��ɫ����
		*/
		void setColor(int x, int y, int width, int height, int color);

		/**
		* @brief ����һ�Ż������ǵ������ϵ�ָ��λ�ã���һ�Ż��������Ͻǽ����׼��λ�ã�
		* @param x ��λ�õĺ�����
		* @param y ��λ�õ�������
		* @param canvas ��һ�Ż���
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

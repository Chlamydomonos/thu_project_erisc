#ifndef CANVAS_H
#define CANVAS_H

namespace image
{
	class Canvas
	{
	public:
		Canvas(int width, int height);
		Canvas(const char* fileName);
		~Canvas();
		void writeToFile(const char* fileName);
		int getWidth();
		int getHeight();
		unsigned char getR(int x, int y);
		unsigned char getG(int x, int y);
		unsigned char getB(int x, int y);
		int getColor(int x, int y);
		void setColor(int x, int y, unsigned char r, unsigned char g, unsigned char b);
		void setColor(int xStart, int yStart, int xEnd, int yEnd, unsigned char r, unsigned char g, unsigned char b);
		void setColor(int x, int y, int color);
		void setColor(int xStart, int yStart, int xEnd, int yEnd, int color);
		void applyCanvas(int x, int y, Canvas* canvas);
	private:
		int width;
		int height;
		unsigned char* content;
		int getIndex(int x, int y);
	};
}

#endif // !CANVAS_H

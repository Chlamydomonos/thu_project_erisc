#include "canvas.h"
#include "../exception/exception.h"
#include "../fuckide/fuckide.h"
#include <cstdio>

#define BMP_HEAD_SIZE 0x36
#define BMP_INFO_SIZE 0x28
#define GET_BITMAP_SIZE(width, height) ((width) % 4 > 0) ? (((width) * 3 + 4 - (((width) * 3) % 4)) * (height)) : ((width) * 3 * (height))
#define UCHR2INT(x1, x2, x3, x4) ((((int) (x4)) << 24) | (((int) (x3)) << 16) | (((int) (x2)) << 8) | ((int) (x1)))

namespace
{
	unsigned char* generateFileHead(int width, int height)
	{
		unsigned char* head = new unsigned char[BMP_HEAD_SIZE];

		head[0] = 'B';
		head[1] = 'M';

		int imgSize = GET_BITMAP_SIZE(width, height);

		int size = imgSize + BMP_HEAD_SIZE;
		for (int i = 2; i < 6; i++)
		{
			head[i] = size & 0xff;
			size >>= 010;
		}

		for (int i = 6; i < 10; i++)
			head[i] = 0;

		head[10] = BMP_HEAD_SIZE;
		for (int i = 11; i < 14; i++)
			head[i] = 0;

		head[14] = BMP_INFO_SIZE;
		for (int i = 15; i < 18; i++)
			head[i] = 0;

		int w = width;
		for (int i = 18; i < 22; i++)
		{
			head[i] = w & 0xff;
			w >>= 010;
		}

		int h = height;
		for (int i = 22; i < 26; i++)
		{
			head[i] = h & 0xff;
			h >>= 010;
		}

		head[26] = 1;
		head[27] = 0;
		head[28] = 24;
		head[29] = 0;

		for (int i = 30; i < 34; i++)
			head[i] = 0;

		for (int i = 34; i < 38; i++)
		{
			head[i] = imgSize & 0xff;
			imgSize >>= 010;
		}

		for (int i = 38; i < BMP_HEAD_SIZE; i++)
			head[i] = 0;
		return head;
	}
}

image::Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	int contentSize = GET_BITMAP_SIZE(width, height);
	content = new unsigned char[contentSize];
	for (int i = 0; i < contentSize; i++)
	{
		content[i] = 0;
	}
}

image::Canvas::Canvas(const char* fileName)
{
	FILE* bmp = fuckIDEfopen(fileName, "rb");
	char h1 = fgetc(bmp);
	char h2 = fgetc(bmp);
	if (h1 != 'B' || h2 != 'M')
	{
		const char* exceptionHead = "File \"";
		const char* exceptionTail = "\" is not a BMP file";
		int len1 = strlen(exceptionHead);
		int len2 = strlen(fileName) + len1;
		int len3 = strlen(exceptionTail) + len2;
		char* message = new char[len3 + 1];
		for (int i = 0; i < len1; i++)
			message[i] = exceptionHead[i];
		for (int i = len1; i < len2; i++)
			message[i] = fileName[i - len1];
		for (int i = len2; i < len3; i++)
			message[i] = exceptionTail[i - len2];
		message[len3] = 0;
		throw Exception(message);
		delete[] message;
	}

	unsigned char l1 = (char)fgetc(bmp);
	unsigned char l2 = (char)fgetc(bmp);
	unsigned char l3 = (char)fgetc(bmp);
	unsigned char l4 = (char)fgetc(bmp);
	int len = UCHR2INT(l1, l2, l3, l4);

	for (int i = 0; i < 4; i++)
		fgetc(bmp);

	l1 = (char)fgetc(bmp);
	l2 = (char)fgetc(bmp);
	l3 = (char)fgetc(bmp);
	l4 = (char)fgetc(bmp);
	int headLen = UCHR2INT(l1, l2, l3, l4);
	len -= headLen;

	for (int i = 0; i < 4; i++)
		fgetc(bmp);

	l1 = (char)fgetc(bmp);
	l2 = (char)fgetc(bmp);
	l3 = (char)fgetc(bmp);
	l4 = (char)fgetc(bmp);
	width = UCHR2INT(l1, l2, l3, l4);

	l1 = (char)fgetc(bmp);
	l2 = (char)fgetc(bmp);
	l3 = (char)fgetc(bmp);
	l4 = (char)fgetc(bmp);
	height = UCHR2INT(l1, l2, l3, l4);

	for (int i = 26; i < headLen; i++)
		fgetc(bmp);

	content = new unsigned char[len];

	for (unsigned char* i = content; i < content + len; i++)
		*i = (char)fgetc(bmp);
}

image::Canvas::~Canvas()
{
	delete[] content;
}

void image::Canvas::writeToFile(const char* fileName)
{
	FILE* bmp = fuckIDEfopen(fileName, "wb");
	unsigned char* head = generateFileHead(width, height);
	fwrite(head, 1, BMP_HEAD_SIZE, bmp);
	fwrite(content, 1, GET_BITMAP_SIZE(width, height), bmp);
	fclose(bmp);
}

int image::Canvas::getWidth()
{
	return width;
}

int image::Canvas::getHeight()
{
	return height;
}

unsigned char image::Canvas::getR(int x, int y)
{
	if (x >= width)
		throw Exception("Canvas x out of range");
	if (y >= height)
		throw Exception("Canvas y out of range");
	return content[getIndex(x, y) + 2];
}

unsigned char image::Canvas::getG(int x, int y)
{
	if (x >= width)
		throw Exception("Canvas x out of range");
	if (y >= height)
		throw Exception("Canvas y out of range");
	return content[getIndex(x, y) + 1];
}

unsigned char image::Canvas::getB(int x, int y)
{
	if (x >= width)
		throw Exception("Canvas x out of range");
	if (y >= height)
		throw Exception("Canvas y out of range");
	return content[getIndex(x, y) + 0];
}

int image::Canvas::getColor(int x, int y)
{
	try
	{
		unsigned char r = getR(x, y);
		unsigned char g = getG(x, y);
		unsigned char b = getB(x, y);
		int color = 0;
		color |= r;
		color <<= 010;
		color |= g;
		color <<= 010;
		color |= b;
		return color;
	}
	catch (Exception& e)
	{
		throw e;
	}
}

void image::Canvas::setColor(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
	if (x >= width)
		throw Exception("Canvas x out of range");
	if (y >= height)
		throw Exception("Canvas y out of range");
	int index = getIndex(x, y);
	content[index + 0] = b;
	content[index + 1] = g;
	content[index + 2] = r;
}

void image::Canvas::setColor(int x, int y, int width, int height, unsigned char r, unsigned char g, unsigned char b)
{
	if (width + x > this->width)
		width = this->width - x;
	if (height + y > this->height)
		height = this->height - y;
	width += x;
	height += y;
	for (int u = x; u < width; u++)
		for (int v = y; v < height; v++)
			setColor(u, v, r, g, b);
}

void image::Canvas::setColor(int x, int y, int color)
{
	try
	{
		if (color < 0 || color > 0xffffff)
			throw Exception("Trying to apply a number that is not a color to canvas");
		unsigned char b = color & 0xff;
		color >>= 010;
		unsigned char g = color & 0xff;
		color >>= 010;
		unsigned char r = color & 0xff;
		setColor(x, y, r, g, b);
	}
	catch (Exception& e)
	{
		throw e;
	}
}

void image::Canvas::setColor(int x, int y, int width, int height, int color)
{
	if (color < 0 || color > 0xffffff)
		throw Exception("Trying to apply a number that is not a color to canvas");
	unsigned char b = color & 0xff;
	color >>= 010;
	unsigned char g = color & 0xff;
	color >>= 010;
	unsigned char r = color & 0xff;
	setColor(x, y, width, height, r, g, b);
}

void image::Canvas::applyCanvas(int x, int y, Canvas* canvas)
{
	int w = canvas->getWidth();
	int h = canvas->getHeight();
	if (x + w > width)
		w = width - x;
	if (y + h > height)
		h = height - y;
	w += x;
	h += y;
	for (int u = x; u < w; u++)
		for (int v = y; v < h; v++)
			setColor(u, v, canvas->getColor(u - x, v - y));
}

int image::Canvas::getIndex(int x, int y)
{
	y = height - y - 1;
	int lineLen = (width % 4 > 0) ? (width * 3 + 4 - ((width * 3) % 4)) : (width * 3);
	return lineLen * y + x * 3;
}

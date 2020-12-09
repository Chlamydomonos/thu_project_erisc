#include "imageconfigreader.h"
#include "../fuckide/fuckide.h"

input::ImageConfigReader::ImageConfigReader(const char* fileName)
{
	file = fuckIDEfopen(fileName, "rb");
	values = new int[10];
	fread(values, 4, 10, file);
	fclose(file);
}

input::ImageConfigReader::~ImageConfigReader()
{
	delete[] values;
}

int input::ImageConfigReader::getRegisterOffsetX()
{
	return values[0];
}

int input::ImageConfigReader::getRegisterOffsetY()
{
	return values[1];
}

int input::ImageConfigReader::getMemoryOffsetX()
{
	return values[2];
}

int input::ImageConfigReader::getMemoryOffsetY()
{
	return values[3];
}

int input::ImageConfigReader::getStackOffsetX()
{
	return values[4];
}

int input::ImageConfigReader::getStackOffsetY()
{
	return values[5];
}

int input::ImageConfigReader::getRegisterSquareWidth()
{
	return values[6];
}

int input::ImageConfigReader::getRegisterSquareHeight()
{
	return values[7];
}

int input::ImageConfigReader::getMemorySquareWidth()
{
	return values[8];
}

int input::ImageConfigReader::getMemorySquareHeight()
{
	return values[9];
}

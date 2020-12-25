#include "imageconfigreader.h"
#include "../fuckide/fuckide.h"
#include "../exception/exception.h"

input::ImageConfigReader::ImageConfigReader(const char* fileName)
{
	file = fuckIDEfopen(fileName, "rb");
	if (file == nullptr)
	{
		const char* head = "Config file \"";
		int len1 = strlen(head);
		int len2 = len1 + strlen(fileName);
		const char* tail = "\" lost";
		int len3 = len2 + strlen(tail);
		char* message = new char[len3 + 1];
		for (int i = 0; i < len1; i++)
			message[i] = head[i];
		for (int i = len1; i < len2; i++)
			message[i] = fileName[i - len1];
		for (int i = len2; i < len3; i++)
			message[i] = tail[i - len2];
		message[len3] = 0;
		Exception exception(message);
		delete[] message;
		throw exception;
	}
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
